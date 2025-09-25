# IOCTL_VIDEO_SET_CURRENT_MODE IOCTL

## Description

Sets the adapter to the specified operating mode. Miniport drivers are required to support this nonmodal request because it resets the current mode. The miniport driver must also consider the two high order flags which are used to additionally control the mode set operation. See [VIDEO_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ns-ntddvdeo-_video_mode) for further information.

## Parameters

### Major code

### Input buffer

The VRP **InputBuffer** contains a [VIDEO_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ns-ntddvdeo-_video_mode) structure specifying the mode to be set.

### Input buffer length

### Output buffer

None

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

The miniport driver does not set the **Information** member of the [STATUS_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_status_block) structure.

## See also

[VIDEO_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ns-ntddvdeo-_video_mode)