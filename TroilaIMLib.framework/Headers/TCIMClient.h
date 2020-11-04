//
//  TCIMClient.h
//  Pods
//
//  Created by 李杰 on 2020/6/16.
//

#import <Foundation/Foundation.h>
#import "TCDelegate.h"
#import "TCMessageContent.h"
#import "TCMessage.h"
#import "TCConversation.h"
#import "TCNotification.h"
#import <UserNotifications/UNUserNotificationCenter.h>

NS_ASSUME_NONNULL_BEGIN
@class GRPCMutableCallOptions;

#pragma mark - IMLib核心类

/*!
卓朗IMLib核心类

 @discussion 您需要通过sharedTCIMClient方法，获取单例对象。
*/
@interface TCIMClient : NSObject


/*!
获取卓朗云通讯能力库IMLib的核心类单例

@return 卓朗云通讯能力库IMLib的核心类单例

@discussion 您可以通过此方法，获取IMLib的单例，访问对象中的属性和方法.
*/
+ (instancetype)sharedTCIMClient;

/*!
设置debug模式
*/
+ (void)setDebug:(BOOL)flag;

/*!
如果需要更改host，请在init前进行操作
*/
+ (void)changeHost:(NSString *)host;

@property (readonly, nonatomic) GRPCMutableCallOptions * options;

/*!
获得当前连接的userId
*/
- (NSString *)getUserId;

#pragma mark - SDK初始化

/*!
初始化卓朗IM Lib SDK

@param appkey  从卓朗开发者平台创建应用后获取到的App Key

@discussion
您在使用卓朗SDK所有功能（包括显示SDK中或者继承于SDK的View）之前，您必须先调用此方法初始化SDK。
在App整个生命周期中，您只需要执行一次初始化。

*/
- (void)initWithAppKey:(int)appkey;

/*!
设置 deviceToken（已兼容 iOS 13），用于远程推送

@param deviceTokenData     从系统获取到的设备号 deviceTokenData (不需要处理)

@discussion
deviceToken 是系统提供的，从苹果服务器获取的，用于 APNs 远程推送必须使用的设备唯一值。
您需要将 -application:didRegisterForRemoteNotificationsWithDeviceToken: 获取到的 deviceToken 作为参数传入此方法。

如:

   - (void)application:(UIApplication *)application
   didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken {
       [[RCITClient sharedRCITClient] setDeviceTokenData:deviceToken];
   }

*/
- (void)setDeviceTokenData:(NSData *)deviceTokenData;

#pragma mark - 连接与断开服务器

/*!
与卓朗服务器建立连接

@param token                   从您服务器端获取的token(用户身份令牌)
@param userId            用户id
@param deviceToken              设备token

*/
- (void)connectWithToken:(NSString *)token userId:(NSString *)userId success:(void (^)(NSString *userId))successBlock error:(void (^)(NSError *error))errorBlock;

/*!
 
断开与卓朗服务器的连接
*/
- (void)disconnect;


/*!
获取通道的连接状态
*/
- (TCConnectionStatus)getConnectionStatus;

#pragma mark - 连接状态监听

/*!
 设置IMLib的连接状态监听器

 @param delegate    IMLib连接状态监听器

 */
- (void)addTCConnectionStatusChangeDelegate:(id<TCConnectionStatusChangeDelegate>)delegate;

/*!
获取当前是否在同步消息

@return 当前是否在同步消息
*/
- (BOOL)getIsOnSyncHistoryMessages;

#pragma mark - 会话操作

/*!
设置会话免打扰状态
*/
- (void)setConversationNotificationStatus:(TCConversationType)conversationType
                                 targetId:(NSString *)targetId
                                isBlocked:(BOOL)isBlocked
                                  success:(void (^)(void))successBlock
                                    error:(void (^)(NSError *error))errorBlock;

/*!
设置会话置顶状态
*/
- (void)setConversationToTop:(TCConversationType)conversationType
                    targetId:(NSString*) targetId
                       isTop:(BOOL)isTop
                     success:(void (^)(void))successBlock
                       error:(void (^)(NSError *error))errorBlock;

/*!
获得置顶的会话列表
 
@return 会话列表
*/
- (NSArray<TCConversation *>*)getTopConversationList;

/*!
获得会话列表
 
@return 会话列表
*/
- (NSArray<TCConversation *> *)getConversationList;

/*!
获取会话的免打扰状态
 
@return 免打扰状态
*/
- (TCConversationNotificationStatus)getConversationNotificationStatus:(NSString *)targetId conversationType:(TCConversationType)conversationType;

/*!
删除会话

@param conversationType    会话类型
@param targetId            目标会话ID
@param successBlock    成功回调
@param errorBlock         失败回调
 
*/
- (void)removeConversation:(TCConversationType)conversationType
                 targetId:(NSString*) targetId
                  success:(void (^)(void))successBlock
                    error:(void (^)(NSError *error))errorBlock;

