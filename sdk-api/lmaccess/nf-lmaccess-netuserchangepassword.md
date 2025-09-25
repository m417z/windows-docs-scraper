# NetUserChangePassword function

## Description

The
**NetUserChangePassword** function changes a user's password for a specified network server or domain.

## Parameters

### `domainname` [in]

A pointer to a constant string that specifies the DNS or NetBIOS name of a remote server or domain on which the function is to execute. If this parameter is **NULL**, the logon domain of the caller is used.

### `username` [in]

A pointer to a constant string that specifies a user name. The
**NetUserChangePassword** function changes the password for the specified user.

If this parameter is **NULL**, the logon name of the caller is used. For more information, see the following Remarks section.

### `oldpassword` [in]

A pointer to a constant string that specifies the user's old password.

### `newpassword` [in]

A pointer to a constant string that specifies the user's new password.

## Return value

If the function succeeds, the return value is NERR_Success.

If the function fails, the return value can be one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The user does not have access to the requested information. |
| **ERROR_INVALID_PASSWORD** | The user has entered an invalid password. |
| **NERR_InvalidComputer** | The computer name is invalid. |
| **NERR_NotPrimary** | The operation is allowed only on the primary domain controller of the domain. |
| **NERR_UserNotFound** | The user name could not be found. |
| **NERR_PasswordTooShort** | The password is shorter than required. (The password could also be too long, be too recent in its change history, not have enough unique characters, or not meet another password policy requirement.) |

## Remarks

If you are programming for Active Directory, you may be able to call certain Active Directory Service Interface (ADSI) methods to achieve the same result you can achieve by calling the network management user functions. For more information, see
[IADsUser](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsuser) and
[IADsComputer](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadscomputer).

If an application calls the **NetUserChangePassword** function on a domain controller that is running Active Directory, access is allowed or denied based on the access control list (ACL) for the [securable object](https://learn.microsoft.com/windows/desktop/SecAuthZ/securable-objects). The default ACL permits only Domain Admins and Account Operators to call this function. On a member server or workstation, only Administrators and Power Users can call this function. A user can change his or her own password. For more information, see
[Security Requirements for the Network Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/security-requirements-for-the-network-management-functions). For more information on ACLs, ACEs, and access tokens, see
[Access Control Model](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control-model).

The security descriptor of the User object is used to perform the access check for this function. In addition, the caller must have the "Change password" [control access right](https://learn.microsoft.com/windows/desktop/AD/control-access-rights) on the User object. This right is granted to Anonymous Logon and Everyone by default.

Note that for the function to succeed, the *oldpassword* parameter must match the password as it currently exists.

In some cases, the process that calls the
**NetUserChangePassword** function must also have the SE_CHANGE_NOTIFY_NAME privilege enabled; otherwise,
**NetUserChangePassword** fails and
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns ERROR_ACCESS_DENIED. This privilege is not required for the
[LocalSystem account](https://learn.microsoft.com/windows/desktop/Services/localsystem-account) or for accounts that are members of the administrators group. By default, SE_CHANGE_NOTIFY_NAME is enabled for all users, but some administrators may disable the privilege for everyone. For more information about account privileges, see
[Privileges](https://learn.microsoft.com/windows/desktop/SecAuthZ/privileges) and
[Authorization Constants](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-constants).

See
[Forcing a User to Change the Logon Password](https://learn.microsoft.com/windows/desktop/NetMgmt/forcing-a-user-to-change-the-logon-password) for a code sample that demonstrates how to force a user to change the logon password on the next logon using the
[NetUserGetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusergetinfo) and
[NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo) functions.

User account names are limited to 20 characters and group names are limited to 256 characters. In addition, account names cannot be terminated by a period and they cannot include commas or any of the following printable characters: ", /, \, [, ], :, |, <, >, +, =, ;, ?, *. Names also cannot include characters in the range 1-31, which are nonprintable.

The
**NetUserChangePassword** function does not control how the *oldpassword* and *newpassword* parameters are secured when sent over the network to a remote server. Any encryption of these parameters is handled by the Remote Procedure Call (RPC) mechanism supported by the network redirector that provides the network transport. Encryption is also controlled by the security mechanisms supported by the local computer and the security mechanisms supported by remote network server or domain specified in the *domainname* parameter. For more details on security when the Microsoft network redirector is used and the remote network server is running Microsoft Windows, see the protocol documentation for [MS-RPCE](https://learn.microsoft.com/openspecs/windows_protocols/ms-rpce/290c38b1-92fe-4229-91e6-4fc376610c15), [MS-SAMR](https://learn.microsoft.com/openspecs/windows_protocols/ms-samr/4df07fab-1bbc-452f-8e92-7853a3c7e380), [MS-SPNG](https://learn.microsoft.com/openspecs/windows_protocols/ms-spng/f377a379-c24f-4a0f-a3eb-0d835389e28a), and [MS-NLMP](https://learn.microsoft.com/openspecs/windows_protocols/ms-nlmp/b38c36ed-2804-4868-a9ff-8dd3182128e4).

#### Examples

The following code sample demonstrates how to change a user's password with a call to the **NetUserChangePassword** function. All parameters to the function are required.

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
   DWORD dwError = 0;
   NET_API_STATUS nStatus;
   //
   // All parameters are required.
   //
   if (argc != 5)
   {
      fwprintf(stderr, L"Usage: %s \\\\ServerName UserName OldPassword NewPassword\n", argv[0]);
      exit(1);
   }
   //
   // Call the NetUserChangePassword function.
   //
   nStatus = NetUserChangePassword(argv[1], argv[2], argv[3], argv[4]);
   //
   // If the call succeeds, inform the user.
   //
   if (nStatus == NERR_Success)
      fwprintf(stderr, L"User password has been changed successfully\n");
   //
   // Otherwise, print the system error.
   //
   else
      fprintf(stderr, "A system error has occurred: %d\n", nStatus);

   return 0;
}

```

## See also

[NetUserGetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusergetinfo)

[NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[User Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/user-functions)