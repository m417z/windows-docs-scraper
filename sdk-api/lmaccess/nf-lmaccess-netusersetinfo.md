# NetUserSetInfo function

## Description

The
**NetUserSetInfo** function sets the parameters of a user account.

## Parameters

### `servername` [in]

A pointer to a constant string that specifies the DNS or NetBIOS name of the remote server on which the function is to execute. If this parameter is **NULL**, the local computer is used.

### `username` [in]

A pointer to a constant string that specifies the name of the user account for which to set information. For more information, see the following Remarks section.

### `level` [in]

The information level of the data. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **0** | Specifies the user account name. The *buf* parameter points to a [USER_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_0) structure. Use this structure to specify a new group name. For more information, see the following Remarks section. |
| **1** | Specifies detailed information about the user account. The *buf* parameter points to a [USER_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_1) structure. |
| **2** | Specifies level one information and additional attributes about the user account. The *buf* parameter points to a [USER_INFO_2](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_2) structure. |
| **3** | Specifies level two information and additional attributes about the user account. This level is valid only on servers. The *buf* parameter points to a [USER_INFO_3](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_3) structure. Note that it is recommended that you use [USER_INFO_4](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_4) instead. |
| **4** | Specifies level two information and additional attributes about the user account. This level is valid only on servers. The *buf* parameter points to a [USER_INFO_4](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_4) structure. |
| **21** | Specifies a one-way encrypted LAN Manager 2.*x*-compatible password. The *buf* parameter points to a [USER_INFO_21](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_21) structure. |
| **22** | Specifies detailed information about the user account. The *buf* parameter points to a [USER_INFO_22](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_22) structure. |
| **1003** | Specifies a user password. The *buf* parameter points to a [USER_INFO_1003](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_1003) structure. |
| **1005** | Specifies a user privilege level. The *buf* parameter points to a [USER_INFO_1005](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_1005) structure. |
| **1006** | Specifies the path of the home directory for the user. The *buf* parameter points to a [USER_INFO_1006](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_1006) structure. |
| **1007** | Specifies a comment to associate with the user account. The *buf* parameter points to a [USER_INFO_1007](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_1007) structure. |
| **1008** | Specifies user account attributes. The *buf* parameter points to a [USER_INFO_1008](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_1008) structure. |
| **1009** | Specifies the path for the user's logon script file. The *buf* parameter points to a [USER_INFO_1009](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_1009) structure. |
| **1010** | Specifies the user's operator privileges. The *buf* parameter points to a [USER_INFO_1010](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_1010) structure. |
| **1011** | Specifies the full name of the user. The *buf* parameter points to a [USER_INFO_1011](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_1011) structure. |
| **1012** | Specifies a comment to associate with the user. The *buf* parameter points to a [USER_INFO_1012](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_1012) structure. |
| **1014** | Specifies the names of workstations from which the user can log on. The *buf* parameter points to a [USER_INFO_1014](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_1014) structure. |
| **1017** | Specifies when the user account expires. The *buf* parameter points to a [USER_INFO_1017](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_1017) structure. |
| **1020** | Specifies the times during which the user can log on. The *buf* parameter points to a [USER_INFO_1020](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_1020) structure. |
| **1024** | Specifies the user's country/region code. The *buf* parameter points to a [USER_INFO_1024](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_1024) structure. |
| **1051** | Specifies the relative identifier of a global group that represents the enrolled user. The *buf* parameter points to a [USER_INFO_1051](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_1051) structure. |
| **1052** | Specifies the path to a network user's profile. The *buf* parameter points to a [USER_INFO_1052](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_1052) structure. |
| **1053** | Specifies the drive letter assigned to the user's home directory. The *buf* parameter points to a [USER_INFO_1053](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_1053) structure. |

### `buf` [in]

A pointer to the buffer that specifies the data. The format of this data depends on the value of the *level* parameter. For more information, see
[Network Management Function Buffers](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffers).

### `parm_err` [out]

A pointer to a value that receives the index of the first member of the user information structure that causes ERROR_INVALID_PARAMETER. If this parameter is **NULL**, the index is not returned on error. For more information, see the following Remarks section.

## Return value

If the function succeeds, the return value is NERR_Success.

If the function fails, the return value can be one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The user does not have access to the requested information. |
| **ERROR_INVALID_PARAMETER** | One of the function parameters is invalid. For more information, see the following Remarks section. |
| **NERR_InvalidComputer** | The computer name is invalid. |
| **NERR_NotPrimary** | The operation is allowed only on the primary domain controller of the domain. |
| **NERR_SpeGroupOp** | The operation is not allowed on specified special groups, which are user groups, admin groups, local groups, or guest groups. |
| **NERR_LastAdmin** | The operation is not allowed on the last administrative account. |
| **NERR_BadPassword** | The share name or password is invalid. |
| **NERR_PasswordTooShort** | The password is shorter than required. (The password could also be too long, be too recent in its change history, not have enough unique characters, or not meet another password policy requirement.) |
| **NERR_UserNotFound** | The user name could not be found. |

