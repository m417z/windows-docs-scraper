# USBD_SelectInterfaceUrbAllocateAndBuild function

## Description

The **USBD_SelectInterfaceUrbAllocateAndBuild** routine allocates and formats a [URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb) structure that is required for a request to select an interface or change its alternate setting.

## Parameters

### `USBDHandle` [in]

USBD handle that is retrieved by the client driver in a previous call to the [USBD_CreateHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-usbd_createhandle) routine.

### `ConfigurationHandle` [in]

Handle returned by the USB driver stack in the **UrbSelectConfiguration.ConfigurationHandle** member of the [URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb) structure, after the driver stack completes a select-configuration request.

### `InterfaceListEntry`

Pointer to a caller-allocated [**USBD_INTERFACE_LIST_ENTRY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/ns-usbdlib-_usbd_interface_list_entry) structure. For more information, see Remarks.

### `Urb` [out]

Pointer to a [URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb) structure that receives the URB allocated by **USBD_SelectInterfaceUrbAllocateAndBuild**. The client driver must free the URB when the driver has finished using it by calling [USBD_UrbFree](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-usbd_urbfree).

## Return value

The routine returns an NTSTATUS code. Possible values include but are not limited to, the status codes listed in the following table.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The routine call succeeded. |
| **STATUS_INVALID_PARAMETER** | The caller passed NULL in any of the parameters. |
| **STATUS_INSUFFICIENT_RESOURCES** | Insufficient memory available to complete the call. |

## Remarks

The client driver must call the **USBD_SelectInterfaceUrbAllocateAndBuild** routine after selecting a configuration in the device. After a select-configuration request completes, the client driver receives a configuration handle in the **UrbSelectConfiguration.ConfigurationHandle** member of the URB. That handle must be specified in the *ConfigurationHandle* parameter of **USBD_SelectInterfaceUrbAllocateAndBuild**.

A client driver calls **USBD_SelectInterfaceUrbAllocateAndBuild** to allocate and build an URB for a select-interface request to change the alternate setting of an interface, in the selected configuration. In the call to **USBD_SelectInterfaceUrbAllocateAndBuild**, the client driver must allocate and provide a pointer to a [USBD_INTERFACE_LIST_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/ns-usbdlib-_usbd_interface_list_entry) structure. The client driver must set the structure members as follows:

* The **InterfaceDescriptor** member must point to a [USB_INTERFACE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_interface_descriptor) structure that contains the interface descriptor with the alternate setting to select. The interface descriptor was obtained in a previous request to get a configuration descriptor and the associated interface and endpoint descriptors.
* The **Interface** member must be NULL.

**USBD_SelectInterfaceUrbAllocateAndBuild** allocates an [URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb) structure and fills it with information about the specified interface setting, and endpoints. The routine also allocates a [USBD_INTERFACE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_usbd_interface_information) structure. The structure members (except pipe information) are filled based on the specified interface descriptor.
**USBD_SelectInterfaceUrbAllocateAndBuild** sets the **Interface** member of [USBD_INTERFACE_LIST_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/ns-usbdlib-_usbd_interface_list_entry) to the address of **USBD_INTERFACE_INFORMATION** in the URB. The client driver can send this URB to the USB driver stack to select an alternate setting in the interface.

A client driver cannot change alternate settings in multiple interfaces in a single select-interface request. Each request targets only one interface.

After the select-interface request is complete, the USB driver stack populates [USBD_INTERFACE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_usbd_interface_information) with information about pipes opened for endpoints that are defined in the selected alternate setting. The client driver can obtain those pipe handles by inspecting the array pointed to by the **Pipes** member of **USBD_INTERFACE_INFORMATION**, and store the handles for future data transfer requests.

The client driver can reuse an URB allocated by **USBD_SelectInterfaceUrbAllocateAndBuild** *only* for another select-interface request for the same alternate setting. The client driver *must not* reuse the URB for any other type of request, or for another select-interface request for a different alternate setting. Instead of allocating a new URB, reusing an existing URB is the preferred approach in certain scenarios. Consider a USB audio device that has an interface with two alternate settings, defined for two bandwidth requirements. Setting 0 is defined for zero bandwidth; Setting 1 is defined to use a certain amount of bandwidth. The client driver wants to frequently switch between the two settings depending on whether the device is in use. To implement this scenario, the client driver can allocate two URBs for select-interface requests, one per setting. The client driver can use (and reuse) an URB for a select-interface request to select Setting 1 when there are sounds to send to the device. To conserve bandwidth when there are no sounds, the client driver can use (and reuse) the other URB to switch to Setting 0. This implementation prevents the client driver from allocating URBs for each of those select-interface requests, every time the driver needs to change the setting.

## See also

[USBD_CreateHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-usbd_createhandle)

[USBD_SelectConfigUrbAllocateAndBuild](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-usbd_selectconfigurballocateandbuild)