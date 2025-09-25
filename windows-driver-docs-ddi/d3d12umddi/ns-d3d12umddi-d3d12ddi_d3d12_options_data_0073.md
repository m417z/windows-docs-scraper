## Description

Contains display options data supported by the driver/hardware.

## Members

### `ResourceBindingTier`

The [**D3D12DDI_RESOURCE_BINDING_TIER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_resource_binding_tier) value.

### `ConservativeRasterizationTier`

The [**D3D12_CONSERVATIVE_RASTERIZATION_TIER**](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_conservative_rasterization_tier) value.

### `TiledResourcesTier`

The [**D3D12DDI_TILED_RESOURCES_TIER**](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_tiled_resources_tier) value.

### `CrossNodeSharingTier`

The [**D3D12DDI_CROSS_NODE_SHARING_TIER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_cross_node_sharing_tier) value indicating the level of sharing across nodes of a display adapter.

### `VPAndRTArrayIndexFromAnyShaderFeedingRasterizerSupportedWithoutGSEmulation`

Set TRUE when VP and RT array index from any shader feeding rasterizer supported without GS emulation; otherwise, set FALSE.

### `OutputMergerLogicOp`

Set TRUE when output merger logic operations are supported; otherwise, set FALSE.

### `ResourceHeapTier`

The [**D3D12DDI_RESOURCE_HEAP_TIER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_resource_heap_tier) value.

### `DepthBoundsTestSupported`

Set TRUE when depth bounds testing is supported; otherwise, set FALSE.

### `ProgrammableSamplePositionsTier`

The **D3D12DDI_PROGRAMMABLE_SAMPLE_POSITIONS_TIER** value indicating the supported programmable sample positions tier.

### `CopyQueueTimestampQueriesSupported`

Set TRUE when queue timestamp queries are supported; otherwise, set FALSE.

### `WriteBufferImmediateQueueFlags`

The [**D3D12DDI_COMMAND_QUEUE_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_command_queue_flags) value for the video command queue.

### `ViewInstancingTier`

The [**D3D12DDI_VIEW_INSTANCING_TIER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_view_instancing_tier) value.

### `BarycentricsSupported`

Set TRUE when Barycentric coordinates are supported; otherwise, set FALSE.

### `ReservedBufferPlacementSupported`

Set TRUE when buffer placement is supported (only 64KB aligned MSAA support); otherwise, set FALSE.

### `Deterministic64KBUndefinedSwizzle`

Set TRUE when deterministic 64KB undefined swizzle is supported; otherwise, set FALSE.

### `SRVOnlyTiledResourceTier3`

Set TRUE when the hardware supports SRV-only sparse volume textures; otherwise, set FALSE.

### `RenderPassTier`

The [**D3D12DDI_RENDER_PASS_TIER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_render_pass_tier) that the hardware supports.

### `RaytracingTier`

The [**D3D12DDI_RAYTRACING_TIER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_raytracing_tier) that the hardware supports.

### `VariableShadingRateTier`

The [**D3D12DDI_VARIABLE_SHADING_RATE_TIER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_variable_shading_rate_tier) that the hardware supports.

### `PerPrimitiveShadingRateSupportedWithViewportIndexing`

Set TRUE when per primitive shading rate is supported with viewport indexing; otherwise, set FALSE.

### `AdditionalShadingRatesSupported`

Set TRUE if additional shading rates are supported; otherwise, set FALSE.

### `ShadingRateImageTileSize`

The tile size of the screen-space image.

### `BackgroundProcessingSupported`

Set TRUE when the driver supports background processing; otherwise, set FALSE.

### `MeshShaderTier`

The [**D3D12DDI_MESH_SHADER_TIER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_mesh_shader_tier) that the device supports.

### `SamplerFeedbackTier`

The [**D3D12DDI_SAMPLER_FEEDBACK_TIER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_mesh_shader_tier) that the device supports.

## Remarks

## See also