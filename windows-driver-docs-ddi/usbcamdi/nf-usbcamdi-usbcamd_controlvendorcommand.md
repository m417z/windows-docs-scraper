## Description

The **USBCAMD_ControlVendorCommand** function sends vendor-specific commands to the control pipe.

## Parameters

### `DeviceContext` [in]

Pointer to device-specific context.

### `Request` [in]

Specifies the value of the **Request** field for the vendor command.

### `Value` [in]

Specifies the value of the **Value** field for the vendor command.

### `Index` [in]

Specifies the value of the **Index** field for the vendor command.

### `Buffer` [in, out, optional]

Pointer to a data buffer if the command has data. If the command does not have any data, this value is **NULL**.

### `BufferLength` [in, out]

Pointer to the buffer length value. Buffer length is expressed in bytes. If the value of *Buffer* is **NULL**, *BufferLength* may also be **NULL**.

### `GetData` [in]

*GetData* indicates data was sent from the device to the host.

### `CommandComplete` [in, optional]

Pointer to a camera minidriver defined [CommandCompleteFunction](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nc-usbcamdi-pcommand_complete_function), which is called when the bulk read or write is completed. This value can be **NULL**.

### `CommandContext` [in, optional]

Pointer to a block of memory, that is passed as an argument to the camera minidriver defined [CommandCompleteFunction](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nc-usbcamdi-pcommand_complete_function).

## Return value

**USBCAMD_ControlVendorCommand** returns the NTSTATUS code from vendor command.

Other possible error codes include:

| Return code | Description |
|---|---|
| **STATUS_PENDING** | The vendor command is deferred. |
| **STATUS_INSUFFICIENT_RESOURCES** | There are insufficient resources to allocate the vendor command. |

## Remarks

This function may be called at IRQL >= PASSIVE_LEVEL. If the function is called at IRQL > PASSIVE_LEVEL, the command is deferred. After completion, the camera minidriver defined [CommandCompleteFunction](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nc-usbcamdi-pcommand_complete_function) is called and passed the value in the *CommandContext* argument.

## See also

[CommandCompleteFunction](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nc-usbcamdi-pcommand_complete_function)