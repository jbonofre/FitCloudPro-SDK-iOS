//
//  FitCloudHealthSportsObject.h
//  FitCloudKit
//
//  Created by pcjbird on 2018/5/30.
//  Copyright © 2018年 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FitCloudKitDefines.h"

#pragma mark - 手环手动同步对象基类


@interface FitCloudManualSyncItemObject : NSObject

/**
 * @brief 采样时刻
 */
@property(nonatomic, strong) NSDate* moment;

@end

/**
 * @brief 手环手动同步记录对象基类
 */
@interface FitCloudManualSyncRecordObject<__covariant ObjectType> : NSObject

/**
 * @brief 开始时间
 */
@property(nonatomic, strong) NSDate* begin;

/**
 * @brief 采样时间 (单位：秒)
 */
@property(nonatomic, assign) NSTimeInterval interval;

/**
 * @brief 详细条目
 */
@property(nonatomic, strong) NSArray<ObjectType>* items;

@end

#pragma mark - 计步

/**
 * @brief 手环计步数据条目
 */
@interface FitCloudStepItemObject : FitCloudManualSyncItemObject

/**
 * @brief 步数
 */
@property(nonatomic, assign) UInt16 steps;

@end


/**
 * @brief 手环计步数据记录
 */
@interface FitCloudStepRecordObject : FitCloudManualSyncRecordObject<FitCloudStepItemObject*>


@end

#pragma mark - 睡眠

/**
 * @brief 手环睡眠数据条目
 */
@interface FitCloudSleepItemObject : FitCloudManualSyncItemObject

/**
 * @brief 睡眠质量
 */
@property(nonatomic, assign) FITCLOUDSLEEPQUALITY quality;

@end

/**
 * @brief 手环睡眠数据记录
 */
@interface FitCloudSleepRecordObject : FitCloudManualSyncRecordObject<FitCloudSleepItemObject*>

@end

#pragma mark - 心率

/**
 * @brief 手环心率(Heart Rate)数据条目
 */
@interface FitCloudHRItemObject : FitCloudManualSyncItemObject


/**
 * @brief 心率值(次/分钟)
 */
@property(nonatomic, assign) UInt8    value;

@end

/**
 * @brief 手环心率(Heart Rate)数据记录
 */
@interface FitCloudHRRecordObject : FitCloudManualSyncRecordObject<FitCloudHRItemObject*>

@end

#pragma mark - 血压

/**
 * @brief 手环血压(Blood Pressure)数据条目
 */
@interface FitCloudBPItemObject : FitCloudManualSyncItemObject

/**
 *@brief 舒张压
 */
@property(nonatomic, assign) UInt8 diastolic;

/**
 *@brief 收缩压
 */
@property(nonatomic, assign) UInt8 systolic;


@end

/**
 * @brief 手环血压(Blood Pressure)数据记录
 */
@interface FitCloudBPRecordObject : FitCloudManualSyncRecordObject<FitCloudBPItemObject*>

@end


#pragma mark - 血氧

/**
 * @brief 手环血氧(Blood Oxygen)数据条目
 */
@interface FitCloudBOItemObject : FitCloudManualSyncItemObject

/**
 * @brief 血氧值
 */
@property(nonatomic, assign) UInt8      value;

@end

/**
 * @brief 手环血氧(Blood Oxygen)数据记录
 */
@interface FitCloudBORecordObject : FitCloudManualSyncRecordObject<FitCloudBOItemObject*>

@end

#pragma mark - 心电

/**
 * @brief 手环心电数据条目
 */
@interface FitCloudECGItemObject : FitCloudManualSyncItemObject

/**
 * @brief 心电值
 */
@property(nonatomic, assign) UInt16 value;

@end

/**
 * @brief 手环心电数据记录
 */
@interface FitCloudECGRecordObject : FitCloudManualSyncRecordObject<FitCloudECGItemObject*>

@end

#pragma mark - 呼吸频率

/**
 * @brief 手环呼吸频率(Breathe Rate)数据记录
 */
@interface FitCloudBRItemObject : FitCloudManualSyncItemObject

/**
 * @brief 呼吸频率
 */
@property(nonatomic, assign) UInt8  value;

@end

/**
 * @brief 手环呼吸频率(Breathe Rate)数据记录
 */
@interface FitCloudBRRecordObject : FitCloudManualSyncRecordObject<FitCloudBRItemObject*>


@end

#pragma mark - 运动模式

/**
 * @brief 手环运动模式运动数据条目
 */
@interface FitCloudSportsItemObject : FitCloudManualSyncItemObject

/**
 * @brief 运动类型
 */
@property(nonatomic, assign) FITCLOUDSPORTSTYPE genre;

/**
 * @brief 运动时长(秒)
 */
@property(nonatomic, assign) UInt16  duration;

/**
 * @brief 步数
 */
@property(nonatomic, assign) UInt16 steps;

/**
 * @brief 距离
 */
@property(nonatomic, assign) UInt16 distance;

/**
 * @brief 卡路里(小卡)
 */
@property(nonatomic, assign) UInt16 calory;

/**
 * @brief 配速(min/km)
 */
@property(nonatomic, assign) UInt16 pace;

/**
 * @brief 运动心率(次/min)
 */
@property(nonatomic, assign) UInt8  hr_excercise;

@end

/**
 * @brief 手环运动模式运动数据记录
 */
@interface FitCloudSportsRecordObject : FitCloudManualSyncRecordObject<FitCloudSportsItemObject*>

@end

#pragma mark - 健康实时测量

/**
 * @brief 实时健康测量项定义
 */
typedef NS_OPTIONS(UInt16, FITCLOUDREALTIMEMHEALTHEASUREITEM)
{
    FITCLOUDREALTIMEMHEALTHEASUREITEM_NONE = 0,                        //无
    FITCLOUDREALTIMEMHEALTHEASUREITEM_HEARTRATE = 1,                   //心率
    FITCLOUDREALTIMEMHEALTHEASUREITEM_BLOODOXYGEN = 1 << 1,            //血氧
    FITCLOUDREALTIMEMHEALTHEASUREITEM_BLOODPRESSURE = 1 << 2,          //血压
    FITCLOUDREALTIMEMHEALTHEASUREITEM_BREATHERATE = 1 << 3,            //呼吸频率
    FITCLOUDREALTIMEMHEALTHEASUREITEM_ECG = 1 << 4,                    //心电
};

/**
 * @brief 实时健康测量参数
 */
@interface FitCloudRealTimeHealthMeasuringParam : NSObject<NSCoding>

/**
 * @brief 测量项
 */
@property(nonatomic, assign) FITCLOUDREALTIMEMHEALTHEASUREITEM item;

/**
 * @brief 实时测量时间间隔(单位：秒)
 */
@property(nonatomic, assign) UInt8 interval;

/**
 * @brief 单次实时测量最长时间限制(单位：分钟)
 */
@property(nonatomic, assign) UInt8 maxMeasuringMinutes;

@end

/**
 * @brief 实时健康测量返回的数据
 */
@interface FitCloudRealTimeHealthMeasuringResultObject : NSObject

/**
* @brief 采样时刻
*/
@property(nonatomic, strong) NSDate* moment;

/**
 * @brief 心率
 */
@property(nonatomic, assign) UInt8 heartRate;

/**
 * @brief 血氧
 */
@property(nonatomic, assign) UInt8 bloodOxygen;

/**
 *@brief 舒张压
 */
@property(nonatomic, assign) UInt8 diastolic;

/**
 *@brief 收缩压
 */
@property(nonatomic, assign) UInt8 systolic;

/**
 * @brief 呼吸频率
 */
@property(nonatomic, assign) UInt8  breatheRate;

@end

#pragma mark - 每日运动健康数据

/**
 * @brief 每日运动健康数据
 */
@interface FitCloudDailyHealthAndSportsDataObject : NSObject<NSCoding>

/**
 * @brief 累计步数
 */
@property(nonatomic, assign) NSUInteger steps;

/**
 * @brief 距离(单位：米)
 */
@property(nonatomic, assign) NSUInteger distance;

/**
 * @brief 卡路里
 */
@property(nonatomic, assign) NSUInteger calory;

/**
 * @brief 深度睡眠时间(单位：分钟)
 */
@property(nonatomic, assign) NSUInteger deepSleepMinutes;

/**
 * @brief 浅度睡眠时间(单位：分钟)
 */
@property(nonatomic, assign) NSUInteger shallowSleepMinutes;

/**
 * @brief 平均心率(次/分钟)
 */
@property(nonatomic, assign) NSUInteger averageHeartRate;

@end
