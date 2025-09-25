# CancelNtmsLibraryRequest function

## Description

[[Removable Storage Manager](https://learn.microsoft.com/previous-versions/windows/desktop/bb540725(v=vs.85)) is no longer available as of Windows 7 and Windows Server 2008 R2.]

The
**CancelNtmsLibraryRequest** function cancels outstanding RSM requests, such as calls to the
[CleanNtmsDrive](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-cleanntmsdrive) function. If the library is busy, RSM queues the cancellation and returns success.

## Parameters

### `hSession` [in]

Handle to the session returned by the
[OpenNtmsSession](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-openntmssessiona) function.

### `lpRequestId` [in]

Unique identifier of the library request to be canceled.

To retrieve the list of existing library requests, use the
[EnumerateNtmsObject](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-enumeratentmsobject) function.

## Return value

This function returns one of the following values.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | Only an administrator of the RSM server can cancel library requests. This error is also returned if the request is currently being handled and cannot be deleted. |
| **ERROR_INVALID_HANDLE** | The session handle is missing or is not valid. |
| **ERROR_NOT_ENOUGH_MEMORY** | There was an allocation failure during processing. |
| **ERROR_OBJECT_NOT_FOUND** | The library request object ID was not found. This error occurs if the request is completed prior to issuing the cancel or when a request ID that is not valid is specified. |
| **ERROR_SUCCESS** | The library request has been queued for cancellation. |

## See also

[EnumerateNtmsObject](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-enumeratentmsobject)

[Library Control Functions](https://learn.microsoft.com/previous-versions/windows/desktop/rsm/removable-storage-manager-functions)