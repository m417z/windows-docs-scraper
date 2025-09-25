# SHRegCreateUSKeyW function

## Description

Creates or opens a registry subkey in a user-specific subtree (HKEY_CURRENT_USER or HKEY_LOCAL_MACHINE).

## Parameters

### `pwzPath`

TBD

### `samDesired` [in]

Type: **[REGSAM](https://learn.microsoft.com/windows/desktop/shell/messages)**

The desired security access. For more information on security access, see [REGSAM](https://learn.microsoft.com/windows/desktop/shell/messages).

### `hRelativeUSKey` [in, optional]

Type: **HUSKEY**

The key to be used as a base for relative paths. If *pszPath* is a relative path, the key it specifies will be relative to *hRelativeUSKey*. If *pszPath* is an absolute path, set *hRelativeUSKey* to **NULL**. The key will then be created under **HKEY_LOCAL_MACHINE** or **HKEY_CURRENT_USER**, depending the value of *dwFlags*.

### `phNewUSKey` [out]

Type: **PHUSKEY**

A pointer to an **HUSKEY** that will receive the handle to the new key.

### `dwFlags` [in]

Type: **DWORD**

The base key under which the key should be opened. This can be one or more of the following values.

#### SHREGSET_HKCU

Create/open the key under **HKEY_CURRENT_USER**. Only creates a key if it is empty.

#### SHREGSET_FORCE_HKCU

Create/open the key under **HKEY_CURRENT_USER**. Creates a key even if it is not empty.

#### SHREGSET_HKLM

Create/open the key under **HKEY_LOCAL_MACHINE**. Only creates a key if it is empty.

#### SHREGSET_FORCE_HKLM

Create/open the key under **HKEY_LOCAL_MACHINE**. Creates a key even if it is not empty.

#### SHREGSET_DEFAULT

Create/open the key under both **HKEY_CURRENT_USER** (forced) and **HKEY_LOCAL_MACHINE** (only if empty). This flag is the equivalent of (**SHREGSET_FORCE_HKCU** | **SHREGSET_HKLM**).

### `dwFlags.SHREGSET_DEFAULT`

Create/open the key under both **HKEY_CURRENT_USER** (forced) and **HKEY_LOCAL_MACHINE** (only if empty). This flag is the equivalent of (**SHREGSET_FORCE_HKCU** | **SHREGSET_HKLM**).

### `dwFlags.SHREGSET_FORCE_HKCU`

Create/open the key under **HKEY_CURRENT_USER**. Creates a key even if it is not empty.

### `dwFlags.SHREGSET_FORCE_HKLM`

Create/open the key under **HKEY_LOCAL_MACHINE**. Creates a key even if it is not empty.

### `dwFlags.SHREGSET_HKCU`

Create/open the key under **HKEY_CURRENT_USER**. Only creates a key if it is empty.

### `dwFlags.SHREGSET_HKLM`

Create/open the key under **HKEY_LOCAL_MACHINE**. Only creates a key if it is empty.

#### - pszPath [in]

Type: **LPCTSTR**

A pointer to a null-terminated string that contains the subkey to be created or opened. If a value with this name is already present in the subkey, it will be opened.

## Return value

Type: **LSTATUS**

Returns ERROR_SUCCESS if successful, or a nonzero error code defined in Winerror.h otherwise. You can use the [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) function with the FORMAT_MESSAGE_FROM_SYSTEM flag to retrieve a generic description of the error.

## Remarks

If you want to write values to the new key, use [SHRegWriteUSValue](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-shregwriteusvaluea) to write each value, passing the **HUSKEY** handle that is returned through *phNewUSKey*. When you have finished, close the user-specific registry key with [SHRegCloseUSKey](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-shregcloseuskey).

> [!NOTE]
> The shlwapi.h header defines SHRegCreateUSKey as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).