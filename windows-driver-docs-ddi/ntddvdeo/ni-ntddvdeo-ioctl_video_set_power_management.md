# IOCTL_VIDEO_SET_POWER_MANAGEMENT IOCTL

## Description

This IOCTL is **obsolete** in Windows 2000 and later, and is no longer supported. A Plug and Play video miniport driver should implement the [HwVidSetPowerState](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_power_set) function, which provides similar functionality.

Resets the power-consumption level of the adapter to the specified state. As long as the state is **VideoPowerOff**, the port driver intercepts and fails all IOCTL_VIDEO_*XXX* requests to the miniport driver until the next IOCTL_VIDEO_SET_POWER_MANAGEMENT request that resets the state to a power-on condition.

## Parameters

### Major code

### Input buffer

The VRP **InputBuffer** contains the [VIDEO_POWER_MANAGEMENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ns-ntddvdeo-_video_power_management) structure, specifying the state to be set.

### Input buffer length

### Output buffer

None

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

The miniport driver does not set the **Information** member of the [STATUS_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_status_block) structure.

## See also

[STATUS_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_status_block)

[VIDEO_POWER_MANAGEMENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ns-ntddvdeo-_video_power_management)