# NetUserGetInfo function

## Description

The
**NetUserGetInfo** function retrieves information about a particular user account on a server.

## Parameters

### `servername` [in]

A pointer to a constant string that specifies the DNS or NetBIOS name of the remote server on which the function is to execute. If this parameter is **NULL**, the local computer is used.

### `username` [in]

A pointer to a constant string that specifies the name of the user account for which to return information. For more information, see the following Remarks section.

### `level` [in]

The information level of the data. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **0** | Return the user account name. The *bufptr* parameter points to a [USER_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_0) structure. |
| **1** | Return detailed information about the user account. The *bufptr* parameter points to a [USER_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_1) structure. |
| **2** | Return detailed information and additional attributes about the user account. The *bufptr* parameter points to a [USER_INFO_2](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_2) structure. |
| **3** | Return detailed information and additional attributes about the user account. This level is valid only on servers. The *bufptr* parameter points to a [USER_INFO_3](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_3) structure. Note that it is recommended that you use [USER_INFO_4](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_4) instead. |
| **4** | Return detailed information and additional attributes about the user account. This level is valid only on servers. The *bufptr* parameter points to a [USER_INFO_4](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_4) structure.<br><br>**Note** This level is supported on Windows XP and later. |
| **10** | Return user and account names and comments. The *bufptr* parameter points to a [USER_INFO_10](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_10) structure. |
| **11** | Return detailed information about the user account. The *bufptr* parameter points to a [USER_INFO_11](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_11) structure. |
| **20** | Return the user's name and identifier and various account attributes. The *bufptr* parameter points to a [USER_INFO_20](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_20) structure. Note that on Windows XP and later, it is recommended that you use [USER_INFO_23](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_23) instead. |
| **23** | Return the user's name and identifier and various account attributes. The *bufptr* parameter points to a [USER_INFO_23](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_23) structure.<br><br>**Note** This level is supported on Windows XP and later. |
| **24** | Return user account information for accounts which are connected to an Internet identity. The *bufptr* parameter points to a [USER_INFO_24](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_24) structure.<br><br>**Note** The level is supported on Windows 8 and Windows Server 2012. |

### `bufptr` [out]

