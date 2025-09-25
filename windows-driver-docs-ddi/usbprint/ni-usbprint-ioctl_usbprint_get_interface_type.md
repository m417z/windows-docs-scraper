### Major Code: [IRP_MJ_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-device-control)

## Description

Get the protocol capabilities of the USB printer interface.

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

IOCTL_USBPRINT_GET_INTERFACE_TYPE returns one of the following values:

| Defined constant | Value | Description |
|--|--|--|
| USB_PRINTER_INTERFACE_CLASSIC | 1 | Has only 7-1-2 alternate config |
| USB_PRINTER_INTERFACE_IPP | 2 | Has only 7-1-4 alternate config |
| USB_PRINTER_INTERFACE_DUAL | 3 | Has both 7-1-2 and 7-1-4 alternate configs |

7-1-2 refers to USB class printer(7), subclass(1), protocol(2==BIDI).

7-1-4 refers to USB class printer(7), subclass(1), protocol(4==IPP over USB).

## See also