## Description

Resets a command list back to its initial state as if a new command list was just created.

## Parameters

### `pAllocator`

Type: **ID3D12CommandAllocator***

A pointer to the [ID3D12CommandAllocator](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12commandallocator) object that the device creates command lists from.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns **S_OK** if successful; otherwise, returns one of the following values:

* **E_FAIL** if the command list was not in the "closed" state when the **Reset** call was made, or the per-device limit would have been exceeded.
* **E_OUTOFMEMORY** if the operating system ran out of memory.
* **E_INVALIDARG** if the allocator is currently being used with another command list in the "recording" state or if the specified allocator was created with the wrong type.

See [Direct3D 12 Return Codes](https://learn.microsoft.com/windows/win32/direct3d12/d3d12-graphics-reference-returnvalues) for other possible return values.

## Remarks

For additional information and examples of using this method, see [ID3D12GraphicsCommandList::Reset method](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12graphicscommandlist-reset)

## See also