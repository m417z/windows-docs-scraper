# LSA_EXPAND_AUTH_DATA_FOR_DOMAIN callback function

## Description

Expands the domain groups in the specified user authentication data.

## Parameters

### `UserAuthData` [in]

A pointer to the user authentication data to expand.

### `UserAuthDataSize` [in]

The size, in bytes, of the *UserAuthData* buffer.

### `Reserved` [in]

Reserved. This parameter must be set to **NULL.**

### `ExpandedAuthData` [out]

A pointer to the expanded authentication data.

### `ExpandedAuthDataSize` [out]

A pointer to the size, in bytes, of the *ExpandedAuthData* buffer.

## Return value

If the function succeeds, return STATUS_SUCCESS, or an informational status code.

If the function fails, return an NTSTATUS error code that indicates the reason it failed.

## Remarks

A pointer to the **ExpandAuthDataForDomain** function is available in the
[LSA_SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-lsa_secpkg_function_table) structure received by the
[SpInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spinitializefn) function.

## See also

[SpInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spinitializefn)