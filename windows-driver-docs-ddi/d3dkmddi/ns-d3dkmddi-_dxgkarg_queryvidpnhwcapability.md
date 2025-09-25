# DXGKARG_QUERYVIDPNHWCAPABILITY structure

## Description

The **DXGKARG_QUERYVIDPNHWCAPABILITY** structure is used by the display miniport driver to describe the hardware capabilities of a functional VidPN in response to a call to the [**DxgkDdiQueryVidPnHWCapability**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryvidpnhwcapability) function.

## Members

### `hFunctionalVidPn` [in]

A handle to a functional VidPN object for which the hardware capabilities are being queried.

### `SourceId` [in]

An integer that identifies a video present source on the display adapter.

### `TargetId` [in]

An integer that identifies a video present target on the display adapter.

### `VidPnHWCaps` [out]

A [**D3DKMDT_VIDPN_HW_CAPABILITY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_hw_capability) structure that describes the capabilities of the display miniport driver to perform display operations without dedicated GPU hardware support.

## Remarks

The D3DDDI_VIDEO_PRESENT_SOURCE_ID and D3DDDI_VIDEO_PRESENT_TARGET_ID data types are defined in *D3dukmdt.h*.

Video present source identifiers are assigned by the operating system. [**DxgkDdiStartDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device), implemented by the display miniport driver, returns the number N of video present sources supported by the display adapter. Then the operating system assigns identifiers 0, 1, 2, ... N - 1.

Video present target identifiers are assigned by the display miniport driver. [**DxgkDdiQueryChildRelations**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_child_relations), implemented by the display miniport driver, returns an array of [**DXGK_CHILD_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_child_descriptor) structures, each of which contains an identifier.

For more information about video present sources and targets, see [Introduction to Video Present Networks](https://learn.microsoft.com/windows-hardware/drivers/display/introduction-to-video-present-networks).

## See also

[**D3DKMDT_VIDEO_PRESENT_SOURCE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_video_present_source)

[**D3DKMDT_VIDEO_PRESENT_TARGET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_video_present_target)

[**D3DKMDT_VIDPN_HW_CAPABILITY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_hw_capability)

[**D3DKMDT_VIDPN_PRESENT_PATH**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_present_path)

[**DXGK_CHILD_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_child_descriptor)

[**DxgkDdiQueryChildRelations**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_child_relations)

[**DxgkDdiQueryVidPnHWCapability**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryvidpnhwcapability)

[**DxgkDdiStartDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device)