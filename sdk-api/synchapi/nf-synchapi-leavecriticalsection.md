# LeaveCriticalSection function

## Description

Releases ownership of the specified critical section object.

## Parameters

### `lpCriticalSection` [in, out]

A pointer to the critical section object.

## Remarks

The threads of a single process can use a critical-section object for mutual-exclusion synchronization. The process is responsible for allocating the memory used by a critical-section object, which it can do by declaring a variable of type **CRITICAL_SECTION**. Before using a critical section, some thread of the process must call the [InitializeCriticalSection](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-initializecriticalsection) or [InitializeCriticalSectionAndSpinCount](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-initializecriticalsectionandspincount) function to initialize the object.

A thread uses the [EnterCriticalSection](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-entercriticalsection) or [TryEnterCriticalSection](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-tryentercriticalsection) function to acquire ownership of a critical section object. To release its ownership, the thread must call **LeaveCriticalSection** once for each time that it entered the critical section.

If a thread calls **LeaveCriticalSection** when it does not have ownership of the specified critical section object, an error occurs that may cause another thread using [EnterCriticalSection](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-entercriticalsection) to wait indefinitely.

**LeaveCriticalSection** does not access the specified **CRITICAL_SECTION** structure after the ownership of a critical section object is released.

Any thread of the process can use the [DeleteCriticalSection](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-deletecriticalsection) function to release the system resources that were allocated when the critical section object was initialized. After this function has been called, the critical section object can no longer be used for synchronization.

#### Examples

For an example that uses **LeaveCriticalSection**, see [Using Critical Section Objects](https://learn.microsoft.com/windows/win32/Sync/using-critical-section-objects).

## See also

[Critical Section Objects](https://learn.microsoft.com/windows/win32/Sync/critical-section-objects)

[DeleteCriticalSection](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-deletecriticalsection)

[EnterCriticalSection](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-entercriticalsection)

[InitializeCriticalSection](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-initializecriticalsection)

[InitializeCriticalSectionAndSpinCount](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-initializecriticalsectionandspincount)

[Synchronization Functions](https://learn.microsoft.com/windows/win32/Sync/synchronization-functions)

[TryEnterCriticalSection](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-tryentercriticalsection)

[Vertdll APIs available in VBS enclaves](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-available-in-vertdll)