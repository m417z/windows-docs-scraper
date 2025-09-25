# _DXVAHDDDI_FILTER enumeration

## Description

The DXVAHDDDI_FILTER enumeration contains values that identify the filter range, which the driver should retrieve when the driver's [GetCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getcaps) function is called with the D3DDDICAPS_DXVAHD_GETVPFILTERRANGE value set.

## Constants

### `DXVAHDDDI_FILTER_BRIGHTNESS`

A value that specifies the filter range of the brightness ProcAmp.

### `DXVAHDDDI_FILTER_CONTRAST`

A value that specifies the filter range of the contrast ProcAmp.

### `DXVAHDDDI_FILTER_HUE`

A value that specifies the filter range of the hue ProcAmp.

### `DXVAHDDDI_FILTER_SATURATION`

A value that specifies the filter range of the saturation ProcAmp.

### `DXVAHDDDI_FILTER_NOISE_REDUCTION`

A value that specifies the filter range of the noise reduction filter.

### `DXVAHDDDI_FILTER_EDGE_ENHANCEMENT`

A value that specifies the filter range of the edge enhancement filter.

### `DXVAHDDDI_FILTER_ANAMORPHIC_SCALING`

A value that specifies that the filter range of anamorphic scaling.

## See also

[GetCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getcaps)