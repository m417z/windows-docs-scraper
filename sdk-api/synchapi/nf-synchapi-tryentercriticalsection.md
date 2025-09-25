# TryEnterCriticalSection function

## Description

Attempts to enter a critical section without blocking. If the call is successful, the calling thread takes ownership of the critical section.

## Parameters

### `lpCriticalSection` [in, out]

A pointer to the critical section object.

## Return value

If the critical section is successfully entered or the current thread already owns the critical section, the return value is nonzero.

If another thread already owns the critical section, the return value is zero.

## Remarks

The threads of a single process can use a critical section object for mutual-exclusion synchronization. The process is responsible for allocating the memory used by a critical section object, which it can do by declaring a variable of type **CRITICAL_SECTION**. Before using a critical section, some thread of the process must call the [InitializeCriticalSection](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-initializecriticalsection) or [InitializeCriticalSectionAndSpinCount](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-initializecriticalsectionandspincount) function to initialize the object.

To enable mutually exclusive use of a shared resource, each thread calls the [EnterCriticalSection](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-entercriticalsection) or **TryEnterCriticalSection** function to request ownership of the critical section before executing any section of code that uses the protected resource. The difference is that **TryEnterCriticalSection** returns immediately, regardless of whether it obtained ownership of the critical section, while **EnterCriticalSection** blocks until the thread can take ownership of the critical section. When it has finished executing the protected code, the thread uses the [LeaveCriticalSection](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-leavecriticalsection) function to relinquish ownership, enabling another thread to become the owner and gain access to the protected resource. The thread must call **LeaveCriticalSection** once for each time that it entered the critical section.

Any thread of the process can use the [DeleteCriticalSection](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-deletecriticalsection) function to release the system resources that were allocated when the critical section object was initialized. After this function has been called, the critical section object can no longer be used for synchronization.

If a thread terminates while it has ownership of a critical section, the state of the critical section is undefined.

To compile an application that uses this function, define **_WIN32_WINNT** as `0x0400` or later. For more information, see [Using the Windows Headers](https://learn.microsoft.com/windows/win32/WinProg/using-the-windows-headers).

## See also

[Critical Section Objects](https://learn.microsoft.com/windows/win32/Sync/critical-section-objects)

[DeleteCriticalSection](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-deletecriticalsection)

[EnterCriticalSection](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-entercriticalsection)

[InitializeCriticalSection](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-initializecriticalsection)

[InitializeCriticalSectionAndSpinCount](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-initializecriticalsectionandspincount)

[LeaveCriticalSection](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-leavecriticalsection)

[Synchronization Functions](https://learn.microsoft.com/windows/win32/Sync/synchronization-functions)

[Vertdll APIs available in VBS enclaves](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-available-in-vertdll)