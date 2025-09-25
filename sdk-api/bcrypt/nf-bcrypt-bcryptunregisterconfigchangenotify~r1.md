# BCryptUnregisterConfigChangeNotify function

## Description

The **BCryptUnregisterConfigChangeNotify(PRKEVENT)** function removes a kernel mode CNG configuration change event handler that was created by using the [BCryptRegisterConfigChangeNotify(PRKEVENT)](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptregisterconfigchangenotify) function.

## Parameters

### `hEvent`

The pointer to the event dispatcher object to remove.
This is the pointer that was obtained by using the [BCryptRegisterConfigChangeNotify(PRKEVENT)](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptregisterconfigchangenotify) function.

## Return value

Returns a status code that indicates the success or failure of the function.

Possible return codes include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The function was successful. |
| **STATUS_INVALID_PARAMETER** | The *hEvent* parameter is not valid. |
| **STATUS_NO_MEMORY** | A memory allocation failure occurred. |

## Remarks

**BCryptUnregisterConfigChangeNotify(PRKEVENT)** can be called only in kernel mode and at **PASSIVE_LEVEL** IRQL.
Code executing in user mode must call [BCryptUnregisterConfigChangeNotify(HANDLE)](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptregisterconfigchangenotify).

## See also

[BCryptRegisterConfigChangeNotify(PRKEVENT)](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptregisterconfigchangenotify)