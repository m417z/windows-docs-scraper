# IOCTL_VIDEO_QUERY_CURRENT_MODE IOCTL

## Description

Returns information about the current adapter mode. Miniport drivers are required to support this modal request.

## Parameters

### Major code

### Input buffer

None

### Input buffer length

### Output buffer

The miniport driver returns the mode information in a [VIDEO_MODE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ns-ntddvdeo-_video_mode_information) structure in the VRP **OutputBuffer**.

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

If the miniport driver successfully returns the mode data, it sets the **Information** member of the [STATUS_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_status_block) structure to **sizeof**(VIDEO_MODE_INFORMATION); otherwise, the miniport driver sets this member to zero.

## See also

[STATUS_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_status_block)

[VIDEO_MODE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ns-ntddvdeo-_video_mode_information)