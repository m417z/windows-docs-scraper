# IDebugEventCallbacksWide::CreateThread

## Description

The **CreateThread** callback method is called by the engine when a create-thread debugging event occurs in the target.

## Parameters

### `Handle` [in]

Specifies the handle for the thread whose creation caused the event. If this information is not available, *Handle* will be **NULL**.

### `DataOffset` [in]

Specifies a block of data that the operating system maintains for this thread. The actual data in the block is operating system-specific. If the operating system does not have such a block, *DataOffset* will be **NULL**.

### `StartOffset` [in]

Specifies the starting location in the target's virtual address space of the thread. If this information is not available, *StartOffset* will be **NULL**.

## Return value

This method returns a [DEBUG_STATUS_XXX](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-status-xxx) value, which indicates how the execution of the target should proceed after the engine processes this event. For details on how the engine treats this value, see [Monitoring Events](https://learn.microsoft.com/windows-hardware/drivers/debugger/monitoring-events).

## Remarks

This method is only called by the engine if the DEBUG_EVENT_CREATE_THREAD flag is set in the mask returned by [IDebugEventCallbacksWide::GetInterestMask](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugeventcallbackswide-getinterestmask).

For more information about handling events, see [Monitoring Events](https://learn.microsoft.com/windows-hardware/drivers/debugger/monitoring-events). For information about threads, see [Threads and Processes](https://learn.microsoft.com/windows-hardware/drivers/debugger/threads-and-processes).