# _URB_HEADER structure

## Description

The **_URB_HEADER** structure is used by USB client drivers to provide basic information about the request being sent to the host controller driver.

## Members

### `Length`

Specifies the length, in bytes, of the URB. For URB requests that use data structures other than **_URB_HEADER**, this member must be set to the length of the entire URB request structure, not the _URB_HEADER size.

### `Function`

Specifies a numeric code indicating the requested operation for this URB. One of the following values must be set:

#### URB_FUNCTION_SELECT_CONFIGURATION

Indicates to the host controller driver that a configuration is to be selected. If set, the URB is used with [URB_SELECT_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_select_configuration) as the data structure.

#### URB_FUNCTION_SELECT_INTERFACE

Indicates to the host controller driver that an alternate interface setting is being selected for an interface. If set, the URB is used with [_URB_SELECT_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_select_interface) as the data structure.

#### URB_FUNCTION_ABORT_PIPE

Indicates that all outstanding requests for a pipe should be canceled. If set, the URB is used with [_URB_PIPE_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_pipe_request) as the data structure. This general-purpose request enables a client to cancel any pending transfers for the specified pipe. Pipe state and endpoint state are unaffected. The abort request might complete before all outstanding requests have completed. Do *not* assume that completion of the abort request implies that all other outstanding requests have completed.

#### URB_FUNCTION_TAKE_FRAME_LENGTH_CONTROL

This URB function is **deprecated** in Windows 2000 and later operating systems and is not supported by Microsoft. Do not use. If you specify this function with an URB request, the request will fail and the system will report an error.

#### URB_FUNCTION_RELEASE_FRAME_LENGTH_CONTROL

This URB function is **deprecated** in Windows 2000 and later operating systems and is not supported by Microsoft. Do not use. If you specify this function with an URB request, the request will fail and the system will report an error.

#### URB_FUNCTION_GET_FRAME_LENGTH

This URB function is **deprecated** in Windows 2000 and later operating systems and is not supported by Microsoft. Do not use. If you use this function with a URB request, the request will fail and the system will report an error.

#### URB_FUNCTION_SET_FRAME_LENGTH

This URB function is **deprecated** in Windows 2000 and later operating systems and is not supported by Microsoft. Do not use. If you use it with a URB request, the request will fail and the system will report an error.

#### URB_FUNCTION_GET_CURRENT_FRAME_NUMBER

Requests the current frame number from the host controller driver. If set, the URB is used with [_URB_GET_CURRENT_FRAME_NUMBER](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_get_current_frame_number) as the data structure.

#### URB_FUNCTION_CONTROL_TRANSFER

Transfers data to or from a control pipe. If set, the URB is used with [_URB_CONTROL_TRANSFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_control_transfer) as the data structure.

#### URB_FUNCTION_CONTROL_TRANSFER_EX

Transfers data to or from a control pipe without a time limit specified by a timeout value. If set, the URB is used with [URB_CONTROL_TRANSFER_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_control_transfer_ex) as the data structure.

Available in Windows Vista and later operating systems.

#### URB_FUNCTION_BULK_OR_INTERRUPT_TRANSFER

Transfers data from a bulk pipe or interrupt pipe or to a bulk pipe. If set, the URB is used with [_URB_BULK_OR_INTERRUPT_TRANSFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_bulk_or_interrupt_transfer) as the data structure.

#### URB_FUNCTION_BULK_OR_INTERRUPT_TRANSFER_USING_CHAINED_MDL

Transfers data to and from a bulk pipe or interrupt pipe, by using chained MDLs. If set, the URB is used with [_URB_BULK_OR_INTERRUPT_TRANSFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_bulk_or_interrupt_transfer) as the data structure. The client driver must set the **TransferBufferMDL** member to the first [MDL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_mdl) structure in the chain that contains the transfer buffer. The USB driver stack ignores the **TransferBuffer** member when processing this URB.

