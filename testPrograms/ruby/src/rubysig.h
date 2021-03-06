/**********************************************************************

  rubysig.h -

  $Author: ocean $
  $Date: 2005/10/21 10:23:03 $
  created at: Wed Aug 16 01:15:38 JST 1995

  Copyright (C) 1993-2003 Yukihiro Matsumoto

**********************************************************************/

#ifndef SIG_H
#define SIG_H
#include <mosync.h>
//#include <errno.h>
//#include "vars.h"

#ifdef _WIN32

typedef LONG rb_atomic_t;

# define ATOMIC_TEST(var) InterlockedExchange(&(var), 0)
# define ATOMIC_SET(var, val) InterlockedExchange(&(var), (val))
# define ATOMIC_INC(var) InterlockedIncrement(&(var))
# define ATOMIC_DEC(var) InterlockedDecrement(&(var))

/* Windows doesn't allow interrupt while system calls */
# define TRAP_BEG do {\
    int saved_errno = 0;
    //rb_atomic_t trap_immediate = ATOMIC_SET(rb_trap_immediate, 1)
# define TRAP_END\
    /*ATOMIC_SET(rb_trap_immediate, trap_immediate);\
    saved_errno = errno;\
    CHECK_INTS;\
    errno = saved_errno;\
} while (0)*/
# define RUBY_CRITICAL(statements) do {\
    rb_w32_enter_critical();\
    statements;\
    rb_w32_leave_critical();\
} while (0)
#else
typedef int rb_atomic_t;

# define ATOMIC_TEST(var) ((var) ? ((var) = 0, 1) : 0)
# define ATOMIC_SET(var, val) ((var) = (val))
# define ATOMIC_INC(var) (++(var))
# define ATOMIC_DEC(var) (--(var))

# define TRAP_BEG do {\
    int saved_errno = 0;\
    int trap_immediate = 0;
    //rb_trap_immediate = 1
# define TRAP_END \
    saved_errno = errno;\
    CHECK_INTS;\
    errno = saved_errno;\
} while (0)

# define RUBY_CRITICAL(statements) do {\
    int trap_immediate = 0;\
    statements;\
} while (0)
#endif
RUBY_EXTERN rb_atomic_t rb_trap_immediate;

#define DEFER_INTS {}
#define ALLOW_INTS {}
#define ENABLE_INTS {}

VALUE rb_with_disable_interrupt _((VALUE(*)(ANYARGS),VALUE));

RUBY_EXTERN rb_atomic_t rb_trap_pending;
void rb_trap_restore_mask _((void));

RUBY_EXTERN int rb_thread_critical;
void rb_thread_schedule _((void));
#if defined(HAVE_SETITIMER) || defined(_THREAD_SAFE)
RUBY_EXTERN int rb_thread_pending;
# define CHECK_INTS {}
#else
/* pseudo preemptive thread switching */
#define THREAD_TICK 500
#define CHECK_INTS {}
#endif

#endif
