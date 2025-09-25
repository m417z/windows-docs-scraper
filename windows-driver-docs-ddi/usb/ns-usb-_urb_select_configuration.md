# _URB_SELECT_CONFIGURATION structure

## Description

The **_URB_SELECT_CONFIGURATION** structure is used by client drivers to select a configuration for a USB device.

## Members

### `Hdr`

Pointer to a [_URB_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_header) structure that specifies the URB header information. **Hdr.Function** must be URB_FUNCTION_SELECT_CONFIGURATION, and **Hdr.Length** must be the size of the entire URB. Drivers may use the GET_SELECT_CONFIGURATION_REQUEST_SIZE macro defined in usbdlib.h to obtain the size of the URB.

### `ConfigurationDescriptor`

Pointer to an initialized USB configuration descriptor that identifies the configuration to be used on the device. If this member is **NULL**, the device will be set to an unconfigured state.

### `ConfigurationHandle`

Contains a handle that is used to access this configuration on return from the host controller driver. USB client drivers must treat this member as opaque.

### `Interface`

Specifies a variable length array of [USBD_INTERFACE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_usbd_interface_information) structures, each describing an interface supported by the configuration being selected.

Before the request is sent to the host controller driver, the driver may select an alternate setting for one or more of the interfaces contained in this array by setting members of the [USBD_INTERFACE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_usbd_interface_information) structure for that interface.

On return from the host controller driver, this member contains a [USBD_INTERFACE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_usbd_interface_information) structure with data describing the capabilities and format of the endpoints within that interface.

## Remarks

An URB_FUNCTION_SELECT_CONFIGURATION URB consists of a **_URB_SELECT_CONFIGURATION** structure followed by a sequence of variable-length array of [USBD_INTERFACE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_usbd_interface_information) structures, each element in the array for each unique interface number in the configuration. Client drivers must allocate enough memory to contain one [USBD_PIPE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_usbd_pipe_information) structure for each endpoint in the selected interfaces.

Drivers can use the [USBD_CreateConfigurationRequestEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-usbd_createconfigurationrequestex) service routine to allocate the URB.

Other members that are part of this structure but not described here should be treated as opaque and considered to be reserved for system use.

## See also

[URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb)

[USB Structures](https://learn.microsoft.com/windows-hardware/drivers/ddi/_usbref/#structures)

[USBD_CreateConfigurationRequestEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-usbd_createconfigurationrequestex)

[USBD_INTERFACE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_usbd_interface_information)

[USBD_PIPE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_usbd_pipe_information)

[_URB_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_header)