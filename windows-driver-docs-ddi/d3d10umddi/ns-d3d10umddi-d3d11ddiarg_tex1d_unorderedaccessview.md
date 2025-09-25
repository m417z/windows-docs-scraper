# D3D11DDIARG_TEX1D_UNORDEREDACCESSVIEW structure

## Description

The D3D11DDIARG_TEX1D_UNORDEREDACCESSVIEW structure describes a one-dimensional texture (1-D) that is used to create an unordered access view in a call to the [CreateUnorderedAccessView](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_createunorderedaccessview) function.

## Members

### `MipSlice` [in]

The identifier of the MIP-map slice.

### `FirstArraySlice` [in]

The identifier of the first array slice.

### `ArraySize` [in]

The number of array slices for the texture.

## See also

[CalcPrivateUnorderedAccessViewSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_calcprivateunorderedaccessviewsize)

[CreateUnorderedAccessView](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_createunorderedaccessview)

[D3D11DDIARG_CREATEUNORDEREDACCESSVIEW](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddiarg_createunorderedaccessview)