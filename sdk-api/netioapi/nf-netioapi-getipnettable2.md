## Description

The **GetIpNetTable2** function retrieves the IP neighbor table on the local computer.

## Parameters

### `Family` [in]

The address family to retrieve.

Possible values for the address family are listed in the *Winsock2.h* header file. Note that the values for the AF_ address family and PF_ protocol family constants are identical (for example, **AF_INET** and **PF_INET**), so either constant can be used.

On the Windows SDK released for Windows Vista and later, the organization of header files has changed and possible values for this member are defined in the *Ws2def.h* header file. Note that the *Ws2def.h* header file is automatically included in *Winsock2.h*, and should never be used directly.

The values currently supported are **AF_INET**, **AF_INET6**, and **AF_UNSPEC**.

| Value | Meaning |
| --- | --- |
| **AF_UNSPEC**<br><br>0 | The address family is unspecified. When this parameter is specified, this function returns the neighbor IP address table containing both IPv4 and IPv6 entries. |
| **AF_INET**<br><br>2 | The Internet Protocol version 4 (IPv4) address family. When this parameter is specified, this function returns the neighbor IP address table containing only IPv4 entries. |
| **AF_INET6**<br><br>23 | The Internet Protocol version 6 (IPv6) address family. When this parameter is specified, this function returns the neighbor IP address table containing only IPv6 entries. |

### `Table` [out]

A pointer to a pointer to a [MIB_IPNET_TABLE2](https://learn.microsoft.com/windows/win32/api/netioapi/ns-netioapi-mib_ipnet_table2) structure that contains a table of neighbor IP address entries on the local computer.

## Return value

If the function succeeds, the return value is NO_ERROR or ERROR_NOT_FOUND.

If the function fails or returns no data, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | An invalid parameter was passed to the function. This error is returned if a **NULL** pointer is passed in the *Table* parameter or the *Family* parameter was not specified as **AF_INET**, **AF_INET6**, or **AF_UNSPEC**. |
| **ERROR_NOT_ENOUGH_MEMORY** | Insufficient memory resources are available to complete the operation. |
| **ERROR_NOT_FOUND** | No neighbor IP address entries as specified in the *Family* parameter were found. <br><br>This return value indicates that the call to the [GetIpNetTable2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getipnettable2) function succeeded, but there was no data to return. This can occur when AF_INET is specified in the *Family* parameter and there are no ARP entries to return. |
| **ERROR_NOT_SUPPORTED** | The request is not supported. <br><br>This error is returned if no IPv4 stack is on the local computer and **AF_INET** was specified in the **Family** parameter. This error is also returned if no IPv6 stack is on the local computer and **AF_INET6** was specified in the **Family** parameter. This error is also returned on versions of Windows where this function is not supported. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error. |

## Remarks

The **GetIpNetTable2** function is defined on Windows Vista and later.

The
**GetIpNetTable2** function enumerates the neighbor IP addresses on a local system and returns this information in a [MIB_IPNET_TABLE2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipnet_table2) structure.

The neighbor IP address entries are returned in a [MIB_IPNET_TABLE2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipnet_table2) structure in the buffer pointed to by the *Table* parameter. The **MIB_IPNET_TABLE2** structure contains a neighbor IP address entry count and an array of [MIB_IPNET_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipnet_row2) structures for each neighbor IP address entry. When these returned structures are no longer required, free the memory by calling the [FreeMibTable](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-freemibtable).

The *Family* parameter must be initialized to either **AF_INET**, **AF_INET6**, or **AF_UNSPEC**.

Note that the returned [MIB_IPNET_TABLE2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipnet_table2) structure pointed to by the *Table* parameter may contain padding for alignment between the **NumEntries** member and the first [MIB_IPNET_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipnet_row2) array entry in the **Table** member of the **MIB_IPNET_TABLE2** structure. Padding for alignment may also be present between the **MIB_IPNET_ROW2** array entries. Any access to a **MIB_IPNET_ROW2** array entry should assume padding may exist.

## Examples

The following example retrieves the IP neighbor table, then prints the values for IP neighbor row entries in the table.

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
#pragma comment(lib, "ws2_32.lib")

int main()
{

    // Declare and initialize variables

    int i;
    unsigned int j;
    unsigned long status = 0;

    PMIB_IPNET_TABLE2 pipTable = NULL;
//    MIB_IPNET_ROW2 ipRow;

    status = GetIpNetTable2(AF_INET, &pipTable);
    if (status != NO_ERROR) {
        printf("GetIpNetTable for IPv4 table returned error: %ld\n", status);
        exit(1);
    }
    // Print some variables from the table
    printf("Number of IPv4 table entries: %d\n\n", pipTable->NumEntries);

    for (i = 0; (unsigned) i < pipTable->NumEntries; i++) {
//        printf("Table entry: %d\n", i);
        printf("IPv4 Address[%d]:\t %s\n", (int) i,
               inet_ntoa(pipTable->Table[i].Address.Ipv4.sin_addr));
        printf("Interface index[%d]:\t\t %lu\n", (int) i,
               pipTable->Table[i].InterfaceIndex);

        printf("Interface LUID NetLuidIndex[%d]:\t %lu\n",
               (int) i, pipTable->Table[i].InterfaceLuid.Info.NetLuidIndex);
        printf("Interface LUID IfType[%d]: ", (int) i);
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

        printf("Physical Address[%d]:\t ", (int) i);
        if (pipTable->Table[i].PhysicalAddressLength == 0)
            printf("\n");
//        for (j = 0; (unsigned) j < pipTable->Table[i].PhysicalAddressLength; j++)
//         printf ("%c"
        for (j = 0; j < pipTable->Table[i].PhysicalAddressLength; j++) {
            if (j == (pipTable->Table[i].PhysicalAddressLength - 1))
                printf("%.2X\n", (int) pipTable->Table[i].PhysicalAddress[j]);
            else
                printf("%.2X-", (int) pipTable->Table[i].PhysicalAddress[j]);
        }

        printf("Physical Address Length[%d]:\t %lu\n", (int) i,
               pipTable->Table[i].PhysicalAddressLength);

        printf("Neighbor State[%d]:\t ", (int) i);
        switch (pipTable->Table[i].State) {
        case NlnsUnreachable:
            printf("NlnsUnreachable\n");
            break;
        case NlnsIncomplete:
            printf("NlnsIncomplete\n");
            break;
        case NlnsProbe:
            printf("NlnsProbe\n");
            break;
        case NlnsDelay:
            printf("NlnsDelay\n");
            break;
        case NlnsStale:
            printf("NlnsStale\n");
            break;
        case NlnsReachable:
            printf("NlnsReachable\n");
            break;
        case NlnsPermanent:
            printf("NlnsPermanent\n");
            break;
        default:
            printf("Unknown: %d\n", pipTable->Table[i].State);
            break;
        }

        printf("Flags[%d]:\t\t %u\n", (int) i,
               (unsigned char) pipTable->Table[i].Flags);

        printf("ReachabilityTime[%d]:\t %lu\n\n", (int) i,
               pipTable->Table[i].ReachabilityTime);

    }
    FreeMibTable(pipTable);
    pipTable = NULL;

    exit(0);
}
```

## See also

[CreateIpNetEntry2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-createipnetentry2)

[FlushIpNetTable2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-flushipnettable2)

[FreeMibTable](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-freemibtable)

[GetIpNetEntry2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getipnetentry2)

[MIB_IPNET_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipnet_row2)

[MIB_IPNET_TABLE2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipnet_table2)

[ResolveIpNetEntry2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-resolveipnetentry2)

[SetIpNetEntry2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-setipnetentry2)