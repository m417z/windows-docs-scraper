# SHRegSetPathW function

## Description

Takes a file path, replaces folder names with environment strings, and places the resulting string in the registry.

## Parameters

### `hKey` [in]

Type: **HKEY**

A handle to a key that is currently open, or a registry root key.

### `pcszSubKey` [in]

Type: **LPCTSTR**

A pointer to a null-terminated string containing the name of an existing subkey. If the subkey does not exist, **SHRegSetPath** will fail.

### `pcszValue` [in]

Type: **LPCTSTR**

A pointer to a null-terminated string with the name of the value to hold the path string.

### `pcszPath` [in]

Type: **LPCTSTR**

A pointer to a null-terminated string with a fully qualified file path.

### `dwFlags`

Type: **DWORD**

Reserved.

## Return value

Type: **LSTATUS**

Returns ERROR_SUCCESS if successful, or a Windows error code otherwise.

## Remarks

For Windows 2000, **SHRegSetPath** uses [PathUnExpandEnvStrings](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-pathunexpandenvstringsa) to convert folder names to their corresponding environment string. If any environment variables were substituted, the registry value will be set with the **REG_EXPAND_SZ** data type. Otherwise, it will be set with the **REG_SZ** data type.

The following folder paths will be replaced by their equivalent environment string.

| Folder | Environment string |
| --- | --- |
| The current user's profile folder | %USERPROFILE% |
| The All Users profile folder | %ALLUSERSPROFILE% |
| The Program Files folder | %ProgramFiles% |
| The system root folder | %SystemRoot% |
| The system drive letter | %SystemDrive% |

**Note** %USERPROFILE% is relative to the user making the call. This function does not work if the user is being impersonated from a service.

The environment variables listed in the above table might not all be set on any particular system. If an environment variable is not set, it will not be unexpanded. In particular, none of these variables are set for the default environment of Windows 95 or Windows 98. The %ProgramFiles% variable is new for Windows 2000, and will typically not be set on Microsoft Windows NT 4.0 systems.

> [!NOTE]
> The shlwapi.h header defines SHRegSetPath as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).