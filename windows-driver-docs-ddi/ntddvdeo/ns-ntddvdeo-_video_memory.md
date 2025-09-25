# _VIDEO_MEMORY structure

## Description

The VIDEO_MEMORY structure holds the address of a requested block of kernel-mode video memory.

## Members

### `RequestedVirtualAddress`

Pointer to the requested virtual address for either the video memory, or the base of video memory, depending on whether [IOCTL_VIDEO_MAP_VIDEO_MEMORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ni-ntddvdeo-ioctl_video_map_video_memory) or [IOCTL_VIDEO_UNMAP_VIDEO_MEMORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ni-ntddvdeo-ioctl_video_unmap_video_memory) is using this structure.

## Remarks

VIDEO_MEMORY is used as an input structure to two IOCTLs: [IOCTL_VIDEO_MAP_VIDEO_MEMORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ni-ntddvdeo-ioctl_video_map_video_memory), and [IOCTL_VIDEO_UNMAP_VIDEO_MEMORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ni-ntddvdeo-ioctl_video_unmap_video_memory).

When VIDEO_MEMORY is used with IOCTL_VIDEO_MAP_VIDEO_MEMORY, **RequestedVirtualAddress** points to the requested virtual address for the video memory. In this case, the value is optional. If zero is specified, the operating system will choose an appropriate location.

When VIDEO_MEMORY is used with IOCTL_VIDEO_UNMAP_VIDEO_MEMORY, **RequestedVirtualAddress** points to the virtual address of the base of video memory. In this case, the size is implicit since it cannot change (you cannot add video memory dynamically, so it must be the same size as when it was mapped).

For structures used in mapping into user-mode video memory, see [VIDEO_SHARE_MEMORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ns-ntddvdeo-_video_share_memory) AND [VIDEO_SHARE_MEMORY_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ns-ntddvdeo-_video_share_memory_information).

## See also

[IOCTL_VIDEO_MAP_VIDEO_MEMORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ni-ntddvdeo-ioctl_video_map_video_memory)

[IOCTL_VIDEO_UNMAP_VIDEO_MEMORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ni-ntddvdeo-ioctl_video_unmap_video_memory)

[VIDEO_MEMORY_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ns-ntddvdeo-_video_memory_information)