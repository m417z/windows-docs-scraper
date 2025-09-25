# LSA_OPEN_TOKEN_BY_LOGON_ID callback function

## Description

Opens the user access token associated with the specified user logon.

## Parameters

### `LogonId` [in]

A pointer to a [LUID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-luid) structure that identifies the user for which to open the access token.

### `RetTokenHandle` [out]

A pointer to the handle to the token this function opens.

## Return value

If the function succeeds, return STATUS_SUCCESS, or an informational status code.

If the function fails, return an NTSTATUS error code that indicates the reason it failed.

## Remarks

A pointer to the **OpenTokenByLogonId** function is available in the
[LSA_SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-lsa_secpkg_function_table) structure received by the
[SpInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spinitializefn) function.

## See also

[SpInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spinitializefn)