A(P)ertain SDK v1.0 for iOS - Getting Started (Swift 3.0)
========================================================================

This document describes how to get started using the A(P)ertain SDK v1.0 for iOS.

Before you Begin
----------------

Before implementing the SDK, make sure you have the following:

* Download the A(P)ertain SDK AAR from [here](https://github.com/jkltech/apertain-as-aar).
* Add the AAR into your Android Studio App Project using the instructions over [here](https://github.com/jkltech/apertain-as-aar/blob/master/AAR_Integration_Instructions.md).

Getting Started
---------------

	
### 1. Initialize the SDK Swift

In the Activity that loads your app write the following code in viewDidLoad(), to initialize the A(P)ertain SDK. This should be called only once in your App/Game on the first Activity loaded by the App/Game.
	
The App Unique ID and User App Signature are generated as you add the App in A(P)ertain SaaS backend. These unique ids will identify the App and the User registered with the A(P)ertain SaaS backend.

	_ =  ApertainFactory.init(appUniqueId: "XXXXXX", userAppSignature: "XXXXXXX", userName: "XYXY", userEmail: "XXXX@yyyyy.com")

	 let ratingPrompt = APTRateApp()
     ratingPrompt.initRateMyApp(viewDelegate: self, title: "Rating prompt Title here", message: "Rating prompt message here")

     let inAppController = InAppController()
     inAppController.launchChatController(selfView: self, title: "chat title here")


### Optional values for Title and message 
Default Title: Give Your Valuable Feedback
Default Message: What can we do to ensure that you love our app? We appreciate your constructive feedback.
Title and Message passing empty 
      
     let inAppController = InAppController()
     inAppController.showFeedbackAlert(viewDelegate: self ,title:  "Feedback Prompt Title here (Optional)",message: "Feedback Prompt Message here (optional)")
### 2. Initialize the SDK Objective-C
In the Activity that loads your app write the following code in viewDidLoad(), to initialize the A(P)ertain SDK. This should be called only once in your App/Game on the first Activity loaded by the App/Game.
	
The App Unique ID and User App Signature are generated as you add the App in A(P)ertain SaaS backend. These unique ids will identify the App and the User registered with the A(P)ertain SaaS backend.

	 [[ApertainFactory alloc] initWithAppUniqueId:@"XXXXXX" userAppSignature:@"XXXXXXX" userName:@"XYXY" userEmail:@"XXXXX@YYY.com"];

	 APTRateApp *rateApp = [[APTRateApp alloc] init];
    [rateApp initRateMyAppWithViewDelegate:self title:@"A(P)ertain Title here" message:@"Rating prompt message here!!"];

     InAppController *obj = [[InAppController alloc] init];
    [obj launchChatControllerWithSelfView:self title:@"MyChat Title here"];


### Optional values for Title and message 
Default Title: Give Your Valuable Feedback
Default Message: What can we do to ensure that you love our app? We appreciate your constructive feedback.
Title and Message passing empty 
      
     InAppController *obj = [[InAppController alloc] init];
    [obj showFeedbackAlertWithViewDelegate:self title:@"Feedback Prompt Title here (Optional)" message:@"Please provide your valuable feedback??"];
