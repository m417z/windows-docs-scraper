# SHRegDeleteEmptyUSKeyA function

## Description

Deletes an empty registry subkey in a user-specific subtree (HKEY_CURRENT_USER or HKEY_LOCAL_MACHINE).

## Parameters

### `hUSKey` [in]

Type: **HUSKEY**

A handle to a currently open registry subkey. The subkey must have been opened with the KEY_SET_VALUE access right. For more information, see [Registry Key Security and Access Rights](https://learn.microsoft.com/windows/desktop/SysInfo/registry-key-security-and-access-rights).

This handle can be obtained through the [SHRegOpenUSKey](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-shregopenuskeya) function.

### `pszSubKey` [in]

Type: **LPCSTR**

A pointer to the null-terminated string that specifies the empty user-defined registry subkey to be deleted.

### `delRegFlags` [in]

Type: **[SHREGDEL_FLAGS](https://learn.microsoft.com/windows/desktop/api/shlwapi/ne-shlwapi-shregdel_flags)**

One of the [SHREGDEL_FLAGS](https://learn.microsoft.com/windows/desktop/api/shlwapi/ne-shlwapi-shregdel_flags) that specifies from which base key the subkey will be deleted.

## Return value

Type: **LSTATUS**

Returns ERROR_SUCCESS if successful, or a nonzero error code defined in Winerror.h otherwise. You can use the [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) function with the FORMAT_MESSAGE_FROM_SYSTEM flag to retrieve a generic description of the error.

## See also

[SHRegDeleteUSValue](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-shregdeleteusvaluea)

## Remarks

> [!NOTE]
> The shlwapi.h header defines SHRegDeleteEmptyUSKey as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).