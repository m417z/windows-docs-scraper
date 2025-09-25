# SendARP function

## Description

The
**SendARP** function sends an Address Resolution Protocol (ARP) request to obtain the physical address that corresponds to the specified destination IPv4 address.

## Parameters

### `DestIP` [in]

The destination IPv4 address, in the form of an [IPAddr](https://learn.microsoft.com/windows/desktop/api/inaddr/ns-inaddr-in_addr) structure. The ARP request attempts to obtain the physical address that corresponds to this IPv4 address.

### `SrcIP` [in]

The source IPv4 address of the sender, in the form of an [IPAddr](https://learn.microsoft.com/windows/desktop/api/inaddr/ns-inaddr-in_addr) structure. This parameter is optional and is used to select the interface to send the request on for the ARP entry. The caller may specify zero corresponding to the **INADDR_ANY** IPv4 address for this parameter.

### `pMacAddr` [out]

A pointer to an array of **ULONG** variables. This array must have at least two **ULONG** elements to hold an Ethernet or token ring physical address. The first six bytes of this array receive the physical address that corresponds to the IPv4 address specified by the *DestIP* parameter.

### `PhyAddrLen` [in, out]

On input, a pointer to a **ULONG** value that specifies the maximum buffer size, in bytes, the application has set aside to receive the physical address or MAC address. The buffer size should be at least 6 bytes for an Ethernet or token ring physical address

The buffer to receive the physical address is pointed to by the *pMacAddr* parameter.

On successful output, this parameter points to a value that specifies the number of bytes written to the buffer pointed to by the *pMacAddr*.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_BAD_NET_NAME** | The network name cannot be found. This error is returned on Windows Vista and later when an ARP reply to the [SendARP](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-sendarp) request was not received. This error occurs if the destination IPv4 address could not be reached because it is not on the same subnet or the destination computer is not operating. |
| **ERROR_BUFFER_OVERFLOW** | The file name is too long. This error is returned on Windows Vista if the **ULONG** value pointed to by the *PhyAddrLen* parameter is less than 6, the size required to store a complete physical address. |
| **ERROR_GEN_FAILURE** | A device attached to the system is not functioning. This error is returned on Windows Server 2003 and earlier when an ARP reply to the [SendARP](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-sendarp) request was not received. This error can occur if destination IPv4 address could not be reached because it is not on the same subnet or the destination computer is not operating. |
| **ERROR_INVALID_PARAMETER** | One of the parameters is invalid. This error is returned on Windows Server 2003 and earlier if either the *pMacAddr* or *PhyAddrLen* parameter is a **NULL** pointer. |
| **ERROR_INVALID_USER_BUFFER** | The supplied user buffer is not valid for the requested operation. This error is returned on Windows Server 2003 and earlier if the **ULONG** value pointed to by the *PhyAddrLen* parameter is zero. |
| **ERROR_NOT_FOUND** | Element not found. This error is returned on Windows Vista if the *SrcIp* parameter does not specify a source IPv4 address on an interface on the local computer or the **INADDR_ANY** IP address (an IPv4 address of 0.0.0.0). |
| **ERROR_NOT_SUPPORTED** | The [SendARP](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-sendarp) function is not supported by the operating system running on the local computer. |
| **Other** | If the function fails, use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error. |

## Remarks

The **SendARP** function is used to request the physical hardware address (sometimes referred to as the MAC address) that corresponds to a specified destination IPv4 address. If the information requested is not in the ARP table on the local computer, then the **SendARP** function will cause an ARP request to be sent to obtain the physical address. If the function is successful, the physical address that corresponds to the specified destination IPv4 address is returned in the array pointed to by the *pMacAddr* parameter.

The physical address of an IPv4 address is only available if the destination IPv4 address is on the local subnet (the IPv4 address can be reached directly without going through any routers). The **SendARP** function will fail if the destination IPv4 address is not on the local subnet.

If the **SendARP** function is successful on Windows Vista and later, the ARP table on the local computer is updated with the results. If the **SendARP** function is successful on Windows Server 2003 and earlier, the ARP table on the local computer is not affected.

The **SendARP** function on Windows Vista and later returns different error return values than the **SendARP** function on Windows Server 2003 and earlier.

 On Windows Vista and later, a **NULL** pointer passed as the *pMacAddr* or *PhyAddrLen* parameter to the **SendARP** function causes an access violation and the application is terminated. If an error occurs on Windows Vista and later and **ERROR_BAD_NET_NAME**, **ERROR_BUFFER_OVERFLOW**, or **ERROR_NOT_FOUND** is returned, the **ULONG** value pointed to by the *PhyAddrLen* parameter is set to zero. If the **ULONG** value pointed to by the *PhyAddrLen* parameter is less than 6 on Windows Vista and later, **SendARP** function returns **ERROR_BUFFER_OVERFLOW** indicating the buffer to receive the physical address is too small. If the *SrcIp* parameter specifies an IPv4 address that is not an interface on the local computer, the **SendARP** function on Windows Vista and later returns **ERROR_NOT_FOUND**.

 On Windows Server 2003 and earlier, a **NULL** pointer passed as the *pMacAddr* or *PhyAddrLen* parameter to the **SendARP** function returns **ERROR_INVALID_PARAMETER**. If an error occurs on Windows Server 2003 and earlier and **ERROR_GEN_FAILURE** or **ERROR_INVALID_USER_BUFFER** is returned, the **ULONG** value pointed to by the *PhyAddrLen* parameter is set to zero. If the **ULONG** value pointed to by the *PhyAddrLen* parameter is less than 6 on Windows Server 2003 and earlier, the **SendARP** function does not return an error but only returns part of the hardware address in the array pointed to by the *pMacAddr* parameter. So if the value pointed to by the *PhyAddrLen* parameter is 4, then only the first 4 bytes of the hardware address are returned in the array pointed to by the *pMacAddr* parameter. If the *SrcIp* parameter specifies an IPv4 address that is not an interface on the local computer, the **SendARP** function on Windows Server 2003 and earlier ignores the *SrcIp* parameter and uses an IPv4 address on the local computer for the source IPv4 address.

The [GetIpNetTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getipnettable) function retrieves the ARP table on the local computer that maps IPv4 addresses to physical addresses.

The [CreateIpNetEntry](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-createipnetentry) function creates an ARP entry in the ARP table on the local computer.

The [DeleteIpNetEntry](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-deleteipnetentry) function deletes an ARP entry from the ARP table on the local computer.

The [SetIpNetEntry](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-setipnetentry) function modifies an existing ARP entry in the ARP table on the local computer.

The [FlushIpNetTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-flushipnettable) function deletes all ARP entries for the specified interface from the ARP table on the local computer.

On Windows Vista and later, the [ResolveIpNetEntry2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-resolveipnetentry2) function can used to replace the **SendARP** function. An ARP request is sent if the **Address** member of the [MIB_IPNET_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipnet_row2) structure passed to the **ResolveIpNetEntry2** function is an IPv4 address.

On Windows Vista, a new group of functions can be used to access, modify, and delete the ARP table entries when the **Address** member of the [MIB_IPNET_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipnet_row2) structure passed to these functions is an IPv4 address. The new functions include the following: [GetIpNetTable2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getipnettable2), [CreateIpNetEntry2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-createipnetentry2), [DeleteIpNetEntry2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-deleteipnetentry2), [FlushIpNetTable2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-flushipnettable2), and [SetIpNetEntry2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-setipnetentry2).

For information about the **IPAddr** data type, see
[Windows Data Types](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types). To convert an IP address between dotted decimal notation and **IPAddr** format, use the
[inet_addr](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-inet_addr) and
[inet_ntoa](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-inet_ntoa) functions.

#### Examples

The following code demonstrates how to obtain the hardware or media access control (MAC) address associated with a specified IPv4 address.

```cpp
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include <winsock2.h>
#include <iphlpapi.h>
#include <stdio.h>
#include <stdlib.h>

#pragma comment(lib, "iphlpapi.lib")
#pragma comment(lib, "ws2_32.lib")

void usage(char *pname)
{
    printf("Usage: %s [options] ip-address\n", pname);
    printf("\t -h \t\thelp\n");
    printf("\t -l length \tMAC physical address length to set\n");
    printf("\t -s src-ip \tsource IP address\n");
    exit(1);
}

int __cdecl main(int argc, char **argv)
{
    DWORD dwRetVal;
    IPAddr DestIp = 0;
    IPAddr SrcIp = 0;       /* default for src ip */
    ULONG MacAddr[2];       /* for 6-byte hardware addresses */
    ULONG PhysAddrLen = 6;  /* default to length of six bytes */

    char *DestIpString = NULL;
    char *SrcIpString = NULL;

    BYTE *bPhysAddr;
    unsigned int i;

    if (argc > 1) {
        for (i = 1; i < (unsigned int) argc; i++) {
            if ((argv[i][0] == '-') || (argv[i][0] == '/')) {
                switch (tolower(argv[i][1])) {
                case 'l':
                    PhysAddrLen = (ULONG) atol(argv[++i]);
                    break;
                case 's':
                    SrcIpString = argv[++i];
                    SrcIp = inet_addr(SrcIpString);
                    break;
                case 'h':
                default:
                    usage(argv[0]);
                    break;
                }               /* end switch */
            } else
                DestIpString = argv[i];
        }                       /* end for */
    } else
        usage(argv[0]);

    if (DestIpString == NULL || DestIpString[0] == '\0')
        usage(argv[0]);

    DestIp = inet_addr(DestIpString);

    memset(&MacAddr, 0xff, sizeof (MacAddr));

    printf("Sending ARP request for IP address: %s\n", DestIpString);

    dwRetVal = SendARP(DestIp, SrcIp, &MacAddr, &PhysAddrLen);

    if (dwRetVal == NO_ERROR) {
        bPhysAddr = (BYTE *) & MacAddr;
        if (PhysAddrLen) {
            for (i = 0; i < (int) PhysAddrLen; i++) {
                if (i == (PhysAddrLen - 1))
                    printf("%.2X\n", (int) bPhysAddr[i]);
                else
                    printf("%.2X-", (int) bPhysAddr[i]);
            }
        } else
            printf
                ("Warning: SendArp completed successfully, but returned length=0\n");

    } else {
        printf("Error: SendArp failed with error: %d", dwRetVal);
        switch (dwRetVal) {
        case ERROR_GEN_FAILURE:
            printf(" (ERROR_GEN_FAILURE)\n");
            break;
        case ERROR_INVALID_PARAMETER:
            printf(" (ERROR_INVALID_PARAMETER)\n");
            break;
        case ERROR_INVALID_USER_BUFFER:
            printf(" (ERROR_INVALID_USER_BUFFER)\n");
            break;
        case ERROR_BAD_NET_NAME:
            printf(" (ERROR_GEN_FAILURE)\n");
            break;
        case ERROR_BUFFER_OVERFLOW:
            printf(" (ERROR_BUFFER_OVERFLOW)\n");
            break;
        case ERROR_NOT_FOUND:
            printf(" (ERROR_NOT_FOUND)\n");
            break;
        default:
            printf("\n");
            break;
        }
    }

    return 0;
}

```

## See also

[CreateIpNetEntry](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-createipnetentry)

[CreateIpNetEntry2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-createipnetentry2)

[CreateProxyArpEntry](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-createproxyarpentry)

[DeleteIpNetEntry](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-deleteipnetentry)

[DeleteIpNetEntry2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-deleteipnetentry2)

[DeleteProxyArpEntry](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-deleteproxyarpentry)

[FlushIpNetTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-flushipnettable)

[FlushIpNetTable2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-flushipnettable2)

[GetIpNetEntry2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getipnetentry2)

[GetIpNetTable2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getipnettable2)

[IP Helper
Function Reference](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-function-reference)

[IP Helper
Start Page](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-start-page)

[IPAddr](https://learn.microsoft.com/windows/desktop/api/inaddr/ns-inaddr-in_addr)

[ResolveIpNetEntry2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-resolveipnetentry2)

[SetIpNetEntry](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-setipnetentry)

[SetIpNetEntry2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-setipnetentry2)