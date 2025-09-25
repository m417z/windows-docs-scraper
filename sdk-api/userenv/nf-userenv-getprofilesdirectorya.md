# GetProfilesDirectoryA function

## Description

Retrieves the path to the root directory where user profiles are stored.

## Parameters

### `lpProfileDir` [out]

Type: **LPTSTR**

A pointer to a buffer that, when this function returns successfully, receives the path to the profiles directory. Set this value to **NULL** to determine the required size of the buffer.

### `lpcchSize` [in, out]

Type: **LPDWORD**

Specifies the size of the *lpProfilesDir* buffer, in **TCHARs**.

If the buffer specified by *lpProfilesDir* is not large enough or *lpProfilesDir* is **NULL**, the function fails and this parameter receives the necessary buffer size, including the terminating null character.

## Return value

Type: **BOOL**

**TRUE** if successful; otherwise, **FALSE**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The following is an example of the path returned by **GetProfilesDirectory** in Windows XP:

``` syntax
C:\Documents and Settings
```

The following is an example of the path returned by **GetProfilesDirectory** in Windows 7:

``` syntax
C:\Users
```

To obtain the paths of subdirectories of this directory, use the [SHGetFolderPath](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shgetfolderpatha) (Windows XP and earlier) or [SHGetKnownFolderPath](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shgetknownfolderpath) (Windows Vista) function.

> [!NOTE]
> The userenv.h header defines GetProfilesDirectory as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[GetAllUsersProfileDirectory](https://learn.microsoft.com/windows/desktop/api/userenv/nf-userenv-getallusersprofiledirectorya)

[GetDefaultUserProfileDirectory](https://learn.microsoft.com/windows/desktop/api/userenv/nf-userenv-getdefaultuserprofiledirectorya)

[GetUserProfileDirectory](https://learn.microsoft.com/windows/desktop/api/userenv/nf-userenv-getuserprofiledirectorya)

[User Profiles Overview](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb776900(v=vs.85))

[User Profiles Reference](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb776901(v=vs.85))