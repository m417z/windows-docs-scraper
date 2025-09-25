# SleepEx function

## Description

Suspends the current thread until the specified condition is met. Execution resumes when one of the following occurs:

* An I/O completion callback function is called.
* An asynchronous procedure call (APC) is queued to the thread.
* The time-out interval elapses.

## Parameters

### `dwMilliseconds` [in]

The time interval for which execution is to be suspended, in milliseconds.

A value of zero causes the thread to relinquish the remainder of its time slice to any other thread that is ready to run. If there are no other threads ready to run, the function returns immediately, and the thread continues execution.**Windows XP:** A value of zero causes the thread to relinquish the remainder of its time slice to any other thread of equal priority that is ready to run. If there are no other threads of equal priority ready to run, the function returns immediately, and the thread continues execution. This behavior changed starting with Windows Server 2003.

A value of INFINITE indicates that the suspension should not time out.

### `bAlertable` [in]

If this parameter is FALSE, the function does not return until the time-out period has elapsed. If an I/O completion callback occurs, the function does not immediately return and the I/O completion function is not executed. If an APC is queued to the thread, the function does not immediately return and the APC function is not executed.

If the parameter is TRUE and the thread that called this function is the same thread that called the extended I/O function ([ReadFileEx](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-readfileex) or
[WriteFileEx](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-writefileex)), the function returns when either the time-out period has elapsed or when an I/O completion callback function occurs. If an I/O completion callback occurs, the I/O completion function is called. If an APC is queued to the thread ([QueueUserAPC](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-queueuserapc)), the function returns when either the time-out period has elapsed or when the APC function is called.

## Return value

The return value is zero if the specified time interval expired.

The return value is **WAIT_IO_COMPLETION** if the function returned due to one or more I/O completion callback functions. This can happen only if *bAlertable* is TRUE, and if the thread that called the
**SleepEx** function is the same thread that called the extended I/O function.

## Remarks

This function causes a thread to relinquish the remainder of its time slice and become unrunnable for an interval based on the value of *dwMilliseconds*. After the sleep interval has passed, the thread is ready to run. Note that a ready thread is not guaranteed to run immediately. Consequently, the thread will not run until some arbitrary time after the sleep interval elapses, based upon the system "tick" frequency and the load factor from other processes. The system clock "ticks" at a constant rate. To increase the accuracy of the sleep interval, call the **timeGetDevCaps** function to determine the supported minimum timer resolution and the **timeBeginPeriod** function to set the timer resolution to its minimum. Use caution when calling **timeBeginPeriod**, as frequent calls can significantly affect the system clock, system power usage, and the scheduler. If you call **timeBeginPeriod**, call it one time early in the application and be sure to call the **timeEndPeriod** function at the very end of the application. If you specify 0 milliseconds, the thread will relinquish the remainder of its time slice but remain ready. For more information, see
[Scheduling Priorities](https://learn.microsoft.com/windows/desktop/ProcThread/scheduling-priorities).

This function can be used with the [ReadFileEx](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-readfileex) or [WriteFileEx](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-writefileex) functions to suspend a thread until an I/O operation has been completed. These functions specify a completion routine that is to be executed when the I/O operation has been completed. For the completion routine to be executed, the thread that called the I/O function must be in an alertable wait state when the completion callback function occurs. A thread goes into an alertable wait state by calling either
**SleepEx**,
[MsgWaitForMultipleObjectsEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-msgwaitformultipleobjectsex),
[WaitForSingleObjectEx](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-waitforsingleobjectex), or
[WaitForMultipleObjectsEx](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-waitformultipleobjectsex), with the function's *bAlertable* parameter set to TRUE.

Be careful when using **SleepEx** in the following scenarios:

* Code that directly or indirectly creates windows (for example, DDE and COM **CoInitialize**). If a thread creates any windows, it must process messages. Message broadcasts are sent to all windows in the system. If you have a thread that uses
  **SleepEx** with infinite delay, the system will deadlock.
* Threads that are under concurrency control. For example, an I/O completion port or thread pool limits the number of associated threads that can run. If the maximum number of threads is already running, no additional associated thread can run until a running thread finishes. If a thread uses **SleepEx** with an interval of zero to wait for one of the additional associated threads to accomplish some work, the process might deadlock.

For these scenarios, use
[MsgWaitForMultipleObjects](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-msgwaitformultipleobjects) or
[MsgWaitForMultipleObjectsEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-msgwaitformultipleobjectsex), rather than
**SleepEx**.

**Windows Phone 8.1:** This function is supported for Windows Phone Store apps on Windows Phone 8.1 and later.

**Windows 8.1** and **Windows Server 2012 R2**: This function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

## See also

[MsgWaitForMultipleObjects](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-msgwaitformultipleobjects)

[MsgWaitForMultipleObjectsEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-msgwaitformultipleobjectsex)

[Process and Thread Functions](https://learn.microsoft.com/windows/desktop/ProcThread/process-and-thread-functions)

[QueueUserAPC](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-queueuserapc)

[ReadFileEx](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-readfileex)

[Sleep](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-sleep)

[Suspending Thread Execution](https://learn.microsoft.com/windows/desktop/ProcThread/suspending-thread-execution)

[Threads](https://learn.microsoft.com/windows/desktop/ProcThread/multiple-threads)

[WaitForMultipleObjectsEx](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-waitformultipleobjectsex)

[WaitForSingleObjectEx](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-waitforsingleobjectex)

[WaitOnAddress](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-waitonaddress)

[WriteFileEx](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-writefileex)