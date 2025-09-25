# EVT_UDECX_WDF_DEVICE_QUERY_USB_CAPABILITY callback function

## Description

The UDE client driver's implementation to determine the capabilities that are supported by the emulated USB host controller.

## Parameters

### `UdecxWdfDevice` [in]

A handle to a framework device object that represents the controller. The client driver initialized this object in the previous call to [UdecxWdfDeviceAddUsbDeviceEmulation](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxwdfdevice/nf-udecxwdfdevice-udecxwdfdeviceaddusbdeviceemulation).

### `CapabilityType` [in]

Pointer to a GUID specifying the requested capability. The possible *PGUID* values are as follows:

* GUID_USB_CAPABILITY_CHAINED_MDLS
* GUID_USB_CAPABILITY_SELECTIVE_SUSPEND
* GUID_USB_CAPABILITY_FUNCTION_SUSPEND
* GUID_USB_CAPABILITY_DEVICE_CONNECTION_HIGH_SPEED_COMPATIBLE
* GUID_USB_CAPABILITY_DEVICE_CONNECTION_SUPER_SPEED_COMPATIBLE

For information about the capabilities, see the Remarks section of [USBD_QueryUsbCapability](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/hh406230(v=vs.85)).

### `OutputBufferLength` [in]

The length, in bytes, of the request's output buffer, if an output buffer is available.

### `OutputBuffer` [out, optional]

A pointer to a location that receives the buffer's address. Certain capabilities may need to provide additional information
to the USB device emulation class extension (UdeCx) in this buffer.

### `ResultLength` [out]

A location that, on return, contains the size, in bytes, of the information that the callback function stored in *OutputBuffer.*

## Return value

If the operation is successful, the callback function must return STATUS_SUCCESS, or another status value for which NT_SUCCESS(status) equals TRUE. If a capability is not supported, the client driver can return NT_SUCCESS(status) equals FALSE, such as STATUS_UNSUCCESSFUL.

## Remarks

The class extension invokes this callback function implemented by the client driver when the class extension receives a request to determine the emulated controller's capabilities. The callback is invoked only after [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) has returned, typically in [EvtDevicePrepareHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_prepare_hardware). This callback cannot be invoked after [EvtDeviceReleaseHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_release_hardware) has returned.

The class extension reports these capability GUIDs, as not supported:

* GUID_USB_CAPABILITY_STATIC_STREAMS
* GUID_USB_CAPABILITY_CLEAR_TT_BUFFER_ON_ASYNC_TRANSFER_CANCEL

The class extension reports the GUID_USB_CAPABILITY_SELECTIVE_SUSPEND capability GUID as supported without even invoking the callback function.

For other GUIDs, the class extension invokes the client driver's implementation, such as GUID_USB_CAPABILITY_CHAINED_MDLS. The client driver is expected to determine support for I/O requests that use a chained MDL. If this capability is supported then, the **TransferBufferMdl** member of the [URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb) contains the request buffer. If chained MDL is not supported, the client driver does not receive **TransferBufferMdl** values that point to chained MDLs.

## See also

[Architecture: USB Device Emulation (UDE)](https://learn.microsoft.com/windows-hardware/drivers/usbcon/)

[Write a UDE client driver](https://learn.microsoft.com/windows-hardware/drivers/usbcon/)