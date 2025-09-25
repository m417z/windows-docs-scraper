# EnterCriticalSection function

## Description

Waits for ownership of the specified critical section object. The function returns when the calling thread is granted ownership.

## Parameters

### `lpCriticalSection` [in, out]

A pointer to the critical section object.

## Return value

This function does not return a value.

This function can raise **EXCEPTION_POSSIBLE_DEADLOCK**, also known as **STATUS_POSSIBLE_DEADLOCK**, if a wait operation on the critical section times out. The timeout interval is specified by the following registry value: **HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\Session Manager**\**CriticalSectionTimeout**. Do not handle a possible deadlock exception; instead, debug the application.

## Remarks

The threads of a single process can use a critical section object for mutual-exclusion synchronization. The process is responsible for allocating the memory used by a critical section object, which it can do by declaring a variable of type **CRITICAL_SECTION**. Before using a critical section, some thread of the process must call [InitializeCriticalSection](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-initializecriticalsection) or [InitializeCriticalSectionAndSpinCount](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-initializecriticalsectionandspincount) to initialize the object.

To enable mutually exclusive access to a shared resource, each thread calls the **EnterCriticalSection** or [TryEnterCriticalSection](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-tryentercriticalsection) function to request ownership of the critical section before executing any section of code that accesses the protected resource. The difference is that **TryEnterCriticalSection** returns immediately, regardless of whether it obtained ownership of the critical section, while **EnterCriticalSection** blocks until the thread can take ownership of the critical section. When it has finished executing the protected code, the thread uses the [LeaveCriticalSection](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-leavecriticalsection) function to relinquish ownership, enabling another thread to become owner and access the protected resource. There is no guarantee about the order in which waiting threads will acquire ownership of the critical section.

After a thread has ownership of a critical section, it can make additional calls to **EnterCriticalSection** or [TryEnterCriticalSection](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-tryentercriticalsection) without blocking its execution. This prevents a thread from deadlocking itself while waiting for a critical section that it already owns. The thread enters the critical section each time **EnterCriticalSection** and **TryEnterCriticalSection** succeed. A thread must call [LeaveCriticalSection](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-leavecriticalsection) once for each time that it entered the critical section.

Any thread of the process can use the [DeleteCriticalSection](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-deletecriticalsection) function to release the system resources that were allocated when the critical section object was initialized. After this function has been called, the critical section object can no longer be used for synchronization.

If a thread terminates while it has ownership of a critical section, the state of the critical section is undefined.

If a critical section is deleted while it is still owned, the state of the threads waiting for ownership of the deleted critical section is undefined.

While a process is exiting, if a call to **EnterCriticalSection** would block, it will instead terminate the process immediately. This may cause global destructors to not be called.

#### Examples

For an example that uses **EnterCriticalSection**, see [Using Critical Section Objects](https://learn.microsoft.com/windows/win32/Sync/using-critical-section-objects).

## See also

[Critical Section Objects](https://learn.microsoft.com/windows/win32/Sync/critical-section-objects)

[DeleteCriticalSection](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-deletecriticalsection)

[InitializeCriticalSection](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-initializecriticalsection)

[InitializeCriticalSectionAndSpinCount](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-initializecriticalsectionandspincount)

[LeaveCriticalSection](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-leavecriticalsection)

[Synchronization Functions](https://learn.microsoft.com/windows/win32/Sync/synchronization-functions)

[TryEnterCriticalSection](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-tryentercriticalsection)

[Vertdll APIs available in VBS enclaves](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-available-in-vertdll)