# UnregisterGPNotification function

## Description

The
**UnregisterGPNotification** function unregisters the specified policy-notification handle from receiving policy change notifications.

## Parameters

### `hEvent` [in]

Policy-notification handle passed to the
[RegisterGPNotification](https://learn.microsoft.com/windows/desktop/api/userenv/nf-userenv-registergpnotification) function.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The caller must call the
[CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle) function to close the handle when it is no longer needed.

## See also

[Group Policy
Functions](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/group-policy-functions)

[Group Policy
Overview](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/about-group-policy)

[RegisterGPNotification](https://learn.microsoft.com/windows/desktop/api/userenv/nf-userenv-registergpnotification)