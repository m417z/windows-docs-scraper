# SHGetValueA function

## Description

Retrieves a registry value.

## Parameters

### `hkey` [in]

Type: **HKEY**

A handle to the currently open key, or any of the following predefined values.

#### HKEY_CLASSES_ROOT

#### HKEY_CURRENT_CONFIG

#### HKEY_CURRENT_USER

#### HKEY_LOCAL_MACHINE

#### HKEY_PERFORMANCE_DATA

#### HKEY_USERS

### `pszSubKey` [in, optional]

Type: **LPCTSTR**

The address of a null-terminated string that specifies the name of the subkey from which to retrieve the value.

### `pszValue` [in, optional]

Type: **LPCTSTR**

The address of the value.

### `pdwType` [out, optional]

Type: **LPDWORD**

The type of value. For more information, see [Registry Data Types](https://learn.microsoft.com/windows/desktop/shell/hkey-type).

### `pvData` [out, optional]

Type: **LPVOID**

The address of the destination data buffer.

### `pcbData` [in, out, optional]

Type: **LPDWORD**

The size of the destination data buffer.

## Return value

Type: **LSTATUS**

Returns ERROR_SUCCESS if successful, or a nonzero error code defined in Winerror.h otherwise. You can use the [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) function with the FORMAT_MESSAGE_FROM_SYSTEM flag to retrieve a generic description of the error.

## Remarks

If your application must set/retrieve a series of values in the same key, it is better to open the key once and set/retrieve the values with the regular Microsoft Win32 registry functions rather than use this function repeatedly.

> [!NOTE]
> The shlwapi.h header defines SHGetValue as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).