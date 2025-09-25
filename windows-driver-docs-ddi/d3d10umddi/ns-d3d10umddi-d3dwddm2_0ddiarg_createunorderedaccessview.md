## Description

The **D3DWDDM2_0DDIARG_CREATEUNORDEREDACCESSVIEW** structure describes an unordered access view that is used to create a shader resource view in a call to [**CreateUnorderedAccessView (WDDM 2.0)**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3dwddm2_0ddi_createunorderedaccessview).

## Members

### `hDrvResource`

[in] A handle to the unordered access block.

### `Format`

[in] A [**DXGI_FORMAT**](https://learn.microsoft.com/windows/win32/api/dxgiformat/ne-dxgiformat-dxgi_format)-typed value that indicates the pixel format of the unordered access block.

### `ResourceDimension`

A [**D3D10DDIRESOURCE_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10ddiresource_type)-typed value that indicates the resource type and dimensionality of the unordered access block. The Direct3D runtime will never set **ResourceDimension** to D3D10DDIRESOURCE_TEXTURECUBE.

### `Buffer`

[in] If **ResourceDimension** is set to D3D10DDIRESOURCE_BUFFER, **Buffer** holds a [**D3D11DDIARG_BUFFER_UNORDEREDACCESSVIEW**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddiarg_buffer_unorderedaccessview) structure for a buffer.

### `Tex1D`

[in] If **ResourceDimension** is set to D3D10DDIRESOURCE_TEXTURE1D, **Tex1D** holds a [**D3D11DDIARG_TEX1D_UNORDEREDACCESSVIEW**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddiarg_tex1d_unorderedaccessview) structure for a one-dimensional texture.

### `Tex2D`

[in] If **ResourceDimension** is set to D3D10DDIRESOURCE_TEXTURE2D, **Tex2D** holds a [**D3DWDDM2_0DDIARG_TEX2D_UNORDEREDACCESSVIEW**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm2_0ddiarg_tex2d_unorderedaccessview) structure for a two-dimensional texture.

### `Tex3D`

[in] If **ResourceDimension** is set to D3D10DDIRESOURCE_TEXTURE3D, **Tex3D** holds a [**D3D11DDIARG_TEX3D_UNORDEREDACCESSVIEW**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddiarg_tex3d_unorderedaccessview) structure for a three-dimensional texture.

## See also

[**CalcPrivateShaderResourceViewSize (WDDM 2.0)**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3dwddm2_0ddi_calcprivateunorderedaccessviewsize)

[**CreateUnorderedAccessView (WDDM 2.0)**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3dwddm2_0ddi_createunorderedaccessview)

[**D3D10DDIRESOURCE_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10ddiresource_type)

[**D3D11DDIARG_BUFFER_UNORDEREDACCESSVIEW**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddiarg_buffer_unorderedaccessview)

[**D3D11DDIARG_TEX1D_UNORDEREDACCESSVIEW**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddiarg_tex1d_unorderedaccessview)

[**D3DWDDM2_0DDIARG_TEX2D_UNORDEREDACCESSVIEW**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm2_0ddiarg_tex2d_unorderedaccessview)

[**D3D11DDIARG_TEX3D_UNORDEREDACCESSVIEW**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddiarg_tex3d_unorderedaccessview)