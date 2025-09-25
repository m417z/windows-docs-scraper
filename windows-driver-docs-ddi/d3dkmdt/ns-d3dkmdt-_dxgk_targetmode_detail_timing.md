# _DXGK_TARGETMODE_DETAIL_TIMING structure

## Description

The DXGK_TARGETMODE_DETAIL_TIMING structure describes a video present target's additional timing modes that are compatible with the display device.

## Members

### `VideoStandard` [in]

A [D3DKMDT_VIDEO_SIGNAL_STANDARD](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_d3dkmdt_video_signal_standard)-typed value that indicates the supported video signal standard.

### `TimingId` [in]

A UINT value that describes the registry ID of the video standard data described by **VideoStandard**. The high 8 bits indicate the target mode's video standard. The low 24 bits indicate the mode index in the video standard.

### `DetailTiming` [in]

A [DISPLAYID_DETAILED_TIMING_TYPE_I](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_displayid_detailed_timing_type_i)-typed value that indicates the target mode data for a video present target.

## See also

[D3DKMDT_VIDEO_SIGNAL_STANDARD](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_d3dkmdt_video_signal_standard)

[DISPLAYID_DETAILED_TIMING_TYPE_I](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_displayid_detailed_timing_type_i)