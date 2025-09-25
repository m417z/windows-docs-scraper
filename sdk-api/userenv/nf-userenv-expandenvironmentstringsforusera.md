# ExpandEnvironmentStringsForUserA function

## Description

Expands the source string by using the environment block established for the specified user.

## Parameters

### `hToken` [in, optional]

Type: **HANDLE**

Token for the user, returned from the [LogonUser](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-logonusera), [CreateRestrictedToken](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-createrestrictedtoken), [DuplicateToken](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-duplicatetoken), [OpenProcessToken](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-openprocesstoken), or [OpenThreadToken](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-openthreadtoken) function. The token must have TOKEN_IMPERSONATE and TOKEN_QUERY access. In addition, as of Windows 7 the token must also have TOKEN_DUPLICATE access. For more information, see [Access Rights for Access-Token Objects](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-rights-for-access-token-objects).

If *hToken* is **NULL**, the environment block contains system variables only.

### `lpSrc` [in]

Type: **LPCTSTR**

Pointer to the null-terminated source string to be expanded.

### `lpDest` [out]

Type: **LPTSTR**

Pointer to a buffer that receives the expanded strings.

### `dwSize` [in]

Type: **DWORD**

Specifies the size of the *lpDest* buffer, in **TCHARs**.

## Return value

Type: **BOOL**

**TRUE** if successful; otherwise, **FALSE**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The following is an example source string:

```
%USERPROFILE%\ntuser.dat
```

When **ExpandEnvironmentStringsForUser** returns, the destination string expands as follows:

```
C:\Documents and Settings\UserName\ntuser.dat
```

> [!NOTE]
> The userenv.h header defines ExpandEnvironmentStringsForUser as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[User Profiles Overview](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb776900(v=vs.85))

[User Profiles Reference](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb776901(v=vs.85))