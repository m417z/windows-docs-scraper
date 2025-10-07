# CreateUserProfileEx function

\[This function is not available as of Windows Vista.\]

Creates a user profile for a specified user.

## Parameters

*pSid* \[in\]

Type: **PSID**

The SID of the new user.

*lpUserName* \[in\]

Type: **LPCTSTR**

Pointer to a buffer that contains the user name of the new user.

*lpUserHive* \[in, optional\]

Type: **LPCTSTR**

Pointer to a buffer that contains the [registry hive](https://learn.microsoft.com/windows/win32/sysinfo/registry-hives) to use. This parameter can be **NULL**.

*lpProfileDir* \[out, optional\]

Type: **LPTSTR**

Pointer to a buffer that, when this function returns, receives the user's profile directory path. This parameter can be **NULL**.

*dwDirSize* \[in\]

Type: **DWORD**

Size of the buffer specified by *lpProfileDir*, in TCHARs.

*bWin9xUpg* \[in\]

Type: **BOOL**

**TRUE** if the user profile is being created as part of a profile migration from Windows 9x; otherwise, **FALSE**.

When **TRUE**, the user profile is set up in the default profile directory—normally C:\\Documents and Settings\\*UserName*. If that directory already exists, it is used. If it does not, it is created.

If **FALSE**, the default profile directory is created if it does not exist. If the default profile directory already exists, a new directory is created for this user profile.

## Return value

Type: **BOOL**

Returns **TRUE** if the new user profile was created successfully; otherwise, **FALSE**.

## Remarks

This function is not declared in the software development kit (SDK) headers and has no associated import library. You must use the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to link to Userenv.dll. The ANSI version of the function, **CreateUserProfileExA** is referenced from Userenv.dll as ordinal 153. The Unicode version, **CreateUserProfileExW** is referenced as ordinal 154.

## Requirements

| Requirement | Value |
|-----------------------------------|----------------------------------------------------------------------------------------|
| End of client support<br> | Windows XP<br> |
| DLL<br> | Userenv.dll |
| Unicode and ANSI names<br> | **CreateUserProfileExW** (Unicode) and **CreateUserProfileExA** (ANSI)<br> |

