# Sleep function

## Description

Suspends the execution of the current thread until the time-out interval elapses.

To enter an alertable wait state, use the
[SleepEx](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-sleepex) function.

## Parameters

### `dwMilliseconds` [in]

The time interval for which execution is to be suspended, in milliseconds.

A value of zero causes the thread to relinquish the remainder of its time slice to any other thread that is ready to run. If there are no other threads ready to run, the function returns immediately, and the thread continues execution. **Windows XP:** A value of zero causes the thread to relinquish the remainder of its time slice to any other thread of equal priority that is ready to run. If there are no other threads of equal priority ready to run, the function returns immediately, and the thread continues execution. This behavior changed starting with Windows Server 2003.

A value of INFINITE indicates that the suspension should not time out.

## Remarks

This function causes a thread to relinquish the remainder of its time slice and become unrunnable for an interval based on the value of *dwMilliseconds*. The system clock "ticks" at a constant rate. If *dwMilliseconds* is less than the resolution of the system clock, the thread may sleep for less than the specified length of time. If *dwMilliseconds* is greater than one tick but less than two, the wait can be anywhere between one and two ticks, and so on. To increase the accuracy of the sleep interval, call the **timeGetDevCaps** function to determine the supported minimum timer resolution and the **timeBeginPeriod** function to set the timer resolution to its minimum. Use caution when calling **timeBeginPeriod**, as frequent calls can significantly affect the system clock, system power usage, and the scheduler. If you call **timeBeginPeriod**, call it one time early in the application and be sure to call the **timeEndPeriod** function at the very end of the application.

After the sleep interval has passed, the thread is ready to run. If you specify 0 milliseconds, the thread will relinquish the remainder of its time slice but remain ready. Note that a ready thread is not guaranteed to run immediately. Consequently, the thread may not run until some time after the sleep interval elapses. For more information, see
[Scheduling Priorities](https://learn.microsoft.com/windows/desktop/ProcThread/scheduling-priorities).

Be careful when using **Sleep** in the following scenarios:

* Code that directly or indirectly creates windows (for example, DDE and COM **CoInitialize**). If a thread creates any windows, it must process messages. Message broadcasts are sent to all windows in the system. If you have a thread that uses
  **Sleep** with infinite delay, the system will deadlock.
* Threads that are under concurrency control. For example, an I/O completion port or thread pool limits the number of associated threads that can run. If the maximum number of threads is already running, no additional associated thread can run until a running thread finishes. If a thread uses **Sleep** with an interval of zero to wait for one of the additional associated threads to accomplish some work, the process might deadlock.

For these scenarios, use
[MsgWaitForMultipleObjects](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-msgwaitformultipleobjects) or
[MsgWaitForMultipleObjectsEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-msgwaitformultipleobjectsex), rather than
**Sleep**.

**Windows Phone 8.1:** This function is supported for Windows Phone Store apps on Windows Phone 8.1 and later.

**Windows 8.1** and **Windows Server 2012 R2**: This function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

#### Examples

For an example, see
[Using Thread Local Storage](https://learn.microsoft.com/windows/desktop/ProcThread/using-thread-local-storage).

## See also

[MsgWaitForMultipleObjects](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-msgwaitformultipleobjects)

[MsgWaitForMultipleObjectsEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-msgwaitformultipleobjectsex)

[Process and Thread Functions](https://learn.microsoft.com/windows/desktop/ProcThread/process-and-thread-functions)

[SleepEx](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-sleepex)

[Suspending Thread Execution](https://learn.microsoft.com/windows/desktop/ProcThread/suspending-thread-execution)

[Threads](https://learn.microsoft.com/windows/desktop/ProcThread/multiple-threads)

[WaitOnAddress](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-waitonaddress)