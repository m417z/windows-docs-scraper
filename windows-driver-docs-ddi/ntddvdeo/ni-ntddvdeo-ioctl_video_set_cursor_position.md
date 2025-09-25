# IOCTL_VIDEO_SET_CURSOR_POSITION IOCTL

## Description

Sets the cursor position (row and column). Miniport drivers for VGA-compatible adapters are required to support this request, which is modal. It is optional for other miniport drivers.

## Parameters

### Major code

### Input buffer

The VRP **InputBuffer** contains the VIDEO_CURSOR_POSITION structure to be set.

### Input buffer length

### Output buffer

None

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

The miniport driver does not set the **Information** member of the [STATUS_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_status_block) structure.