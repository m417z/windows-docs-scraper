# IOCTL_VIDEO_MAP_VIDEO_MEMORY IOCTL

## Description

Maps the video hardware [frame buffer](https://learn.microsoft.com/windows-hardware/drivers/) and video RAM into the virtual address space of the requester. Miniport drivers are required to handle this IOCTL and to map all video memory in the caller's address space with [VideoPortMapMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportmapmemory).

This request is both modal and nonmodal: the miniport driver must return the location size of the frame buffer within video memory, and the frame buffer size and location can vary from mode to mode (modal characteristic). However, a subsequent set-mode operation (to the same mode) must not cause the video memory to change location (nonmodal characteristic).

## Parameters

### Major code

### Input buffer

The VRP **InputBuffer** contains a [VIDEO_MEMORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ns-ntddvdeo-_video_memory) structure specifying either a requested virtual base address or zero, which requests the system to assign a virtual base address mapped to the adapter's RAM and frame buffer range(s).

### Input buffer length

### Output buffer

The miniport driver returns a [VIDEO_MEMORY_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ns-ntddvdeo-_video_memory_information) structure in the VRP **OutputBuffer**.

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

If the miniport driver successfully maps the memory, it sets the **Information** member of the [STATUS_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_status_block) structure to **sizeof**(VIDEO_MEMORY_INFORMATION); otherwise, it sets this member to zero.

## See also

[STATUS_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_status_block)

[VIDEO_MEMORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ns-ntddvdeo-_video_memory)

[VIDEO_MEMORY_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ns-ntddvdeo-_video_memory_information)

[VideoPortMapMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportmapmemory)