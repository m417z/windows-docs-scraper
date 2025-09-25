# IOCTL_VIDEO_SWITCH_DUALVIEW IOCTL

## Description

Notifies the video miniport that a secondary view is about to be enabled or disabled. A secondary view is enabled by a call to the video port driver's [VideoPortCreateSecondaryDisplay](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportcreatesecondarydisplay).

Windows XP and later send this request to the video miniport driver to notify it of a secondary view change of status. Video miniport drivers can use this notification to make video memory arrangements in advance. For example, when the display driver sets the mode of the primary view, it can reserve video memory for one or more secondary views.

**Note** This request, which is available in Windows XP and later, can only be used to manage video memory.

## Parameters

### Major code

### Input buffer

The VRP **InputBuffer** contains a pointer to a ULONG, which can be one of the two following values:

|Value|Meaning|
|--- |--- |
|0|The device is about to be detached.|
|1|The device is about to be attached.|

### Input buffer length

### Output buffer

None

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

The miniport driver does not set the **Information** member of the [STATUS_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_status_block) structure.

## See also

[VideoPortCreateSecondaryDisplay](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportcreatesecondarydisplay)