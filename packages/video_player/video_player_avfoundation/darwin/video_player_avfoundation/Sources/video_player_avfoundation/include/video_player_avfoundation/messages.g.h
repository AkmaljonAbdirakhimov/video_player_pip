// Copyright 2013 The Flutter Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
// Autogenerated from Pigeon (v22.7.4), do not edit directly.
// See also: https://pub.dev/packages/pigeon

#import <Foundation/Foundation.h>

@protocol FlutterBinaryMessenger;
@protocol FlutterMessageCodec;
@class FlutterError;
@class FlutterStandardTypedData;

NS_ASSUME_NONNULL_BEGIN

/// Pigeon equivalent of VideoViewType.
typedef NS_ENUM(NSUInteger, FVPPlatformVideoViewType) {
  FVPPlatformVideoViewTypeTextureView = 0,
  FVPPlatformVideoViewTypePlatformView = 1,
};

/// Wrapper for FVPPlatformVideoViewType to allow for nullability.
@interface FVPPlatformVideoViewTypeBox : NSObject
@property(nonatomic, assign) FVPPlatformVideoViewType value;
- (instancetype)initWithValue:(FVPPlatformVideoViewType)value;
@end

/// Represents the state of a video download.
typedef NS_ENUM(NSUInteger, FVPDownloadState) {
  FVPDownloadStateInitial = 0,
  FVPDownloadStateDownloading = 1,
  FVPDownloadStateDownloaded = 2,
  FVPDownloadStateFailed = 3,
};

/// Wrapper for FVPDownloadState to allow for nullability.
@interface FVPDownloadStateBox : NSObject
@property(nonatomic, assign) FVPDownloadState value;
- (instancetype)initWithValue:(FVPDownloadState)value;
@end

@class FVPPlatformVideoViewCreationParams;
@class FVPCreationOptions;
@class FVPDownloadProgress;

/// Information passed to the platform view creation.
@interface FVPPlatformVideoViewCreationParams : NSObject
/// `init` unavailable to enforce nonnull fields, see the `make` class method.
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)makeWithPlayerId:(NSInteger )playerId;
@property(nonatomic, assign) NSInteger  playerId;
@end

@interface FVPCreationOptions : NSObject
/// `init` unavailable to enforce nonnull fields, see the `make` class method.
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)makeWithAsset:(nullable NSString *)asset
    uri:(nullable NSString *)uri
    packageName:(nullable NSString *)packageName
    formatHint:(nullable NSString *)formatHint
    httpHeaders:(NSDictionary<NSString *, NSString *> *)httpHeaders
    viewType:(FVPPlatformVideoViewType)viewType;
@property(nonatomic, copy, nullable) NSString * asset;
@property(nonatomic, copy, nullable) NSString * uri;
@property(nonatomic, copy, nullable) NSString * packageName;
@property(nonatomic, copy, nullable) NSString * formatHint;
@property(nonatomic, copy) NSDictionary<NSString *, NSString *> * httpHeaders;
@property(nonatomic, assign) FVPPlatformVideoViewType viewType;
@end

/// Information about download progress.
@interface FVPDownloadProgress : NSObject
/// `init` unavailable to enforce nonnull fields, see the `make` class method.
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)makeWithUrl:(NSString *)url
    progress:(double )progress
    bytesDownloaded:(NSInteger )bytesDownloaded;
@property(nonatomic, copy) NSString * url;
@property(nonatomic, assign) double  progress;
@property(nonatomic, assign) NSInteger  bytesDownloaded;
@end

/// The codec used by all APIs.
NSObject<FlutterMessageCodec> *FVPGetMessagesCodec(void);

@protocol FVPAVFoundationVideoPlayerApi
- (void)initialize:(FlutterError *_Nullable *_Nonnull)error;
/// @return `nil` only when `error != nil`.
- (nullable NSNumber *)createWithOptions:(FVPCreationOptions *)creationOptions error:(FlutterError *_Nullable *_Nonnull)error;
- (void)disposePlayer:(NSInteger)playerId error:(FlutterError *_Nullable *_Nonnull)error;
- (void)setLooping:(BOOL)isLooping forPlayer:(NSInteger)playerId error:(FlutterError *_Nullable *_Nonnull)error;
- (void)setVolume:(double)volume forPlayer:(NSInteger)playerId error:(FlutterError *_Nullable *_Nonnull)error;
- (void)setPlaybackSpeed:(double)speed forPlayer:(NSInteger)playerId error:(FlutterError *_Nullable *_Nonnull)error;
- (void)playPlayer:(NSInteger)playerId error:(FlutterError *_Nullable *_Nonnull)error;
/// @return `nil` only when `error != nil`.
- (nullable NSNumber *)positionForPlayer:(NSInteger)playerId error:(FlutterError *_Nullable *_Nonnull)error;
- (void)seekTo:(NSInteger)position forPlayer:(NSInteger)playerId completion:(void (^)(FlutterError *_Nullable))completion;
- (void)pausePlayer:(NSInteger)playerId error:(FlutterError *_Nullable *_Nonnull)error;
- (void)setMixWithOthers:(BOOL)mixWithOthers error:(FlutterError *_Nullable *_Nonnull)error;
/// @return `nil` only when `error != nil`.
- (nullable NSString *)startDownload:(NSString *)url error:(FlutterError *_Nullable *_Nonnull)error;
/// @return `nil` only when `error != nil`.
- (nullable NSNumber *)cancelDownload:(NSString *)url error:(FlutterError *_Nullable *_Nonnull)error;
/// @return `nil` only when `error != nil`.
- (nullable NSNumber *)removeDownload:(NSString *)url error:(FlutterError *_Nullable *_Nonnull)error;
/// @return `nil` only when `error != nil`.
- (nullable FVPDownloadProgress *)getDownloadProgress:(NSString *)url error:(FlutterError *_Nullable *_Nonnull)error;
- (nullable NSString *)getCachedVideoPath:(NSString *)url error:(FlutterError *_Nullable *_Nonnull)error;
/// @return `nil` only when `error != nil`.
- (nullable NSNumber *)getMaxConcurrentDownloads:(FlutterError *_Nullable *_Nonnull)error;
/// @return `nil` only when `error != nil`.
- (FVPDownloadStateBox *_Nullable)getDownloadState:(NSString *)url error:(FlutterError *_Nullable *_Nonnull)error;
@end

extern void SetUpFVPAVFoundationVideoPlayerApi(id<FlutterBinaryMessenger> binaryMessenger, NSObject<FVPAVFoundationVideoPlayerApi> *_Nullable api);

extern void SetUpFVPAVFoundationVideoPlayerApiWithSuffix(id<FlutterBinaryMessenger> binaryMessenger, NSObject<FVPAVFoundationVideoPlayerApi> *_Nullable api, NSString *messageChannelSuffix);

NS_ASSUME_NONNULL_END
