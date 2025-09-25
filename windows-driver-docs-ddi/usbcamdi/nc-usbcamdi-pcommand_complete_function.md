# PCOMMAND_COMPLETE_FUNCTION callback function

## Description

A camera minidriver's *CommandCompleteFunction* callback function allows the camera minidriver to perform any additional tasks necessary to complete certain USBCAMD services

## Parameters

### `DeviceContext`

Specifies the user-supplied value or structure relevant to the stream.

### `CommandContext`

Specifies the context passed to *CommandCompleteFunction* by certain USBCAMD services.

### `NtStatus`

Specifies the completion status of the called function.

## Return value

*CommandCompleteFunction* does not return a value.

## Remarks

The following USBCAMD services allow for the camera minidriver to perform any additional tasks:

USBCAMD_BulkReadWrite

USBCAMD_ControlVendorCommand

USBCAMD_WaitOnDeviceEvent.

## See also

[USBCAMD_BulkReadWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nc-usbcamdi-pfnusbcamd_bulkreadwrite)

[USBCAMD_ControlVendorCommand](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nf-usbcamdi-usbcamd_controlvendorcommand)

[USBCAMD_WaitOnDeviceEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nc-usbcamdi-pfnusbcamd_waitondeviceevent)