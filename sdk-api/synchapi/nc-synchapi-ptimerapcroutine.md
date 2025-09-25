# PTIMERAPCROUTINE callback function

## Description

An application-defined timer completion routine. Specify this address when calling the
[SetWaitableTimer](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-setwaitabletimer) function. The **PTIMERAPCROUTINE** type defines a pointer to this callback function.
**TimerAPCProc** is a placeholder for the application-defined function name.

## Parameters

### `lpArgToCompletionRoutine` [in, optional]

The value passed to the function using the *lpArgToCompletionRoutine* parameter of the
[SetWaitableTimer](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-setwaitabletimer) function.

### `dwTimerLowValue` [in]

The low-order portion of the UTC-based time at which the timer was signaled. This value corresponds to the **dwLowDateTime** member of the
[FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure. For more information about UTC-based time, see
[System Time](https://learn.microsoft.com/windows/desktop/SysInfo/system-time).

### `dwTimerHighValue` [in]

The high-order portion of the UTC-based time at which the timer was signaled. This value corresponds to the **dwHighDateTime** member of the [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure.

## Remarks

The completion routine is executed by the thread that activates the timer using
[SetWaitableTimer](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-setwaitabletimer). However, the thread must be in an alertable state. For more information, see
[Asynchronous Procedure Calls](https://learn.microsoft.com/windows/desktop/Sync/asynchronous-procedure-calls).

#### Examples

For an example, see
[Using a Waitable Timer with an Asynchronous Procedure Call](https://learn.microsoft.com/windows/desktop/Sync/using-a-waitable-timer-with-an-asynchronous-procedure-call).

## See also

[SetWaitableTimer](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-setwaitabletimer)