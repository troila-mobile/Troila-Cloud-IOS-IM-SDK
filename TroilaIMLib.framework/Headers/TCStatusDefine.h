//
//  TCStatusDefine.h
//  TroilaImLib
//
//  Created by 李杰 on 2020/6/29.
//  Copyright © 2020 troila. All rights reserved.
//

#ifndef TCStatusDefine_h
#define TCStatusDefine_h

#pragma mark - 连接相关

#pragma mark TCConnectionStatus - 连接状态
typedef NS_ENUM(NSInteger,TCConnectionStatus){
        ConnectionStatus_Disconnected = 0,
        ConnectionStatus_Connecting = 1,
        ConnectionStatus_Connected = 2
};


#pragma mark - 消息相关

#pragma mark TCMessageDirection - 消息的方向
typedef NS_ENUM(NSUInteger, TCMessageDirection) {
    /*!
     发送
     */
    MessageDirection_SEND = 1,
    /*!
     接收
     */
    MessageDirection_RECEIVE = 2
};

#pragma mark TCCommandType - 命令消息类型
typedef NSString *TCCommandType NS_STRING_ENUM;
/*!
撤回
*/
static TCCommandType const TCCommandType_RecallMessage = @"CMD:RecallMessage";
/*!
已读
*/
static TCCommandType const TCCommandType_ReadMessage = @"CMD:ReadMessage";
/*!
同步已读
*/
static TCCommandType const TCCommandType_ReadSyncMessage = @"CMD:ReadSyncMessage";

#pragma mark TCSentStatus - 消息的发送状态
typedef NS_ENUM(NSUInteger, TCSentStatus) {
    /*!
     发送中
     */
    SentStatus_SENDING = 10,

    /*!
     发送失败
     */
    SentStatus_FAILED = 20,

    /*!
     已发送成功
     */
    SentStatus_SENT = 30,
};
#pragma mark TCMessageType - 消息的类型
typedef NSString *TCMessageType NS_STRING_ENUM;
/*!
文本消息
*/
static TCMessageType const TCMessageType_Text = @"MT:Text";
/*!
图片消息
*/
static TCMessageType const TCMessageType_Image = @"MT:Image";
/*!
GIF动态图片消息
 */
static TCMessageType const TCMessageType_Gif = @"MT:Gif";
/*!
图文消息
 */
static TCMessageType const TCMessageType_News = @"MT:News";
/*!
语音消息
 */
static TCMessageType const TCMessageType_Voice = @"MT:Voice";
/*!
文件消息
 */
static TCMessageType const TCMessageType_File = @"MT:File";
/*!
位置消息
 */
static TCMessageType const TCMessageType_Location = @"MT:Location";
/*!
命令消息
 */
static TCMessageType const TCMessageType_Command = @"MT:Command";
/*!
 通知消息
 */
static TCMessageType const TCMessageType_Notification = @"MT:Notify";
/*!
状态消息
*/
static TCMessageType const TCMessageType_Status = @"MT:Status";
/*!
时间消息
*/
static TCMessageType const TCMessageType_Time = @"MT:Time";
/*!
其他消息
*/
static TCMessageType const TCMessageType_Other = @"MT:Other";


#pragma mark TCNotificationType - 通知消息类型
typedef NSString *TCNotificationType NS_STRING_ENUM;

/*!
群聊创建
*/
static TCNotificationType const TCNotificationType_GroupCreated = @"NT:GroupCreated";

/*!
 退出群聊
 */
static TCNotificationType const TCNotificationType_GroupDismissed = @"NT:GroupDismissed";

/*!
 群聊成员加入
 */
static TCNotificationType const TCNotificationType_GroupMemberJoined = @"NT:GroupMemberJoined";

/*!
 群聊成员退出
 */
static TCNotificationType const TCNotificationType_GroupMemberQuited = @"NT:GroupMemberQuited";

/*!
 群聊重命名
 */
static TCNotificationType const TCNotificationType_GroupRenamed = @"NT:GroupRenamed";

/*!
 群聊成员被踢出
 */
static TCNotificationType const TCNotificationType_GroupMemberKicked = @"NT:GroupMemberKicked";

/*!
 会话免打扰更新
 */
static TCNotificationType const TCNotificationType_ConversationMuteUpdated = @"NT:ConversationMuteUpdated";

/*!
 会话置顶更新
 */
static TCNotificationType const TCNotificationType_ConversationStickyUpdated = @"NT:ConversationStickyUpdated";

/*!
 会话移除
 */
static TCNotificationType const TCNotificationType_ConversationRemoved = @"NT:ConversationRemoved";

/*!
 消息撤回
 */
static TCNotificationType const TCNotificationType_MessageRecalled = @"NT:MessageRecalled";

/*!
 消息已读
 */
static TCNotificationType const TCNotificationType_MessageRead = @"NT:MessageRead";

/*!
 消息更新
 */
static TCNotificationType const TCNotificationType_MessageUpdate = @"NT:MessageUpdate";


#pragma mark - 会话相关

#pragma mark TCConversationType - 会话类型
typedef NSString *TCConversationType NS_STRING_ENUM;
/*!
单聊
*/
static TCConversationType const TCConversationType_Private = @"CT:Private";
/*!
群聊
*/
static TCConversationType const TCConversationType_Group = @"CT:Group";


#pragma mark TCConversationNotificationStatus --- 会话通知状态
typedef NS_ENUM(NSInteger,TCConversationNotificationStatus){
        ConversationNotificationStatus_false = 0, //关闭
        ConversationNotificationStatus_true= 1, //开启
};


#pragma mark TCStatusType - 状态消息类型
typedef NSString *TCStatusType NS_STRING_ENUM;
/*!
撤回
*/
static TCStatusType const TCStatusType_Typing = @"ST:Typing";

#endif /* TCStatusDefine_h */
