# D3D11_TILED_RESOURCES_TIER enumeration

## Description

Indicates the tier level at which tiled resources are supported.

## Constants

### `D3D11_TILED_RESOURCES_NOT_SUPPORTED:0`

Tiled resources are not supported.

### `D3D11_TILED_RESOURCES_TIER_1:1`

Tier_1 tiled resources are supported.

The device supports calls to [CreateTexture2D](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11device-createtexture2d) and so on with the [D3D11_RESOURCE_MISC_TILED](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_resource_misc_flag) flag.

The device supports calls to [CreateBuffer](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11device-createbuffer) with the [D3D11_RESOURCE_MISC_TILE_POOL](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_resource_misc_flag) flag.

If you access tiles (read or write) that are **NULL**-mapped, you get undefined behavior, which includes device-removed. Apps can map all tiles to a single "default" tile to avoid this condition.

### `D3D11_TILED_RESOURCES_TIER_2:2`

Tier_2 tiled resources are supported.

Superset of Tier_1 functionality, which includes this additional support:

* On Tier_1, if the size of a texture mipmap level is an integer multiple of the standard tile shape for its format, it is guaranteed to be nonpacked. On Tier_2, this guarantee is expanded to include mipmap levels whose size is at least one standard tile shape.
  For more info, see [D3D11_PACKED_MIP_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11_2/ns-d3d11_2-d3d11_packed_mip_desc).
* Shader instructions are available for clamping level-of-detail (LOD) and for obtaining status about the shader operation. For info about one of these shader instructions, see [Sample(S,float,int,float,uint)](https://learn.microsoft.com/windows/desktop/direct3dhlsl/sample-s-float--int-uint-).
* Reading from **NULL**-mapped tiles treat that sampled value as zero. Writes to **NULL**-mapped tiles are discarded.

### `D3D11_TILED_RESOURCES_TIER_3:3`

Tier_3 tiled resources are supported.

Superset of Tier_2 functionality, Tier 3 is essentially Tier 2 but with the additional support of Texture3D for Tiled Resources.

## See also

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-d3d11-core-enums)

[D3D11_FEATURE_DATA_D3D11_OPTIONS1](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_feature_data_d3d11_options1)