# VideoPortReleaseDeviceLock function

## Description

The **VideoPortReleaseDeviceLock** function releases the device lock acquired in a prior call to [VideoPortAcquireDeviceLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportacquiredevicelock).

## Parameters

### `HwDeviceExtension` [in]

Pointer to the miniport driver's device extension.

## Return value

None

## Remarks

Typically, the video port driver guarantees threaded synchronization into the miniport driver by using of a device lock. However, a miniport driver must perform its own synchronization when being accessed by a child device; that is, a miniport driver must perform synchronization in routines that it exposes through [HwVidQueryInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_query_interface). The miniport driver does this by calling [VideoPortAcquireDeviceLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportacquiredevicelock) to acquire the device lock maintained by the video port driver.

The miniport driver should call **VideoPortReleaseDeviceLock** to release the device lock as quickly as possible.

## See also

[HwVidQueryInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_query_interface)

[VideoPortAcquireDeviceLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportacquiredevicelock)