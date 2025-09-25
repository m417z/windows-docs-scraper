# SHQueryValueExW function

## Description

Opens a registry key and queries it for a specific value.

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

### `pszValue` [in, optional]

Type: **LPCTSTR**

The address of the **null**-terminated string that contains the name of the value to be queried.

### `pdwReserved`

Type: **LPDWORD**

Reserved. Must be **NULL**.

### `pdwType` [out, optional]

Type: **LPDWORD**

The address of the variable that receives the key's value type. For more information, see [Registry Data Types](https://learn.microsoft.com/windows/desktop/shell/hkey-type).

### `pvData` [out, optional]

Type: **LPVOID**

The address of the buffer that receives the value's data. This parameter can be **NULL** if the data is not required.

### `pcbData` [in, out, optional]

Type: **LPDWORD**

The address of the variable that specifies the size, in bytes, of the buffer pointed to by the *pvData* parameter. When the function returns, this variable contains the size of the data copied to *pvData*.

##### - hkey.HKEY_CLASSES_ROOT

##### - hkey.HKEY_CURRENT_CONFIG

##### - hkey.HKEY_CURRENT_USER

##### - hkey.HKEY_LOCAL_MACHINE

##### - hkey.HKEY_PERFORMANCE_DATA

##### - hkey.HKEY_USERS

## Return value

Type: **DWORD**

Returns ERROR_SUCCESS if successful, or a nonzero error code defined in Winerror.h otherwise. You can use the [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) function with the FORMAT_MESSAGE_FROM_SYSTEM flag to retrieve a generic description of the error.

## Remarks

> [!NOTE]
> The shlwapi.h header defines SHQueryValueEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).