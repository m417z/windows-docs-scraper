# IOCTL_VIDEO_GET_POWER_MANAGEMENT IOCTL

## Description

This IOCTL is **obsolete** in Windows 2000 and later, and is no longer supported. A Plug and Play video miniport driver should implement the [HwVidGetPowerState](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_power_get) function, which provides similar functionality.

Returns the current power-consumption level of the adapter. Support for this nonmodal IOCTL is required for adapters that conform to the VESA DPMS standard.

## Parameters

### Major code

### Input buffer

None

### Input buffer length

### Output buffer

The miniport driver returns a [VIDEO_POWER_MANAGEMENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ns-ntddvdeo-_video_power_management) structure in the VRP **OutputBuffer**.

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

If the miniport driver successfully returns the power-consumption information, it sets the **Information** member of the [STATUS_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_status_block) structure to **sizeof**(VIDEO_POWER_MANAGEMENT); otherwise, the miniport driver sets this member to zero.

## See also

[STATUS_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_status_block)

[VIDEO_POWER_MANAGEMENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ns-ntddvdeo-_video_power_management)