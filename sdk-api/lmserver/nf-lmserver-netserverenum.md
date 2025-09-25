# NetServerEnum function

## Description

The
**NetServerEnum** function lists all servers of the specified type that are visible in a domain.

## Parameters

### `servername` [in, optional]

Reserved; must be **NULL**.

### `level` [in]

The information level of the data requested. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **100** | Return server names and platform information. The *bufptr* parameter points to an array of [SERVER_INFO_100](https://learn.microsoft.com/windows/desktop/api/lmserver/ns-lmserver-server_info_100) structures. |
| **101** | Return server names, types, and associated data. The *bufptr* parameter points to an array of [SERVER_INFO_101](https://learn.microsoft.com/windows/desktop/api/lmserver/ns-lmserver-server_info_101) structures. |

### `bufptr` [out]

A pointer to the buffer that receives the data. The format of this data depends on the value of the *level* parameter. This buffer is allocated by the system and must be freed using the
[NetApiBufferFree](https://learn.microsoft.com/windows/desktop/api/lmapibuf/nf-lmapibuf-netapibufferfree) function. Note that you must free the buffer even if the function fails with ERROR_MORE_DATA.

### `prefmaxlen` [in]

The preferred maximum length of returned data, in bytes. If you specify MAX_PREFERRED_LENGTH, the function allocates the amount of memory required for the data. If you specify another value in this parameter, it can restrict the number of bytes that the function returns. If the buffer size is insufficient to hold all entries, the function returns ERROR_MORE_DATA. For more information, see
[Network Management Function Buffers](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffers) and
[Network Management Function Buffer Lengths](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffer-lengths).

### `entriesread` [out]

A pointer to a value that receives the count of elements actually enumerated.

### `totalentries` [out]

A pointer to a value that receives the total number of visible servers and workstations on the network. Note that applications should consider this value only as a hint.

### `servertype` [in]

A value that filters the server entries to return from the enumeration. This parameter can be a combination of the following values defined in the *Lmserver.h* header file.

| Value | Meaning |
| --- | --- |
| **SV_TYPE_WORKSTATION**<br><br>0x00000001 | All workstations. |
| **SV_TYPE_SERVER**<br><br>0x00000002 | All computers that run the Server service. |
| **SV_TYPE_SQLSERVER**<br><br>0x00000004 | Any server that runs an instance of Microsoft SQL Server. |
| **SV_TYPE_DOMAIN_CTRL**<br><br>0x00000008 | A server that is primary domain controller. |
| **SV_TYPE_DOMAIN_BAKCTRL**<br><br>0x00000010 | Any server that is a backup domain controller. |
| **SV_TYPE_TIME_SOURCE**<br><br>0x00000020 | Any server that runs the Timesource service. |
| **SV_TYPE_AFP**<br><br>0x00000040 | Any server that runs the Apple Filing Protocol (AFP) file service. |
| **SV_TYPE_NOVELL**<br><br>0x00000080 | Any server that is a Novell server. |
| **SV_TYPE_DOMAIN_MEMBER**<br><br>0x00000100 | Any computer that is LAN Manager 2.x domain member. |
| **SV_TYPE_PRINTQ_SERVER**<br><br>0x00000200 | Any computer that shares a print queue. |
| **SV_TYPE_DIALIN_SERVER**<br><br>0x00000400 | Any server that runs a dial-in service. |
| **SV_TYPE_XENIX_SERVER**<br><br>0x00000800 | Any server that is a Xenix server. |
| **SV_TYPE_SERVER_UNIX**<br><br>0x00000800 | Any server that is a UNIX server. This is the same as the **SV_TYPE_XENIX_SERVER**. |
| **SV_TYPE_NT**<br><br>0x00001000 | A workstation or server. |
| **SV_TYPE_WFW**<br><br>0x00002000 | Any computer that runs Windows for Workgroups. |
| **SV_TYPE_SERVER_MFPN**<br><br>0x00004000 | Any server that runs the Microsoft File and Print for NetWare service. |
| **SV_TYPE_SERVER_NT**<br><br>0x00008000 | Any server that is not a domain controller. |
| **SV_TYPE_POTENTIAL_BROWSER**<br><br>0x00010000 | Any computer that can run the browser service. |
| **SV_TYPE_BACKUP_BROWSER**<br><br>0x00020000 | A computer that runs a browser service as backup. |
| **SV_TYPE_MASTER_BROWSER**<br><br>0x00040000 | A computer that runs the master browser service. |
| **SV_TYPE_DOMAIN_MASTER**<br><br>0x00080000 | A computer that runs the domain master browser. |
| **SV_TYPE_SERVER_OSF**<br><br>0x00100000 | A computer that runs OSF/1. |
| **SV_TYPE_SERVER_VMS**<br><br>0x00200000 | A computer that runs Open Virtual Memory System (VMS). |
| **SV_TYPE_WINDOWS**<br><br>0x00400000 | A computer that runs Windows. |
| **SV_TYPE_DFS**<br><br>0x00800000 | A computer that is the root of Distributed File System (DFS) tree. |
| **SV_TYPE_CLUSTER_NT**<br><br>0x01000000 | Server clusters available in the domain. |
| **SV_TYPE_TERMINALSERVER**<br><br>0x02000000 | A server running the Terminal Server service. |
| **SV_TYPE_CLUSTER_VS_NT**<br><br>0x04000000 | Cluster virtual servers available in the domain.<br><br>**Windows 2000:** This value is not supported. |
| **SV_TYPE_DCE**<br><br>0x10000000 | A computer that runs IBM Directory and Security Services (DSS) or equivalent. |
| **SV_TYPE_ALTERNATE_XPORT**<br><br>0x20000000 | A computer that over an alternate transport. |
| **SV_TYPE_LOCAL_LIST_ONLY**<br><br>0x40000000 | Any computer maintained in a list by the browser. See the following Remarks section. |
| **SV_TYPE_DOMAIN_ENUM**<br><br>0x80000000 | The primary domain. |
| **SV_TYPE_ALL**<br><br>0xFFFFFFFF | All servers. This is a convenience that will return all possible servers. |

### `domain` [in, optional]

A pointer to a constant string that specifies the name of the domain for which a list of servers is to be returned. The domain name must be a NetBIOS domain name (for example, microsoft).
The **NetServerEnum** function does not support DNS-style names (for example, microsoft.com).

If this parameter is **NULL**, the primary domain is implied.

### `resume_handle` [in, out, optional]

Reserved; must be set to zero.

## Return value

If the function succeeds, the return value is NERR_Success.

If the function fails, the return value can be one of the following error codes:

| Return code/value | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED**<br><br>5 | Access was denied. |
| **ERROR_INVALID_PARAMETER**<br><br>87 | The parameter is incorrect. |
| **ERROR_MORE_DATA**<br><br>234 | More entries are available. Specify a large enough buffer to receive all entries. |
| **ERROR_NO_BROWSER_SERVERS_FOUND**<br><br>6118 | No browser servers found. |
| **ERROR_NOT_SUPPORTED**<br><br>50 | The request is not supported. |
| **NERR_RemoteErr**<br><br>2127 | A remote error occurred with no data returned by the server. |
| **NERR_ServerNotStarted**<br><br>2114 | The server service is not started. |
| **NERR_ServiceNotInstalled**<br><br>2184 | The service has not been started. |
| **NERR_WkstaNotStarted**<br><br>2138 | The Workstation service has not been started. The local workstation service is used to communicate with a downlevel remote server. |

## Remarks

The
**NetServerEnum** function is used to list all servers of the specified type that are visible in a domain. For example, an application can call
**NetServerEnum** to list all domain controllers only or all servers that run instances of SQL server only.

An application combine the bit masks for various server types in the *servertype* parameter to list several types. For example, a value of SV_TYPE_WORKSTATION | SVTYPE_SERVER (0x00000003) combines the bit masks for SV_TYPE_WORKSTATION (0x00000001) and SV_TYPE_SERVER (0x00000002).

If you require more information for a specific server, call the
[WNetEnumResource](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetenumresourcea) function.

No special group membership is required to successfully execute the
**NetServerEnum** function.

If you specify the value SV_TYPE_LOCAL_LIST_ONLY, the
**NetServerEnum** function returns the list of servers that the browser maintains internally. This has meaning only on the master browser (or on a computer that has been the master browser in the past). The master browser is the computer that currently has rights to determine which computers can be servers or workstations on the network.

If there are no servers found that match the types specified in the *servertype* parameter, the
**NetServerEnum** function returns the *bufptr* parameter as **NULL** and DWORD values pointed to by the *entriesread* and *totalentries* parameters are set to zero.

The
**NetServerEnum** function depends on the browser service being installed and running. If no browser servers are found, then **NetServerEnum** fails with ERROR_NO_BROWSER_SERVERS_FOUND.

If you are programming for Active Directory, you may be able to call certain Active Directory Service Interface (ADSI) methods to achieve the same function you can achieve by calling the network management server functions. For more information, see
[IADsComputer](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadscomputer).

#### Examples

The following code sample demonstrates how to list all servers that are visible in a domain with a call to the
**NetServerEnum** function. The sample calls
**NetServerEnum**, specifying information level 101 (
[SERVER_INFO_101](https://learn.microsoft.com/windows/desktop/api/lmserver/ns-lmserver-server_info_101)). If any servers are found, the sample code loops through the entries and prints the retrieved data. If the server is a domain controller, it identifies the server as either a primary domain controller (PDC) or a backup domain controller (BDC). The sample also prints the total number of entries available and a hint about the number of entries actually enumerated, warning the user if all entries were not enumerated. Finally, the sample frees the memory allocated for the information buffer.

```cpp
#ifndef UNICODE
#define UNICODE
#endif
#pragma comment(lib, "netapi32.lib")

#include <stdio.h>
#include <assert.h>
#include <windows.h>
#include <lm.h>

int wmain(int argc, wchar_t * argv[])
{
    LPSERVER_INFO_101 pBuf = NULL;
    LPSERVER_INFO_101 pTmpBuf;
    DWORD dwLevel = 101;
    DWORD dwPrefMaxLen = MAX_PREFERRED_LENGTH;
    DWORD dwEntriesRead = 0;
    DWORD dwTotalEntries = 0;
    DWORD dwTotalCount = 0;
    DWORD dwServerType = SV_TYPE_SERVER;        // all servers
    DWORD dwResumeHandle = 0;
    NET_API_STATUS nStatus;
    LPWSTR pszServerName = NULL;
    LPWSTR pszDomainName = NULL;
    DWORD i;

    if (argc > 2)
    {
        fwprintf(stderr, L"Usage: %s [DomainName]\n", argv[0]);
        exit(1);
    }
    // The request is not for the primary domain.
    //
    if (argc == 2)
        pszDomainName = argv[1];
    //
    // Call the NetServerEnum function to retrieve information
    //  for all servers, specifying information level 101.
    //
    nStatus = NetServerEnum(pszServerName,
                            dwLevel,
                            (LPBYTE *) & pBuf,
                            dwPrefMaxLen,
                            &dwEntriesRead,
                            &dwTotalEntries,
                            dwServerType,
                            pszDomainName,
                            &dwResumeHandle);
    //
    // If the call succeeds,
    //
    if ((nStatus == NERR_Success) || (nStatus == ERROR_MORE_DATA)) {
        if ((pTmpBuf = pBuf) != NULL) {
            //
            // Loop through the entries and
            //  print the data for all server types.
            //
            for (i = 0; i < dwEntriesRead; i++) {
                assert(pTmpBuf != NULL);

                if (pTmpBuf == NULL) {
                    fprintf(stderr, "An access violation has occurred\n");
                    break;
                }

                printf("\tPlatform: %d\n", pTmpBuf->sv101_platform_id);
                wprintf(L"\tName:     %s\n", pTmpBuf->sv101_name);
                printf("\tVersion:  %d.%d\n",
                       pTmpBuf->sv101_version_major,
                       pTmpBuf->sv101_version_minor);
                printf("\tType:     %d", pTmpBuf->sv101_type);
                //
                // Check to see if the server is a domain controller;
                //  if so, identify it as a PDC or a BDC.
                //
                if (pTmpBuf->sv101_type & SV_TYPE_DOMAIN_CTRL)
                    wprintf(L" (PDC)");
                else if (pTmpBuf->sv101_type & SV_TYPE_DOMAIN_BAKCTRL)
                    wprintf(L" (BDC)");

                printf("\n");
                //
                // Also print the comment associated with the server.
                //
                wprintf(L"\tComment:  %s\n\n", pTmpBuf->sv101_comment);

                pTmpBuf++;
                dwTotalCount++;
            }
            // Display a warning if all available entries were
            //  not enumerated, print the number actually
            //  enumerated, and the total number available.

            if (nStatus == ERROR_MORE_DATA) {
                fprintf(stderr, "\nMore entries available!!!\n");
                fprintf(stderr, "Total entries: %d", dwTotalEntries);
            }

            printf("\nEntries enumerated: %d\n", dwTotalCount);

        } else {
            printf("No servers were found\n");
            printf("The buffer (bufptr) returned was NULL\n");
            printf("  entriesread: %d\n", dwEntriesRead);
            printf("  totalentries: %d\n", dwEntriesRead);
        }

    } else
        fprintf(stderr, "NetServerEnum failed with error: %d\n", nStatus);
    //
    // Free the allocated buffer.
    //
    if (pBuf != NULL)
        NetApiBufferFree(pBuf);

    return 0;
}

```

## See also

[NetQueryDisplayInformation](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netquerydisplayinformation)

[NetServerDiskEnum](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netserverdiskenum)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[SERVER_INFO_100](https://learn.microsoft.com/windows/desktop/api/lmserver/ns-lmserver-server_info_100)

[SERVER_INFO_101](https://learn.microsoft.com/windows/desktop/api/lmserver/ns-lmserver-server_info_101)

[Server
Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/server-functions)