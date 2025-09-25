# IDebugClient3::StartServer

## Description

The **StartServer** method starts a debugging server.

## Parameters

### `Options` [in]

Specifies the connections options for this server. These are the same options given to the **.server** debugger command or the WinDbg and CDB **-server** command-line option. For details on the syntax of this string, see [Activating a Debugging Server](https://learn.microsoft.com/windows-hardware/drivers/debugger/activating-a-debugging-server).

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

The server that is started will be accessible by other [debuggers](https://learn.microsoft.com/windows-hardware/drivers/debugger/debuggers-in-the-debugging-tools-for-windows-package) through the transport specified in the *Options* parameter.

For more information about debugging servers, see Debugging Server and Debugging Client.

## See also

[DebugConnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-debugconnect)

[IDebugClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient)

[IDebugClient2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient2)

[IDebugClient3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient3)

[IDebugClient4](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient4)

[IDebugClient5](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient5)

[OutputServers](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-outputservers)

[StartProcessServer](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-startprocessserver)