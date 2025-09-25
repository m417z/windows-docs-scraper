# PVIDEO_HW_START_IO callback function

## Description

*HwVidStartIO* processes the specified [VRP](https://learn.microsoft.com/windows-hardware/drivers/).

## Parameters

### `HwDeviceExtension`

Pointer to the miniport driver's per-adapter storage area. For more information, see [Device Extensions](https://learn.microsoft.com/windows-hardware/drivers/kernel/device-extensions).

### `RequestPacket`

Pointer to a [VIDEO_REQUEST_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_request_packet) structure, which contains all the parameters originally passed to [EngDeviceIoControl](https://learn.microsoft.com/windows/win32/api/winddi/nf-winddi-engdeviceiocontrol).

## Return value

*HwVidStartIO* must return **TRUE**, indicating that it has completed the request.

## Remarks

Every video miniport driver must have a *HwVidStartIO* function.

The video port driver calls *HwVidStartIO* in response to each GDI [EngDeviceIoControl](https://learn.microsoft.com/windows/win32/api/winddi/nf-winddi-engdeviceiocontrol) request, which originates in the corresponding display driver. When *HwVidStartIO* is called, the miniport driver owns the input video request packet until it completes the requested operation. *HwVidStartIO* must do the following:

1. Look at the **IoControlCode** member of the [VRP](https://learn.microsoft.com/windows-hardware/drivers/) to determine the operation being requested by the display driver.
2. Check that the VRP **InputBufferLength** and/or **OutputBufferLength** indicates a buffer that is large enough to satisfy the request. The miniport driver should return an error if either buffer is too small.
3. Satisfy the request.
4. Set the **Status** and **Information** members in the [VRP](https://learn.microsoft.com/windows-hardware/drivers/) and return **TRUE**.

The system video port driver serializes all requests. A miniport driver need not perform any serialization of its own unless it has a [HwVidInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_interrupt) function.

However, every miniport driver's *HwVidStartIO* function must complete each requested operation or set an appropriate error in the VRP's **StatusBlock** before it returns control.

*HwVidStartIO* should be made pageable.

## See also

[VIDEO_REQUEST_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_request_packet)

[Video Miniport Driver I/O Control Codes](https://learn.microsoft.com/windows-hardware/drivers/ddi/)

[VideoPortSynchronizeExecution](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportsynchronizeexecution)