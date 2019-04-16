//
//  FitCloudDFUKit.h
//  FitCloudDFUKit
//
//  Created by pcjbird on 2019/4/4.
//  Copyright © 2019 Zero Status. All rights reserved.
//
//  框架名称:FitCloudDFUKit.framework
//  框架功能:iOS framework for FitCloud Smart Bracelet Device Firmware Upgrade, which is responsible for the upgrade of bracelet firmware. FitCloud智能手环固件升级的iOS框架，负责手环固件升级等功能的封装。
//  修改记录:
//     pcjbird    2019-04-04  Version:1.0.0 Build:201904040001
//                            1.首次发布SDK版本
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import <FitCloudDFUKit/FitCloudDFUErrorCode.h>
#import <FitCloudDFUKit/FitCloudDFULogLevel.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @brief 芯片供应商
 */
typedef NS_ENUM(NSInteger, FITCLOUDDFUCHIPVENDOR)
{
    FITCLOUDDFUCHIPVENDOR_UNKNOWN = 0,                //未知
    FITCLOUDDFUCHIPVENDOR_REALTEK = 1,                //Realtek
    FITCLOUDDFUCHIPVENDOR_NORDIC = 2,                 //Nordic
};

/**
 * @brief FitCloud 固件升级代理
 */
@protocol FitCloudDFUDelegate <NSObject>
@optional
/**
 * @brief 成功启动DFU回调
 */
-(void) OnStartDFUSuccess;

/**
 * @brief 启动DFU失败
 * @param error 错误信息
 */
-(void) OnStartDFUFailureWithError:(NSError*)error;

/**
 * @brief 升级进度回调
 * @param progress 升级进度百分比(0~1)
 * @param index 当前镜像索引
 */
-(void) OnDFUProgress:(CGFloat)progress imageIndex:(NSInteger)index;

/**
 * @brief 意外终止回调
 * @param error 错误信息
 */
-(void) OnAbortWithError:(NSError*)error;

/**
 * @brief 升级完成回调
 * @param speed 速度
 */
-(void) OnDFUFinishWithSpeed:(CGFloat)speed;

/**
 *@brief 记录日志数据
 *@param message 日志信息
 *@param level 日志等级
 */
-(void) OnLogMessage:(NSString*)message level:(FCDFUKLogLevel)level;

@end

/**
 * @brief FitCloud 固件升级
 */
@interface FitCloudDFUKit : NSObject

/**
 * @brief 设置是否为调试模式,默认为NO
 */
+(void) setDebugMode:(BOOL)debugMode;

/**
 * @brief 设置代理
 * @param delegate 代理
 */
+(void) setDelegate:(id<FitCloudDFUDelegate>)delegate;

/**
 * @brief 开始固件升级
 * @param peripheral 固件升级的蓝牙外设
 * @param firmware 新版本固件文件路径,注意是 file path, 不是 file url
 * @param chipVendor 芯片供应商
 */
+(void) startWithPeripheral:(CBPeripheral *) peripheral firmware:(NSString*)firmware chipVendor:(FITCLOUDDFUCHIPVENDOR)chipVendor;

@end

NS_ASSUME_NONNULL_END
