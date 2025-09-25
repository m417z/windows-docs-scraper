# SHRegSetUSValueA function

## Description

Sets a registry subkey value in a user-specific subtree (HKEY_CURRENT_USER or HKEY_LOCAL_MACHINE).

## Parameters

### `pszSubKey` [in]

Type: **LPCTSTR**

A pointer to a null-terminated string with the name of the subkey.

### `pszValue` [in]

Type: **LPCTSTR**

A pointer to a null-terminated string that specifies the name of the value.

### `dwType` [in]

Type: **DWORD**

Type of data to be stored. This parameter must be the **REG_SZ** type. For more information, see [Registry Data Types](https://learn.microsoft.com/windows/desktop/shell/hkey-type).

### `pvData` [in, optional]

Type: **LPVOID***

 Apointer to a null-terminated string that contains the value to be set for the specified key.

### `cbData` [in, optional]

Type: **DWORD**

Length, in bytes, of the string pointed to by the *pvData* parameter, not including the terminating null character.

### `dwFlags` [in, optional]

Type: **DWORD**

Flags indicating where the data should be written.

#### SHREGSET_HKCU

Write to **HKEY_CURRENT_USER** if empty.

#### SHREGSET_FORCE_HKCU

Write to **HKEY_CURRENT_USER**.

#### SHREGSET_HKLM

Write to **HKEY_LOCAL_MACHINE** if empty.

#### SHREGSET_FORCE_HKLM

Write to **HKEY_LOCAL_MACHINE**.

#### SHREGSET_DEFAULT

Equivalent to (**SHREGSET_FORCE_HKCU** | **SHREGSET_HKLM**).

## Return value

Type: **LSTATUS**

Returns ERROR_SUCCESS if successful, or a nonzero error code defined in Winerror.h otherwise. You can use the [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) function with the FORMAT_MESSAGE_FROM_SYSTEM flag to retrieve a generic description of the error.

## Remarks

This function opens the key each time it is used. If your code involves setting a series of values in the same key, it is more efficient to open the key once with [SHRegOpenUSKey](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-shregopenuskeya) and then use [SHRegWriteUSValue](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-shregwriteusvaluea) to write the data.

> [!NOTE]
> The shlwapi.h header defines SHRegSetUSValue as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).