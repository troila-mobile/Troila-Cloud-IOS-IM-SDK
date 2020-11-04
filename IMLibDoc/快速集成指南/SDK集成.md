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
pod 'TroilaCloudIM/IMLib'
```
5. 执行 `pod install`
6. 双击打开 .xcworkspace

# 初始化

1. 使用 SDK 功能前，请 import 下面的头文件
```objc
#import <TroilaIMLib/TroilaIMLib.h>
```
2. 请使用开发功能之前从卓朗云开发者控制台注册得到的 Appkey，通过 RCIMClient 的单例，传入 initWithAppKey: 方法，初始化 SDK。
3. 开发者在使用卓朗云 SDK 所有功能之前，开发者必须先调用此方法初始化 SDK。 在 App 的整个生命周期中，开发者只需要将 SDK 初始化一次。
```objc
[[TCIMClient sharedTCIMClient] initWithAppKey:Your Appkey];
```

# 连接融云

1. `Token` 即用户令牌，相当于您 APP 上当前用户连接卓朗云的身份凭证。`UserId` 即用户ID，相当于您 APP 上当前用户连接卓朗云的用户ID。在您连接卓朗云服务器之前，您需要请求您的 App Server，您的 App Server 通过卓朗云 Server API 获取 `Token` 和 `UserId`并返回给您的客户端，客户端获取到 `Token` 和 `UserId` 即可连接卓朗云服务器。
2. `success` 即连接成功回调，会返回 `Token` 对应的 UserId。
3. `error` 即连接失败回调，请您检查客户端初始化使用的 AppKey 和您服务器获取 token 用的 AppKey 是否一致，`token` 和 `userId` 是否匹配；
```objc
[[TCIMClient sharedTCIMClient] connectWithToken:@"开发者的 server 通过请求 server api 获取到的 token 值" 
                            userId: @"开发者的 server 通过请求 server api 获取到的 userId 值"
                            success:^(NSString *userId) {}
                            error:^(RCConnectErrorCode status) {}];

```

# 获取会话列表

1. 获取到所有单聊会话，如果需要获取更多会话类型的会话，可以增加数组中的会话类型对象。
2. 可以将获取到的会话列表数用 `UITableView` 来展示。
```objc
NSArray *conversationList = [[TCIMClient sharedTCIMClient] getConversationList];
```

# 发送消息

1. 构造文本消息对象。
2. 调用 TCIMClient 中 sendMessage 方法发送。
3. `success` 即发送成功回调，会返回消息的 `messageId`。
4. `error` 即发送失败回调，会返回消息的 `messageId` 和 发送失败的错误码 `errorCode`。
```objc
TCTextMessage *textMessage = [TCTextMessage messageWithContent:@"测试内容"];
[[TCIMClient sharedTCIMClient] 
    sendMessage:textMessage 
    targetId:@"test-userId" 
    conversationType:TCConversationType_Private 
    success:^(NSString *messageId) {
    
    }
    error:^(NSError *error) {
    
}];
```

# 接收消息

1. 设置接收消息监听代理。
```objc
// 设置消息接收监听
[[TCIMClient sharedTCIMClient] addReceiveMessageDelegate:self];

```
2. 实现接收消息回调方法。
```objc
- (void)onReceivedMessage:(TCMessage *)tcMessage 
        left:(int)left 
        offline:(BOOL)offline{
    NSLog(@"消息内容：%@", tcMessage.messageContent);
    NSLog(@"还剩余的未接收的消息数：%d", left);
}
```

# 获取历史消息

1. 从本地数据库中获取历史消息。
2. oldestMessageId 从messageId的一条消息开始获取。
3. count 即获取消息的数量。
4. RCIMClient 类中还有其他获取历史消息的接口，可根据自己的需求调用。
```objc
[[TCIMClient sharedTCIMClient]
    getHistoryMessages:@"targetId"
    conversationType:TCConversationType_Private
    oldestMessageId:@"oldestMessageId"
    count:20];
```

# 断开连接

1. 断开连接后不会再收到消息。
2. 在下次连接成功后，会收取上次离线后的消息，离线消息最多可以保存 7 天。
```objc
[[TCIMClient sharedTCIMClient] logout];
```