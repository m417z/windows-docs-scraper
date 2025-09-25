# D3D10_DDI_QUERY_DATA_SO_STATISTICS structure

## Description

The D3D10_DDI_QUERY_DATA_SO_STATISTICS structure describes stream output statistics that is used in a call to the [CreateQuery(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createquery) function to create a D3D10DDI_QUERY_STREAMOUTPUTSTATS

query type and in a call to the [QueryGetData](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_querygetdata) function to return information about the query.

## Members

### `NumPrimitivesWritten`

The number of primitives that is written to the stream output resource.

### `PrimitivesStorageNeeded`

The number of primitives that would have been written to the stream output resource if the resource was big enough.

## Remarks

The driver associates a D3D10_DDI_QUERY_DATA_SO_STATISTICS structure with the D3D10DDI_QUERY_STREAMOUTPUTSTATS query type value from the [D3D10DDI_QUERY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10ddi_query) enumeration.

## See also

[CreateQuery(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createquery)

[D3D10DDI_QUERY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10ddi_query)

[QueryGetData](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_querygetdata)