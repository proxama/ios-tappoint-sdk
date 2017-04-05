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
- Adds new `GeoHex Safety Fence` reporting event which is sent when the safety geofence is left.
- Adds new `GeoHex Location Failed` reporting event which is sent when the SDK is unable to get a location.
- Added `Location Permission Change` reporting event.
- Added additional properties to reporting events related to Location.
- Fixed a defect where some Location Managers were not being created on the main thread.