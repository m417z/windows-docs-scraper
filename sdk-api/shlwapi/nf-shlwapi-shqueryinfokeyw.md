# SHQueryInfoKeyW function

## Description

Retrieves information about a specified registry key.

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

### `pcSubKeys` [out, optional]

Type: **LPDWORD**

The address of a **DWORD** that receives the number of subkeys under the specified key.

### `pcchMaxSubKeyLen` [out, optional]

Type: **LPDWORD**

The address of a **DWORD** that receives the number of characters in the name of the subkey with the largest name.

### `pcValues` [out, optional]

Type: **LPDWORD**

The address of a **DWORD** that receives the number of values under the specified key.

### `pcchMaxValueNameLen` [out, optional]

Type: **LPDWORD**

The address of a **DWORD** that receives the number of characters in the name of the value with the largest name.

##### - hkey.HKEY_CLASSES_ROOT

##### - hkey.HKEY_CURRENT_CONFIG

##### - hkey.HKEY_CURRENT_USER

##### - hkey.HKEY_LOCAL_MACHINE

##### - hkey.HKEY_PERFORMANCE_DATA

##### - hkey.HKEY_USERS

## Return value

Type: **LSTATUS**

Returns ERROR_SUCCESS if successful, or a nonzero error code defined in Winerror.h otherwise. You can use the [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) function with the FORMAT_MESSAGE_FROM_SYSTEM flag to retrieve a textual description of the error.

## Remarks

> [!NOTE]
> The shlwapi.h header defines SHQueryInfoKey as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).