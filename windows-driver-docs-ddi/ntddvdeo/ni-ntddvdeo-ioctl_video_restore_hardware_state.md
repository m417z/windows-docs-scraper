# IOCTL_VIDEO_RESTORE_HARDWARE_STATE IOCTL

## Description

Restores all values used to set the hardware registers. Miniport drivers for VGA-compatible adapters are required to support this nonmodal request; optional for other miniport drivers.

## Parameters

### Major code

### Input buffer

The VRP **InputBuffer** contains the previously-saved VIDEO_HARDWARE_STATE structure.

### Input buffer length

### Output buffer

None

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

The miniport driver does not set the **Information** member of the [STATUS_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_status_block) structure.