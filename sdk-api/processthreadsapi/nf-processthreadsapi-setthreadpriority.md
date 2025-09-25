# SetThreadPriority function

## Description

Sets the priority value for the specified thread. This value, together with the priority class of the thread's process, determines the thread's base priority level.

## Parameters

### `hThread` [in]

A handle to the thread whose priority value is to be set.

The handle must have the **THREAD_SET_INFORMATION** or **THREAD_SET_LIMITED_INFORMATION** access right. For more information, see
[Thread Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/thread-security-and-access-rights).**Windows Server 2003:** The handle must have the **THREAD_SET_INFORMATION** access right.

### `nPriority` [in]

The priority value for the thread. This parameter can be one of the following values.

| Priority | Meaning |
| --- | --- |
| **THREAD_MODE_BACKGROUND_BEGIN**<br><br>0x00010000 | Begin background processing mode. The system lowers the resource scheduling priorities of the thread so that it can perform background work without significantly affecting activity in the foreground.<br><br>This value can be specified only if *hThread* is a handle to the current thread. The function fails if the thread is already in background processing mode.<br><br>**Windows Server 2003:** This value is not supported. |
| **THREAD_MODE_BACKGROUND_END**<br><br>0x00020000 | End background processing mode. The system restores the resource scheduling priorities of the thread as they were before the thread entered background processing mode.<br><br>This value can be specified only if *hThread* is a handle to the current thread. The function fails if the thread is not in background processing mode.<br><br>**Windows Server 2003:** This value is not supported. |
| **THREAD_PRIORITY_ABOVE_NORMAL**<br><br>1 | Priority 1 point above the priority class. |
| **THREAD_PRIORITY_BELOW_NORMAL**<br><br>-1 | Priority 1 point below the priority class. |
| **THREAD_PRIORITY_HIGHEST**<br><br>2 | Priority 2 points above the priority class. |
| **THREAD_PRIORITY_IDLE**<br><br>-15 | Base priority of 1 for **IDLE_PRIORITY_CLASS**, **BELOW_NORMAL_PRIORITY_CLASS**, **NORMAL_PRIORITY_CLASS**, **ABOVE_NORMAL_PRIORITY_CLASS**, or **HIGH_PRIORITY_CLASS** processes, and a base priority of 16 for **REALTIME_PRIORITY_CLASS** processes. |
| **THREAD_PRIORITY_LOWEST**<br><br>-2 | Priority 2 points below the priority class. |
| **THREAD_PRIORITY_NORMAL**<br><br>0 | Normal priority for the priority class. |
| **THREAD_PRIORITY_TIME_CRITICAL**<br><br>15 | Base priority of 15 for **IDLE_PRIORITY_CLASS**, **BELOW_NORMAL_PRIORITY_CLASS**, **NORMAL_PRIORITY_CLASS**, **ABOVE_NORMAL_PRIORITY_CLASS**, or **HIGH_PRIORITY_CLASS** processes, and a base priority of 31 for **REALTIME_PRIORITY_CLASS** processes. |

