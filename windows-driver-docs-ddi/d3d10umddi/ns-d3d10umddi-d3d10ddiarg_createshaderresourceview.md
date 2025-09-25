# D3D10DDIARG_CREATESHADERRESOURCEVIEW structure

## Description

The **D3D10DDIARG_CREATESHADERRESOURCEVIEW** structure describes the shader resource view to create.

## Members

### `hDrvResource` [in]

A handle to the shader resource.

### `Format` [in]

A DXGI_FORMAT-typed value that indicates the pixel format of the view.

### `ResourceDimension` [in]

A [**D3D10DDIRESOURCE_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10ddiresource_type)-typed value that indicates the resource type and dimensionality.

### `Buffer` [in]

If the value in the **ResourceDimension** member is set to D3D10DDIRESOURCE_BUFFER, a member in the union that is contained in D3D10DDIARG_CREATESHADERRESOURCEVIEW that can hold a [**D3D10DDIARG_BUFFER_SHADERRESOURCEVIEW**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_buffer_shaderresourceview) structure for a buffer.

### `Tex1D` [in]

If the value in the **ResourceDimension** member is set to D3D10DDIRESOURCE_TEXTURE1D, a member in the union that is contained in D3D10DDIARG_CREATESHADERRESOURCEVIEW that can hold a [**D3D10DDIARG_TEX1D_SHADERRESOURCEVIEW**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_tex1d_shaderresourceview) structure for a one-dimensional texture.

### `Tex2D` [in]

If the value in the **ResourceDimension** member is set to D3D10DDIRESOURCE_TEXTURE2D, a member in the union that is contained in D3D10DDIARG_CREATESHADERRESOURCEVIEW that can hold a [**D3D10DDIARG_TEX2D_SHADERRESOURCEVIEW**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_tex2d_shaderresourceview) structure for a two-dimensional texture.

### `Tex3D` [in]

If the value in the **ResourceDimension** member is set to D3D10DDIRESOURCE_TEXTURE3D, a member in the union that is contained in D3D10DDIARG_CREATESHADERRESOURCEVIEW that can hold a [**D3D10DDIARG_TEX3D_SHADERRESOURCEVIEW**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_tex3d_shaderresourceview) structure for a three-dimensional texture.

### `TexCube` [in]

If the value in the **ResourceDimension** member is set to D3D10DDIRESOURCE_TEXTURECUBE, a member in the union that is contained in D3D10DDIARG_CREATESHADERRESOURCEVIEW that can hold a [**D3D10DDIARG_TEXCUBE_SHADERRESOURCEVIEW**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_texcube_shaderresourceview) structure for a cube texture.

## See also

[**CalcPrivateShaderResourceViewSize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_calcprivateshaderresourceviewsize)

[**CreateShaderResourceView**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createshaderresourceview)

[**D3D10DDIARG_BUFFER_SHADERRESOURCEVIEW**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_buffer_shaderresourceview)

[**D3D10DDIARG_TEX1D_SHADERRESOURCEVIEW**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_tex1d_shaderresourceview)

[**D3D10DDIARG_TEX2D_SHADERRESOURCEVIEW**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_tex2d_shaderresourceview)

[**D3D10DDIARG_TEX3D_SHADERRESOURCEVIEW**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_tex3d_shaderresourceview)

[**D3D10DDIARG_TEXCUBE_SHADERRESOURCEVIEW**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_texcube_shaderresourceview)

[**D3D10DDIRESOURCE_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10ddiresource_type)