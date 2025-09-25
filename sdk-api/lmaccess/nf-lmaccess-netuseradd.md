# NetUserAdd function

## Description

The
**NetUserAdd** function adds a user account and assigns a password and privilege level.

## Parameters

### `servername` [in]

Pointer to a constant string that specifies the DNS or NetBIOS name of the remote server on which the function is to execute. If this parameter is **NULL**, the local computer is used.

This string is Unicode if **_WIN32_WINNT** or **FORCE_UNICODE** are defined.

### `level` [in]

Specifies the information level of the data. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **1** | Specifies information about the user account. The *buf* parameter points to a [USER_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_1) structure. <br><br>When you specify this level, the call initializes certain attributes to their default values. For more information, see the following Remarks section. |
| **2** | Specifies level one information and additional attributes about the user account. The *buf* parameter points to a [USER_INFO_2](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_2) structure. |
| **3** | Specifies level two information and additional attributes about the user account. This level is valid only on servers. The *buf* parameter points to a [USER_INFO_3](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_3) structure. Note that it is recommended that you use [USER_INFO_4](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_4) instead. |
| **4** | Specifies level two information and additional attributes about the user account. This level is valid only on servers. The *buf* parameter points to a [USER_INFO_4](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_4) structure.<br><br>**Windows 2000:** This level is not supported. |

### `buf` [in]

Pointer to the buffer that specifies the data. The format of this data depends on the value of the *level* parameter. For more information, see
[Network Management Function Buffers](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffers).

### `parm_err` [out]

Pointer to a value that receives the index of the first member of the user information structure that causes ERROR_INVALID_PARAMETER. If this parameter is **NULL**, the index is not returned on error. For more information, see the
[NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo) function.

## Return value

If the function succeeds, the return value is NERR_Success.

If the function fails, the return value can be one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The user does not have access to the requested information. |
| **NERR_InvalidComputer** | The computer name is invalid. |
| **NERR_NotPrimary** | The operation is allowed only on the primary domain controller of the domain. |
| **NERR_GroupExists** | The group already exists. |
| **NERR_UserExists** | The user account already exists. |
| **NERR_PasswordTooShort** | The password is shorter than required. (The password could also be too long, be too recent in its change history, not have enough unique characters, or not meet another password policy requirement.) |

## Remarks

If you are programming for Active Directory, you may be able to call certain Active Directory Service Interface (ADSI) methods to achieve the same functionality you can achieve by calling the network management user functions. For more information, see
[IADsUser](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsuser) and
[IADsComputer](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadscomputer).

If you call this function on a domain controller that is running Active Directory, access is allowed or denied based on the access control list (ACL) for the [securable object](https://learn.microsoft.com/windows/desktop/SecAuthZ/securable-objects). The default ACL permits only Domain Admins and Account Operators to call this function. On a member server or workstation, only Administrators and Power Users can call this function. For more information, see
[Security Requirements for the Network Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/security-requirements-for-the-network-management-functions). For more information on ACLs, ACEs, and access tokens, see
[Access Control Model](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control-model).

The security descriptor of the user container is used to perform the access check for this function. The caller must be able to create child objects of the user class.

Server users must use a system in which the server creates a system account for the new user. The creation of this account is controlled by several parameters in the server's LanMan.ini file.

If the newly added user already exists as a system user, the **usri1_home_dir** member of the
[USER_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_1) structure is ignored.

When you call the
**NetUserAdd** function and specify information level 1, the call initializes the additional members in the
[USER_INFO_2](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_2),
[USER_INFO_3](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_3), and
[USER_INFO_4](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_4) structures to their default values. You can change the default values by making subsequent calls to the
[NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo) function. The default values supplied are listed following. (The prefix usriX indicates that the member can begin with multiple prefixes, for example, usri2_ or usri4_.)

| Member | Default Value |
| --- | --- |
| usriX_auth_flags | None (0) |
| usriX_full_name | None (null string) |
| usriX_usr_comment | None (null string) |
| usriX_parms | None (null string) |
| usriX_workstations | All (null string) |
| usriX_acct_expires | Never (TIMEQ_FOREVER) |
| usriX_max_storage | Unlimited (USER_MAXSTORAGE_UNLIMITED) |
| usriX_logon_hours | Logon allowed at any time (each element 0xFF; all bits set to 1) |
| usriX_logon_server | Any domain controller (\\*) |
| usriX_country_code | 0 |
| usriX_code_page | 0 |

User account names are limited to 20 characters and group names are limited to 256 characters. In addition, account names cannot be terminated by a period and they cannot include commas or any of the following printable characters: ", /, \, [, ], :, |, <, >, +, =, ;, ?, *. Names also cannot include characters in the range 1-31, which are nonprintable.

#### Examples

The following code sample demonstrates how to add a user account and assign a privilege level using a call to the
**NetUserAdd** function. The code sample fills in the members of the
[USER_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_1) structure and calls
**NetUserAdd**, specifying information level 1.

```cpp
#ifndef UNICODE
#define UNICODE
#endif
#pragma comment(lib, "netapi32.lib")

#include <stdio.h>
#include <windows.h>
#include <lm.h>

int wmain(int argc, wchar_t *argv[])
{
   USER_INFO_1 ui;
   DWORD dwLevel = 1;
   DWORD dwError = 0;
   NET_API_STATUS nStatus;

   if (argc != 3)
   {
      fwprintf(stderr, L"Usage: %s \\\\ServerName UserName\n", argv[0]);
      exit(1);
   }
   //
   // Set up the USER_INFO_1 structure.
   //  USER_PRIV_USER: name identifies a user,
   //    rather than an administrator or a guest.
   //  UF_SCRIPT: required
   //
   ui.usri1_name = argv[2];
   ui.usri1_password = argv[2];
   ui.usri1_priv = USER_PRIV_USER;
   ui.usri1_home_dir = NULL;
   ui.usri1_comment = NULL;
   ui.usri1_flags = UF_SCRIPT;
   ui.usri1_script_path = NULL;
   //
   // Call the NetUserAdd function, specifying level 1.
   //
   nStatus = NetUserAdd(argv[1],
                        dwLevel,
                        (LPBYTE)&ui,
                        &dwError);
   //
   // If the call succeeds, inform the user.
   //
   if (nStatus == NERR_Success)
      fwprintf(stderr, L"User %s has been successfully added on %s\n",
               argv[2], argv[1]);
   //
   // Otherwise, print the system error.
   //
   else
      fprintf(stderr, "A system error has occurred: %d\n", nStatus);

   return 0;
}

```

## See also

[NetUserDel](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netuserdel)

[NetUserEnum](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netuserenum)

[NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[USER_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_1)

[USER_INFO_2](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_2)

[USER_INFO_4](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_4)

[User Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/user-functions)