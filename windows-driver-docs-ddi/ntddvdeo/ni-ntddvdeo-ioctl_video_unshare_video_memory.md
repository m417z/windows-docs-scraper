# IOCTL_VIDEO_UNSHARE_VIDEO_MEMORY IOCTL

## Description

Unmaps a video hardware frame buffer and video RAM from the virtual address space of the requester that was mapped by an [IOCTL_VIDEO_SHARE_VIDEO_MEMORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ni-ntddvdeo-ioctl_video_share_video_memory) request.

## Parameters

### Major code

### Input buffer

The VRP **InputBuffer** contains a [VIDEO_SHARE_MEMORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ns-ntddvdeo-_video_share_memory) structure specifying the process and the virtual address where the video memory is mapped. The memory is unmapped by calling [VideoPortUnmapMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportunmapmemory).

### Input buffer length

### Output buffer

None

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

The miniport driver does not set the **Information** member of the [STATUS_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_status_block) structure.

## See also

[IOCTL_VIDEO_SHARE_VIDEO_MEMORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ni-ntddvdeo-ioctl_video_share_video_memory)

[VIDEO_SHARE_MEMORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ns-ntddvdeo-_video_share_memory)

[VideoPortUnmapMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportunmapmemory)