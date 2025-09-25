# IOCTL_VIDEO_RESET_DEVICE IOCTL

## Description

Resets the video hardware to the default mode, to which it was initialized at system boot. Miniport drivers are required to support this nonmodal request.

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