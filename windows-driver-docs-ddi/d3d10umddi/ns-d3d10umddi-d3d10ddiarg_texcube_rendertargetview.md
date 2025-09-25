# D3D10DDIARG_TEXCUBE_RENDERTARGETVIEW structure

## Description

The D3D10DDIARG_TEXCUBE_RENDERTARGETVIEW structure describes a cube texture that is used to create a render target view in a call to the [CreateRenderTargetView](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createrendertargetview) function.

## Members

### `MipSlice` [in]

The identifier of the MIP-map slice.

### `FirstArraySlice` [in]

The identifier of the first array slice.

### `ArraySize` [in]

The number of array slices for the texture.

## See also

[CalcPrivateRenderTargetViewSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_calcprivaterendertargetviewsize)

[CreateRenderTargetView](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createrendertargetview)

[D3D10DDIARG_CREATERENDERTARGETVIEW](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_createrendertargetview)