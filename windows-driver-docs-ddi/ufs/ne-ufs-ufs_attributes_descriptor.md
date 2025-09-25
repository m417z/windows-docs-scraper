# UFS_ATTRIBUTES_DESCRIPTOR enumeration

## Description

**UFS_ATTRIBUTES_DESCRIPTOR** describes the different types of attributes used by Universal Flash Storage (UFS) descriptors.

## Constants

### `UFS_bBootLunEn`

Indicates if the Boot Logical Unit Number(LUN) is enabled.

### `UFS_Reserved_01`

Reserved for future use.

### `UFS_bCurrentPowerMode`

Indicates the current power mode. See Remarks for possible values.

### `UFS_bActiveICCLevel`

Specifies the maximum current consumption allowed during Active Mode. Value ranges from 0x00 to 0x0F.

### `UFS_bOutOfOrderDataEn`

Specifies if out-of-order data transfer is enabled.

### `UFS_bBackgroundOpStatus`

Specifies if the device has a need for background operations. See Remarks for possible values.

### `UFS_bPurgeStatus`

Specifies the current purge operation's status.

### `UFS_bMaxDataInSize`

Specifies the maximum data size in a DATA IN UFS Protocol Information Units (UPIU). This parameter can be written by the host only when all logical unit task queues are empty.

### `UFS_bMaxDataOutSize`

Specifies the maximum data-out size. This parameter can be written by the host only when all logical unit task queues are empty.

### `UFS_dDynCapNeeded`

Specifies the dynamic capacity need.

### `UFS_bRefClkFreq`

Specifies the reference clock frequency value. See Remarks for possible values.

### `UFS_bConfigDescrLock`

Specifies if the configuration descriptor is locked.

### `UFS_bMaxNumOfRTT`

Defines the current maximum number of outstanding READY TO TRANSFER UPIU's (RTT's) that are allowed. This value can be set by the host.

### `UFS_wExceptionEventControl`

Specifies the Exception Event Controller. **UFS_wExceptionEventControl** enables the setting of the **EVENT_ALERT** bit in the Device Information field, which is contained in the RESPONSE UPIU.

### `UFS_wExceptionEventStatus`

Specifies a bitmap of each exception event status.A bit will be set only if the relevant event has occurred (regardless of the **UFS_wExceptionEventControl** status). See Remarks for possible values.

### `UFS_dSecondsPassed`

Specifies the time passed in seconds.

### `UFS_wContextConf`

Specifies the context attribute.

### `UFS_Obsolete`

Obsolete

### `UFS_Reserved_12`

Reserved for future use.

### `UFS_Reserved_13`

Reserved for future use.

### `UFS_bDeviceFFUStatus`

Specifies the Device Field Firmware Update (FFU) status. See Remarks for possible values.

### `UFS_bPSAState`

Specifies the current Product State Awareness (PSA) State. See Remarks for possible values.

### `UFS_dPSADataSize`

Specifies the amount of data that the host plans to load to all logical units with **bPSASensitive** set to 1.

### `UFS_bRefClkGatingWaitTime`

Specifies the reference clock gating wait time.

### `UFS_bDeviceCaseRoughTemperature`

Specifies the rough temperature of the device case.

### `UFS_bDeviceTooHighTempBoundary`

Specifies the upper boundary for the device temperature.

### `UFS_bDeviceTooLowTempBoundary`

Specifies the lower boundary for the device temperature.

### `UFS_bThrottlingStatus`

Specifies the throttling status.

### `UFS_bWriteBoosterBufferFlushStatus`

Specifies the write booster buffer flush status.

### `UFS_bAvailableWriteBoosterBufferSize`

Specifies the available write booster buffer size.

### `UFS_bWriteBoosterBufferLifeTimeEst`

Specifies the write booster buffer lifetime estimate.

### `UFS_dCurrentWriteBoosterBufferSize`

Specifies the current write booster buffer size.

### `UFS_Reserved_20`

Reserved for future use.

### `UFS_Reserved_21`

Reserved for future use.

### `UFS_Reserved_22`

Reserved for future use.

### `UFS_Reserved_23`

Reserved for future use.

### `UFS_Reserved_24`

Reserved for future use.

### `UFS_Reserved_25`

Reserved for future use.

### `UFS_Reserved_26`

Reserved for future use.

### `UFS_Reserved_27`

Reserved for future use.

### `UFS_Reserved_28`

