# D3D10_QUERY_DATA_PIPELINE_STATISTICS structure

## Description

Query information about graphics-pipeline activity in between calls to [ID3D10Asynchronous::Begin](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10asynchronous-begin) and [ID3D10Asynchronous::End](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10asynchronous-end).

## Members

### `IAVertices`

Type: **[UINT64](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of vertices read by input assembler.

### `IAPrimitives`

Type: **[UINT64](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of primitives read by the input assembler. This number can be different depending on the primitive topology used. For example, a triangle strip with 6 vertices will produce 4 triangles, however a triangle list with 6 vertices will produce 2 triangles.

### `VSInvocations`

Type: **[UINT64](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of times a vertex shader was invoked. Direct3D invokes the vertex shader once per vertex.

### `GSInvocations`

Type: **[UINT64](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of times a geometry shader was invoked. When the geometry shader is set to **NULL**, this statistic may or may not increment depending on the hardware manufacturer.

### `GSPrimitives`

Type: **[UINT64](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of primitives output by a geometry shader.

### `CInvocations`

Type: **[UINT64](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of primitives that were sent to the rasterizer. When the rasterizer is disabled, this will not increment.

### `CPrimitives`

Type: **[UINT64](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of primitives that were rendered. This may be larger or smaller than CInvocations because after a primitive is clipped sometimes it is either broken up into more than one primitive or completely culled.

### `PSInvocations`

Type: **[UINT64](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of times a pixel shader was invoked.

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-d3d10-core-structures)