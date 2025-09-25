# BCryptUnregisterConfigChangeNotify function

## Description

The **BCryptUnregisterConfigChangeNotify(HANDLE)** function removes a user mode CNG configuration change event handler that was created by using the [BCryptRegisterConfigChangeNotify(HANDLE*)](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptregisterconfigchangenotify) function.

## Parameters

### `pEvent` [in]

The handle of the event to remove. This is the handle that was obtained by using the [BCryptRegisterConfigChangeNotify(HANDLE*)](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptregisterconfigchangenotify) function.

## Return value

Returns a status code that indicates the success or failure of the function.

Possible return codes include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The function was successful. |
| **STATUS_INVALID_PARAMETER** | The *hEvent* parameter is not valid. |
| **STATUS_NO_MEMORY** | A memory allocation failure occurred. |

## Remarks

**BCryptUnregisterConfigChangeNotify(HANDLE)** can be called only in user mode. Code executing in kernel mode must call [BCryptUnregisterConfigChangeNotify(PRKEVENT)](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptunregisterconfigchangenotify).

## See also

[BCryptRegisterConfigChangeNotify(HANDLE*)](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptregisterconfigchangenotify)