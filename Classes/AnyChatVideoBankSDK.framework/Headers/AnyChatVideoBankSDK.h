//
//  AnyChatVideoBankSDK.h
//  AnyChatVideoBankSDK
//
//  Created by tangyao on 2020/12/10.
//  Copyright © 2020 bairuitech. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <AnyChatSDK/AnyChatSDK.h>

NS_ASSUME_NONNULL_BEGIN

@class BRUserInfoModel;
@protocol AnyChatVideoBankSDKDelegate <NSObject>

@optional
//完成视频呼叫
- (void)onRecordCompleted:(AnyChatResult *)result;

//异常错误
- (void)onError:(AnyChatResult *)result;

//登录成功，返回用户登录后的userId
- (void)onLoginSuccess:(NSString *)userId;

/// 坐席请求客户登录时触发
/// @param vc 控制器视图
/// @param success 回调客户信息
- (void)onRequestLogin:(UIViewController *)vc success:(void (^)(BRUserInfoModel *userInfo))success;

@end

typedef NS_ENUM(NSUInteger, BRFunctionConfig) {
    BRFunctionConfigTransFile,//文件传输
    BRFunctionConfigSwitchCamera,//切换前后摄像头
};

//业务类型
typedef NS_ENUM(NSUInteger, BRBusinessType) {
    BRBusinessTypeCommonRoute = 0000, //默认业务类型
    BRBusinessTypeTakeCashReservation = 1001, //大额现金预约
    BRBusinessTypeMobileModify = 2001, //手机号码修改
    BRBusinessTypeTransferRemittance = 3001, //转账汇款
};

@interface BRStyleModel : NSObject

/**呼叫时否显示坐席账号*/
@property (nonatomic, assign) BOOL isShowAgentAccount;
/**功能动态配置集合(如：配置文件发送功能等)*/
@property (nonatomic, strong) NSArray *functionConfigs;

@end

@interface BRUserInfoModel : NSObject

/**
 游客登录: 游客-@"0" 非游客-@"1"
*/
@property (nonatomic, copy) NSString *isTourist;
/**
 客户号
*/
@property (nonatomic, copy) NSString *userNumber;
/**
 客户名
*/
@property (nonatomic, copy) NSString *userName;
/**
 客户身份证号码 (必传字段)
*/
@property (nonatomic, copy) NSString *userCardNumber;
/**
 客户手机号码
*/
@property (nonatomic, copy) NSString *phoneNumber;
/**
 客户认证级别
*/
@property (nonatomic, copy) NSString *userLevel;
/**
 账户
*/
@property (nonatomic, copy) NSString *accountNumber;
/**
 户名
*/
@property (nonatomic, copy) NSString *accountName;
/**
 账户类型
*/
@property (nonatomic, copy) NSString *accountType;
/**
 网络ip
*/
@property (nonatomic, copy) NSString *ip;
/**
 设备类型 （例：iOS ）
*/
@property (nonatomic, copy) NSString *deviceName;
/**
 设备系统版本号 (例：13.6.1)
*/
@property (nonatomic, copy) NSString *deviceVersion;
/**
 设备唯一标识
*/
@property (nonatomic, copy) NSString *deviceId;
/**
 应用版本号
*/
@property (nonatomic, copy) NSString *appVersion;

@end

@interface AnyChatVideoBankSDKModel : NSObject

/**
 服务器IP
 */
@property (nonatomic, copy) NSString *serverIp;

/**
 服务器端口
 */
@property (nonatomic, copy) NSString *serverPort;

/**
 用户姓名/昵称
 */
@property (nonatomic, copy) NSString *nickName;

/**
用户身份证号码
*/
@property (nonatomic, copy) NSString *idCardNumber;

/**
用户手机号
*/
@property (nonatomic, copy) NSString *phoneNumber;

/**
 商户应用ID（商户唯一标识，由佰锐科技提供）
 */
@property (nonatomic, copy) NSString *loginAppId;

/**
 业务类型
 */
@property (nonatomic, assign) BRBusinessType businessType;

/**
 产品编号
 */
@property (nonatomic, copy) NSString *productCode;

/**
 产品名称
 */
@property (nonatomic, copy) NSString *productName;

/**
 自定义样式配置模型类
 */
@property (nonatomic, strong) BRStyleModel *styleModel;

/**
 登录用户信息模型类
 */
@property (nonatomic, strong) BRUserInfoModel *userModel;

@end

@interface AnyChatVideoBankSDK : NSObject

#pragma mark - method

/** 初始化单例 */
+ (instancetype)shareInstance;

/** 获取SDK的版本信息 */
- (NSString*)getVersionInfo;

/** 开启SDK功能 */
- (void)startWithViewController:(UIViewController *)vc model:(AnyChatVideoBankSDKModel *)model delegate:(id<AnyChatVideoBankSDKDelegate>)delegate;

@end

NS_ASSUME_NONNULL_END



