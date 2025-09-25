# PVIDEO_HW_TIMER callback function

## Description

*HwVidTimer* is a video miniport driver routine called at timed intervals by the video port driver.

## Parameters

### `HwDeviceExtension`

Pointer to the miniport driver's per-adapter storage area. For more information, see [Device Extensions](https://learn.microsoft.com/windows-hardware/drivers/kernel/device-extensions).

## Remarks

*HwVidTimer* is an optional miniport driver function to which calls are enabled with [VideoPortStartTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportstarttimer) and disabled with [VideoPortStopTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportstoptimer).

Any miniport driver can have a *HwVidTimer* function. For example, a *HwVidTimer* function could be used to read the state of the "VGA" registers on a high-end video adapter so that the miniport driver can emulate VGA-compatible behavior.

After a call to **VideoPortStartTimer**, the video port driver calls a miniport driver's *HwVidTimer* function at approximately one-second intervals until the miniport driver calls **VideoPortStopTimer**.

Note that the *HwVidTimer* function *must not* disable the timer with a call to **VideoPortStopTimer**.

*HwVidTimer* must not be made pageable.

## See also

[VideoPortStartTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportstarttimer)

[VideoPortStopTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportstoptimer)