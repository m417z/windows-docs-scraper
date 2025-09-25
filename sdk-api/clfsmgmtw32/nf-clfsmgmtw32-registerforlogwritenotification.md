# RegisterForLogWriteNotification function

## Description

The **RegisterForLogWriteNotification** function is
called by a managed log client to enable or disable log write notifications.

## Parameters

### `hLog` [in]

A handle to the log on which to resolve the log full condition.

### `cbThreshold` [in]

Number of bytes to be written to the log file before the notification is sent.

### `fEnable` [in]

If **TRUE**, the notification is enabled. If **FALSE**, the notification is disabled.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). Valid values include the following:

## See also

[CLFS Management Functions](https://learn.microsoft.com/previous-versions/windows/desktop/clfs/clfs-management-functions)