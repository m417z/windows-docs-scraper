## Description

Indicates that recording to the command list has finished.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns **S_OK** if successful; otherwise, returns one of the following values:

* **E_FAIL** if the command list has already been closed, or an invalid API was called during command list recording.
* **E_OUTOFMEMORY** if the operating system ran out of memory during recording.
* **E_INVALIDARG** if an invalid argument was passed to the command list API during recording.

See [Direct3D 12 Return Codes](https://learn.microsoft.com/windows/win32/direct3d12/d3d12-graphics-reference-returnvalues) for other possible return values.

## Remarks

The runtime will validate that the command list has not previously been closed. If an error was encountered during recording, the error code is returned here. The runtime won't call the close device driver interface (DDI) in this case.

For an example of creating a command list, see [ID3D12GraphicsCommandList::Close method](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12graphicscommandlist-close)

## See also