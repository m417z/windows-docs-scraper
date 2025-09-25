# LsaEnumerateLogonSessions function

## Description

The **LsaEnumerateLogonSessions** function retrieves the set of existing logon session identifiers ([LUIDs](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-luid)) and the number of sessions.

## Parameters

### `LogonSessionCount` [out]

Pointer to a long integer that receives the number of elements returned in the array returned in *LogonSessionList* parameter.

### `LogonSessionList` [out]

Address of a pointer to a LUID. The pointer receives the first element of an array of logon session identifiers. The memory used by the array is allocated by the LSA. When the array is no longer needed, call the
[LsaFreeReturnBuffer](https://learn.microsoft.com/windows/win32/api/ntsecapi/nf-ntsecapi-lsafreereturnbuffer) function to free it.

## Return value

If the function succeeds, the return value is STATUS_SUCCESS.

If the function fails, the return value is an NTSTATUS code indicating the reason.

## Remarks

To retrieve information about the logon sessions returned by **LsaEnumerateLogonSessions**, call the
[LsaGetLogonSessionData](https://learn.microsoft.com/windows/win32/api/ntsecapi/nf-ntsecapi-lsagetlogonsessiondata) function.