# _D3DKMDT_MONITOR_ORIENTATION_AWARENESS enumeration

## Description

The D3DKMDT_MONITOR_ORIENTATION_AWARENESS enumeration is used to describe the ability of a video output device (on the display adapter) to detect changes in the orientation (rotation angle) of a connected external display device.

## Constants

### `D3DKMDT_MOA_UNINITIALIZED`

Indicates that a variable of type D3DKMDT_MONITOR_ORIENTATION_AWARENESS has not yet been assigned a meaningful value.

### `D3DKMDT_MOA_NONE`

Indicates that the video output device is unable to determine the orientation of a connected external display device.

### `D3DKMDT_MOA_POLLED`

Indicates that the video output device can determine the orientation of a connected external display device, and the display miniport driver can be aware of changes in orientation by polling the video output device.

### `D3DKMDT_MOA_INTERRUPTIBLE`

Indicates that the video output device can generate an interrupt when the orientation of a connected external display device changes.

## Remarks

The **ChildCapabilities** member of a [DXGK_CHILD_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_child_descriptor) structure is a [DXGK_CHILD_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_child_capabilities) structure. The **Type.VideoOutput** member of a CHILD_CAPABILITIES structure is a [DXGK_VIDEO_OUTPUT_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_video_output_capabilities) structure. The **MonitorOrientationAwareness** member of a VIDEO_OUTPUT_CAPABILITIES structure is a D3DKMDT_MONITOR_ORIENTATION_AWARENESS value.

## See also

[DxgkDdiQueryChildRelations](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_child_relations)