A pointer to the buffer that receives the data. The format of this data depends on the value of the *level* parameter. This buffer is allocated by the system and must be freed using the
[NetApiBufferFree](https://learn.microsoft.com/windows/desktop/api/lmapibuf/nf-lmapibuf-netapibufferfree) function. For more information, see
[Network Management Function Buffers](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffers) and
[Network Management Function Buffer Lengths](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffer-lengths).

## Return value

If the function succeeds, the return value is NERR_Success.

If the function fails, the return value can be one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The user does not have access to the requested information. |
| **ERROR_BAD_NETPATH** | The network path specified in the *servername* parameter was not found. |
| **ERROR_INVALID_LEVEL** | The value specified for the *level* parameter is invalid. |
| **NERR_InvalidComputer** | The computer name is invalid. |
| **NERR_UserNotFound** | The user name could not be found. |

## Remarks

If you are programming for Active Directory, you may be able to call certain Active Directory Service Interface (ADSI) methods to achieve the same functionality you can achieve by calling the network management user functions. For more information, see
[IADsUser](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsuser) and
[IADsComputer](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadscomputer).

If you call this function on a domain controller that is running Active Directory, access is allowed or denied based on the access control list (ACL) for the [securable object](https://learn.microsoft.com/windows/desktop/SecAuthZ/securable-objects). The default ACL permits all authenticated users and members of the "[Pre-Windows 2000 compatible access](https://learn.microsoft.com/windows/desktop/SecAuthZ/allowing-anonymous-access)" group to view the information. If you call this function on a member server or workstation, all authenticated users can view the information. For information about anonymous access and restricting anonymous access on these platforms, see
[Security Requirements for the Network Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/security-requirements-for-the-network-management-functions). For more information on ACLs, ACEs, and access tokens, see
[Access Control Model](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control-model).

The security descriptor of the User object is used to perform the access check for this function.

User account names are limited to 20 characters and group names are limited to 256 characters. In addition, account names cannot be terminated by a period and they cannot include commas or any of the following printable characters: ", /, \, [, ], :, |, <, >, +, =, ;, ?, *. Names also cannot include characters in the range 1-31, which are nonprintable.

If the information level specified in the *level* parameter is set to 24, the *servername* parameter specified must resolve to the local computer. If the *servername* resolves to a remote computer or to a domain controller, the **NetUserGetInfo** function will fail.

#### Examples

The following code sample demonstrates how to retrieve information about a particular user account with a call to the
**NetUserGetInfo** function. The sample calls
**NetUserGetInfo**, specifying various information levels . If the call succeeds, the code prints information about the user account. Finally, the sample frees the memory allocated for the information buffer.

```cpp
#ifndef UNICODE
#define UNICODE
#endif
#pragma comment(lib, "advapi32.lib")
#pragma comment(lib, "netapi32.lib")

#include <windows.h>
#include <stdio.h>
#include <assert.h>
#include <lm.h>
#include <sddl.h>               /* for ConvertSidToStringSid function */

int wmain(int argc, wchar_t * argv[])
{
    DWORD dwLevel = 0;

    LPUSER_INFO_0 pBuf = NULL;
    LPUSER_INFO_1 pBuf1 = NULL;
    LPUSER_INFO_2 pBuf2 = NULL;
    LPUSER_INFO_3 pBuf3 = NULL;
    LPUSER_INFO_4 pBuf4 = NULL;
    LPUSER_INFO_10 pBuf10 = NULL;
    LPUSER_INFO_11 pBuf11 = NULL;
    LPUSER_INFO_20 pBuf20 = NULL;
    LPUSER_INFO_23 pBuf23 = NULL;

    NET_API_STATUS nStatus;

    LPTSTR sStringSid = NULL;

    int i = 0;
    int j = 0;

    if (argc != 3)
    {
        fwprintf(stderr, L"Usage: %s \\\\ServerName UserName\n", argv[0]);
        exit(1);
    }

    while (i < 24)
    {

        //
        // Call the NetUserGetInfo function.
        //
        dwLevel = i;
        wprintf
            (L"\nCalling NetUserGetinfo with Servername=%s Username=%s Level=%d\n",
             argv[1], argv[2], dwLevel);
        nStatus = NetUserGetInfo(argv[1], argv[2], dwLevel, (LPBYTE *) & pBuf);
        //
        // If the call succeeds, print the user information.
        //
        if (nStatus == NERR_Success)
        {
            if (pBuf != NULL)
            {

                switch (i)
                {
                case 0:
                    wprintf(L"\tUser account name: %s\n", pBuf->usri0_name);
                    break;
                case 1:
                    pBuf1 = (LPUSER_INFO_1) pBuf;
                    wprintf(L"\tUser account name: %s\n", pBuf1->usri1_name);
                    wprintf(L"\tPassword: %s\n", pBuf1->usri1_password);
                    wprintf(L"\tPassword age (seconds): %d\n",
                            pBuf1->usri1_password_age);
                    wprintf(L"\tPrivilege level: %d\n", pBuf1->usri1_priv);
                    wprintf(L"\tHome directory: %s\n", pBuf1->usri1_home_dir);
                    wprintf(L"\tUser comment: %s\n", pBuf1->usri1_comment);
                    wprintf(L"\tFlags (in hex): %x\n", pBuf1->usri1_flags);
                    wprintf(L"\tScript path: %s\n", pBuf1->usri1_script_path);
                    break;
                case 2:
                    pBuf2 = (LPUSER_INFO_2) pBuf;
                    wprintf(L"\tUser account name: %s\n", pBuf2->usri2_name);
                    wprintf(L"\tPassword: %s\n", pBuf2->usri2_password);
                    wprintf(L"\tPassword age (seconds): %d\n",
                            pBuf2->usri2_password_age);
                    wprintf(L"\tPrivilege level: %d\n", pBuf2->usri2_priv);
                    wprintf(L"\tHome directory: %s\n", pBuf2->usri2_home_dir);
                    wprintf(L"\tComment: %s\n", pBuf2->usri2_comment);
                    wprintf(L"\tFlags (in hex): %x\n", pBuf2->usri2_flags);
                    wprintf(L"\tScript path: %s\n", pBuf2->usri2_script_path);
                    wprintf(L"\tAuth flags (in hex): %x\n",
                            pBuf2->usri2_auth_flags);
                    wprintf(L"\tFull name: %s\n", pBuf2->usri2_full_name);
                    wprintf(L"\tUser comment: %s\n", pBuf2->usri2_usr_comment);
                    wprintf(L"\tParameters: %s\n", pBuf2->usri2_parms);
                    wprintf(L"\tWorkstations: %s\n", pBuf2->usri2_workstations);
                    wprintf
                        (L"\tLast logon (seconds since January 1, 1970 GMT): %d\n",
                         pBuf2->usri2_last_logon);
                    wprintf
                        (L"\tLast logoff (seconds since January 1, 1970 GMT): %d\n",
                         pBuf2->usri2_last_logoff);
                    wprintf
                        (L"\tAccount expires (seconds since January 1, 1970 GMT): %d\n",
                         pBuf2->usri2_acct_expires);
                    wprintf(L"\tMax storage: %d\n", pBuf2->usri2_max_storage);
                    wprintf(L"\tUnits per week: %d\n",
                            pBuf2->usri2_units_per_week);
                    wprintf(L"\tLogon hours:");
                    for (j = 0; j < 21; j++)
                    {
                        printf(" %x", (BYTE) pBuf2->usri2_logon_hours[j]);
                    }
                    wprintf(L"\n");
                    wprintf(L"\tBad password count: %d\n",
                            pBuf2->usri2_bad_pw_count);
                    wprintf(L"\tNumber of logons: %d\n",
                            pBuf2->usri2_num_logons);
                    wprintf(L"\tLogon server: %s\n", pBuf2->usri2_logon_server);
                    wprintf(L"\tCountry code: %d\n", pBuf2->usri2_country_code);
                    wprintf(L"\tCode page: %d\n", pBuf2->usri2_code_page);
                    break;
                case 4:
                    pBuf4 = (LPUSER_INFO_4) pBuf;
                    wprintf(L"\tUser account name: %s\n", pBuf4->usri4_name);
                    wprintf(L"\tPassword: %s\n", pBuf4->usri4_password);
                    wprintf(L"\tPassword age (seconds): %d\n",
                            pBuf4->usri4_password_age);
                    wprintf(L"\tPrivilege level: %d\n", pBuf4->usri4_priv);
                    wprintf(L"\tHome directory: %s\n", pBuf4->usri4_home_dir);
                    wprintf(L"\tComment: %s\n", pBuf4->usri4_comment);
                    wprintf(L"\tFlags (in hex): %x\n", pBuf4->usri4_flags);
                    wprintf(L"\tScript path: %s\n", pBuf4->usri4_script_path);
                    wprintf(L"\tAuth flags (in hex): %x\n",
                            pBuf4->usri4_auth_flags);
                    wprintf(L"\tFull name: %s\n", pBuf4->usri4_full_name);
                    wprintf(L"\tUser comment: %s\n", pBuf4->usri4_usr_comment);
                    wprintf(L"\tParameters: %s\n", pBuf4->usri4_parms);
                    wprintf(L"\tWorkstations: %s\n", pBuf4->usri4_workstations);
                    wprintf
                        (L"\tLast logon (seconds since January 1, 1970 GMT): %d\n",
                         pBuf4->usri4_last_logon);
                    wprintf
                        (L"\tLast logoff (seconds since January 1, 1970 GMT): %d\n",
                         pBuf4->usri4_last_logoff);
                    wprintf
                        (L"\tAccount expires (seconds since January 1, 1970 GMT): %d\n",
                         pBuf4->usri4_acct_expires);
                    wprintf(L"\tMax storage: %d\n", pBuf4->usri4_max_storage);
                    wprintf(L"\tUnits per week: %d\n",
                            pBuf4->usri4_units_per_week);
                    wprintf(L"\tLogon hours:");
                    for (j = 0; j < 21; j++)
                    {
                        printf(" %x", (BYTE) pBuf4->usri4_logon_hours[j]);
                    }
                    wprintf(L"\n");
                    wprintf(L"\tBad password count: %d\n",
                            pBuf4->usri4_bad_pw_count);
                    wprintf(L"\tNumber of logons: %d\n",
                            pBuf4->usri4_num_logons);
                    wprintf(L"\tLogon server: %s\n", pBuf4->usri4_logon_server);
                    wprintf(L"\tCountry code: %d\n", pBuf4->usri4_country_code);
                    wprintf(L"\tCode page: %d\n", pBuf4->usri4_code_page);
                    if (ConvertSidToStringSid
                        (pBuf4->usri4_user_sid, &sStringSid))
                    {
                        wprintf(L"\tUser SID: %s\n", sStringSid);
                        LocalFree(sStringSid);
                    }
                    else
                        wprintf(L"ConvertSidToSTringSid failed with error %d\n",
                                GetLastError());
                    wprintf(L"\tPrimary group ID: %d\n",
                            pBuf4->usri4_primary_group_id);
                    wprintf(L"\tProfile: %s\n", pBuf4->usri4_profile);
                    wprintf(L"\tHome directory drive letter: %s\n",
                            pBuf4->usri4_home_dir_drive);
                    wprintf(L"\tPassword expired information: %d\n",
                            pBuf4->usri4_password_expired);
                    break;
                case 10:
                    pBuf10 = (LPUSER_INFO_10) pBuf;
                    wprintf(L"\tUser account name: %s\n", pBuf10->usri10_name);
                    wprintf(L"\tComment: %s\n", pBuf10->usri10_comment);
                    wprintf(L"\tUser comment: %s\n",
                            pBuf10->usri10_usr_comment);
                    wprintf(L"\tFull name: %s\n", pBuf10->usri10_full_name);
                    break;
                case 11:
                    pBuf11 = (LPUSER_INFO_11) pBuf;
                    wprintf(L"\tUser account name: %s\n", pBuf11->usri11_name);
                    wprintf(L"\tComment: %s\n", pBuf11->usri11_comment);
                    wprintf(L"\tUser comment: %s\n",
                            pBuf11->usri11_usr_comment);
                    wprintf(L"\tFull name: %s\n", pBuf11->usri11_full_name);
                    wprintf(L"\tPrivilege level: %d\n", pBuf11->usri11_priv);
                    wprintf(L"\tAuth flags (in hex): %x\n",
                            pBuf11->usri11_auth_flags);
                    wprintf(L"\tPassword age (seconds): %d\n",
                            pBuf11->usri11_password_age);
                    wprintf(L"\tHome directory: %s\n", pBuf11->usri11_home_dir);
                    wprintf(L"\tParameters: %s\n", pBuf11->usri11_parms);
                    wprintf
                        (L"\tLast logon (seconds since January 1, 1970 GMT): %d\n",
                         pBuf11->usri11_last_logon);
                    wprintf
                        (L"\tLast logoff (seconds since January 1, 1970 GMT): %d\n",
                         pBuf11->usri11_last_logoff);
                    wprintf(L"\tBad password count: %d\n",
                            pBuf11->usri11_bad_pw_count);
                    wprintf(L"\tNumber of logons: %d\n",
                            pBuf11->usri11_num_logons);
                    wprintf(L"\tLogon server: %s\n",
                            pBuf11->usri11_logon_server);
                    wprintf(L"\tCountry code: %d\n",
                            pBuf11->usri11_country_code);
                    wprintf(L"\tWorkstations: %s\n",
                            pBuf11->usri11_workstations);
                    wprintf(L"\tMax storage: %d\n", pBuf11->usri11_max_storage);
                    wprintf(L"\tUnits per week: %d\n",
                            pBuf11->usri11_units_per_week);
                    wprintf(L"\tLogon hours:");
                    for (j = 0; j < 21; j++)
                    {
                        printf(" %x", (BYTE) pBuf11->usri11_logon_hours[j]);
                    }
                    wprintf(L"\n");
                    wprintf(L"\tCode page: %d\n", pBuf11->usri11_code_page);
                    break;
                case 20:
                    pBuf20 = (LPUSER_INFO_20) pBuf;
                    wprintf(L"\tUser account name: %s\n", pBuf20->usri20_name);
                    wprintf(L"\tFull name: %s\n", pBuf20->usri20_full_name);
                    wprintf(L"\tComment: %s\n", pBuf20->usri20_comment);
                    wprintf(L"\tFlags (in hex): %x\n", pBuf20->usri20_flags);
                    wprintf(L"\tUser ID: %u\n", pBuf20->usri20_user_id);
                    break;
                case 23:
                    pBuf23 = (LPUSER_INFO_23) pBuf;
                    wprintf(L"\tUser account name: %s\n", pBuf23->usri23_name);
                    wprintf(L"\tFull name: %s\n", pBuf23->usri23_full_name);
                    wprintf(L"\tComment: %s\n", pBuf23->usri23_comment);
                    wprintf(L"\tFlags (in hex): %x\n", pBuf23->usri23_flags);
                    if (ConvertSidToStringSid
                        (pBuf23->usri23_user_sid, &sStringSid))
                    {
                        wprintf(L"\tUser SID: %s\n", sStringSid);
                        LocalFree(sStringSid);
                    }
                    else
                        wprintf(L"ConvertSidToSTringSid failed with error %d\n",
                                GetLastError());
                    break;
                default:
                    break;
                }
            }
        }
        // Otherwise, print the system error.
        //
        else
            fprintf(stderr, "NetUserGetinfo failed with error: %d\n", nStatus);
        //
        // Free the allocated memory.
        //
        if (pBuf != NULL)
            NetApiBufferFree(pBuf);

        switch (i)
        {
        case 0:
        case 1:
        case 10:
            i++;
            break;
        case 2:
            i = 4;
            break;
        case 4:
            i = 10;
            break;
        case 11:
            i = 20;
            break;
        case 20:
            i = 23;
            break;
        default:
            i = 24;
            break;
        }
    }
    return 0;
}

```

## See also

[NetUserEnum](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netuserenum)

[NetUserGetGroups](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusergetgroups)

[NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[USER_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_0)

[USER_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_1)

[USER_INFO_10](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_10)

[USER_INFO_11](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_11)

[USER_INFO_2](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_2)

[USER_INFO_23](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_23)

[USER_INFO_24](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_24)

[USER_INFO_4](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_4)

[User Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/user-functions)