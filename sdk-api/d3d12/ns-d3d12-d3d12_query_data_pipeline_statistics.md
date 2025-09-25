# D3D12_QUERY_DATA_PIPELINE_STATISTICS structure

## Description

Query information about graphics-pipeline activity in between calls to [BeginQuery](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12graphicscommandlist-beginquery) and [EndQuery](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12graphicscommandlist-endquery).

## Members

### `IAVertices`

Number of vertices read by input assembler.

### `IAPrimitives`

Number of primitives read by the input assembler. This number can be different depending on the primitive topology used. For example, a triangle strip with 6 vertices will produce 4 triangles, however a triangle list with 6 vertices will produce 2 triangles.

### `VSInvocations`

Specifies the number of vertex shader invocations. Direct3D invokes the vertex shader once per vertex.

### `GSInvocations`

Specifies the number of geometry shader invocations. When the geometry shader is set to NULL, this statistic may or may not increment depending on the graphics adapter.

### `GSPrimitives`

Specifies the number of geometry shader output primitives.

### `CInvocations`

Number of primitives that were sent to the rasterizer. When the rasterizer is disabled, this will not increment.

### `CPrimitives`

Number of primitives that were rendered. This may be larger or smaller than CInvocations because after a primitive is clipped sometimes it is either broken up into more than one primitive or completely culled.

### `PSInvocations`

Specifies the number of pixel shader invocations.

### `HSInvocations`

Specifies the number of hull shader invocations.

### `DSInvocations`

Specifies the number of domain shader invocations.

### `CSInvocations`

Specifies the number of compute shader invocations.

## Remarks

Use this structure with [D3D12_QUERY_HEAP_TYPE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_query_heap_type) and [CreateQueryHeap](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device-createqueryheap).

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)