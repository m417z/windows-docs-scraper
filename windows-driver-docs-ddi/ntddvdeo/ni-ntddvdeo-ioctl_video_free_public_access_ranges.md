# IOCTL_VIDEO_FREE_PUBLIC_ACCESS_RANGES IOCTL

## Description

Releases the address range that was allocated by a preceding [IOCTL_VIDEO_QUERY_PUBLIC_ACCESS_RANGES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ni-ntddvdeo-ioctl_video_query_public_access_ranges) request. Support for this nonmodal request is optional.

## Parameters

### Major code

### Input buffer

The VRP **InputBuffer** contains an array of [VIDEO_MEMORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ns-ntddvdeo-_video_memory) structures to be released.

### Input buffer length

### Output buffer

None

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

The miniport driver does not set the **Information** member of the [STATUS_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_status_block) structure.

## See also

[IOCTL_VIDEO_QUERY_PUBLIC_ACCESS_RANGES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ni-ntddvdeo-ioctl_video_query_public_access_ranges)

[VIDEO_MEMORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ns-ntddvdeo-_video_memory)