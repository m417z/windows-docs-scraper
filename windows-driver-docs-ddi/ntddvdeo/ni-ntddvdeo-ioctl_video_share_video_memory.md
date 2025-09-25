# IOCTL_VIDEO_SHARE_VIDEO_MEMORY IOCTL

## Description

This IOCTL is called by a process that will share user-mode video memory as a linear [frame buffer](https://learn.microsoft.com/windows-hardware/drivers/). Miniport drivers handle this IOCTL by mapping the frame buffer into the caller's address space with [VideoPortMapBankedMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportmapbankedmemory). Otherwise this IOCTL is the same as [IOCTL_VIDEO_MAP_VIDEO_MEMORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ni-ntddvdeo-ioctl_video_map_video_memory).

This request is both modal and nonmodal: the miniport driver must return the location size of the frame buffer within video memory, and the frame buffer size and location can vary from mode to mode (modal characteristic), but a subsequent set-mode operation (to the same mode) must not cause the video memory to change location (nonmodal characteristic).

This IOCTL is DCI only.

## Parameters

### Major code

### Input buffer

The VRP **InputBuffer** contains a [VIDEO_SHARE_MEMORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ns-ntddvdeo-_video_share_memory) structure specifying a handle to the process mapping the frame buffer, and the requested view size and offset into the shared memory. The view size plus the offset must not exceed the memory size of the adapter.

### Input buffer length

### Output buffer

The miniport driver returns the [VIDEO_SHARE_MEMORY_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ns-ntddvdeo-_video_share_memory_information) structure in the VRP **OutputBuffer**. This output contains the virtual address where the video memory is mapped, the view size in bytes of the mapped memory and the offset into the view.

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

If the miniport driver successfully maps the memory, it sets the **Information** member of the [STATUS_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_status_block) structure to **sizeof**(VIDEO_SHARE_MEMORY_INFORMATION); otherwise, the miniport driver sets this member to zero.

## See also

[IOCTL_VIDEO_MAP_VIDEO_MEMORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ni-ntddvdeo-ioctl_video_map_video_memory)

[STATUS_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_status_block)

[VIDEO_SHARE_MEMORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ns-ntddvdeo-_video_share_memory)

[VIDEO_SHARE_MEMORY_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ns-ntddvdeo-_video_share_memory_information)

[VideoPortMapBankedMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportmapbankedmemory)