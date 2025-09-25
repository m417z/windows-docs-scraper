# SpAcquireCredentialsHandleFn callback function

## Description

Called to obtain a handle to a principal's [credentials](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly). The [security package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) can deny access to the caller if the caller does not have permission to access the credentials.

If the credentials handle is returned to the caller, the package should also specify an expiration time for the handle.

## Parameters

### `PrincipalName` [in]

Optional. Pointer to a
[UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) structure containing the name of the [security principal](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) whose credentials are being requested. If this value is **NULL**, the caller requests a handle to the credentials of the user in whose [security context](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) the caller is executing.

### `CredentialUseFlags` [in]

Flags indicating how the credentials will be used. The following values are valid.

| Value | Meaning |
| --- | --- |
| **SECPKG_CRED_INBOUND** | Credentials will be used with the [AcceptSecurityContext (General)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-acceptsecuritycontext) function. |
| **SECPKG_CRED_OUTBOUND** | Credentials will be used with the [InitializeSecurityContext (General)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-initializesecuritycontexta) function. |

### `LogonId` [in]

Optional. Pointer to an
[LUID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-luid) containing the [logon identifier](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) of the security principal.

### `AuthorizationData` [in]

Optional. Pointer to supplemental authentication data.

### `GetKeyFunction` [in]

Pointer to a function in the caller's address space that generates [session keys](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly).

### `GetKeyArgument` [in]

Pointer to the argument used with the *GetKeyFunction* function.

### `CredentialHandle` [out]

Pointer to an **LSA_SEC_HANDLE** that receives the credentials. When you have finished using the credentials, free the handle by calling the [SpFreeCredentialsHandle](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spfreecredentialshandlefn) function.

### `ExpirationTime` [out]

Pointer to a
[TimeStamp](https://learn.microsoft.com/windows/desktop/SecAuthN/timestamp) that receives the time the credentials handle expires.

## Return value

If the function succeeds, return STATUS_SUCCESS.

If the function fails, return an **NTSTATUS** code that indicates the reason it failed. The following table lists common reasons for failure and the error codes that should be returned.

| Return code | Description |
| --- | --- |
| **SEC_E_NOT_OWNER** | The caller is denied access. |
| **SEC_E_NO_CREDENTIALS** | There are no credentials available for the specified principal. |

## Remarks

The package can use the [Local Security Authority](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) (LSA) support functions to determine whether the caller should be given access to the requested credentials.

Credentials obtained from **SpAcquireCredentialsHandle** are freed by calling the
[SpFreeCredentialsHandle](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spfreecredentialshandlefn) function.

SSP/APs must implement the **SpAcquireCredentialsHandle** function; however, the actual name given to the implementation is up to the developer.

A pointer to the **SpAcquireCredentialsHandle** function is available in the
[SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_function_table) structure received from the
[SpLsaModeInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-splsamodeinitializefn) function.

## See also

[SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_function_table)

[SpFreeCredentialsHandle](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spfreecredentialshandlefn)

[SpLsaModeInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-splsamodeinitializefn)