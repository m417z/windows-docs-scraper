# _VIDEO_CHILD_STATE_CONFIGURATION structure

## Description

The VIDEO_CHILD_STATE_CONFIGURATION structure contains an array of [VIDEO_CHILD_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_child_state) structures, each holding the state of a particular child device.

## Members

### `Count`

Specifies the number of structures in the **ChildStateArray** member.

### `ChildStateArray`

Is an array of [VIDEO_CHILD_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_child_state) structures. Each element of this array contains the ID and state for a particular child device.

## Remarks

The video port driver sends a VIDEO_CHILD_STATE_CONFIGURATION structure to the miniport driver for the following IOCTLs:

* [IOCTL_VIDEO_VALIDATE_CHILD_STATE_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ni-ntddvdeo-ioctl_video_validate_child_state_configuration), in which the video port driver queries the miniport driver to determine whether the specified state for each child device in **ChildStateArray** is valid.
* [IOCTL_VIDEO_SET_CHILD_STATE_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ni-ntddvdeo-ioctl_video_set_child_state_configuration), in which the video port driver requests the miniport driver to make the specified state change for each child device in **ChildStateArray**.

## See also

[IOCTL_VIDEO_SET_CHILD_STATE_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ni-ntddvdeo-ioctl_video_set_child_state_configuration)

[IOCTL_VIDEO_VALIDATE_CHILD_STATE_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ni-ntddvdeo-ioctl_video_validate_child_state_configuration)

[VIDEO_CHILD_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_child_state)

[VIDEO_REQUEST_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_request_packet)