# SHSetValueW function

## Description

Sets the value of a registry key.

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

The address of a null-terminated string that specifies the name of the subkey with which a value is associated. This can be **NULL** or a pointer to an empty string. In this case, the value is added to the key identified by the *hkey* parameter.

### `pszValue` [in, optional]

Type: **LPCTSTR**

The address of a null-terminated string that specifies the value. This value can be **NULL**.

### `dwType` [in]

Type: **DWORD**

Type of data to be stored. This parameter must be the **REG_SZ** type. For more information, see [Registry Data Types](https://learn.microsoft.com/windows/desktop/shell/hkey-type).

### `pvData` [in, optional]

Type: **LPCVOID**

Pointer to a buffer that contains the data to set for the specified value. This value can be **NULL**.

### `cbData` [in]

Type: **DWORD**

Length, in bytes, of the buffer pointed to by the *pvData* parameter. If the data is a null-terminated string, this length includes the terminating null character.

##### - hkey.HKEY_CLASSES_ROOT

##### - hkey.HKEY_CURRENT_CONFIG

##### - hkey.HKEY_CURRENT_USER

##### - hkey.HKEY_LOCAL_MACHINE

##### - hkey.HKEY_PERFORMANCE_DATA

##### - hkey.HKEY_USERS

## Return value

Type: **LSTATUS**

Returns ERROR_SUCCESS if successful; otherwise, a nonzero error code defined in Winerror.h. You can use the [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) function with the FORMAT_MESSAGE_FROM_SYSTEM flag to retrieve a generic description of the error.

## Remarks

> [!NOTE]
> The shlwapi.h header defines SHSetValue as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).