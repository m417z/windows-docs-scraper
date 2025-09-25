# _SRB_IO_CONTROL structure

## Description

**Note** The SCSI port driver and SCSI miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver-overview) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Members

### `HeaderLength`

Is **sizeof**(SRB_IO_CONTROL).

### `Signature`

Identifies the application-dedicated, target HBA for this request. This signature is used to prevent conflicts in **ControlCode** values between vendors. It should be a string of ASCII characters. If a miniport driver does not recognize the input **Signature** value, it must complete the request with a status of SRB_STATUS_INVALID_REQUEST.

### `Timeout`

Indicates the interval in seconds that the request can execute before the OS-specific port driver might consider it timed out. Miniport drivers should be enforcing timeouts for SRB_IO_CONTROL, especially for any privately defined SRB_IO_CONTROL.

### `ControlCode`

Indicates the operation to be performed. There are no system-defined operations. Values must be defined by the driver as a set of private I/O control codes with which the application can make requests by calling the Win32 [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) function. For more information about defining private I/O control codes for device control requests, see [Using I/O Control Codes](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-i-o-control-codes).

### `ReturnCode`

Returns a status code for examination by the requesting application.

### `Length`

Indicates the size in bytes of the immediately following data area. This area can be divided for the particular operation into input and output areas. For input requests, the contents of the DataBuffer will be copied to the requester up to the returned value of DataTransferLength.

## Remarks

This structure is used by applications to send requests directly to an application-dedicated HBA. Note that such an application also must set up requests to program its dedicated HBA.

## See also

SCSI Port I/O Control Codes

[SCSI_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_scsi_request_block)