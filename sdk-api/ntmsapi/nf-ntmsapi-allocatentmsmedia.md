# AllocateNtmsMedia function

## Description

[[Removable Storage Manager](https://learn.microsoft.com/previous-versions/windows/desktop/bb540725(v=vs.85)) is no longer available for use as of Windows 7 and Windows Server 2008 R2.]

The
**AllocateNtmsMedia** function allocates a piece of available media.

## Parameters

### `hSession` [in]

Handle to the session returned by the
[OpenNtmsSession](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-openntmssessiona) function.

### `lpMediaPool` [in]

Unique identifier of the media pool from which the media is to be allocated. Only application pools may be specified for allocation.

### `lpPartition` [in]

Part identifier of a side to use as a logical media identifier (LMID). The side must be in the Available or Import state. This feature can be used to allocate a particular side or to import media. This parameter is optional.

### `lpMediaId` [out]

LMID of the allocated medium. This parameter is **NULL** if the medium cannot be allocated.

### `dwOptions` [in]

Options. This parameter can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **NTMS_ALLOCATE_ERROR_IF_UNAVAILABLE** | Prevents the submission of an operator request for new media if none can be allocated with the specified constraints. |
| **NTMS_ALLOCATE_NEW** | Allocates a side of the specified medium that cannot be shared with another application's logical media. For example, this value reserves the second side of two-sided optical media. |
| **NTMS_ALLOCATE_NEXT** | Allocate the next side of the multi-sided medium previously allocated with the NTMS_ALLOCATE_NEW value. This allows a single application to use both sides of a piece of two-sided media and ensure that the application owns all the data on the piece of physical media. <br><br>If all the sides of the medium are already allocated, the allocation request fails. |

### `dwTimeout` [in]

Maximum time allowed to allocate the specified media, in milliseconds. If this parameter is INFINITE, the function will not time out. If this parameter is zero, it will wait for media. Note that this function does not queue a request for more media if the *dwOptions* parameter specifies NTMS_ALLOCATE_ERROR_IF_UNAVAILABLE.

### `lpAllocateInformation` [out]

Pointer to an
[NTMS_ALLOCATION_INFORMATION](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ns-ntmsapi-ntms_allocation_information) structure that receives the source media pool from which the medium was taken. This parameter can be **NULL**.

## Return value

This function returns one of the following values.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | NTMS_CONTROL_ACCESS to the media's media pool is denied. Other security error are also possible, but they would indicate a security subsystem error.<br><br>**Windows XP:** NTMS_MODIFY_ACCESS to media's media pool is denied. |
| **ERROR_CANCELLED** | The operator canceled the request for new media. |
| **ERROR_DATABASE_FAILURE** | The database is inaccessible or damaged. |
| **ERROR_DATABASE_FULL** | The database is full. |
| **ERROR_DEVICE_NOT_AVAILABLE** | An intermediate resource is not available; for example, the free media pool is not available. |
| **ERROR_INVALID_HANDLE** | The session handle is missing or is not valid. |
| **ERROR_INVALID_MEDIA** | The partition ID or LMID was not valid upon input when using the NTMS_ALLOCATE_NEXT flag. |
| **ERROR_INVALID_MEDIA_POOL** | The media pool ID is not valid. |
| **ERROR_INVALID_PARAMETER** | The media or media pool ID is missing. |
| **ERROR_MEDIA_OFFLINE** | The specified media is offline and cannot be allocated. |
| **ERROR_MEDIA_UNAVAILABLE** | No media has been allocated within the specified time-out event. |
| **ERROR_NOT_ENOUGH_MEMORY** | There was an allocation failure during processing. |
| **ERROR_SUCCESS** | The function was successful. |
| **ERROR_TIMEOUT** | The time-out event expired before media was available. |

## Remarks

The
**AllocateNtmsMedia** function returns an LMID. Depending upon the media pool's policy, if the specified media pool does not contain any online Available media,
**AllocateNtmsMedia** might search the free media pool for the specified medium to move to the specified media pool. Media from the designated media pool is allocated first, and then the free media is moved and allocated.

If the media pool contains any online Available media, a medium from the pool is allocated.

If the media pool is configured to allocate media from the free pool automatically, and the free pool contains online Available media, a medium is moved to the specified pool and allocated.

**Windows Server 2003:** If media is being allocated from the free pool, NTMS_USE_ACCESS to the free pool and NTMS_CONTROL_ACCESS to the destination pool is required. If the free pool is not the source media pool, NTMS_CONTROL_ACCESS is required on both source and destination pools.

When the NTMS_ALLOCATE_NEXT value is specified, the *lpMediaId* parameter must point to a valid media ID at the time of invocation. In this case, *lpMediaId* is used as an IN and OUT parameter. The next side of the multiple sided medium specified by *lpMediaId* is allocated, and the new partition ID is returned through *lpMediaId* (overwriting the original media ID passed in).

If NTMS_ALLOCATE_ERROR_IF_UNAVAILABLE is specified, ERROR_MEDIA_ UNAVAILABLE is returned if no media is available.

When necessary, RSM generates an operator request to insert new or Available media. If the time specified in the *dwTimeout* parameter elapses before the operator request is handled, RSM returns ERROR_TIMEOUT and deletes the operator request.

If the user cancels the allocation request, RSM returns ERROR_CANCELLED.

If a user indicates that the operator request has been satisfied, the request is deleted and RSM retries the process.

When an application requires new media containing data, a user or administrator places the media in a library or drive. RSM identifies the media and places it in the import pool. The application searches the import pool, moves the media to its application pool and allocates it. This routine process can be streamlined and made atomic through a single call to
**AllocateNtmsMedia**. After searching the import pool the application can call
**AllocateNtmsMedia**, passing the partition ID of the side as the value of the *lpPartId* parameter. RSM then:

1. moves the medium to the specified media pool.
2. changes the media's state to allocated.
3. returns an LMID.

**Note** For two-sided media, the flip side remains in the Import state and is not available for use until imported.

## See also

[DeallocateNtmsMedia](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-deallocatentmsmedia)

[Media Services Functions](https://learn.microsoft.com/previous-versions/windows/desktop/rsm/removable-storage-manager-functions)

[NTMS_ALLOCATION_INFORMATION](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ns-ntmsapi-ntms_allocation_information)