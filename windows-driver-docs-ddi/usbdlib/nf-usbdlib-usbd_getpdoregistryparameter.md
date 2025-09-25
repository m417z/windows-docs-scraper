# USBD_GetPdoRegistryParameter function

## Description

The **USBD_GetPdoRegistryParameter** routine retrieves the value from the specified key in the USB device's hardware registry.

## Parameters

### `PhysicalDeviceObject` [in]

Specifies the device object for the USB device.

### `ParameterLength` [in]

Size, in bytes, of the buffer that is pointed to by *Parameter*.

### `KeyName` [in]

Pointer to a string containing the name of the registry key.

### `KeyNameLength` [in]

Size, in bytes, of the buffer that is pointed to by *KeyName*.

### `Parameter` [in, out]

Pointer to a caller-allocated buffer that receives the registry value.

## Return value

The **USBD_GetPdoRegistryParameter** returns STATUS_SUCCESS when the operation succeeds or an appropriate error status when the operation fails.

## See also

[USB device driver programming reference](https://learn.microsoft.com/windows-hardware/drivers/ddi/_usbref/)