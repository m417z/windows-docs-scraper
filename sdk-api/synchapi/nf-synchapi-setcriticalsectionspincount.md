# SetCriticalSectionSpinCount function

## Description

Sets the spin count for the specified critical section. Spinning means that when a thread tries to acquire a critical section that is locked, the thread enters a loop, checks to see if the lock is released, and if the lock is not released, the thread goes to sleep.

## Parameters

### `lpCriticalSection` [in, out]

A pointer to the critical section object.

### `dwSpinCount` [in]

The spin count for the critical section object. On single-processor systems, the spin count is ignored and the critical section spin count is set to zero (0). On multiprocessor systems, if the critical section is unavailable, the calling thread spins *dwSpinCount* times before performing a wait operation on a semaphore associated with the critical section. If the critical section becomes free during the spin operation, the calling thread avoids the wait operation.

## Return value

The function returns the previous spin count for the critical section.

## Remarks

The threads of a single process can use a critical section object for mutual-exclusion synchronization. The process is responsible for allocating the memory used by a critical section object, which it can do by declaring a variable of type **CRITICAL_SECTION**. Before using a critical section, some thread of the process must call the [InitializeCriticalSection](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-initializecriticalsection) or [InitializeCriticalSectionAndSpinCount](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-initializecriticalsectionandspincount) function to initialize the object. You can subsequently modify the spin count by calling the **SetCriticalSectionSpinCount** function.

The spin count is useful for critical sections of short duration that can experience high levels of contention. Consider a worst-case scenario, in which an application on an SMP system has two or three threads constantly allocating and releasing memory from the heap. The application serializes the heap with a critical section. In the worst-case scenario, contention for the critical section is constant, and each thread makes a processing-intensive call to the [WaitForSingleObject](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-waitforsingleobject) function. However, if the spin count is set properly, the calling thread does not immediately call **WaitForSingleObject** when contention occurs. Instead, the calling thread can acquire ownership of the critical section if it is released during the spin operation.

You can improve performance significantly by choosing a small spin count for a critical section of short duration. The heap manager uses a spin count of roughly 4000 for its per-heap critical sections. This gives great performance and scalability in almost all worst-case scenarios.

To compile an application that uses this function, define **_WIN32_WINNT** as `0x0403` or later. For more information, see [Using the Windows Headers](https://learn.microsoft.com/windows/win32/WinProg/using-the-windows-headers).

## See also

[Critical Section Objects](https://learn.microsoft.com/windows/win32/Sync/critical-section-objects)

[InitializeCriticalSection](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-initializecriticalsection)

[InitializeCriticalSectionAndSpinCount](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-initializecriticalsectionandspincount)

[WaitForSingleObject](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-waitforsingleobject)

[Synchronization Functions](https://learn.microsoft.com/windows/win32/Sync/synchronization-functions)

[Vertdll APIs available in VBS enclaves](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-available-in-vertdll)