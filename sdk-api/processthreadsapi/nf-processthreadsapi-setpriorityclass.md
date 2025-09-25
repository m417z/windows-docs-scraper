# SetPriorityClass function

## Description

Sets the priority class for the specified process. This value together with the priority value of each thread of the process determines each thread's base priority level.

## Parameters

### `hProcess` [in]

A handle to the process.

The handle must have the **PROCESS_SET_INFORMATION** access right. For more information, see
[Process Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/process-security-and-access-rights).

### `dwPriorityClass` [in]

The priority class for the process. This parameter can be one of the following values.

| Priority | Meaning |
| --- | --- |
| **ABOVE_NORMAL_PRIORITY_CLASS**<br><br>0x00008000 | Process that has priority above **NORMAL_PRIORITY_CLASS** but below **HIGH_PRIORITY_CLASS**. |
| **BELOW_NORMAL_PRIORITY_CLASS**<br><br>0x00004000 | Process that has priority above **IDLE_PRIORITY_CLASS** but below **NORMAL_PRIORITY_CLASS**. |
| **HIGH_PRIORITY_CLASS**<br><br>0x00000080 | Process that performs time-critical tasks that must be executed immediately. The threads of the process preempt the threads of normal or idle priority class processes. An example is the Task List, which must respond quickly when called by the user, regardless of the load on the operating system. Use extreme care when using the high-priority class, because a high-priority class application can use nearly all available CPU time. |
| **IDLE_PRIORITY_CLASS**<br><br>0x00000040 | Process whose threads run only when the system is idle. The threads of the process are preempted by the threads of any process running in a higher priority class. An example is a screen saver. The idle-priority class is inherited by child processes. |
| **NORMAL_PRIORITY_CLASS**<br><br>0x00000020 | Process with no special scheduling needs. |
| **PROCESS_MODE_BACKGROUND_BEGIN**<br><br>0x00100000 | Begin background processing mode. The system lowers the resource scheduling priorities of the process (and its threads) so that it can perform background work without significantly affecting activity in the foreground.<br><br>This value can be specified only if *hProcess* is a handle to the current process. The function fails if the process is already in background processing mode.<br><br>**Windows Server 2003 and Windows XP:** This value is not supported. |
| **PROCESS_MODE_BACKGROUND_END**<br><br>0x00200000 | End background processing mode. The system restores the resource scheduling priorities of the process (and its threads) as they were before the process entered background processing mode.<br><br>This value can be specified only if *hProcess* is a handle to the current process. The function fails if the process is not in background processing mode.<br><br>**Windows Server 2003 and Windows XP:** This value is not supported. |
| **REALTIME_PRIORITY_CLASS**<br><br>0x00000100 | Process that has the highest possible priority. The threads of the process preempt the threads of all other processes, including operating system processes performing important tasks. For example, a real-time process that executes for more than a very brief interval can cause disk caches not to flush or cause the mouse to be unresponsive. |

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Every thread has a base priority level determined by the thread's priority value and the priority class of its process. The system uses the base priority level of all executable threads to determine which thread gets the next slice of CPU time. The
[SetThreadPriority](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setthreadpriority) function enables setting the base priority level of a thread relative to the priority class of its process. For more information, see
[Scheduling Priorities](https://learn.microsoft.com/windows/desktop/ProcThread/scheduling-priorities).

The ***_PRIORITY_CLASS** values affect the CPU scheduling priority of the process. For processes that perform background work such as file I/O, network I/O, or data processing, it is not sufficient to adjust the CPU scheduling priority; even an idle CPU priority process can easily interfere with system responsiveness when it uses the disk and memory. Processes that perform background work should use the **PROCESS_MODE_BACKGROUND_BEGIN** and **PROCESS_MODE_BACKGROUND_END** values to adjust their resource scheduling priorities; processes that interact with the user should not use **PROCESS_MODE_BACKGROUND_BEGIN**.

If a process is in background processing mode, the new threads it creates will also be in background processing mode. When a thread is in background processing mode, it should minimize sharing resources such as critical sections, heaps, and handles with other threads in the process, otherwise priority inversions can occur. If there are threads executing at high priority, a thread in background processing mode may not be scheduled promptly, but it will never be starved.

Each thread can enter background processing mode independently using [SetThreadPriority](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setthreadpriority). Do not call **SetPriorityClass** to enter background processing mode after a thread in the process has called **SetThreadPriority** to enter background processing mode. After a process ends background processing mode, it resets all threads in the process; however, it is not possible for the process to know which threads were already in background processing mode.

#### Examples

The following example demonstrates the use of process background mode.

```cpp
#include <windows.h>
#include <tchar.h>

int main( void )
{
   DWORD dwError, dwPriClass;

   if(!SetPriorityClass(GetCurrentProcess(), PROCESS_MODE_BACKGROUND_BEGIN))
   {
      dwError = GetLastError();
      if( ERROR_PROCESS_MODE_ALREADY_BACKGROUND == dwError)
         _tprintf(TEXT("Already in background mode\n"));
      else _tprintf(TEXT("Failed to enter background mode (%d)\n"), dwError);
      goto Cleanup;
   }

   // Display priority class

   dwPriClass = GetPriorityClass(GetCurrentProcess());

   _tprintf(TEXT("Current priority class is 0x%x\n"), dwPriClass);

   //
   // Perform background work
   //
   ;

   if(!SetPriorityClass(GetCurrentProcess(), PROCESS_MODE_BACKGROUND_END))
   {
      _tprintf(TEXT("Failed to end background mode (%d)\n"), GetLastError());
   }

Cleanup:
   // Clean up
   ;
return 0;
}

```

## See also

[CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa)

[CreateThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createthread)

[GetPriorityClass](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getpriorityclass)

[GetThreadPriority](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getthreadpriority)

[Process and Thread Functions](https://learn.microsoft.com/windows/desktop/ProcThread/process-and-thread-functions)

[Processes](https://learn.microsoft.com/windows/desktop/ProcThread/child-processes)

[Scheduling Priorities](https://learn.microsoft.com/windows/desktop/ProcThread/scheduling-priorities)

[SetThreadPriority](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setthreadpriority)