/*!
删除会话不刷新
*/
- (void)removeConversationWithNotRefresh:(TCConversationType)conversationType targetId:(NSString*) targetId success:(void (^)(void))successBlock error:(void (^)(NSError *error))errorBlock;

/*!
清除会话的未读消息数量

@param conversationType    会话类型
@param targetId            目标会话ID
 
*/
- (void)clearConversationUnreadStatus:(NSString*)targetId conversationType:(TCConversationType)conversationType;

/*!
向会话中发送正在输入的状态
@param conversationType    会话类型
@param targetId            会话目标ID
@param messageType         消息类型
@discussion
messageType为用户当前正在编辑的消息类型名，即TextMessage中MessageType的返回值。
如文本消息，应该传类型名"MT:Text"。
@warning 目前仅支持单聊。
*/
-(void)sendTypingStatus:(NSString*)targetId
       conversationType:(TCConversationType)conversationType
            messageType:(TCMessageType)messageType
                success:(void (^)(void))successBlock
                  error:(void (^)(NSError *error))errorBlock;

#pragma mark 发送已读回执
/*!
发送已读回执
 @param conversationType    会话类型
 @param targetId            会话目标ID
 @param messages     消息
*/
-(void)sendReadReceiptResponse:(NSString*)targetId conversationType:(TCConversationType)conversationType messages:(NSArray*)messages;




#pragma mark 未读消息数

/*!
获取所有的未读消息数

@return    所有的未读消息数
*/
- (int)getTotalUnreadCount;

#pragma mark - 消息操作

/*!
获取某个会话中指定数量的最新消息实体

@param conversationType    会话类型
@param targetId            目标会话ID
@param count               需要获取的消息数量
@return                    消息实体TCMessage对象列表

@discussion
此方法会获取该会话中指定数量的最新消息实体，返回的消息实体按照时间从新到旧排列。
如果会话中的消息数量小于参数count的值，会将该会话中的所有消息返回。
*/
- (NSArray*)getLatestMessages:(TCConversationType)conversationType
                    targetId:(NSString*)targetId
                       count:(int)count;

/*!
获取会话中，从指定消息之前、指定数量的最新消息实体

@param conversationType    会话类型
@param targetId            目标会话ID
@param oldestMessageId     截止的消息ID
@param count               需要获取的消息数量
@return                    消息实体TCMessage对象列表

@discussion
此方法会获取该会话中，oldestMessageId之前的、指定数量的最新消息实体，返回的消息实体按照时间从新到旧排列。
返回的消息中不包含oldestMessageId对应那条消息，如果会话中的消息数量小于参数count的值，会将该会话中的所有消息返回。
如：
oldestMessageId为10，count为2，会返回messageId为9和8的TCMessage对象列表。
*/
- (NSArray*)getHistoryMessages:targetId
             conversationType:(TCConversationType)conversationType
              oldestMessageId:(NSString*)oldestMessageId
                        count:(int)count;

/*!
删除消息

@param messageIds  消息ID的列表
*/
- (void)deleteMessages:(NSArray<NSString *> *)messageIds;

/*!
删除某个会话中的所有消息

@param conversationType    会话类型，不支持聊天室
@param targetId            目标会话ID

@discussion 此方法删除数据库中该会话的消息记录，同时会整理压缩数据库，减少占用空间
*/
- (void)deleteMessages:(TCConversationType)conversationType targetId:(NSString *)targetId;

/*!
撤回消息

@param message      需要撤回的消息
@param successBlock 撤回成功的回调 [messageId:撤回的消息ID，该消息已经变更为新的消息]
@param errorBlock   撤回失败的回调 [errorCode:撤回失败错误码]

*/
- (void)recallMessage:(TCMessage *)message success:(void (^)(NSString *messageId))successBlock error:(void (^)(NSError *error))errorBlock;


/*!
更新消息

@param messageContent      消息内容
@param messageId 消息id

*/
- (void)updateMessageWithMessageContent:(TCMessageContent *)messageContent messageId:(NSString *)messageId;

/*!
 通过messageId获取消息实体

 @param messageId   消息ID（数据库索引唯一值）
 @return            通过消息ID获取到的消息实体，当获取失败的时候，会返回nil。
 */
- (TCMessage *)getMessageWithMessageId:(NSString *)messageId;

#pragma mark 消息发送

