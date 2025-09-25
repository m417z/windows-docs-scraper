# IOCTL_VIDEO_VALIDATE_CHILD_STATE_CONFIGURATION IOCTL

## Description

Queries the miniport driver to determine whether it is ready for a display device switch. This switch is a state change in which the video signal going to one display device is sent to another, possibly different type of display device. After the display device switch, the video signal can be sent to one or both display devices. When the video port driver receives a request to switch display devices (by, for example, a hotkey being pressed), it sends this IOCTL to the video miniport driver. The value returned by the miniport driver indicates whether the video port driver should proceed with the display device switch.

When the miniport driver receives this request, it should indicate that it has successfully handled the request by:

* Placing the appropriate value (described in the **Output** section) in **OutputBuffer**
* Returning NO_ERROR in the **Status** member of the VRP's **StatusBlock**

The video miniport driver carries out a validated display device switch when it receives an [IOCTL_VIDEO_SET_CHILD_STATE_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ni-ntddvdeo-ioctl_video_set_child_state_configuration) request.

The miniport driver is not required to handle this modal IOCTL. The video port driver interprets a default return value from the miniport driver as permission to proceed with the display device switch.

## Parameters

### Major code

### Input buffer

The VRP **InputBuffer** contains a [VIDEO_CHILD_STATE_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_child_state_configuration) structure.

### Input buffer length

### Output buffer

The miniport driver returns 1 in the VRP **OutputBuffer** if the video port driver should proceed with the display device switch; otherwise, the driver returns 0 in the VRP **OutputBuffer**.

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

The miniport driver stores NO_ERROR in **Status** if it has successfully handled this IOCTL; otherwise, the driver stores a relevant video error code in **Status**. In either case, the miniport driver sets the **Information** member of the [STATUS_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_status_block) structure to **sizeof**(ULONG).

## See also

[IOCTL_VIDEO_SET_CHILD_STATE_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ni-ntddvdeo-ioctl_video_set_child_state_configuration)

[STATUS_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_status_block)

[VIDEO_CHILD_STATE_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_child_state_configuration)