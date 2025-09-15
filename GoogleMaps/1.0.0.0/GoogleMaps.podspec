Pod::Spec.new do |s|
  s.name             = 'GoogleMaps'
  s.version          = '1.0.0.0'
  s.summary          = 'Google Maps SDK for iOS packaged as a CocoaPod.'
  s.description      = <<-DESC
  Google Maps SDK for iOS provides map rendering, geolocation,
  and related services as a single XCFramework + resources bundle.
  From v9.2.0, GoogleMapsCore and GoogleMapsBase have been merged
  into GoogleMaps.xcframework, no extra setup required.
  DESC

  s.license          = { :type => 'MIT', :file => 'GoogleMaps/LICENSE' }
  s.author           = { 'gjw1024630744' => '1024630744@qq.com' }
  s.homepage         = "https://github.com/gjw1024630744/Specs"
  s.source           = { :git => 'https://github.com/gjw1024630744/IOSSDK.git', :tag => '1.0.0.0' }
  s.platform         = :ios, "16.0"

  # Google Maps SDK 所需系统 frameworks
  s.frameworks       = [
    "Accelerate", "Contacts", "CoreData", "CoreGraphics", "CoreImage",
    "CoreLocation", "CoreTelephony", "CoreText", "GLKit", "ImageIO",
    "Metal", "MetricKit", "OpenGLES", "QuartzCore", "Security",
    "SystemConfiguration", "UIKit"
  ]

  # 必需系统库
  s.libraries        = "c++", "z"

  s.pod_target_xcconfig = {
    "OTHER_LDFLAGS" => "-ObjC",
    "CLANG_ALLOW_NON_MODULAR_INCLUDES_IN_FRAMEWORK_MODULES" => "YES"
  }

  # XCFramework + 资源
  s.vendored_frameworks = ["GoogleMaps/GoogleMaps.xcframework"]
  s.resources           = ["GoogleMaps/GoogleMapsResources/GoogleMaps.bundle"]
  s.preserve_paths      = "GoogleMaps/GoogleMaps.xcframework"
end
