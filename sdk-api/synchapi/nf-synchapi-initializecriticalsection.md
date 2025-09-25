# InitializeCriticalSection function

## Description

Initializes a critical section object.

## Parameters

### `lpCriticalSection` [out]

A pointer to the critical section object.

## Return value

This function does not return a value.

**Windows Server 2003 and Windows XP:** In low memory situations, **InitializeCriticalSection** can raise a **STATUS_NO_MEMORY** exception. Starting with Windows Vista, this exception was eliminated and **InitializeCriticalSection** always succeeds, even in low memory situations.

## Remarks

The threads of a single process can use a critical section object for mutual-exclusion synchronization. There is no guarantee about the order in which threads will obtain ownership of the critical section, however, the system will be fair to all threads.

The process is responsible for allocating the memory used by a critical section object, which it can do by declaring a variable of type **CRITICAL_SECTION**. Before using a critical section, some thread of the process must initialize the object.

After a critical section object has been initialized, the threads of the process can specify the object in the [EnterCriticalSection](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-entercriticalsection), [TryEnterCriticalSection](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-tryentercriticalsection), or [LeaveCriticalSection](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-leavecriticalsection) function to provide mutually exclusive access to a shared resource. For similar synchronization between the threads of different processes, use a mutex object.

A critical section object cannot be moved or copied. The process must also not modify the object, but must treat it as logically opaque. Use only the critical section functions to manage critical section objects. When you have finished using the critical section, call the [DeleteCriticalSection](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-deletecriticalsection) function.

A critical section object must be deleted before it can be reinitialized. Initializing a critical section that has already been initialized results in undefined behavior.

## See also

[CreateMutex](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-createmutexa)

[Critical Section Objects](https://learn.microsoft.com/windows/win32/Sync/critical-section-objects)

[DeleteCriticalSection](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-deletecriticalsection)

[EnterCriticalSection](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-entercriticalsection)

[InitializeCriticalSectionAndSpinCount](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-initializecriticalsectionandspincount)

[LeaveCriticalSection](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-leavecriticalsection)

[Synchronization Functions](https://learn.microsoft.com/windows/win32/Sync/synchronization-functions)

[TryEnterCriticalSection](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-tryentercriticalsection)

[Vertdll APIs available in VBS enclaves](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-available-in-vertdll)