# IOCTL_VIDEO_LOAD_AND_SET_FONT IOCTL

## Description

Loads a user-defined font on the adapter. Miniport drivers for VGA-compatible adapters are required to support this modal request; optional for other miniport drivers.

## Parameters

### Major code

### Input buffer

The VRP **InputBuffer** contains a VIDEO_LOAD_FONT_INFORMATION structure describing the font's width, height, and size, as well as a pointer to the font buffer.

### Input buffer length

### Output buffer

None

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

The miniport driver does not set the **Information** member of the [STATUS_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_status_block) structure.