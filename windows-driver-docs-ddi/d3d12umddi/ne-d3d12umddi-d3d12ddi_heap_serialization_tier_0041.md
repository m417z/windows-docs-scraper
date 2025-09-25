# D3D12DDI_HEAP_SERIALIZATION_TIER_0041 enumeration

## Description

Defines the heap serialization tier.

## Constants

### `D3D12DDI_HEAP_SERIALIZATION_TIER_0041_0`

Tier level 0 indicates that there is no hardware support for heap serialization. GPU access to a buffer overlapping a texture is may divulge disjoint TBWC metadata representations.

### `D3D12DDI_HEAP_SERIALIZATION_TIER_0041_1`

Tier level 1 indicates that there is hardware support for heap serialization. Seamless Texture BandWidth Compression (TBWC) guarantees that textures are always observable in their parameterized swizzle representations, by overlapping resources. The Driver verifier will ensure resource serialization tier 2 in addition to heap serialization tier 1.