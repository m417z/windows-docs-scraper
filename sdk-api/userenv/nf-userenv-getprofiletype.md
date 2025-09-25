# GetProfileType function

## Description

Retrieves the type of profile loaded for the current user.

## Parameters

### `dwFlags` [out]

Type: **DWORD***

Pointer to a variable that receives the profile type. If the function succeeds, it sets one or more of the following values:

#### PT_MANDATORY

The user has a [Mandatory User Profiles](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb776895(v=vs.85)).

#### PT_ROAMING

The user has a [Roaming User Profiles](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb776897(v=vs.85)).

#### PT_ROAMING_PREEXISTING

The user has a [Roaming User Profile](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb776897(v=vs.85)) that was created on another PC and is being downloaded.
This profile type implies **PT_ROAMING**.

#### PT_TEMPORARY

The user has a [Temporary User Profiles](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb776898(v=vs.85)); it will be deleted at logoff.

## Return value

Type: **BOOL**

**TRUE** if successful; otherwise, **FALSE**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If the user profile is not already loaded, the function fails.

Note that the caller must have **KEY_READ** access to **HKEY_LOCAL_MACHINE**. This access right is granted by default. For more information, see [Registry Key Security and Access Rights](https://learn.microsoft.com/windows/desktop/SysInfo/registry-key-security-and-access-rights).

If the profile type is **PT_ROAMING_PREEXISTING**, Explorer will not reinitialize default programs associations when a profile is loaded on a machine for the first time.

## See also

[LoadUserProfile](https://learn.microsoft.com/windows/desktop/api/userenv/nf-userenv-loaduserprofilea)

[User Profiles Overview](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb776900(v=vs.85))

[User Profiles Reference](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb776901(v=vs.85))