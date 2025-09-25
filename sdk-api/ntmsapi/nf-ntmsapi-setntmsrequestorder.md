# SetNtmsRequestOrder function

## Description

[[Removable Storage Manager](https://learn.microsoft.com/previous-versions/windows/desktop/bb540725(v=vs.85)) is no longer available as of Windows 7 and Windows Server 2008 R2.]

The
**SetNtmsRequestOrder** function sets the order that the specified request will be processed in the library queue.

## Parameters

### `hSession` [in]

Handle to the session returned by the
[OpenNtmsSession](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-openntmssessiona) function.

### `lpRequestId` [in]

Unique identifier of a library request.

### `dwOrderNumber` [in]

Order that the request will be processed in the queue.

## Return value

This function returns one of the following values.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | NTMS_CONTROL_ACCESS to the computer is denied. Other security errors are also possible, but they would indicate a security subsystem error.<br><br>**Windows XP:** No access rights are required. |
| **ERROR_DATABASE_FAILURE** | The database is inaccessible or damaged. |
| **ERROR_INVALID_HANDLE** | The session handle is missing or is not valid. |
| **ERROR_INVALID_PARAMETER** | The library request identifier is missing. |
| **ERROR_OBJECT_NOT_FOUND** | A request object with the specified identifier cannot be found. |
| **ERROR_SUCCESS** | The function was successful. |

## Remarks

Currently NTMS_LM_MOUNT requests are sorted using the order number.

The order number set by the
**SetNtmsRequestOrder** function is specific to the type of request because the types are processed in a predetermined order. For example, an NTMS_LM_DISMOUNT request is processed prior to an NTMS_LM_MOUNT request. Within a specific class of requests the queue can be ordered, however. The lower ordered requests are processed first; for example, 1 is the first request processed, 2 is the next request processed, and so forth.

To process a request immediately, an application can set the order number to 1. To defer processing, an application should set the order number to a very large number or 0xFFFFFFFF. The order number of a request, which currently has an order number of zero, cannot be changed.

## See also

[GetNtmsRequestOrder](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-getntmsrequestorder)

[Library Control Functions](https://learn.microsoft.com/previous-versions/windows/desktop/rsm/removable-storage-manager-functions)