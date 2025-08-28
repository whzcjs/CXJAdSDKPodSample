source 'https://github.com/CocoaPods/Specs.git'
platform :ios, '12.0'

target 'CXJAdSDKPodSample' do
  # Comment the next line if you don't want to use dynamic frameworks
  use_frameworks!

  pod 'CXJAdSDK'
  pod 'CXJAdSDK/CXBDAdapter'
  pod 'CXJAdSDK/CXQMAdapter'
  pod 'CXJAdSDK/CXFWAdapter'
  pod 'CXJAdSDK/CXJADAdapter'
  
  pod 'Toast'
  pod 'MJExtension'
  pod 'MBProgressHUD'
  pod 'SDWebImage'
  pod 'Masonry'

end


post_install do |installer|
  installer.pods_project.targets.each do |target|
    target.build_configurations.each do |config|
      if ['Masonry', 'MBProgressHUD', 'Toast', 'FBRetainCycleDetector', 'MLeaksFinder'].include?(target.name)
        config.build_settings['IPHONEOS_DEPLOYMENT_TARGET'] = '12.0'
      end
    end
  end
end