Available in Windows 8. For information about using chained MDLs see [How to Send Chained MDLs](https://learn.microsoft.com/windows-hardware/drivers/usbcon/how-to-send-chained-mdls)">How to Send Chained MDLs.

#### URB_FUNCTION_ISOCH_TRANSFER

Transfers data to or from an isochronous pipe. If set, the URB is used with [_URB_ISOCH_TRANSFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_isoch_transfer) as the data structure.

#### URB_FUNCTION_ISOCH_TRANSFER_USING_CHAINED_MDL

Transfers data to or from an isochronous pipe by using chained MDLs. If set, the URB is used with [_URB_ISOCH_TRANSFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_isoch_transfer) as the data structure. The client driver must set the **TransferBufferMDL** member to the first [MDL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_mdl) in the chain that contains the transfer buffer. The USB driver stack ignores the **TransferBuffer** member when processing this URB.

Available in Windows 8. For information about using chained MDLs see [How to Send Chained MDLs](https://learn.microsoft.com/windows-hardware/drivers/usbcon/how-to-send-chained-mdls)">How to Send Chained MDLs.

#### URB_FUNCTION_RESET_PIPE

See URB_FUNCTION_SYNC_RESET_PIPE_AND_CLEAR_STALL.

#### URB_FUNCTION_SYNC_RESET_PIPE_AND_CLEAR_STALL

Resets the indicated pipe. If set, this URB is used with [_URB_PIPE_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_pipe_request).

> [!NOTE]
> This URB replaces URB_FUNCTION_RESET_PIPE.

The bus driver accomplishes three tasks in response to this URB:

First, for all pipes except isochronous pipes, this URB sends a CLEAR_FEATURE request to clear the device's ENDPOINT_HALT feature.

Second, the USB bus driver resets the data toggle on the host side, as required by the USB specification. The USB device should reset the data toggle on the device side when the bus driver clears its ENDPOINT_HALT feature. Since some non-compliant devices do not support this feature, Microsoft provides the two additional URBs: URB_FUNCTION_SYNC_CLEAR_STALL and URB_FUNCTION_SYNC_RESET_PIPE. These allow client drivers to clear the ENDPOINT_HALT feature on the device, or reset the pipe on the host side, respectively, without affecting the data toggle on the host side. If the device does not reset the data toggle when it should, then the client driver can compensate for this defect by not resetting the host-side data toggle. If the data toggle is reset on the host side but not on the device side, packets will get out of sequence, and the device might drop packets.

Third, after the bus driver has successfully reset the pipe, it resumes transfers with the next queued URB.

After a pipe reset, transfers resume with the next queued URB.

It is not necessary to clear a halt condition on a default control pipe. The default control pipe must always accept setup packets, and so if it halts, the USB stack will clear the halt condition automatically. The client driver does not need to take any special action to clear the halt condition on a default pipe.

All transfers must be aborted or canceled before attempting to reset the pipe.

This URB must be sent at PASSIVE_LEVEL.

#### URB_FUNCTION_SYNC_RESET_PIPE

Clears the halt condition on the host side of a pipe. If set, this URB is used with [_URB_PIPE_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_pipe_request) as the data structure.

This URB allows a client to clear the halted state of a pipe without resetting the data toggle and without clearing the endpoint stall condition (feature ENDPOINT_HALT). To clear a halt condition on the pipe, reset the host-side data toggle and clear a stall on the device with a single operation, use URB_FUNCTION_SYNC_RESET_PIPE_AND_CLEAR_STALL.

The following status codes are important and have the indicated meaning:

USBD_STATUS_INVALID_PIPE_HANDLE

The **PipeHandle** is not valid

USBD_STATUS_ERROR_BUSY

The endpoint has active transfers pending.

It is not necessary to clear a halt condition on a default control pipe. The default control pipe must always accept setup packets, and so if it halts, the USB stack will clear the halt condition automatically. The client driver does not need to take any special action to clear the halt condition on a default pipe.

All transfers must be aborted or canceled before attempting to reset the pipe.

This URB must be sent at PASSIVE_LEVEL.

Available in Windows XP and later operating systems.

#### URB_FUNCTION_SYNC_CLEAR_STALL

Clears the stall condition on the endpoint. For all pipes except isochronous pipes, this URB sends a CLEAR_FEATURE request to clear the device's ENDPOINT_HALT feature. However, unlike the RB_FUNCTION_SYNC_RESET_PIPE_AND_CLEAR_STALL function, this URB function does not reset the data toggle on the host side of the pipe. The USB specification requires devices to reset the device-side data toggle after the client clears the device's ENDPOINT_HALT feature, but some non-compliant devices do not reset their data toggle properly. Client drivers that manage such devices can compensate for this defect by clearing the stall condition directly with URB_FUNCTION_SYNC_CLEAR_STALL instead of resetting the pipe with URB_FUNCTION_SYNC_RESET_PIPE_AND_CLEAR_STALL. URB_FUNCTION_SYNC_CLEAR_STALL clears a stall condition on the device without resetting the host-side data toggle. This prevents a non-compliant device from interpreting the next packet as a retransmission and dropping the packet.

If set, the URB is used with [_URB_PIPE_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_pipe_request) as the data structure.

This URB function should be sent at PASSIVE_LEVEL

Available in Windows XP and later operating systems.

#### URB_FUNCTION_GET_DESCRIPTOR_FROM_DEVICE

Retrieves the device descriptor from a specific USB device. If set, the URB is used with [_URB_CONTROL_DESCRIPTOR_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_control_descriptor_request) as the data structure.

#### URB_FUNCTION_GET_DESCRIPTOR_FROM_ENDPOINT

Retrieves the descriptor from an endpoint on an interface for a USB device. If set, the URB is used with [_URB_CONTROL_DESCRIPTOR_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_control_descriptor_request) as the data structure.

#### URB_FUNCTION_SET_DESCRIPTOR_TO_DEVICE

Sets a device descriptor on a device. If set, the URB is used with [_URB_CONTROL_DESCRIPTOR_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_control_descriptor_request) as the data structure.

#### URB_FUNCTION_SET_DESCRIPTOR_TO_ENDPOINT

Sets an endpoint descriptor on an endpoint for an interface. If set, the URB is used with [_URB_CONTROL_DESCRIPTOR_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_control_descriptor_request) as the data structure.

#### URB_FUNCTION_SET_FEATURE_TO_DEVICE

Sets a USB-defined feature on a device. If set, the URB is used with [_URB_CONTROL_FEATURE_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_control_feature_request) as the data structure.

#### URB_FUNCTION_SET_FEATURE_TO_INTERFACE

Sets a USB-defined feature on an interface for a device. If set, the URB is used with [_URB_CONTROL_FEATURE_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_control_feature_request) as the data structure.

#### URB_FUNCTION_SET_FEATURE_TO_ENDPOINT

Sets a USB-defined feature on an endpoint for an interface on a USB device. If set, the URB is used with [_URB_CONTROL_FEATURE_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_control_feature_request) as the data structure.

#### URB_FUNCTION_SET_FEATURE_TO_OTHER

Sets a USB-defined feature on a device-defined target on a USB device. If set, the URB is used with [_URB_CONTROL_FEATURE_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_control_feature_request) as the data structure.

#### URB_FUNCTION_CLEAR_FEATURE_TO_DEVICE

Clears a USB-defined feature on a device. If set, the URB is used with [_URB_CONTROL_FEATURE_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_control_feature_request) as the data structure.

#### URB_FUNCTION_CLEAR_FEATURE_TO_INTERFACE

Clears a USB-defined feature on an interface for a device. If set, the URB is used with [_URB_CONTROL_FEATURE_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_control_feature_request) as the data structure.

#### URB_FUNCTION_CLEAR_FEATURE_TO_ENDPOINT

Clears a USB-defined feature on an endpoint, for an interface, on a USB device. If set, the URB is used with [_URB_CONTROL_FEATURE_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_control_feature_request) as the data structure.

#### URB_FUNCTION_CLEAR_FEATURE_TO_OTHER

Clears a USB-defined feature on a device defined target on a USB device. If set, the URB is used with [_URB_CONTROL_FEATURE_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_control_feature_request) as the data structure.

#### URB_FUNCTION_GET_STATUS_FROM_DEVICE

Retrieves status from a USB device. If set, the URB is used with [_URB_CONTROL_GET_STATUS_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_control_get_status_request) as the data structure.

#### URB_FUNCTION_GET_STATUS_FROM_INTERFACE

Retrieves status from an interface on a USB device. If set, the URB is used with [_URB_CONTROL_GET_STATUS_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_control_get_status_request) as the data structure.

#### URB_FUNCTION_GET_STATUS_FROM_ENDPOINT

Retrieves status from an endpoint for an interface on a USB device. If set, the URB is used with [_URB_CONTROL_GET_STATUS_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_control_get_status_request) as the data structure.

#### URB_FUNCTION_GET_STATUS_FROM_OTHER

Retrieves status from a device-defined target on a USB device. If set, the URB is used with [_URB_CONTROL_GET_STATUS_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_control_get_status_request) as the data structure.

#### URB_FUNCTION_VENDOR_DEVICE

Sends a vendor-specific command to a USB device. If set, the URB is used with [_URB_CONTROL_VENDOR_OR_CLASS_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_control_vendor_or_class_request) as the data structure.

#### URB_FUNCTION_VENDOR_INTERFACE

Sends a vendor-specific command for an interface on a USB device. If set, the URB is used with [_URB_CONTROL_VENDOR_OR_CLASS_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_control_vendor_or_class_request) as the data structure.

#### URB_FUNCTION_VENDOR_ENDPOINT

Sends a vendor-specific command for an endpoint on an interface on a USB device. If set, the URB is used with [_URB_CONTROL_VENDOR_OR_CLASS_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_control_vendor_or_class_request) as the data structure.

#### URB_FUNCTION_VENDOR_OTHER

Sends a vendor-specific command to a device-defined target on a USB device. If set, the URB is used with [_URB_CONTROL_VENDOR_OR_CLASS_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_control_vendor_or_class_request) as the data structure.

#### URB_FUNCTION_CLASS_DEVICE

Sends a USB-defined class-specific command to a USB device. If set, the URB is used with [_URB_CONTROL_VENDOR_OR_CLASS_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_control_vendor_or_class_request) as the data structure.

#### URB_FUNCTION_CLASS_INTERFACE

Sends a USB-defined class-specific command to an interface on a USB device. If set, the URB is used with [_URB_CONTROL_VENDOR_OR_CLASS_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_control_vendor_or_class_request) as the data structure.

#### URB_FUNCTION_CLASS_ENDPOINT

Sends a USB-defined class-specific command to an endpoint, on an interface, on a USB device. If set, the URB is used with [_URB_CONTROL_VENDOR_OR_CLASS_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_control_vendor_or_class_request) as the data structure.

#### URB_FUNCTION_CLASS_OTHER

Sends a USB-defined class-specific command to a device defined target on a USB device. If set, the URB is used with [_URB_CONTROL_VENDOR_OR_CLASS_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_control_vendor_or_class_request) as the data structure.

#### URB_FUNCTION_GET_CONFIGURATION

Retrieves the current configuration on a USB device. If set, the URB is used with [_URB_CONTROL_GET_CONFIGURATION_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_control_get_configuration_request) as the data structure.

#### URB_FUNCTION_GET_INTERFACE

Retrieves the current settings for an interface on a USB device. If set, the URB is used with [_URB_CONTROL_GET_INTERFACE_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_control_get_interface_request) as the data structure.

Available in Windows 2000, and Windows Vista and later operating systems. Not available in Windows XP.

#### URB_FUNCTION_GET_DESCRIPTOR_FROM_INTERFACE

Retrieves the descriptor from an interface for a USB device. If set, the URB is used with [_URB_CONTROL_DESCRIPTOR_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_control_descriptor_request) as the data structure.

#### URB_FUNCTION_SET_DESCRIPTOR_TO_INTERFACE

Sets a descriptor for an interface on a USB device. If set, the URB is used with [_URB_CONTROL_DESCRIPTOR_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_control_descriptor_request) as the data structure.

#### URB_FUNCTION_GET_MS_FEATURE_DESCRIPTOR

Retrieves a Microsoft OS feature descriptor from a USB device or an interface on a USB device. If set, the URB is used with [_URB_OS_FEATURE_DESCRIPTOR_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_os_feature_descriptor_request) as the data structure.

Available in Windows XP and later operation systems.

#### URB_FUNCTION_OPEN_STATIC_STREAMS

Opens streams in the specified bulk endpoint. If set, the URB is used with [_URB_OPEN_STATIC_STREAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_open_static_streams) as the data structure.

Available in Windows 8. For information about formatting an URB for an open-stream request, see [How to Open and Close Static Streams in a USB Bulk Endpoint](https://learn.microsoft.com/windows-hardware/drivers/usbcon/how-to-open-streams-in-a-usb-endpoint).

#### URB_FUNCTION_CLOSE_STATIC_STREAMS

Closes all opened streams in the specified bulk endpoint. If set, the URB is used with [_URB_PIPE_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_pipe_request) as the data structure.

Available in Windows 8. For information about formatting an URB for an open-stream request, see [How to Open and Close Static Streams in a USB Bulk Endpoint](https://learn.microsoft.com/windows-hardware/drivers/usbcon/how-to-open-streams-in-a-usb-endpoint).

### `Status`

Contains a USBD_STATUS_*XXX* code on return from the host controller driver.

### `UsbdDeviceHandle`

Reserved. Do not use.

### `UsbdFlags`

Reserved. Do not use.

## Remarks

The **_URB_HEADER** structure is a member of all USB requests that are part of the URB structure. The **_URB_HEADER** structure is used to provide common information about each request to the host controller driver.

The reserved members of this structure must be treated as opaque and are reserved for system use.

## See also

[URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb)

[USB Structures](https://learn.microsoft.com/windows-hardware/drivers/ddi/)

[_URB_BULK_OR_INTERRUPT_TRANSFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_bulk_or_interrupt_transfer)

[_URB_CONTROL_DESCRIPTOR_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_control_descriptor_request)

[_URB_CONTROL_FEATURE_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_control_feature_request)

[_URB_CONTROL_GET_CONFIGURATION_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_control_get_configuration_request)

[_URB_CONTROL_GET_INTERFACE_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_control_get_interface_request)

[_URB_CONTROL_GET_STATUS_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_control_get_status_request)

[_URB_CONTROL_TRANSFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_control_transfer)

[_URB_CONTROL_VENDOR_OR_CLASS_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_control_vendor_or_class_request)

[_URB_GET_CURRENT_FRAME_NUMBER](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_get_current_frame_number)

[_URB_ISOCH_TRANSFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_isoch_transfer)

[_URB_OS_FEATURE_DESCRIPTOR_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_os_feature_descriptor_request)

[_URB_PIPE_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_pipe_request)

[_URB_SELECT_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_select_configuration)

[_URB_SELECT_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_select_interface)