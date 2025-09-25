# _VIDEO_CHILD_STATE structure

## Description

The VIDEO_CHILD_STATE structure contains information about a child device and the state into which it should be placed.

## Members

### `Id`

Specifies the ID for a particular child device, as given to it by the miniport driver. This value is the same as that returned in the *UId* parameter of the [HwVidGetVideoChildDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_get_child_descriptor) function.

### `State`

Specifies the new state, on or off, for the child device. A value of one (1) indicates that the child device should be turned on; a value of zero (0) indicates that it should be turned off. One possible use for **State** is in hotkey switching from one display device to another.

## Remarks

One member of the [VIDEO_CHILD_STATE_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_child_state_configuration) structure is an array of VIDEO_CHILD_STATE structures. Each of these structures maintains state information for one of an adapter's child devices.

## See also

[HwVidGetVideoChildDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_get_child_descriptor)

[VIDEO_CHILD_STATE_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_child_state_configuration)