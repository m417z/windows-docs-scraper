# NetUserEnum function

## Description

The
**NetUserEnum** function retrieves information about all user accounts on a server.

## Parameters

### `servername` [in]

A pointer to a constant string that specifies the DNS or NetBIOS name of the remote server on which the function is to execute. If this parameter is **NULL**, the local computer is used.

### `level` [in]

Specifies the information level of the data. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **0** | Return user account names. The *bufptr* parameter points to an array of [USER_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_0) structures. |
| **1** | Return detailed information about user accounts. The *bufptr* parameter points to an array of [USER_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_1) structures. |
| **2** | Return detailed information about user accounts, including authorization levels and logon information. The *bufptr* parameter points to an array of [USER_INFO_2](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_2) structures. |
| **3** | Return detailed information about user accounts, including authorization levels, logon information, RIDs for the user and the primary group, and profile information. The *bufptr* parameter points to an array of [USER_INFO_3](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_3) structures. |
| **10** | Return user and account names and comments. The *bufptr* parameter points to an array of [USER_INFO_10](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_10) structures. |
| **11** | Return detailed information about user accounts. The *bufptr* parameter points to an array of [USER_INFO_11](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_11) structures. |
| **20** | Return the user's name and identifier and various account attributes. The *bufptr* parameter points to an array of [USER_INFO_20](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_20) structures. Note that on Windows XP and later, it is recommended that you use [USER_INFO_23](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_23) instead. |

### `filter` [in]

A value that specifies the user account types to be included in the enumeration. A value of zero indicates that all normal user, trust data, and machine account data should be included.

This parameter can also be a combination of the following values.

| Value | Meaning |
| --- | --- |
| **FILTER_TEMP_DUPLICATE_ACCOUNT** | Enumerates account data for users whose primary account is in another domain. This account type provides user access to this domain, but not to any domain that trusts this domain. The User Manager refers to this account type as a local user account. |
| **FILTER_NORMAL_ACCOUNT** | Enumerates normal user account data. This account type is associated with a typical user. |
| **FILTER_INTERDOMAIN_TRUST_ACCOUNT** | Enumerates interdomain trust account data. This account type is associated with a trust account for a domain that trusts other domains. |
| **FILTER_WORKSTATION_TRUST_ACCOUNT** | Enumerates workstation or member server trust account data. This account type is associated with a machine account for a computer that is a member of the domain. |
| **FILTER_SERVER_TRUST_ACCOUNT** | Enumerates member server machine account data. This account type is associated with a computer account for a backup domain controller that is a member of the domain. |

### `bufptr` [out]

A pointer to the buffer that receives the data. The format of this data depends on the value of the *level* parameter.

