//
//  PolycodeAppDelegate.h
//  Polycode
//
//  Created by Ivan Safrin on 11/28/10.
//  Copyright 2010 Local Projects. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "PolycodeView.h"

#include "Polycode.h"
#include "PolycodeIDEApp.h"

using namespace Polycode;

class PolycodeAppEventHandler : public EventHandler {
	
public:
	PolycodeAppEventHandler() {}
	~PolycodeAppEventHandler() {}
	
	void handleEvent(Event *evt) {
		switch(evt->getEventCode()) {
			case PolycodeIDEApp::EVENT_SHOW_MENU:
				[appDelegate showProjectMenu];
			break;
		}
	}
	
	id appDelegate;
};

@interface PolycodeAppDelegate : NSObject <NSApplicationDelegate> {
    NSWindow *window;	
	PolycodeIDEApp *app;
	PolycodeView *polycodeView;
	PolycodeAppEventHandler *eventHandler;
	NSTimer* timer;
	
	NSMenu *projectMenu;
	
	String fileToOpen;
	BOOL mustShowProjectMenu;
}

@property (assign) IBOutlet PolycodeView *polycodeView;
@property (assign) IBOutlet NSWindow *window;
@property (assign) IBOutlet NSMenu *projectMenu;


- (void) showProjectMenu;

// Menu accessors

-(IBAction) toggleConsole: (id) sender;
-(IBAction) refreshProject: (id) sender;
-(IBAction) renameFile: (id) sender;
-(IBAction) removeFile: (id) sender;
-(IBAction) newGroup: (id) sender;
-(IBAction) browseExamples: (id) sender;
-(IBAction) runProject: (id) sender;
-(IBAction) exportProject: (id) sender;
-(IBAction) newProject: (id) sender;
-(IBAction) closeProject: (id) sender;
-(IBAction) closeFile: (id) sender;
-(IBAction) newFile: (id) sender;
-(IBAction) openProject: (id) sender;
-(IBAction) saveFile: (id) sender;
-(IBAction) findText: (id) sender;
-(IBAction) openDocs: (id) sender;
-(IBAction) showAbout: (id) sender;

@end
