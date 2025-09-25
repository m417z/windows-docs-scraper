# IOCTL_VIDEO_SET_PALETTE_REGISTERS IOCTL

## Description

Loads a specified portion of the adapter palette registers with an array of colors. Miniport drivers for VGA-compatible adapters are required to support this request, which is modal. Support is optional for other miniport drivers.

## Parameters

### Major code

### Input buffer

The VRP **InputBuffer** contains the VIDEO_PALETTE_DATA structure, specifying an array of colors to be set in the palette registers.

### Input buffer length

### Output buffer

None

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

The miniport driver does not set the **Information** member of the [STATUS_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_status_block) structure.