# SECPKG_USER_FUNCTION_TABLE structure

## Description

The **SECPKG_USER_FUNCTION_TABLE** structure contains pointers to the functions that a [security package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) implements to support executing in process with client/server applications. This structure is provided by the
[SpUserModeInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spusermodeinitializefn) function.

## Members

### `InstanceInit`

Pointer to the **InstanceInit** function.

### `InitUserModeContext`

Pointer to the **InitUserModeContext** function.

### `MakeSignature`

Pointer to the [MakeSignature](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-makesignature) function.

### `VerifySignature`

Pointer to the [VerifySignature](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-verifysignature) function.

### `SealMessage`

Pointer to the **SealMessage** function.

### `UnsealMessage`

Pointer to the **UnsealMessage** function.

### `GetContextToken`

Pointer to the **GetContextToken** function.

### `QueryContextAttributes`

Pointer to the [QueryContextAttributes (General)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-querycontextattributesa) function.

### `CompleteAuthToken`

Pointer to the [CompleteAuthToken](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-completeauthtoken) function.

### `DeleteUserModeContext`

Pointer to the **DeleteUserModeContext** function.

### `FormatCredentials`

Pointer to the **FormatCredentials** function.

### `MarshallSupplementalCreds`

Pointer to the **MarshallSupplementalCreds** function.

### `ExportContext`

Pointer to the **ExportContext** function.

### `ImportContext`

Pointer to the **ImportContext** function.