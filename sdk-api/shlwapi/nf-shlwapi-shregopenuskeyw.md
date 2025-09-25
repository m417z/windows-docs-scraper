# SHRegOpenUSKeyW function

## Description

Opens a registry subkey in a user-specific subtree (HKEY_CURRENT_USER or HKEY_LOCAL_MACHINE).

## Parameters

### `pwzPath`

TBD

### `samDesired` [in]

Type: **[REGSAM](https://learn.microsoft.com/windows/desktop/shell/messages)**

The desired security access. For more information on security access, see [REGSAM](https://learn.microsoft.com/windows/desktop/shell/messages).

### `hRelativeUSKey` [in, optional]

Type: **HUSKEY**

The key to be used as a base for relative paths. If *pszPath* is a relative path, the key it specifies will be relative to *hRelativeUSKey*. If *pszPath* is an absolute path, set *hRelativeUSKey* to **NULL**.

### `phNewUSKey` [out]

Type: **PHUSKEY**

A pointer to the handle of the opened key.

### `fIgnoreHKCU` [in]

Type: **BOOL**

The variable that specifies which key to look under. When set to **TRUE**, **SHRegOpenUSKey** ignores **HKEY_CURRENT_USER** and returns a value from **HKEY_LOCAL_MACHINE**.

#### - pszPath [in]

Type: **LPCTSTR**

A pointer to a null-terminated string with the name of the subkey.

## Return value

Type: **LSTATUS**

Returns ERROR_SUCCESS if successful, or a nonzero error code defined in Winerror.h otherwise. You can use the [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) function with the FORMAT_MESSAGE_FROM_SYSTEM flag to retrieve a generic description of the error.

## Remarks

> [!NOTE]
> The shlwapi.h header defines SHRegOpenUSKey as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).