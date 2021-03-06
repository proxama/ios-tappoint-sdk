Pod::Spec.new do |s|
  s.name                  = 'TapPointSDK'
  s.version               = '3.7.0'
  s.summary               = 'iOS beacon library used to interact with the TapPoint network effortlessly.'
  s.description           = <<-DESC
                          TapPoint SDK makes it easy to take advantage of Bluetooth beacons, enabling you to focus on creating the best possible app experience for your users. Once integrated it enables your app to detect nearby beacons and trigger content specific to that beacon's location.
                          DESC

  s.homepage              = 'http://developer.tappoint.com/'
  s.license               = { :type => 'Commercial', :file => 'Licence.txt' }
  s.author                = { "Proxama PLC" => "support@proxama.com" }
  s.source                = { :git => 'https://github.com/proxama/ios-tappoint-sdk.git', :tag => 'v3.7.0' }
  s.social_media_url      = 'https://twitter.com/LocationSci'
  s.platform              = :ios
  s.ios.deployment_target = '8.0'
  s.requires_arc          = true

  s.framework             = 'CoreData', 'CoreLocation', 'Foundation', 'AdSupport'

  s.vendored_frameworks   = 'TapPointSDK/TapPointSDK.framework'
  s.resource              = 'Resources/*.bundle'
end
