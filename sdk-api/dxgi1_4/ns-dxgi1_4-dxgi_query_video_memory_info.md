# DXGI_QUERY_VIDEO_MEMORY_INFO structure

## Description

Describes the current video memory budgeting parameters.

## Members

### `Budget`

Specifies the OS-provided video memory budget, in bytes, that the application should target. If *CurrentUsage* is greater than *Budget*, the application may incur stuttering or performance penalties due to background activity by the OS to provide other applications with a fair usage of video memory.

### `CurrentUsage`

 Specifies the application’s current video memory usage, in bytes.

### `AvailableForReservation`

 The amount of video memory, in bytes, that the application has available for reservation. To reserve this video memory, the application should call [IDXGIAdapter3::SetVideoMemoryReservation](https://learn.microsoft.com/windows/desktop/api/dxgi1_4/nf-dxgi1_4-idxgiadapter3-setvideomemoryreservation).

### `CurrentReservation`

 The amount of video memory, in bytes, that is reserved by the application. The OS uses the reservation as a hint to determine the application’s minimum working set. Applications should attempt to ensure that their video memory usage can be trimmed to meet this requirement.

## Remarks

Use this structure with [QueryVideoMemoryInfo](https://learn.microsoft.com/windows/desktop/api/dxgi1_4/nf-dxgi1_4-idxgiadapter3-queryvideomemoryinfo).

Refer to the remarks for [D3D12_MEMORY_POOL](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_memory_pool).

## See also

[DXGI Structures](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-reference-dxgi-structures)