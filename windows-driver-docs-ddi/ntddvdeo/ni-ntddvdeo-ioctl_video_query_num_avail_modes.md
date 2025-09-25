# IOCTL_VIDEO_QUERY_NUM_AVAIL_MODES IOCTL

## Description

Returns the number of video modes supported by the adapter and the size in bytes of the video mode information, which can be used to allocate a buffer for an [IOCTL_VIDEO_QUERY_AVAIL_MODES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ni-ntddvdeo-ioctl_video_query_avail_modes) request. Miniport drivers are required to support this nonmodal request.

## Parameters

### Major code

### Input buffer

None

### Input buffer length

### Output buffer

The miniport driver returns the number of modes in a [VIDEO_NUM_MODES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ns-ntddvdeo-_video_num_modes) structure in the VRP **OutputBuffer**.

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

If the miniport driver successfully returns the mode count, it sets the **Information** member of the [STATUS_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_status_block) structure to **sizeof**(VIDEO_NUM_MODES); otherwise, the miniport driver sets this member to zero.

## See also

[IOCTL_VIDEO_QUERY_AVAIL_MODES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ni-ntddvdeo-ioctl_video_query_avail_modes)

[STATUS_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_status_block)

[VIDEO_NUM_MODES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ns-ntddvdeo-_video_num_modes)