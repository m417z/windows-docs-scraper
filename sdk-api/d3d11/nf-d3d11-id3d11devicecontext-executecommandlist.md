# ID3D11DeviceContext::ExecuteCommandList

## Description

Queues commands from a command list onto a device.

## Parameters

### `pCommandList` [in]

Type: **[ID3D11CommandList](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11commandlist)***

A pointer to an [ID3D11CommandList](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11commandlist) interface that encapsulates a command list.

### `RestoreContextState`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A Boolean flag that determines whether the target context state is saved prior to and restored after the execution of a command list. Use **TRUE** to indicate that the runtime needs to save and restore the state. Use **FALSE** to indicate that no state shall be saved or restored, which causes the target context to return to its default state after the command list executes. Applications should typically use **FALSE** unless they will restore the state to be nearly equivalent to the state that the runtime would restore if **TRUE** were passed. When applications use **FALSE**, they can avoid unnecessary and inefficient state transitions.

## Remarks

Use this method to play back a command list that was recorded by a deferred context on any thread.

A call to **ExecuteCommandList** of a command list from a deferred context onto the immediate context is required for the recorded commands to be executed on the graphics processing unit (GPU). A call to **ExecuteCommandList** of a command list from a deferred context onto another deferred context can be used to merge recorded lists. But to run the commands from the merged deferred command list on the GPU, you need to execute them on the immediate context.

This method performs some runtime validation related to queries. Queries that are begun in a device context cannot be manipulated indirectly by executing a command list (that is, Begin or End was invoked against the same query by the deferred context which generated the command list). If such a condition occurs, the ExecuteCommandList method does not execute the command list. However, the state of the device context is still maintained, as would be expected ([ID3D11DeviceContext::ClearState](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-clearstate) is performed, unless the application indicates to preserve the device context state).

**Windows Phone 8:** This API is supported.

## See also

[ID3D11DeviceContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11devicecontext)