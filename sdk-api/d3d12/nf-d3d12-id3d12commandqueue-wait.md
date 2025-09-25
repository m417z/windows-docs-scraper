## Description

Queues a GPU-side wait, and returns immediately. A GPU-side wait is where the GPU waits until the specified fence reaches or exceeds the specified value.

## Parameters

### `pFence`

Type: **[ID3D12Fence](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12fence)***

A pointer to the [ID3D12Fence](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12fence) object.

### `Value`

Type: **[UINT64](https://learn.microsoft.com/windows/win32/WinProg/windows-data-types)**

The value that the command queue is waiting for the fence to reach or exceed. So when [ID3D12Fence::GetCompletedValue](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12fence-getcompletedvalue) is greater than or equal to *Value*, the wait is terminated.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the [Direct3D 12 Return Codes](https://learn.microsoft.com/windows/win32/direct3d12/d3d12-graphics-reference-returnvalues).

## Remarks

Because a wait is being queued, the API returns immediately. It's the command queue that waits (during which time no work is executed) until the fence specified reaches the requested value.
If you want to perform a CPU-side wait (where the calling thread blocks until a fence reaches a particular value), then you should use the [**ID3D12Fence::SetEventOnCompletion**](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12fence-seteventoncompletion) API in conjunction with [**WaitForSingleObject**](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-waitforsingleobject) (or a similar API).

## See also

[ID3D12CommandQueue](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12commandqueue)

[Multi-engine synchronization](https://learn.microsoft.com/windows/win32/direct3d12/user-mode-heap-synchronization)