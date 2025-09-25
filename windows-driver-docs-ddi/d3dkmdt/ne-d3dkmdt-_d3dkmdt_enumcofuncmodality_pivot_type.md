# _D3DKMDT_ENUMCOFUNCMODALITY_PIVOT_TYPE enumeration

## Description

The D3DKMDT_ENUMCOFUNCMODALITY_PIVOT_TYPE enumeration indicates the pivot type in a call to [DxgkDdiEnumVidPnCofuncModality](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_enumvidpncofuncmodality).

## Constants

### `D3DKMDT_EPT_UNINITIALIZED`

Indicates that a variable of type D3DKMDT_ENUMCOFUNCMODALITY_PIVOT_TYPE has not yet been assigned a meaningful value.

### `D3DKMDT_EPT_VIDPNSOURCE`

Indicates that a video present source is the pivot of the enumeration.

### `D3DKMDT_EPT_VIDPNTARGET`

Indicates that a video present target is the pivot of the enumeration.

### `D3DKMDT_EPT_SCALING`

Indicates that the scaling transformation is the pivot of the enumeration.

### `D3DKMDT_EPT_ROTATION`

Indicates that the rotation transformation is the pivot of the enumeration.

### `D3DKMDT_EPT_NOPIVOT`

Indicates that the enumeration has no pivot.

## Remarks

The **EnumPivotType** member of the [DXGKARG_ENUMVIDPNCOFUNCMODALITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_enumvidpncofuncmodality) structure is a D3DKMDT_ENUMCOFUNCMODALITY_PIVOT_TYPE value.

## See also

[DxgkDdiEnumVidPnCofuncModality](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_enumvidpncofuncmodality)