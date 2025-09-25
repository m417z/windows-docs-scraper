# GetIpInterfaceTable function

## Description

The
**GetIpInterfaceTable** function retrieves the IP interface entries on the local computer.

## Parameters

### `Family` [in]

The address family of IP interfaces to retrieve.

Possible values for the address family are listed in the *Winsock2.h* header file. Note that the values for the AF_ address family and PF_ protocol family constants are identical (for example, **AF_INET** and **PF_INET**), so either constant can be used.

On Windows Vista and later as well as on the Windows SDK, the organization of header files has changed and possible values for this member are defined in the *Ws2def.h* header file. Note that the *Ws2def.h* header file is automatically included in *Winsock2.h*, and should never be used directly.

The values currently supported are **AF_INET**, **AF_INET6**, and **AF_UNSPEC**.

| Value | Meaning |
| --- | --- |
| **AF_UNSPEC**<br><br>0 | The address family is unspecified. When this parameter is specified, the **GetIpInterfaceTable** function returns the IP interface table containing both IPv4 and IPv6 entries. |
| **AF_INET**<br><br>2 | The Internet Protocol version 4 (IPv4) address family. |
| **AF_INET6**<br><br>23 | The Internet Protocol version 6 (IPv6) address family. |

### `Table` [out]

A pointer to a buffer that receives the table of IP interface entries in a [MIB_IPINTERFACE_TABLE](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipinterface_table) structure.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | An invalid parameter was passed to the function. This error is returned if a **NULL** pointer is passed in the *Table* parameter or the *Family* parameter was not specified as **AF_INET**, **AF_INET6**, or **AF_UNSPEC**. |
| **ERROR_NOT_ENOUGH_MEMORY** | Insufficient memory resources are available to complete the operation. |
| **ERROR_NOT_FOUND** | No IP interface entries as specified in the *Family* parameter were found. |
| **ERROR_NOT_SUPPORTED** | The function is not supported. This error is returned when the IP transport specified in the *Address* parameter is not configured on the local computer. This error is also returned on versions of Windows where this function is not supported. |
| **Other** | Use the [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) function to obtain the message string for the returned error. |

## Remarks

The **GetIpInterfaceTable** function is defined on Windows Vista and later.

The
**GetIpInterfaceTable** function enumerates the IP interfaces on a local system and returns this information in an [MIB_IPINTERFACE_TABLE](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipinterface_table) structure.

IP interface entries are returned in a [MIB_IPINTERFACE_TABLE](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipinterface_table) structure in the buffer pointed to by the *Table* parameter. The **MIB_IPINTERFACE_TABLE** structure contains an IP interface entry count and an array of [MIB_IPINTERFACE_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipinterface_row) structures for each IP interface entry. When these returned structures are no longer required, free the memory by calling the [FreeMibTable](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-freemibtable).

The *Family* parameter must be initialized to either **AF_INET** or **AF_INET6**.

Note that the returned [MIB_IPINTERFACE_TABLE](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipinterface_table) structure pointed to by the *Table* parameter may contain padding for alignment between the **NumEntries** member and the first [MIB_IPINTERFACE_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipinterface_row) array entry in the **Table** member of the **MIB_IPINTERFACE_TABLE** structure. Padding for alignment may also be present between the **MIB_IPINTERFACE_ROW** array entries. Any access to a **MIB_IPINTERFACE_ROW** array entry should assume padding may exist.

#### Examples

The following example retrieves the IP interface table, then prints the values of a few members of the IP interface entries in the table.

