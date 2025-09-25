# IDebugEventCallbacksWide::UnloadModule

## Description

The **UnloadModule** callback method is called by the engine when a module-unload debugging event occurs in the target.

## Parameters

### `ImageBaseName` [in, optional]

Specifies the name of the module's image file, which can include the path. If this information is not available, *ImageBaseName* will be **NULL**.

### `BaseOffset` [in]

Specifies the base address of the module in the target's memory address space. If this information is not available, *BaseOffset* will be **NULL**.

## Return value

This method returns a [DEBUG_STATUS_XXX](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-status-xxx) value, which indicates how the execution of the target should proceed after the engine processes this event. For details on how the engine treats this value, see [Monitoring Events](https://learn.microsoft.com/windows-hardware/drivers/debugger/monitoring-events).

## Remarks

This method is only called by the engine if the DEBUG_EVENT_UNLOAD_MODULE flag is set in the mask returned by [IDebugEventCallbacksWide::GetInterestMask](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugeventcallbackswide-getinterestmask).

After calling this method, the engine will call [IDebugEventCallbacksWide::ChangeSymbolState](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugeventcallbackswide-changesymbolstate), with the *Flags* parameter containing the bit flag DEBUG_CSS_UNLOADS.

For more information about handling events, see [Monitoring Events](https://learn.microsoft.com/windows-hardware/drivers/debugger/monitoring-events).