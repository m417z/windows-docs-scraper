# D3D12_FEATURE_DATA_D3D12_OPTIONS structure

## Description

Describes Direct3D 12 feature options in the current graphics driver.

## Members

### `DoublePrecisionFloatShaderOps`

Specifies whether **double** types are allowed for shader operations.
If **TRUE**, double types are allowed; otherwise **FALSE**.
The supported operations are equivalent to Direct3D 11's **ExtendedDoublesShaderInstructions** member of the [D3D11_FEATURE_DATA_D3D11_OPTIONS](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_feature_data_d3d11_options) structure.

To use any HLSL shader that is compiled with a **double** type,
the runtime must set **DoublePrecisionFloatShaderOps** to **TRUE**.

### `OutputMergerLogicOp`

Specifies whether logic operations are available in blend state. The runtime sets this member to **TRUE** if logic operations are available in blend state and **FALSE** otherwise. This member is **FALSE** for feature level 9.1, 9.2, and 9.3. This member is optional for feature level 10, 10.1, and 11. This member is **TRUE** for feature level 11.1 and 12.

### `MinPrecisionSupport`

A combination of [D3D12_SHADER_MIN_PRECISION_SUPPORT](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_shader_min_precision_support)-typed values that are combined by using a bitwise OR operation. The resulting value specifies minimum precision levels that the driver supports for shader stages. A value of zero indicates that the driver supports only full 32-bit precision for all shader stages.

### `TiledResourcesTier`

Specifies whether the hardware and driver support tiled resources. The runtime sets this member to a [D3D12_TILED_RESOURCES_TIER](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_tiled_resources_tier)-typed value that indicates if the hardware and driver support tiled resources and at what tier level.

### `ResourceBindingTier`

Specifies the level at which the hardware and driver support resource binding. The runtime sets this member to a [D3D12_RESOURCE_BINDING_TIER](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_resource_binding_tier)-typed value that indicates the tier level.

### `PSSpecifiedStencilRefSupported`

Specifies whether pixel shader stencil ref is supported. If **TRUE**, it's supported; otherwise **FALSE**.

### `TypedUAVLoadAdditionalFormats`

Specifies whether the loading of additional formats for typed unordered-access views (UAVs) is supported.
If **TRUE**, it's supported; otherwise **FALSE**.

### `ROVsSupported`

Specifies whether [Rasterizer Order Views](https://learn.microsoft.com/windows/desktop/direct3d12/directx-12-glossary) (ROVs) are supported. If **TRUE**, they're supported; otherwise **FALSE**.

### `ConservativeRasterizationTier`

Specifies the level at which the hardware and driver support conservative rasterization. The runtime sets this member to a [D3D12_CONSERVATIVE_RASTERIZATION_TIER](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_conservative_rasterization_tier)-typed value that indicates the tier level.

### `MaxGPUVirtualAddressBitsPerResource`

Don't use this field; instead, use the [D3D12_FEATURE_DATA_GPU_VIRTUAL_ADDRESS_SUPPORT](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_feature_data_gpu_virtual_address_support) query
(a structure with a **MaxGPUVirtualAddressBitsPerResource** member), which is more accurate.

### `StandardSwizzle64KBSupported`

TRUE if the hardware supports textures with the 64KB standard swizzle pattern.
Support for this pattern enables zero-copy texture optimizations while providing near-equilateral locality for each dimension within the texture.
For texture swizzle options and restrictions, see [D3D12_TEXTURE_LAYOUT](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_texture_layout).

### `CrossNodeSharingTier`

A [D3D12_CROSS_NODE_SHARING_TIER](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_cross_node_sharing_tier) enumeration constant that specifies the level of sharing across nodes of an adapter that has multiple nodes,
such as Tier 1 Emulated, Tier 1, or Tier 2.

### `CrossAdapterRowMajorTextureSupported`

FALSE means the device only supports copy operations to and from cross-adapter row-major textures.
TRUE means the device supports shader resource views, unordered access views, and render target views of cross-adapter row-major textures.
"Cross-adapter" means between multiple adapters (even from different IHVs).

### `VPAndRTArrayIndexFromAnyShaderFeedingRasterizerSupportedWithoutGSEmulation`

Whether the viewport (VP) and Render Target (RT) array index from any shader feeding the rasterizer are supported without geometry shader emulation.
Compare the **VPAndRTArrayIndexFromAnyShaderFeedingRasterizer** member of the [D3D11_FEATURE_DATA_D3D11_OPTIONS3](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_feature_data_d3d11_options3) structure.
In [ID3D12ShaderReflection::GetRequiresFlags](https://learn.microsoft.com/windows/desktop/api/d3d12shader/nf-d3d12shader-id3d12shaderreflection-getrequiresflags), see the #define D3D_SHADER_REQUIRES_VIEWPORT_AND_RT_ARRAY_INDEX_FROM_ANY_SHADER_FEEDING_RASTERIZER.

### `ResourceHeapTier`

Specifies the level at which the hardware and driver require heap attribution related to resource type.
The runtime sets this member to a [D3D12_RESOURCE_HEAP_TIER](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_resource_heap_tier) enumeration constant.

## Remarks

See [D3D12_FEATURE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_feature).

## See also

[Conservative Rasterization](https://learn.microsoft.com/windows/desktop/direct3d12/conservative-rasterization)

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)

[D3D12_FEATURE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_feature)

[Rasterizer Ordered Views](https://learn.microsoft.com/windows/desktop/direct3d12/rasterizer-order-views)