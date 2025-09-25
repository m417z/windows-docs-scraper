# UFS_FLAGS_DESCRIPTOR enumeration

## Description

**UFS_FLAGS_DESCRIPTOR** describes the different types of flags used by Universal Flash Storage (UFS) descriptors.

## Constants

### `UFS_Reserved_00`

Reserved for future use.

### `UFS_fDeviceInit`

Indicates the device initialization is in progress.

### `UFS_fPermanentWPEn`

Indicates permanent write protection is enabled.

### `UFS_fPowerOnWPEn`

Indicates power on write protection is enabled.

### `UFS_fBackgroundOpsEn`

Indicates the device is permitted to run background operations.

### `UFS_fDeviceLifeSpanModeEn`

Indicates Device Life Span Mode is enabled.

### `UFS_fPurgeEnable`

Indicates Purge Operation is enabled.

### `UFS_fRefreshEnable`

Initiate a refresh operation by setting **UFS_fRefreshEnable** to 0x01 and interrupt it by clearing **UFS_fRefreshEnable** to 0x00.

### `UFS_fPhyResourceRemoval`

Indicates that the dynamic capacity operation occurs on the device's EndPointReset or a hardware reset. The host cannot reset this flag.

### `UFS_fBusyRTC`

Indicates the device is executing internal operation related to Real Time Clock.

### `UFS_Reserved_0A`

Reserved for future use.

### `UFS_fPermanentlyDisableFwUpdate`

Indicates the UFS device will permanently disallow future firmware updates to the Universal Flash Storage (UFS) device.

### `UFS_Reserved_0C`

Reserved for the Unified Memory Extension standard.

### `UFS_Reserved_0D`

Reserved for the Unified Memory Extension standard.

### `UFS_fWriteBoosterEn`

Set the **UFS_fWriteBoosterEn** flag to one to enable the WriteBooster feature.

### `UFS_fWriteBoosterBufferFlushEn`

The **UFS_fWriteBoosterBufferFlushEn** flag enables the flush operation. When **UFS_fWriteBoosterBufferFlushEn** is set to one, the device flushes the WriteBooster buffer.

### `UFS_fWriteBoosterBufferFlushDuringHibernate`

The **UFS_fWriteBoosterBufferFlushDuringHibernate** enables the flush operation during device hibernate. The device does a WriteBooster buffer flush operation whenever the link enters in the hibernate state.

### `UFS_Reserved_11`

Reserved for future use.