# D3D12DDI_D3D12_OPTIONS_DATA_0031 structure

## Description

Display options data.

## Members

### `ResourceBindingTier`

Resource binding tier.

### `ConservativeRasterizationTier`

Conservative rasterization tier.

### `TiledResourcesTier`

Tiled resources tier.

### `CrossNodeSharingTier`

Cross node sharing tier.

### `VPAndRTArrayIndexFromAnyShaderFeedingRasterizerSupportedWithoutGSEmulation`

VP and RT array index from any shader feeding rasterizer supported without GS emulation.

### `OutputMergerLogicOp`

Output merger logic option.

### `ResourceHeapTier`

Resource heap tier.

### `DepthBoundsTestSupported`

Depth bounds test supported.

### `ProgrammableSamplePositionsTier`

Programmable sample positions tier.

### `CopyQueueTimestampQueriesSupported`

Copy queue timestamp queries are supported.

## Remarks

For UMDs that support the 0031 (or greater) DDI build, the runtime will query whether the UMD supports timestamps queries on the Copy Queue.

The core runtime will fail if [CreateQueryHeap](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_create_query_heap_0001) fails for D3D12_QUERY_HEAP_TYPE_COPY_QUEUE_TIMESTAMP in [D3D12DDI_QUERY_HEAP_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_query_heap_type) when the driver has not reported support.

The core runtime will no longer remove the command list in response to EndQuery or [ResolveQueryData](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_resolve_query_data), that is being called on a Copy command list. The debug layer will have a warning, however, if:

* A COPY_QUEUE_TIMESTAMP query is issued/resolved on a COPY command list when the UMD has not set the CAP indicating support.
* A COPY_QUEUE_TIMESTAMP query is issued/resolved on a command list type other than COPY.

The runtime allows ID3D12CommandQueue::GetClockCalibration/GetTimestampFrequency on Copy command queues when the capability are set. This API should return timestamps that correspond to what the Copy engine will emit, which in turn should be on the same GPU timeline/frequency with what the existing 3D/Compute engines emit.