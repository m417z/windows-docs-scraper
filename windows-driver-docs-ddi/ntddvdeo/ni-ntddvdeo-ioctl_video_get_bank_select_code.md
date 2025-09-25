# IOCTL_VIDEO_GET_BANK_SELECT_CODE IOCTL

## Description

Returns a block of x86-specific executable code to be used by a high-resolution SVGA display driver for bank switching. Miniport drivers for VGA-compatible adapters are required to support this modal request; optional for other miniport drivers.

## Parameters

### Major code

### Input buffer

None

### Input buffer length

### Output buffer

The miniport driver returns a VIDEO_BANK_SELECT structure in the VRP **OutputBuffer**.

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

If the miniport driver returns its code block, it sets the **Information** member of the [STATUS_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_status_block) structure to **sizeof**(VIDEO_BANK_SELECT); otherwise, the miniport driver sets this member to zero.

## See also

[STATUS_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_status_block)