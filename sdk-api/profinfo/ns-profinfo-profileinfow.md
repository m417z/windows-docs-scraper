# PROFILEINFOW structure

## Description

Contains information used when loading or unloading a user profile.

## Members

### `dwSize`

Type: **DWORD**

The size of this structure, in bytes.

### `dwFlags`

Type: **DWORD**

This member can be one of the following flags:

#### PI_NOUI

Prevents the display of profile error messages.

#### PI_APPLYPOLICY

Not supported.

### `lpUserName`

Type: **LPTSTR**

A pointer to the name of the user. This member is used as the base name of the directory in which to store a new profile.

### `lpProfilePath`

Type: **LPTSTR**

A pointer to the [roaming user profile](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb776897(v=vs.85)) path. If the user does not have a roaming profile, this member can be **NULL**. To retrieve the user's roaming profile path, call the [NetUserGetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusergetinfo) function, specifying information level 3 or 4. For more information, see Remarks.

### `lpDefaultPath`

Type: **LPTSTR**

A pointer to the default user profile path. This member can be **NULL**.

### `lpServerName`

Type: **LPTSTR**

A pointer to the name of the validating domain controller, in NetBIOS format.

### `lpPolicyPath`

Type: **LPTSTR**

Not used, set to **NULL**.

### `hProfile`

Type: **HANDLE**

A handle to the **HKEY_CURRENT_USER** registry subtree. For more information, see Remarks.

##### - dwFlags.PI_APPLYPOLICY

Not supported.

##### - dwFlags.PI_NOUI

Prevents the display of profile error messages.

## Remarks

Do not use environment variables when specifying a path. The
[LoadUserProfile](https://learn.microsoft.com/windows/desktop/api/userenv/nf-userenv-loaduserprofilea) function does not expand environment variables, such as %username%, in a path.

When the [LoadUserProfile](https://learn.microsoft.com/windows/desktop/api/userenv/nf-userenv-loaduserprofilea) call returns successfully, the **hProfile** member receives a registry key handle opened to the root of the user's subtree, opened with full access (KEY_ALL_ACCESS). For more information see the Remarks sections in **LoadUserProfile**,
[Registry Key Security and Access Rights](https://learn.microsoft.com/windows/desktop/SysInfo/registry-key-security-and-access-rights), and
[Registry Hives](https://learn.microsoft.com/windows/desktop/SysInfo/registry-hives).

Services and applications that call [LoadUserProfile](https://learn.microsoft.com/windows/desktop/api/userenv/nf-userenv-loaduserprofilea) should check to see if the user has a roaming profile. If the user has a roaming profile, specify its path as the **lpProfilePath** member of this structure.

> [!NOTE]
> The profinfo.h header defines PROFILEINFO as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[LoadUserProfile](https://learn.microsoft.com/windows/desktop/api/userenv/nf-userenv-loaduserprofilea)

[UnloadUserProfile](https://learn.microsoft.com/windows/desktop/api/userenv/nf-userenv-unloaduserprofile)

[User Profiles Overview](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb776900(v=vs.85))