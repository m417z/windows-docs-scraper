# NetUserModalsGet function

## Description

The
**NetUserModalsGet** function retrieves global information for all users and global groups in the security database, which is the security accounts manager (SAM) database or, in the case of domain controllers, the Active Directory.

## Parameters

### `servername` [in, optional]

A pointer to a constant string that specifies the DNS or NetBIOS name of the remote server on which the function is to execute. If this parameter is **NULL**, the local computer is used. For more information, see the following Remarks section.

### `level` [in]

The information level of the data requested. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **0** | Return global password parameters. The *bufptr* parameter points to a [USER_MODALS_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_modals_info_0) structure. |
| **1** | Return logon server and domain controller information. The *bufptr* parameter points to a [USER_MODALS_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_modals_info_1) structure. |
| **2** | Return domain name and identifier. The *bufptr* parameter points to a [USER_MODALS_INFO_2](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_modals_info_2) structure. For more information, see the following Remarks section. |
| **3** | Return lockout information. The *bufptr* parameter points to a [USER_MODALS_INFO_3](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_modals_info_3) structure. |

A null session logon can call
**NetUserModalsGet** anonymously at information levels 0 and 3.

### `bufptr` [out]

A pointer to the buffer that receives the data. The format of this data depends on the value of the *level* parameter.

The buffer for this data is allocated by the system and the application must call the [NetApiBufferFree](https://learn.microsoft.com/windows/desktop/api/lmapibuf/nf-lmapibuf-netapibufferfree) function to free the allocated memory when the data returned is no longer needed. For more information, see
[Network Management Function Buffers](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffers) and
[Network Management Function Buffer Lengths](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffer-lengths).

## Return value

If the function succeeds, the return value is NERR_Success.

If the function fails, the return value can be one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The user does not have access to the requested information. |
| **ERROR_BAD_NETPATH** | The network path was not found. This error is returned if the *servername* parameter could not be found. |
| **ERROR_INVALID_LEVEL** | The system call level is not correct. This error is returned if the *level*  parameter is not one of the supported values. |
| **ERROR_INVALID_NAME** | The file name, directory name, or volume label syntax is incorrect. This error is returned if the *servername* parameter syntax is incorrect. |
| **ERROR_WRONG_TARGET_NAME** | The target account name is incorrect. This error is returned for a logon failure to a remote *servername* parameter running on Windows Vista. |
| **NERR_InvalidComputer** | The computer name is invalid. |

## Remarks

If you are programming for Active Directory, you may be able to call certain Active Directory Service Interface (ADSI) methods to achieve the same functionality you can achieve by calling the network management user modal functions. For more information, see
[IADsDomain](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsdomain).

If you call this function on a domain controller that is running Active Directory, access is allowed or denied based on the access control list (ACL) for the [securable object](https://learn.microsoft.com/windows/desktop/SecAuthZ/securable-objects). The default ACL permits all authenticated users and members of the "[Pre-Windows 2000 compatible access](https://learn.microsoft.com/windows/desktop/SecAuthZ/allowing-anonymous-access)" group to view the information. If you call this function on a member server or workstation, all authenticated users can view the information. For information about anonymous access and restricting anonymous access on these platforms, see
[Security Requirements for the Network Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/security-requirements-for-the-network-management-functions). For more information on ACLs, ACEs, and access tokens, see
[Access Control Model](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control-model).

The security descriptor of the Domain object is used to perform the access check for this function.

To retrieve the
[security identifier](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-identifiers) (SID) of the domain to which the computer belongs, call the
**NetUserModalsGet** function specifying a
[USER_MODALS_INFO_2](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_modals_info_2) structure and **NULL** in the *servername* parameter. If the computer isn't a member of a domain, the function returns a **NULL** pointer.

#### Examples

The following code sample demonstrates how to retrieve global information for all users and global groups with a call to the
**NetUserModalsGet** function. The sample calls
**NetUserModalsGet**, specifying information level 0 ([USER_MODALS_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_modals_info_0)). If the call succeeds, the sample prints global password information. Finally, the code sample frees the memory allocated for the information buffer.

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
   USER_MODALS_INFO_0 *pBuf = NULL;
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
   // Call the NetUserModalsGet function; specify level 0.
   //
   nStatus = NetUserModalsGet((LPCWSTR) pszServerName,
                              dwLevel,
                              (LPBYTE *)&pBuf);
   //
   // If the call succeeds, print the global information.
   //
   if (nStatus == NERR_Success)
   {
      if (pBuf != NULL)
      {
         printf("\tMinimum password length:  %d\n", pBuf->usrmod0_min_passwd_len);
         printf("\tMaximum password age (d): %d\n", pBuf->usrmod0_max_passwd_age/86400);
         printf("\tMinimum password age (d): %d\n", pBuf->usrmod0_min_passwd_age/86400);
         printf("\tForced log off time (s):  %d\n", pBuf->usrmod0_force_logoff);
         printf("\tPassword history length:  %d\n", pBuf->usrmod0_password_hist_len);
      }
   }
   // Otherwise, print the system error.
   //
   else
      fprintf(stderr, "A system error has occurred: %d\n", nStatus);
   //
   // Free the allocated memory.
   //
   if (pBuf != NULL)
      NetApiBufferFree(pBuf);

   return 0;
}

```

## See also

[NetUserModalsSet](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusermodalsset)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[USER_MODALS_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_modals_info_0)

[USER_MODALS_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_modals_info_1)

[USER_MODALS_INFO_2](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_modals_info_2)

[USER_MODALS_INFO_3](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_modals_info_3)

[User Modals
Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/user-modal-functions)