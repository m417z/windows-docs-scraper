## Description

The **D3DWDDM2_0DDIARG_CREATESHADERRESOURCEVIEW** structure describes a shader resource view.

## Members

### `hDrvResource`

[in] A handle to the shader resource.

### `Format`

[in] A [**DXGI_FORMAT**](https://learn.microsoft.com/windows/win32/api/dxgiformat/ne-dxgiformat-dxgi_format)-typed value that indicates the pixel format of the view.

### `ResourceDimension`

[in] A [**D3D10DDIRESOURCE_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10ddiresource_type)-typed value that indicates the resource type and dimensionality.

### `Buffer`

[in] If **ResourceDimension** is set to D3D10DDIRESOURCE_BUFFER, **Buffer** holds a [**D3D10DDIARG_BUFFER_SHADERRESOURCEVIEW**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_buffer_shaderresourceview) structure for a buffer.

### `Tex1D`

[in] If **ResourceDimension** is set to D3D10DDIRESOURCE_TEXTURE1D, holds a [**D3D10DDIARG_TEX1D_SHADERRESOURCEVIEW**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_tex1d_shaderresourceview) structure for a one-dimensional texture.

### `Tex2D`

[in] If **ResourceDimension** is set to D3D10DDIRESOURCE_TEXTURE2D, **Buffer** holds a [**D3DWDDM2_0DDIARG_TEX2D_SHADERRESOURCEVIEW**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm2_0ddiarg_tex2d_shaderresourceview) structure for a two-dimensional texture.

### `Tex3D`

[in] If **ResourceDimension** is set to D3D10DDIRESOURCE_TEXTURE3D, **Buffer** holds a [**D3D10DDIARG_TEX3D_SHADERRESOURCEVIEW**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_tex3d_shaderresourceview) structure for a three-dimensional texture.

### `TexCube`

[in] If **ResourceDimension** is set to D3D10DDIRESOURCE_TEXTURECUBE, **Buffer** holds a [**D3D10DDIARG_TEXCUBE_SHADERRESOURCEVIEW**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_texcube_shaderresourceview) structure for a cube texture.

### `BufferEx`

[in] If **ResourceDimension** is set to D3D11DDIRESOURCE_BUFFEREX, a **Buffer** holds a [**D3D11DDIARG_BUFFEREX_SHADERRESOURCEVIEW**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddiarg_bufferex_shaderresourceview) structure for a buffer.

## See also

[**CalcPrivateShaderResourceViewSize(WDDM 2.0)**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3dwddm2_0ddi_calcprivateshaderresourceviewsize)

[**CreateShaderResourceView(WDDM 2.0)**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3dwddm2_0ddi_createshaderresourceview)

[**D3D10DDIARG_BUFFER_SHADERRESOURCEVIEW**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_buffer_shaderresourceview)

[**D3D10DDIARG_TEX1D_SHADERRESOURCEVIEW**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_tex1d_shaderresourceview)

[**D3DWDDM2_0DDIARG_TEX2D_SHADERRESOURCEVIEW**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm2_0ddiarg_tex2d_shaderresourceview)

[**D3D10DDIARG_TEX3D_SHADERRESOURCEVIEW**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_tex3d_shaderresourceview)

[**D3D10DDIARG_TEXCUBE_SHADERRESOURCEVIEW**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_texcube_shaderresourceview)

[**D3D10DDIRESOURCE_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10ddiresource_type)

[**D3D11DDIARG_BUFFEREX_SHADERRESOURCEVIEW**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddiarg_bufferex_shaderresourceview)