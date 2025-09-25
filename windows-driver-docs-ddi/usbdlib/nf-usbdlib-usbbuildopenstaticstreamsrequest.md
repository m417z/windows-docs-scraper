# UsbBuildOpenStaticStreamsRequest function

## Description

The **UsbBuildOpenStaticStreamsRequest** inline function formats an [URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb) structure for an open-streams request. The request opens streams associated with the specified bulk endpoint.

## Parameters

### `Urb` [in, out]

Pointer to the [URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb) structure to be formatted for the open-stream request (URB_FUNCTION_OPEN_STATIC_STREAMS). The caller must allocate nonpaged pool for this **URB**.

### `PipeHandle` [in]

An opaque handle for the pipe associated with the endpoint that contains the streams to open.

The client driver obtains **PipeHandle** from a previous select-configuration request (URB_FUNCTION_SELECT_CONFIGURATION) or a select-interface request (URB_FUNCTION_SELECT_INTERFACE).

### `NumberOfStreams` [in]

The number of streams to open. The **NumberOfStreams** value indicates the number of elements in the array pointed to by **Streams**. This value must be greater than zero and less than or equal to the maximum number of streams supported by the host controller hardware. To get the maximum number of supported streams, call [USBD_QueryUsbCapability](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/hh406230(v=vs.85)).

The number streams must also be less than or equal to the maximum number of streams supported by the USB device. To get that number, inspect the endpoint companion descriptor.

In the **NumberOfStreams** value, specify lesser of two values supported by the host controller and the USB device.

### `StreamInfoArray` [in]

Pointer to a caller-allocated, initialized array of [USBD_STREAM_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_usbd_stream_information) structures. The length of the array depends on the number of streams to open and must be the same as the **NumberOfStreams** value.

## Remarks

For a code example that shows the URB format required for an open-streams request, see [How to Open and Close Static Streams in a USB Bulk Endpoint](https://learn.microsoft.com/windows-hardware/drivers/ddi/).

## See also

[How to Open and Close Static Streams in a USB Bulk Endpoint](https://learn.microsoft.com/windows-hardware/drivers/ddi/)

[_URB_OPEN_STATIC_STREAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_open_static_streams)