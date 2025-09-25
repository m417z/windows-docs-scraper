# IDebugSystemObjects::GetCurrentProcessExecutableName

## Description

The **GetCurrentProcessExecutableName** method returns the name of executable file loaded in the current process.

## Parameters

### `Buffer` [out, optional]

Receives the name of the executable file. If *Buffer* is **NULL**, this information is not returned.

### `BufferSize` [in]

Specifies the size in characters of the buffer *Buffer*. This size includes the space for the '\0' terminating character.

### `ExeSize` [out, optional]

Receives the size in characters of the name of the executable file. This size includes the space for the '\0' terminating character. If *ExeSize* is **NULL**, this information is not returned.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **S_FALSE** | The method was successful. However, the buffer was not large enough to hold the name of the executable file and it was truncated. |

## Remarks

These methods are only available in user-mode debugging.

If the engine cannot determine the name of the executable file, it writes the string "?NoImage?" to the buffer.

For more information about processes, see [Threads and Processes](https://learn.microsoft.com/windows-hardware/drivers/debugger/threads-and-processes).