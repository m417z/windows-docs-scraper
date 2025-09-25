# USBD_ParseConfigurationDescriptor function

## Description

The **USBD_ParseConfigurationDescriptor** routine has been deprecated. Use [USBD_ParseConfigurationDescriptorEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-usbd_parseconfigurationdescriptorex) instead.

## Parameters

### `ConfigurationDescriptor` [in]

Pointer to a USB configuration descriptor that contains the interface for which to search.

### `InterfaceNumber` [in]

Specifies the device-defined index of the interface to be retrieved. This should be set to -1 if it should not be a search criterion.

### `AlternateSetting` [in]

Specifies the device-defined alternate-setting index of the interface to be retrieved. If the caller does not wish the alternate setting value to be a search criterion, this parameter should be set to -1.

## Return value

**USBD_ParseConfigurationDescriptor** returns a pointer to the first interface descriptor that matches the given search criteria. If no interface matches the search criteria, it returns **NULL**.

## See also

[USB device driver programming reference](https://learn.microsoft.com/windows-hardware/drivers/ddi/_usbref/)

[USBD_ParseConfigurationDescriptorEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-usbd_parseconfigurationdescriptorex)