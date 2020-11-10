Pod::Spec.new do |s|
  s.name         = "TroilaCloudIM"
  s.version      = "1.0.0"
  s.summary      = "TroilaCloud IM SDK"
  s.description  = <<-DESC
TroilaCloud IM SDK for iOS
                   DESC
  s.homepage     = "https://im.perfectwork.com"
  s.license      = { :type => 'MIT', :file => 'LICENSE' }
  s.author       = { "yulianlin" => "yll@520wcf.com", "lijie" => "lj706517903@163.com" }
  s.platform     = :ios, "11.0"
  s.source       = { :git => "https://github.com/troila-mobile/Troila-Cloud-IOS-IM-SDK.git", :tag => "#{s.version}" }
  s.pod_target_xcconfig = { 'VALID_ARCHS[sdk=iphonesimulator*]' => '' }

  s.subspec 'IMLib' do |lib|
  lib.vendored_frameworks = 'TroilaIMLib.framework'
  lib.dependency "!ProtoCompiler-gRPCPlugin", "~> 1.0"
  lib.dependency "Realm", "~> 1.10"
  lib.dependency "AFNetworking"
  end

  s.subspec 'IMKit' do |kit|
  kit.vendored_frameworks = 'TroilaIMKit.framework'
  kit.resource = "TroilaIMKit.framework/Assets.bundle"
  kit.dependency "SDWebImage"
  kit.dependency "UIColor-HexString"
  kit.dependency "Masonry"
  kit.dependency "lottie-ios", '~> 2.5.3'
  kit.dependency 'GBKUIButtonProgressView'
  end

end

