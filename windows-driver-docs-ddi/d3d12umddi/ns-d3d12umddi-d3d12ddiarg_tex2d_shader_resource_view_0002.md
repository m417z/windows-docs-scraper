# D3D12DDIARG_TEX2D_SHADER_RESOURCE_VIEW_0002 structure

## Description

Describes a two-dimensional (2-D) texture that is used to create a shader resource view.

## Members

### `MostDetailedMip`

The identifier of the most detailed MIP-map.

### `FirstArraySlice`

The identifier of the first array slice.

### `MipLevels`

The number of MIP-map levels for the texture.

### `ArraySize`

The number of array slices for the texture.

### `PlaneSlice`

The index (plane slice number) of the plane to use in the texture.

### `ResourceMinLODClamp`

A value to clamp sample LOD values to. For example, if you specify 2.0f for the clamp value, you ensure that no individual sample accesses a mip level less than 2.0f.

## Remarks

## See also