The buffer for this data is allocated by the system and the application must call the [NetApiBufferFree](https://learn.microsoft.com/windows/desktop/api/lmapibuf/nf-lmapibuf-netapibufferfree) function to free the allocated memory when the data returned is no longer needed. Note that you must free the buffer even if the **NetUserEnum** function fails with ERROR_MORE_DATA.

### `prefmaxlen` [in]

The preferred maximum length, in bytes, of the returned data. If you specify MAX_PREFERRED_LENGTH, the **NetUserEnum** function allocates the amount of memory required for the data. If you specify another value in this parameter, it can restrict the number of bytes that the function returns. If the buffer size is insufficient to hold all entries, the function returns ERROR_MORE_DATA. For more information, see
[Network Management Function Buffers](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffers) and
[Network Management Function Buffer Lengths](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffer-lengths).

### `entriesread` [out]

A pointer to a value that receives the count of elements actually enumerated.

### `totalentries` [out]

A pointer to a value that receives the total number of entries that could have been enumerated from the current resume position. Note that applications should consider this value only as a hint. If your application is communicating with a Windows 2000 or later domain controller, you should consider using the
[ADSI LDAP Provider](https://learn.microsoft.com/windows/desktop/ADSI/adsi-ldap-provider) to retrieve this type of data more efficiently. The ADSI LDAP Provider implements a set of ADSI objects that support various ADSI interfaces. For more information, see
[ADSI Service Providers](https://learn.microsoft.com/windows/desktop/ADSI/adsi-system-providers).

**LAN Manager:** If the call is to a computer that is running LAN Manager 2.*x*, the *totalentries* parameter will always reflect the total number of entries in the database no matter where it is in the resume sequence.

### `resume_handle` [in, out]

A pointer to a value that contains a resume handle which is used to continue an existing user search. The handle should be zero on the first call and left unchanged for subsequent calls. If this parameter is **NULL**, then no resume handle is stored.

## Return value

If the function succeeds, the return value is NERR_Success.

If the function fails, the return value can be one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The user does not have access to the requested information. |
| **ERROR_INVALID_LEVEL** | The system call level is not correct. This error is returned if the *level* parameter is set to a value not supported. |
| **NERR_BufTooSmall** | The buffer is too small to contain an entry. No information has been written to the buffer. |
| **NERR_InvalidComputer** | The computer name is invalid. |
| **ERROR_MORE_DATA** | More entries are available. Specify a large enough buffer to receive all entries. |

## Remarks

The
**NetUserEnum** function retrieves information about all user accounts on a specified remote server or the local computer.

The
[NetQueryDisplayInformation](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netquerydisplayinformation) function can be used to quickly enumerate user, computer, or global group account information for display in user interfaces .

If you are programming for Active Directory, you may be able to call certain Active Directory Service Interface (ADSI) methods to achieve the same functionality you can achieve by calling the network management user functions. For more information, see
[IADsUser](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsuser) and
[IADsComputer](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadscomputer).

If you call the **NetUserEnum** function on a domain controller that is running Active Directory, access is allowed or denied based on the access control list (ACL) for the [securable object](https://learn.microsoft.com/windows/desktop/SecAuthZ/securable-objects). The default ACL permits all authenticated users and members of the "[Pre-Windows 2000 compatible access](https://learn.microsoft.com/windows/desktop/SecAuthZ/allowing-anonymous-access)" group to view the information. If you call this function on a member server or workstation, all authenticated users can view the information. For information about anonymous access and restricting anonymous access on these platforms, see
[Security Requirements for the Network Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/security-requirements-for-the-network-management-functions). For more information on ACLs, ACEs, and access tokens, see
[Access Control Model](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control-model).

The **NetUserEnum** function only returns information to which the caller has Read access. The caller must have List Contents access to the Domain object, and Enumerate Entire SAM Domain access on the SAM Server object located in the System container.

The [LsaEnumerateTrustedDomains](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaenumeratetrusteddomains) or [LsaEnumerateTrustedDomainsEx](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaenumeratetrusteddomainsex) function can be used to retrieve the names and SIDs of domains trusted by a Local Security Authority (LSA) policy object.

The
**NetUserEnum** function does not return all system users. It returns only those users who have been added with a call to the
[NetUserAdd](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netuseradd) function. There is no guarantee that the list of users will be returned in sorted order.

If you call
the **NetUserEnum** function and specify information level 1, 2, or 3, for the *level* parameter, the password member of each structure retrieved is set to **NULL** to maintain password security.

User account names are limited to 20 characters and group names are limited to 256 characters. In addition, account names cannot be terminated by a period and they cannot include commas or any of the following printable characters: ", /, \, [, ], :, |, <, >, +, =, ;, ?, *. Names also cannot include characters in the range 1-31, which are nonprintable.

The **NetUserEnum** function does not support a *level* parameter of 4 and the [USER_INFO_4](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_4) structure. The [NetUserGetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusergetinfo)
function supports a *level* parameter of 4 and the **USER_INFO_4** structure.

#### Examples

The following code sample demonstrates how to retrieve information about the user accounts on a server with a call to the
**NetUserEnum** function. The sample calls
**NetUserEnum**, specifying information level 0 ([USER_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_0)) to enumerate only global user accounts. If the call succeeds, the code loops through the entries and prints the name of each user account. Finally, the code sample frees the memory allocated for the information buffer and prints a total of the users enumerated.

```cpp
#ifndef UNICODE
#define UNICODE
#endif
#pragma comment(lib, "netapi32.lib")

#include <stdio.h>
#include <assert.h>
#include <windows.h>
#include <lm.h>

int wmain(int argc, wchar_t *argv[])
{
   LPUSER_INFO_0 pBuf = NULL;
   LPUSER_INFO_0 pTmpBuf;
   DWORD dwLevel = 0;
   DWORD dwPrefMaxLen = MAX_PREFERRED_LENGTH;
   DWORD dwEntriesRead = 0;
   DWORD dwTotalEntries = 0;
   DWORD dwResumeHandle = 0;
   DWORD i;
   DWORD dwTotalCount = 0;
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
      pszServerName =  (LPTSTR) argv[1];
   wprintf(L"\nUser account on %s: \n", pszServerName);
   //
   // Call the NetUserEnum function, specifying level 0;
   //   enumerate global user account types only.
   //
   do // begin do
   {
      nStatus = NetUserEnum((LPCWSTR) pszServerName,
                            dwLevel,
                            FILTER_NORMAL_ACCOUNT, // global users
                            (LPBYTE*)&pBuf,
                            dwPrefMaxLen,
                            &dwEntriesRead,
                            &dwTotalEntries,
                            &dwResumeHandle);
      //
      // If the call succeeds,
      //
      if ((nStatus == NERR_Success) || (nStatus == ERROR_MORE_DATA))
      {
         if ((pTmpBuf = pBuf) != NULL)
         {
            //
            // Loop through the entries.
            //
            for (i = 0; (i < dwEntriesRead); i++)
            {
               assert(pTmpBuf != NULL);

               if (pTmpBuf == NULL)
               {
                  fprintf(stderr, "An access violation has occurred\n");
                  break;
               }
               //
               //  Print the name of the user account.
               //
               wprintf(L"\t-- %s\n", pTmpBuf->usri0_name);

               pTmpBuf++;
               dwTotalCount++;
            }
         }
      }
      //
      // Otherwise, print the system error.
      //
      else
         fprintf(stderr, "A system error has occurred: %d\n", nStatus);
      //
      // Free the allocated buffer.
      //
      if (pBuf != NULL)
      {
         NetApiBufferFree(pBuf);
         pBuf = NULL;
      }
   }
   // Continue to call NetUserEnum while
   //  there are more entries.
   //
   while (nStatus == ERROR_MORE_DATA); // end do
   //
   // Check again for allocated memory.
   //
   if (pBuf != NULL)
      NetApiBufferFree(pBuf);
   //
   // Print the final count of users enumerated.
   //
   fprintf(stderr, "\nTotal of %d entries enumerated\n", dwTotalCount);

   return 0;
}

```

## See also

[LsaEnumerateTrustedDomains](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaenumeratetrusteddomains)

[LsaEnumerateTrustedDomainsEx](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaenumeratetrusteddomainsex)

[NetQueryDisplayInformation](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netquerydisplayinformation)

[NetUserAdd](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netuseradd)

[NetUserGetGroups](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusergetgroups)

[NetUserGetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusergetinfo)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[USER_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_0)

[USER_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_1)

[USER_INFO_10](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_10)

[USER_INFO_11](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_11)

[USER_INFO_2](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_2)

[USER_INFO_20](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_20)

[USER_INFO_23](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_23)

[USER_INFO_3](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_3)

[User Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/user-functions)