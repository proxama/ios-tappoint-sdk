Pod::Spec.new do |s|
  s.name                  = 'TapPointSDK'
  s.version               = '3.0.0'
  s.summary               = 'An beacon library used to interact with the TapPoint network effortlessly.'
  s.description           = <<-DESC
                          TapPoint SDK makes it easy to take advantage of Bluetooth beacons, enabling you to focus on creating the best possible app experience for your users. Once integrated it enables your app to detect nearby beacons and trigger content specific to that beacon's location.
                          DESC

  s.homepage              = 'http://developer.tappoint.com/'
  s.license               = { :type => 'Apache 2.0', :file => 'Licence.txt' }
  s.author                = { "Proxama iOS Dev Team" => "iosdev@proxama.com" }
  s.source                = { :git => 'https://github.com/proxama/ios-tappoint-sdk.git', :tag => 'v3.0.0' }
  s.social_media_url      = 'https://twitter.com/proxama?lang=en-gb'
  s.platform              = :ios
  s.ios.deployment_target = '8.0'

  s.framework             = 'CoreData', 'CoreLocation', 'Foundation'
  s.dependency            'Analytics', '~> 3.1.0'

  s.source_files          = 'TapPointSDK/TapPointSDK.framework/Versions/A/Headers/*.h'
  s.public_header_files   = 'TapPointSDK/TapPointSDK.framework/Versions/A/Headers/*.h'
  s.vendored_frameworks   = 'TapPointSDK/TapPointSDK.framework'
  s.resource              = 'Resources/*.bundle'
 
  s.xcconfig              =  {  'LIBRARY_SEARCH_PATHS' => '"$(PODS_ROOT)/TapPointSDK"',
                                'HEADER_SEARCH_PATHS' => '"${PODS_ROOT}/Headers/TapPointSDK"' }
end
