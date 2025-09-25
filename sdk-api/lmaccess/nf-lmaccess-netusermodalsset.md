# NetUserModalsSet function

## Description

The
**NetUserModalsSet** function sets global information for all users and global groups in the security database, which is the security accounts manager (SAM) database or, in the case of domain controllers, the Active Directory.

## Parameters

### `servername` [in]

Pointer to a constant string that specifies the DNS or NetBIOS name of the remote server on which the function is to execute. If this parameter is **NULL**, the local computer is used.

### `level` [in]

Specifies the information level of the data. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **0** | Specifies global password parameters. The *buf* parameter points to a [USER_MODALS_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_modals_info_0) structure. |
| **1** | Specifies logon server and domain controller information. The *buf* parameter points to a [USER_MODALS_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_modals_info_1) structure. |
| **2** | Specifies the domain name and identifier. The *buf* parameter points to a [USER_MODALS_INFO_2](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_modals_info_2) structure. |
| **3** | Specifies lockout information. The *buf* parameter points to a [USER_MODALS_INFO_3](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_modals_info_3) structure. |
| **1001** | Specifies the minimum allowable password length. The *buf* parameter points to a [USER_MODALS_INFO_1001](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_modals_info_1001) structure. |
| **1002** | Specifies the maximum allowable password age. The *buf* parameter points to a [USER_MODALS_INFO_1002](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_modals_info_1002) structure. |
| **1003** | Specifies the minimum allowable password age. The *buf* parameter points to a [USER_MODALS_INFO_1003](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_modals_info_1003) structure. |
| **1004** | Specifies forced logoff information. The *buf* parameter points to a [USER_MODALS_INFO_1004](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_modals_info_1004) structure. |
| **1005** | Specifies the length of the password history. The *buf* parameter points to a [USER_MODALS_INFO_1005](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_modals_info_1005) structure. |
| **1006** | Specifies the role of the logon server. The *buf* parameter points to a [USER_MODALS_INFO_1006](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_modals_info_1006) structure. |
| **1007** | Specifies domain controller information. The *buf* parameter points to a [USER_MODALS_INFO_1007](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_modals_info_1007) structure. |

### `buf` [in]

Pointer to the buffer that specifies the data. The format of this data depends on the value of the *level* parameter. For more information, see
[Network Management Function Buffers](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffers).

### `parm_err` [out]

Pointer to a value that receives the index of the first member of the information structure that causes ERROR_INVALID_PARAMETER. If this parameter is **NULL**, the index is not returned on error. For more information, see the following Remarks section.

## Return value

If the function succeeds, the return value is NERR_Success.

If the function fails, the return value can be one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The user does not have access to the requested information. |
| **ERROR_INVALID_PARAMETER** | The specified parameter is invalid. For more information, see the following Remarks section. |
| **NERR_InvalidComputer** | The computer name is invalid. |
| **NERR_UserNotFound** | The user name could not be found. |

## Remarks

If you are programming for Active Directory, you may be able to call certain Active Directory Service Interface (ADSI) methods to achieve the same functionality you can achieve by calling the network management user modal functions. For more information, see
[IADsDomain](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsdomain).

