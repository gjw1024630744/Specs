Pod::Spec.new do |s|
  s.name             = 'GoogleMaps'
  s.version          = '1.0.0.0'
  s.summary          = 'Google Maps SDK for iOS packaged as a CocoaPod.'
  s.description      = 'Google Maps SDK for iOS XCFramework + Resources.'

  s.license          = { :type => 'MIT' }
  s.author           = { 'gjw1024630744' => '1024630744@qq.com' }
  s.homepage         = "https://github.com/gjw1024630744/Specs"
  s.source           = { :git => 'https://github.com/gjw1024630744/IOSSDK.git', :tag => s.version.to_s }
  s.platform         = :ios, "16.0"

  # vendored frameworks + 资源
  s.vendored_frameworks = "GoogleMaps/GoogleMaps.xcframework"
  s.resources           = "GoogleMaps/GoogleMapsResources/GoogleMaps.bundle"

  # 系统 frameworks
  s.frameworks = [
    "Accelerate", "Contacts", "CoreData", "CoreGraphics", "CoreImage",
    "CoreLocation", "CoreTelephony", "CoreText", "GLKit", "ImageIO",
    "Metal", "MetricKit", "OpenGLES", "QuartzCore", "Security",
    "SystemConfiguration", "UIKit"
  ]

  # 系统库
  s.libraries = "c++", "z"

  # 强制指定链接方式
  s.pod_target_xcconfig = {
    "OTHER_LDFLAGS" => "$(inherited) -ObjC -framework GoogleMaps -lc++ -lz",
    "CLANG_ALLOW_NON_MODULAR_INCLUDES_IN_FRAMEWORK_MODULES" => "YES",
    "FRAMEWORK_SEARCH_PATHS" => "$(inherited) $(PODS_ROOT)/GoogleMaps"
  }
end
