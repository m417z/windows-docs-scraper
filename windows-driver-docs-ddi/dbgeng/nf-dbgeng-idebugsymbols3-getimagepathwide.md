# IDebugSymbols3::GetImagePathWide

## Description

The **GetImagePathWide** method returns the executable image path.

## Parameters

### `Buffer` [out, optional]

Receives the executable image path. This is a string that contains directories separated by semicolons (**;**). If *Buffer* is **NULL**, this information is not returned.

### `BufferSize` [in]

Specifies the size, in characters, of the *Buffer* buffer.

### `PathSize` [out, optional]

Receives the size, in characters, of the executable image path.

## Return value

This method may also return other error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **S_FALSE** | The method was successful. However, the buffer was not large enough to hold the executable image path and the path was truncated. |

## Remarks

The executable image path is used by the engine when searching for executable images.

The executable image path can consist of several directories separated by semicolons. These directories are searched in order.

## See also

[AppendImagePath](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-appendimagepath)

[IDebugSymbols3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols3)

[SetImagePath](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-setimagepath)