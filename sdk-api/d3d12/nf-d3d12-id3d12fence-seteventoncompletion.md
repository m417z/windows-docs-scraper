## Description

Specifies an event that's raised when the fence reaches a certain value.

## Parameters

### `Value`

Type: **[UINT64](https://learn.microsoft.com/windows/win32/WinProg/windows-data-types)**

The fence value when the event is to be signaled.

### `hEvent`

Type: **[HANDLE](https://learn.microsoft.com/windows/win32/WinProg/windows-data-types)**

A handle to the event object.

## Return value

Type: **HRESULT**

This method returns **E_OUTOFMEMORY** if the kernel components don’t have sufficient memory to store the event in a list. See [Direct3D 12 return codes](https://learn.microsoft.com/windows/win32/direct3d12/d3d12-graphics-reference-returnvalues) for other possible return values.

## Remarks

To specify multiple fences before an event is triggered, refer to [SetEventOnMultipleFenceCompletion](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12device1-seteventonmultiplefencecompletion).

If *hEvent* is a null handle, then this API will not return until the specified fence value(s) have been reached.

This method can be safely called from multiple threads at one time.

## Examples

The [D3D12Multithreading](https://learn.microsoft.com/windows/win32/direct3d12/working-samples) sample uses **ID3D12Fence::SetEventOnCompletion** as follows:

```cpp
// Wait for the command list to execute; we are reusing the same command
// list in our main loop but for now, we just want to wait for setup to
// complete before continuing.

// Signal and increment the fence value.
const UINT64 fenceToWaitFor = m_fenceValue;
ThrowIfFailed(m_commandQueue->Signal(m_fence.Get(), fenceToWaitFor));
m_fenceValue++;

// Wait until the fence is completed.
ThrowIfFailed(m_fence->SetEventOnCompletion(fenceToWaitFor, m_fenceEvent));
WaitForSingleObject(m_fenceEvent, INFINITE);
```

Refer to the [Example code in the Direct3D 12 reference](https://learn.microsoft.com/windows/win32/direct3d12/notes-on-example-code).

## See also

[ID3D12Fence](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12fence)

[Multi-engine synchronization](https://learn.microsoft.com/windows/win32/direct3d12/user-mode-heap-synchronization)