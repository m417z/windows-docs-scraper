# UFS_RPMB_UNIT_DESCRIPTOR structure

## Description

**UFS_RPMB_UNIT_DESCRIPTOR** structure describes the contents of a Replay Protected Memory Block (RBMB) Unit.

## Members

### `bLength`

Specifies the length, in bytes, of this descriptor.

### `bDescriptorIDN`

Specifies the type of the descriptor. This descriptor will have a value of **UFS_DESC_UNIT_IDN**.

### `bUnitIndex`

Specifies the unit index.

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

Specifies the desired memory type. Equal to 0x0F.

### `Reserved`

Reserved for future use.

### `bLogicalBlockSize`

Specifies the logical block size of the descriptor.

### `qLogicalBlockCount[8]`

Specifies the total number of addressable logical blocks in the logical unit.

### `dEraseBlockSize[4]`

Specifies the erase block size.

### `bProvisioningType`

Specifies the provisioning type.

### `qPhyMemResourceCount[8]`

Specifies the total physical memory resources available in the logical unit.

### `Reserved2[3]`

Reserved for future use.