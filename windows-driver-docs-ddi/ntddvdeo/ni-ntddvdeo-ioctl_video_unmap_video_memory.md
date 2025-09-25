# IOCTL_VIDEO_UNMAP_VIDEO_MEMORY IOCTL

## Description

Releases a mapping between the virtual address space and the adapter's [frame buffer](https://learn.microsoft.com/windows-hardware/drivers/) and video RAM. Miniport drivers are required to support this nonmodal request.

## Parameters

### Major code

### Input buffer

The VRP **InputBuffer** contains a [VIDEO_MEMORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ns-ntddvdeo-_video_memory) structure, specifying the previously mapped virtual base address to be released with [VideoPortUnmapMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportunmapmemory).

### Input buffer length

### Output buffer

None

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

The miniport driver does not set the **Information** member of the [STATUS_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_status_block) structure.

## See also

[VIDEO_MEMORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ns-ntddvdeo-_video_memory)

[VideoPortUnmapMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportunmapmemory)