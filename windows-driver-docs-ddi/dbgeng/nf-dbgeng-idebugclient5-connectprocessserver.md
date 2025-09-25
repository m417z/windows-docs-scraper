# IDebugClient5::ConnectProcessServer

## Description

The **ConnectProcessServer** methods connect to a [process server](https://learn.microsoft.com/windows-hardware/drivers/debugger/p).

## Parameters

### `RemoteOptions` [in]

Specifies how the [debugger engine](https://learn.microsoft.com/windows-hardware/drivers/debugger/d) will connect with the process server. These are the same options passed to the **-premote** option on the WinDbg and CDB command lines. For details on the syntax of this string, see [Activating a Smart Client](https://learn.microsoft.com/windows-hardware/drivers/debugger/activating-a-smart-client).

### `Server` [out]

Receives a handle for the process server. This handle is used when creating or attaching to processes by using the process server.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

For more information about process servers and remote debugging, see [Process Servers, Kernel Connection Servers, and Smart Clients](https://learn.microsoft.com/windows-hardware/drivers/debugger/remote-targets).

## See also

[AttachProcess](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-attachprocess)

[CreateProcess2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-createprocess2)

[CreateProcessAndAttach2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-createprocessandattach2)

[DisconnectProcessServer](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-disconnectprocessserver)

[EndProcessServer](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-endprocessserver)

[GetRunningProcessDescription](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-getrunningprocessdescription)

[GetRunningProcessSystemIdByExecutableName](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-getrunningprocesssystemidbyexecutablename)

[GetRunningProcessSystemIds](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-getrunningprocesssystemids)

[IDebugClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient)

[IDebugClient2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient2)

[IDebugClient3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient3)

[IDebugClient4](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient4)

[IDebugClient5](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient5)

[StartProcessServer](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-startprocessserver)