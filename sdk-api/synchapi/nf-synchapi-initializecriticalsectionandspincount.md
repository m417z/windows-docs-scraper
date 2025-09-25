# InitializeCriticalSectionAndSpinCount function

## Description

Initializes a critical section object and sets the spin count for the critical section. When a thread tries to acquire a critical section that is locked, the thread *spins*: it enters a loop which iterates spin count times, checking to see if the lock is released. If the lock is not released before the loop finishes, the thread goes to sleep to wait for the lock to be released.

## Parameters

### `lpCriticalSection` [out]

A pointer to the critical section object.

### `dwSpinCount` [in]

The spin count for the critical section object. On single-processor systems, the spin count is ignored and the critical section spin count is set to 0 (zero). On multiprocessor systems, if the critical section is unavailable, the calling thread spins *dwSpinCount* times before performing a wait operation on a semaphore associated with the critical section. If the critical section becomes free during the spin operation, the calling thread avoids the wait operation.

## Return value

This function always succeeds and returns a nonzero value.

**Windows Server 2003 and Windows XP:** If the function succeeds, the return value is nonzero. If the function fails, the return value is zero `0`. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror). Starting with Windows Vista, the **InitializeCriticalSectionAndSpinCount** function always succeeds, even in low memory situations.

## Remarks

The threads of a single process can use a critical section object for mutual-exclusion synchronization. There is no guarantee about the order that threads obtain ownership of the critical section. However, the system is fair to all threads.

The process is responsible for allocating the memory used by a critical section object, which it can do by declaring a variable of type **CRITICAL_SECTION**. Before using a critical section, some thread of the process must initialize the object. You can subsequently modify the spin count by calling the [SetCriticalSectionSpinCount](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-setcriticalsectionspincount) function.

After a critical section object is initialized, the threads of the process can specify the object in the [EnterCriticalSection](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-entercriticalsection), [TryEnterCriticalSection](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-tryentercriticalsection), or [LeaveCriticalSection](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-leavecriticalsection) function to provide mutually exclusive access to a shared resource. For similar synchronization between the threads of different processes, use a mutex object.

A critical section object cannot be moved or copied. The process must also not modify the object, but must treat it as logically opaque. Use only the critical section functions to manage critical section objects. When you have finished using the critical section, call the [DeleteCriticalSection](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-deletecriticalsection) function.

A critical section object must be deleted before it can be reinitialized. Initializing a critical section that is already initialized results in undefined behavior.

The spin count is useful for critical sections of short duration that can experience high levels of contention. Consider a worst-case scenario, in which an application on an SMP system has two or three threads constantly allocating and releasing memory from the heap. The application serializes the heap with a critical section. In the worst-case scenario, contention for the critical section is constant, and each thread makes a processing-intensive call to the [WaitForSingleObject](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-waitforsingleobject) function. However, if the spin count is set properly, the calling thread does not immediately call **WaitForSingleObject** when contention occurs. Instead, the calling thread can acquire ownership of the critical section if it is released during the spin operation.

You can improve performance significantly by choosing a small spin count for a critical section of short duration. For example, the heap manager uses a spin count of roughly 4,000 for its per-heap critical sections.

To compile an application that uses this function, define **_WIN32_WINNT** as `0x0403` or later. For more information, see [Using the Windows Headers](https://learn.microsoft.com/windows/win32/WinProg/using-the-windows-headers).

#### Examples

For an example that uses **InitializeCriticalSectionAndSpinCount**, see [Using Critical Section Objects](https://learn.microsoft.com/windows/win32/Sync/using-critical-section-objects).

## See also

[Critical Section Objects](https://learn.microsoft.com/windows/win32/Sync/critical-section-objects)

[DeleteCriticalSection](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-deletecriticalsection)

[InitializeCriticalSection](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-initializecriticalsection)

[InitializeCriticalSectionEx](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-initializecriticalsectionex)

[SetCriticalSectionSpinCount](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-setcriticalsectionspincount)

[Synchronization Functions](https://learn.microsoft.com/windows/win32/Sync/synchronization-functions)

[WaitForSingleObject](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-waitforsingleobject)

[Vertdll APIs available in VBS enclaves](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-available-in-vertdll)