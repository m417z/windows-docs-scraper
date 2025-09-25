# _DXGK_ENUM_PIVOT structure

## Description

The DXGK_ENUM_PIVOT structure identifies either a video present source or a video present target as the enumeration pivot in a call to [DxgkDdiEnumVidPnCofuncModality](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_enumvidpncofuncmodality).

## Members

### `VidPnSourceId`

If the pivot of the enumeration is a video present source, this member is the identifier of that source.

### `VidPnTargetId`

If the pivot of the enumeration is a video present target, this member is the identifier of that target.

## Remarks

The **EnumPivot** member of the [DXGKARG_ENUMVIDPNCOFUNCMODALITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_enumvidpncofuncmodality) structure is a DXGK_ENUM_PIVOT structure.

The **EnumPivotType** member of the [DXGKARG_ENUMVIDPNCOFUNCMODALITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_enumvidpncofuncmodality) structure is a value from the [D3DKMDT_ENUMCOFUNCMODALITY_PIVOT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_d3dkmdt_enumcofuncmodality_pivot_type) enumeration that specifies the pivot type (for example, video present source, video present target, rotation transformation, or scaling transformation).