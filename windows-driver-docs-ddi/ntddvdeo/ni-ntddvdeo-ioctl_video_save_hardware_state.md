# IOCTL_VIDEO_SAVE_HARDWARE_STATE IOCTL

## Description

Saves the state of the video adapter in the VRP **OutputBuffer**. Miniport drivers for VGA-compatible adapters are required to support this nonmodal request; optional for other miniport drivers.

## Parameters

### Major code

### Input buffer

None

### Input buffer length

### Output buffer

The miniport driver returns a VIDEO_HARDWARE_STATE structure in the VRP **OutputBuffer**.

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

If the miniport driver successfully saves the adapter state, it sets the **Information** member of the [STATUS_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_status_block) structure to **sizeof**(VIDEO_HARDWARE_STATE); otherwise, the miniport driver sets this member to zero.

## See also

[STATUS_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_status_block)