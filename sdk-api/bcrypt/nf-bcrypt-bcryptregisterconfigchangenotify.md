# BCryptRegisterConfigChangeNotify function

## Description

[**BCryptRegisterConfigChangeNotify** is deprecated beginning with Windows 10.]

The **BCryptRegisterConfigChangeNotify(HANDLE*)** function creates a user mode CNG configuration change event handler.

## Parameters

### `pEvent` [out]

The address of a **HANDLE** variable that receives the event handle. Use one of the [Wait Functions](https://learn.microsoft.com/windows/desktop/Sync/wait-functions), such as [WaitForSingleObject](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-waitforsingleobject), to determine when the event has been signaled. The event is unnamed and must be a manual-reset event. The event is signaled when any CNG configuration data has changed.

This handle must be passed to the [BCryptUnregisterConfigChangeNotify(HANDLE)](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptunregisterconfigchangenotify) function to remove the event notification.

## Return value

Returns a status code that indicates the success or failure of the function.

Possible return codes include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The function was successful. |
| **STATUS_INVALID_PARAMETER** | The *phEvent* parameter is not valid. |
| **STATUS_NO_MEMORY** | A memory allocation failure occurred. |

## Remarks

The handle returned in the variable pointed to by the *phEvent* parameter will be signaled when a change to the CNG configuration occurs.

**BCryptRegisterConfigChangeNotify(HANDLE*)** can be called only in user mode. Code executing in kernel mode must call [BCryptRegisterConfigChangeNotify(PRKEVENT)](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptregisterconfigchangenotify).

## See also

[BCryptUnregisterConfigChangeNotify(HANDLE)](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptunregisterconfigchangenotify)