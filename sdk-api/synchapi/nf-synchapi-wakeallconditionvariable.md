# WakeAllConditionVariable function

## Description

Wake all threads waiting on the specified condition variable.

## Parameters

### `ConditionVariable` [in, out]

A pointer to the condition variable.

## Remarks

The **WakeAllConditionVariable** wakes all waiting threads while the [WakeConditionVariable](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-wakeconditionvariable) wakes only a single thread. Waking one thread is similar to setting an auto-reset event, while waking all threads is similar to pulsing a manual reset event but more reliable (see [PulseEvent](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-pulseevent) for details).

## See also

[Condition Variables](https://learn.microsoft.com/windows/win32/Sync/condition-variables)

[Synchronization Functions](https://learn.microsoft.com/windows/win32/Sync/synchronization-functions)

[Vertdll APIs available in VBS enclaves](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-available-in-vertdll)