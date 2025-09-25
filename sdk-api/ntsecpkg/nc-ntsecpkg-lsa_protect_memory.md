# LSA_PROTECT_MEMORY callback function

## Description

Encrypts the specified memory buffer.

## Parameters

### `Buffer` [in, out]

On input, a pointer to the buffer to be encrypted. On output, a pointer to the encrypted buffer.

### `BufferSize` [in]

The size, in bytes, of the *Buffer* buffer.

## Remarks

A pointer to the **LsaProtectMemory** function is available in the
[LSA_SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-lsa_secpkg_function_table) structure received by the
[SpInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spinitializefn) function.

## See also

[SpInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spinitializefn)