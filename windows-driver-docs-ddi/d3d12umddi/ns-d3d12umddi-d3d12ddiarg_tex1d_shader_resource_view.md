# D3D12DDIARG_TEX1D_SHADER_RESOURCE_VIEW structure

## Description

Describes a one-dimensional (1-D) texture that is used to create a shader resource view.

## Members

### `MostDetailedMip`

The identifier of the most detailed MIP-map.

### `FirstArraySlice`

The identifier of the first array slice.

### `MipLevels`

The number of MIP-map levels for the texture.

### `ArraySize`

The number of array slices for the texture.

### `ResourceMinLODClamp`

A value to clamp sample LOD values to. For example, if you specify 2.0f for the clamp value, you ensure that no individual sample accesses a mip level less than 2.0f.

## Remarks

## See also