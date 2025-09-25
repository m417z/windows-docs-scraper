## Description

A user-mode driver indicates support for capabilities in the **D3D12DDI_OPTIONS_DATA_0091** structure when its [**PFND3DDDI_GETCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getcaps) function is called with [**D3D12DDICAPS_TYPE_OPTIONS_0091**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddicaps_type).

## Members

### `UnrestrictedBufferTextureCopyPitchSupported`

Set TRUE when the driver supports unrestricted copy alignments. Otherwise, set to FALSE.

### `UnrestrictedVertexElementAlignmentSupported`

Set TRUE when the driver supports unrestricted vertex element alignment (potentially unaligned input element layouts). Otherwise, set to FALSE.

### `InvertedViewportHeightFlipsYSupported`

Set TRUE when the driver supports inverted viewports. Otherwise, set to FALSE.

### `InvertedViewportDepthFlipsZSupported`

Set TRUE when the driver supports inverted viewport. Otherwise, set to FALSE.

## See also

[**D3D12DDICAPS_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddicaps_type)

[**D3DDDIARG_GETCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_getcaps)

[**PFND3DDDI_GETCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getcaps)