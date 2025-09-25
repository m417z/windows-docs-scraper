# UnloadUserProfile function

## Description

Unloads a user's profile that was loaded by the [LoadUserProfile](https://learn.microsoft.com/windows/desktop/api/userenv/nf-userenv-loaduserprofilea) function. The caller must have administrative privileges on the computer. For more information, see the Remarks section of the **LoadUserProfile** function.

## Parameters

### `hToken` [in]

Type: **HANDLE**

Token for the user, returned from the [LogonUser](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-logonusera), [CreateRestrictedToken](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-createrestrictedtoken), [DuplicateToken](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-duplicatetoken), [OpenProcessToken](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-openprocesstoken), or [OpenThreadToken](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-openthreadtoken) function. The token must have **TOKEN_IMPERSONATE** and **TOKEN_DUPLICATE** access. For more information, see [Access Rights for Access-Token Objects](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-rights-for-access-token-objects).

### `hProfile` [in]

Type: **HANDLE**

Handle to the registry key. This value is the **hProfile** member of the [PROFILEINFO](https://learn.microsoft.com/windows/desktop/api/profinfo/ns-profinfo-profileinfoa) structure. For more information see the Remarks section of [LoadUserProfile](https://learn.microsoft.com/windows/desktop/api/userenv/nf-userenv-loaduserprofilea) and [Registry Key Security and Access Rights](https://learn.microsoft.com/windows/desktop/SysInfo/registry-key-security-and-access-rights).

## Return value

Type: **BOOL**

**TRUE** if successful; otherwise, **FALSE**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Before calling **UnloadUserProfile** you should ensure that all handles to keys that you have opened in the user's registry hive are closed. If you do not close all open registry handles, the user's profile fails to unload. For more information, see
[Registry Key Security and Access Rights](https://learn.microsoft.com/windows/desktop/SysInfo/registry-key-security-and-access-rights) and [Registry Hives](https://learn.microsoft.com/windows/desktop/SysInfo/registry-hives).

For more information about calling functions that require administrator privileges, see [Running with Special Privileges](https://learn.microsoft.com/windows/desktop/SecBP/running-with-special-privileges).

## See also

[LoadUserProfile](https://learn.microsoft.com/windows/desktop/api/userenv/nf-userenv-loaduserprofilea)

[PROFILEINFO](https://learn.microsoft.com/windows/desktop/api/profinfo/ns-profinfo-profileinfoa)

[User Profiles Overview](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb776900(v=vs.85))

[User Profiles Reference](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb776901(v=vs.85))