# _VIDEO_NUM_MODES structure

## Description

The VIDEO_NUM_MODES structure contains the number of modes supported by a video adapter, and the size of the structure that describes each mode.

## Members

### `NumModes`

Specifies the number of modes supported by the device.

### `ModeInformationLength`

Is the length, in bytes, of the [VIDEO_MODE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ns-ntddvdeo-_video_mode_information) structure that describes each of the modes supported by the device.

## Remarks

The miniport driver returns a VIDEO_NUM_MODES structure in response to an [IOCTL_VIDEO_QUERY_NUM_AVAIL_MODES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ni-ntddvdeo-ioctl_video_query_num_avail_modes) request.

## See also

[IOCTL_VIDEO_QUERY_NUM_AVAIL_MODES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ni-ntddvdeo-ioctl_video_query_num_avail_modes)

[VIDEO_MODE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ns-ntddvdeo-_video_mode_information)