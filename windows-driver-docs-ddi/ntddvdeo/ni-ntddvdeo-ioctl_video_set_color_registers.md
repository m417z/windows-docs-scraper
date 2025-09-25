# IOCTL_VIDEO_SET_COLOR_REGISTERS IOCTL

## Description

Sets the adapter's color registers to the specified RGB values. If the adapter has a color look up table (CLUT), sometimes called a palette, the miniport driver is required to support this modal request.

## Parameters

### Major code

### Input buffer

The VRP **InputBuffer** contains a VIDEO_CLUT structure, specifying an array of RGB values to be set.

### Input buffer length

### Output buffer

None

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

The miniport driver does not set the **Information** member of the [STATUS_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_status_block) structure.