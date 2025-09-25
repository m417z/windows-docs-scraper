# PVIDEO_HW_POWER_GET callback function

## Description

*HwVidGetPowerState* queries whether the device can support the requested power state.

## Parameters

### `HwDeviceExtension`

Pointer to the miniport driver's per-adapter storage area. For more information, see [Device Extensions](https://learn.microsoft.com/windows-hardware/drivers/kernel/device-extensions).

### `HwId`

Pointer to a 32-bit [device ID](https://learn.microsoft.com/windows-hardware/drivers/) that uniquely identifies the device that the miniport driver should query. This parameter is returned by the miniport driver's [HwVidGetVideoChildDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_get_child_descriptor) function. Alternatively, a value of DISPLAY_ADAPTER_HW_ID indicates that power information is being requested of the adapter itself.

### `VideoPowerControl`

Pointer to a [VIDEO_POWER_MANAGEMENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ns-ntddvdeo-_video_power_management) structure that specifies the power state for which support is being queried.

## Return value

*HwVidGetPowerState* returns one of the following values:

|Return code|Description|
|--- |--- |
|NO_ERROR|The device supports the requested power state.|
|ERROR_DEVICE_REINITIALIZATION_NEEDED|The driver failed the power state query.|

## Remarks

*HwVidGetPowerState* is a required function in a video miniport driver.

The driver should check the ID specified in *HwId* to determine which device to query. The driver should then determine whether that device supports the power state specified in the **PowerState** member of the [VIDEO_POWER_MANAGEMENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ns-ntddvdeo-_video_power_management) structure to which *VideoPowerControl* points.

This function must not return the current power state of the device.

*HwVidGetPowerState* should be made pageable.

## See also

[HwVidGetVideoChildDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_get_child_descriptor)

[HwVidSetPowerState](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_power_set)

[VIDEO_POWER_MANAGEMENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ns-ntddvdeo-_video_power_management)