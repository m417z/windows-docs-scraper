# IDXGIAdapter3::QueryVideoMemoryInfo

## Description

This method informs the process of the current budget and process usage.

## Parameters

### `NodeIndex` [in]

Type: **UINT**

Specifies the device's physical adapter for which the video memory information is queried.
For single-GPU operation, set this to zero.
If there are multiple GPU nodes, set this to the index of the node (the device's physical adapter) for which the video memory information is queried.
See [Multi-adapter systems](https://learn.microsoft.com/windows/win32/direct3d12/multi-engine).

### `MemorySegmentGroup` [in]

Type: **[DXGI_MEMORY_SEGMENT_GROUP](https://learn.microsoft.com/windows/win32/api/dxgi1_4/ne-dxgi1_4-dxgi_memory_segment_group)**

Specifies a DXGI_MEMORY_SEGMENT_GROUP that identifies the group as local or non-local.

### `pVideoMemoryInfo` [out]

Type: **[DXGI_QUERY_VIDEO_MEMORY_INFO](https://learn.microsoft.com/windows/win32/api/dxgi1_4/ns-dxgi1_4-dxgi_query_video_memory_info)***

Fills in a DXGI_QUERY_VIDEO_MEMORY_INFO structure with the current values.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns S_OK if successful; an error code otherwise.
For a list of error codes, see [DXGI_ERROR](https://learn.microsoft.com/windows/win32/direct3ddxgi/dxgi-error).

## Remarks

Applications must explicitly manage their usage of physical memory explicitly and keep usage within the budget assigned to the application process.
Processes that cannot kept their usage within their assigned budgets will likely experience stuttering, as they are intermittently frozen and paged-out to allow other processes to run.

## See also

[IDXGIAdapter3](https://learn.microsoft.com/windows/win32/api/dxgi1_4/nn-dxgi1_4-idxgiadapter3)