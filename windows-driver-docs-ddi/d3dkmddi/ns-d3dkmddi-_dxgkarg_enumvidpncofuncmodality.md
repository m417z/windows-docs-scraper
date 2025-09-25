# _DXGKARG_ENUMVIDPNCOFUNCMODALITY structure

## Description

The DXGKARG_ENUMVIDPNCOFUNCMODALITY structure contains arguments for the [DxgkDdiEnumVidPnCofuncModality](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_enumvidpncofuncmodality) function. The *DxgkDdiEnumVidPnCofuncModality* function makes the source and target mode sets of a VidPN cofunctional with the VidPN's topology and the modes that have already been pinned.

## Members

### `hConstrainingVidPn`

A handle to the VidPn object for which the cofunctional modes are being requested.

### `EnumPivotType`

A [D3DKMDT_ENUMCOFUNCMODALITY_PIVOT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_d3dkmdt_enumcofuncmodality_pivot_type) enumerator that supplies the enumeration pivot type.

### `EnumPivot`

A [DXGK_ENUM_PIVOT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_enum_pivot) structure.

## Remarks

If a particular video present source or target is designated as the pivot of the enumeration, then *DxgkDdiEnumVidPnCofuncModality* must not change the mode set for that source or target.

The D3DKMDT_HVIDPN data type is defined in *D3dkmdt.h*. The D3DDDI_VIDEO_PRESENT_SOURCE_ID and D3DDDI_VIDEO_PRESENT_TARGET_ID data types are defined in *D3dukmdt.h*.

## See also

[D3DKMDT_ENUMCOFUNCMODALITY_PIVOT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_d3dkmdt_enumcofuncmodality_pivot_type)

[DXGK_ENUM_PIVOT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_enum_pivot)

[DxgkDdiEnumVidPnCofuncModality](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_enumvidpncofuncmodality)