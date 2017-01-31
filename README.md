A(P)ertain SDK v0.9.0 for iOS - Getting Started (BETA)
======================================================

This document describes how to get started using the A(P)ertain SDK v0.9.0 for iOS. Our Library is built using Swift 3.0 and can also be used with Apps developed in Objective-C. You can see sample Apps uploaded as part of this project in near future.

Before you Begin
----------------

Before implementing the SDK, make sure you have the following:

* Download the A(P)ertain SDK framework from [here](https://github.com/jkltech/apertain-sdk-ios). The best way is to clone the Git Hub project, such that future updates for the SDK are integrated immediately.
* Add the Framework into your Xcode App Project using the instructions over [here](https://github.com/jkltech/apertain-sdk-ios/blob/master/XCode_Instructions.md).

Getting Started
---------------

### 1. Initialize the SDK

The APertain SDK though written on Swift 3.0, can also be used on Objective-C Apps. Following specifies how to initiate APertain SDK in both Swift & Objective-C Apps.
	
## 1.1. Initialize the SDK (Swift Apps)

In your Swift App, in the Controller Code that loads your App write the following code in viewDidLoad() function. This should be called only once in your App/Game on the first Controller loaded by the App/Game.
	
The App Unique ID and User App Signature are generated when you add the App in ![APertain SaaS Console](https://www.apertain.com/login.apt). The App Unique IDs & User App Signature will identify the App and your Publisher Account registered with the APertain SaaS Console.

	Let _Init_Return =  ApertainFactory.init(appUniqueId: "XXXXXX", userAppSignature: 
										"XXXXXXX", userName: "XYXY", userEmail: "XXXX@yyyyy.com");

## 1.2. Initialize the SDK (Objective-C Apps)

In your Objective-C App, in the Controller that loads your App write the following code in viewDidLoad() function. This should be called only once in your App/Game on the first Controller loaded by the App/Game.
	
The App Unique ID and User App Signature are generated when you add the App in ![APertain SaaS Console](https://www.apertain.com/login.apt). The App Unique IDs & User App Signature will identify the App and your Publisher Account registered with the APertain SaaS Console.

	 [[ApertainFactory alloc] initWithAppUniqueId:@"XXXXXX" userAppSignature:@"XXXXXXX"
										userName:@"XYXY" userEmail:@"XXXXX@YYY.com"];
	
### 2. Showing Smart Rating Prompt

The following code shows the APertain Smart Rating Prompt.

When the Rating Prompt shows up, it takes the user to rate your app in App Store. This can be called from any part/process of your Controller where you like to show the Rating Prompt.

## 2.1. Smart Rating Prompt (Swift Apps)

	 let ratingPrompt = APTRateApp();
     ratingPrompt.initRateMyApp(viewDelegate: self, title: "Rating prompt Title here",
								message: "Rating prompt message here");

## 2.2. Smart Rating Prompt (Objective-C Apps)

	APTRateApp *rateApp = [[APTRateApp alloc] init];
    [rateApp initRateMyAppWithViewDelegate:self title:@"A(P)ertain Title here"
								message:@"Rating prompt message here!!"];
	
### 3. APertain In-App Support Chat Interface

A(P)ertain App Support Chat Interface provides a means messenger style communication (conversation) interface for the user and the Mobile Developer. The below code provides a APertain Support icon view which when clicked will open up the In-App Support Chat Interface. 

As a developer you can place this view in any View of your choice to let the user open up the App Support Chat Interface with a customised title.

## 3.1. App Support (Swift Apps)

     let inAppController = InAppController();
     inAppController.launchChatController(selfView: self, title: "Ask Me!");

## 3.2. App Support (Objective-C Apps)

	InAppController *obj = [[InAppController alloc] init];
    [obj launchChatControllerWithSelfView:self title:@"Ask Me!"];

### 4. APertain App Feedback Prompt

APertain Feedback Prompt ensures that the Users are redirected to provide constructive feedback when they face negative experiences within the App regularly. This also ensures that User is able to communicate their frustrations within the App for a successful resolution of issues they face. 

## 4.1. Feedback Prompt (Swift Apps)

Default Title: Give Your Valuable Feedback

Default Message: What can we do to ensure that you love our app? We appreciate your constructive feedback.

If Title and Message are passed empty in the API Call, the Default Title and Defaule Message would be used.
      
     let inAppController = InAppController();
	 
     inAppController.showFeedbackAlert(viewDelegate: self, title: "App Feedback!",
							message: "We appreciate your constructive feedback.");
	 
or

     inAppController.showFeedbackAlert(viewDelegate: self ,title:  "",message: "");


## 4.2. Feedback Prompt (Objective-C Apps)

Default Title: Give Your Valuable Feedback.

Default Message: What can we do to ensure that you love our app? We appreciate your constructive feedback.

If Title and Message are passed empty in the API Call, the Default Title and Defaule Message would be used.
      
	InAppController *obj = [[InAppController alloc] init];
    
	[obj showFeedbackAlertWithViewDelegate:self title:@"App Feedback!" 
					message:@"We appreciate your constructive feedback."];
	
or

	[obj showFeedbackAlertWithViewDelegate:self title:@"" message:@""];
