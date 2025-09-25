# SpUpdateCredentialsFn callback function

## Description

Updates the credentials associated with the specified context.

## Parameters

### `ContextHandle` [in]

A handle to the context to update.

### `CredType` [in]

The type of credential specified by the *ContextHandle* parameter. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **SEC_WINNT_AUTH_DATA_TYPE_PASSWORD**<br><br>0x28bfc32f, 0x10f6, 0x4738, 0x98, 0xd1, 0x1a, 0xc0, 0x61, 0xdf, 0x71, 0x6a | The credential is a password. |
| **SEC_WINNT_AUTH_DATA_TYPE_CERT**<br><br>0x235f69ad, 0x73fb, 0x4dbc, 0x82, 0x3, 0x6, 0x29, 0xe7, 0x39, 0x33, 0x9b | The credential is a certificate. |
| **SEC_WINNT_AUTH_DATA_TYPE_CSP_DATA**<br><br>0x68fd9879, 0x79c, 0x4dfe, 0x82, 0x81, 0x57, 0x8a, 0xad, 0xc1, 0xc1, 0x0 | The credential is authentication data from a [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP). |

### `FlatCredUIContextLength` [in]

The size, in characters, of the buffer specified by the *FlatCredUIContext* parameter.

### `FlatCredUIContext`

A string that specifies the updated credentials.

## Return value

If the function succeeds, return **STATUS_SUCCESS**, or an informational status code.

If the function fails, return an **NTSTATUS** error code that indicates the reason it failed. For more information, see Remarks.

## Remarks

A pointer to the **SpUpdateCredentialsFn** function is available in the
[SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_function_table) structure received from the
[SpLsaModeInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-splsamodeinitializefn) function.