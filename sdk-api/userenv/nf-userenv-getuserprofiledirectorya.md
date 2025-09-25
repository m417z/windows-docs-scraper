# GetUserProfileDirectoryA function

## Description

Retrieves the path to the root directory of the specified user's profile.

## Parameters

### `hToken` [in]

Type: **HANDLE**

A token for the user, which is returned by the [LogonUser](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-logonusera), [CreateRestrictedToken](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-createrestrictedtoken), [DuplicateToken](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-duplicatetoken), [OpenProcessToken](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-openprocesstoken), or [OpenThreadToken](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-openthreadtoken) function. The token must have TOKEN_QUERY access. For more information, see [Access Rights for Access-Token Objects](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-rights-for-access-token-objects).

### `lpProfileDir` [out, optional]

Type: **LPTSTR**

A pointer to a buffer that, when this function returns successfully, receives the path to the specified user's profile directory.

### `lpcchSize` [in, out]

Type: **LPDWORD**

Specifies the size of the *lpProfileDir* buffer, in **TCHARs**.

If the buffer specified by *lpProfileDir* is not large enough or *lpProfileDir* is **NULL**, the function fails and this parameter receives the necessary buffer size, including the terminating null character.

If the function succeeds then this parameter receives the number of **TCHARs** written to *lpProfileDir*, including the terminating null character.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The following is an example of the path returned by **GetUserProfileDirectory** in Windows XP:

``` syntax
C:\Documents and Settings\Joe
```

The following is an example of the path returned by **GetUserProfileDirectory** in Windows 7:

``` syntax
C:\Users\Joe
```

To obtain the paths of subdirectories of this directory, use the [SHGetFolderPath](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shgetfolderpatha) (Windows XP and earlier) or [SHGetKnownFolderPath](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shgetknownfolderpath) (Windows Vista) function.

> [!NOTE]
> The userenv.h header defines GetUserProfileDirectory as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[GetAllUsersProfileDirectory](https://learn.microsoft.com/windows/desktop/api/userenv/nf-userenv-getallusersprofiledirectorya)

[GetDefaultUserProfileDirectory](https://learn.microsoft.com/windows/desktop/api/userenv/nf-userenv-getdefaultuserprofiledirectorya)

[GetProfilesDirectory](https://learn.microsoft.com/windows/desktop/api/userenv/nf-userenv-getprofilesdirectorya)

[User Profiles Overview](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb776900(v=vs.85))

[User Profiles Reference](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb776901(v=vs.85))