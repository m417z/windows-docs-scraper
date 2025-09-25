# GetSecurityUserInfo function

## Description

The **GetSecurityUserInfo** function retrieves information about a logon [session](https://learn.microsoft.com/windows/win32/secgloss/s-gly).

## Parameters

### `LogonId` [in, optional]

An optional pointer to an [LUID](https://learn.microsoft.com/windows/win32/secgloss/l-gly) containing the logon session for which information is to be retrieved. If *LogonId* is **NULL**, information for the logon session of the calling thread is returned.

### `Flags` [in]

This parameter is currently not used.

### `UserInformation` [out]

A pointer to a location which contains a pointer to a [SecurityUserData](https://learn.microsoft.com/windows/win32/api/ntsecpkg/ns-ntsecpkg-security_user_data) structure. If the function call succeeds, the user information is returned in this structure. The caller is responsible for freeing this buffer by calling the [LsaFreeReturnBuffer](https://learn.microsoft.com/windows/win32/api/ntsecapi/nf-ntsecapi-lsafreereturnbuffer) function.

## Return value

**GetSecurityUserInfo** returns an appropriate NTSTATUS value, such as one of the following.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The SecurityUserData structure, indirectly pointed to by *UserInformation*, contains the requested user information. |
| **STATUS_NO_SUCH_LOGON_SESSION** | Indicates that the specified logon session does not exist. |

## Remarks

This function obtains information about a logon [session](https://learn.microsoft.com/windows/win32/secgloss/s-gly) via the [SecurityUserData](https://learn.microsoft.com/windows/win32/api/ntsecpkg/ns-ntsecpkg-security_user_data) structure.

## See also

[LsaFreeReturnBuffer](https://learn.microsoft.com/windows/win32/api/ntsecapi/nf-ntsecapi-lsafreereturnbuffer)

[MapSecurityError](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-mapsecurityerror)