# IOCTL_VIDEO_HANDLE_VIDEOPARAMETERS IOCTL

## Description

Gets the capabilities of the device's television connector and/or copy protection hardware, or sets the desired functionality on the copy protection hardware. Adapters that support TV connectors should provide support for this modal IOCTL. See [TV Connector and Copy Protection Support in Video Miniport Drivers](https://learn.microsoft.com/windows-hardware/drivers/display/tv-connector-and-copy-protection-support-in-video-miniport-drivers) for details.

## Parameters

### Major code

### Input buffer

The VRP **InputBuffer** contains a [VIDEOPARAMETERS](https://learn.microsoft.com/windows/win32/api/tvout/ns-tvout-videoparameters) structure that describes the action to be performed by the miniport driver.

### Input buffer length

### Output buffer

The miniport driver returns the VIDEOPARAMETERS structure in the VRP **OutputBuffer**.

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

If the miniport driver successfully gets or sets the requested information, it sets the **Information** member of the VRP's [STATUS_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_status_block) to **sizeof**(VIDEOPARAMETERS); otherwise, the miniport driver sets this member to zero.

## See also

[STATUS_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_status_block)

[VIDEOPARAMETERS](https://learn.microsoft.com/windows/win32/api/tvout/ns-tvout-videoparameters)