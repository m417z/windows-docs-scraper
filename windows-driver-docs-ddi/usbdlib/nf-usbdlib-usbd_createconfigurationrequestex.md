# USBD_CreateConfigurationRequestEx function

## Description

 The **USBD_CreateConfigurationRequestEx** routine allocates and formats a [URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb) to select a configuration for a USB device.

**USBD_CreateConfigurationRequestEx** replaces [USBD_CreateConfigurationRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-usbd_createconfigurationrequest).

## Parameters

### `ConfigurationDescriptor` [in]

Pointer to a caller-allocated [USB_CONFIGURATION_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_configuration_descriptor) structure that contains the configuration descriptor for the configuration to be selected. Typically, the client driver submits a URB of the type URB_FUNCTION_GET_DESCRIPTOR_FROM_DEVICE (see [_URB_CONTROL_DESCRIPTOR_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_control_descriptor_request)) to retrieve information about configurations, interfaces, endpoints, the vendor, and class-specific descriptors from a USB device. When the client driver specifies USB_CONFIGURATION_DESCRIPTOR_TYPE as the descriptor type, the request retrieves all device information in a **USB_CONFIGURATION_DESCRIPTOR** structure. The driver then passes the received pointer to the **USB_CONFIGURATION_DESCRIPTOR** structure in the *ConfigurationDescriptor* parameter.

### `InterfaceList` [in]

Pointer to the first element of a caller-allocated array of [USBD_INTERFACE_LIST_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/ns-usbdlib-_usbd_interface_list_entry) structures. The length of the array depends on the number of interfaces in the configuration descriptor. The number of elements in the array must be one more than the number of interfaces in the configuration. Initialize the array by calling [RtlZeroMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlzeromemory). The **InterfaceDescriptor** member of the last element in the array must be set to **NULL**.

## Return value

**USBD_CreateConfigurationRequestEx** allocates a [URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb) structure, formats it for the URB_FUNCTION_SELECT_CONFIGURATION request (select-configuration request), and returns a pointer to the **URB**. The client driver can then use the returned **URB** to send the select-configuration request to the host controller driver to set the configuration. You must free the **URB** when you have finished using it.

## Remarks

For information about how to build a select-configuration request and code example, see [How to Select a Configuration for a USB Device](https://learn.microsoft.com/windows-hardware/drivers/ddi/).

The returned value is a pointer to the [URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb) structure that you can use to submit a select-configuration request to the host controller driver to set the specified configuration.

After the USB driver stack completes the select-configuration request, you can inspect the [USBD_INTERFACE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_usbd_interface_information) structures. The **Pipes** member of **USBD_INTERFACE_INFORMATION** points to an array of [USBD_PIPE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_usbd_pipe_information) structures. The USB bus driver fills the array of **USBD_PIPE_INFORMATION** structures with information about the pipes associated with the endpoints of the interface. The client driver can obtain pipe handles from the `Pipes[i].PipeHandle` and use them to send I/O requests to specific pipes.

After you have completed all operations with the returned [URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb), you must free the **URB** by calling [ExFreePool](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-exfreepool).

You can allocate the configuration descriptor and the array from nonpaged or paged pool. Callers of this routine can run at IRQL <= DISPATCH_LEVEL if the memory pointed to by *ConfigurationDescriptor* and *InterfaceList* is allocated from nonpaged pool. Otherwise, callers must run at IRQL < DISPATCH_LEVEL.

## See also

[How to Select a Configuration for a USB Device](https://learn.microsoft.com/windows-hardware/drivers/ddi/)

[USB device driver programming reference](https://learn.microsoft.com/windows-hardware/drivers/ddi/_usbref/)

[USBD_INTERFACE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_usbd_interface_information)

[_URB_SELECT_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_select_configuration)