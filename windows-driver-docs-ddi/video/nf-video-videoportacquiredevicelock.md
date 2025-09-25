# VideoPortAcquireDeviceLock function

## Description

The **VideoPortAcquireDeviceLock** function acquires the device lock maintained by the video port driver.

## Parameters

### `HwDeviceExtension` [in]

Pointer to the miniport driver's device extension.

## Return value

None

## Remarks

Typically, the video port driver guarantees threaded synchronization into the miniport driver through the use of a device lock. However, a miniport driver must perform its own synchronization when being accessed by a child device. That is, a miniport driver must perform synchronization in routines that it exposes through [HwVidQueryInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_query_interface) by acquiring the device lock maintained by the video port driver.

The miniport driver should release the device lock as quickly as possible by calling [VideoPortReleaseDeviceLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportreleasedevicelock).

## See also

[HwVidQueryInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_query_interface)

[VideoPortReleaseDeviceLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportreleasedevicelock)