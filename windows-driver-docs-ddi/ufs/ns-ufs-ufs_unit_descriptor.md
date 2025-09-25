# UFS_UNIT_DESCRIPTOR structure

## Description

The **UFS_UNIT_DESCRIPTOR** structure describes a generic unit descriptor.

## Members

### `bLength`

Specifies the length, in bytes, of this descriptor.

### `bDescriptorIDN`

Specifies the type of the descriptor. This descriptor will have a value of **UFS_DESC_UNIT_IDN**.

### `bUnitIndex`

Specifies unit index

### `bLUEnable`

Specifies if the logic unit number (LUN) is enabled. If **bLUEnable** is equal to 0x00, the logical unit is disabled.

### `bBootLunID`

### `bLUWriteProtect`

Specifies if the logical unit is write-protected. Contains one of the following values:

| Value | Description |
|--|--|
| 0x00 | The logical unit is not write protected. |
| 0x01 | The logical unit is write protected. |
| 0x02 | The logical unit is permanently write protected. |

### `bLUQueueDepth`

Specifies the logical unit queue depth. Can be any value from 0x00 to 0xff.

### `bPSASensitive`

Specifies if the logical unit is sensitive to soldering. Contains one of the following values:

| Value | Description |
|--|--|
| 0x00 | The logical unit is not sensitive to soldering. |
| 0x01 | The logical unit is sensitive to soldering. |

### `bMemoryType`

Specifies the desired memory type. The **wSupportedMemoryTypes** parameter in the **[UFS_GEOMETRY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufs/ns-ufs-ufs_geometry_descriptor)** structure indicates which memory types are supported by the device.

### `bDataReliability`

Specifies if the device is protected against a power failure during a write operation to the logical unit.

### `bLogicalBlockSize`

Specifies the logical block size of the descriptor. Set the value of this equal to the corresponding value in **dOptimalLogicalBlockSize** of **[UFS_GEOMETRY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufs/ns-ufs-ufs_geometry_descriptor)** for the specific logical unit memory type.

### `qLogicalBlockCount[8]`

Specifies the total number of addressable logical blocks in the logical unit.

### `dEraseBlockSize[4]`

Specifies the erase block size.

### `bProvisioningType`

Specifies the provisioning type.

### `qPhyMemResourceCount[8]`

Specifies the total physical memory resources available in the logical unit.

### `wContextCapabilities[2]`

Specifies the number of contexts to be supported in each logical unit.

### `bLargeUnitGranularity_M1`

Specifies the Large Unit granularity, minus one.

### `wLUMaxActiveHPBRegions`

Specifies the maximum number of HPB regions assigned to the HPB logical unit.

### `wHPBPinnedRegionStartIdx`

Specifies the HPB pinned region start offset.

### `wNumHPBPinnedRegions`

Specifies the number of HPB pinned regions assigned to the HPB logical unit.

### `dLUNumWriteBoosterBufferAllocUnits`

Specifies the number of logical unit WriteBooster buffer allocation units.

## Remarks

**bPSASensitive** and **dEraseBlockSize** are updated automatically after device configuration.

## See also

- **[UFS_GEOMETRY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufs/ns-ufs-ufs_geometry_descriptor)**
- **[UFS_RPMB_UNIT_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufs/ns-ufs-ufs_rpmb_unit_descriptor)**