# VideoPortStartTimer function

## Description

The **VideoPortStartTimer** function enables calls to a miniport driver's [HwVidTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_timer) function.

## Parameters

### `HwDeviceExtension`

Pointer to the miniport driver's device extension. This pointer is the input parameter to the *HwVidTimer* function.

## Return value

None

## Remarks

After a miniport driver calls **VideoPortStartTimer**, its *HwVidTimer* function is called at approximately one-second intervals until the miniport driver calls [VideoPortStopTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportstoptimer). A miniport driver's *HwVidTimer* function *must not* call **VideoPortStopTimer**.

A miniport driver cannot call **VideoPortStartTimer** or **VideoPortStopTimer** if its [DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) function set the **HwTimer** member of the [VIDEO_HW_INITIALIZATION_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_hw_initialization_data) structure to **NULL**.

## See also

[DriverEntry of Video Miniport Driver](https://learn.microsoft.com/windows-hardware/drivers/display/driverentry-of-video-miniport-driver)

[HwVidTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_timer)

[VIDEO_HW_INITIALIZATION_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_hw_initialization_data)

[VideoPortStopTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportstoptimer)