## Description

## Members

### `bLength`

Specifies the size, in bytes, of this descriptor.

### `bDescriptorIDN`

Specifies the configuration descriptor type identifier. This descriptor will have a value of UFS_DESC_CONFIGURATION_IDN.

### `bConfDescContinue`

Specifies if a device's configuration descriptor continue feature is enabled.

### `bBootEnable`

Specifies if a device's boot feature is enabled.

### `bDescrAccessEn`

Enables access to the device descriptor after the partial initialization phase of the boot sequence.

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

### `bWriteBoosterBufferPreserveUserSpaceEn`

Setting **bWriteBoosterBufferPreserveUserSpaceEn** to 0x01 avoids the reduction of the total user space that can be configured during provisioning, but might result in lower performance. If **bWriteBoosterBufferPreserveUserSpaceEn** is set to 0x00, the write booster buffer reduces the total user space that can be configured during provisioning.

### `bWriteBoosterBufferType`

**bWriteBoosterBufferType** configures the the write booster buffer type. A value of 0x00 specifies logical unit dedicated buffer mode. A value of 0x01 specifies shared buffer mode.

### `dNumSharedWriteBoosterBufferAllocUnits`

**dNumSharedWriteBoosterBufferAllocUnits** specifies the write booster buffer size for a shared write booster buffer configuration.

### `UnitConfig[UFS_MAX_NUM_LU]`

Contains the configurable parameters of the unit descriptor.

## Remarks

If **bBootEnable** is set to zero or if the *Boot Well Known Logical Unit* is not mapped to an enabled logical unit, then the *Boot Well Known Logical Unit* shall terminate.

**UFS_DEVICE_DESCRIPTOR** is read only, some of its parameters may be changed by changing the corresponding parameter in **[UFS_UNIT_CONFIG_DESCRIPTOR_V3_1](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufs/ns-ufs-ufs_unit_config_descriptor_v3_1)**.

## See also

- **[UFS_UNIT_CONFIG_DESCRIPTOR_V3_1](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufs/ns-ufs-ufs_unit_config_descriptor_v3_1)**
- **[UFS_CONFIG_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufs/ns-ufs-ufs_config_descriptor)**
- **[UFS_DEVICE_HEALTH_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufs/ns-ufs-ufs_device_health_descriptor)**
- **[UFS_GEOMETRY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufs/ns-ufs-ufs_geometry_descriptor)**
- **[UFS_INTERCONNECT_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufs/ns-ufs-ufs_interconnect_descriptor)**
- **[UFS_POWER_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufs/ns-ufs-ufs_power_descriptor)**
- **[UFS_RPMB_UNIT_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufs/ns-ufs-ufs_rpmb_unit_descriptor)**
- **[UFS_STRING_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufs/ns-ufs-_ufs_string_descriptor)**
- **[UFS_UNIT_CONFIG_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufs/ns-ufs-ufs_unit_config_descriptor)**
- **[UFS_UNIT_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufs/ns-ufs-ufs_unit_descriptor)**
- [Universal Flash Storage 4.0 specification](https://www.jedec.org/standards-documents/docs/jesd220f)