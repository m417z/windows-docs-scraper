# VideoPortInt10 function

## Description

The **VideoPortInt10** function performs the equivalent of an MS-DOS INT10 operation, such as setting the video mode. **VideoPortInt10** runs the BIOS ROM code on the device.

## Parameters

### `HwDeviceExtension`

Pointer to the miniport driver's device extension.

### `BiosArguments`

Pointer to a structure containing values for the x86 registers that should be set before making the BIOS call. The miniport driver should set any unused registers to zero. All values set up in the [VIDEO_x86_BIOS_ARGUMENTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_x86_bios_arguments) structure are interpreted as immediate values.

## Return value

**VideoPortInt10** returns NO_ERROR if it successfully called the given BIOS INT10 routine; otherwise, it returns an error status.

## Remarks

Generally, VGA-compatible miniport drivers, which support full-screen MS-DOS applications on x86-based machines, call **VideoPortInt10**. Such a driver's [HwVidFindAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_find_adapter) function must have set up the **VdmPhysicalVideoMemoryAddress** and **VdmPhysicalVideoMemoryLength** for the range in the [VIDEO_PORT_CONFIG_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_port_config_info) structure.

However, other video miniport drivers also can call this function.

Because **VideoPortInt10** interprets the *BiosArgument* parameter values as immediate values, the caller cannot pass in or retrieve data from a memory buffer with this function.

## See also

[HwVidFindAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_find_adapter)

[VIDEO_PORT_CONFIG_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_port_config_info)

[VIDEO_x86_BIOS_ARGUMENTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_x86_bios_arguments)

[VideoPortGetDeviceBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetdevicebase)