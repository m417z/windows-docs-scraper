# RAS\_USER\_0 structure

\[This version of the **RAS\_USER\_0** structure is not supported as of Windows Vista. Use the newer [**RAS\_USER\_0**](https://learn.microsoft.com/windows/desktop/api/Mprapi/ns-mprapi-ras_user_0) defined in mprapi.h instead.\]

The **RAS\_USER\_0** structure is used in the [**RasAdminUserSetInfo**](https://learn.microsoft.com/windows/win32/rras/rasadminusersetinfo) and [**RasAdminUserGetInfo**](https://learn.microsoft.com/windows/win32/rras/rasadminusergetinfo) functions to specify information about a user.

## Members

**bfPrivilege**

A set of bit flags that specify the RAS privileges of the user. This member can be a combination of the RASPRIV\_DialinPrivilege flag and one of the call-back flags. Use the RASPRIV\_CallbackType mask to identify the type of call-back privilege provided to the user. The following flags are defined.

| Value | Meaning |
|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------------------------|
| **RASPRIV\_NoCallback** | The user has no call-back privilege.<br> |
| **RASPRIV\_AdminSetCallback** | The user account is configured to have the administrator set the call-back number.<br> |
| **RASPRIV\_CallerSetCallback** | The remote user can specify a call-back phone number when dialing in.<br> |
| **RASPRIV\_DialinPrivilege** | The user has permission to dial in to this server.<br> |

Specify one of the call-back flags in the call to the [**RasAdminUserSetInfo**](https://learn.microsoft.com/windows/win32/rras/rasadminusersetinfo) function.

**szPhoneNumber**

A null-terminated Unicode string that specifies the call-back phone number for the user.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| End of client support<br> | Windows XP<br> |
| End of server support<br> | Windows Server 2003<br> |
| Header<br> | Rassapi.h |

## See also

[Remote Access Service (RAS) Overview](https://learn.microsoft.com/windows/win32/rras/about-remote-access-service)

[RAS Server Administration Structures](https://learn.microsoft.com/windows/win32/rras/ras-server-administration-structures)

[**RasAdminUserGetInfo**](https://learn.microsoft.com/windows/win32/rras/rasadminusergetinfo)

[**RasAdminUserSetInfo**](https://learn.microsoft.com/windows/win32/rras/rasadminusersetinfo)

