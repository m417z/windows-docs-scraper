# InitializeConditionVariable function

## Description

Initializes a condition variable.

## Parameters

### `ConditionVariable` [out]

A pointer to the condition variable.

## Remarks

Threads can atomically release a lock and enter the sleeping state using the [SleepConditionVariableCS](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-sleepconditionvariablecs) or [SleepConditionVariableSRW](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-sleepconditionvariablesrw) function. The threads are woken using the [WakeConditionVariable](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-wakeconditionvariable) or [WakeAllConditionVariable](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-wakeallconditionvariable) function.

Condition variables are user-mode objects that cannot be shared across processes.

A condition variable cannot be moved or copied while in use. The process must not modify the object, and must instead treat it as logically opaque. Only use the condition variable functions to manage condition variables.

A condition variable with no waiting threads is in its initial state and can be copied, moved, and forgotten without being explicitly destroyed.

#### Examples

For an example that uses this function, see [Using Condition Variables](https://learn.microsoft.com/windows/win32/Sync/using-condition-variables).

## See also

[Condition Variables](https://learn.microsoft.com/windows/win32/Sync/condition-variables)

[Synchronization Functions](https://learn.microsoft.com/windows/win32/Sync/synchronization-functions)

[Vertdll APIs available in VBS enclaves](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-available-in-vertdll)