# SpGetUserInfoFn callback function

## Description

The **SpGetUserInfo** function retrieves information about a logon [session](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly).

## Parameters

### `LogonId` [in]

Pointer to an [LUID](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) containing the logon session for which information is to be retrieved.

### `Flags` [in]

Specifies the acceptable length of the domain name as one of the following values.

| Value | Meaning |
| --- | --- |
| **NO_LONG_NAMES** | The returned domain name cannot be longer than 15 characters. |
| **UNDERSTANDS_LONG_NAMES** | The returned domain name can be longer than 15 characters. |

### `UserData` [out]

Pointer to a pointer to a
[SecurityUserData](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-security_user_data) structure. If the function call succeeds, the user information is returned in this structure. The [security package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) should allocate the memory for this structure in the caller's address space. The caller is responsible for freeing the buffer by calling the
[FreeContextBuffer](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-freecontextbuffer) function.

## Return value

If the function succeeds, return STATUS_SUCCESS.

If the function fails, return an **NTSTATUS** code that indicates the reason it failed.

## Remarks

The *Flags* value NO_LONG_NAMES provides compatibility with Microsoft NTLM.

SSP/APs must implement the **SpGetUserInfo** function; however, the actual name given to the implementation is up to the developer.

A pointer to the **SpGetUserInfo** function is available in the
[SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_function_table) structure received from the
[SpLsaModeInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-splsamodeinitializefn) function.

## See also

[FreeContextBuffer](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-freecontextbuffer)

[SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_function_table)

[SpLsaModeInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-splsamodeinitializefn)