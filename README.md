Apertain SDK v0.9.0 for iOS - Getting Started (BETA)
======================================================

This document describes how to get started using the Apertain SDK v0.9.0 for iOS. Our Library is built using Swift 3.0 and can also be used with Apps developed in Objective-C. You can see sample Apps uploaded as part of this project in near future.

Before you Begin
----------------

Before implementing the SDK, make sure you have the following:

* Download the Apertain SDK framework from [here](https://github.com/jkltech/apertain-sdk-ios). The best way is to clone the Git Hub project, such that future updates for the SDK are integrated immediately.
* Add the Framework into your Xcode App Project using the instructions over [here](https://github.com/jkltech/apertain-sdk-ios/blob/master/XCode_Instructions.md).

Getting Started
---------------

### 1. Changes to iOS App Information Property List.

To integrate APertain SDK with the iOS App, the following changes are needed in the Information Property Plist (Info.plist).

	<key>AppID</key>
    <string>20171502001</string>

Optional:
    
    <key>DefaultFeedbackTitle</key>
    <string>Give Your Valuable Feedback</string>
    
    <key>DefaultFeedbackMsg</key>
    <string>What can we do to ensure that you love our ApertainAppDemo? We 
    appreciate your constructive feedback.</string>
    
    <key>DefaultMsgRatingConfirm</key>
    <string>Do you love ApertainAppDemo?</string>
    
    <key>DefaultTitleRatingPrompt</key>
    <string>Thank You</string>
    
    <key>DefaultMsgRatingPrompt</key>
    <string>We&apos;re so happy to hear that you love ApertainAppDemo! It&apos;d be 
    really helpful if you rated us. Thanks so much for spending some time 
    with us.</string>

Note: Is not necessary, If you are not adding above tags its takes default text from APertain SDK. 

### 2. Initialize the SDK

The APertain SDK though written on Swift 3.0, can also be used on Objective-C Apps. Following specifies how to initiate APertain SDK in both Swift & Objective-C Apps.
	
## 2.1. Initialize the SDK (Swift Apps)

In your Swift App, in the Controller Code that loads your App write the following code in viewDidLoad() function. This should be called only once in your App/Game on the first Controller loaded by the App/Game.
	
The App Unique ID and User App Signature are generated when you add the App in [APertain SaaS Console](https://www.apertain.com/login.apt). The App Unique IDs & User App Signature will identify the App and your Publisher Account registered with the APertain SaaS Console.

	let appUniqueId = "XXXXXXXXXXXXXXXXX";
    let userAppSignature = "XXXXXXXXXXXX";
    
    ApertainFactory.init(self, appUniqueId, userAppSignature);

## 2.2. Initialize the SDK (Objective-C Apps)

In your Objective-C App, in the Controller that loads your App write the following code in viewDidLoad() function. This should be called only once in your App/Game on the first Controller loaded by the App/Game.
	
The App Unique ID and User App Signature are generated when you add the App in [APertain SaaS Console](https://www.apertain.com/login.apt). The App Unique IDs & User App Signature will identify the App and your Publisher Account registered with the APertain SaaS Console.

	 NSString *appUniqueId = @"XXXXXXXXXXX";
     NSString *userAppSignature = @"XXXXXXXX";
     
     [ApertainFactory init: self : appUniqueId : userAppSignature ];
	
### 3. Showing Smart Rating Prompt

The following code shows the APertain Smart Rating Prompt.

When the Rating Prompt shows up, it takes the user to rate your app in App Store. This can be called from any part/process of your Controller where you like to show the Rating Prompt.

## 3.1. Smart Rating Prompt (Swift Apps)

	 ApertainFactory.showRatingFlowIfConditionsAreMet(self, "Event");

If you would just like to show your rating prompt from a menu item or your own smart conditions, please use the following code,

	ApertainFactory.showRatingPrompt(self);

## 3.2. Smart Rating Prompt (Objective-C Apps)

	[ApertainFactory showRatingFlowIfConditionsAreMet:self : @"Event"];

If you would just like to show your rating prompt from a menu item or your own smart conditions, please use the following code,

	[ApertainFactory showRatingPrompt:self];
	
### 4. APertain In-App Support Chat Interface

Apertain App Support Chat Interface provides a means messenger style communication (conversation) interface for the user and the Mobile Developer. The below code provides a APertain Support icon view which when clicked will open up the In-App Support Chat Interface. 

As a developer you can place this view in any View of your choice to let the user open up the App Support Chat Interface with a customised title.

## 4.1. App Support (Swift Apps)

     ApertainFactory.showApertainConversationChatter(self, "Ask Me!")

## 4.2. App Support (Objective-C Apps)

	[ApertainFactory showApertainConversationChatter:self :@"Ask Me!"];

### 5. APertain App Feedback Prompt

APertain Feedback Prompt ensures that the Users are redirected to provide constructive feedback when they face negative experiences within the App regularly. This also ensures that User is able to communicate their frustrations within the App for a successful resolution of issues they face. 

Default Title: Give Your Valuable Feedback

Default Message: What can we do to ensure that you love our app? We appreciate your constructive feedback.

## 5.1. Feedback Prompt (Swift Apps)

	ApertainFactory.showFeedbackPrompt(self);

## 5.2. Feedback Prompt (Objective-C Apps)

	[ ApertainFactory showFeedbackPrompt:self];


### 6. Logging User Experience
From within the App/Game, a user tends to experience various levels of emotions as they pass-through various obstacles or processes intended to be executed within the App/Game. When the App Developer (Swift Or Objective-C) records such experiences it enables the App to be more pro-active based on User Experiences to provide additional means to execute the App/Game processes.

Apertain allows such User Experiences to be recorded and then use those specific experience values to further add relevant process flows related to the App/Game.

## 6.1. Recording a Positive User Experience
Whenever a positive experience occurred (eg., Level Completion in a game or Achieving some Milestone in App) the developer can add this code to record the positive experience gained by the user.

### 6.1.1 Swift Apps Code

	Apertain.logUserXp(viewDelegate: UIViewController, uniqueIdentification: [uniqueEvent], 
										valueXp: Apertain.PositiveXp)
	
	Example: Apertain.logUserXp(viewDelegate: self, uniqueIdentification: "TicketBooked", 
										valueXp: Apertain.PositiveXp)

### 6.2.2. Objective-C Apps Code

	[Apertain logUserXpWithViewDelegate:UIViewController uniqueIdentification:[uniqueEvent] 
										valueXp: [Apertain PositiveXp]];
	
	Example: [Apertain logUserXpWithViewDelegate:self uniqueIdentification:@"TicketBooked" 
										valueXp: [Apertain PositiveXp]];

## 6.2. Recording a Negative User Experience
When a user gets a negative experience (eg., Level Failed or invalid process input) you can add this code to record the negative experience for the user.

### 6.2.1. Swift Apps Code

	Apertain.logUserXp(viewDelegate: UIViewController, uniqueIdentification: [uniqueEvent], 
										valueXp: Apertain.NegativeXp)
										
	Example: Apertain.logUserXp(viewDelegate: self, uniqueIdentification: "LevelFailed", 
										valueXp: Apertain.NegativeXp)
										
### 6.2.2. Objective-C Apps Code

	[Apertain logUserXpWithViewDelegate:UIViewController uniqueIdentification: [uniqueEvent] 
										valueXp: [Apertain NegativeXp]];
										
	Example: [Apertain logUserXpWithViewDelegate:self uniqueIdentification:@"LevelFailed
										valueXp: [Apertain NegativeXp]];

## 6.3. Recording a Neutral Experience
When a user gets a Neutral experience (neither positive or negative) you can add this code to record the neutral experience for the user.
	
### 6.3.1. Swift Apps Code

	Apertain.logUserXp(viewDelegate: UIViewController, uniqueIdentification: [uniueEvent], 
										valueXp: Apertain.NegativeXp)
	
	Example: Apertain.logUserXp(viewDelegate: self, uniqueIdentification: "SkipLevel", 
										valueXp: Apertain.NeutralXp)
	
### 6.3.2. Objective-C Apps Code

	[Apertain logUserXpWithViewDelegate:self uniqueIdentification:[uniueEvent] 
										valueXp: [Apertain NeutralXp]];
										
	Example: [Apertain logUserXpWithViewDelegate:self uniqueIdentification:@"SkipLevel" 
										valueXp: [Apertain NeutralXp]];
										
### 7. User Data 

If you would like to add more user information like User Name, User E-Mail and Other, you can use the following API call to store custom user data with App Registration.

## 7.1. Swift Apps Code
	
	let user_Name = "Marketing";
	ApertainFactory.setUserName(userName: user_Name);
	
	let user_Mail = "marketing@jkltech.in";
    ApertainFactory.setUserEmail(userEmail: user_Mail);
    
    let my_Key = "level1";
    let strLevel = "Completed";
    let user_Data = ApertainFactory.setUserData(key: my_key, value: strLevel);
    
    let user_Name = ApertainFactory.getUserName();
    let user_eMail = ApertainFactory.getUserEmail();

    let my_Key = "level1";
    let user_Data = ApertainFactory.getUserData(key: my_Key);

## 7.2. Objective-C Apps Code

	NSString *userName = @"marketing";
    [ApertainFactory setUserNameWithUserName: userName];
   
	NSString *userMail = @"marketing@jkltech.in";
    [ApertainFactory setUserEmailWithUserEmail: userMail];
    
    NSString *myKey = @"level1";
    NSString *strLevel = @"Completed";
    [ApertainFactory setUserDataWithKey:myKey value:strLevel];
    
    NSString *user =  [ApertainFactory getUserName];
    
    NSString *email = [ApertainFactory getUserEmail];
    
    NSString *userData = [ApertainFactory getUserDataWithKey:myKey];
    