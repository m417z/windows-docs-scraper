# IDebugSystemObjects3::GetCurrentSystemServerName

## Description

Gets the server name for the current process.

## Parameters

### `Buffer` [out]

A pointer to an output buffer.

### `BufferSize` [in]

The size of the buffer. This size includes the space for the '\0' terminating character.

### `NameSize` [out, optional]

A pointer to the name size. This size includes the space for the '\0' terminating character.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## See also

[Debugging Session and Execution Model](https://learn.microsoft.com/windows-hardware/drivers/debugger/debugging-session-and-execution-model)

[IDebugSystemObjects3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsystemobjects3)