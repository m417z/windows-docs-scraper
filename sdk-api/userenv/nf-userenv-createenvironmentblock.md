# CreateEnvironmentBlock function

## Description

Retrieves the environment variables for the specified user. This block can then be passed to the [CreateProcessAsUser](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessasusera) function.

## Parameters

### `lpEnvironment` [out]

Type: **LPVOID***

When this function returns, receives a pointer to the new environment block. The environment block is an array of null-terminated Unicode strings. The list ends with two nulls (\0\0).

### `hToken` [in, optional]

Type: **HANDLE**

Token for the user, returned from the
[LogonUser](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-logonusera) function. If this is a primary token, the token must have **TOKEN_QUERY** and **TOKEN_DUPLICATE** access. If the token is an impersonation token, it must have **TOKEN_QUERY** access. For more information, see
[Access Rights for Access-Token Objects](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-rights-for-access-token-objects).

If this parameter is **NULL**, the returned environment block contains system variables only.

### `bInherit` [in]

Type: **BOOL**

Specifies whether to inherit from the current process' environment. If this value is **TRUE**, the process inherits the current process' environment. If this value is **FALSE**, the process does not inherit the current process' environment.

## Return value

Type: **BOOL**

**TRUE** if successful; otherwise, **FALSE**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

To free the buffer when you have finished with the environment block, call the
[DestroyEnvironmentBlock](https://learn.microsoft.com/windows/desktop/api/userenv/nf-userenv-destroyenvironmentblock) function.

If the environment block is passed to
[CreateProcessAsUser](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessasusera), you must also specify the **CREATE_UNICODE_ENVIRONMENT** flag. After **CreateProcessAsUser** has returned, the new process has a copy of the environment block, and [DestroyEnvironmentBlock](https://learn.microsoft.com/windows/desktop/api/userenv/nf-userenv-destroyenvironmentblock) can be safely called.

User-specific environment variables such as %USERPROFILE% are set only when the user's profile is loaded. To load a user's profile, call the
[LoadUserProfile](https://learn.microsoft.com/windows/desktop/api/userenv/nf-userenv-loaduserprofilea) function.

## See also

[CreateProcessAsUser](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessasusera)

[DestroyEnvironmentBlock](https://learn.microsoft.com/windows/desktop/api/userenv/nf-userenv-destroyenvironmentblock)

[LogonUser](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-logonusera)

[User Profiles Overview](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb776900(v=vs.85))

[User Profiles Reference](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb776901(v=vs.85))