# _SCSI_PASS_THROUGH_DIRECT_EX structure

## Description

The **SCSI_PASS_THROUGH_DIRECT_EX** structure is used in conjunction with an [IOCTL_SCSI_PASS_THROUGH_DIRECT_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_scsi_pass_through_direct_ex) request to instruct the port driver to send an embedded SCSI command to the target device. **SCSI_PASS_THROUGH_DIRECT_EX** can contain a bi-directional data transfers and a variable length command data block.
> [!NOTE]
> The SCSI port driver and SCSI miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver-overview) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Members

### `Version`

The version of this structure. Set to 0.

### `Length`

The size of this structure. Set to **sizeof**(SCSI_PASS_THROUGH_DIRECT_EX).

### `CdbLength`

Indicates the size in bytes of the SCSI command descriptor block in **Cdb**.

### `StorAddressLength`

The length of the storage device address structure at the offset of **StorAddressOffset** after this structure. This is set to **sizeof**(STOR_ADDR_BTL8).

### `ScsiStatus`

Reports the SCSI status that was returned by the HBA or the target device.

### `SenseInfoLength`

Indicates the size in bytes of the request-sense buffer. This member is optional and can be set to 0.

### `DataDirection`

This field must have one of these values:

|Data Transfer Type|Meaning|
|----|----|
|SCSI_IOCTL_DATA_IN|Read data from the device.|
|SCSI_IOCTL_DATA_OUT|Write data to the device.|
|SCSI_IOCTL_DATA_UNSPECIFIED|No data is transferred.|
|SCSI_IOCTL_DATA_BIDIRECTIONAL|Data is valid for both input and output.|

### `Reserved`

Reserved. Set to 0.

### `TimeOutValue`

Indicates the interval in seconds that the request can execute before the port driver considers it timed out.

### `StorAddressOffset`

The location of the target device's [STOR_ADDR_BTL8](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsi/ns-scsi-_stor_addr_btl8) address structure, in bytes, from the beginning of this structure.

### `SenseInfoOffset`

Offset from the beginning of this structure to the request-sense buffer. Set to 0 if no request-sense buffer is present.

### `DataOutTransferLength`

Indicates the size in bytes of the output data buffer. Many devices transfer chunks of data of predefined length. The value in **DataOutTransferLength** must be an integral multiple of this predefined, minimum length that is specified by the device. If an underrun occurs, the miniport driver must update this member to the number of bytes actually transferred. If no output data buffer is present, this member is set to 0.

### `DataInTransferLength`

Indicates the size in bytes of the input data buffer. Many devices transfer chunks of data of predefined length. The value in **DataInTransferLength** must be an integral multiple of this predefined, minimum length that is specified by the device. If an underrun occurs, the miniport driver must update this member to the number of bytes actually transferred. If no input data buffer is present, this member is set to 0.

### `DataOutBuffer`

A pointer to an output data buffer.

### `DataInBuffer`

A pointer to an input data buffer.

### `Cdb`

Specifies the SCSI command descriptor block to be sent to the target device.

## Remarks

The **SCSI_PASS_THROUGH_DIRECT_EX** structure is used with [IOCTL_SCSI_PASS_THROUGH_DIRECT_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_scsi_pass_through_direct_ex). With this request, the system locks down the buffer in user memory and the device accesses this memory directly. For a double-buffered equivalent of this device control request see **IOCTL_SCSI_PASS_THROUGH_EX** and [SCSI_PASS_THROUGH_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_scsi_pass_through_ex).

> [!NOTE]
> Drivers executing on a 64 bit version of Windows must use the **SCSI_PASS_THROUGH_DIRECT32_EX** structure as the request data type when handling an [IOCTL_SCSI_PASS_THROUGH_DIRECT_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_scsi_pass_through_direct_ex) request from a 32 bit process.

## See also

[IOCTL_SCSI_PASS_THROUGH_DIRECT_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_scsi_pass_through_direct_ex)

[IOCTL_SCSI_PASS_THROUGH_DIRECT_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_scsi_pass_through_direct_ex)

[SCSI_PASS_THROUGH_DIRECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_scsi_pass_through_direct)

[STOR_ADDR_BTL8](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsi/ns-scsi-_stor_addr_btl8)