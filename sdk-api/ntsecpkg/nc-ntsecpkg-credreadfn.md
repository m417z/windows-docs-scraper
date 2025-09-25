# CredReadFn callback function

## Description

Reads a credential from the [Credential Manager](https://learn.microsoft.com/windows/desktop/SecAuthN/credential-manager).

## Parameters

### `LogonId` [in]

The logon ID for which to read credentials.

### `CredFlags` [in]

Flags that determine the behavior of this function. The following flags are defined.

| Value | Meaning |
| --- | --- |
| **CREDP_FLAGS_IN_PROCESS**<br><br>0x01 | The caller is in-process. |
| **CREDP_FLAGS_USE_MIDL_HEAP**<br><br>0x02 | The caller should use the [midl_user_allocate](https://learn.microsoft.com/windows/desktop/Rpc/the-midl-user-allocate-function) function to allocate the *Credential* buffer. |
| **CREDP_FLAGS_DONT_CACHE_TI**<br><br>0x04 | Do not cache target information. |
| **CREDP_FLAGS_CLEAR_PASSWORD**<br><br>0x08 | The credential data is passed as clear text. |
| **CREDP_FLAGS_USER_ENCRYPTED_PASSWORD**<br><br>0x10 | The credential data is encrypted by using the [RtlEncryptMemory](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-rtlencryptmemory) function. |
| **CREDP_FLAGS_TRUSTED_CALLER**<br><br>0x20 | The caller is a trusted process. |

### `TargetName` [in]

The name of the target computer.

### `Type` [in]

Specifies the type of the credential to read. The possible values for this parameter are the same as the possible values of the *Type* member of the [CREDENTIAL](https://learn.microsoft.com/windows/desktop/api/wincred/ns-wincred-credentiala) structure.

### `Flags` [in]

Reserved. This parameter must be set to zero.

### `Credential` [out]

A pointer to a pointer to an [ENCRYPTED_CREDENTIALW](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-encrypted_credentialw) structure that receives the credentials that this function reads.

## Return value

If the function succeeds, return STATUS_SUCCESS, or an informational status code.

If the function fails, return an NTSTATUS error code that indicates the reason it failed.

## Remarks

A pointer to the **CrediRead** function is available in the
[LSA_SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-lsa_secpkg_function_table) structure received by the
[SpInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spinitializefn) function.

## See also

[SpInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spinitializefn)