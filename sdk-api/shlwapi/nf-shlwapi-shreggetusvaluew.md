# SHRegGetUSValueW function

## Description

Retrieves a value from a registry subkey in a user-specific subtree (HKEY_CURRENT_USER or HKEY_LOCAL_MACHINE).

## Parameters

### `pszSubKey` [in]

Type: **LPCTSTR**

A pointer to a null-terminated string with the name of the subkey relative to **HKEY_LOCAL_MACHINE** and **HKEY_CURRENT_USER**. For example: "Software\MyCompany\MyProduct".

### `pszValue` [in, optional]

Type: **LPCTSTR**

A pointer to a null-terminated string with the name of the value. This value can be **NULL**.

### `pdwType` [in, out, optional]

Type: **DWORD***

A pointer to a **DWORD** that receives the type of data stored in the retrieved value. When using default values, the input *pdwType* is the type of the default value. For possible values, see [Registry Data Types](https://learn.microsoft.com/windows/desktop/shell/hkey-type). If type information is not required, this parameter can be **NULL**.

### `pvData` [out, optional]

Type: **void***

A pointer to a buffer that receives the value's data.

### `pcbData` [in, out, optional]

Type: **DWORD***

A pointer to a variable that specifies the size, in bytes, of the buffer pointed to by *pvData*. When **SHRegGetUSValue** returns, *pcbData* contains the size of the data copied to *pvData*.

### `fIgnoreHKCU` [in]

Type: **BOOL**

A variable that specifies which key to look under. When set to **TRUE**, **SHRegGetUSValue** ignores **HKEY_CURRENT_USER** and returns the value from the key under **HKEY_LOCAL_MACHINE**.

### `pvDefaultData` [in, optional]

Type: **void***

A pointer to a buffer that receives the value's default data.

### `dwDefaultDataSize` [in]

Type: **DWORD**

The length, in bytes, of the buffer pointed to by *pvDefaultData*.

## Return value

Type: **LSTATUS**

Returns ERROR_SUCCESS if successful, or a nonzero error code defined in Winerror.h otherwise. You can use the [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) function with the FORMAT_MESSAGE_FROM_SYSTEM flag to retrieve a generic description of the error.

## Remarks

When *fIgnoreHKCU* is set to **TRUE**, **SHRegGetUSValue** returns the value from the key under **HKEY_LOCAL_MACHINE**. When set to **FALSE**, **SHRegGetUSValue** first tries to return the value from the key under **HKEY_CURRENT_USER**. However, if the key is not found under **HKEY_CURRENT_USER**, the value is returned from the key under **HKEY_LOCAL_MACHINE**. If neither key is present, or if an error occurred and *dwDefaultDataSize* is nonzero, then the default data is copied to *pvData* and ERROR_SUCCESS returns. ERROR_SUCCESS returns for both default and non-default data, and there is no way of distinguishing which value copies to *pvData*. To prevent the use of default data, set *pvDefaultData* to **NULL** and *dwDefaultDataSize* to zero.

This function opens the key each time it is used. If your code involves getting a series of values from the same key, it is more efficient to open the key once with [SHRegOpenUSKey](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-shregopenuskeya) and then use [SHRegQueryUSValue](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-shregqueryusvaluea) to retrieve the data.

> [!NOTE]
> The shlwapi.h header defines SHRegGetUSValue as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).