# CREATE_PROCESS_DEBUG_INFO structure

## Description

Contains process creation information that can be used by a debugger.

## Members

### `hFile`

A handle to the process's image file. If this member is **NULL**, the handle is not
valid. Otherwise, the debugger can use the member to read from and write to the image file.

When the debugger is finished with this file, it should close the handle using the
[CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle) function.

### `hProcess`

A handle to the process. If this member is **NULL**, the handle is not valid.
Otherwise, the debugger can use the member to read from and write to the process's memory.

### `hThread`

A handle to the initial thread of the process identified by the **hProcess** member.
If **hThread** param is **NULL**, the handle is not valid.
Otherwise, the debugger has **THREAD_GET_CONTEXT**,
**THREAD_SET_CONTEXT**, and **THREAD_SUSPEND_RESUME** access to the
thread, allowing the debugger to read from and write to the registers of the thread and to control execution of
the thread.

### `lpBaseOfImage`

The base address of the executable image that the process is running.

### `dwDebugInfoFileOffset`

The offset to the debugging information in the file identified by the **hFile**
member.

### `nDebugInfoSize`

The size of the debugging information in the file, in bytes. If this value is zero, there is no debugging
information.

### `lpThreadLocalBase`

A pointer to a block of data. At offset 0x2C into this block is another pointer, called
`ThreadLocalStoragePointer`, that points to an array of per-module thread local storage
blocks. This gives a debugger access to per-thread data in the threads of the process being debugged using the
same algorithms that a compiler would use.

### `lpStartAddress`

A pointer to the starting address of the thread. This value may only be an approximation of the thread's
starting address, because any application with appropriate access to the thread can change the thread's context
by using the [SetThreadContext](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setthreadcontext) function.

### `lpImageName`

A pointer to the file name associated with the **hFile** member. This parameter may be
**NULL**, or it may contain the address of a string pointer in the address space of the
process being debugged. That address may, in turn, either be **NULL** or point to the
actual filename. If **fUnicode** is a nonzero value, the name string is Unicode;
otherwise, it is ANSI.

This member is strictly optional. Debuggers must be prepared to handle the case where
**lpImageName** is **NULL** or
       ***lpImageName** (in the address space of the process being debugged) is
**NULL**. Specifically, the system does not provide an image name for a create process
event, and will not likely pass an image name for the first DLL event. The system also does not provide this
information in the case of debug events that originate from a call to the
[DebugActiveProcess](https://learn.microsoft.com/windows/desktop/api/debugapi/nf-debugapi-debugactiveprocess) function.

### `fUnicode`

A value that indicates whether a file name specified by the **lpImageName** member
is Unicode or ANSI. A nonzero value indicates Unicode; zero indicates ANSI.

## See also

[CREATE_THREAD_DEBUG_INFO](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-create_thread_debug_info)

[DEBUG_EVENT](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-debug_event)

[DebugActiveProcess](https://learn.microsoft.com/windows/desktop/api/debugapi/nf-debugapi-debugactiveprocess)

[LOAD_DLL_DEBUG_INFO](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-load_dll_debug_info)

[SetThreadContext](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setthreadcontext)