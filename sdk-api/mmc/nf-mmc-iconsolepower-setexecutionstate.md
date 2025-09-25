# IConsolePower::SetExecutionState

## Description

The
**SetExecutionState** method sets the execution state for the current thread.

## Parameters

### `dwAdd` [in]

Flags to add to the snap-in execution state. This can be a combination of 0 or more of the following flags.

#### ES_DISPLAY_REQUIRED

The display (monitor) power-management requirement. If specified in *dwAdd*, the snap-in prohibits the operating system from invoking the power management routine for the display.

#### ES_SYSTEM_REQUIRED

The system power-management requirement. If specified in *dwAdd*, the snap-in prohibits the operating system from invoking the power management routine for the system.

### `dwRemove` [in]

Flags to remove from the snap-in's execution-state. This can be a combination of 0 or more of the preceding flags. Specifying one or more of the flags enables a snap-in to turn off a power management requirement established by an earlier call to
**SetExecutionState**.

**Note** A power management requirement must be turned off before it can be turned on. An attempt to turn on a power management requirement without first turning it off returns an error **E_INVALIDARG**.

## Return value

If successful, the return value is **S_OK**. This method will return **S_FALSE** when invoked on a system that does not support power management. Other return values indicate an error code.

## Remarks

Call **IConsolePower::SetExecutionState** instead of
[SetThreadExecutionState](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setthreadexecutionstate). Snap-ins must not call the **SetThreadExecutionState** function directly, doing so causes conflicts if multiple snap-ins are running on the same thread.

A snap-in defines its power requirements and sends them to MMC by calling
**SetExecutionState**. After the snap-in calls
**SetExecutionState**, its execution state remains in effect until the snap-in makes another call to
**SetExecutionState**. Be aware that after **SetExecutionState** is called, the same instance of the [IConsolePower](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iconsolepower) interface must be used for subsequent calls to **SetExecutionState**. If a snap-in does not use the same instance of **IConsolePower**, then MMC cannot effectively call [SetThreadExecutionState](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setthreadexecutionstate). MMC maintains an array to track each snap-in's execution state, and calls **SetThreadExecutionState** for all snap-ins running on the thread.

#### Examples

```cpp
HRESULT hr;

// Specify that the display and system are required.
// pConsolePower was created previously by
// the CoCreateInstance method.
hr = pConsolePower->SetExecutionState(ES_DISPLAY_REQUIRED | ES_SYSTEM_REQUIRED,0);
switch (hr)
{
    case S_OK:
        OutputDebugString(_T("SetExecutionState: Succeeded\n"));
        break;

    case S_FALSE:
        // The system does not support power management.
        OutputDebugString(_T("SetExecutionState: Unsupported\n"));
        break;

    default:
        // Unexpected error occurred.
        OutputDebugString(_T("SetExecutionState: Failure\n"));
        break;
}
```

## See also

[IConsolePower::ResetIdleTimer](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iconsolepower-resetidletimer)

[SetThreadExecutionState](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setthreadexecutionstate)