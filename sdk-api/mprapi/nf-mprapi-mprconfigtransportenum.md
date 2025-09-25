# MprConfigTransportEnum function

## Description

The
**MprConfigTransportEnum** function enumerates the transports configured on the router.

## Parameters

### `hMprConfig` [in]

Handle to the router configuration for the transports. Obtain this handle by calling
[MprConfigServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfigserverconnect).

### `dwLevel` [in]

A **DWORD** value that describes the format in which the information is returned in the *lplpBuffer* parameter. Must be zero.

### `lplpBuffer` [in, out]

On input, a non-**NULL** pointer.

On successful completion, a pointer to an array of
[MPR_TRANSPORT_0](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_transport_0) structures. Free this memory buffer by calling
[MprConfigBufferFree](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfigbufferfree).

### `dwPrefMaxLen` [in]

Specifies the preferred maximum length of returned data in 8-bit bytes. If this parameter is -1, the buffer returned will be large enough to hold all available information.

### `lpdwEntriesRead` [out]

Pointer to a **DWORD** variable. This variable receives the total number of entries that were enumerated from the current resume position.

### `lpdwTotalEntries` [out]

Pointer to a **DWORD** variable. This variable receives the total number of entries that could have been enumerated from the current resume position.

### `lpdwResumeHandle` [in, out, optional]

Pointer to a **DWORD** variable.

On input, the handle should be zero on the first call and left unchanged on subsequent calls.

On output, this variable contains a resume handle used to continue the enumeration. If the handle is **NULL**, the enumeration is complete.

If an error occurs in the enumeration, this handle is invalid.

This parameter is optional. If the calling application specifies **NULL** for this parameter, the function does not return a resume handle.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | At least one of the following is true: <br><br>* *hMprConfig* is **NULL**.<br>* *dwLevel* is not zero.<br>* *lplpBuffer* is **NULL**.<br>* *dwPrefMaxLen* is smaller than the size of a single   [MPR_TRANSPORT_0](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_transport_0) structure.<br>* *lpdwEntriesRead* is **NULL**.<br>* *lpdwTotalEntries* is **NULL**. |
| **ERROR_NOT_ENOUGH_MEMORY** | Insufficient resources to complete the operation. |
| **ERROR_NO_MORE_ITEMS** | No more entries available from the current resume position. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to retrieve the system error message that corresponds to the error code returned. |

## See also

[FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage)

[MprConfigBufferFree](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfigbufferfree)

[MprConfigServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfigserverconnect)

[Router Configuration Functions](https://learn.microsoft.com/windows/desktop/RRAS/router-configuration-functions)

[Router Management Reference](https://learn.microsoft.com/windows/desktop/RRAS/router-management-reference)