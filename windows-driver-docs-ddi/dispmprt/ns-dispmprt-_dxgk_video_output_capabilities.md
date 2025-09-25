# _DXGK_VIDEO_OUTPUT_CAPABILITIES structure

## Description

The DXGK_VIDEO_OUTPUT_CAPABILITIES structure contains information about the capabilities of a video output on a display adapter.

## Members

### `InterfaceTechnology`

A [D3DKMDT_VIDEO_OUTPUT_TECHNOLOGY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_d3dkmdt_video_output_technology) enumerator that indicates the type of connector the video output uses to connect to an external display device.

### `MonitorOrientationAwareness`

A [D3DKMDT_MONITOR_ORIENTATION_AWARENESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_d3dkmdt_monitor_orientation_awareness) enumerator that describes the video output's ability to detect the rotation angle of an external display device.

### `SupportsSdtvModes`

Indicates whether the video output supports standard definition TV (SDTV) modes.

## Remarks

All child devices of a display adapter are onboard devices. Monitors and other external devices that connect to the display adapter are not considered child devices. Display adapters have two types of child devices: **TypeVideoOutput** and **TypeOther**. This structure applies only to child devices of type **TypeVideoOutput**.

The **ChildCapabilities** member of a [DXGK_CHILD_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_child_descriptor) structure is a DXGK_CHILD_CAPABILITIES structure. The **Type.VideoOutput** member of a DXGK_CHILD_CAPABILITIES structure is a DXGK_VIDEO_OUTPUT_CAPABILITIES structure.

## See also

[DXGK_CHILD_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_child_capabilities)

[DXGK_CHILD_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_child_descriptor)

[DxgkDdiQueryChildRelations](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_child_relations)