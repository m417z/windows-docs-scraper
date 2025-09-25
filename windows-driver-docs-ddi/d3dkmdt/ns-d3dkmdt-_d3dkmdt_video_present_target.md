# _D3DKMDT_VIDEO_PRESENT_TARGET structure

## Description

The D3DKMDT_VIDEO_PRESENT_TARGET structure contains information about a video present target.

## Members

### `Id`

An integer that uniquely identifies the video present target.

### `VideoOutputTechnology`

A [D3DKMDT_VIDEO_OUTPUT_TECHNOLOGY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_d3dkmdt_video_output_technology) enumerator that indicates the target's output technology (for example HD15, DVI, HDMI).

### `VideoOutputHpdAwareness`

A value from the [DXGK_CHILD_DEVICE_HPD_AWARENESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_dxgk_child_device_hpd_awareness) enumeration that indicates the target's ability to detect that a monitor has been hot plugged or unplugged.

### `MonitorOrientationAwareness`

A [D3DKMDT_MONITOR_ORIENTATION_AWARENESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_d3dkmdt_monitor_orientation_awareness) enumerator that indicates the target's ability to detect that a connected monitor (or other display device) has been rotated.

### `SupportsSdtvModes`

Indicates whether the video output supports standard definition TV (SDTV) modes.

## Remarks

The D3DDDI_VIDEO_PRESENT_TARGET_ID data type is defined in *D3dukmdt.h*.

Video present target identifiers are assigned by the display miniport driver. [DxgkDdiQueryChildRelations](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_child_relations), implemented by the display miniport driver, returns an array of [DXGK_CHILD_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_child_descriptor) structures, each of which contains an identifier.

For more information about video present targets, see [Introduction to Video Present Networks](https://learn.microsoft.com/windows-hardware/drivers/display/introduction-to-video-present-networks).

## See also

[D3DKMDT_VIDEO_PRESENT_SOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_video_present_source)

[D3DKMDT_VIDPN_PRESENT_PATH](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_present_path)

[DXGK_CHILD_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_child_descriptor)

[DxgkDdiQueryChildRelations](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_child_relations)