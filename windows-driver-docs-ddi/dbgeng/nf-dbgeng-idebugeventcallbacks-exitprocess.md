# IDebugEventCallbacks::ExitProcess

## Description

The **ExitProcess** callback method is called by the engine when an exit-process debugging event occurs in the target.

## Parameters

### `ExitCode` [in]

Specifies the exit code for the process.

## Return value

This method returns a [DEBUG_STATUS_XXX](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-status-xxx) value, which indicates how the execution of the target should proceed after the engine processes this event. For details on how the engine treats this value, see [Monitoring Events](https://learn.microsoft.com/windows-hardware/drivers/debugger/monitoring-events).

## Remarks

This method is only called by the engine if the DEBUG_EVENT_EXIT_PROCESS flag is set in the mask returned by [IDebugEventCallbacks::GetInterestMask](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugeventcallbacks-getinterestmask).

For more information about handling events, see [Monitoring Events](https://learn.microsoft.com/windows-hardware/drivers/debugger/monitoring-events). For information about threads, see [Threads and Processes](https://learn.microsoft.com/windows-hardware/drivers/debugger/threads-and-processes).