#
# Be sure to run `pod lib lint Ads-CN.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'PAGSShortPlay'
  s.version         = '1.8.0.1'
  s.summary          = 'PAGSShortPlay is a SDK from Bytedance providing union AD service.'
  s.description      = <<-DESC
  PAGSShortPlay provides ADs which include native、banner、RewardVideo、FullscreenVideo etc.
                       DESC

  s.license          = { :type => 'MIT', :file => 'PAGSShortPlay/LICENSE' }
  s.author           = { 'gjw1024630744' => '1024630744@qq.com' }
  s.homepage     = "https://github.com/gjw1024630744/Specs"
	s.source   = { :git => 'https://github.com/gjw1024630744/IOSSDK.git', :tag => '1.8.0.1' }
  s.platform         = :ios, "12.0"
	s.frameworks = "UIKit", "CoreFoundation", "WebKit", "StoreKit", "CoreServices", "MediaPlayer", "CoreMedia", "AVFoundation", "CoreTelephony", "SystemConfiguration", "AdSupport", "CoreMotion", "Accelerate"
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
	  ###symolocation，don't delete
	}
  
	# Core subspec，提供基础 framework + bundle + 公共依赖
  s.subspec 'Core' do |ss|
		ss.vendored_frameworks = ['PAGSShortPlay/PAGSShortPlay.xcframework']
		ss.preserve_paths = 'PAGSShortPlay/PAGSShortPlay.xcframework'
		ss.resource = 'PAGSShortPlay/PAGSShortPlay.bundle'
  end
  
  # 标准版 subspec
  s.subspec 'standard' do |ss|
    ss.dependency 'PAGSShortPlay/Core'
    ss.dependency 'TTSDKFramework/Player-SR', '1.47.200.2-standard'
  end
  
  # 高级版 subspec
  s.subspec 'premium' do |ss|
    ss.dependency 'PAGSShortPlay/Core'
    ss.dependency 'TTSDKFramework/Player-SR', '1.47.200.2-premium'
  end
end