A(P)ertain SDK v0.9.0 for iOS - Getting Started (For XCode)
========================================================================

This document describes how to get started using the A(P)ertain SDK v0.9.0 for iOS.

Before you Begin
----------------

Before implementing the SDK, make sure you have the following:

* Download the A(P)ertain SDK Libraries from [here](https://github.com/jkltech/apertain-sdk-ios).
* Add the Libraries into your iOS App Project using the instructions over [here](https://github.com/jkltech/apertain-sdk-ios/blob/master/XCode_Instructions.md).

Getting Started
---------------

### 1. Changes to Android Application Manifest

To integrate APertain with the App, the following changes are needed in the Android App Manifest file (AndroidManifest.xml).

#### 1.1. Permissions for A(P)ertain

A(P)ertain tries to be as non-intrusive with minimal permissions as required to provide the developers the best possible App data as well as App User Analytics as possible.

The developers can update their project’s AndroidManifest.xml file by adding the following permissions:

    <!-- A(P)ertain Essential Permissions -->
    <uses-permission android:name="android.permission.INTERNET" />
    <uses-permission android:name="android.permission.ACCESS_NETWORK_STATE" />
    <uses-permission android:name="android.permission.READ_PHONE_STATE" /> 
    <!-- A(P)ertain Optional Permissions -->
    <uses-permission android:name="android.permission.GET_ACCOUNTS" /> <!-- To get user name and email -->
	<uses-permission android:name="android.permission.RECEIVE_BOOT_COMPLETED" /> <!-- To start necessary Services on boot completion -->
    <uses-permission android:name="android.permission.ACCESS_COARSE_LOCATION" /> <!-- To track location of the Users -->
    <uses-permission android:name="android.permission.ACCESS_FINE_LOCATION" /> <!-- To track accurate location of the Users -->
	
Other than the permissions the following entries should be added to initiate relevant APertain features.

#### 1.2. For Initiating A(P)ertain (Before first run of App)

Mobile Users tend to forget that they have downloaded an App, so to make sure they run the App and get to know about it, we need to send in Mobile User Onboarding Push Notifications. This can happen only when APertain is registered even if the user hasn't run the App once. These parameters passed in will help achieve that goal.

	<-- For Inititating Apertain Service before first Run of App -->
	<meta-data android:name="com.jkl.apertain.APP_UNIQUE_ID" android:value="APP_UNIQUE_ID" />

	<meta-data android:name="com.jkl.apertain.USER_APP_SIGNATURE" android:value="USER_APP_SIGNATURE" />
	
#### 1.3. For Enabling Mobile User Onboarding Drip Push Notifications

Mobile User Onboarding Drip Push Notifications is a way to engage the Users even if they haven't yet started using the App. Otherwise, there are users who have downloaded the App and have forgotten what the App is about. This is a way to remind the users that there is a fabulous App they have downloaded with all such wonderful features they should take a look at.

	<-- For Mobile User OnBoarding Drip Push Notifications & Reports -->
	<service android:name="com.jkl.apertain.fcm.NotificationIntentService"/>
	<service android:name="com.jkl.apertain.fcm.SendNotificationService"/>
	<receiver android:name="com.jkl.apertain.fcm.NotificationEventReceiver"/>
	<receiver android:name="com.jkl.apertain.fcm.NotificationClearService"/>
	
#### 1.4. Smart Push Notifications

Using Smart Push Notifications feature of APertain needs a specific set of classes to be invoked. Please copy the following entries to enable these features.

	<-- For Push Notification -->
	<service android:name="com.jkl.apertain.fcm.APertainFCMService" android:exported="true">
		<intent-filter android:priority="-500">
			<action android:name="com.google.firebase.MESSAGING_EVENT" />
		</intent-filter>
	</service>

	<service android:name="com.jkl.apertain.fcm.APertainFCMInstanceIdService" android:exported="true">
		<intent-filter android:priority="-500">
			<action android:name="com.google.firebase.INSTANCE_ID_EVENT" />
		</intent-filter>
	</service>

	<receiver android:name="com.jkl.apertain.util.APertainBroadcastReceiver" android:enabled="true">
		<intent-filter>
			<action android:name="android.intent.action.BOOT_COMPLETED"/>
			<action android:name="android.intent.action.QUICKBOOT_POWERON" />
			<action android:name="android.intent.action.NOTIFY" />
		</intent-filter>
	</receiver>
	
	<-- For Customizing Push Notification On Click Event -->
	<meta-data android:name="com.jkl.apertain.fcm.ApertainPushActionListener"
		android:value="APP_IMPLMENTATION_OF_APERTAIN_PUSH_ACTION_LISTENER_INTERFACE" />

	<-- For Push Notification Logo since Android 5.0 Lollypop -->
	<meta-data android:name="app_logo_resource_id"
		android:resource="@drawable/APP_WHITE_LOGO_WITH_BACKGROUND" />
	
### 2. Initialize the SDK

In the Activity that loads your app write the following code in onCreate(), to initialize the A(P)ertain SDK. This should be called only once in your App/Game on the first Activity loaded by the App/Game.
	
The App Unique ID and User App Signature are generated as you add the App in A(P)ertain SaaS backend. These unique ids will identify the App and the User registered with the A(P)ertain SaaS backend.

	String appUniqueID = "xxxxxxxxxx";
	String userAppSignature = "xxxxx";
	
	appUniqueID = ApertainUtil.getAppUniqueID(context);
	userAppSignature = ApertainUtil.getUserAppSignature(context);
	
	try {
		ApertainFactory.init(context, appUniqueID, userAppSignature);
		ApertainFactory.setUserName(userName); //Optional. If Game/App has collected username from User
		ApertainFactory.setUserEmail(userEmail); //Optional. If Game/App has collected e-mail from User
	} catch (ApertainException ape) {
		Log.e(TAG, "Error while initializing A(P)ertain " + ape.getMessage(), ape);
	}

If you would like to add more user information other than User Name and User E-Mail, you can use the following API call to store custom user data with App Registration.

	ApertainFactory.setUserData(context, key, value); /* Where key is any String value which represents the data stored and value is the actual value for the key */

#### 2.1 Destroy the A(P)ertain Object

In onDestroy() call the following code to cleanup the A(P)ertain instance created.

	ApertainFactory.destroyAPertainInstance(context);

### 3. Logging User Experience

From within the App/Game, a user tends to experience various levels of emotions as they pass-through various obstacles or processes intended to be executed within the App/Game. When the Mobile Developer records such experiences it enables the App to be more pro-active based on User Experiences to provide additional means to execute the App/Game processes. 

A(P)ertain allows such User Experiences to be recorded and then use those specific experience values to further add relevant process flows related to the App/Game.

#### 3.1 Recording a Positive User Experience

Whenever a positive experience occurred (eg., Level Completion in a game or Achieving some Milestone in a fitness App, etc.,) the developer can add this code to record the positive experience gained by the user.

	Apertain.logUserXp(Activity, [Event_Name], XP);

	Example: Apertain.logUserXp(this, "WorkoutComplete", Apertain.POSITIVEXP);

Here, the [Event_Name] is used as a User Experience Parameter which can be further used in Rules defined for Pertain Engine as well as Smart Rating & Feedback Prompts..

#### 3.2 Recording a Negative User Experience

When a user gets a negative experience (eg., Level Failed or invalid process input) you can add this code to record the negative experience for the user.

	Apertain.logUserXp(Activity, [Event_Name], XP);

	Example: Apertain.logUserXp(this, "LevelFailed", Apertain.NEGATIVEXP);

#### 3.3 Recording a Neutral Experience

When a user gets a Neutral experience (neither positive or negative) you can add this code to record the neutral experience for the user.

	Apertain.logUserXp(Activity, [Event_Name], XP);

	Example: Apertain.logUserXp(this, "NameEntered", Apertain.NEUTRALXP);

### 4. Smart Rating Prompt Configuration

In-App Rating Prompt Flow an intelligent program flow that shows the Rating Prompt to each user according to their behavior & past experiences within the App/Game. The prompt flow is shown based on the experience user has gained in the App/Game according to the configuration made by the developer in A(P)ertain SaaS backend.

#### 4.1 Showing Smart Rating Prompt

The following code shows the Smart Rating Prompt when the conditions as configured in A(P)ertain SaaS backend are met. 

When the Rating Prompt shows up, it takes the user to rate your app in Play Store (or Amazon App Store). Use the following code to show the Rating Prompt as the related conditions are met. This can be called from any part/process of your activity where you like to show the Rating Prompt.

	Apertain aPertainInstance = null;
	try {
		aPertainInstance = ApertainFactory.getApertainInstance(context);
	} catch (ApertainException ape) {
		Log.e(TAG, "Error while creating A(P)ertain Instance" + ape.getMessage(), ape);
	}


	if (aPertainInstance != null) {
		aPertainInstance.showRatingFlowIfConditionsAreMet("<User Experience Parameter>");
		// Empty String in the above method means a cumulative Positive Experience Count.
	}
	
If you would just like to show your rating prompt from a menu item or your own smart conditions, please use the following code,

	if (aPertainInstance != null) {
		aPertainInstance.showRatingPrompt();
	}

As showing the Rating Prompt popup will invade the flow of your App, if you would like to pause and resume your underlying Activity or Fragment code, please implement the ResumableActivity with methods pauseActivity() and resumeActivity() to add a callback for pausing and resuming the underlying activity or Fragment. 

### 5. A(P)ertain App Support Chat Interface

A(P)ertain App Support Chat Interface provides a means messenger style communication (conversation) interface for the user and the Mobile Developer. The below code provides a native A(P)ertain Support icon view which when clicked will open up the App Support Chat Interface. 

As a developer you can place this view in any layout of your choice to let the user open up the App Support Chat Interface.

	Apertain aPertainInstance = null;
	try {
		aPertainInstance = ApertainFactory.getApertainInstance(context);
	} catch (ApertainException ape) {
		Log.e(TAG, "Error while creating A(P)ertain Instance" + ape.getMessage(), ape);
	}
	
#### 5.1 App Support Chat View as a Popup within your Activity or Fragment:

Please add the following code to show the App Support Chat View as a Popup in your Activity or Fragment.

	View view = aPertainInstance.getAppSupportChatterView();
	layout.addView(view);

Most developers add the App Support Chat Icon to the layout defining their own Action Bar for the App/Game.

Alternatively you can have your own icon to show the Support Chat Interface and add the click listener to that layout or button and call the following code inside onClick:

	apertainInstance.showApertainConversationChatter();

As showing the In-App Support Chat will invade the flow of your App, if you would like to pause and resume your underlying Activity or Fragment code, please implement the ResumableActivity with methods pauseActivity() and resumeActivity() to add a callback for pausing and resuming the underlying activity or Fragment.

#### 5.2 App Support Chat View as a Fragment:

Please add the following code to show the App Support Chat View as another Fragment in your App.

	android.app.Fragment inAppSupportFragment = new InAppSupportFragment();
	FragmentManager fragmentManager = getFragmentManager();
	FragmentTransaction fragmentTransaction = fragmentManager.beginTransaction();
	fragmentTransaction.replace(R.id.frame_container, inAppSupportFragment);
	fragmentTransaction.commit();

#### 5.3 App Support Chat View as an Activity:

Please add the following code to show the App Support Chat View as another Activity in your App.

	Intent inAppSupportActivityIntent = new Intent(context, InAppSupportActivity.class);
	startActivity(inAppSupportActivityIntent);
	
#### 5.4 Custom In App Support View’s Title and Action bar Color

The following function is used to change the Action bar color and title for Activity and Fragment.

	int color = getResources().getColor(R.color.light_red);
	String title = "APertain In-App Support View";/* Limited to 25 to 30 Letters based on Character width */
	
	ApertainFactory.setInAppSupportTitle(context, title, color);

### 6. Tracking Activities & Processes

A(P)ertain as part of the App Analytics feature needs to keep track of the Activities and Processes which are initiated by the App/Game. An Activity is an Android Activity within which there can be many processes initiated and concluded. 

Within the Activity’s class onStart, onStop, onPause, onResume methods can be overridden to include A(P)ertain’s Activity Tracking code. Similarly whenever the Developer initiates a special process within the Activity which needs to be tracked, specific code can be written by naming the process to keep track of it.

**NOTE**: A(P)ertain start, pause, resume, stop code should be called on all the activities.

#### 6.1 Start A(P)ertain Activity Tracking

In onStart() add the following code to start tracking an Activity

	Apertain.start(this);

#### 6.2 Pause A(P)ertain Activity Tracking

In onPause() add the following code to mention to A(P)ertain this Activity is paused 

	Apertain.pause(this);

#### 6.3 Resume A(P)ertain Activity Tracking

In onResume() add the following code to mention to A(P)ertain this Activity is resumed

	Apertain.resume(this);

#### 6.4 Stop A(P)ertain Activity Tracking

In onStop() add the following code to mention to A(P)ertain this Activity is stopped

	Apertain.stop(this);

#### 6.5 Start A(P)ertain Process Tracking

Sometimes we create separate streams of work within the Activity which engage with the User in a manner to start and complete a process. For example, we may be in a screen where the user initiates in-app purchase, now even though the Activity is not just intended for in-app purchase, by creating a separate process within the Activity it becomes difficult for the developer to ascertain the result of this process and why User successfully purchased or not. 

Hence by tracking the process independent of the Activity as a named process, A(P)ertain enables the developer to track User engagement outside the initial screen which initiated the process.

Here, you have the code for starting the process tracking.

	Apertain.startProcess([processName], Activity);

	Example: Apertain.startProcess(“In-App-Purchase”, this);

#### 6.6 Stop A(P)ertain Process Tracking

Here, you have the code for stopping the tracking of a process as it completes.

	Apertain.stopProcess([processName], Activity);

	Example: Apertain.stopProcess(“In-App-Purchase”, this);

**Note**: All Process tracking are ceased when the Activity which starts the process tracking is stopped and destroyed.

### 7. App Analytics Uploader Service

A(P)ertain uses a background process to initiate uploading of App Analytics parameters into the A(P)ertain Server to analyze and provide insights into App User Behavior. To enable this the Uploader Service has to be initiated within the AndroidManifest.xml on every App.

Please enter the below tags within the Application tag of your App to enable the UploadService for A(P)ertain.

	<service 
	    android:name="com.jkl.apertain.service.UploadService"
	    android:label="UploadService" >
	</service>

### 8. Social Share

Social Media is a wonderful way to let your Users Engage with their friends as well as publicize your App on your behalf among their network of friends.

To easily enable this type of sharing among Users, we have provided an intuitive User Interface. It is designed as a Popup that contains the share buttons on your interested Social Networks. Clicking this button allows users to share links and descriptions directly to Social Networks such as Twitter, Facebook & WhatsApp.

**NOTE**: We only Support the above Social Networks now!

If one of these social networks is not installed in the Device it will show default share options E-Mail & Messaging.

If the Device any of the above Social Networks and E-Mail & Messaging is also unavailable, then it would show up with “Device doesn’t have Supported Sharing Options” as a Toast Message.

This User Interface can be initiated with this function call having Four arguments:

1. Arg 1: Integer array of String Resource array that mention the social network software.
2. Arg 2 : String Resource that mention the App URL or any other to be shared URL.
3. Arg 3 : String Resource that mention Text to share.
4. Arg 4(Optional) : String Resource that mention Subject. Use this only if you want to share via E-Mail.

Example:

	int[] shareArray = {R.string.facebook, R.string.twitter, R.string.whatsapp};
	int url = R.string.sharing_app_url;
	int textToBeShared = R.string.text_to_be_share;
	int emailSubject = R.string.subject_to_share;
	   			 
	if (apertainInstance != null)
	{
		apertainInstance.showSocialSharePopupUI(shareArray, url, textToBeShare);
	
(or)

		apertainInstance.showSocialSharePopupUI(shareArray, url, textToBeShared, emailSubject);
	}

### 9. Customer On-Boarding UI

All Applications need a relevant on-boarding User Interface to explain What the App is about and How to use the App. Customer on-boarding is nothing but an inituitive way to introduce the App’s premise to the end users. This interface is your chance to inform, to inspire, and to get the user excited about using your App. This is one of the commonly used aspects of "User Experience" (UX) design, but is often overlooked by the App Developer.

The Customer On-Boarding UI will be used as a self explanatory introduction to your application. A(P)ertain provides a powerful On-Boarding UI which is completely customizable. All you have to do is to decide how many Screens needed for the app intro and choose of Images, Title Text, Description and Background color for each Screen respectively. 

Here is the Sample UI of a single screen in A(P)ertain On-Boarding UI.

![Image of Customer On-boarding UI Design Sample](./images/customer_onboarding_ui_sample.jpg)

#### 9.1. A(P)ertain OnBoardingUI has Four arguments:

1. Integer array of resource that mention images for each page (each for landscape and portrait orientations).
2. Integer array of resource that mention Title text for each page.
3. Integer array of resource that mention Description Text for each page.
4. Integer array of resource that mention Background colors for each page.
5. Integer array of resource that mentions whether screenshot is bottom or top oriented.

The array size determines the number of Screens in the Customer On-Boarding UI. For example the array for each argument is four, you will get four Screens.

The sample arrays.xml for declaring the Screenshot Images, Title, Description & Background Colors can be looked up over [here](./resources/arrays.xml)

**NOTE**: It is recommended to keep the On-Boarding UI to 3-5 intriguing screenshot or usage introductions.

#### 9.2. To get the A(P)ertain Customer On-Boarding UI use the following code snippet: 

	/**
	 **	You can use the arrays.xml to add values for the following arrays in your App
	 **	Please refer the url above for arrays.xml sample.
	 */
	String[] titlesStrArr = getResources().getStringArray(R.array.onboarding_ui_titles);
	String[] descStrArr = null;//getResources().getStringArray(R.array.onboarding_ui_descriptions);
	int[] onboardingImagesLand = R.array.onboard_ui_images_land;
	int[] onboardingImagesPortrait = R.array.onboard_ui_images_portrait;
	int[] onboardingUIBackgroundColors = R.array.onboard_ui_colors;
	

	/**
	 ** Integers to mention mobile template image in Onboarding. 
	 ** If onBoardingMobileTemplateMode is null, it will take default value (i.e) 0.
	 ** 0 - Top Image
	 ** 1 - Bottom Image
	 */
	int[] onBoardingMobileTemplateMode = R.array.onboarding_ui_mode;
	
	/* You can use either Fragment class or a FragmentActivity class to show up onboarding UI */
	android.support.v4.app.FragmentActivity fragmentActivity = (FragmentActivity)activity;

	/**
	 ** If you don't want the description in the UI, 
	 ** please leave the descriptionText array as a null parameter, 
	 ** similarly for bgColors array.
	 */
	Apertain apertainInstance = null;
	try {
		apertainInstance = ApertainFactory.getApertainInstance(context);
	} catch (ApertainException e) {
	}

	if (apertainInstance != null) {
		apertainInstance.showUserOnboardingUI(fragmentActivity, onboardingImagesLand, onboardingImagesPortrait, onboardingUIBackgroundColors,
												titlesStrArr, descStrArr, onBoardingMobileTemplateMode);
	}

### 10. Push Notifications

If you would like to integrate Push Notifications with your App using APertain SDK, first of all you should move your App to Android Studio. APertain uses FCM (Firebase Cloud Messaging) to integrate Push Notifications within your App. 

Google has deprecated GCM (Google Cloud Messaging) which relied on Android Device IDs. Now with FCM, you just need an Authorization Token from the Device to push Notifications. You don't need Android Device IDs. 

This is the way forward as handling Android Device IDs were affecting lots of parameters of User Privacy. 

Also you should use the AAR (Android Archive Library: The 'aar' bundle is the binary distribution of an Android Library Project.) bundle of the APertain SDK available over [here](https://github.com/jkltech/apertain-as-aar).

Please see the instructions to integrate an AAR file into the Android Studio Project of your App fromt the following [URL](./AAR_Integration_Instructions.md).

#### 10.1 Push Notification Configuration:

[Login](https://www.apertain.com/login.apt) to the APertain Console, and navigate to "Interactions --> Push Notifications --> Push Configuration".

In this page you configure the Push Configuration from your App's Firebase Cloud Messaging Console, also known as [FCM Console](https://console.firebase.google.com) following the steps provided [here](./Firebase_Instructions.md).

When the APertain inititialization code is executed, APertain automatically registers the FCM Push Notifications to be listened by the APertain SDK. There is no additional coding needed. If you would like to subscribe for more Push Notifications from FCM, you can do so.

If you would like to handle the APertain Push Notifications in a custom manner and push your own Notifications from your custom code, you would need to implement the interface APertainPushActionListener and mention the same in the AndroidManifest.xml. 

	<!-- Android Manifest meta-data to configure which class in your App implements ApertainPushActionListener interface -->
	<meta-data android:name="com.jkl.apertain.fcm.ApertainPushActionListener" android:value="com.yourcompany.yourapp.yoursubpackage.ApertainDemoPushActionListener" />

Please refer for a sample code [here](./resources/ApertainDemoPushActionListener.java) managing how to push the Notification to the Device show up a custom activity or fragment within your App.
