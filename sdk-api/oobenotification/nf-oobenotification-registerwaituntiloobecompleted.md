# RegisterWaitUntilOOBECompleted function

## Description

Registers a callback to be called once OOBE (Windows Welcome) has been completed.

## Parameters

### `OOBECompletedCallback`

Pointer to an application-defined callback function that will be called upon completion of OOBE. For more information, see [OOBE_COMPLETED_CALLBACK](https://learn.microsoft.com/previous-versions/windows/desktop/api/oobenotification/nc-oobenotification-oobe_completed_callback).

### `CallbackContext`

Pointer to the callback context. This value will be passed to the function specified by *OOBECompletedCallback*. This value can be **null**.

### `WaitHandle`

Pointer to a variable that will receive the handle to the wait callback registration.

## Return value

**TRUE** if the routine successfully registered the callback. Otherwise, **FALSE** is returned. If **FALSE**, [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) will retrieve extended error information.

## Remarks

If **RegisterWaitUntilOOBECompleted** returns **FALSE**, and a subsequent call to [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns a value of **ERROR_INVALID_STATE**, this indicates that OOBE is already complete and there is no need to register for OOBE completion.