# LoadUserProfileW function

## Description

Loads the specified user's profile. The profile can be a
[local user profile](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb776894(v=vs.85)) or a
[roaming user profile](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb776897(v=vs.85)).

## Parameters

### `hToken` [in]

Type: **HANDLE**

Token for the user, which is returned by the [LogonUser](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-logonusera), [CreateRestrictedToken](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-createrestrictedtoken), [DuplicateToken](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-duplicatetoken), [OpenProcessToken](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-openprocesstoken), or [OpenThreadToken](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-openthreadtoken) function. The token must have **TOKEN_QUERY**, **TOKEN_IMPERSONATE**, and **TOKEN_DUPLICATE** access. For more information, see [Access Rights for Access-Token Objects](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-rights-for-access-token-objects).

### `lpProfileInfo` [in, out]

Type: **LPPROFILEINFO**

Pointer to a [PROFILEINFO](https://learn.microsoft.com/windows/desktop/api/profinfo/ns-profinfo-profileinfoa) structure. **LoadUserProfile** fails and returns **ERROR_INVALID_PARAMETER** if the **dwSize** member of the structure is not set to `sizeof(PROFILEINFO)` or if the **lpUserName** member is **NULL**. For more information, see Remarks.

## Return value

Type: **BOOL**

**TRUE** if successful; otherwise, **FALSE**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The function fails and returns ERROR_INVALID_PARAMETER if the **dwSize** member of the structure at *lpProfileInfo* is not set to `sizeof(PROFILEINFO)` or if the **lpUserName** member is **NULL**.

## Remarks

When a user logs on interactively, the system automatically loads the user's profile. If a service or an application impersonates a user, the system does not load the user's profile. Therefore, the service or application should load the user's profile with **LoadUserProfile**.

Services and applications that call **LoadUserProfile** should check to see if the user has a roaming profile. If the user has a roaming profile, specify its path as the **lpProfilePath** member of
[PROFILEINFO](https://learn.microsoft.com/windows/desktop/api/profinfo/ns-profinfo-profileinfoa). To retrieve the user's roaming profile path, you can call the
[NetUserGetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusergetinfo) function, specifying information level 3 or 4.

Upon successful return, the **hProfile** member of [PROFILEINFO](https://learn.microsoft.com/windows/desktop/api/profinfo/ns-profinfo-profileinfoa) is a registry key handle opened to the root of the user's hive. It has been opened with full access (KEY_ALL_ACCESS). If a service that is impersonating a user needs to read or write to the user's registry file, use this handle instead of **HKEY_CURRENT_USER**. Do not close the **hProfile** handle. Instead, pass it to the
[UnloadUserProfile](https://learn.microsoft.com/windows/desktop/api/userenv/nf-userenv-unloaduserprofile) function. This function closes the handle. You should ensure that all handles to keys in the user's registry hive are closed. If you do not close all open registry handles, the user's profile fails to unload. For more information, see
[Registry Key Security and Access Rights](https://learn.microsoft.com/windows/desktop/SysInfo/registry-key-security-and-access-rights) and [Registry Hives](https://learn.microsoft.com/windows/desktop/SysInfo/registry-hives).

Note that it is your responsibility to load the user's registry hive into the **HKEY_USERS** registry key with the **LoadUserProfile** function before you call [CreateProcessAsUser](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessasusera). This is because **CreateProcessAsUser** does not load the specified user's profile into **HKEY_USERS**. This means that access to information in the **HKEY_CURRENT_USER** registry key may not produce results consistent with a normal interactive logon.

The calling process must have the **SE_RESTORE_NAME** and **SE_BACKUP_NAME** privileges. For more information, see [Running with Special Privileges](https://learn.microsoft.com/windows/desktop/SecBP/running-with-special-privileges).

Starting with Windows XP Service Pack 2 (SP2) and Windows Server 2003, the caller must be an administrator or the LocalSystem account. It is not sufficient for the caller to merely impersonate the administrator or LocalSystem account.

> [!NOTE]
> The userenv.h header defines LoadUserProfile as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[PROFILEINFO](https://learn.microsoft.com/windows/desktop/api/profinfo/ns-profinfo-profileinfoa)

[UnloadUserProfile](https://learn.microsoft.com/windows/desktop/api/userenv/nf-userenv-unloaduserprofile)

[User Profiles Overview](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb776900(v=vs.85))

[User Profiles Reference](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb776901(v=vs.85))