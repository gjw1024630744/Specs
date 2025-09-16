Pod::Spec.new do |s|
  s.name             = "XbGoogleMaps" # Give your pod a descriptive name
  s.version          = "1.0.0.0" # Match the version of the SDK you downloaded
  s.summary          = "Google Maps SDK for iOS hosted on GitHub." # A brief description
  s.description      = <<-DESC
                       This is a custom Podspec for the Google Maps SDK for iOS,
                       allowing integration from a GitHub repository.
                       DESC
  s.homepage         = "https://github.com/gjw1024630744/Specs" # Replace with the URL of your GitHub repo
  s.license          = { :type => "See Google Maps SDK for iOS license", :file => "LICENSE" } # Include the license file if you have it
  s.author           = { "gjw1024630744" => "1024630744@qq.com" } # Replace with your name and email
  s.source           = { :git => "https://github.com/gjw1024630744/IOSSDK.git", :tag => "#{s.version}" } # Point to your GitHub repo and tag

  s.ios.deployment_target = '16.0' # Or your minimum iOS deployment target

  # This is the crucial part for linking the library and frameworks
  s.vendored_frameworks = 'GoogleMaps/GoogleMaps.xcframework' # Path to the GoogleMaps.xcframework within your repo
  s.resources = 'GoogleMaps/GoogleMapsResources/GoogleMaps.bundle' # Path to the GoogleMaps.bundle within your repo

  # List the required system frameworks and libraries as specified in the Google documentation
  s.frameworks = 'Accelerate', 'Contacts', 'CoreData', 'CoreGraphics', 'CoreImage', 'CoreLocation', 'CoreTelephony', 'CoreText', 'GLKit', 'ImageIO', 'Metal', 'MetricKit', 'OpenGLES', 'QuartzCore', 'Security', 'SystemConfiguration', 'UIKit'
  s.libraries = 'c++', 'bz2', 'resolv.9', 'sqlite3', 'xml2', 'z' # Note: Some libraries might be .tbd in newer SDKs, adjust as needed

  # Add the -ObjC linker flag
  s.user_target_xcconfig = { 'OTHER_LDFLAGS' => '-ObjC' }

end
