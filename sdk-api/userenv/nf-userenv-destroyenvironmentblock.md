# DestroyEnvironmentBlock function

## Description

Frees environment variables created by the [CreateEnvironmentBlock](https://learn.microsoft.com/windows/desktop/api/userenv/nf-userenv-createenvironmentblock) function.

## Parameters

### `lpEnvironment` [in]

Type: **LPVOID**

Pointer to the environment block created by
[CreateEnvironmentBlock](https://learn.microsoft.com/windows/desktop/api/userenv/nf-userenv-createenvironmentblock). The environment block is an array of null-terminated Unicode strings. The list ends with two nulls (\0\0).

## Return value

Type: **BOOL**

**TRUE** if successful; otherwise, **FALSE**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[CreateEnvironmentBlock](https://learn.microsoft.com/windows/desktop/api/userenv/nf-userenv-createenvironmentblock)

[User Profiles Overview](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb776900(v=vs.85))

[User Profiles Reference](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb776901(v=vs.85))