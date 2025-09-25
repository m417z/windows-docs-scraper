# SHRegGetPathW function

## Description

Retrieves a file path from the registry, expanding environment variables as needed.

## Parameters

### `hKey` [in]

Type: **HKEY**

A handle to a key that is currently open, or a registry root key.

### `pcszSubKey` [in]

Type: **LPCTSTR**

A pointer to a null-terminated string that contains the name of the subkey.

### `pcszValue` [in]

Type: **LPCTSTR**

A pointer to a null-terminated string that contains the name of the value that holds the unexpanded path string.

### `pszPath` [out]

Type: **LPTSTR**

A buffer to hold the expanded path. You should set the size of this buffer to **MAX_PATH** to ensure that it is large enough to hold the returned string.

### `dwFlags`

Type: **DWORD**

Reserved.

## Return value

Type: **LSTATUS**

Returns **ERROR_SUCCESS** if successful, or a Windows error code otherwise.

## Remarks

The data type of the specified registry value must be either **REG_EXPAND_SZ** or **REG_SZ**. If it has the **REG_EXPAND_SZ** type, any environment variables in the registry string will be expanded with [ExpandEnvironmentStrings](https://learn.microsoft.com/windows/desktop/api/rrascfg/nn-rrascfg-ieapproviderconfig). If it has the **REG_SZ** data type, environment variables will not be expanded and the string pointed to by *pszPath* will be identical to the string in the registry.

The following environment strings will be replaced by their equivalent path.

| Environment string | Folder |
| --- | --- |
| %USERPROFILE% | The current user's profile folder |
| %ALLUSERSPROFILE% | The All Users profile folder |
| %ProgramFiles% | The Program Files folder |
| %SystemRoot% | The system root folder |
| %SystemDrive% | The system drive letter |

**Note** %USERPROFILE% is relative to the user making the call. This function does not work if the user is being impersonated from a service.

> [!NOTE]
> The shlwapi.h header defines SHRegGetPath as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).