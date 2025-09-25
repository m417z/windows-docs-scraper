# ID3D10Asynchronous::GetData

## Description

Get data from the GPU asynchronously.

## Parameters

### `pData` [out]

Type: **void***

Address of memory that will receive the data. If **NULL**, **GetData** will be used only to check status. The type of data output depends on the type of asynchronous interface. See Remarks.

### `DataSize` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Size of the data to retrieve or 0. This value can be obtained with [ID3D10Asynchronous::GetDataSize](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10asynchronous-getdatasize). Must be 0 when *pData* is **NULL**.

### `GetDataFlags` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Optional flags. Can be 0 or any combination of the flags enumerated by
[D3D10_ASYNC_GETDATA_FLAG](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_async_getdata_flag).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this function succeeds, it returns S_OK. Otherwise, possible
return values are the following:

* S_FALSE
* DXGI_ERROR_DEVICE_REMOVED
* DXGI_ERROR_INVALID_CALL

## Remarks

**GetData** retrieves the data collected between calls to [ID3D10Asynchronous::Begin](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10asynchronous-begin) and [ID3D10Asynchronous::End](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10asynchronous-end). Certain queries only require a call to **ID3D10Asynchronous::End** in which case the data returned by **GetData** is accurate up to the last call to **ID3D10Asynchronous::End** (See [ID3D10Query Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10query)).

If *DataSize* is 0, **GetData** is only used to check status where a return value of S_OK indicates that data is available to give to an application, and a return value of S_FALSE indicates data is not yet available.

It is invalid to invoke this function on a predicate created with the flag D3D10_QUERY_MISCFLAG_PREDICATEHINT.

If the asynchronous interface that calls this function is [ID3D10Query Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10query), then the following table applies.

| Query Type | Output Data Type | Supports Begin Method |
| --- | --- | --- |
| D3D10_QUERY_EVENT | BOOL | NO |
| D3D10_QUERY_OCCLUSION | UINT64 | YES |
| D3D10_QUERY_TIMESTAMP | UINT64 | NO |
| D3D10_QUERY_TIMESTAMP_DISJOINT | D3D10_QUERY_DATA_TIMESTAMP_DISJOINT | YES |
| D3D10_QUERY_PIPELINE_STATISTICS | D3D10_QUERY_DATA_PIPELINE_STATISTICS | YES |
| D3D10_QUERY_OCCLUSION_PREDICATE | BOOL | YES |
| D3D10_QUERY_SO_STATISTICS | D3D10_QUERY_DATA_SO_STATISTICS | YES |
| D3D10_QUERY_SO_OVERFLOW_PREDICATE | BOOL | YES |

If the asynchronous interface that calls this API is [ID3D10Counter Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10counter), then the following applies.

| Counter Type | Output Data Type | Units |
| --- | --- | --- |
| D3D10_COUNTER_GPU_IDLE | FLOAT32 | fraction of time |
| D3D10_COUNTER_VERTEX_PROCESSING | FLOAT32 | fraction of time |
| D3D10_COUNTER_GEOMETRY_PROCESSING | FLOAT32 | fraction of time |
| D3D10_COUNTER_PIXEL_PROCESSING | FLOAT32 | fraction of time |
| D3D10_COUNTER_OTHER_GPU_PROCESSING | FLOAT32 | fraction of time |
| D3D10_COUNTER_HOST_ADAPTER_BANDWIDTH_UTILIZATION | FLOAT32 | fraction of theoretical maximum |
| D3D10_COUNTER_LOCAL_VIDMEM_BANDWIDTH_UTILIZATION | FLOAT32 | fraction of theoretical maximum |
| D3D10_COUNTER_VERTEX_THROUGHPUT_UTILIZATION | FLOAT32 | fraction of theoretical maximum |
| D3D10_COUNTER_TRIANGLE_SETUP_THROUGHPUT_UTILIZATION | FLOAT32 | fraction of theoretical maximum |
| D3D10_COUNTER_FILLRATE_THROUGHPUT_UTILIZATION | FLOAT32 | fraction of theoretical maximum |
| D3D10_COUNTER_VS_MEMORY_LIMITED | FLOAT32 | fraction of time |
| D3D10_COUNTER_VS_COMPUTATION_LIMITED | FLOAT32 | fraction of time |
| D3D10_COUNTER_GS_MEMORY_LIMITED | FLOAT32 | fraction of time |
| D3D10_COUNTER_GS_COMPUTATION_LIMITED | FLOAT32 | fraction of time |
| D3D10_COUNTER_PS_MEMORY_LIMITED | FLOAT32 | fraction of time |
| D3D10_COUNTER_PS_COMPUTATION_LIMITED | FLOAT32 | fraction of time |
| D3D10_COUNTER_POST_TRANSFORM_CACHE_HIT_RATE | FLOAT32 | fraction |
| D3D10_COUNTER_TEXTURE_CACHE_HIT_RATE | FLOAT32 | fraction |

The value returned by a D3D10_COUNTER_GPU_IDLE, D3D10_COUNTER_VERTEX_PROCESSING, D3D10_COUNTER_GEOMETRY_PROCESSING, D3D10_COUNTER_PIXEL_PROCESSING, or D3D10_COUNTER_OTHER_GPU_PROCESSING counter may be different depending on the number of parallel counters that exist on a video card, and those values can be interpreted with the following equation:

![Equation to interpret the number of parallel counters](https://learn.microsoft.com/windows/win32/api/d3d10/images/parallelUnits.jpg)

The number of parallel counters that a video card has is available from **NumDetectableParallelUnits** in [D3D10_COUNTER_INFO](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_counter_info), and it can be retrieved by calling [ID3D10Device::CheckCounterInfo](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-checkcounterinfo).

## See also

[ID3D10Asynchronous Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10asynchronous)