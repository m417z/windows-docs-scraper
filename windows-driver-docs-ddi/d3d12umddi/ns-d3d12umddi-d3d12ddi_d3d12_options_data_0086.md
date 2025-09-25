## Description

The **D3D12DDI_D3D12_OPTIONS_DATA_0086** structure describes the feature options supported by the driver/hardware in D3D12 Release 8, Build Revision 6.

## Members

### `ResourceBindingTier`

The [**D3D12DDI_RESOURCE_BINDING_TIER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_resource_binding_tier) value that identifies the [hardware tier level](https://learn.microsoft.com/windows/win32/direct3d12/hardware-support) that the driver supports.

### `ConservativeRasterizationTier`

The [**D3D12_CONSERVATIVE_RASTERIZATION_TIER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_conservative_rasterization_tier) value that identifies the supported tier level of conservative rasterization.

### `TiledResourcesTier`

The [**D3D12DDI_TILED_RESOURCES_TIER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_tiled_resources_tier) value that identifies the tier level at which tiled resources are supported.

### `CrossNodeSharingTier`

The [**D3D12DDI_CROSS_NODE_SHARING_TIER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_cross_node_sharing_tier) value indicating the level of sharing across nodes of a display adapter.

### `VPAndRTArrayIndexFromAnyShaderFeedingRasterizerSupportedWithoutGSEmulation`

Set TRUE when the viewport and render target array index from any shader feeding rasterizer is supported without geometry shader emulation; otherwise, set FALSE.

### `OutputMergerLogicOp`

Set TRUE when output merger logic operations are supported; otherwise, set FALSE.

### `ResourceHeapTier`

The [**D3D12DDI_RESOURCE_HEAP_TIER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_resource_heap_tier) value that indicates the resource heap tier supported by the driver and hardware.

### `DepthBoundsTestSupported`

Set TRUE when depth bounds testing is supported; otherwise, set FALSE.

### `ProgrammableSamplePositionsTier`

The [**D3D12DDI_PROGRAMMABLE_SAMPLE_POSITIONS_TIER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_programmable_sample_positions_tier) value indicating the supported programmable sample positions tier.

### `CopyQueueTimestampQueriesSupported`

Set TRUE when queue timestamp queries are supported; otherwise, set FALSE.

### `WriteBufferImmediateQueueFlags`

The [**D3D12DDI_COMMAND_QUEUE_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_command_queue_flags) value that identifies the flags for the command queue.

### `ViewInstancingTier`

The [**D3D12DDI_VIEW_INSTANCING_TIER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_view_instancing_tier) value that indicates the supported view instancing tier.

### `BarycentricsSupported`

Set TRUE when Barycentric coordinates are supported; otherwise, set FALSE.

### `ReservedBufferPlacementSupported`

Set TRUE when buffer placement is supported (only 64KB aligned MSAA support); otherwise, set FALSE.

### `Deterministic64KBUndefinedSwizzle`

Set TRUE when deterministic 64KB undefined swizzle is supported; otherwise, set FALSE.

### `SRVOnlyTiledResourceTier3`

Set TRUE when the hardware supports SRV-only sparse volume textures; otherwise, set FALSE.

### `RenderPassTier`

The [**D3D12DDI_RENDER_PASS_TIER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_render_pass_tier) value that indicates render pass tier supported by the driver.

### `RaytracingTier`

The [**D3D12DDI_RAYTRACING_TIER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_raytracing_tier) value that indicates the ray tracing tier supported by the hardware.

### `VariableShadingRateTier`

The [**D3D12DDI_VARIABLE_SHADING_RATE_TIER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_variable_shading_rate_tier) value that indicates the variable shading rate tier that the hardware supports.

### `PerPrimitiveShadingRateSupportedWithViewportIndexing`

Set TRUE when per primitive shading rate is supported with viewport indexing; otherwise, set FALSE.

### `AdditionalShadingRatesSupported`

Set TRUE if additional shading rates are supported; otherwise, set FALSE.

### `ShadingRateImageTileSize`

A UINT value that specifies the tile size of the screen-space image.

### `BackgroundProcessingSupported`

Set TRUE when the driver supports background processing; otherwise, set FALSE.

### `MeshShaderTier`

The [**D3D12DDI_MESH_SHADER_TIER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_mesh_shader_tier) that the device supports.

### `SamplerFeedbackTier`

The [**D3D12DDI_SAMPLER_FEEDBACK_TIER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_mesh_shader_tier) that the device supports.

### `DriverManagedShaderCachePresent`

Set TRUE when the driver supports shader cache management; otherwise, set FALSE. When set TRUE, the driver must provide a non-NULL [**PFND3D12DDI_IMPLICITSHADERCACHECONTROL_0080**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_implicitshadercachecontrol_0080) callback function.

### `MeshShaderSupportsFullRangeRenderTargetArrayIndex`

Set TRUE when the driver supports full render target array indexing; otherwise, set FALSE.

### `VariableRateShadingSumCombinerSupported`

Set TRUE when the driver supports the sum combiner for variable rate shading; otherwise, set FALSE.

### `MeshShaderPerPrimitiveShadingRateSupported`

Set TRUE when the SV_ShadingRate can be set from a mesh shader; otherwise, set FALSE.

### `MSPrimitivesPipelineStatisticIncludesCulledPrimitives`

Set TRUE when the driver supports culled primitives pipeline statistics; otherwise, set FALSE.

## Remarks

## See also

[**D3D12DDICAPS_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddicaps_type)

[**PFND3DDDI_GETCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getcaps)