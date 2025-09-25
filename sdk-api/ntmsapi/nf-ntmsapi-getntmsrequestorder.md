# GetNtmsRequestOrder function

## Description

[[Removable Storage Manager](https://learn.microsoft.com/previous-versions/windows/desktop/bb540725(v=vs.85)) is no longer available as of Windows 7 and Windows Server 2008 R2.]

The
**GetNtmsRequestOrder** function gets the order that the specified request will be processed in the library queue.

## Parameters

### `hSession` [in]

Handle to the session returned by the
[OpenNtmsSession](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-openntmssessiona) function.

### `lpRequestId` [in]

Unique identifier of a library request.

### `lpdwOrderNumber` [out]

Order in which this request will be processed in the queue.

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

If the
**GetNtmsRequestOrder** function returns zero in *lpdwOrderNumber*, ordering is not available for this request. The order number is specific to the type of request because the types are processed in a predetermined order.

For example, the NTMS_LM_DISMOUNT request is processed prior to an NTMS_LM_MOUNT request. Within a specific class of requests the queue can be ordered, however. The lower-ordered requests are processed first, for example, 1 is the first request processed, 2 is the next request processed, and so forth.

You can use this order number, the request type, the submission time, and the submission date to help view the queue in sorted order. Request type, order number, and submission time should perform sorting.

Currently on NTMS_LM_MOUNT, requests are sorted using the order number.

## See also

[Library Control Functions](https://learn.microsoft.com/previous-versions/windows/desktop/rsm/removable-storage-manager-functions)

[SetNtmsRequestOrder](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-setntmsrequestorder)