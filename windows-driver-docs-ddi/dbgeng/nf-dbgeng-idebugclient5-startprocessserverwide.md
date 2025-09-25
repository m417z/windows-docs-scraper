# IDebugClient5::StartProcessServerWide

## Description

The **StartProcessServerWide** method starts a process server.

## Parameters

### `Flags` [in]

Specifies the class of the targets that will be available through the process server. This must be set to DEBUG_CLASS_USER_WINDOWS.

### `Options` [in]

Specifies the connections options for this process server. These are the same options given to the **-t** option of the DbgSrv command line. For details on the syntax of this string, see [Activating a Process Server](https://learn.microsoft.com/windows-hardware/drivers/debugger/activating-a-process-server).

### `Reserved` [in, optional]

Set to **NULL**.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

The process server that is started will be accessible by remote clients through the transport specified in the *Options* parameter.

To stop the process server from the smart client, use the [EndProcessServer](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-endprocessserver) method. To shut down the process server from the computer that it is running on, use Task Manager to end the process. If the instance of the debugger engine that used **StartProcessServer** is still running, it can use [Execute](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-execute) to issue the debugger command [.endsrv 0](https://learn.microsoft.com/windows-hardware/drivers/debugger/-endsrv--end-debugging-server-), which will end the process server (this is an exception to the usual behavior of **.endsrv**, which generally does not affect process servers).

For more information about process servers and remote debugging, see [Process Servers, Kernel Connection Servers, and Smart Clients](https://learn.microsoft.com/windows-hardware/drivers/debugger/remote-targets).

## See also

[ConnectProcessServer](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-connectprocessserver)

[DisconnectProcessServer](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-disconnectprocessserver)

[EndProcessServer](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-endprocessserver)

[IDebugClient5](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient5)

[WaitForProcessServerEnd](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-waitforprocessserverend)