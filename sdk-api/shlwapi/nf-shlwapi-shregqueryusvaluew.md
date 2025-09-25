# SHRegQueryUSValueW function

## Description

Retrieves the type and data for a specified name associated with an open registry subkey in a user-specific subtree (HKEY_CURRENT_USER or HKEY_LOCAL_MACHINE).

## Parameters

### `hUSKey` [in]

Type: **HUSKEY**

A handle to a currently open registry subkey, or one of the following predefined values. The subkey must have been opened with the KEY_SET_VALUE access right. For more information, see [Registry Key Security and Access Rights](https://learn.microsoft.com/windows/desktop/SysInfo/registry-key-security-and-access-rights).

This handle can be obtained through the [SHRegOpenUSKey](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-shregopenuskeya) function.

#### HKEY_CLASSES_ROOT

#### HKEY_CURRENT_CONFIG

#### HKEY_CURRENT_USER

#### HKEY_LOCAL_MACHINE

#### HKEY_PERFORMANCE_DATA

#### HKEY_USERS

### `pszValue` [in, optional]

Type: **LPCTSTR**

A pointer to the **null**-terminated string that contains the name of the value to be queried.

### `pdwType` [in, out, optional]

Type: **LPDWORD***

A pointer to the variable that sets or receives the key's value type. For more information, see [Registry Data Types](https://learn.microsoft.com/windows/desktop/shell/hkey-type). This parameter can be **NULL**.

### `pvData` [out, optional]

Type: **LPVOID***

A pointer to the buffer that receives the value's data. This parameter can be **NULL** if the data is not required.

### `pcbData` [in, out]

Type: **LPDWORD***

A pointer to the variable that specifies the size, in bytes, of the buffer pointed to by the *pvData* parameter. When the function returns, this variable contains the size of the data copied to *pvData*.

### `fIgnoreHKCU` [in]

Type: **BOOL**

The variable that specifies which key to look under. When set to **TRUE**, **SHRegQueryUSValue** ignores **HKEY_CURRENT_USER** and returns the value from the key under **HKEY_LOCAL_MACHINE**.

### `pvDefaultData` [in, optional]

Type: **LPVOID***

A pointer to the default data.

### `dwDefaultDataSize` [in, optional]

Type: **DWORD**

The length, in bytes, of the default data.

##### - hUSKey.HKEY_CLASSES_ROOT

##### - hUSKey.HKEY_CURRENT_CONFIG

##### - hUSKey.HKEY_CURRENT_USER

##### - hUSKey.HKEY_LOCAL_MACHINE

##### - hUSKey.HKEY_PERFORMANCE_DATA

##### - hUSKey.HKEY_USERS

## Return value

Type: **LSTATUS**

Returns ERROR_SUCCESS if successful, or a nonzero error code defined in Winerror.h otherwise. You can use the [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) function with the FORMAT_MESSAGE_FROM_SYSTEM flag to retrieve a generic description of the error.

## Remarks

When *fIgnoreHKCU* is set to **TRUE**, **SHRegQueryUSValue** returns the value from the key under **HKEY_LOCAL_MACHINE**. When set to **FALSE**, **SHRegQueryUSValue** first tries to return the value from the key under **HKEY_CURRENT_USER**. However, if the key is not found under **HKEY_CURRENT_USER**, the value returns from the key under **HKEY_LOCAL_MACHINE**. If neither key is present, or if an error occurs and *dwDefaultDataSize* is nonzero, then the default data is copied to *pvData* and ERROR_SUCCESS returns. ERROR_SUCCESS returns for both default and non-default data, and there is no way of distinguishing which value copies to *pvData*. To prevent the use of default data, set *pvDefaultData* to **NULL** and *dwDefaultDataSize* to zero.

If you only need to read a single value, [SHRegGetUSValue](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-shreggetusvaluea) will both open the key and return the value. To use **SHRegQueryUSValue**, you must first open the key with [SHRegOpenUSKey](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-shregopenuskeya). However, once the key is opened, you can use **SHRegQueryUSValue** as many times as necessary. If you need to retrieve more than one value from the same key, using multiple calls to **SHRegQueryUSValue** is usually more efficient than **SHRegGetUSValue**, as the key is only opened once.

> [!NOTE]
> The shlwapi.h header defines SHRegQueryUSValue as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).