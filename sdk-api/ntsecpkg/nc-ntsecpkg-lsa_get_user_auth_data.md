# LSA_GET_USER_AUTH_DATA callback function

## Description

The **GetUserAuthData** function returns the authorization data for the user in a single buffer.

## Parameters

### `UserHandle` [in]

A handle to the user account. This handle is returned by the
[OpenSamUser](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_open_sam_user) function.

### `UserAuthData` [out]

Pointer that receives the consolidated authorization data. When you have finished using the authorization data, free the memory by calling the [FreeLsaHeap](https://learn.microsoft.com/windows/desktop/api/ntlsa/nc-ntlsa-lsa_free_lsa_heap) function.

### `UserAuthDataSize` [out]

Pointer that receives the size of the authorization data.

## Return value

If the function succeeds, the return value is STATUS_SUCCESS.

If the function fails, the return value is an NTSTATUS code indicating the reason it failed.

## Remarks

The authorization data returned by the **GetUserAuthData** function can be passed to the
[ConvertAuthDataToToken](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_convert_auth_data_to_token) function.

A pointer to the **GetUserAuthData** function is available in the
[LSA_SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-lsa_secpkg_function_table) structure received by the
[SpInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spinitializefn) function.

## See also

[ConvertAuthDataToToken](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_convert_auth_data_to_token)

[LSA_SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-lsa_secpkg_function_table)

[OpenSamUser](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_open_sam_user)

[SpInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spinitializefn)