# USBD_CreateConfigurationRequest function

## Description

The **USBD_CreateConfigurationRequest** routine has been deprecated. Use [USBD_CreateConfigurationRequestEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-usbd_createconfigurationrequestex) instead.

## Parameters

### `ConfigurationDescriptor` [in]

Pointer to a caller-allocated [USB_CONFIGURATION_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_configuration_descriptor) structure that contains the configuration descriptor for the configuration to be selected.

### `Siz` [in, out]

Size of the [URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb) structure.

## Return value

**USBD_CreateConfigurationRequest** allocates a [URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb) structure, formats it for the URB_FUNCTION_SELECT_CONFIGURATION request (select-configuration request), and returns a pointer to the **URB**.

## See also

[USB device driver programming reference](https://learn.microsoft.com/windows-hardware/drivers/ddi/_usbref/)

[USBD_CreateConfigurationRequestEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-usbd_createconfigurationrequestex)