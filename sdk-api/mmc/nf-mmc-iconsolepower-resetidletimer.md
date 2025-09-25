# IConsolePower::ResetIdleTimer

## Description

The
ResetIdleTimer method resets the specified power management idle timers.

## Parameters

### `dwFlags` [in]

The flags used to reset idle timers. One or more of the following flags can be used. For more information, see
[SetThreadExecutionState](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setthreadexecutionstate).

#### ES_DISPLAY_REQUIRED

Resets the display (monitor) idle timer.

#### ES_SYSTEM_REQUIRED

Resets the system idle timer.

## Return value

If successful, the return value is S_OK. This method will return S_FALSE when invoked on a system that does not support power management. Other return values indicate an error code.

## Remarks

Call **IConsolePower::ResetIdleTimer** instead of calling
[SetThreadExecutionState](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setthreadexecutionstate). Snap-ins must not call the **SetThreadExecutionState** function directly, doing so causes conflicts if multiple snap-ins are running on the same thread. Instead, snap-ins should call
SetExecutionState. Resetting an idle timer causes it to start over in tracking the idle period. If a snap-in does not specify a continuous execution state by calling [IConsolePower::SetExecutionState](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iconsolepower-setexecutionstate), it can periodically call
ResetIdleTimer to prolong the time before the system or display power-management routines are invoked.

#### Examples

```cpp
HRESULT hr;

// Reset both the display and system idle timers.
// pConsolePower was created previously by
// the CoCreateInstance method.
hr = pConsolePower->ResetIdleTimer(
             ES_DISPLAY_REQUIRED | ES_SYSTEM_REQUIRED);
switch (hr)
{
    case S_OK:
        OutputDebugString(_T("ResetIdleTimer: Succeeded\n"));
        break;

    case S_FALSE:
        // The system does not support power management.
        OutputDebugString(_T("ResetIdleTimer: Unsupported\n"));
        break;

    default:
        // Unexpected error occurred.
        OutputDebugString(_T("ResetIdleTimer: Failure\n"));
        break;
}
```

## See also

[IConsolePower::SetExecutionState](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iconsolepower-setexecutionstate)

[SetThreadExecutionState](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setthreadexecutionstate)