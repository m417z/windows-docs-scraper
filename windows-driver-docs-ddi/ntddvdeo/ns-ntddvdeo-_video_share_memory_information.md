# _VIDEO_SHARE_MEMORY_INFORMATION structure

## Description

The VIDEO_SHARE_MEMORY_INFORMATION structure is used to communicate to the display driver that a request for a block of user-mode memory has been fulfilled.

## Members

### `SharedViewOffset`

Indicates the offset, in bytes, from the beginning of the [frame buffer](https://learn.microsoft.com/windows-hardware/drivers/).

### `SharedViewSize`

Indicates the size, in bytes, of the frame buffer. The value of this member will always be a multiple of 64 KB.

### `VirtualAddress`

Indicates the address in virtual memory at which the requested memory was mapped.

## Remarks

When an application must have access to user-mode video memory, the display driver can call into the video miniport driver by sending it an [IOCTL_VIDEO_SHARE_VIDEO_MEMORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ni-ntddvdeo-ioctl_video_share_video_memory) request. The miniport driver uses a [VIDEO_SHARE_MEMORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ns-ntddvdeo-_video_share_memory) structure as an input buffer, and communicates back to the display driver a VIDEO_SHARE_MEMORY_INFORMATION structure.

The video miniport driver fills out a VIDEO_SHARE_MEMORY_INFORMATION structure based on information in a VIDEO_SHARE_MEMORY structure. The following table summarizes how the information is used:

|VIDEO_SHARE_MEMORY member|Result on VIDEO_SHARE_MEMORY_INFORMATION|
|--- |--- |
|ProcessHandle|Is not used.|
|ViewOffset|Copied directly to SharedViewOffset.|
|ViewSize|Values that are multiples of 64 KB are copied directly to SharedViewSize. Other values are rounded up to the next larger multiple of 64 KB.|
|RequestedVirtualAddress|If NULL, the miniport driver determines the address of a frame buffer to assign to VirtualAddress. If non-NULL, the miniport driver attempts to assign that value to VirtualAddress.|

## See also

[IOCTL_VIDEO_SHARE_VIDEO_MEMORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ni-ntddvdeo-ioctl_video_share_video_memory)

[VIDEO_SHARE_MEMORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ns-ntddvdeo-_video_share_memory)