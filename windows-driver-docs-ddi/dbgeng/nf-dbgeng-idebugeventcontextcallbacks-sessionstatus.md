## Description

Session status is synchronous like the other wait callbacks but it is called as the state of the session is changing rather than at specific events so its return value does not influence waiting. Implementations should just return DEBUG_STATUS_NO_CHANGE.

Also, because some of the status notifications are very early or very late in the session lifetime there may not be current processes or threads when the notification is generated.

Refer to [IDebugEventCallbacks::SessionStatus](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugeventcallbacks-sessionstatus) for parameter description and additional information.

## Parameters

### `Status`

## Return value

## Remarks

## See also

[IDebugEventContextCallbacks (dbgeng.h)](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugeventcontextcallbacks)