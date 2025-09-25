# IOCTL_VIDEO_ENABLE_POINTER IOCTL

## Description

Makes the pointer visible by enabling pointer attributes. Support for this modal request is optional; however, if a miniport driver supports this request, it must process an [IOCTL_VIDEO_SET_POINTER_ATTR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ni-ntddvdeo-ioctl_video_set_pointer_attr) request before processing this request.

## Parameters

### Major code

### Input buffer

None

### Input buffer length

### Output buffer

None

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

The miniport driver does not set the **Information** member of the [STATUS_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_status_block) structure.

## See also

[IOCTL_VIDEO_SET_POINTER_ATTR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ni-ntddvdeo-ioctl_video_set_pointer_attr)