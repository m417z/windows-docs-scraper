# D3DQUERYTYPE enumeration

Identifies the query type. For information about queries, see [Queries (Direct3D 9)](https://learn.microsoft.com/windows/win32/direct3d9/queries)

## Constants

**D3DQUERYTYPE\_VCACHE**

Query for driver hints about data layout for vertex caching.

**D3DQUERYTYPE\_ResourceManager**

Query the resource manager. For this query, the device behavior flags must include [D3DCREATE\_DISABLE\_DRIVER\_MANAGEMENT](https://learn.microsoft.com/windows/win32/direct3d9/d3dcreate).

**D3DQUERYTYPE\_VERTEXSTATS**

Query vertex statistics.

**D3DQUERYTYPE\_EVENT**

Query for any and all asynchronous events that have been issued from API calls.

**D3DQUERYTYPE\_OCCLUSION**

An occlusion query returns the number of pixels (or samples when multisampling is enabled) that pass z-testing. These pixels/samples are for primitives drawn between the issue of [**D3DISSUE\_BEGIN**](https://learn.microsoft.com/windows/win32/direct3d9/d3dissue-begin) and [**D3DISSUE\_END**](https://learn.microsoft.com/windows/win32/direct3d9/d3dissue-end). This enables an application to check the occlusion result against 0. Zero is fully occluded, which means the pixels/samples are not visible from the current camera position. To get the number of pixels when a multisampled render target is used, the result should be divided by the sample count of the target.

**D3DQUERYTYPE\_TIMESTAMP**

Returns a 64-bit timestamp.

**D3DQUERYTYPE\_TIMESTAMPDISJOINT**

Use this query to notify an application if the counter frequency has changed from the D3DQUERYTYPE\_TIMESTAMP.

**D3DQUERYTYPE\_TIMESTAMPFREQ**

This query result is **TRUE** if the values from D3DQUERYTYPE\_TIMESTAMP queries cannot be guaranteed to be continuous throughout the duration of the D3DQUERYTYPE\_TIMESTAMPDISJOINT query. Otherwise, the query result is **FALSE**.

**D3DQUERYTYPE\_PIPELINETIMINGS**

Percent of time processing pipeline data.

**D3DQUERYTYPE\_INTERFACETIMINGS**

Percent of time processing data in the driver.

**D3DQUERYTYPE\_VERTEXTIMINGS**

Percent of time processing vertex shader data.

**D3DQUERYTYPE\_PIXELTIMINGS**

Percent of time processing pixel shader data.

**D3DQUERYTYPE\_BANDWIDTHTIMINGS**

Throughput measurement comparisons for help in understanding the performance of an application.

**D3DQUERYTYPE\_CACHEUTILIZATION**

Measure the cache hit-rate performance for textures and indexed vertices.

**D3DQUERYTYPE\_MEMORYPRESSURE**

Efficiency of memory allocation contained in a [**D3DMEMORYPRESSURE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dmemorypressure) structure.

Differences between Direct3D 9 and Direct3D 9Ex:

- D3DQUERYTYPE\_MEMORYPRESSURE is only available in Direct3D9Ex running on Windows 7 (or more current operating system).

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3D9Types.h |

## See also

[Direct3D Enumerations](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3d-enums)

[**IDirect3DDevice9::CreateQuery**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-createquery)

