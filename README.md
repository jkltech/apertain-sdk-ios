A(P)ertain SDK v0.9.0 for iOS - Getting Started (Swift 3.0)
========================================================================

This document describes how to get started using the A(P)ertain SDK v0.9.0 for iOS.

Before you Begin
----------------

Before implementing the SDK, make sure you have the following:

* Download the A(P)ertain SDK framework from [here](https://github.com/jkltech/apertain-sdk-ios).
* Add the Framework into your Xcode App Project using the instructions over [here](https://github.com/jkltech/apertain-sdk-ios/blob/master/XCode_Instructions.md).

Getting Started
---------------

	
### 1. Initialize the SDK Swift

In the Activity that loads your app write the following code in viewDidLoad(), to initialize the A(P)ertain SDK. This should be called only once in your App/Game on the first Activity loaded by the App/Game.
	
The App Unique ID and User App Signature are generated as you add the App in A(P)ertain SaaS backend. These unique ids will identify the App and the User registered with the A(P)ertain SaaS backend.

	_ =  ApertainFactory.init(appUniqueId: "XXXXXX", userAppSignature: "XXXXXXX", userName: "XYXY", userEmail: "XXXX@yyyyy.com")
	
### 2. Showing Smart Rating Prompt

The following code shows the Smart Rating Prompt.

When the Rating Prompt shows up, it takes the user to rate your app in App Store. This can be called from any part/process of your Controller where you like to show the Rating Prompt.

	 let ratingPrompt = APTRateApp()
     ratingPrompt.initRateMyApp(viewDelegate: self, title: "Rating prompt Title here", message: "Rating prompt message here")
### 3. A(P)ertain App Support Chat Interface

A(P)ertain App Support Chat Interface provides a means messenger style communication (conversation) interface for the user and the Mobile Developer. The below code provides a A(P)ertain Support icon view which when clicked will open up the App Support Chat Interface. 

As a developer you can place this view in any layout of your choice to let the user open up the App Support Chat Interface with customised  title.

     let inAppController = InAppController()
     inAppController.launchChatController(selfView: self, title: "chat title here")


### 4. A(P)ertain App Feedback Prompt
Default Title: Give Your Valuable Feedback
Default Message: What can we do to ensure that you love our app? We appreciate your constructive feedback.
Title and Message passing empty 
      
     let inAppController = InAppController()
     inAppController.showFeedbackAlert(viewDelegate: self ,title:  "Feedback Prompt Title here (Optional)",message: "Feedback Prompt Message here (optional)")
or
     inAppController.showFeedbackAlert(viewDelegate: self ,title:  "",message: "")

## 2. Initialize the SDK Objective-C
In the Activity that loads your app write the following code in viewDidLoad(), to initialize the A(P)ertain SDK. This should be called only once in your App/Game on the first Activity loaded by the App/Game.
	
The App Unique ID and User App Signature are generated as you add the App in A(P)ertain SaaS backend. These unique ids will identify the App and the User registered with the A(P)ertain SaaS backend.

	 [[ApertainFactory alloc] initWithAppUniqueId:@"XXXXXX" userAppSignature:@"XXXXXXX" userName:@"XYXY" userEmail:@"XXXXX@YYY.com"];

### 1. Showing Smart Rating Prompt

The following code shows the Smart Rating Prompt.

When the Rating Prompt shows up, it takes the user to rate your app in App Store. This can be called from any part/process of your Controller where you like to show the Rating Prompt.

	 APTRateApp *rateApp = [[APTRateApp alloc] init];
    [rateApp initRateMyAppWithViewDelegate:self title:@"A(P)ertain Title here" message:@"Rating prompt message here!!"];
### 2. A(P)ertain App Support Chat Interface

A(P)ertain App Support Chat Interface provides a means messenger style communication (conversation) interface for the user and the Mobile Developer. The below code provides a A(P)ertain Support icon view which when clicked will open up the App Support Chat Interface. 

As a developer you can place this view in any layout of your choice to let the user open up the App Support Chat Interface with customised  title.

     InAppController *obj = [[InAppController alloc] init];
    [obj launchChatControllerWithSelfView:self title:@"MyChat Title here"];


### 3. A(P)ertain App Feedback Prompt
Default Title: Give Your Valuable Feedback
Default Message: What can we do to ensure that you love our app? We appreciate your constructive feedback.
Title and Message passing empty 
      
     InAppController *obj = [[InAppController alloc] init];
    [obj showFeedbackAlertWithViewDelegate:self title:@"Feedback Prompt Title here (Optional)" message:@"Please provide your valuable feedback??"];
or
	[obj showFeedbackAlertWithViewDelegate:self title:@"" message:@""];
