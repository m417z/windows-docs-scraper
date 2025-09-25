# IDebugClient::GetRunningProcessSystemIdByExecutableName

## Description

The **GetRunningProcessSystemIdByExecutableName** method searches for a process with a given executable file name and return its process ID.

## Parameters

### `Server` [in]

Specifies the process server to search for the executable name. If *Server* is zero, the engine will search for the executable name among the processes running on the local computer.

### `ExeName` [in]

Specifies the executable file name for which to search.

### `Flags` [in]

Specifies a bit-set that controls how the executable name is matched. The following flags may be present:

| Flag | Description |
| --- | --- |
| DEBUG_GET_PROC_FULL_MATCH | *ExeName* specifies the full path name of the executable file name.<br><br>If this flag is not set, this method will not use path names when searching for the process. |
| DEBUG_GET_PROC_ONLY_MATCH | Require that only one process match the executable file name *ExeName*. |

### `Id` [out]

Receives the process ID of the first process to match *ExeName*.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **S_FALSE** | More than one process matched the executable file name in *ExeName*, and DEBUG_GET_PROC_ONLY_MATCH was set in *Flags*. |
| **E_NOINTERFACE** | No process matched the executable file name in *ExeName*. |

## Remarks

This method is available only for live user-mode debugging.

For more information about creating and attaching to live user-mode targets, see [Live User-Mode Targets](https://learn.microsoft.com/windows-hardware/drivers/debugger/live-user-mode-targets).

## See also

[AttachProcess](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-attachprocess)

[ConnectProcessServer](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-connectprocessserver)

[CreateProcessAndAttach2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-createprocessandattach2)

[GetRunningProcessDescription](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-getrunningprocessdescription)

[GetRunningProcessSystemIds](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-getrunningprocesssystemids)

[IDebugClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient)

[IDebugClient2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient2)

[IDebugClient3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient3)

[IDebugClient4](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient4)

[IDebugClient5](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient5)