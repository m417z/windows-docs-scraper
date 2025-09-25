# UFS_CONFIG_DESCRIPTOR structure

## Description

The **UFS_CONFIG_DESCRIPTOR** structure describes the modifiable values of the default device configuration set by the manufacturer.

## Members

### `bLength`

Specifies the size, in bytes, of this descriptor.

### `bDescriptorIDN`

Specifies the Configuration Descriptor Type Identifier. This descriptor will have a value of **UFS_DESC_CONFIGURATION_IDN**.

### `bConfDescContinue`

Specifies if a device's configuration descriptor continue feature is enabled.

### `bBootEnable`

Specifies if a device's boot feature is enabled.

### `bDescrAccessEn`

Enables access to the Device Descriptor after the partial initialization phase of the boot sequence.

### `bInitPowerMode`

Specifies the power mode after device initialization or hardware reset.

### `bHighPriorityLUN`

**bHighPriorityLUN** configures the high priority logical unit.

### `bSecureRemovalType`

Configures the secure removal type.

### `bInitActiveICCLevel`

Configures the ICC level in Active mode after device initialization or hardware reset.

### `wPeriodicRTCUpdate[2]`

Specifies the frequency and method of real-time clock updates.

### `Reserved2[1]`

Reserved for future use.

### `bRPMBRegionEnable`

Specifies if Replay Protected Memory Blocks (RPMB) are enabled.

### `bRPMBRegion1Size`

Specifies the size of RPMB region 1.

### `bRPMBRegion2Size`

Specifies the size of RPMB region 2.

### `bRPMBRegion3Size`

Specifies the size of RPMB region 3.

### `UnitConfig[UFS_MAX_NUM_LU]`

Contains the configurable parameters of the unit descriptor.

## See also

- **[UFS_UNIT_CONFIG_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufs/ns-ufs-ufs_unit_config_descriptor)**