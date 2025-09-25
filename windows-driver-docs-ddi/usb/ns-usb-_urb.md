# _URB structure

## Description

The **URB** structure is used by USB client drivers to describe USB request blocks (URBs) that send requests to the USB driver stack. The **URB** structure defines a format for all possible commands that can be sent to a USB device.

## Members

### `UrbHeader`

Provides basic information about the request being sent to the host controller driver. For more information, see [_URB_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_header).

### `UrbSelectInterface`

Defines the format of a select interface command for a USB device. For more information, see [_URB_SELECT_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_select_interface).

### `UrbSelectConfiguration`

Defines the format of a select configuration command for a USB device. For more information, see [_URB_SELECT_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_select_configuration).

### `UrbPipeRequest`

Defines the format for a command for a pipe in a USB endpoint. For more information, see [_URB_PIPE_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_pipe_request).

### `UrbFrameLengthControl`

Deprecated in Windows 2000 and later operating systems and is not supported by Microsoft. Do not use.

### `UrbGetFrameLength`

Deprecated in Windows 2000 and later operating systems and is not supported by Microsoft. Do not use.

### `UrbSetFrameLength`

Deprecated in Windows 2000 and later operating systems and is not supported by Microsoft. Do not use.

### `UrbGetCurrentFrameNumber`

Defines the format for a command to get the current frame number on a USB bus. For more information, see [_URB_GET_CURRENT_FRAME_NUMBER](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_get_current_frame_number).

### `UrbControlTransfer`

Defines the format for a command to transmit or receive data on a control pipe. For more information, see [_URB_CONTROL_TRANSFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_control_transfer).

### `UrbControlTransferEx`

Defines the format for a command to transmit or receive data on a control pipe. For more information, see [_URB_CONTROL_TRANSFER_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_control_transfer_ex).

Defines the format for a command to transmit or receive data on a control pipe.

### `UrbBulkOrInterruptTransfer`

Defines the format for a command to transmit or receive data on a bulk pipe, or to receive data from an interrupt pipe. For more information, see [_URB_BULK_OR_INTERRUPT_TRANSFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_bulk_or_interrupt_transfer).

### `UrbIsochronousTransfer`

Defines the format of an isochronous transfer to a USB device. For more information, see [_URB_ISOCH_TRANSFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_isoch_transfer).

### `UrbControlDescriptorRequest`

Defines the format for a command to retrieve or set descriptor(s) on a USB device. For more information, see [_URB_CONTROL_DESCRIPTOR_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_control_descriptor_request).

### `UrbControlGetStatusRequest`

Defines the format for a command to get status from a device, interface, or endpoint. For more information, see [_URB_CONTROL_GET_STATUS_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_control_get_status_request).

### `UrbControlFeatureRequest`

Defines the format for a command to set or clear USB-defined features on a device, interface, or endpoint. For more information, see [_URB_CONTROL_FEATURE_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_control_feature_request).

### `UrbControlVendorClassRequest`

Defines the format for a command to send or receive a vendor or class-specific request on a device, interface, endpoint, or other device-defined target. For more information, see [_URB_CONTROL_VENDOR_OR_CLASS_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_control_vendor_or_class_request).

### `UrbControlGetInterfaceRequest`

Defines the format for a command to get the current alternate interface setting for a selected interface. For more information, see [_URB_CONTROL_GET_INTERFACE_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_control_get_interface_request).

### `UrbControlGetConfigurationRequest`

Defines the format for a command to get the current configuration for a device. For more information, see [_URB_CONTROL_GET_CONFIGURATION_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_control_get_configuration_request).

### `UrbOSFeatureDescriptorRequest`

Defines the format for a command to request a Microsoft OS Descriptor. For more information, see [_URB_OS_FEATURE_DESCRIPTOR_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_os_feature_descriptor_request).

### `UrbOpenStaticStreams`

Defines the format for a command to open streams in a bulk endpoint of a USB 3.0 device. For more information, see [_URB_OPEN_STATIC_STREAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_open_static_streams) and [How to Open and Close Static Streams in a USB Bulk Endpoint](https://learn.microsoft.com/windows-hardware/drivers/ddi/).

### `UrbGetIsochPipeTransferPathDelays`

Defines the format for a command to retrieve delays associated with isochronous transfer programming in the host controller and transfer completion so that the client driver can ensure that the device gets the isochronous packets in time.
For more information, see [_URB_GET_ISOCH_PIPE_TRANSFER_PATH_DELAYS](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_get_isoch_pipe_transfer_path_delays).

## Remarks

For information about the function codes to set in each structure, see [_URB_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_header).

## See also

[IOCTL_INTERNAL_USB_SUBMIT_URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_internal_usb_submit_urb)

[USB Structures](https://learn.microsoft.com/windows-hardware/drivers/ddi/_usbref/#structures)