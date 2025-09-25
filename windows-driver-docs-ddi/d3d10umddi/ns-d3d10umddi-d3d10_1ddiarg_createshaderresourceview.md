# D3D10_1DDIARG_CREATESHADERRESOURCEVIEW structure

## Description

The **D3D10_1DDIARG_CREATESHADERRESOURCEVIEW** structure describes the shader resource view to create.

## Members

### `hDrvResource` [in]

A handle to the shader resource.

### `Format` [in]

A DXGI_FORMAT-typed value that indicates the pixel format of the view.

### `ResourceDimension` [in]

A [**D3D10DDIRESOURCE_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10ddiresource_type)-typed value that indicates the resource type and dimensionality.

### `Buffer` [in]

If the value in the **ResourceDimension** member is set to D3D10DDIRESOURCE_BUFFER, a member in the union that is contained in D3D10_1DDIARG_CREATESHADERRESOURCEVIEW that can hold a [**D3D10DDIARG_BUFFER_SHADERRESOURCEVIEW**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_buffer_shaderresourceview) structure for a buffer.

### `Tex1D` [in]

If the value in the **ResourceDimension** member is set to D3D10DDIRESOURCE_TEXTURE1D, a member in the union that is contained in D3D10_1DDIARG_CREATESHADERRESOURCEVIEW that can hold a [**D3D10DDIARG_TEX1D_SHADERRESOURCEVIEW**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_tex1d_shaderresourceview) structure for a one-dimensional texture.

### `Tex2D` [in]

If the value in the **ResourceDimension** member is set to D3D10DDIRESOURCE_TEXTURE2D, a member in the union that is contained in D3D10_1DDIARG_CREATESHADERRESOURCEVIEW that can hold a [**D3D10DDIARG_TEX2D_SHADERRESOURCEVIEW**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_tex2d_shaderresourceview) structure for a two-dimensional texture.

### `Tex3D` [in]

If the value in the **ResourceDimension** member is set to D3D10DDIRESOURCE_TEXTURE3D, a member in the union that is contained in D3D10_1DDIARG_CREATESHADERRESOURCEVIEW that can hold a [**D3D10DDIARG_TEX3D_SHADERRESOURCEVIEW**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_tex3d_shaderresourceview) structure for a three-dimensional texture.

### `TexCube` [in]

If the value in the **ResourceDimension** member is set to D3D10DDIRESOURCE_TEXTURECUBE, a member in the union that is contained in D3D10_1DDIARG_CREATESHADERRESOURCEVIEW that can hold a [**D3D10DDIARG_TEXCUBE_SHADERRESOURCEVIEW**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_texcube_shaderresourceview) structure for a cube texture.

## Remarks

[**CreateShaderResourceView(D3D10_1)**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10_1ddi_createshaderresourceview) has a major functionality difference from the Direct3D 10.0 version (that is,[**CreateShaderResourceView**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createshaderresourceview)) in regard to the **ResourceDimension** member of D3D10_1DDIARG_CREATESHADERRESOURCEVIEW. If the Direct3D runtime attempts to create a view on a shader resource, **CreateShaderResourceView** requires that the **ResourceDimension** member of [**D3D10DDIARG_CREATESHADERRESOURCEVIEW**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_createshaderresourceview) match the **ResourceDimension** member of [**D3D10DDIARG_CREATERESOURCE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_createresource) for the shader resource that was created in a call to the driver's [**CreateResource(D3D10)**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createresource) function. If the Direct3D 10.1 runtime attempts to create a view on a shader resource, **CreateShaderResourceView(D3D10_1)** allows a slight relaxation for its **ResourceDimension** member. **CreateShaderResourceView(D3D10_1)** allows the creation of Tex2D views on TexCube resources. In addition, the distinction between TexCube at the resource level is gone in Direct3D version 10.1. **CreateShaderResourceView(D3D10_1)** only represents whether it can create a TexCube view. In Direct3D version 10.0, copying a resource, validation of a multiple render target, and so on (that is, various operations that required the resource type to be identical) all included the distinction of TexCube to factor into the resource type. In Direct3D version 10.1, the runtime can determine only Tex2D.

## See also

[**CalcPrivateShaderResourceViewSize(D3D10_1)**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10_1ddi_calcprivateshaderresourceviewsize)

[**CreateShaderResourceView(D3D10_1)**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10_1ddi_createshaderresourceview)

[**D3D10DDIARG_BUFFER_SHADERRESOURCEVIEW**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_buffer_shaderresourceview)

[**D3D10DDIARG_TEX1D_SHADERRESOURCEVIEW**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_tex1d_shaderresourceview)

[**D3D10DDIARG_TEX2D_SHADERRESOURCEVIEW**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_tex2d_shaderresourceview)

[**D3D10DDIARG_TEX3D_SHADERRESOURCEVIEW**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_tex3d_shaderresourceview)

[**D3D10DDIARG_TEXCUBE_SHADERRESOURCEVIEW**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_texcube_shaderresourceview)

[**D3D10DDIRESOURCE_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10ddiresource_type)