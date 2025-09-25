# IOCTL_VIDEO_QUERY_POINTER_ATTR IOCTL

## Description

Returns the attributes for the pointer, defined as a set of pixels used to paint the shape associated with the mouse. Support for this modal request is optional.

## Parameters

### Major code

### Input buffer

None

### Input buffer length

### Output buffer

The miniport driver returns a VIDEO_POINTER_ATTRIBUTES structure in the VRP **OutputBuffer**.

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

If the miniport driver successfully returns the pointer attributes, it sets the **Information** member of the [STATUS_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_status_block) structure to **sizeof**(VIDEO_POINTER_ATTRIBUTES); otherwise, the miniport driver sets this member to zero.

## See also

[STATUS_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_status_block)