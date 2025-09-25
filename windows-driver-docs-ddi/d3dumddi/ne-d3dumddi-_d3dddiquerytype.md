# _D3DDDIQUERYTYPE enumeration

## Description

The query type.

## Constants

### `D3DDDIQUERYTYPE_VCACHE`

Query at issue end for driver hints about data layout for vertex caching. This query is processed through a call to the driver's [IssueQuery](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_issuequery) function in which the **End** bit-field flag is set in the **Flags** member of the [D3DDDIARG_ISSUEQUERY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_issuequery) structure.

### `D3DDDIQUERYTYPE_RESOURCEMANAGER`

Query the driver's resource manager.

### `D3DDDIQUERYTYPE_VERTEXSTATS`

Query for the vertex stats.

### `D3DDDIQUERYTYPE_DDISTATS`

Query for the DDI stats.

### `D3DDDIQUERYTYPE_EVENT`

Query at issue end for asynchronous events that have occurred.

### `D3DDDIQUERYTYPE_OCCLUSION`

Query for the number of pixels that pass z-testing. These pixels are for primitives that are drawn between an issue begin and an issue end.

This query is processed between calls to the driver's [IssueQuery](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_issuequery) function in which first the **Begin** bit-field flag is set in the **Flags** member of the [D3DDDIARG_ISSUEQUERY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_issuequery) structure and next the **End** bit-field flag is set.

This query enables an application to check the occlusion result against 0. A value of 0 is "fully occluded," which means the pixels are not visible from the current camera position.

### `D3DDDIQUERYTYPE_TIMESTAMP`

Query at issue end for the 64-bit timestamp.

### `D3DDDIQUERYTYPE_TIMESTAMPDISJOINT`

This query is used to notify an application whether the counter frequency has changed from the value that is returned from the D3DQUERYTYPE_TIMESTAMP query.

### `D3DDDIQUERYTYPE_TIMESTAMPFREQ`

The GPU timestamp frequency for resolving query timestamps.

This query result is **TRUE** if the values from D3DQUERYTYPE_TIMESTAMP queries cannot be guaranteed to be continuous throughout the duration of the D3DQUERYTYPE_TIMESTAMPDISJOINT query. Otherwise, the query result is **FALSE**.

### `D3DDDIQUERYTYPE_PIPELINETIMINGS`

Query for the percent of processing time spent on pipeline data.

### `D3DDDIQUERYTYPE_INTERFACETIMINGS`

Query for the percent of processing time spent on data in the driver.

### `D3DDDIQUERYTYPE_VERTEXTIMINGS`

Query for the percent of processing time spent on vertex shader data.

### `D3DDDIQUERYTYPE_PIXELTIMINGS`

Query for the percent of processing time spent on pixel shader data.

### `D3DDDIQUERYTYPE_BANDWIDTHTIMINGS`

Query for throughput measurements for help in understanding the performance of an application.

### `D3DDDIQUERYTYPE_CACHEUTILIZATION`

Query for the cache hit-rate performance for textures and indexed vertices.

### `D3DDDIQUERYTYPE_COUNTER_DEVICE_DEPENDENT`

Query for device-dependent counters.

## Remarks

## See also