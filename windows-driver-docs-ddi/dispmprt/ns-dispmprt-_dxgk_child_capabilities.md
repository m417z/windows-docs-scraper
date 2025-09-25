# _DXGK_CHILD_CAPABILITIES structure

## Description

The DXGK_CHILD_CAPABILITIES structure contains information about the capabilities of an individual child device of a display adapter.

## Members

### `Type`

 A union that can contain either video output information or other information in the following members.

### `Type.VideoOutput`

A [DXGK_VIDEO_OUTPUT_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_video_output_capabilities) structure that contains information about a video output. This member is meaningful only if the child device has type **TypeVideoOutput**.

### `Type.Other`

A structure whose only member must be equal to zero if the child device has type **TypeOther**.

### `Type.Other.MustBeZero`

A UINT value that must be equal to zero.

### `Type.IntegratedDisplayChild`

Returns the integrated display child specific fields of the child capabilities.

### `HpdAwareness`

A [DXGK_CHILD_DEVICE_HPD_AWARENESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_dxgk_child_device_hpd_awareness) enumerator that indicates the child device's level of hot-plug awareness.

## Remarks

The **ChildDeviceType** member of a [DXGK_CHILD_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_child_descriptor) structure is a [DXGK_CHILD_DEVICE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ne-dispmprt-_dxgk_child_device_type) enumerator that indicates type of the child device: **TypeVideoOutput** or **TypeOther**.

If a child device is of type **TypeVideoOutput**, the **Type.VideoOutput** member of its DXGK_CHILD_DESCRIPTOR structure is a DXGK_VIDEO_OUTPUT_CAPABILITIES structure.

If a child device is of type **TypeOther**, then **Type.Other.MustBeZero** must be set to zero.

## See also

[DXGK_CHILD_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_child_descriptor)

[DXGK_VIDEO_OUTPUT_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_video_output_capabilities)

[DxgkDdiQueryChildRelations](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_child_relations)