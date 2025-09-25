## Description

A user-mode driver indicates support for capabilities in the **D3D12DDI_OPTIONS_DATA_0090** structure when its [**PFND3DDDI_GETCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getcaps) function is called with [**D3D12DDICAPS_TYPE_OPTIONS_0090**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddicaps_type).

## Members

### `RelaxedFormatCastingSupported`

Set TRUE when the driver supports format list casting; otherwise, set to FALSE.

## See also

[**D3D12DDICAPS_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddicaps_type)

[**D3DDDIARG_GETCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_getcaps)

[**PFND3DDDI_GETCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getcaps)