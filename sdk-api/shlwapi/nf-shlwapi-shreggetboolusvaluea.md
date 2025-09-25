# SHRegGetBoolUSValueA function

## Description

Retrieves a Boolean value from a registry subkey in a user-specific subtree (HKEY_CURRENT_USER or HKEY_LOCAL_MACHINE).

## Parameters

### `pszSubKey` [in]

Type: **LPCTSTR**

A pointer to a null-terminated string with the name of the subkey relative to **HKEY_LOCAL_MACHINE** and **HKEY_CURRENT_USER**. For example, "Software\MyCompany\MyProduct".

### `pszValue` [in, optional]

Type: **LPCTSTR**

A pointer to a null-terminated string that specifies the name of the value. This value can be **NULL**.

### `fIgnoreHKCU` [in]

Type: **BOOL**

A variable that specifies which key to look under. When set to **TRUE**, [SHRegGetUSValue](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-shreggetusvaluea) ignores **HKEY_CURRENT_USER** and returns a value from **HKEY_LOCAL_MACHINE**.

### `fDefault` [in]

Type: **BOOL**

A value that is returned if there is no registry value.

## Return value

Type: **BOOL**

Returns either the value from the registry, or *fDefault* if none is found.

## Remarks

> [!NOTE]
> The shlwapi.h header defines SHRegGetBoolUSValue as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).