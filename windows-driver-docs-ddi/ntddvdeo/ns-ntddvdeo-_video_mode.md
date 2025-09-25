# _VIDEO_MODE structure

## Description

The VIDEO_MODE structure contains the requested VGA mode that an adapter should set. This structure is used in conjunction with [IOCTL_VIDEO_SET_CURRENT_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ni-ntddvdeo-ioctl_video_set_current_mode).

## Members

### `RequestedMode`

Is the mode that the miniport driver should set if possible. In addition, the two high-order bits can be set to request special behavior from the miniport driver as follows:

#### VIDEO_MODE_ZERO_MEMORY

Indicates that the miniport driver should zero the video memory in conjunction with the mode set.

#### VIDEO_MODE_MAP_MEM_LINEAR

Indicates that the miniport driver should map the video memory in a linear fashion if the adapter supports such an operation.