# IDebugEventCallbacks::CreateProcess

## Description

The **CreateProcess** callback method is called by the engine when a create-process debugging event occurs in the target.

## Parameters

### `ImageFileHandle` [in]

Specifies the handle to the process's image file. If this information is not available, *ImageFileHandle* will be **NULL**.

### `Handle` [in]

Specifies the handle to the process. This parameter corresponds to the **hProcess** field in the CREATE_PROCESS_DEBUG_INFO structure. If this information is not available, *ImageFileHandle* will be **NULL**.

### `BaseOffset` [in]

Specifies the base address of the process's executable image in the target's memory address space. If this information is not available, *BaseOffset* will be **NULL**.

### `ModuleSize` [in]

Specifies the process's executable image size in bytes. If this information is not available, *ModuleSize* will be zero.

### `ModuleName` [in, optional]

Specifies the simplified module name that is used by the debugger engine. In most cases, this matches the image file name excluding the extension. If this information is not available, *ModuleName* will be **NULL**.

### `ImageName` [in, optional]

Specifies the process's executable-image file name, which can include the path. If this information is not available, *ImageName* will be **NULL**.

### `CheckSum` [in]

Specifies the checksum of the process's executable image. If this information is not available, *CheckSum* will be zero.

### `TimeDateStamp` [in]

Specifies the time and date stamp of the process's executable-image file. If this information is not available, *TimeDateStamp* will be zero.

### `InitialThreadHandle` [in]

Specifies the handle to the process's initial thread. This parameter corresponds to the **hThread** field in the CREATE_PROCESS_DEBUG_INFO structure. If this information is not available, *InitialThreadHandle* will be **NULL**.

### `ThreadDataOffset` [in]

Specifies a block of data that the operating system maintains for this thread. The actual data in the block is operating system-specific. If this information is not available, *ThreadDataOffset* will be **NULL**.

### `StartOffset` [in]

Specifies the starting address of the thread in the process's virtual address space. If this information is not available, *StartOffset* will be **NULL**.

## Return value

This method returns a [DEBUG_STATUS_XXX](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-status-xxx) value, which indicates how the execution of the target should proceed after the engine processes this event. For details on how the engine treats this value, see [Monitoring Events](https://learn.microsoft.com/windows-hardware/drivers/debugger/monitoring-events).

## Remarks

This method is only called by the engine if the DEBUG_EVENT_CREATE_PROCESS flag is set in the mask returned by [IDebugEventCallbacks::GetInterestMask](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugeventcallbacks-getinterestmask).

For more information about handling events, see [Monitoring Events](https://learn.microsoft.com/windows-hardware/drivers/debugger/monitoring-events). For information about threads, see [Threads and Processes](https://learn.microsoft.com/windows-hardware/drivers/debugger/threads-and-processes).