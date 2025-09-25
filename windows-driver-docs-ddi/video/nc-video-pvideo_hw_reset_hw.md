# PVIDEO_HW_RESET_HW callback function

## Description

*HwVidResetHw* resets the adapter to character mode.

## Parameters

### `HwDeviceExtension`

Pointer to the miniport driver's per-adapter storage area. For more information, see [Device Extensions](https://learn.microsoft.com/windows-hardware/drivers/kernel/device-extensions).

### `Columns`

Specifies the number of columns of the mode to be set up.

### `Rows`

Specifies the number of rows of the mode to be set up.

## Return value

*HwVidResetHw* should return **TRUE** if it completely resets the adapter to the given character mode. Otherwise, it should return **FALSE** to indicate that the HAL should perform the equivalent of an INT10, MODE3-type BIOS call after *HwVidResetHw* returns control.

## Remarks

A video miniport driver must have a *HwVidResetHw* function if its adapter cannot be reset to a fully initialized state without a hard boot of the machine. For example, if the adapter's ROM initialization code cannot reset the adapter state to a boot-up mode, the miniport driver must have a *HwVidResetHw* function. Another reason the miniport driver must implement this function is to clean up the adapter's interrupt lines when the adapter is powered down, thereby avoiding a deluge of interrupts the next time the system boots.

The HAL calls *HwVidResetHw* if the system is about to crash, so that the HAL can display information on the screen while the system is being shut down. This call can occur at any IRQL, and the driver must be ready to handle it at any time. The HAL also calls *HwVidResetHw* just before the machine is rebooted when a soft boot occurs.

Most miniport drivers must provide this function, except for drivers of adapters that are reset to a VGA standard character mode on receipt of an INT10, MODE3-type command.

*HwVidResetHw* resets the adapter to character mode, according to the given *Columns* and *Rows* values. However, because the system is shutting down, *HwVidResetHw* cannot call the BIOS or any pageable code. *HwVidResetHw* should call only the **VideoPortRead/WritePort***Xxx* and/or **VideoPortRead/WriteRegister***Xxx* functions. (See [Functions Exported by the Video Port Driver](https://learn.microsoft.com/windows-hardware/drivers/ddi/).)

If *HwVidResetHw* cannot change the mode of the adapter by simply programming the adapter registers, it can set up the appropriate values in adapter registers and return **FALSE**. This causes the HAL to perform an extended INT10-type operation to reset the video adapter to character mode.

*HwVidResetHw* must not call [VideoPortInt10](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportint10). A miniport driver's [HwVidStartIO](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_start_io) function is called with the [IOCTL_VIDEO_RESET_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ni-ntddvdeo-ioctl_video_reset_device)[VRP](https://learn.microsoft.com/windows-hardware/drivers/) to reset the adapter whenever the Display program is used to test or change the graphics display mode, *not* the miniport driver's *HwVidResetHw* function.

*HwVidResetHw* must not be made pageable.

## See also

[Functions Exported by the Video Port Driver](https://learn.microsoft.com/windows-hardware/drivers/ddi/)

[HwVidInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_initialize)

[HwVidStartIO](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_start_io)

[IOCTL_VIDEO_RESET_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ni-ntddvdeo-ioctl_video_reset_device)

[VideoPortInt10](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportint10)