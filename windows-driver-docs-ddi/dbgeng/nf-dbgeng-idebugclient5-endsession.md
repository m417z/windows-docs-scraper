# IDebugClient5::EndSession

## Description

The **EndSession** method ends the current debugger session.

## Parameters

### `Flags` [in]

Specifies how to end the session. *Flags* can be one of the following values:

| Flag | Description |
| --- | --- |
| DEBUG_END_PASSIVE | Perform cleanup for the session. |
| DEBUG_END_ACTIVE_TERMINATE | Attempt to terminate all user-mode targets before performing cleanup for the session. |
| DEBUG_END_ACTIVE_DETACH | Attempt to disconnect from all targets before performing cleanup for the session. |
| DEBUG_END_REENTRANT | Perform only the cleanup that doesn't require acquiring locks. See Remarks section for details. |
| DEBUG_END_DISCONNECT | Do not end the session. Disconnect the client from the session and disable the client.<br><br>This flag is intended for when remote clients disconnect. It generates a server message about the disconnection. |

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

This method may be called at any time with *Flags* set to DEBUG_END_REENTRANT. If, for example, the application needs to exit but another thread is using the engine, this method can be used to perform as much cleanup as possible.

Using DEBUG_END_REENTRANT may leave the engine in an indeterminate state. If this flag is used, no subsequent calls should be made to the engine.

For more information about debugger sessions, see [Debugging Session and Execution Model](https://learn.microsoft.com/windows-hardware/drivers/debugger/debugging-session-and-execution-model).