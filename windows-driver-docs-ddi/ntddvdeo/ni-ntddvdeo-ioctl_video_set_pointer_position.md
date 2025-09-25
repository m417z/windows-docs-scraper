# IOCTL_VIDEO_SET_POINTER_POSITION IOCTL

## Description

Sets the pointer position. Support for this modal request is optional. A supporting miniport driver should have already processed an enable-pointer request before processing this request.

## Parameters

### Major code

### Input buffer

The VRP **InputBuffer** contains the VIDEO_POINTER_POSITION structure to be set.

### Input buffer length

### Output buffer

None

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

The miniport driver does not set the **Information** member of the [STATUS_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_status_block) structure.