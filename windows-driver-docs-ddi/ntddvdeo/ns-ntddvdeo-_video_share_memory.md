# _VIDEO_SHARE_MEMORY structure

## Description

The VIDEO_SHARE_MEMORY structure is used in a request to the video miniport driver for a block of user-mode memory to be shared with the specified process.

## Members

### `ProcessHandle`

Is a handle to the current process. This member is usually set to **NtCurrentProcess**, a macro defined in *Ntddk.h*.

### `ViewOffset`

Indicates the byte offset from the beginning of the [frame buffer](https://learn.microsoft.com/windows-hardware/drivers/). This member is usually set to 0.

### `ViewSize`

Indicates the size, in bytes, of the frame buffer.

### `RequestedVirtualAddress`

Indicates the location of the requested frame buffer in the process's memory. This member is normally set to **NULL**, which means the display driver writer does not care about the precise location of the requested memory. If this member is set to a non-**NULL** value, the display driver writer intends that the frame buffer be located at that address. In this case, the display driver writer must be certain that the location specified is not already in use for another purpose.

## Remarks

VIDEO_SHARE_MEMORY is provided so that applications such as Direct Draw can have a view of video memory. Although the display driver is unable to directly provide such access to video memory, it can call into the video miniport driver for this purpose. The display driver does this by sending an [IOCTL_VIDEO_SHARE_VIDEO_MEMORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ni-ntddvdeo-ioctl_video_share_video_memory) request to the miniport driver. When the miniport driver fulfills this request, it uses the information in the VIDEO_SHARE_MEMORY structure, and fills in a [VIDEO_SHARE_MEMORY_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ns-ntddvdeo-_video_share_memory_information) structure with the actual location of the requested memory, if no location was specified. When the application no longer needs the shared memory, the display driver can release this memory by making an [IOCTL_VIDEO_UNSHARE_VIDEO_MEMORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ni-ntddvdeo-ioctl_video_unshare_video_memory) request, which also uses a VIDEO_SHARE_MEMORY structure as an input buffer.

For structures used in mapping into kernel-mode video memory, see [VIDEO_MEMORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ns-ntddvdeo-_video_memory) and [VIDEO_MEMORY_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ns-ntddvdeo-_video_memory_information).

## See also

[IOCTL_VIDEO_SHARE_VIDEO_MEMORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ni-ntddvdeo-ioctl_video_share_video_memory)

[IOCTL_VIDEO_UNSHARE_VIDEO_MEMORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ni-ntddvdeo-ioctl_video_unshare_video_memory)

[VIDEO_SHARE_MEMORY_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ns-ntddvdeo-_video_share_memory_information)