If you call this function on a domain controller that is running Active Directory, access is allowed or denied based on the access control list (ACL) for the [securable object](https://learn.microsoft.com/windows/desktop/SecAuthZ/securable-objects). The default ACL permits only Domain Admins and Account Operators to call this function. On a member server or workstation, only Administrators and Power Users can call this function. For more information, see
[Security Requirements for the Network Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/security-requirements-for-the-network-management-functions). For more information on ACLs, ACEs, and access tokens, see
[Access Control Model](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control-model).

The security descriptor of the Domain object is used to perform the access check for this function. Typically, callers must have write access to the entire object for calls to this function to succeed.

If the
**NetUserModalsSet** function returns ERROR_INVALID_PARAMETER, you can use the *parm_err* parameter to indicate the first member of the information structure that is invalid. (The information structure begins with USER_MODALS_INFO_ and its format is specified by the *level* parameter.) The following table lists the values that can be returned in the *parm_err* parameter and the corresponding structure member that is in error. (The prefix usrmod*_ indicates that the member can begin with multiple prefixes, for example, usrmod2_ or usrmod1002_.)

| Value | Member |
| --- | --- |
| MODALS_MIN_PASSWD_LEN_PARMNUM | usrmod*_min_passwd_len |
| MODALS_MAX_PASSWD_AGE_PARMNUM | usrmod*_max_passwd_age |
| MODALS_MIN_PASSWD_AGE_PARMNUM | usrmod*_min_passwd_age |
| MODALS_FORCE_LOGOFF_PARMNUM | usrmod*_force_logoff |
| MODALS_PASSWD_HIST_LEN_PARMNUM | usrmod*_password_hist_len |
| MODALS_ROLE_PARMNUM | usrmod*_role |
| MODALS_PRIMARY_PARMNUM | usrmod*_primary |
| MODALS_DOMAIN_NAME_PARMNUM | usrmod*_domain_name |
| MODALS_DOMAIN_ID_PARMNUM | usrmod*_domain_id |
| MODALS_LOCKOUT_DURATION_PARMNUM | usrmod*_lockout_duration |
| MODALS_LOCKOUT_OBSERVATION_WINDOW_PARMNUM | usrmod*_lockout_observation_window |
| MODALS_LOCKOUT_THRESHOLD_PARMNUM | usrmod*_lockout_threshold |

#### Examples

The following code sample demonstrates how to set the global information for all users and global groups with a call to the
**NetUserModalsSet** function. The sample fills in the members of the
[USER_MODALS_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_modals_info_0) structure and calls
**NetUserModalsSet**, specifying information level 0.

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
   DWORD dwLevel = 0;
   USER_MODALS_INFO_0 ui;
   NET_API_STATUS nStatus;
   LPTSTR pszServerName = NULL;

   if (argc > 2)
   {
      fwprintf(stderr, L"Usage: %s [\\\\ServerName]\n", argv[0]);
      exit(1);
   }
   // The server is not the default local computer.
   //
   if (argc == 2)
      pszServerName = (LPTSTR) argv[1];
   //
   // Fill in the USER_MODALS_INFO_0 structure.
   //
   ui.usrmod0_min_passwd_len = 0;
   ui.usrmod0_max_passwd_age = (86400 * 30);
   ui.usrmod0_min_passwd_age = 0;
   ui.usrmod0_force_logoff = TIMEQ_FOREVER; // never force logoff
   ui.usrmod0_password_hist_len = 0;
   //
   // Call the NetUserModalsSet function; specify level 0.
   //
   nStatus = NetUserModalsSet((LPCWSTR) pszServerName,
                              dwLevel,
                              (LPBYTE)&ui,
                              NULL);
   //
   // If the call succeeds, inform the user.
   //
   if (nStatus == NERR_Success)
      fwprintf(stderr, L"Modals information set successfully on %s\n", argv[1]);
   //
   // Otherwise, print the system error.
   //
   else
      fprintf(stderr, "A system error has occurred: %d\n", nStatus);

   return 0;
}

```

## See also

[NetUserModalsGet](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusermodalsget)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[USER_MODALS_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_modals_info_0)

[USER_MODALS_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_modals_info_1)

[USER_MODALS_INFO_1001](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_modals_info_1001)

[USER_MODALS_INFO_1002](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_modals_info_1002)

[USER_MODALS_INFO_1003](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_modals_info_1003)

[USER_MODALS_INFO_1004](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_modals_info_1004)

[USER_MODALS_INFO_1005](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_modals_info_1005)

[USER_MODALS_INFO_1006](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_modals_info_1006)

[USER_MODALS_INFO_1007](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_modals_info_1007)

[USER_MODALS_INFO_2](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_modals_info_2)

[USER_MODALS_INFO_3](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_modals_info_3)

[User Modals
Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/user-modal-functions)