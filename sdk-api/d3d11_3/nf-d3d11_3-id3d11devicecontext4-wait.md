# ID3D11DeviceContext4::Wait

## Description

Waits until the specified fence reaches or exceeds the specified value before future work can begin.

This member function is equivalent to the Direct3D 12 [ID3D12CommandQueue::Wait](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12commandqueue-wait) member function, and applies between Direct3D 11 and Direct3D 12 in interop scenarios.

**Note** This method only applies to immediate-mode contexts.

## Parameters

### `pFence`

Type: **[ID3D11Fence](https://learn.microsoft.com/windows/win32/api/d3d11_3/nn-d3d11_3-id3d11fence)***

A pointer to the [ID3D11Fence](https://learn.microsoft.com/windows/win32/api/d3d11_3/nn-d3d11_3-id3d11fence) object.

### `Value`

Type: **[UINT64](https://learn.microsoft.com/windows/win32/WinProg/windows-data-types)**

The value that the device context is waiting for the fence to reach or exceed. So when [ID3D11Fence::GetCompletedValue](https://learn.microsoft.com/windows/win32/api/d3d11_3/nf-d3d11_3-id3d11fence-getcompletedvalue) is greater than or equal to *Value*, the wait is terminated.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/win32/direct3d11/d3d11-graphics-reference-returnvalues).

## See also

[ID3D11DeviceContext4](https://learn.microsoft.com/windows/win32/api/d3d11_3/nn-d3d11_3-id3d11devicecontext4)

[Multi-engine synchronization](https://learn.microsoft.com/windows/win32/direct3d12/user-mode-heap-synchronization)