// SHE library
// Copyright (C) 2012-2015  David Capello
//
// This file is released under the terms of the MIT license.
// Read LICENSE.txt for more information.

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <CoreFoundation/CoreFoundation.h>
#include <Foundation/Foundation.h>
#include <AppKit/AppKit.h>

#include "she/osx/app_delegate.h"

#include "she/event.h"
#include "she/event_queue.h"
#include "she/osx/app.h"
#include "she/system.h"

@implementation OSXAppDelegate

- (BOOL)applicationShouldTerminateAfterLastWindowClosed:(NSApplication*)theApplication
{
  return YES;
}

- (NSApplicationTerminateReply)applicationShouldTerminate:(NSApplication*)sender
{
  return NSTerminateNow;
}

- (void)applicationWillTerminate:(NSNotification*)aNotification
{
  she::Event ev;
  ev.setType(she::Event::CloseDisplay);
  she::instance()->eventQueue()->queueEvent(ev);

  she::OSXApp::instance()->joinUserThread();
}

- (void)quit:(id)sender
{
  [[NSApp mainWindow] performClose:self];
}

@end
