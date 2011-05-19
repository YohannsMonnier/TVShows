/*
 *  This file is part of the TVShows 2 ("Phoenix") source code.
 *  http://github.com/victorpimentel/TVShows/
 *
 *  TVShows is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with TVShows. If not, see <http://www.gnu.org/licenses/>.
 *
 */

#import <PreferencePanes/PreferencePanes.h>
#import <Cocoa/Cocoa.h>
#import "JRFeedbackController.h"

@interface TabController : NSPreferencePane
{
    IBOutlet NSTabView *prefTabView;
    IBOutlet NSButton *feedbackButton;
    NSManagedObject *selectedShow;
    
    // Version information
    IBOutlet NSTextField *sidebarHeader;
    IBOutlet NSTextField *sidebarVersionText;
    IBOutlet NSTextField *sidebarDateText;
    
    // About tab
    IBOutlet NSTextView *textView_aboutBox;
    IBOutlet NSButton *websiteButton;
    IBOutlet NSButton *donateButton;
    IBOutlet NSButton *viewLogsButton;
    IBOutlet NSButton *uninstallButton;
    IBOutlet NSTextField *disclaimer;
    
    // Log Viewer
    IBOutlet NSTextView *textView_logViewer;
    IBOutlet NSWindow *logViewerWindow;
    IBOutlet NSTextField *logTitleText;
    IBOutlet NSTextField *logExplanationText;
    IBOutlet NSTextField *logLocalizationText;
    IBOutlet NSButton *closeLogButton;
    
    // Subscriptions tab
    IBOutlet NSArrayController *SBArrayController;
    IBOutlet NSWindow *showInfoWindow;
    IBOutlet NSTextField *lastCheckedText;
    IBOutlet NSButton *addButton;
    IBOutlet NSButton *addRSSButton;
    IBOutlet NSTextField *lastCheckedDate;
    IBOutlet NSTableColumn *colHD;
    IBOutlet NSTableColumn *colName;
    IBOutlet NSTableColumn *colSeason;
    IBOutlet NSTableColumn *colEpisode;
    IBOutlet NSTableColumn *colDate;
    
    // Show info window
    IBOutlet NSTextField *showName;
    IBOutlet NSTextField *showStatus;
    IBOutlet NSTextField *showLastDownloaded;
    IBOutlet NSButton *showQuality;
    IBOutlet NSButton *showIsEnabled;
    IBOutlet NSArrayController *episodeArrayController;
    IBOutlet NSTableView *episodeTableView;
    IBOutlet NSTextField *statusTitle;
    IBOutlet NSTextField *lastDownloadedTitle;
    IBOutlet NSBox *infoBoxTitle;
    IBOutlet NSBox *prefBoxTitle;
    IBOutlet NSButton *closeButton;
    IBOutlet NSButton *unsubscribeButton;
    IBOutlet NSImageView *showPoster;
}

@property (retain) NSManagedObject *selectedShow;

- (void) awakeFromNib;
- (NSObject *) getEpisodeAtRow:(NSInteger)row;
- (void) tabView:(NSTabView *)tabView didSelectTabViewItem:(NSTabViewItem *)tabViewItem;
- (IBAction) showFeedbackWindow:(id)sender;

#pragma mark -
#pragma mark About Tab
- (IBAction) openWebsite:(id)sender;
- (IBAction) openTwitter:(id)sender;
- (IBAction) openPaypal:(id)sender;
- (IBAction) openUninstaller:(id)sender;
- (void) drawAboutBox;

#pragma mark -
#pragma mark Log Viewer
- (IBAction) showLogViewerWindow:(id)sender;
- (IBAction) closeLogViewerWindow:(id)sender;

#pragma mark -
#pragma mark Subscriptions TabController
- (IBAction) displayShowInfoWindow:(id)sender;
- (void) setEpisodesForShow;
- (void) setStatusForShow:(NSString *)show;
- (void) setPosterForShow:(NSString *)show;
- (IBAction) closeShowInfoWindow:(id)sender;
- (IBAction) showQualityDidChange:(id)sender;
- (void) startDownloadingURL:(NSString *)url withFileName:(NSString *)fileName;
- (void) sortSubscriptionList;
- (IBAction) unsubscribeFromShow:(id)sender;

@end
