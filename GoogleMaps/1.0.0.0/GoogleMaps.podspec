Pod::Spec.new do |s|
  s.name            = 'GoogleMaps'
  s.version         = '1.0.0.0'
  s.summary         = 'Google Maps SDK for iOS packaged as a CocoaPod.'
  s.description     = 'Google Maps SDK for iOS XCFramework + Resources.'

  s.license          = { :type => 'MIT' }
  s.author           = { 'gjw1024630744' => '1024630744@qq.com' }
  s.homepage     = "https://github.com/gjw1024630744/Specs"
	s.source   = { :git => 'https://github.com/gjw1024630744/IOSSDK.git', :tag => s.version.to_s }
  s.platform         = :ios, "16.0"
	s.frameworks = "Accelerate", "Contacts", "CoreData", "CoreGraphics", "CoreImage",
    "CoreLocation", "CoreTelephony", "CoreText", "GLKit", "ImageIO",
    "Metal", "MetricKit", "OpenGLES", "QuartzCore", "Security",
    "SystemConfiguration", "UIKit"
	s.libraries = 'z', 'bz2', 'resolv.9', 'c++', 'sqlite3', 'xml2', 'c++abi'
  s.weak_frameworks = 'AppTrackingTransparency'

  s.default_subspec = ['standard']
	
	# 配置
	s.pod_target_xcconfig = {
	  'OTHER_LDFLAGS' => '-ObjC',
	  'COMPILER_INDEX_STORE_ENABLE' => 'NO',
	  'LLVM_LTO[config=Debug][sdk=*][arch=*]' => 'NO',
	  'LLVM_LTO[config=Release][sdk=*][arch=*]' => 'NO',
	  'GCC_OPTIMIZATION_LEVEL[config=Debug][sdk=*][arch=*]' => '0',
	  'GCC_OPTIMIZATION_LEVEL[config=Release][sdk=*][arch=*]' => 'z',
	  'ASSETCATALOG_COMPILER_OPTIMIZATION'=>'space',
	  'CLANG_ALLOW_NON_MODULAR_INCLUDES_IN_FRAMEWORK_MODULES'=>'YES',
	  'CODE_SIGNING_ALLOWED' => 'NO',
	  'VALID_ARCHS' => 'x86_64 arm64'
	}
  
	# Core subspec，提供基础 framework + bundle + 公共依赖
  s.subspec 'Core' do |ss|
		ss.vendored_frameworks = ['GoogleMaps/GoogleMaps.xcframework']
		ss.preserve_paths = 'GoogleMaps/GoogleMaps.xcframework'
		ss.resource = 'GoogleMaps/GoogleMapsResources/GoogleMaps.bundle'
  end
  
  # 标准版 subspec
  s.subspec 'standard' do |ss|
    ss.dependency 'GoogleMaps/Core'
  end
end