# UFS_UNIT_CONFIG_DESCRIPTOR structure

## Description

The **UFS_UNIT_CONFIG_DESCRIPTOR** structure describes the user-configurable parameters within the **[UFS_CONFIG_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufs/ns-ufs-ufs_config_descriptor)** structure.

## Members

### `bLUEnable`

Specifies whether the logical unit is enabled.

### `bBootLunID`

Specifies whether the logical unit is a bootable logical unit.

### `bLUWriteProtect`

Specifies whether the Logical Unit is write protected.

### `bMemoryType`

Specifies the Memory type of the device. Can be one of the following values.

| Value | Description |
|--|--|
| 0x00 | Normal Memory type |
| 0x01 | System code memory type |
| 0x02 | Non-Persistent memory type |
| 0x03 | Enhanced memory type 1 |
| 0x04 | Enhanced memory type 2 |
| 0x05 | Enhanced memory type 3 |
| 0x06 | Enhanced memory type 4 |
| All other values | Reserved for future use. |

### `dNumAllocUnits[4]`

Specifies the number of allocation units assigned to the logical unit.

### `bDataReliability`

**bDataReliability** defines the device behavior when a power failure occurs during a write operation to the logical unit. Can be one of the following values.

| Value | Description |
|--|--|
| 0x00 | The logical unit is not protected; thus its entire data may be lost as a result of a power failure during a write operation. |
| 0x01 | The logical unit is protected; thus its data is protected against power failure. |
| All other values | Reserved for future use. |

### `bLogicalBlockSize`

Specifies the logical block size.

### `bProvisioningType`

Specifies the provisioning type. Can be one of the following values.

| Value | Description |
|--|--|
| 0x00 | Thin Provisioning is disabled (default) |
| 0x02 | Thin Provisioning is enabled and Thin Provisioning Read Zeros (TPRZ) = 0 |
| 0x03 | Thin Provisioning is enabled and TPRZ = 1 |
| All other values | Reserved for future use. |

### `wContextCapabilities[2]`

Specifies the Context Capabilities.

### `Reserved[3]`

Reserved for future use.

## See also

- **[UFS_CONFIG_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufs/ns-ufs-ufs_config_descriptor)**