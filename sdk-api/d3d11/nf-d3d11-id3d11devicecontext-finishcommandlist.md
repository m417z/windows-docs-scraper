# ID3D11DeviceContext::FinishCommandList

## Description

Create a command list and record graphics commands into it.

## Parameters

### `RestoreDeferredContextState`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A Boolean flag that determines whether the runtime saves deferred context state before it executes **FinishCommandList** and restores it afterwards. Use **TRUE** to indicate that the runtime needs to save and restore the state. Use **FALSE** to indicate that the runtime will not save or restore any state. In this case, the deferred context will return to its default state after the call to **FinishCommandList** completes. For information about default state, see [ID3D11DeviceContext::ClearState](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-clearstate). Typically, use **FALSE** unless you restore the state to be nearly equivalent to the state that the runtime would restore if you passed **TRUE**. When you use **FALSE**, you can avoid unnecessary and inefficient state transitions.

**Note** This parameter does not affect the command list that the current call to **FinishCommandList** returns. However, this parameter affects the command list of the next call to **FinishCommandList** on the same deferred context.

### `ppCommandList` [out, optional]

Type: **[ID3D11CommandList](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11commandlist)****

Upon completion of the method, the passed pointer to an [ID3D11CommandList](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11commandlist) interface pointer is initialized with the recorded command list information. The resulting **ID3D11CommandList** object is immutable and can only be used with [ID3D11DeviceContext::ExecuteCommandList](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-executecommandlist).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns S_OK if successful; otherwise, returns one of the following:

* Returns DXGI_ERROR_DEVICE_REMOVED if the video card has been physically removed from the system, or a driver upgrade for the video card has occurred. If this error occurs, you should destroy and recreate the device.
* Returns DXGI_ERROR_INVALID_CALL if **FinishCommandList** cannot be called from the current context. See remarks.
* Returns E_OUTOFMEMORY if the application has exhausted available memory.

## Remarks

Create a command list from a deferred context and record commands into it by calling **FinishCommandList**. Play back a command list with an immediate context by calling [ID3D11DeviceContext::ExecuteCommandList](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-executecommandlist).

Immediate context state is cleared before and after a command list is executed. A command list has no concept of inheritance. Each call to **FinishCommandList** will record only the state set since any previous call to **FinishCommandList**.

For example, the state of a [device context](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-intro) is its render state or pipeline state. To retrieve device context state, an application can call [ID3D11DeviceContext::GetData](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-getdata) or [ID3D11DeviceContext::GetPredication](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-getpredication).

For more information about how to use **FinishCommandList**, see [How to: Record a Command List](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-render-multi-thread-command-list-record).

**Windows Phone 8:** This API is supported.

## See also

[ID3D11DeviceContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11devicecontext)