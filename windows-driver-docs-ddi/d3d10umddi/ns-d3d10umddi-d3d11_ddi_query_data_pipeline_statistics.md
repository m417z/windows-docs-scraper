# D3D11_DDI_QUERY_DATA_PIPELINE_STATISTICS structure

## Description

The D3D11_DDI_QUERY_DATA_PIPELINE_STATISTICS structure describes statistics for each stage of the graphics pipeline that is used in a call to the [CreateQuery(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createquery) function to create a D3D10DDI_QUERY_PIPELINESTATS query type and in a call to the [QueryGetData](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_querygetdata) function to return information about the query.

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

## Remarks

The driver associates a D3D11_DDI_QUERY_DATA_PIPELINE_STATISTICS structure with the D3D11DDI_QUERY_PIPELINESTATS query type value from the [D3D10DDI_QUERY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10ddi_query) enumeration.

## See also

[CreateQuery(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createquery)

[D3D10DDI_QUERY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10ddi_query)

[QueryGetData](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_querygetdata)