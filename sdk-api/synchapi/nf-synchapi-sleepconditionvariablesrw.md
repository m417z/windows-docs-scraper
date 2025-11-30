# SleepConditionVariableSRW function

## Description

Sleeps on the specified condition variable and releases the specified lock as an atomic operation.

## Parameters

### `ConditionVariable` [in, out]

A pointer to the condition variable. This variable must be initialized by either calling [InitializeConditionVariable](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-initializeconditionvariable) (to initialize the structure dynamically) or assign the constant CONDITION_VARIABLE_INIT to the structure variable (to initialize the structure statically).

### `SRWLock` [in, out]

A pointer to the lock. This lock must be held in the manner specified by the *Flags* parameter.

### `dwMilliseconds` [in]

The time-out interval, in milliseconds. The function returns if the interval elapses. If *dwMilliseconds* is zero, the function tests the states of the specified objects and returns immediately. If *dwMilliseconds* is **INFINITE**, the function's time-out interval never elapses.

### `Flags` [in]

If this parameter is **CONDITION_VARIABLE_LOCKMODE_SHARED**, the SRW lock is in shared mode. Otherwise, the lock is in exclusive mode.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is `0`. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

If the timeout expires the function returns `FALSE` and [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns **ERROR_TIMEOUT**.

## Remarks

If the lock is unlocked when this function is called, the function behavior is undefined.

The thread can be woken using the [WakeConditionVariable](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-wakeconditionvariable) or [WakeAllConditionVariable](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-wakeallconditionvariable) function. After the thread is woken, it re-acquires the lock it released when the thread entered the sleeping state.

Condition variables are subject to spurious wakeups (those not associated with an explicit wake) and stolen wakeups (another thread manages to run before the woken thread). Therefore, you should recheck a predicate (typically in a `while` loop) after a sleep operation returns.

## See also

[Slim Reader/Writer (SRW) Locks](https://learn.microsoft.com/windows/win32/Sync/slim-reader-writer--srw--locks)

[Synchronization Functions](https://learn.microsoft.com/windows/win32/Sync/synchronization-functions)

[Vertdll APIs available in VBS enclaves](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-available-in-vertdll)