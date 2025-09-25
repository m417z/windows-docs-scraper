# USBD_ValidateConfigurationDescriptor function

## Description

The **USBD_ValidateConfigurationDescriptor** routine validates all descriptors returned by a device in its response to a configuration descriptor request.

## Parameters

### `ConfigDesc` [in]

Pointer to a configuration descriptor that includes all interface, endpoint, vendor, and class-specific descriptors retrieved from a USB device.

### `BufferLength` [in]

Size, in bytes, of the configuration descriptor being validated.

### `Level` [in]

Level of validation to be performed. The following are valid values:

* 1-Basic validation of the configuration descriptor header.
* 2-Full validation of the configuration descriptor including checking for invalid endpoint addresses, interface numbers, descriptor structures, interface alternate settings, number of interfaces and **bLength** fields of all descriptors.
* 3-In addition to the validation for levels 1 and 2, level 3 validates plus validates the number of endpoints in each interface, enforces the USB specification's descriptor **bLength** sizes, and verifies that all interface numbers are in sequential order.

### `Offset` [out]

 Offset within configuration descriptor where validation failed. Only valid when a status other than USBD_STATUS_SUCCESS is returned.

### `Tag` [in, optional]

Pool tag used by **USBD_ValidateConfigurationDescriptor** when allocating memory.

## Return value

USBD_STATUS_SUCCESS, or appropriate USBD error code if validation failed.

## See also

[USB device driver programming reference](https://learn.microsoft.com/windows-hardware/drivers/ddi/_usbref/)