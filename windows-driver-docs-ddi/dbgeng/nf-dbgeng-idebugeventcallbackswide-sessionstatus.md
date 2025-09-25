# IDebugEventCallbacksWide::SessionStatus

## Description

The **SessionStatus** callback method is called by the engine when a change occurs in the debugger session.

## Parameters

### `Status` [in]

Specifies the new status of the debugger session. The following table describes the possible values.

| Value | Description |
| --- | --- |
| DEBUG_SESSION_ACTIVE | A debugger session has started. |
| DEBUG_SESSION_END_SESSION_ACTIVE_TERMINATE | The session was ended by sending DEBUG_END_ACTIVE_TERMINATE to [EndSession](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-endsession). |
| DEBUG_SESSION_END_SESSION_ACTIVE_DETACH | The session was ended by sending DEBUG_END_ACTIVE_DETACH to **EndSession**. |
| DEBUG_SESSION_END_SESSION_PASSIVE | The session was ended by sending DEBUG_END_PASSIVE to **EndSession**. |
| DEBUG_SESSION_END | The target ran to completion, ending the session. |
| DEBUG_SESSION_REBOOT | The target computer rebooted, ending the session. |
| DEBUG_SESSION_HIBERNATE | The target computer went into hibernation, ending the session. |
| DEBUG_SESSION_FAILURE | The engine was unable to continue the session. |

## Return value

This method's return value is ignored by the engine.

## Remarks

This method is only called by the engine if the DEBUG_EVENT_SESSION_STATUS flag is set in the mask returned by [IDebugEventCallbacksWide::GetInterestMask](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugeventcallbackswide-getinterestmask).

After the engine has notified all the event callbacks of the change in the session status, it will also notify any loaded [extensions](https://learn.microsoft.com/windows-hardware/drivers/debugger/introduction) that export the [DebugExtensionNotify](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nc-dbgeng-pdebug_extension_notify) callback method. The value that it passes to the extensions depends on the value of *Status*. If *Status* is DEBUG_SESSION_ACTIVE, it passes DEBUG_SESSION_ACTIVE; otherwise, it passes DEBUG_SESSION_INACTIVE.

In the DEBUG_SESSION_ACTIVE case, the engine follows the debugger session change notification with a target state change notification by calling [IDebugEventCallbacksWide::ChangeDebuggeeState](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugeventcallbackswide-changedebuggeestate) on the event callbacks and passing DEBUG_CDS_ALL in the *Flags* parameter. In all other cases, the engine precedes this notification with an engine state change notification by calling [IDebugEventCallbacksWide::ChangeEngineState](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugeventcallbackswide-changeenginestate) on the event callbacks and passing DEBUG_CES_EXECUTION_STATUS in the *Flags* parameter.

For more information about handling events, see [Monitoring Events](https://learn.microsoft.com/windows-hardware/drivers/debugger/monitoring-events). For information about debugger sessions, see [Debugging Session and Execution Model](https://learn.microsoft.com/windows-hardware/drivers/debugger/debugging-session-and-execution-model).