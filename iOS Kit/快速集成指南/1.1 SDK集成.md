# 导入SDK

## 环境要求

| name | version |
| - | -|
| xcode | 11+ |

SDK 需要使用 CocoaPods 导入并管理 SDK。 需安装 CocoaPods 环境，请参照 [CocoaPods](https://cocoapods.org/) 安装

## 导入 SDK

1. `cd` 至项目根目录
2. 执行 `pod init`
3. 执行 `open -e Podfile`
4. 在 `Podfile` 文件中添加下面内容
```ruby
pod 'TroilaCloudIM/IMKit'
```
5. 执行 `pod install`
6. 双击打开 .xcworkspace


# 初始化

1. 使用 SDK 功能前，请 import 下面的头文件
```objc
#import <TroilaIMKit/TroilaIMKit.h>
```
2. 请使用开发功能之前从卓朗云开发者控制台注册得到的 Appkey，通过 TCIM 的单例，传入 initWithAppKey: 方法，初始化 SDK。
3. 开发者在使用卓朗云 SDK 所有功能之前，开发者必须先调用此方法初始化 SDK。 在 App 的整个生命周期中，开发者只需要将 SDK 初始化一次。
```objc
[[TCIM sharedTCIM] initWithAppKey:Your Appkey];
```

