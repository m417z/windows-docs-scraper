# NetServerSetInfo function

## Description

The
**NetServerSetInfo** function sets a server's operating parameters; it can set them individually or collectively. The information is stored in a way that allows it to remain in effect after the system has been reinitialized.

## Parameters

### `servername` [in]

Pointer to a string that specifies the name of the remote server on which the function is to execute. If this parameter is **NULL**, the local computer is used.

### `level` [in]

Specifies the information level of the data. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **101** | Specifies the server name, type, and associated software. The *buf* parameter points to a [SERVER_INFO_101](https://learn.microsoft.com/windows/desktop/api/lmserver/ns-lmserver-server_info_101) structure. |
| **102** | Specifies the server name, type, associated software, and other attributes. The *buf* parameter points to a [SERVER_INFO_102](https://learn.microsoft.com/windows/desktop/api/lmserver/ns-lmserver-server_info_102) structure. |
| **402** | Specifies detailed information about the server. The *buf* parameter points to a [SERVER_INFO_402](https://learn.microsoft.com/windows/desktop/api/lmserver/ns-lmserver-server_info_402) structure. |
| **403** | Specifies detailed information about the server. The *buf* parameter points to a [SERVER_INFO_403](https://learn.microsoft.com/windows/desktop/api/lmserver/ns-lmserver-server_info_403) structure. |

In addition, levels 1001-1006, 1009-1011, 1016-1018, 1021, 1022, 1028, 1029, 1037, and 1043 are valid based on the restrictions for LAN Manager systems.

### `buf` [in]

Pointer to a buffer that receives the server information. The format of this data depends on the value of the *level* parameter. For more information, see
[Network Management Function Buffers](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffers).

### `ParmError` [out]

Pointer to a value that receives the index of the first member of the server information structure that causes the ERROR_INVALID_PARAMETER error. If this parameter is **NULL**, the index is not returned on error. For more information, see the following Remarks section.

## Return value

If the function succeeds, the return value is NERR_Success.

If the function fails, the return value can be one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The user does not have access to the requested information. |
| **ERROR_INVALID_LEVEL** | The value specified for the *level* parameter is invalid. |
| **ERROR_INVALID_PARAMETER** | The specified parameter is invalid. For more information, see the following Remarks section. |
| **ERROR_NOT_ENOUGH_MEMORY** | Insufficient memory is available. |

## Remarks

Only members of the Administrators or Server Operators local group can successfully execute the
**NetServerSetInfo** function.

If you are programming for Active Directory, you may be able to call certain Active Directory Service Interface (ADSI) methods to achieve the same functionality you can achieve by calling the network management server functions. For more information, see
[IADsComputer](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadscomputer).

If the
**NetServerSetInfo** function returns ERROR_INVALID_PARAMETER, you can use the *ParmError* parameter to indicate the first member of the server information structure that is invalid. (A server information structure begins with SERVER_INFO_ and its format is specified by the *level* parameter.) The following table lists the values that can be returned in the *ParmError* parameter and the corresponding structure member that is in error. (The prefix sv*_ indicates that the member can begin with multiple prefixes, for example, sv101_ or sv402_.)

| Value | Member |
| --- | --- |
| SV_PLATFORM_ID_PARMNUM | sv*_platform_id |
| SV_NAME_PARMNUM | sv*_name |
| SV_VERSION_MAJOR_PARMNUM | sv*_version_major |
| SV_VERSION_MINOR_PARMNUM | sv*_version_minor |
| SV_TYPE_PARMNUM | sv*_type |
| SV_COMMENT_PARMNUM | sv*_comment |
| SV_USERS_PARMNUM | sv*_users |
| SV_DISC_PARMNUM | sv*_disc |
| SV_HIDDEN_PARMNUM | sv*_hidden |
| SV_ANNOUNCE_PARMNUM | sv*_announce |
| SV_ANNDELTA_PARMNUM | sv*_anndelta |
| SV_USERPATH_PARMNUM | sv*_userpath |
| SV_ULIST_MTIME_PARMNUM | sv*_ulist_mtime |
| SV_GLIST_MTIME_PARMNUM | sv*_glist_mtime |
| SV_ALIST_MTIME_PARMNUM | sv*_alist_mtime |
| SV_ALERTS_PARMNUM | sv*_alerts |
| SV_SECURITY_PARMNUM | sv*_security |
| SV_NUMADMIN_PARMNUM | sv*_numadmin |
| SV_LANMASK_PARMNUM | sv*_lanmask |
| SV_GUESTACC_PARMNUM | sv*_guestacc |
| SV_CHDEVQ_PARMNUM | sv*_chdevq |
| SV_CHDEVJOBS_PARMNUM | sv*_chdevjobs |
| SV_CONNECTIONS_PARMNUM | sv*_connections |
| SV_SHARES_PARMNUM | sv*_shares |
| SV_OPENFILES_PARMNUM | sv*_openfiles |
| SV_SESSOPENS_PARMNUM | sv*_sessopens |
| SV_SESSVCS_PARMNUM | sv*_sessvcs |
| SV_SESSREQS_PARMNUM | sv*_sessreqs |
| SV_OPENSEARCH_PARMNUM | sv*_opensearch |
| SV_ACTIVELOCKS_PARMNUM | sv*_activelocks |
| SV_NUMREQBUF_PARMNUM | sv*_numreqbuf |
| SV_SIZREQBUF_PARMNUM | sv*_sizreqbuf |
| SV_NUMBIGBUF_PARMNUM | sv*_numbigbuf |
| SV_NUMFILETASKS_PARMNUM | sv*_numfiletasks |
| SV_ALERTSCHED_PARMNUM | sv*_alertsched |
| SV_ERRORALERT_PARMNUM | sv*_erroralert |
| SV_LOGONALERT_PARMNUM | sv*_logonalert |
| SV_ACCESSALERT_PARMNUM | sv*_accessalert |
| SV_DISKALERT_PARMNUM | sv*_diskalert |
| SV_NETIOALERT_PARMNUM | sv*_netioalert |
| SV_MAXAUDITSZ_PARMNUM | sv*_maxauditsz |
| SV_SRVHEURISTICS_PARMNUM | sv*_srvheuristics |
| SV_TIMESOURCE_PARMNUM | sv*_timesource |

#### Examples

The following code sample demonstrates how to call the
**NetServerSetInfo** function. The sample calls
**NetServerSetInfo**, specifying the *level* parameter as 1005 (required) to set the **sv1005_comment** member of the [SERVER_INFO_1005](https://learn.microsoft.com/windows/desktop/api/lmserver/ns-lmserver-server_info_1005) structure.

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
   DWORD dwLevel = 1005;
   SERVER_INFO_1005 si;
   NET_API_STATUS nStatus;

   if (argc != 3)
   {
      fwprintf(stderr, L"Usage: %s \\\\ServerName Comment\n", argv[0]);
      exit(1);
   }
   //
   // Fill in SERVER_INFO_1005 structure member.
   //
   si.sv1005_comment = (LPTSTR) argv[2];
   //
   // Call the NetServerSetInfo function,
   //  specifying level 1005.
   //
   nStatus = NetServerSetInfo(argv[1],
                              dwLevel,
                              (LPBYTE)&si,
                              NULL);
   //
   // Display the result of the call.
   //
   if (nStatus == NERR_Success)
      fwprintf(stderr, L"Comment reset\n", argv[2]);
   else
      fprintf(stderr, "A system error has occurred: %d\n", nStatus);
   return 0;
}

```

## See also

[NetServerGetInfo](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netservergetinfo)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[SERVER_INFO_101](https://learn.microsoft.com/windows/desktop/api/lmserver/ns-lmserver-server_info_101)

[SERVER_INFO_102](https://learn.microsoft.com/windows/desktop/api/lmserver/ns-lmserver-server_info_102)

[SERVER_INFO_402](https://learn.microsoft.com/windows/desktop/api/lmserver/ns-lmserver-server_info_402)

[SERVER_INFO_403](https://learn.microsoft.com/windows/desktop/api/lmserver/ns-lmserver-server_info_403)

[Server
Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/server-functions)