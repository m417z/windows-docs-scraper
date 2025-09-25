# IDebugClient5::OutputServersWide

## Description

The **OutputServersWide** method lists the servers running on a given computer.

## Parameters

### `OutputControl` [in]

Specifies the output control to use while outputting the servers. For possible values, see [DEBUG_OUTCTL_XXX](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-outctl-xxx).

### `Machine` [in]

Specifies the name of the computer whose servers will be listed. *Machine* has the following form:

\\*computername*

### `Flags` [in]

Specifies a bit-set that determines which servers to output. The possible bit flags are:

| Flag | Description |
| --- | --- |
| DEBUG_SERVERS_DEBUGGER | Output the debugging servers on the computer. |
| DEBUG_SERVERS_PROCESS | Output the process servers on the computer. |

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

For more information about remote debugging, see [Remote Debugging](https://learn.microsoft.com/windows-hardware/drivers/debugger/remote-debugging5).

## See also

[ConnectProcessServer](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-connectprocessserver)

[DebugConnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-debugconnect)

[IDebugClient5](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient5)

[StartProcessServer](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-startprocessserver)

[StartServer](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-startserver)