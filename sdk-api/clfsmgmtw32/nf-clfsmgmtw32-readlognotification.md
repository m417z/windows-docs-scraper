# ReadLogNotification function

## Description

The **ReadLogNotification** function retrieves notifications from the log manager. It retrieves a queued notification from the log manager immediately if a notification is available; otherwise the request remains pending until a notification is generated.

## Parameters

### `hLog` [in]

The handle to the log.

### `pNotification` [out]

Receives the notification type, and if the type has parameters associated with it, the parameters.

### `lpOverlapped` [in]

A pointer to an [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure that is required for asynchronous operation. If asynchronous operation is not used, this parameter can be **NULL**.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). The following is a possible error code:

## Remarks

If the log handle is not created with the **FILE_FLAG_OVERLAPPED** file option, no operations can start on the log handle while the call to **ReadLogNotification** is pending.

## See also

[CLFS_MGMT_NOTIFICATION](https://learn.microsoft.com/windows/desktop/api/clfsmgmt/ns-clfsmgmt-clfs_mgmt_notification)

[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped)