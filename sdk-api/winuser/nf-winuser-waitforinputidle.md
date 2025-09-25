# WaitForInputIdle function

## Description

Waits until the specified process has finished processing its initial input and is waiting for user input with no input pending, or until the time-out interval has elapsed.

## Parameters

### `hProcess` [in]

A handle to the process. If this process is a console application or does not have a message queue,
**WaitForInputIdle** returns immediately.

### `dwMilliseconds` [in]

The time-out interval, in milliseconds. If *dwMilliseconds* is INFINITE, the function does not return until the process is idle.

## Return value

The following table shows the possible return values for this function.

| Return code/value | Description |
| --- | --- |
| 0 | The wait was satisfied successfully. |
| **WAIT_TIMEOUT** | The wait was terminated because the time-out interval elapsed. |
| **WAIT_FAILED** | An error occurred. |

## Remarks

The
**WaitForInputIdle** function enables a thread to suspend its execution until the specified process has finished its initialization and is waiting for user input with no input pending. If the process has multiple threads, the **WaitForInputIdle** function returns as soon as any thread becomes idle.

**WaitForInputIdle** can be used at any time, not just during application startup. However, **WaitForInputIdle** waits only once for a process to become idle; subsequent **WaitForInputIdle** calls return immediately, whether the process is idle or busy.

**WaitForInputIdle** can be useful for synchronizing a parent process and a newly created child process. When a parent process creates a child process, the
[CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa) function returns without waiting for the child process to finish its initialization. Before trying to communicate with the child process, the parent process can use
the **WaitForInputIdle** function to determine when the child's initialization has been completed. For example, the parent process should use
the **WaitForInputIdle** function before trying to find a window associated with the child process.

## See also

[CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa)

[Process and Thread Functions](https://learn.microsoft.com/windows/desktop/ProcThread/process-and-thread-functions)

[Synchronizing Execution of Multiple Threads](https://learn.microsoft.com/windows/desktop/ProcThread/synchronizing-execution-of-multiple-threads)