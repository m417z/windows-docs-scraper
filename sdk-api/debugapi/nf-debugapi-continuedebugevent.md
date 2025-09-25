# ContinueDebugEvent function

## Description

Enables a debugger to continue a thread that previously reported a debugging event.

## Parameters

### `dwProcessId` [in]

The process identifier of the process to continue.

### `dwThreadId` [in]

The thread identifier of the thread to continue. The combination of process identifier and thread identifier must identify a thread that has previously reported a debugging event.

### `dwContinueStatus` [in]

The options to continue the thread that reported the debugging event.

| Value | Meaning |
| --- | --- |
| **DBG_CONTINUE**<br><br>0x00010002L | If the thread specified by the *dwThreadId* parameter previously reported an EXCEPTION_DEBUG_EVENT debugging event, the function stops all exception processing and continues the thread and the exception is marked as handled. For any other debugging event, this flag simply continues the thread. |
| **DBG_EXCEPTION_NOT_HANDLED**<br><br>0x80010001L | If the thread specified by *dwThreadId* previously reported an EXCEPTION_DEBUG_EVENT debugging event, the function continues exception processing. If this is a first-chance exception event, the search and dispatch logic of the structured exception handler is used; otherwise, the process is terminated. For any other debugging event, this flag simply continues the thread. |
| **DBG_REPLY_LATER**<br><br>0x40010001L | Supported in Windows 10, version 1507 or above, this flag causes *dwThreadId* to replay the existing breaking event after the target continues. By calling the [SuspendThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-suspendthread) API against *dwThreadId*, a debugger can resume other threads in the process and later return to the breaking. |

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Only the thread that created *dwProcessId* with the
[CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa) function can call
**ContinueDebugEvent**.

After the
**ContinueDebugEvent** function succeeds, the specified thread continues. Depending on the debugging event previously reported by the thread, different actions occur. If the continued thread previously reported an EXIT_THREAD_DEBUG_EVENT debugging event,
**ContinueDebugEvent** closes the handle the debugger has to the thread. If the continued thread previously reported an EXIT_PROCESS_DEBUG_EVENT debugging event,
**ContinueDebugEvent** closes the handles the debugger has to the process and to the thread.

#### Examples

For an example, see
[Writing the Debugger's Main Loop](https://learn.microsoft.com/windows/desktop/Debug/writing-the-debugger-s-main-loop).

## See also

[CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa)

[Debugging Events](https://learn.microsoft.com/windows/desktop/Debug/debugging-events)

[Debugging Functions](https://learn.microsoft.com/windows/desktop/Debug/debugging-functions)