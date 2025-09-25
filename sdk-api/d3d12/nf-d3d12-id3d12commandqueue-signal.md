# ID3D12CommandQueue::Signal

## Description

Updates a fence to a specified value.

## Parameters

### `pFence`

Type: **[ID3D12Fence](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12fence)***

A pointer to the [ID3D12Fence](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12fence) object.

### `Value`

Type: **[UINT64](https://learn.microsoft.com/windows/win32/WinProg/windows-data-types)**

The value to set the fence to.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the [Direct3D 12 Return Codes](https://learn.microsoft.com/windows/win32/direct3d12/d3d12-graphics-reference-returnvalues).

## Remarks

Use this method to set a fence value from the GPU side. Use [ID3D12Fence::Signal](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12fence-signal) to set a fence from the CPU side.

#### Examples

Adds a signal to the command queue, then waits for the compute shader to complete the simulation, finally signal and increment the fence value.

```cpp
// Wait for the compute shader to complete the simulation.
UINT64 threadFenceValue = InterlockedIncrement(&m_threadFenceValues[threadIndex]);
ThrowIfFailed(pCommandQueue->Signal(pFence, threadFenceValue));
ThrowIfFailed(pFence->SetEventOnCompletion(threadFenceValue, m_threadFenceEvents[threadIndex]));
WaitForSingleObject(m_threadFenceEvents[threadIndex], INFINITE);

```

```cpp
// Add a signal command to the queue.
ThrowIfFailed(m_commandQueue->Signal(m_renderContextFence.Get(), m_renderContextFenceValue));

```

```cpp
// Signal and increment the fence value.
ThrowIfFailed(m_commandQueue->Signal(m_renderContextFence.Get(), m_renderContextFenceValue));
m_renderContextFenceValue++;

```

Refer to the [Example Code in the D3D12 Reference](https://learn.microsoft.com/windows/win32/direct3d12/notes-on-example-code).

## See also

[ID3D12CommandQueue](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12commandqueue)

[Multi-engine synchronization](https://learn.microsoft.com/windows/win32/direct3d12/user-mode-heap-synchronization)