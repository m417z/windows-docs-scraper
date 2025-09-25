# CrediUnmarshalandDecodeStringFn callback function

## Description

Transforms a marshaled string back into its original form, and decrypts the unmarshaled string.

## Parameters

### `MarshaledString` [in]

The marshaled, encrypted string.

### `Blob` [out]

A pointer to the unmarshaled, decrypted string.

### `BlobSize` [out]

A pointer to the size, in bytes, of the buffer pointed to by the *Blob* parameter.

### `IsFailureFatal` [out]

A pointer to a **BOOLEAN** variable to receive a value that indicates whether the caller should complete the operation. If the value of this parameter is **TRUE**, the caller should not complete the operation.

## Return value

If the function succeeds, return STATUS_SUCCESS, or an informational status code.

If the function fails, return an NTSTATUS error code that indicates the reason it failed.

## Remarks

A pointer to the **CrediUnmarshalandDecodeString** function is available in the
[LSA_SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-lsa_secpkg_function_table) structure received by the
[SpInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spinitializefn) function.

## See also

[SpInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spinitializefn)