## Remarks

If you are programming for Active Directory, you may be able to call certain Active Directory Service Interface (ADSI) methods to achieve the same functionality you can achieve by calling the network management user functions. For more information, see
[IADsUser](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsuser) and
[IADsComputer](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadscomputer).

If you call this function on a domain controller that is running Active Directory, access is allowed or denied based on the access control list (ACL) for the [securable object](https://learn.microsoft.com/windows/desktop/SecAuthZ/securable-objects). The default ACL permits only Domain Admins and Account Operators to call this function. On a member server or workstation, only Administrators and Power Users can call this function. For more information, see
[Security Requirements for the Network Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/security-requirements-for-the-network-management-functions). For more information on ACLs, ACEs, and access tokens, see
[Access Control Model](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control-model).

The security descriptor of the User object is used to perform the access check for this function.

Only users or applications having administrative privileges can call the
**NetUserSetInfo** function to change a user's password. When an administrator calls
**NetUserSetInfo**, the only restriction applied is that the new password length must be consistent with system modals. A user or application that knows a user's current password can call the
[NetUserChangePassword](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netuserchangepassword) function to change the password. For more information about calling functions that require administrator privileges, see [Running with Special Privileges](https://learn.microsoft.com/windows/desktop/SecBP/running-with-special-privileges).

Members of the Administrators local group can set any modifiable user account elements. All users can set the **usri2_country_code** member of the
[USER_INFO_2](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_2) structure (and the **usri1024_country_code** member of the
[USER_INFO_1024](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_1024) structure) for their own accounts.

A member of the Account Operator's local group cannot set details for an Administrators class account, give an existing account Administrator privilege, or change the operator privilege of any account. If you attempt to change the privilege level or disable the last account with Administrator privilege in the security database, (the security accounts manager (SAM) database or, in the case of domain controllers, the Active Directory), the
**NetUserSetInfo** function fails and returns NERR_LastAdmin.

To set the following user account control flags, the following [privileges](https://learn.microsoft.com/windows/desktop/SecAuthZ/privileges) and [control access rights](https://learn.microsoft.com/windows/desktop/AD/control-access-rights) are required.

| Account control flag | Privilege or right required |
| --- | --- |
| UF_TRUSTED_TO_AUTHENTICATE_FOR_DELEGATION | SeEnableDelegationPrivilege privilege, which is granted to Administrators by default. |
| UF_TRUSTED_FOR_DELEGATION | SeEnableDelegationPrivilege. |
| UF_PASSWD_NOTREQD | "Update password not required" control access right on the Domain object, which is granted to authenticated users by default. |
| UF_DONT_EXPIRE_PASSWD | "Unexpire password" control access right on the Domain object, which is granted to authenticated users by default. |
| UF_ENCRYPTED_TEXT_PASSWORD_ALLOWED | "Enable per user reversibly encrypted password" control access right on the Domain object, which is granted to authenticated users by default. |
| UF_SERVER_TRUST_ACCOUNT | "Add/remove replica in domain" control access right on the Domain object, which is granted to Administrators by default. |

For a list of privilege constants, see [Authorization Constants](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-constants).

The correct way to specify the new name for an account is to call
**NetUserSetInfo** with
[USER_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_0) and to specify the new value using the **usri0_name** member. If you call
**NetUserSetInfo** with other information levels and specify a value using a **usriX_name** member, the value is ignored.

Note that calls to
**NetUserSetInfo** can change the home directory only for user accounts that the network server creates.

If the
**NetUserSetInfo** function returns ERROR_INVALID_PARAMETER, you can use the *parm_err* parameter to indicate the first member of the user information structure that is invalid. (A user information structure begins with USER_INFO_ and its format is specified by the *level* parameter.) The following table lists the values that can be returned in the *parm_err* parameter and the corresponding structure member that is in error. (The prefix usri*_ indicates that the member can begin with multiple prefixes, for example, usri10_ or usri1003_.)

| Value | Member |
| --- | --- |
| USER_NAME_PARMNUM | usri*_name |
| USER_PASSWORD_PARMNUM | usri*_password |
| USER_PASSWORD_AGE_PARMNUM | usri*_password_age |
| USER_PRIV_PARMNUM | usri*_priv |
| USER_HOME_DIR_PARMNUM | usri*_home_dir |
| USER_COMMENT_PARMNUM | usri*_comment |
| USER_FLAGS_PARMNUM | usri*_flags |
| USER_SCRIPT_PATH_PARMNUM | usri*_script_path |
| USER_AUTH_FLAGS_PARMNUM | usri*_auth_flags |
| USER_FULL_NAME_PARMNUM | usri*_full_name |
| USER_USR_COMMENT_PARMNUM | usri*_usr_comment |
| USER_PARMS_PARMNUM | usri*_parms |
| USER_WORKSTATIONS_PARMNUM | usri*_workstations |
| USER_LAST_LOGON_PARMNUM | usri*_last_logon |
| USER_LAST_LOGOFF_PARMNUM | usri*_last_logoff |
| USER_ACCT_EXPIRES_PARMNUM | usri*_acct_expires |
| USER_MAX_STORAGE_PARMNUM | usri*_max_storage |
| USER_UNITS_PER_WEEK_PARMNUM | usri*_units_per_week |
| USER_LOGON_HOURS_PARMNUM | usri*_logon_hours |
| USER_PAD_PW_COUNT_PARMNUM | usri*_bad_pw_count |
| USER_NUM_LOGONS_PARMNUM | usri*_num_logons |
| USER_LOGON_SERVER_PARMNUM | usri*_logon_server |
| USER_COUNTRY_CODE_PARMNUM | usri*_country_code |
| USER_CODE_PAGE_PARMNUM | usri*_code_page |
| USER_PRIMARY_GROUP_PARMNUM | usri*_primary_group_id |
| USER_PROFILE_PARMNUM | usri*_profile |
| USER_HOME_DIR_DRIVE_PARMNUM | usri*_home_dir_drive |

User account names are limited to 20 characters and group names are limited to 256 characters. In addition, account names cannot be terminated by a period and they cannot include commas or any of the following printable characters: ", /, \, [, ], :, |, <, >, +, =, ;, ?, *. Names also cannot include characters in the range 1-31, which are nonprintable.

The
**NetUserSetInfo** function does not control how the password parameters are secured when sent over the network to a remote server to change a user password. Any encryption of these parameters is handled by the Remote Procedure Call (RPC) mechanism supported by the network redirector that provides the network transport. Encryption is also controlled by the security mechanisms supported by the local computer and the security mechanisms supported by remote network server specified in the *servername* parameter. For more details on security when the Microsoft network redirector is used and the remote network server is running Microsoft Windows, see the protocol documentation for [MS-RPCE](https://learn.microsoft.com/openspecs/windows_protocols/ms-rpce/290c38b1-92fe-4229-91e6-4fc376610c15) and [MS-SAMR](https://learn.microsoft.com/openspecs/windows_protocols/ms-samr/4df07fab-1bbc-452f-8e92-7853a3c7e380).

#### Examples

The following code sample demonstrates how to disable a user account with a call to the
**NetUserSetInfo** function. The code sample fills in the **usri1008_flags** member of the
[USER_INFO_1008](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_1008) structure, specifying the value UF_ACCOUNTDISABLE. Then the sample calls
**NetUserSetInfo**, specifying information level 0.

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
   DWORD dwLevel = 1008;
   USER_INFO_1008 ui;
   NET_API_STATUS nStatus;

   if (argc != 3)
   {
      fwprintf(stderr, L"Usage: %s \\\\ServerName UserName\n", argv[0]);
      exit(1);
   }
   // Fill in the USER_INFO_1008 structure member.
   // UF_SCRIPT: required.
   //
   ui.usri1008_flags = UF_SCRIPT | UF_ACCOUNTDISABLE;
   //
   // Call the NetUserSetInfo function
   //  to disable the account, specifying level 1008.
   //
   nStatus = NetUserSetInfo(argv[1],
                            argv[2],
                            dwLevel,
                            (LPBYTE)&ui,
                            NULL);
   //
   // Display the result of the call.
   //
   if (nStatus == NERR_Success)
      fwprintf(stderr, L"User account %s has been disabled\n", argv[2]);
   else
      fprintf(stderr, "A system error has occurred: %d\n", nStatus);

   return 0;
}

```

## See also

[NetUserGetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusergetinfo)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[USER_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_0)

[USER_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_1)

[USER_INFO_1003](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_1003)

[USER_INFO_1005](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_1005)

[USER_INFO_1006](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_1006)

[USER_INFO_1007](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_1007)

[USER_INFO_1008](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_1008)

[USER_INFO_1009](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_1009)

[USER_INFO_1010](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_1010)

[USER_INFO_1011](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_1011)

[USER_INFO_1012](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_1012)

[USER_INFO_1013](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_1013)

[USER_INFO_1014](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_1014)

[USER_INFO_1017](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_1017)

[USER_INFO_1020](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_1020)

[USER_INFO_1024](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_1024)

[USER_INFO_1051](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_1051)

[USER_INFO_1052](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_1052)

[USER_INFO_1053](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_1053)

[USER_INFO_2](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_2)

[USER_INFO_21](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_21)

[USER_INFO_22](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_22)

[USER_INFO_4](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_4)

[User Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/user-functions)