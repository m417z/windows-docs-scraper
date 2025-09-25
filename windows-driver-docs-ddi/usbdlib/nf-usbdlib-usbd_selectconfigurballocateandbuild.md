# USBD_SelectConfigUrbAllocateAndBuild function

## Description

The **USBD_SelectConfigUrbAllocateAndBuild** routine allocates and formats a [URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb) structure that is required to select a configuration for a USB device.

**Note** In Windows 8, **USBD_SelectConfigUrbAllocateAndBuild** replaces [USBD_CreateConfigurationRequestEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-usbd_createconfigurationrequestex) and [USBD_CreateConfigurationRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-usbd_createconfigurationrequest).

## Parameters

### `USBDHandle` [in]

USBD handle that is retrieved by the client driver in a previous call to the [USBD_CreateHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-usbd_createhandle) routine.

### `ConfigurationDescriptor` [in]

Pointer to a caller-allocated [USB_CONFIGURATION_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_configuration_descriptor) structure that contains the configuration descriptor for the configuration to be selected. Typically, the client driver submits an URB of the type URB_FUNCTION_GET_DESCRIPTOR_FROM_DEVICE (see [_URB_CONTROL_DESCRIPTOR_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_control_descriptor_request)) to retrieve information about configurations, interfaces, endpoints, the vendor, and class-specific descriptors from a USB device. When the client driver specifies USB_CONFIGURATION_DESCRIPTOR_TYPE as the descriptor type, the request retrieves all device information in a **USB_CONFIGURATION_DESCRIPTOR** structure. The driver then passes the received pointer to the **USB_CONFIGURATION_DESCRIPTOR** structure in the *ConfigurationDescriptor* parameter.

### `InterfaceList` [in]

Pointer to the first element of a caller-allocated array of [USBD_INTERFACE_LIST_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/ns-usbdlib-_usbd_interface_list_entry) structures. The length of the array depends on the number of interfaces in the configuration descriptor. For more information, see Remarks.

### `Urb` [out]

Pointer to a [URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb) structure that receives the URB allocated by **USBD_SelectConfigUrbAllocateAndBuild**. The client driver must free the URB when the driver has finished using it by calling [USBD_UrbFree](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-usbd_urbfree).

## Return value

The **USBD_SelectConfigUrbAllocateAndBuild** routine returns an NT status code.

Possible values include, but are not limited to, the status codes listed in the following table.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The request was successful. |
| **STATUS_INVALID_PARAMETER** | The caller passed an invalid parameter value. *USBDHandle* or *Urb* is NULL. |
| **STATUS_INSUFFICIENT_RESOURCES** | Insufficient memory available to complete the request. |

## Remarks

Before calling **USBD_SelectConfigUrbAllocateAndBuild**, the client driver must perform the following tasks:

1. Get the number of interfaces in the configuration. This information is contained in the **bNumInterfaces** member of the [USB_CONFIGURATION_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_configuration_descriptor) structure pointed to by *ConfigurationDescriptor*.
2. Create an array of [USBD_INTERFACE_LIST_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/ns-usbdlib-_usbd_interface_list_entry) structures. The number of elements in the array must be one more than the number of interfaces. Initialize the array by calling [RtlZeroMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlzeromemory).
3. Obtain an interface descriptor for each interface (or its alternate setting) in the configuration. You can obtain those interface descriptors by calling [USBD_ParseConfigurationDescriptorEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-usbd_parseconfigurationdescriptorex).
4. For each element (except the last element) in the array, set the **InterfaceDescriptor** member to the address of an interface descriptor. For the first element in the array, set the **InterfaceDescriptor** member to the address of the interface descriptor that represents the first interface in the configuration. Similarly for the *n*th element in the array, set the **InterfaceDescriptor** member to the address of the interface descriptor that represents the *n*th interface in the configuration.
5. The **InterfaceDescriptor** member of the last element must be set to NULL.

**USBD_SelectConfigUrbAllocateAndBuild** performs the following tasks:

* Creates an URB and fills it with information about the specified configuration, its interfaces and endpoints, and sets the request type to URB_FUNCTION_SELECT_CONFIGURATION.
* Fills a [USBD_INTERFACE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_usbd_interface_information) structure in the URB for each interface.
* Sets the **Interface** member of the *n*th element of the caller-provided [USBD_INTERFACE_LIST_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/ns-usbdlib-_usbd_interface_list_entry) array to the address of the corresponding [USBD_INTERFACE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_usbd_interface_information) structure in the URB.

You can use the received pointer to the [URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb) structure to submit a select-configuration request to the USB driver stack to set the specified configuration. In addition, you can use the **Interface** member of each [USBD_INTERFACE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_usbd_interface_information) structure in the array to get information about the interface. Within each **USBD_INTERFACE_INFORMATION** structure, the **Pipes** member is an array of [USBD_PIPE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_usbd_pipe_information) structures. Each **USBD_PIPE_INFORMATION** structure contains information about the pipes opened (by the USB driver stack) for the endpoints in that interface. You can obtain pipe handles from the array and store them for future I/O requests to the device.

## See also

[USBD_CreateConfigurationRequestEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-usbd_createconfigurationrequestex)

[USBD_CreateHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-usbd_createhandle)