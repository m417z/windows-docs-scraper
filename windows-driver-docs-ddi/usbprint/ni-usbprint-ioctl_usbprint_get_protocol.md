### Major Code: [IRP_MJ_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-device-control)

## Description

Retrieve the current printer protocol code of the USB printer interface.

## Parameters

### Major code

### Input buffer

NULL

### Input buffer length

0

### Output buffer

Pointer to a DWORD

### Output buffer length

sizeof(DWORD)

### Input/output buffer

### Input/output buffer length

### Status block

Irp->IoStatus.Status is set to STATUS_SUCCESS if the request is successful.
Otherwise, Status to the appropriate error condition as a NTSTATUS code.

For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

IOCTL_USBPRINT_GET_PROTOCOL returns one of the following values:

| Defined constant | Value |
|--|--|
| USB_PRINTER_PROTOCOL_BIDI | 2 |
| USB_PRINTER_PROTOCOL_IPPOVERUSB | 4 |

## See also