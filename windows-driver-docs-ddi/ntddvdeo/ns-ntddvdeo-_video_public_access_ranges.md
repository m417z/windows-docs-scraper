# _VIDEO_PUBLIC_ACCESS_RANGES structure

## Description

The VIDEO_PUBLIC_ACCESS_RANGES structure contains information about video resources other than [frame buffers](https://learn.microsoft.com/windows-hardware/drivers/) and video RAM, such as memory-mapped I/O registers or ports.

## Members

### `InIoSpace`

Indicates the location of the range. This parameter can be one of the following values, or certain bitwise combinations of these values:

|Value|Meaning|
|--- |--- |
|VIDEO_MEMORY_SPACE_DENSE|Obsolete.|
|VIDEO_MEMORY_SPACE_IO|The indicated address ranges are in system I/O space rather than in memory space.|
|VIDEO_MEMORY_SPACE_MEMORY|The indicated address ranges are in memory space rather than in system I/O space.|
|VIDEO_MEMORY_SPACE_P6CACHE|The processor aggregates a sequence of write operations and sends them to a given cache line. The processor then flushes the cache. This flag is meaningful only when VIDEO_MEMORY_SPACE_IO is not set.|
|VIDEO_MEMORY_SPACE_USER_MODE|Indicates that the address range specified should be mapped into user mode rather than kernel mode. This flag is meaningful only when VIDEO_MEMORY_SPACE_IO is not set.|

### `MappedInIoSpace`

Indicates, on the current platform, whether the registers or ports are mapped in I/O space or in memory space. A value of **TRUE** (1) indicates that the registers or ports are mapped in I/O space; a value of **FALSE** (0) indicates that the registers or ports are mapped in memory space.

### `VirtualAddress`

Pointer to the location of the registers or I/O ports as mapped under the current architecture.

## Remarks

VIDEO_PUBLIC_ACCESS_RANGES is similar to [VIDEO_ACCESS_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_access_range) in that both are used by miniport drivers to obtain information about display resources. The principal difference is that VIDEO_PUBLIC_ACCESS_RANGES contains information about control and accelerator registers for an adapter, while VIDEO_ACCESS_RANGE is used to hold frame buffer and video RAM addresses.

VIDEO_PUBLIC_ACCESS_RANGES is used as an input buffer with the [IOCTL_VIDEO_QUERY_PUBLIC_ACCESS_RANGES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ni-ntddvdeo-ioctl_video_query_public_access_ranges) request.

## See also

[IOCTL_VIDEO_QUERY_PUBLIC_ACCESS_RANGES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ni-ntddvdeo-ioctl_video_query_public_access_ranges)

[VIDEO_ACCESS_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_access_range)