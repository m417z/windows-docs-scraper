# _DXGK_CHILD_DESCRIPTOR structure

## Description

The DXGK_CHILD_DESCRIPTOR structure holds identification and capability information for an individual child device of the display adapter.

## Members

### `ChildDeviceType`

A member of the [DXGK_CHILD_DEVICE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ne-dispmprt-_dxgk_child_device_type) enumeration that indicates the type of the child device.

### `ChildCapabilities`

A [DXGK_CHILD_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_child_capabilities) structure that describes the capabilities of the child device.

### `AcpiUid`

If the child device is an ACPI device, this member contains the unique ACPI identifier of the child device.

### `ChildUid`

A unique identifier, created by the display miniport driver, that identifies the child device.

## Remarks

The [DxgkDdiQueryChildRelations](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_child_relations) function, implemented by the display miniport driver, fills in an array of DXGK_CHILD_DESCRIPTOR structures, one for each child device of the display adapter.

Each child device of type **TypeVideoOutput** is associated with a video present target, and the **ChildUid** member of this structure is used as the identifier for that video present target. Several functions implemented by the video present network (VidPN) manager receive a video present target identifier. For an example, see the *VidPnTargetId* parameter of the [pfnAcquireTargetModeSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpn_acquiretargetmodeset) function.

## See also

[DXGK_CHILD_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_child_capabilities)

[DXGK_CHILD_DEVICE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ne-dispmprt-_dxgk_child_device_type)

[DxgkDdiQueryChildRelations](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_child_relations)

[DxgkDdiQueryChildStatus](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_child_status)