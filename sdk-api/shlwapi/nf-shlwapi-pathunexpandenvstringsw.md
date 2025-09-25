# PathUnExpandEnvStringsW function

## Description

Replaces certain folder names in a fully qualified path with their associated environment string.

## Parameters

### `pszPath` [in]

Type: **LPCTSTR**

A pointer to a null-terminated string of maximum length MAX_PATH that contains the path to be unexpanded.

### `pszBuf` [out]

Type: **LPTSTR**

A pointer to a buffer that, when this method returns successfully, receives the unexpanded string. The size of this buffer must be set to MAX_PATH to ensure that it is large enough to hold the returned string.

### `cchBuf` [in]

Type: **UINT**

The size, in characters, in the *pszBuf* buffer.

## Return value

Type: **BOOL**

Returns **TRUE** if successful; otherwise, **FALSE**.

## Remarks

The following folder paths are replaced by their equivalent environment string.

| Folder | Environment String |
| --- | --- |
| The All Users profile folder | %ALLUSERSPROFILE% |
| The current user's application data folder (Windows Vista and later only). | %APPDATA% |
| The system name | %COMPUTERNAME% |
| The Program Files folder | %ProgramFiles% |
| The system root folder | %SystemRoot% |
| The system drive letter | %SystemDrive% |
| The current user's profile folder | %USERPROFILE% |

**Note** %APPDATA% and %USERPROFILE% are relative to the user making the call. This function does not work if the user is being impersonated from a service. For further discussion of access control issues, see [Access Control](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control).

The environment variables listed in the above table might not all be set on all systems. If an environment variable is not set, it is not unexpanded.

> [!NOTE]
> The shlwapi.h header defines PathUnExpandEnvStrings as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[DoEnvironmentSubst](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-doenvironmentsubsta)