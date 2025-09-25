# _ATA_PASS_THROUGH_DIRECT structure

## Description

The ATA_PASS_THROUGH_DIRECT structure is used in conjunction with an [IOCTL_ATA_PASS_THROUGH_DIRECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_ata_pass_through_direct) request to instruct the port driver to send an embedded ATA command to the target device.

## Members

### `Length`

Specifies the length in bytes of the ATA_PASS_THROUGH_DIRECT structure.

### `AtaFlags`

Indicates the direction of data transfer and specifies the kind of operation to be performed. The value of this member must be some combination of the flags in the following table.

| ATA flags | Meaning |
| --- | --- |
| ATA_FLAGS_DRDY_REQUIRED | Wait for DRDY status from the device before sending the command to the device. |
| ATA_FLAGS_DATA_IN | Read data from the device. |
| ATA_FLAGS_DATA_OUT | Write data to the device. |
| ATA_FLAGS_48BIT_COMMAND | The ATA command to be sent uses the 48-bit logical block address (LBA) feature set. When this flag is set, the contents of the **PreviousTaskFile** member in the ATA_PASS_THROUGH_DIRECT structure should be valid. |
| ATA_FLAGS_USE_DMA | Set the transfer mode to DMA. |
| ATA_FLAGS_NO_MULTIPLE | Read single sector only. |

### `PathId`

Contains an integer that indicates the IDE port or bus for the request. This value is set by the port driver.

### `TargetId`

Contains an integer that indicates the target device on the bus. This value is set by the port driver.

### `Lun`

Indicates the logical unit number of the device. This value is set by the port driver.

### `ReservedAsUchar`

Reserved for future use.

### `DataTransferLength`

Indicates the size, in bytes, of the data buffer. If an underrun occurs, the miniport driver must update this member to the number of bytes actually transferred.

### `TimeOutValue`

Indicates the number of seconds that are allowed for the request to execute before the OS-specific port driver determines that the request has timed out.

### `ReservedAsUlong`

Reserved for future use.

### `DataBuffer`

Pointer to the data buffer.

### `PreviousTaskFile`

Specifies the contents of the input task file register prior to the current pass-through command. This member is not used when the ATA_FLAGS_48BIT_COMMAND flag is not set.

### `CurrentTaskFile`

Specifies the content of the task file register on both input and output. On input, the array values in **CurrentTaskFile** map to the input registers in the following manner.

| Byte | Input Register |
| --- | --- |
| 0 | Features Register |
| 1 | Sector Count Register |
| 2 | Sector Number Register |
| 3 | Cylinder Low Register |
| 4 | Cylinder High Register |
| 5 | Device/Head Register |
| 6 | Command Register |
| 7 | Reserved |

When [IOCTL_ATA_PASS_THROUGH_DIRECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_ata_pass_through_direct) completes, the port driver updates **CurrentTaskFile** with the values that are present in the device's output registers at the completion of the embedded command. The array values in **CurrentTaskFile** correspond to the following task file output registers.

| Byte | Output Register |
| --- | --- |
| 0 | Error Register |
| 1 | Sector Count Register |
| 2 | Sector Number Register |
| 3 | Cylinder Low Register |
| 4 | Cylinder High Register |
| 5 | Device/Head Register |
| 6 | Status Register |
| 7 | Reserved |

## Remarks

The ATA_PASS_THROUGH_DIRECT structure is used with [IOCTL_ATA_PASS_THROUGH_DIRECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_ata_pass_through_direct). With this request, the system locks down the buffer in user memory and the device accesses this memory directly. For a double-buffered equivalent of this device control request, see [IOCTL_ATA_PASS_THROUGH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_ata_pass_through) and [ATA_PASS_THROUGH_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_ata_pass_through_ex).

## See also

[ATA_PASS_THROUGH_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_ata_pass_through_ex)

[IOCTL_ATA_PASS_THROUGH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_ata_pass_through)

[IOCTL_ATA_PASS_THROUGH_DIRECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_ata_pass_through_direct)