## Description

The **D3D12DDI_QUERY_DATA_PIPELINE_STATISTICS1** structure describes statistics for each stage of the graphics pipeline that is used in a call to the [**pfnBeginEndQuery**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_begin_end_query) function to create a **D3D12_QUERY_TYPE_PIPELINE_STATISTICS1** query type, and in a call to [**pfnResolveQueryData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_resolve_query_data) to return information about the query.

## Members

### `IAVertices`

The number of input assembler (IA) vertices.

### `IAPrimitives`

The number of IA primitives.

### `VSInvocations`

The number of vertex shader (VS) invocations.

### `GSInvocations`

The number of geometry shader (GS) invocations.

### `GSPrimitives`

The number of GS primitives.

### `CInvocations`

The number of clipper invocations.

### `CPrimitives`

The number of clipper primitives.

### `PSInvocations`

The number of pixel shader (PS) invocations.

### `HSInvocations`

The number of hull shader (HS) invocations.

### `DSInvocations`

The number of domain shader (DS) invocations.

### `CSInvocations`

The number of compute shader (CS) invocations.

### `ASInvocations`

The number of amplification shader (AS) invocations.

### `MSInvocations`

The number of mesh shader (MS) invocations.

### `MSPrimitives`

The number of primitives output by the MS.

## Remarks

The driver associates a **D3D12DDI_QUERY_DATA_PIPELINE_STATISTICS1** structure with the **D3D12DDI_QUERY_TYPE_PIPELINE_STATISTICS1** query type value for the [**D3D12DDI_QUERY_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_query_type) and [**D3D12DDI_QUERY_HEAP_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_query_heap_type) enumerations.

## See also

[**D3D12DDI_QUERY_HEAP_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_query_heap_type)

[**D3D12DDI_QUERY_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_query_type)

[**pfnBeginEndQuery**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_begin_end_query)

[**pfnResolveQueryData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_resolve_query_data)