/*!
发送消息

@param conversationType    发送消息的会话类型
@param targetId            发送消息的目标会话ID
@param content             消息的内容
@param successBlock        消息发送成功的回调 [messageId:消息的ID]
@param errorBlock          消息发送失败的回调 [nErrorCode:发送失败的错误码,
messageId:消息的ID]

*/
- (void)sendMessage:(TCMessageContent *)content targetId:(NSString *)targetId conversationType:(TCConversationType)conversationType success:(void (^)(NSString *messageId))successBlock error:(void (^)(NSError *error))errorBlock;

/*!
重新发送消息（必须是发送后失败的消息）

@param tcMessage    实体消息
@param successBlock        消息发送成功的回调 [messageId:消息的ID]
@param errorBlock          消息发送失败的回调 [nErrorCode:发送失败的错误码,

 */

- (void)resendMessage:(TCMessage *)tcMessage success:(void (^)(NSString *messageId))successBlock error:(void (^)(NSError *error))errorBlock;

#pragma mark 消息接收监听
/*!
 设置IMlib的消息接收监听器

 @param delegate    IMLib消息接收监听器

 */
- (void)addReceiveMessageDelegate:(id<TCReceivedMessageDelegate>)delegate;


#pragma mark 通知接收监听
/*!
 设置IMlib的通知接收监听器

 @param delegate    IMLib通知接收监听器

 */
- (void)addTCNotificationDelegate:(id<TCNotificationDelegate>)delegate;

#pragma mark 消息删除监听
/*!
 设置IMlib的消息删除监听器

 @param delegate    IMLib消息删除监听器

 */
- (void)addTCDeleteMessageDelegate:(id<TCDeleteMessageDelegate>)delegate;

#pragma mark 会话状态监听
/*!
 设置IMlib的会话状态监听器
 @param delegate    IMLib会话状态监听器
  */

- (void)addTCConversationStatusChangeDelegate:(id<TCConversationStatusChangeDelegate>)delegate;

#pragma mark 自定义通知监听
/*!
 设置IMlib的自定义通知监听器
 @param delegate    IMLib自定义通知监听器
  */

- (void)addTCCustomNotificationDelegate:(id<TCCustomNotificationDelegate>)delegate;

#pragma mark 状态消息监听
/*!
 设置IMlib的状态消息监听器
 @param delegate    IMLib状态消息监听器
  */

- (void)addTCReceivedStatusDelegate:(id<TCReceivedStatusDelegate>)delegate;

#pragma mark 同步历史消息状态监听
/*!
 设置IMlib的同步历史消息状态监听器
 @param delegate    IMLib同步历史消息状态监听器
  */

- (void)addTCSyncHistoryMessagesStatusChangeDelegate:(id<TCSyncHistoryMessagesStatusChangeDelegate>)delegate;


#pragma mark - 注册消息类型

/*!
 注册自定义的消息类型

 @param messageClass    自定义消息的类，该自定义消息需要继承于TCMessageContent

 @discussion
 如果您需要自定义消息，必须调用此方法注册该自定义消息的消息类型，否则SDK将无法识别和解析该类型消息。

 */
- (void)registerMessageType:(Class)messageClass;


#pragma mark - 会话中的草稿操作
/*!
 获取会话中的草稿信息（用户输入但未发送的暂存消息）

 @param conversationType    会话类型
 @param targetId            会话目标 ID
 @return                    该会话中的草稿

 @remarks 会话
 */
- (NSString *)getTextMessageDraft:(TCConversationType)conversationType targetId:(NSString *)targetId;

/*!
 保存草稿信息（用户输入但未发送的暂存消息）

 @param conversationType    会话类型
 @param targetId            会话目标 ID
 @param content             草稿信息
 @return                    是否保存成功

 @remarks 会话
 */
- (BOOL)saveTextMessageDraft:(TCConversationType)conversationType targetId:(NSString *)targetId content:(NSString *)content;

/*!
 删除会话中的草稿信息（用户输入但未发送的暂存消息）

 @param conversationType    会话类型
 @param targetId            会话目标 ID
 @return                    是否删除成功

 @remarks 会话
 */
- (BOOL)clearTextMessageDraft:(TCConversationType)conversationType targetId:(NSString *)targetId;

#pragma mark - 推送

/*!
 根据UNNotificationResponse获得TCNotification

 @param response    系统推送结果
 @return    TCNotification
 */
- (TCNotification *)getTCNotificationWithNotificationResponse:(UNNotificationResponse *)response;


#pragma mark - 辅助方法

- (id)getTCMessageContentWithTRMessage:(id)trMessage;

- (void)getFileUploadInfo: (void (^)(NSString *fileUploadInfo))successBlock error:(void (^)(NSError *error))errorBlock;

- (void)getGroupMemberList:(NSString *)groupId memberIds:(NSArray *)memberIds success:(void (^)(NSMutableArray *groupMembers))successBlock error:(void (^)(NSError *error))errorBlock;

@end
NS_ASSUME_NONNULL_END


