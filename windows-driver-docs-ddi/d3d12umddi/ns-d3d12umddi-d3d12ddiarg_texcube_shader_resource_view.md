# D3D12DDIARG_TEXCUBE_SHADER_RESOURCE_VIEW structure

## Description

Describes the subresources from an array of cube textures to use in a shader-resource view.

## Members

### `MostDetailedMip`

The identifier of the most detailed MIP-map.

### `MipLevels`

The number of MIP-map levels for the texture.

### `First2DArrayFace`

Index of the first 2D texture to use.

### `NumCubes`

Number of cube textures in the array.

### `ResourceMinLODClamp`

A value to clamp sample LOD values to. For example, if you specify 2.0f for the clamp value, you ensure that no individual sample accesses a mip level less than 2.0f.

## Remarks

## See also