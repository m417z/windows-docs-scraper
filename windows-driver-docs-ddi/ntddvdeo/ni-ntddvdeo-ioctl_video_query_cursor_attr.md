# IOCTL_VIDEO_QUERY_CURSOR_ATTR IOCTL

## Description

Returns the size, position, and visibility of the cursor. Miniport drivers for VGA-compatible adapters are required to support this modal request; optional for other miniport drivers. The cursor position is specified by top and bottom scan lines, instead of row and column information, for VGA-compatible adapters.

## Parameters

### Major code

### Input buffer

None

### Input buffer length

### Output buffer

The miniport driver returns a VIDEO_CURSOR_ATTRIBUTES structure in the VRP **OutputBuffer**.

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

If the miniport driver successfully returns the cursor-attribute data, it sets the **Information** member of the [STATUS_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_status_block) structure to **sizeof**(VIDEO_CURSOR_ATTRIBUTES); otherwise, the miniport driver sets this member to zero.

## See also

[STATUS_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_status_block)