# DeleteProfileA function

## Description

Deletes the user profile and all user-related settings from the specified computer. The caller must have administrative privileges to delete a user's profile.

## Parameters

### `lpSidString` [in]

Type: **LPCTSTR**

Pointer to a string that specifies the user
[SID](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-identifiers).

### `lpProfilePath` [in, optional]

Type: **LPCTSTR**

Pointer to a string that specifies the profile path. If this parameter is **NULL**, the function obtains the path from the registry.

### `lpComputerName` [in, optional]

Type: **LPCTSTR**

Pointer to a string that specifies the name of the computer from which the profile is to be deleted. If this parameter is **NULL**, the local computer name is used.

**Note** As of Windows Vista, this parameter must be **NULL**. If it is not, this function fails with the error code ERROR_INVALID_PARAMETER.

## Return value

Type: **BOOL**

**TRUE** if successful; otherwise, **FALSE**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

**DeleteProfile** might fail when passed the security identifier (SID) of the local system account (S-1-5-18).

> [!NOTE]
> The userenv.h header defines DeleteProfile as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[User Profiles Overview](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb776900(v=vs.85))

[User Profiles Reference](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb776901(v=vs.85))