# DebugActiveProcess function

## Description

Enables a debugger to attach to an active process and debug it.

## Parameters

### `dwProcessId` [in]

The identifier for the process to be debugged. The debugger is granted debugging access to the process as
if it created the process with the **DEBUG_ONLY_THIS_PROCESS** flag. For more information,
see the Remarks section of this topic.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is 0 (zero). To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

To stop debugging the process, you must exit the process or call the
[DebugActiveProcessStop](https://learn.microsoft.com/windows/desktop/api/debugapi/nf-debugapi-debugactiveprocessstop) function. Exiting the
debugger also exits the process unless you use the
[DebugSetProcessKillOnExit](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-debugsetprocesskillonexit) function.

The debugger must have appropriate access to the target process, and it must be able to open the process for
**PROCESS_ALL_ACCESS**.
**DebugActiveProcess** can fail if the target process
is created with a security descriptor that grants the debugger anything less than full access. If the debugging
process has the **SE_DEBUG_NAME** privilege granted and enabled, it can debug any
process.

After the system checks the process identifier and determines that a valid debugging attachment is being made,
the function returns **TRUE**. Then the debugger is expected to wait for debugging events by
using the [WaitForDebugEvent](https://learn.microsoft.com/windows/desktop/api/debugapi/nf-debugapi-waitfordebugevent) function. The system
suspends all threads in the process, and sends the debugger events that represents the current state of the
process.

The system sends the debugger a single **CREATE_PROCESS_DEBUG_EVENT** debugging event
that represents the process specified by the *dwProcessId* parameter. The
**lpStartAddress** member of the
[CREATE_PROCESS_DEBUG_INFO](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-create_process_debug_info) structure is
**NULL**.

For each thread that is currently part of the process, the system sends a
**CREATE_THREAD_DEBUG_EVENT** debugging event. The **lpStartAddress**
member of the [CREATE_THREAD_DEBUG_INFO](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-create_thread_debug_info)
structure is **NULL**.

For each dynamic-link library (DLL) that is currently loaded into the address space of the target process, the
system sends a **LOAD_DLL_DEBUG_EVENT** debugging event. The system arranges for the first
thread in the process to execute a breakpoint instruction after it resumes. Continuing this thread causes it to
return to doing the same thing as before the debugger is attached.

After all of this is done, the system resumes all threads in the process. When the first thread in the process
resumes, it executes a breakpoint instruction that causes an **EXCEPTION_DEBUG_EVENT**
debugging event to be sent to the debugger. All future debugging events are sent to the debugger by using the
normal mechanism and rules.

## See also

[CREATE_PROCESS_DEBUG_INFO](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-create_process_debug_info)

[CREATE_THREAD_DEBUG_INFO](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-create_thread_debug_info)

[CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa)

[DebugActiveProcessStop](https://learn.microsoft.com/windows/desktop/api/debugapi/nf-debugapi-debugactiveprocessstop)

[Debugging Functions](https://learn.microsoft.com/windows/desktop/Debug/debugging-functions)

[Debugging a Running Process](https://learn.microsoft.com/windows/desktop/Debug/debugging-a-running-process)

[WaitForDebugEvent](https://learn.microsoft.com/windows/desktop/api/debugapi/nf-debugapi-waitfordebugevent)