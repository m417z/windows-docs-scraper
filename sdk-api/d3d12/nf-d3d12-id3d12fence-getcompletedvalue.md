# ID3D12Fence::GetCompletedValue

## Description

Gets the current value of the fence.

## Return value

Type: **[UINT64](https://learn.microsoft.com/windows/win32/WinProg/windows-data-types)**

Returns the current value of the fence. If the device has been removed, the return value will be **UINT64_MAX**.

## See also

[ID3D12Fence](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12fence)

[Multi-engine synchronization](https://learn.microsoft.com/windows/win32/direct3d12/user-mode-heap-synchronization)