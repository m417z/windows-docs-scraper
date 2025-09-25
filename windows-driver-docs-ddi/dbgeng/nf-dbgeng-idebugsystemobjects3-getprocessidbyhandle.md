# IDebugSystemObjects3::GetProcessIdByHandle

## Description

The **GetProcessIdByHandle** method returns the engine process ID for the specified process. The process is specified by its system handle.

## Parameters

### `Handle` [in]

Specifies the handle of the process whose process ID is requested. This handle must be a process handle previously retrieved from the debugger engine.

### `Id` [out]

Receives the engine process ID.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

For more information about processes, see [Threads and Processes](https://learn.microsoft.com/windows-hardware/drivers/debugger/threads-and-processes). For details on system handles, see [Handles](https://learn.microsoft.com/windows-hardware/drivers/).