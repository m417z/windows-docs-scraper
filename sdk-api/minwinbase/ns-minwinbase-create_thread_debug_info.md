# CREATE_THREAD_DEBUG_INFO structure

## Description

Contains thread-creation information that can be used by a debugger.

## Members

### `hThread`

A handle to the thread whose creation caused the debugging event. If this member is **NULL**, the handle is not valid. Otherwise, the debugger has THREAD_GET_CONTEXT, THREAD_SET_CONTEXT, and THREAD_SUSPEND_RESUME access to the thread, allowing the debugger to read from and write to the registers of the thread and control execution of the thread.

### `lpThreadLocalBase`

A pointer to a block of data. At offset 0x2C into this block is another pointer, called ThreadLocalStoragePointer, that points to an array of per-module thread local storage blocks. This gives a debugger access to per-thread data in the threads of the process being debugged using the same algorithms that a compiler would use.

### `lpStartAddress`

A pointer to the starting address of the thread. This value may only be an approximation of the thread's starting address, because any application with appropriate access to the thread can change the thread's context by using the
[SetThreadContext](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setthreadcontext) function.

## See also

[CREATE_PROCESS_DEBUG_INFO](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-create_process_debug_info)

[DEBUG_EVENT](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-debug_event)

[Debugging Structures](https://learn.microsoft.com/windows/desktop/Debug/debugging-structures)

[LOAD_DLL_DEBUG_INFO](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-load_dll_debug_info)

[SetThreadContext](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setthreadcontext)