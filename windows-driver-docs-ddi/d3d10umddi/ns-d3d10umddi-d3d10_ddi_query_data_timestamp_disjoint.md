# D3D10_DDI_QUERY_DATA_TIMESTAMP_DISJOINT structure

## Description

The D3D10_DDI_QUERY_DATA_TIMESTAMP_DISJOINT structure describes timestamp-disjoint information that is used in a call to the [CreateQuery(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createquery) function to create a D3D10DDI_QUERY_TIMESTAMPDISJOINT query type and in a call to the [QueryGetData](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_querygetdata) function to return information about the query.

## Members

### `Frequency`

The frequency, in Hz, of the timestamp clock.

### `Disjoint`

A BOOL value that indicates whether something caused the timestamp counter to become discontinuous or disjoint. This value is **TRUE** if the values from TIMESTAMP queries cannot be guaranteed to be continuous throughout the duration of the D3D10DDI_QUERY_TIMESTAMPDISJOINT query. Otherwise, this value should be **FALSE**.

## Remarks

The driver associates a D3D10_DDI_QUERY_DATA_TIMESTAMP_DISJOINT structure with the D3D10DDI_QUERY_TIMESTAMPDISJOINT query type value from the [D3D10DDI_QUERY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10ddi_query) enumeration.

## See also

[CreateQuery(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createquery)

[D3D10DDI_QUERY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10ddi_query)

[QueryGetData](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_querygetdata)