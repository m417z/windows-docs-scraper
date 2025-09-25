# IDebugClient4::WaitForProcessServerEnd

## Description

The **WaitForProcessServerEnd** method waits for a local process server to exit.

## Parameters

### `Timeout` [in]

Specifies how long in milliseconds to wait for a process server to exit. If *Timeout* is INFINITE, this method will not return until a process server has ended.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **S_FALSE** | A time-out occurred -- *Timeout* milliseconds passed without a local process server exiting. |

## Remarks

This method will only wait for the first local process server to end. After a process server has ended, subsequent calls to this method will return immediately.

For more information about process servers and remote debugging, see [Process Servers, Kernel Connection Servers, and Smart Clients](https://learn.microsoft.com/windows-hardware/drivers/debugger/remote-targets).

The constant INFINITE is defined in Winbase.h.

## See also

[EndProcessServer](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-endprocessserver)

[IDebugClient2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient2)

[IDebugClient3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient3)

[IDebugClient4](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient4)

[IDebugClient5](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient5)

[StartProcessServer](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-startprocessserver)