//
//  PRXConsentStatus.h
//  TapPointSDK
//
//  Created by Dominik Ostrowski on 18.04.2018.
//  Copyright © 2018 Proxama Solutions Ltd. All rights reserved.
//

/**
 * A PRXConsentStatus represents the user data consent status
 */
typedef NS_ENUM(NSUInteger, PRXConsentStatus) {
	/**
	 * Indicates that user have not specified permission and we can act as if he has NOT granted them
	 */
	PRXConsentStatusUndefined = 0,
	
	/**
	 * Indicates that user allows us to use his data
	 */
	PRXConsentStatusOptIn = 1,
	
	/**
	 * Indicates that user does not allow us to use his data
	 */
	PRXConsentStatusOptOut = 2,
};
