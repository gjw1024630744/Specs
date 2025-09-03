

Pod::Spec.new do |s|
  s.name         = "PAGSShortPlay"
  s.version      = "1.7.0.0"
  s.summary      = "Short drama sdk built for overseas."
  s.description  = <<-DESC
  Short drama sdk built for overseas.
                    DESC
  s.homepage     = "https://github.com/gjw1024630744/PAGSShortPlaySpecs.git"
  s.license          = { :type => 'MIT', :file => 'SDK/LICENSE'}
  s.authors      = { "gjw1024630744" => "1024630744@qq.com"}
  s.platform     = :ios, "12.0"
  s.source       = { :http => "https://sf16-fe-tos-sg.i18n-pglstatp.com/obj/bu-rely-framework-sg/shortplay/1.7.0.0/SDK.zip" }
  s.frameworks = "UIKit", "CoreFoundation", "WebKit", "StoreKit", "CoreServices", "MediaPlayer", "CoreMedia", "AVFoundation", "CoreTelephony", "SystemConfiguration", "AdSupport", "CoreMotion", "Accelerate"
  s.weak_frameworks = "AppTrackingTransparency"
  s.libraries = 'z', 'bz2', 'resolv.9', 'c++', 'sqlite3', 'xml2', 'c++abi'

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

  s.requires_arc = true

#  s.prefix_header_file = 'PAGShortPlay/Classes/PAGS-prefix.pch'

  # 默认使用业务的标准版本
  s.default_subspec = ['standard']

  #业务的标准版本
  s.subspec 'standard' do |ss|
    ss.dependency 'PAGSShortPlay/Core'
    ss.dependency 'TTSDKFramework/Player-SR','1.47.200.2-standard'
  end

  ##业务的定制版本 ，BP sdk使用高级版
  s.subspec 'standard' do |ss|
    ss.dependency 'PAGSShortPlay/Core'
    ss.dependency 'TTSDKFramework/Player-SR','1.47.200.2-premium'
  end


  #业务的标准版本
  s.subspec 'Core' do |ss|
    ss.vendored_frameworks = ['SDK/PAGSShortPlay.xcframework']
    ss.preserve_paths = 'SDK/PAGSShortPlay.xcframework'
    ss.resource = 'SDK/PAGSShortPlay.bundle'
    ss.dependency 'AFNetworking','>= 4.0.0'
    ss.dependency 'YYModel','>= 1.0.1'
    ss.dependency 'SDWebImage','>= 5.12.0'
  end

  #业务的可选业务1
  # s.subspec '可选业务1的名称示例' do |ss|

  # end

  ## 精简版本部分

  ## 某高级的扩展功能部分

end
