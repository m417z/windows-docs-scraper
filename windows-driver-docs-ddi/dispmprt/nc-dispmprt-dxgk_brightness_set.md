# DXGK_BRIGHTNESS_SET callback function

## Description

The *DxgkDdiSetBrightness* function sets a new brightness level.

## Parameters

### `Context` [in]

A handle to a context block that is associated with a display adapter. The display miniport driver's [DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function previously provided this handle to the Microsoft DirectX graphics kernel subsystem.

### `Brightness` [in]

The brightness level value to set.

## Return value

*DxgkDdiSetBrightness* returns STATUS_SUCCESS if it succeeds in setting a new brightness level. Otherwise, it returns one of the error codes defined in *Ntstatus.h*.

## Remarks

The [monitor driver](https://learn.microsoft.com/windows-hardware/drivers/display/monitor-drivers) calls the display miniport driver's *DxgkDdiSetBrightness* function to change the brightness level of the integrated display panel for the following reasons:

* Notifications from the Device Power Policy Engine (DPPE) indicate that either the current policy is modified or a new policy takes effect. A new DPPE policy takes effect on system start, resume, and user switch, as well as when the power source is changed.
* The preferred way for user-mode clients to control brightness is through Windows Management Instrumentation (WMI). The monitor driver implements the WMI brightness controls that select a brightness level or revert the brightness level to the level that was selected by the currently active DPPE policy. The WMI method to select a brightness level overrides the current DPPE policy level until any change in DPPE policy occurs. When DPPE policy changes, the new DPPE level is set.
* For compatibility with the [Windows 2000 Display Driver Model](https://learn.microsoft.com/windows-hardware/drivers/display/windows-2000-display-driver-model-design-guide), the monitor driver implements [IOCTL_VIDEO_SET_DISPLAY_BRIGHTNESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ni-ntddvdeo-ioctl_video_set_display_brightness) as an alternative way for user-mode clients to control brightness. A call to IOCTL_VIDEO_SET_DISPLAY_BRIGHTNESS is handled the same way as the WMI brightness control that selects a brightness level.
* The monitor driver interprets brightness hot-key notifications from the Advanced Configuration and Power Interface (ACPI) driver as user requests to change the current brightness level. As with the WMI and IOCTL user-mode interfaces, a change in brightness level that is triggered by a hot-key notification overrides the current DPPE policy and stays in effect until DPPE policy requests that the brightness value is set again.

*DxgkDdiSetBrightness* should be made pageable.

## See also

[DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device)

[IOCTL_VIDEO_SET_DISPLAY_BRIGHTNESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ni-ntddvdeo-ioctl_video_set_display_brightness)