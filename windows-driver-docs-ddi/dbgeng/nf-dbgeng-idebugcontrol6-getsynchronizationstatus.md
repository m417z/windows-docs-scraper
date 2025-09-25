# IDebugControl6::GetSynchronizationStatus

## Description

The GetSynchronizationStatus method returns information about the synchronization status of the debugger engine.

## Parameters

### `SendsAttempted` [out]

The number of packet sends that have been attempted by the current debugger-engine kernel transport mechanism. This number will be incremented if engine did not receive a packet "ACK" for the last packet sent by the engine to the target.

### `SecondsSinceLastResponse` [out]

The number of seconds since the last response.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

When the client object connects to a session, the most recent output from the session is sent to the client. If the session is currently waiting on input, the client object is given the opportunity to provide input. Thus, the client object synchronizes with the session's input and output.

## See also

[IDebugControl6](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol6)

[Synchronizing with the Target Computer](https://learn.microsoft.com/windows-hardware/drivers/debugger/synchronizing-with-the-target-computer)