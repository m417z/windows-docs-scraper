# LOAD_DLL_DEBUG_INFO structure

## Description

Contains information about a dynamic-link library (DLL) that has just been loaded.

## Members

### `hFile`

A handle to the loaded DLL. If this member is **NULL**, the handle is not valid. Otherwise, the member is opened for reading and read-sharing in the context of the debugger.

When the debugger is finished with this file, it should close the handle using the [CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle) function.

### `lpBaseOfDll`

A pointer to the base address of the DLL in the address space of the process loading the DLL.

### `dwDebugInfoFileOffset`

The offset to the debugging information in the file identified by the **hFile** member, in bytes. The system expects the debugging information to be in CodeView 4.0 format. This format is currently a derivative of Common Object File Format (COFF).

### `nDebugInfoSize`

The size of the debugging information in the file, in bytes. If this member is zero, there is no debugging information.

### `lpImageName`

A pointer to the file name associated with **hFile**. This member may be **NULL**, or it may contain the address of a string pointer in the address space of the process being debugged. That address may, in turn, either be **NULL** or point to the actual filename. If **fUnicode** is a nonzero value, the name string is Unicode; otherwise, it is ANSI.

This member is strictly optional. Debuggers must be prepared to handle the case where **lpImageName** is **NULL** or ***lpImageName** (in the address space of the process being debugged) is **NULL**. Specifically, the system will never provide an image name for a create process event, and it will not likely pass an image name for the first DLL event. The system will also never provide this information in the case of debugging events that originate from a call to the
[DebugActiveProcess](https://learn.microsoft.com/windows/desktop/api/debugapi/nf-debugapi-debugactiveprocess) function.

### `fUnicode`

A value that indicates whether a filename specified by **lpImageName** is Unicode or ANSI. A nonzero value for this member indicates Unicode; zero indicates ANSI.

## See also

[CREATE_PROCESS_DEBUG_INFO](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-create_process_debug_info)

[CREATE_THREAD_DEBUG_INFO](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-create_thread_debug_info)

[DEBUG_EVENT](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-debug_event)

[DebugActiveProcess](https://learn.microsoft.com/windows/desktop/api/debugapi/nf-debugapi-debugactiveprocess)