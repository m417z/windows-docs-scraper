# IOCTL_VIDEO_ENABLE_CURSOR IOCTL

## Description

Makes the cursor visible by enabling the cursor's visibility attribute. Miniport drivers for VGA-compatible adapters are required to support this modal request; optional for other miniport drivers.

## Parameters

### Major code

### Input buffer

None

### Input buffer length

### Output buffer

None

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

The miniport driver does not set the **Information** member of the [STATUS_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_status_block) structure.