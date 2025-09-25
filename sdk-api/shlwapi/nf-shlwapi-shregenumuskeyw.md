# SHRegEnumUSKeyW function

## Description

Enumerates the subkeys of a registry subkey in a user-specific subtree (HKEY_CURRENT_USER or HKEY_LOCAL_MACHINE).

## Parameters

### `hUSKey` [in]

Type: **HUSKEY**

A handle to a currently open registry subkey. The subkey must have been opened with the KEY_SET_VALUE access right. For more information, see [Registry Key Security and Access Rights](https://learn.microsoft.com/windows/desktop/SysInfo/registry-key-security-and-access-rights).

This handle can be obtained through the [SHRegOpenUSKey](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-shregopenuskeya) function.

### `dwIndex` [in]

Type: **DWORD**

The index of the subkey to retrieve. This parameter should be zero for the first call and incremented for subsequent calls.

### `pwzName`

TBD

### `pcchName` [in, out]

Type: **LPDWORD**

A pointer to a DWORD that, on entry, contains the size of the buffer at *pszName*, in characters. On exit, this contains the number of characters that were copied to *pszName*.

### `enumRegFlags` [in]

Type: **[SHREGENUM_FLAGS](https://learn.microsoft.com/windows/desktop/api/shlwapi/ne-shlwapi-shregenum_flags)**

A [SHREGENUM_FLAGS](https://learn.microsoft.com/windows/desktop/api/shlwapi/ne-shlwapi-shregenum_flags) that specifies the base key in which the enumeration should take place.

#### - pszName [out]

Type: **LPTSTR**

A pointer to a character buffer that receives the enumerated key name.

## Return value

Type: **LSTATUS**

Returns ERROR_SUCCESS if successful, or a nonzero error code defined in Winerror.h otherwise. You can use the [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) function with the FORMAT_MESSAGE_FROM_SYSTEM flag to retrieve a textual description of the error.

## Remarks

> [!NOTE]
> The shlwapi.h header defines SHRegEnumUSKey as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).