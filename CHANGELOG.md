##CHANGELOG for TapPoint SDK

## Version 1.0.0

- The first release of the TapPoint SDK that includes access to four APIs: Authentication, Synchronisation, Triggers and Reporting.


## Version 1.0.1

- Minor bugfix for trigger reporting.


## Version 1.0.2

- Fixed a critical defect which caused triggers previously deleted on TapPoint to not be removed from the handset following synchronisation with the server, resulting in redundant data being persisted on the handset.


## Version 1.1.0

- Added Rate Statistics feature.
- Added Conversion Reporting feature.
- Updated Trigger Schedule funtionality.


## Version 1.1.1

- Now using TapPoint Consumer v2 API (Consumer v1.5 core library).
- Fixed issue with Trigger schedule parsing (BLE v2.8.5 & Utils v1.9 core libraries).


## Version 2.0.0

- Supports multiple beacon networks.
- Eddystone support.
- Apple bitcode compliant.
- Minor fixes.


## Version 2.0.1

- Fixed a defect which caused duplicate beacon notifications on iOS 8.3, 8.4 & 8.4.1.
- Fixed a crash when calculating rate statistics on iOS 7.


## Version 2.1.0

- Added Dwell functionality.
- Added `sdkversion` property to all reporting events.
- Prefixed all reporting events with `TapPoint.`.

## Version 2.2.0

- Added Custom Reporting Event with ability to add custom data.
- Changed TapPoint API end point.
- Updated to Segment Analytics version 3.1.0.
- Minor fixes.

## Version 3.0.0

- Removal of AFNetworking, replaced with native components.
- Removal of the location permission request. Permissions now to be handled app-side.
- Added reporting of Bluetooth switched on/off events.
- Added location_permission core field to all reporting events.

## Version 3.1.0

- Added GeoHex tracking functionality.
- Removed reporting of Bluetooth switched on/off events.
- Updated to Segment Analytics version 3.4.0.

## Version 3.2.0

- Updates to Cocoapods v1.2.0.
- Updated to Segment Analytics version 3.6.0.
- Minor location related bug fixes.

## Version 3.2.1

- Minor bug fixes.

## Version 3.2.2 - 17/05/17

- Minor networking bug fix.

## Version 3.3.0 - 06/07/17

- Added improvements to tracking functionality.

# Version 3.4.0 - 04/12/17

- Added configuration Library and functionality to retrieve a configuration from the server that allows certain features to
be turned off (BLE, Geo and Reporting) as well as changing the write key and reporting endpoint.
- Convenience API that wraps Auth, Sync and Start Monitoring APIs.
- 12 hour defence to calls against TapPoint's Sync API.
- Segment Library is replaced with custom version that allows for the endpoint to be changed through the configuration.

# Version 3.4.1 - 25/04/18

- Fixed a bug which caused application freeze.

# Version 3.5.0 - 18/05/18

- Added new `Visit` reporting event which is sent when a visit is reported by iOS SDK.
- Added a possibility to set user's consent related to storing and using his private data (due to GDPR act).
- Refactored a configuration module (changes under the hood).
- Fixed a defect where an old endpoint was used after app's upgrade.

# Version 3.6.0 - 31/10/18

- Improved dwell algorithm
- Add last_tile_latitude to Geohex transition
- Add last_tile_longitude to Geohex transition
- Add ablity to scan for beacons when within a GeoHex containing a beacon. Otherwise BLE scanning is disabled
- Ability to enable Granular Location Update events when the user is in GeoHex's flagged as POIs
- Ability to enable Location Update events in general for the user
- Add logging feature introduced for: better integration with clients, live troubleshooting, QA
- Regression confirmed support of OS12

# Version 3.6.1 - 28/02/19

- Improved flushing logic for SDK events

# Version 3.7.0 - 04/11/19

- iOS13 Support
- Support for non-BLE applications
- General bug fixes
