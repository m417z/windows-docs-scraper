# SpAddCredentialsFn callback function

## Description

Used to add [credentials](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) for a [security principal](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly).

## Parameters

### `CredentialHandle` [in]

A handle to the credential to add.

### `PrincipalName` [in]

Optional. Pointer to a
[UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) structure containing the name of the [security principal](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) whose credentials are being added.

### `Package` [in]

Pointer to a
[UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) structure containing the name of the authenticating package.

### `CredentialUseFlags` [in]

Flags indicating how the credentials will be used. The following values are valid.

| Value | Meaning |
| --- | --- |
| **SECPKG_CRED_INBOUND** | Credentials will be used with the [AcceptSecurityContext (General)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-acceptsecuritycontext) function. |
| **SECPKG_CRED_OUTBOUND** | Credentials will be used with the [InitializeSecurityContext (General)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-initializesecuritycontexta) function. |

### `AuthorizationData` [in]

Optional. Pointer to supplemental authentication data.

### `GetKeyFunction` [in]

Pointer to a function in the caller's address space that generates [session keys](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly).

### `GetKeyArgument` [in]

Pointer to the argument used with the *GetKeyFunction* function.

### `ExpirationTime` [out]

Pointer to a
[TimeStamp](https://learn.microsoft.com/windows/desktop/SecAuthN/timestamp) that receives the time the credentials handle expires.

## Return value

If the function succeeds, return STATUS_SUCCESS.

If the function fails, return an **NTSTATUS** code that indicates the reason it failed.

## Remarks

SSP/APs must implement the **SpAddCredentials** function; however, the actual name given to the implementation is up to the developer.

A pointer to the **SpAddCredentials** function is available in the
[SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_function_table) structure received from the
[SpLsaModeInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-splsamodeinitializefn) function.

## See also

[SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_function_table)

[SpLsaModeInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-splsamodeinitializefn)