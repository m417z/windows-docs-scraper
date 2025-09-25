# IDebugEventCallbacksWide::Exception

## Description

The **Exception** callback method is called by the engine when an [exception](https://learn.microsoft.com/windows-hardware/drivers/) debugging event occurs in the target.

## Parameters

### `Exception` [in]

Specifies the nature of the exception. EXCEPTION_RECORD64 is defined in Winnt.h.

### `FirstChance` [in]

Specifies whether this exception has been previously encountered. A nonzero value means that this is the first time the exception has been encountered ("first chance"). A zero value means that the exception has already been offered to all possible handlers, and each one declined to handle it ("second chance").

## Return value

This method returns a [DEBUG_STATUS_XXX](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-status-xxx) value, which indicates how the execution of the target should proceed after the engine processes this event. For details on how the engine treats this value, see [Monitoring Events](https://learn.microsoft.com/windows-hardware/drivers/debugger/monitoring-events).

## Remarks

This method is only called by the engine if the DEBUG_EVENT_EXCEPTION flag is set in the mask returned by [IDebugEventCallbacksWide::GetInterestMask](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugeventcallbackswide-getinterestmask).

Because the structure that *Exception* points to might be deleted after this method returns, implementations of **IDebugEventCallbacksWide** should not access this structure after returning.

For more information about handling events, see [Monitoring Events](https://learn.microsoft.com/windows-hardware/drivers/debugger/monitoring-events).