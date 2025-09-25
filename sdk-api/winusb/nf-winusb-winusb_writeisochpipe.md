# WinUsb_WriteIsochPipe function

## Description

The **WinUsb_WriteIsochPipe** function writes the contents of a caller-supplied buffer to an isochronous OUT endpoint, starting on a specified frame number.

## Parameters

### `BufferHandle` [in]

An opaque handle to the transfer buffer that was registered by a previous call to [WinUsb_RegisterIsochBuffer](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_registerisochbuffer).

### `Offset` [in]

Offset into the buffer relative to the start the transfer.

### `Length` [in]

Length in bytes of the transfer buffer.

### `FrameNumber` [in, out]

On input, indicates the starting frame number for the transfer. On output, contains the frame number of the frame that follows the last frame used in the transfer.

### `Overlapped` [in, optional]

Pointer to an [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/shobjidl/ns-shobjidl-overlapped) structure used for asynchronous operations.

## Return value

**WinUsb_WriteIsochPipe** returns TRUE if the operation succeeds. Otherwise this function returns FALSE, and the caller can retrieve the logged error by calling **GetLastError**.

## Remarks

**WinUsb_WriteIsochPipe** packetizes the transfer buffer so that in each 1ms interval, the host can send the maximum bytes allowed per interval. The maximum bytes is as specified by the endpoint descriptor for full and high-speed endpoints, and endpoint companion descriptor for SuperSpeed endpoints.
If the caller submits multiple write requests to stream data to the device, the transfer size should be a multiple of the maximum bytes per interval (as returned by [WinUsb_QueryPipeEx](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_querypipeex)) * 8 / interval.

Because of the transfer packaging used in the underlying kernel-mode interface, the lowest latency notification to an application or driver is 1ms intervals.

## See also

[Send USB isochronous transfers from a WinUSB desktop app](https://learn.microsoft.com/windows-hardware/drivers/usbcon/)

[WinUSB Functions](https://learn.microsoft.com/windows/iot-core/learn-about-hardware/hardwarecompatlist)