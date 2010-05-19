/* Copyright (C) 2009 Mobile Sorcery AB
 
 This program is free software; you can redistribute it and/or modify it under
 the terms of the GNU General Public License, version 2, as published by
 the Free Software Foundation.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; see the file COPYING.  If not, write to the Free
 Software Foundation, 59 Temple Place - Suite 330, Boston, MA
 02111-1307, USA.
 */

#import <UIKit/UIKit.h>

@interface UIApplication(MyExtras) 
- (void)terminateWithSuccess; 
@end

@interface MessageBoxHandler : UIViewController <UIAlertViewDelegate> {
	BOOL kill;
	NSString *msg;
	NSMutableArray *mutableArray;
}
@property BOOL kill;
@property (copy, nonatomic) NSString* msg;
@property (nonatomic, retain) NSMutableArray *mutableArray;
- (void)alertViewCancel:(UIAlertView *)alertView;
@end

// Controller for a table view, used for "List Boxes"
@interface MyTableViewController : UITableViewController {
	NSMutableArray *displayedObjects;
}
@property (nonatomic, retain) NSMutableArray *displayedObjects;
@end

// Used to pass parameters to the widgets, through performSelectorOnMainThread
@interface WidgetHandler : UIViewController <UITextFieldDelegate> {
	NSString *msg;
	int x,y,l,h, widgetId, rsc;
}
@property (copy, nonatomic) NSString* msg;
@property int x,y,l,h, widgetId, rsc;
- (BOOL)textFieldShouldReturn:(UITextField *)textField;
@end

// Proper MoSync View, each screen is an instance of this class
@interface MoSyncView : UIView {
	CGImageRef mosyncView;
	UIToolbar *toolbar;
	NSMutableArray *items;
	MyTableViewController *controller;
}
-(void) updateMoSyncView: (CGImageRef)ref;
-(void) showMessageBox:(NSString*)msg shouldKill:(bool)kill;
-(void) addLabel:(id) obj;
-(void) showLabel:(NSString*) msg posX:(int) x posY:(int) y length:(int) l height:(int) h widgetId:(int) widgetid;
-(void) addButton:(id) obj;
-(void) showButton:(NSString*) msg posX:(int) x posY:(int) y length:(int) l height:(int) h widgetId:(int) widgetid;
-(void) addTextField:(id) obj;
-(void) showTextField: (NSString*) msg posX:(int) x posY:(int) y length:(int) l height:(int) h widgetId:(int) widgetid;
- (void)navigationBar:(UINavigationBar*)bar buttonClicked:(int)button;
//- (void) pressButton1:(id)sender;
-(void) addNavigationBar:(id) obj;
-(void) showNavigationBar: (NSString*) msg;
-(void) addScreen:(id) obj;
-(void) addScreenList:(id) obj;
-(MoSyncView *) showScreen:(int) widgetid;
-(MoSyncView *) showScreenList:(int) widgetid;
-(void) addListItem:(id) obj;
-(void) showListItem: (NSString*) msg widgetId: (int) widgetid;
-(void) addToolBar:(id) obj;
-(void) showToolBar;
-(void) showToolBarItem: (int) widgetid withIcon: (int) rsc;
-(void) addToolBarItem:(id) obj;
-(void) addImage:(id) obj;
-(void) showImage: (int) widgetid withImage: (int) rsc posX:(int) x posY:(int) y;
-(void) passEvent:(id) obj;
-(NSString *) getText:(int) widgetId;
@end
