# PVIDEO_HW_POWER_SET callback function

## Description

*HwVidSetPowerState* sets the power state of the specified device.

## Parameters

### `HwDeviceExtension`

Pointer to the miniport driver's per-adapter storage area. For more information, see [Device Extensions](https://learn.microsoft.com/windows-hardware/drivers/kernel/device-extensions).

### `HwId`

Pointer to a 32-bit [device ID](https://learn.microsoft.com/windows-hardware/drivers/) that uniquely identifies the device for which the miniport driver should set the power state. This parameter is the value returned by the miniport driver's [HwVidGetVideoChildDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_get_child_descriptor) function. A value of DISPLAY_ADAPTER_HW_ID indicates that the miniport driver should set the power state of the adapter itself.

### `VideoPowerControl`

Pointer to a [VIDEO_POWER_MANAGEMENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ns-ntddvdeo-_video_power_management) structure that specifies the power state to be set.

## Return value

*HwVidSetPowerState* should always return NO_ERROR.

## Remarks

*HwVidSetPowerState* is a required function in a video miniport driver.

The driver should check the ID specified in *HwId* to determine the device on which to set the power state. The driver should then set that device's power state to the level specified in the **PowerState** member of the VIDEO_POWER_MANAGEMENT structure to which *VideoPowerControl* points.

*HwVidSetPowerState* should be made pageable.

## See also

[HwVidGetPowerState](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_power_get)

[HwVidGetVideoChildDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_get_child_descriptor)

[VIDEO_POWER_MANAGEMENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ns-ntddvdeo-_video_power_management)