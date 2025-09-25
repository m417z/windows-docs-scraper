### Major Code: [IRP_MJ_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-device-control)

## Description

Set the current printer protocol code of the USB printer interface.

## Parameters

### Major code

### Input buffer

Pointer to a DWORD

### Input buffer length

sizeof(DWORD)

### Output buffer

NULL

### Output buffer length

0

### Input/output buffer

### Input/output buffer length

### Status block

Irp->IoStatus.Status is set to STATUS_SUCCESS if the request is successful.
Otherwise, Status to the appropriate error condition as a NTSTATUS code.

For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

IOCTL_USBPRINT_SET_PROTOCOL supports the following values:

| Defined constant | Value |
|--|--|
| USB_PRINTER_PROTOCOL_BIDI | 2 |

If an interface supports IPP over USB, then it is started in the IPP over USB protocol. If the Windows print system detects that IHV drivers have been installed for the printer, then it will switch the printer back to BIDI.

## See also