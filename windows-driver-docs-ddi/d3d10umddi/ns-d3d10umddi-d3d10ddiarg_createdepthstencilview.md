# D3D10DDIARG_CREATEDEPTHSTENCILVIEW structure

## Description

The **D3D10DDIARG_CREATEDEPTHSTENCILVIEW** structure describes the depth stencil view to create.

## Members

### `hDrvResource` [in]

A handle to the base depth stencil resource.

### `Format` [in]

A DXGI_FORMAT-typed value that indicates the pixel format of the depth stencil view.

### `ResourceDimension` [in]

A [**D3D10DDIRESOURCE_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10ddiresource_type)-typed value that indicates the resource type and dimensionality of the base resource.

### `Tex1D` [in]

If the value in the **ResourceDimension** member is set to D3D10DDIRESOURCE_TEXTURE1D, a member in the union that is contained in D3D10DDIARG_CREATEDEPTHSTENCILVIEW that can hold a [**D3D10DDIARG_TEX1D_DEPTHSTENCILVIEW**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_tex1d_depthstencilview) structure for a one-dimensional texture.

### `Tex2D` [in]

If the value in the **ResourceDimension** member is set to D3D10DDIRESOURCE_TEXTURE2D, a member in the union that is contained in D3D10DDIARG_CREATEDEPTHSTENCILVIEW that can hold a [**D3D10DDIARG_TEX2D_DEPTHSTENCILVIEW**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_tex2d_depthstencilview) structure for a two-dimensional texture.

### `TexCube` [in]

If the value in the **ResourceDimension** member is set to D3D10DDIRESOURCE_TEXTURECUBE, a member in the union that is contained in D3D10DDIARG_CREATEDEPTHSTENCILVIEW that can hold a [**D3D10DDIARG_TEXCUBE_DEPTHSTENCILVIEW**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_texcube_depthstencilview) structure for a cube texture.

## See also

[**CalcPrivateDepthStencilViewSize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_calcprivatedepthstencilviewsize)

[**CreateDepthStencilView**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createdepthstencilview)

[**D3D10DDIARG_TEX1D_DEPTHSTENCILVIEW**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_tex1d_depthstencilview)

[**D3D10DDIARG_TEX2D_DEPTHSTENCILVIEW**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_tex2d_depthstencilview)

[**D3D10DDIARG_TEXCUBE_DEPTHSTENCILVIEW**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_texcube_depthstencilview)

[**D3D10DDIRESOURCE_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10ddiresource_type)