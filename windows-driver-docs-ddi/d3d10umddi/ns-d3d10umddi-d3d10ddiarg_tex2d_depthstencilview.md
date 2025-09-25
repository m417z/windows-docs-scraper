# D3D10DDIARG_TEX2D_DEPTHSTENCILVIEW structure

## Description

The D3D10DDIARG_TEX2D_DEPTHSTENCILVIEW structure describes a two-dimensional (2-D) texture that is used to create a depth stencil view in a call to the [CreateDepthStencilView](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createdepthstencilview) function.

## Members

### `MipSlice` [in]

The identifier of the MIP-map slice.

### `FirstArraySlice` [in]

The identifier of the first array slice.

### `ArraySize` [in]

The number of array slices for the texture.

## See also

[CalcPrivateDepthStencilViewSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_calcprivatedepthstencilviewsize)

[CreateDepthStencilView](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createdepthstencilview)

[D3D10DDIARG_CREATEDEPTHSTENCILVIEW](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_createdepthstencilview)