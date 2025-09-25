# IDXGIAdapter3::SetVideoMemoryReservation

## Description

This method sends the minimum required physical memory for an application, to the OS.

## Parameters

### `NodeIndex` [in]

Type: **UINT**

Specifies the device's physical adapter for which the video memory information is being set.
For single-GPU operation, set this to zero.
If there are multiple GPU nodes, set this to the index of the node (the device's physical adapter) for which the video memory information is being set.
See [Multi-adapter systems](https://learn.microsoft.com/windows/win32/direct3d12/multi-engine).

### `MemorySegmentGroup` [in]

Type: **[DXGI_MEMORY_SEGMENT_GROUP](https://learn.microsoft.com/windows/win32/api/dxgi1_4/ne-dxgi1_4-dxgi_memory_segment_group)**

Specifies a DXGI_MEMORY_SEGMENT_GROUP that identifies the group as local or non-local.

### `Reservation` [in]

Type: **UINT64**

Specifies a UINT64 that sets the minimum required physical memory, in bytes.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns S_OK if successful; an error code otherwise.
For a list of error codes, see [DXGI_ERROR](https://learn.microsoft.com/windows/win32/direct3ddxgi/dxgi-error).

## Remarks

Applications are encouraged to set a video reservation to denote the amount of physical memory they cannot go without.
This value helps the OS quickly minimize the impact of large memory pressure situations.

## See also

[IDXGIAdapter3](https://learn.microsoft.com/windows/win32/api/dxgi1_4/nn-dxgi1_4-idxgiadapter3)