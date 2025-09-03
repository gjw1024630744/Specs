Pod::Spec.new do |s|
  s.name         = "PAGSShortPlay"
  s.version      = "1.7.0.1"
  s.summary      = "Short drama SDK built for overseas."
  s.description  = "Short drama SDK built for overseas."
  s.homepage     = "https://github.com/gjw1024630744/PAGSShortPlay"
  s.license      = { :type => 'MIT', :file => 'LICENSE' }  # 建议 LICENSE 放仓库根目录
  s.authors      = { "gjw1024630744" => "1024630744@qq.com" }
  s.platform     = :ios, "12.0"
	s.source   = { :git => 'https://github.com/gjw1024630744/PAGSShortPlayIOSSDK.git', :tag => '1.7.0.1' }

  s.frameworks = "UIKit", "CoreFoundation", "WebKit", "StoreKit", "CoreServices", "MediaPlayer", "CoreMedia", "AVFoundation", "CoreTelephony", "SystemConfiguration", "AdSupport", "CoreMotion", "Accelerate"
  s.weak_frameworks = "AppTrackingTransparency"
  s.libraries = 'z', 'bz2', 'resolv.9', 'c++', 'sqlite3', 'xml2', 'c++abi'

  # 编译配置
  s.pod_target_xcconfig = {
    'OTHER_LDFLAGS' => '-ObjC',
    'COMPILER_INDEX_STORE_ENABLE' => 'NO',
    'LLVM_LTO[config=Debug][sdk=*][arch=*]' => 'NO',
    'LLVM_LTO[config=Release][sdk=*][arch=*]' => 'NO',
    'GCC_OPTIMIZATION_LEVEL[config=Debug][sdk=*][arch=*]' => '0',
    'GCC_OPTIMIZATION_LEVEL[config=Release][sdk=*][arch=*]' => 'z',
    'ASSETCATALOG_COMPILER_OPTIMIZATION' => 'space',
    'CLANG_ALLOW_NON_MODULAR_INCLUDES_IN_FRAMEWORK_MODULES' => 'YES',
    'VALID_ARCHS' => 'x86_64 arm64',
		'INFOPLIST_FILE' => '',
		'CODE_SIGNING_ALLOWED' => 'NO'
  }

  s.requires_arc = true

  # 默认 subspec
  s.default_subspec = 'standard'

  # Core subspec，提供基础 framework + bundle + 公共依赖
  s.subspec 'Core' do |ss|
		ss.vendored_frameworks = ['SDK/PAGSShortPlay.xcframework']
		ss.preserve_paths = 'SDK/PAGSShortPlay.xcframework'
		ss.resource = 'SDK/PAGSShortPlay.bundle'
    ss.dependency 'AFNetworking','>= 4.0.0'
    ss.dependency 'YYModel','>= 1.0.1'
    ss.dependency 'SDWebImage','>= 5.12.0'
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