```cpp
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include <windows.h>
#include <winsock2.h>
#include <ws2ipdef.h>
#include <iphlpapi.h>
#include <stdio.h>
#include <stdlib.h>

#pragma comment(lib, "iphlpapi.lib")

int main()
{
    // Declare and initialize variables

    int i;

    DWORD dwRetVal = 0;

    PMIB_IPINTERFACE_TABLE pipTable = NULL;

    dwRetVal = GetIpInterfaceTable(AF_UNSPEC, &pipTable);
    if (dwRetVal != NO_ERROR) {
        printf("GetIpInterfaceTable returned error: %ld\n", dwRetVal);
        exit(1);
    }
    // Print some variables from the rows in the table
    printf("Number of table entries: %d\n\n", pipTable->NumEntries);

    for (i = 0; i < (int) pipTable->NumEntries; i++) {
        printf("Address Family[%d]:\t\t", i);
        switch (pipTable->Table[i].Family) {
        case AF_INET:
            printf("IPv4\n");
            break;
        case AF_INET6:
            printf("IPv6\n");
            break;
        default:
            printf("Other: %d\n", pipTable->Table[i].Family);
            break;
        }

        printf("Interface LUID NetLuidIndex[%d]:\t %lu\n",
               i, pipTable->Table[i].InterfaceLuid.Info.NetLuidIndex);

        printf("Interface LUID IfType[%d]:\t ", i);
        switch (pipTable->Table[i].InterfaceLuid.Info.IfType) {
        case IF_TYPE_OTHER:
            printf("Other\n");
            break;
        case IF_TYPE_ETHERNET_CSMACD:
            printf("Ethernet\n");
            break;
        case IF_TYPE_ISO88025_TOKENRING:
            printf("Token ring\n");
            break;
        case IF_TYPE_PPP:
            printf("PPP\n");
            break;
        case IF_TYPE_SOFTWARE_LOOPBACK:
            printf("Software loopback\n");
            break;
        case IF_TYPE_ATM:
            printf("ATM\n");
            break;
        case IF_TYPE_IEEE80211:
            printf("802.11 wireless\n");
            break;
        case IF_TYPE_TUNNEL:
            printf("Tunnel encapsulation\n");
            break;
        case IF_TYPE_IEEE1394:
            printf("IEEE 1394 (Firewire)\n");
            break;
        default:
            printf("Unknown: %d\n",
                   pipTable->Table[i].InterfaceLuid.Info.IfType);
            break;
        }
        printf("Interface Index[%d]:\t\t %lu\n",
               i, pipTable->Table[i].InterfaceIndex);
        printf("Maximum reassembly size[%d]:\t %lu\n", i,
               pipTable->Table[i].MaxReassemblySize);

        printf("Advertising enabled[%d]:\t\t ", i);
        if (pipTable->Table[i].AdvertisingEnabled)
            printf("Yes\n");
        else
            printf("No\n");

        printf("Forwarding enabled[%d]:\t\t ", i);
        if (pipTable->Table[i].ForwardingEnabled)
            printf("Yes\n");
        else
            printf("No\n");

        printf("Network layer MTU[%d]:\t\t %lu\n", i, pipTable->Table[i].NlMtu);

        printf("Connected[%d]:\t\t\t ", i);
        if (pipTable->Table[i].Connected)
            printf("Yes\n");
        else
            printf("No\n");

        printf("Supports wakeup patterns[%d]:\t ", i);
        if (pipTable->Table[i].SupportsWakeUpPatterns)
            printf("Yes\n");
        else
            printf("No\n");

        printf("Supports neighbor discovery[%d]:\t ", i);
        if (pipTable->Table[i].SupportsNeighborDiscovery)
            printf("Yes\n");
        else
            printf("No\n");

        printf("Supports router discovery[%d]:\t ", i);
        if (pipTable->Table[i].SupportsRouterDiscovery)
            printf("Yes\n");
        else
            printf("No\n");

        printf("\n");
    }

    FreeMibTable(pipTable);
    pipTable = NULL;

    exit(0);
}

```

## See also

[FreeMibTable](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-freemibtable)

[GetIfEntry2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getifentry2)

[GetIfStackTable](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getifstacktable)

[GetIfTable2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getiftable2)

[GetInvertedIfStackTable](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getinvertedifstacktable)

[GetIpInterfaceEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getipinterfaceentry)

[IP Helper Function Reference](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-function-reference)

[InitializeIpInterfaceEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-initializeipinterfaceentry)

[MIB_IF_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_if_row2)

[MIB_IF_TABLE2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_if_table2)

[MIB_IPINTERFACE_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipinterface_row)

[MIB_IPINTERFACE_TABLE](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipinterface_table)

[NotifyIpInterfaceChange](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-notifyipinterfacechange)