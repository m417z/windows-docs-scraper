# SHEnumKeyExA function

## Description

Enumerates the subkeys of the specified open registry key.

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

### `dwIndex`

Type: **DWORD**

The index of the subkey to retrieve. This parameter should be zero for the first call and incremented for subsequent calls.

### `pszName`

Type: **LPTSTR**

The address of a character buffer that receives the enumerated key name.

### `pcchName` [in]

Type: **LPDWORD**

The address of a **DWORD** that, on entry, contains the size of the buffer at *pszName*, in characters. On exit, this contains the number of characters that were copied to *pszName*.

## Return value

Type: **LSTATUS**

Returns ERROR_SUCCESS if successful, or a nonzero error code defined in Winerror.h otherwise. You can use the [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) function with the FORMAT_MESSAGE_FROM_SYSTEM flag to retrieve a textual description of the error.

## Remarks

> [!NOTE]
> The shlwapi.h header defines SHEnumKeyEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).