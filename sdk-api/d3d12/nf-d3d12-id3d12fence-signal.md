# ID3D12Fence::Signal

## Description

Sets the fence to the specified value.

## Parameters

### `Value`

Type: **[UINT64](https://learn.microsoft.com/windows/win32/WinProg/windows-data-types)**

The value to set the fence to.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the [Direct3D 12 Return Codes](https://learn.microsoft.com/windows/win32/direct3d12/d3d12-graphics-reference-returnvalues).

## Remarks

Use this method to set a fence value from the CPU side. Use [ID3D12CommandQueue::Signal](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12commandqueue-signal) to set a fence from the GPU side.

## See also

[ID3D12Fence](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12fence)

[Multi-engine synchronization](https://learn.microsoft.com/windows/win32/direct3d12/user-mode-heap-synchronization)