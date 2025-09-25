# IOCTL_VIDEO_SET_CHILD_STATE_CONFIGURATION IOCTL

## Description

Performs a display device switch, a state change in which the video signal going to one display device is sent to another, possibly different type of display device. After the display device switch, the video signal can be sent to one or both display devices. When the video port driver receives a notification to switch display devices, it sends this IOCTL to the miniport driver. Normally, this IOCTL is sent after [IOCTL_VIDEO_VALIDATE_CHILD_STATE_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ni-ntddvdeo-ioctl_video_validate_child_state_configuration) indicates that the miniport driver is ready to make the switch. If the miniport driver is capable of switching display devices, it should do so and set the **Status** member of **StatusBlock** to NO_ERROR.

If the miniport driver is not capable of performing the display device switch, it can set the **Status** member of **StatusBlock** to an appropriate error value (described in the **StatusBlock** section), choosing not to handle the request. Although this request is optional, it is highly recommended that the miniport driver handle this request. Failure to do so forces a call to the BIOS to handle the display device switch, which can be very inefficient, and can have an adverse effect on the system's robustness.

IOCTL_VIDEO_SET_CHILD_STATE_CONFIGURATION is synchronous. After this IOCTL is sent, [IOCTL_VIDEO_GET_CHILD_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ni-ntddvdeo-ioctl_video_get_child_state) should reflect the new state.

This request is modal.

## Parameters

### Major code

### Input buffer

The VRP **InputBuffer** contains a [VIDEO_CHILD_STATE_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_child_state_configuration) structure.

### Input buffer length

### Output buffer

None

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

The miniport driver sets the **Status** member to NO_ERROR if it is capable of performing the display device switch. If it is not able to carry out this operation, the miniport driver can set **Status** to an appropriate error value, or do nothing at all.

## See also

[IOCTL_VIDEO_GET_CHILD_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ni-ntddvdeo-ioctl_video_get_child_state)

[IOCTL_VIDEO_VALIDATE_CHILD_STATE_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ni-ntddvdeo-ioctl_video_validate_child_state_configuration)

[VIDEO_CHILD_STATE_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_child_state_configuration)