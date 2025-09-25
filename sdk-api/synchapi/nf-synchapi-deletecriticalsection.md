# DeleteCriticalSection function

## Description

Releases all resources used by an unowned critical section object.

## Parameters

### `lpCriticalSection` [in, out]

A pointer to the critical section object. The object must have been previously initialized with the [InitializeCriticalSection](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-initializecriticalsection) function.

## Remarks

Deleting a critical section object releases all system resources used by the object. The caller is responsible for ensuring that the critical section object is unowned and the specified CRITICAL_SECTION structure is not being accessed by any critical section functions called by other threads in the process.

After a critical section object has been deleted, do not reference the object in any function that operates on critical sections (such as [EnterCriticalSection](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-entercriticalsection), [TryEnterCriticalSection](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-tryentercriticalsection), and [LeaveCriticalSection](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-leavecriticalsection)) other than [InitializeCriticalSection](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-initializecriticalsection) and [InitializeCriticalSectionAndSpinCount](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-initializecriticalsectionandspincount). If you attempt to do so, memory corruption and other unexpected errors can occur.

If a critical section is deleted while it is still owned, the state of the threads waiting for ownership of the deleted critical section is undefined.

#### Examples

For an example that uses **DeleteCriticalSection**, see [Using Critical Section Objects](https://learn.microsoft.com/windows/win32/Sync/using-critical-section-objects).

## See also

[Critical Section Objects](https://learn.microsoft.com/windows/win32/Sync/critical-section-objects)

[EnterCriticalSection](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-entercriticalsection)

[InitializeCriticalSection](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-initializecriticalsection)

[LeaveCriticalSection](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-leavecriticalsection)

[Synchronization Functions](https://learn.microsoft.com/windows/win32/Sync/synchronization-functions)

[TryEnterCriticalSection](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-tryentercriticalsection)

[Vertdll APIs available in VBS enclaves](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-available-in-vertdll)