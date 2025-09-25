# SHDeleteKeyA function

## Description

Deletes a subkey and all its descendants. This function removes the key and all the key's values from the registry.

## Parameters

### `hkey` [in]

Type: **HKEY**

A handle to an open registry key, or one of the following [predefined keys](https://learn.microsoft.com/windows/desktop/SysInfo/predefined-keys):

#### HKEY_CLASSES_ROOT

#### HKEY_CURRENT_CONFIG

#### HKEY_CURRENT_USER

#### HKEY_LOCAL_MACHINE

#### HKEY_PERFORMANCE_DATA

#### HKEY_USERS

### `pszSubKey` [in, optional]

Type: **LPCTSTR**

The address of a null-terminated string specifying the name of the key to delete.

## Return value

Type: **LSTATUS**

Returns **ERROR_SUCCESS** if successful, or a nonzero error code defined in Winerror.h otherwise. You can use the [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) function with the **FORMAT_MESSAGE_FROM_SYSTEM** flag to retrieve a generic description of the error.

## Remarks

Alternatively, use the [RegDeleteKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regdeletekeya) or [RegDeleteTree](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regdeletetreea) function.

> [!NOTE]
> The shlwapi.h header defines SHDeleteKey as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).