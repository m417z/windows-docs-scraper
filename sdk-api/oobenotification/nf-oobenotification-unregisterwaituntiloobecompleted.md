# UnregisterWaitUntilOOBECompleted function

## Description

Unregisters the callback previously registered via [RegisterWaitUntilOOBECompleted](https://learn.microsoft.com/previous-versions/windows/desktop/api/oobenotification/nf-oobenotification-registerwaituntiloobecompleted).

## Parameters

### `WaitHandle`

Handle to be unregistered.

## Return value

**TRUE** if the callback was successfully unregistered. Otherwise, **FALSE** is returned. If **FALSE**, [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) will retrieve extended error information.