If the thread has the **REALTIME_PRIORITY_CLASS** base class, this parameter can also be -7, -6, -5, -4, -3, 3, 4, 5, or 6. For more information, see
[Scheduling Priorities](https://learn.microsoft.com/windows/desktop/ProcThread/scheduling-priorities).

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

**Windows Phone 8.1:** Windows Phone Store apps may call this function but it has no effect. The function will return a nonzero value indicating success.

## Remarks

Every thread has a base priority level determined by the thread's priority value and the priority class of its process. The system uses the base priority level of all executable threads to determine which thread gets the next slice of CPU time. Threads are scheduled in a round-robin fashion at each priority level, and only when there are no executable threads at a higher level does scheduling of threads at a lower level take place.

The
**SetThreadPriority** function enables setting the base priority level of a thread relative to the priority class of its process. For example, specifying **THREAD_PRIORITY_HIGHEST** in a call to
**SetThreadPriority** for a thread of an **IDLE_PRIORITY_CLASS** process sets the thread's base priority level to 6. For a table that shows the base priority levels for each combination of priority class and thread priority value, see
[Scheduling Priorities](https://learn.microsoft.com/windows/desktop/ProcThread/scheduling-priorities).

For **IDLE_PRIORITY_CLASS**, **BELOW_NORMAL_PRIORITY_CLASS**, **NORMAL_PRIORITY_CLASS**, **ABOVE_NORMAL_PRIORITY_CLASS**, and **HIGH_PRIORITY_CLASS** processes, the system dynamically boosts a thread's base priority level when events occur that are important to the thread. **REALTIME_PRIORITY_CLASS** processes do not receive dynamic boosts.

All threads initially start at **THREAD_PRIORITY_NORMAL**. Use the
[GetPriorityClass](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getpriorityclass) and
[SetPriorityClass](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setpriorityclass) functions to get and set the priority class of a process. Use the
[GetThreadPriority](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getthreadpriority) function to get the priority value of a thread.

Use the priority class of a process to differentiate between applications that are time critical and those that have normal or below normal scheduling requirements. Use thread priority values to differentiate the relative priorities of the tasks of a process. For example, a thread that handles input for a window could have a higher priority level than a thread that performs intensive calculations for the CPU.

When manipulating priorities, be very careful to ensure that a high-priority thread does not consume all of the available CPU time. A thread with a base priority level above 11 interferes with the normal operation of the operating system. Using **REALTIME_PRIORITY_CLASS** may cause disk caches to not flush, cause the mouse to stop responding, and so on.

The **THREAD_PRIORITY_*** values affect the CPU scheduling priority of the thread. For threads that perform background work such as file I/O, network I/O, or data processing, it is not sufficient to adjust the CPU scheduling priority; even an idle CPU priority thread can easily interfere with system responsiveness when it uses the disk and memory. Threads that perform background work should use the **THREAD_MODE_BACKGROUND_BEGIN** and **THREAD_MODE_BACKGROUND_END** values to adjust their resource scheduling priorities; threads that interact with the user should not use **THREAD_MODE_BACKGROUND_BEGIN**.

When a thread is in background processing mode, it should minimize sharing resources such as critical sections, heaps, and handles with other threads in the process, otherwise priority inversions can occur. If there are threads executing at high priority, a thread in background processing mode may not be scheduled promptly, but it will never be starved.

**Windows Server 2008 and Windows Vista:** While the system is starting, the **SetThreadPriority** function returns a success return value but does not change thread priority for applications that are started from the system Startup folder or listed in the **HKEY_LOCAL_MACHINE**\**SOFTWARE**\**Microsoft**\**Windows**\**CurrentVersion**\**Run** registry key. These applications run at reduced priority for a short time (approximately 60 seconds) to make the system more responsive to user actions during startup.

**Windows 8.1** and **Windows Server 2012 R2**: This function is supported for Windows Store apps.

**Windows Phone 8.1:**Windows Phone Store apps may call this function but it has no effect.

#### Examples

The following example demonstrates the use of thread background mode.

```cpp
#include <windows.h>
#include <tchar.h>

int main( void )
{
   DWORD dwError, dwThreadPri;

   if(!SetThreadPriority(GetCurrentThread(), THREAD_MODE_BACKGROUND_BEGIN))
   {
      dwError = GetLastError();
      if( ERROR_THREAD_MODE_ALREADY_BACKGROUND == dwError)
         _tprintf(TEXT("Already in background mode\n"));
      else _tprintf(TEXT("Failed to enter background mode (%d)\n"), dwError);
      goto Cleanup;
   }

   // Display thread priority

   dwThreadPri = GetThreadPriority(GetCurrentThread());

   _tprintf(TEXT("Current thread priority is 0x%x\n"), dwThreadPri);

   //
   // Perform background work
   //
   ;

   if(!SetThreadPriority(GetCurrentThread(), THREAD_MODE_BACKGROUND_END))
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

[GetPriorityClass](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getpriorityclass)

[GetThreadPriority](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getthreadpriority)

[Process and Thread Functions](https://learn.microsoft.com/windows/desktop/ProcThread/process-and-thread-functions)

[Scheduling Priorities](https://learn.microsoft.com/windows/desktop/ProcThread/scheduling-priorities)

[SetPriorityClass](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setpriorityclass)

[Threads](https://learn.microsoft.com/windows/desktop/ProcThread/multiple-threads)