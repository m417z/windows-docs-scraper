# BCryptRegisterConfigChangeNotify function

## Description

[**BCryptRegisterConfigChangeNotify** is deprecated beginning with Windows 10.]

The **BCryptRegisterConfigChangeNotify(PRKEVENT)** function creates kernel mode CNG configuration change event handler.

## Parameters

### `phEvent` [in]

The address of a **PRKEVENT** variable that receives the pointer to the event dispatcher object.
You use the kernel wait functions, such as [WaitForSingleObject](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-waitforsingleobject), to determine when the event has been signaled.
The event is signaled when the CNG configuration has changed.

This handle must be passed to the [BCryptUnregisterConfigChangeNotify(PRKEVENT)](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptunregisterconfigchangenotify) function to remove the event notification.

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
**BCryptRegisterConfigChangeNotify(PRKEVENT)** can be called only in kernel mode and at **PASSIVE_LEVEL** IRQL.
Code executing in user mode must call [BCryptRegisterConfigChangeNotify(HANDLE*)](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptregisterconfigchangenotify).

## See also

[BCryptUnregisterConfigChangeNotify(PRKEVENT) function](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptunregisterconfigchangenotify)