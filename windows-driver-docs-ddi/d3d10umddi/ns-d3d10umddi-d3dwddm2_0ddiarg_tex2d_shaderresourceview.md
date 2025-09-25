## Description

The **D3DWDDM2_0DDIARG_TEX2D_SHADERRESOURCEVIEW** structure describes a two-dimensional (2-D) texture that is used to create a shader resource view in a call to [**CreateShaderResourceView**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3dwddm2_0ddi_createshaderresourceview).

## Members

### `MostDetailedMip`

[in] The identifier of the most detailed MIP-map.

### `FirstArraySlice`

[in] The identifier of the first array slice.

### `MipLevels`

[in] The number of MIP-map levels for the texture.

### `ArraySize`

[in] The number of array slices for the texture.

### `PlaneSlice`

[in] The identifier of the plane slice.

### `PlaneIndex`

[in] The index (plane slice number) of the plane to use in the texture.

## Remarks

If **MipLevels** is set to -1, the MIP-maps in the texture start from the MIP-map that is set in the **MostDetailedMip** member.

If **ArraySize** is set to -1, the array slices in the texture start from the array slice that is set in **FirstArraySlice** member.

## See also

[**CalcPrivateShaderResourceViewSize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3dwddm2_0ddi_calcprivateshaderresourceviewsize)

[**CreateShaderResourceView**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3dwddm2_0ddi_createshaderresourceview)

[**D3DWDDM2_0DDIARG_CREATESHADERRESOURCEVIEW**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm2_0ddiarg_createshaderresourceview)