# WinUsb_WriteIsochPipeAsap function

## Description

The **WinUsb_WriteIsochPipeAsap** submits a request for writing the contents of a buffer to an isochronous OUT endpoint.

## Parameters

### `BufferHandle` [in]

An opaque handle to the transfer buffer that was registered by a previous call to [WinUsb_RegisterIsochBuffer](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_registerisochbuffer).

### `Offset` [in]

Offset into the buffer relative to the start the transfer.

### `Length` [in]

Length in bytes of the transfer buffer.

### `ContinueStream` [in]

Indicates that the transfer should only be submitted if it can be scheduled in the first frame after the last pending transfer.

### `Overlapped` [in, optional]

Pointer to an [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/shobjidl/ns-shobjidl-overlapped) structure used for asynchronous operations.

## Return value

**WinUsb_WriteIsochPipeAsap** returns TRUE if the operation succeeds. Otherwise this function returns FALSE, and the caller can retrieve the logged error by calling **GetLastError**.

If the caller sets *ContinueStream* to TRUE, The transfer fails if Winusb.sys is unable to schedule the transfer to continue the stream without dropping one or more frames.

## Remarks

**WinUsb_WriteIsochPipeAsap** allows the USB driver stack to choose the starting frame number for the transfer. If one or more transfers are already pending on the endpoint, the transfer will be scheduled for the frame number immediately following the last frame number of the last currently pending transfer.

**WinUsb_WriteIsochPipeAsap** packetizes the transfer buffer so that in each 1ms interval, the host can send the maximum bytes allowed per interval. The maximum bytes is as specified by the endpoint descriptor for full and high-speed endpoints, and endpoint companion descriptor for SuperSpeed endpoints.
If the caller submits multiple write requests to stream data to the device, the transfer size should be a multiple of the maximum bytes per interval (as returned by [WinUsb_QueryPipeEx](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_querypipeex)) * 8 / interval.

Because of the transfer packaging used in the underlying kernel-mode interface, the lowest latency notification to an application or driver is 1ms intervals.

## See also

[Send USB isochronous transfers from a WinUSB desktop app](https://learn.microsoft.com/windows-hardware/drivers/usbcon/)

[WinUSB Functions](https://learn.microsoft.com/windows/iot-core/learn-about-hardware/hardwarecompatlist)