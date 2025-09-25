# IOCTL_VIDEO_QUERY_COLOR_CAPABILITIES IOCTL

## Description

Returns the color-capabilities information found in the VDDP description file for the adapter. Support for this nonmodal request is optional. However, if a miniport driver supports this request, it cannot return a subset of the color-capabilities information.

## Parameters

### Major code

### Input buffer

None

### Input buffer length

### Output buffer

The miniport driver returns all VIDEO_COLOR_CAPABILITIES information in the VRP **OutputBuffer**.

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

If the miniport driver successfully returns the color-capabilities data, it sets the **Information** member of the [STATUS_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_status_block) structure to **sizeof**(VIDEO_COLOR_CAPABILITIES); otherwise, the miniport driver sets this member to zero.

## See also

[STATUS_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_status_block)