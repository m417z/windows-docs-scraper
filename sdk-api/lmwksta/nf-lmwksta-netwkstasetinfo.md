# NetWkstaSetInfo function

## Description

 The **NetWkstaSetInfo** function configures a workstation with information that remains in effect after the system has been reinitialized.

## Parameters

### `servername` [in]

A pointer to a string that specifies the DNS or NetBIOS name of the remote server on which the function is to execute. If this parameter is **NULL**, the local computer is used.

### `level` [in]

The information level of the data. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **100** | **Windows NT:** Specifies information about a workstation environment, including platform-specific information, the names of the domain and the local computer, and information concerning the operating system. The *buffer* parameter points to a [WKSTA_INFO_100](https://learn.microsoft.com/windows/desktop/api/lmwksta/ns-lmwksta-wksta_info_100) structure. The **wk100_computername** and **wk100_langroup** fields of this structure cannot be set by calling this function. To set these values, call [SetComputerName](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-setcomputernamea)/[SetComputerNameEx](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-setcomputernameexa) or [NetJoinDomain](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netjoindomain), respectively. |
| **101** | **Windows NT:** In addition to level 100 information, specifies the path to the LANMAN directory. The *buffer* parameter points to a [WKSTA_INFO_101](https://learn.microsoft.com/windows/desktop/api/lmwksta/ns-lmwksta-wksta_info_101) structure. The **wk101_computername** and **wk101_langroup** fields of this structure cannot be set by calling this function. To set these values, call [SetComputerName](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-setcomputernamea)/[SetComputerNameEx](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-setcomputernameexa) or **NetJoinDomain**, respectively. |
| **102** | **Windows NT:** In addition to level 101 information, specifies the number of users who are logged on to the local computer. The *buffer* parameter points to a [WKSTA_INFO_102](https://learn.microsoft.com/windows/desktop/api/lmwksta/ns-lmwksta-wksta_info_102) structure. The **wk102_computername** and **wk102_langroup** fields of this structure cannot be set by calling this function. To set these values, call [SetComputerName](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-setcomputernamea)/[SetComputerNameEx](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-setcomputernameexa) or **NetJoinDomain**, respectively. |
| **502** | **Windows NT:** The *buffer* parameter points to a [WKSTA_INFO_502](https://learn.microsoft.com/windows/desktop/api/lmwksta/ns-lmwksta-wksta_info_502) structure that contains information about the workstation environment. |

Do not set levels 1010-1013, 1018, 1023, 1027, 1028, 1032, 1033, 1035, or 1041-1062.

### `buffer` [in]

A pointer to the buffer that specifies the data. The format of this data depends on the value of the *level* parameter. For more information, see
[Network Management Function Buffers](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffers).

### `parm_err` [out]

A pointer to a value that receives the index of the first member of the workstation information structure that causes the ERROR_INVALID_PARAMETER error. If this parameter is **NULL**, the index is not returned on error. For more information, see the Remarks section.

## Return value

If the function succeeds, the return value is NERR_Success.

If the function fails, the return value can be one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The user does not have access to the requested information. |
| **ERROR_INVALID_PARAMETER** | One of the function parameters is invalid. For more information, see the following Remarks section. |

## Remarks

Only members of the Administrators group can successfully execute the
**NetWkstaSetInfo** function on a remote server.

The
**NetWkstaSetInfo** function calls the workstation service on the local system or a remote system. Only a limited number of members of the [WKSTA_INFO_502](https://learn.microsoft.com/windows/desktop/api/lmwksta/ns-lmwksta-wksta_info_502) structure can actually be changed using the **NetWkstaSetInfo** function. No errors are returned if a member is set that is ignored by the workstation service. The workstation service is primarily configured using settings in the registry.

The [NetWkstaUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmwksta/nf-lmwksta-netwkstausersetinfo) function can be used instead of the **NetWkstaSetInfo** function to set configuration information on the local system. The **NetWkstaUserSetInfo** function calls the Local Security Authority (LSA).

If the
**NetWkstaSetInfo** function returns ERROR_INVALID_PARAMETER, you can use the *parm_err* parameter to indicate the first member of the workstation information structure that is invalid. (A workstation information structure begins with WKSTA_INFO_ and its format is specified by the *level* parameter.) The following table lists the values that can be returned in the *parm_err* parameter and the corresponding structure member that is in error. (The prefix wki*_ indicates that the member can begin with multiple prefixes, for example, wki100_ or wki402_.)

| Value | Member |
| --- | --- |
| WKSTA_PLATFORM_ID_PARMNUM | wki*_platform_id |
| WKSTA_COMPUTERNAME_PARMNUM | wki*_computername |
| WKSTA_LANGROUP_PARMNUM | wki*_langroup |
| WKSTA_VER_MAJOR_PARMNUM | wki*_ver_major |
| WKSTA_VER_MINOR_PARMNUM | wki*_ver_minor |
| WKSTA_LOGGED_ON_USERS_PARMNUM | wki*_logged_on_users |
| WKSTA_LANROOT_PARMNUM | wki*_lanroot |
| WKSTA_LOGON_DOMAIN_PARMNUM | wki*_logon_domain |
| WKSTA_LOGON_SERVER_PARMNUM | wki*_logon_server |
| WKSTA_CHARWAIT_PARMNUM | wki*_char_wait |
| WKSTA_CHARTIME_PARMNUM | wki*_collection_time |
| WKSTA_CHARCOUNT_PARMNUM | wki*_maximum_collection_count |
| WKSTA_KEEPCONN_PARMNUM | wki*_keep_conn |
| WKSTA_KEEPSEARCH_PARMNUM | wki*_keep_search |
| WKSTA_MAXCMDS_PARMNUM | wki*_max_cmds |
| WKSTA_NUMWORKBUF_PARMNUM | wki*_num_work_buf |
| WKSTA_MAXWRKCACHE_PARMNUM | wki*_max_wrk_cache |
| WKSTA_SESSTIMEOUT_PARMNUM | wki*_sess_timeout |
| WKSTA_SIZERROR_PARMNUM | wki*_siz_error |
| WKSTA_NUMALERTS_PARMNUM | wki*_num_alerts |
| WKSTA_NUMSERVICES_PARMNUM | wki*_num_services |
| WKSTA_ERRLOGSZ_PARMNUM | wki*_errlog_sz |
| WKSTA_PRINTBUFTIME_PARMNUM | wki*_print_buf_time |
| WKSTA_NUMCHARBUF_PARMNU | wki*_num_char_buf |
| WKSTA_SIZCHARBUF_PARMNUM | wki*_siz_char_buf |
| WKSTA_WRKHEURISTICS_PARMNUM | wki*_wrk_heuristics |
| WKSTA_MAILSLOTS_PARMNUM | wki*_mailslots |
| WKSTA_MAXTHREADS_PARMNUM | wki*_max_threads |
| WKSTA_SIZWORKBUF_PARMNUM | wki*_siz_work_buf |
| WKSTA_NUMDGRAMBUF_PARMNUM | wki*_num_dgram_buf |

The workstation service parameter settings are stored in the registry, not in the LanMan.ini file used previously by LAN Manager. The
**NetWkstaSetInfo** function does not change the values in the LanMan.ini file. When the workstation service is stopped and restarted, workstation parameters are reset to the default values specified in the registry (unless they are overwritten by command-line parameters). Values set by previous calls to
**NetWkstaSetInfo** can be overwritten when workstation parameters are reset.

#### Examples

The following code sample demonstrates how to set the session time-out value associated with a workstation using a call to the
**NetServerSetInfo** function. (The session time-out is the number of seconds the server waits before disconnecting an inactive session.) The code specifies information level 502 ([WKSTA_INFO_502](https://learn.microsoft.com/windows/desktop/api/lmwksta/ns-lmwksta-wksta_info_502)).

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
   LPWKSTA_INFO_502 pBuf = NULL;
   WKSTA_INFO_502 wi;
   DWORD dwLevel = 502;
   NET_API_STATUS nStatus;
   LPWSTR pszServerName = NULL;

   if ((argc < 2) || (argc > 3))
   {
      fwprintf(stderr, L"Usage: %s [\\\\ServerName] SessionTimeOut\n", argv[0]);
      exit(1);
   }

   if (argc == 3)
      pszServerName = argv[1];
   //
   // Retrieve the current settings.
   //
   nStatus = NetWkstaGetInfo(pszServerName,
                             dwLevel,
                             (LPBYTE *)&pBuf);

   if (nStatus != NERR_Success)
   {
      fprintf(stderr, "A system error has occurred (NetWkstaGetInfo): %d\n", nStatus);
      return -1;
   }

   if (pBuf != NULL)
   {
      //
      // Copy the existing settings to the new structure,
      //   and free the buffer.
      //
      CopyMemory(&wi, pBuf, sizeof(wi));
      NetApiBufferFree(pBuf);
   }
   else
   {
      fprintf(stderr, "Memory invalid!\n");
      return -1;
   }
   //
   // Set a new session time-out value by
   //   calling the NetWkstaSetInfo function.
   //
   wi.wki502_sess_timeout = _wtoi(argv[argc-1]);
   nStatus = NetWkstaSetInfo(pszServerName,
                             dwLevel,
                             (LPBYTE)&wi,
                             NULL);
   //
   // Display the result of the call.
   //
   if (nStatus == NERR_Success)
      fwprintf(stderr, L"Workstation information reset: session time-out = %d\n", _wtoi(argv[argc-1]));
   else
      fprintf(stderr, "A system error has occurred (NetWkstaSetInfo): %d\n", nStatus);

   return 0;
}

```

## See also

[NetWkstaGetInfo](https://learn.microsoft.com/windows/desktop/api/lmwksta/nf-lmwksta-netwkstagetinfo)

[NetWkstaUserGetInfo](https://learn.microsoft.com/windows/desktop/api/lmwksta/nf-lmwksta-netwkstausergetinfo)

[NetWkstaUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmwksta/nf-lmwksta-netwkstausersetinfo)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Workstation and Workstation User Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/workstation-and-workstation-user-functions)