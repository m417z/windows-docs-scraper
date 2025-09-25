# SleepConditionVariableCS function

## Description

Sleeps on the specified condition variable and releases the specified critical section as an atomic operation.

## Parameters

### `ConditionVariable` [in, out]

A pointer to the condition variable. This variable must be initialized using the [InitializeConditionVariable](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-initializeconditionvariable) function.

### `CriticalSection` [in, out]

A pointer to the critical section object. This critical section must be entered exactly once by the caller at the time **SleepConditionVariableCS** is called.

### `dwMilliseconds` [in]

The time-out interval, in milliseconds. If the time-out interval elapses, the function re-acquires the critical section and returns zero. If *dwMilliseconds* is zero, the function tests the states of the specified objects and returns immediately. If *dwMilliseconds* is **INFINITE**, the function's time-out interval never elapses. For more information, see Remarks.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails or the time-out interval elapses, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror). Possible error codes include **ERROR_TIMEOUT**, which indicates that the time-out interval has elapsed before another thread has attempted to wake the sleeping thread.

## Remarks

A thread that is sleeping on a condition variable can be woken before the specified time-out interval has elapsed using the [WakeConditionVariable](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-wakeconditionvariable) or [WakeAllConditionVariable](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-wakeallconditionvariable) function. In this case, the thread wakes when the wake processing is complete, and not when its time-out interval elapses. After the thread is woken, it re-acquires the critical section it released when the thread entered the sleeping state.

Condition variables are subject to spurious wakeups (those not associated with an explicit wake) and stolen wakeups (another thread manages to run before the woken thread). Therefore, you should recheck a predicate (typically in a `while` loop) after a sleep operation returns.

#### Examples

For an example that uses this function, see [Using Condition Variables](https://learn.microsoft.com/windows/win32/Sync/using-condition-variables).

## See also

[Condition Variables](https://learn.microsoft.com/windows/win32/Sync/condition-variables)

[Synchronization Functions](https://learn.microsoft.com/windows/win32/Sync/synchronization-functions)

[Vertdll APIs available in VBS enclaves](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-available-in-vertdll)