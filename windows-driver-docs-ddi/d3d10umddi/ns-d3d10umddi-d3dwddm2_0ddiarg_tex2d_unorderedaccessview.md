## Description

the **D3DWDDM2_0DDIARG_TEX2D_UNORDEREDACCESSVIEW** structure describes a 2D texture that is used to create an unordered access view in a call to [**CreateUnorderedAccessView (WDDM 2.0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3dwddm2_0ddi_createunorderedaccessview).

## Members

### `MipSlice`

[in] The identifier of the MIP-map slice.

### `FirstArraySlice`

[in] The identifier of the first array slice.

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

[**CalcPrivateUnorderedAccessViewSize (WDDM 2.0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3dwddm2_0ddi_calcprivateunorderedaccessviewsize)

[**CreateUnorderedAccessView (WDDM 2.0)**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3dwddm2_0ddi_createunorderedaccessview)

[**D3DWDDM2_0DDIARG_CREATEUNORDEREDACCESSVIEW**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm2_0ddiarg_createunorderedaccessview)