# _USBD_INTERFACE_LIST_ENTRY structure

## Description

The **USBD_INTERFACE_LIST_ENTRY** structure is used by USB client drivers to create an array of interfaces to be inserted into a configuration request.

## Members

### `InterfaceDescriptor`

Pointer to a [USB_INTERFACE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_interface_descriptor) structure that describes the interface to be added to the configuration request.

### `Interface`

Pointer to a [USBD_INTERFACE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_usbd_interface_information) structure that describes the properties and settings of the interface pointed to by *InterfaceDescriptor*.

## Remarks

This structure is used by USB clients with the routine [USBD_CreateConfigurationRequestEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-usbd_createconfigurationrequestex). Clients allocate an array of these structures, one for each interface to be configured. Clients must also allocate a **NULL** entry in the array to be used as a terminator before calling **USBD_CreateConfigurationRequestEx**.

## See also

[USB Structures](https://learn.microsoft.com/windows-hardware/drivers/ddi/_usbref/#structures)

[USBD_CreateConfigurationRequestEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-usbd_createconfigurationrequestex)