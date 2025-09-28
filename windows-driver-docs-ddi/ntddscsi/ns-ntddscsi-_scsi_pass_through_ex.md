# SCSI_PASS_THROUGH_EX structure

## Description

The **SCSI_PASS_THROUGH_EX** structure is used in conjunction with an **IOCTL_SCSI_PASS_THROUGH_EX** request to instruct the port driver to send an embedded SCSI command to the target device. **SCSI_PASS_THROUGH_EX** can contain a bi-directional data transfers and a variable length command data block.

> [!NOTE]
> The SCSI port driver and SCSI miniport driver models may be altered or unavailable in the future. Instead, use the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver-overview) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Members

### `Version`

The version of this structure. Set to 0.

### `Length`

The size of this structure, in bytes. Set to ```sizeof(SCSI_PASS_THROUGH_EX)```.

### `CdbLength`

The size of the SCSI command descriptor block in **Cdb**, in bytes.

### `StorAddressLength`

The length, in bytes, of the storage device address structure at the offset of **StorAddressOffset** after this structure.

### `ScsiStatus`

Reports the SCSI status that was returned by the HBA or the target device.

### `SenseInfoLength`

The size in bytes of the request-sense buffer. This member is optional and can be set to 0.

### `DataDirection`

Indicates whether the SCSI command will read or write data. This field must be one of the following values:

| Value | Meaning |
| ----- | ------- |
| SCSI_IOCTL_DATA_OUT | Write data to the device. |
| SCSI_IOCTL_DATA_IN | Read data from the device. |
| SCSI_IOCTL_DATA_UNSPECIFIED | No data is being transferred. |
| SCSI_IOCTL_DATA_BIDIRECTIONAL | Data is valid for both input and output. |

### `Reserved`

Reserved. Set to 0.

### `TimeOutValue`

Indicates the interval in seconds that the request can execute before the port driver considers it timed out. Do not set this value to 0. Default values often range from:

* Typical operations: 30 to 60 seconds
* Short operations: 10 to 30 seconds
* Medium operations: 30 to 120 seconds
* Long operations (like format, extended self-test): 300 to 3600 seconds or more

### `StorAddressOffset`

The location of the target storage device address structure, in bytes, from the beginning of this structure.

### `SenseInfoOffset`

Offset from the beginning of this structure to the request-sense buffer. Set to 0 if no request-sense buffer is present.

### `DataOutTransferLength`

Indicates the size in bytes of the output data buffer. Many devices transfer chunks of data of predefined length. The value in **DataOutTransferLength** must be an integral multiple of this predefined, minimum length that is specified by the device. If an underrun occurs, the miniport driver must update this member to the number of bytes actually transferred. If no output data buffer is present, this member is set to 0.

### `DataInTransferLength`

Indicates the size in bytes of the input data buffer. Many devices transfer chunks of data of predefined length. The value in **DataInTransferLength** must be an integral multiple of this predefined, minimum length that is specified by the device. If an underrun occurs, the miniport driver must update this member to the number of bytes actually transferred. If no input data buffer is present, this member is set to 0.

### `DataOutBufferOffset`

Contains an offset from the beginning of this structure to the output data buffer. The offset must respect the data alignment requirements of the device.

### `DataInBufferOffset`

Contains an offset from the beginning of this structure to the input data buffer. The offset must respect the data alignment requirements of the device.

### `Cdb`

Specifies the SCSI command descriptor block to be sent to the target device.

## Remarks

The **SCSI_PASS_THROUGH_EX** structure is used with the [**IOCTL_SCSI_PASS_THROUGH_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_scsi_pass_through_ex) control code, which is a buffered device control request. To bypass buffering in system memory, callers should use [**IOCTL_SCSI_PASS_THROUGH_DIRECT_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_scsi_pass_through_direct_ex). When handling an **IOCTL_SCSI_PASS_THROUGH_DIRECT_EX** request, the system locks down the buffer in user memory and the device accesses this memory directly.

> [!NOTE]
> Drivers executing on a 64-bit version of Windows must use the **SCSI_PASS_THROUGH32_EX** structure as the request data type when handling an [**IOCTL_SCSI_PASS_THROUGH_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_scsi_pass_through_ex) request from a 32-bit process.

## See also

[**IOCTL_SCSI_PASS_THROUGH**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_scsi_pass_through)

[**IOCTL_SCSI_PASS_THROUGH_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_scsi_pass_through_ex)

[**SCSI_PASS_THROUGH**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_scsi_pass_through)