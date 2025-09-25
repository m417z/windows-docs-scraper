# IDebugEventCallbacks::LoadModule

## Description

The **LoadModule** callback method is called by the engine when a module-load debugging event occurs in the target.

## Parameters

### `ImageFileHandle` [in]

Specifies the handle to the module's image file. If this information is not available, *ImageFileHandle* will be **NULL**.

### `BaseOffset` [in]

Specifies the base address of the module in the target's memory address space. If this information is not available, *BaseOffset* will be **NULL**.

### `ModuleSize` [in]

Specifies the module's image size in bytes. If this information is not available, *ModuleSize* will be **NULL**.

### `ModuleName` [in, optional]

Specifies the simplified module name that is used by the debugger engine. In most cases, this matches the image file name excluding the extension. If this information is not available, *ModuleName* will be **NULL**.

### `ImageName` [in, optional]

Specifies the module's image file name, which can include the path. If this information is not available, *ImageName* will be **NULL**.

### `CheckSum` [in]

Specifies the checksum of the module's image file. If this information is not available, *CheckSum* will be **NULL**.

### `TimeDateStamp` [in]

Specifies the time and date stamp of the module's image file. If this information is not available, *TimeDateStamp* will be zero.

## Return value

This method returns a [DEBUG_STATUS_XXX](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-status-xxx) value, which indicates how the execution of the target should proceed after the engine processes this event. For details on how the engine treats this value, see [Monitoring Events](https://learn.microsoft.com/windows-hardware/drivers/debugger/monitoring-events).

## Remarks

This method is only called by the engine if the DEBUG_EVENT_LOAD_MODULE flag is set in the mask returned by [IDebugEventCallbacks::GetInterestMask](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugeventcallbacks-getinterestmask).

After calling this method, the engine will call [IDebugEventCallbacks::ChangeSymbolState](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugeventcallbacks-changesymbolstate), with the *Flags* parameter containing the bit flag DEBUG_CSS_LOADS.

For more information about handling events, see [Monitoring Events](https://learn.microsoft.com/windows-hardware/drivers/debugger/monitoring-events).