Reserved for future use.

### `UFS_Reserved_29`

Reserved for future use.

### `UFS_Reserved_2A`

Reserved for future use.

### `UFS_Reserved_2B`

Reserved for future use.

### `UFS_bRefreshStatus`

Specifies the refresh status.

### `UFS_bRefreshFreq`

Specifies the refresh frequency.

### `UFS_bRefreshUnit`

Specifies the refresh units.

### `UFS_bRefreshMethod`

Specifies the refresh method.

## Remarks

**UFS_bCurrentPowerMode** is the only attribute the device is required to return in any power mode. If the device
is not in Active power mode or Idle power mode, a **QUERY REQUEST UPIU** to access descriptors, flags, or attributes other than **bCurrentPowerMode** may fail.

Tje **UFS_bDeviceFFUStatus** value is kept after power cycle, hardware reset or any other type of reset. This attribute may change value when a microcode activation event occurs.

**UFS_bMaxDataInSize** is equal to **bMaxInBufferSize** when a UFS device is shipped.

### Possible values for some fields

**UFS_bCurrentPowerMode** contains one of the following values:

| Value | Description |
|--|--|
| 0x00 | Idle power mode. |
| 0x10 | Pre-Active power mode. |
| 0x11 | Active power mode. |
| 0x20 | Pre-Sleep power mode. |
| 0x22 | Universal Flash Storage (UFS)-Sleep power mode. |
| 0x30 | 40% to 50% of the device's estimated life time has been used. |
| 0x33 | 50% to 60% of the device's estimated life time has been used. |
| All other values | Reserved for future use. |

**UFS_bBackgroundOpStatus** contains one of the following values:

| Value | Description |
|--|--|
| 0x00 | Device requires no background operations. |
| 0x01 | Device has a non-critical need of background operations. |
| 0x02 | Device has a performance impacted-based need of background operations. |
| 0x03 | Device has a critical need of background operations. |

**UFS_bRefClkFreq** contains one of the following values:

| Value | Description |
|--|--|
| 0x00 | 19.2 MHz |
| 0x01 | 26 MHz |
| 0x02 | 38.4 MHz |
| 0x03 | 52 MHz |

**UFS_wExceptionEventStatus** contains the following bits:

| Bit | Value |
|--|--|
| 0 | DYNCAP_NEEDED |
| 1 | SYSPOOL_EXHAUSTED |
| 2 | URGENT_BKOPS |
| 3 to 15 | Reserved. |

**UFS_bDeviceFFUStatus** contains one of the following values:

| Value | Description |
|--|--|
| 0x00 | No information on the FFU status. |
| 0x01 | Successful microcode update. |
| 0x02 | Microcode corruption error. |
| 0x03 | Internal error. |
| 0x04 | Microcode version mismatch. |
| 0x05 to 0xFE | Reserved. |
| 0xFF | General Error. |

**UFS_bPSAState** contains one of the following values:

| Value | State | Description |
|--|--|--|
| 0x00 | Off | PSA feature is off. |
| 0x01 | Pre-solder | PSA feature is on and the device is in a pre-soldering state. |
| 0x02 | Loading Complete | The PSA feature is on. The host will set to this value after the host finished writing data during pre-soldering state. |
| 0x03 | Soldered | PSA feature is no longer available. Set by the Device to indicate it is in a post-soldering state. This attribute is locked after it is in 'Soldered' state. |

## See also

**[UFS_CONFIG_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufs/ns-ufs-ufs_config_descriptor)**
**[UFS_DEVICE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufs/ns-ufs-ufs_device_descriptor)**
**[UFS_DEVICE_HEALTH_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufs/ns-ufs-ufs_device_health_descriptor)**
**[UFS_GEOMETRY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufs/ns-ufs-ufs_geometry_descriptor)**
**[UFS_INTERCONNECT_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufs/ns-ufs-ufs_interconnect_descriptor)**
**[UFS_POWER_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufs/ns-ufs-ufs_power_descriptor)**
**[UFS_RPMB_UNIT_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufs/ns-ufs-ufs_rpmb_unit_descriptor)**
**[UFS_STRING_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufs/ns-ufs-_ufs_string_descriptor)**
**[UFS_UNIT_CONFIG_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufs/ns-ufs-ufs_unit_config_descriptor)**
**[UFS_UNIT_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufs/ns-ufs-ufs_unit_descriptor)**