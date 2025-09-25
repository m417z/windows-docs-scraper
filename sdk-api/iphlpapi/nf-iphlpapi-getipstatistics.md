# GetIpStatistics function

## Description

The
**GetIpStatistics** function retrieves the IP statistics for the current computer.

## Parameters

### `Statistics` [out]

A pointer to a
[MIB_IPSTATS](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipstats_lh) structure that receives the IP statistics for the local computer.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | The *pStats* parameter is **NULL**, or [GetIpStatistics](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getipstatistics) is unable to write to the memory pointed to by the *pStats* parameter. |
| **Other** | Use the [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) function to obtain the message string for the returned error. |

## Remarks

The
**GetIpStatistics** function returns the statistics for IPv4 on the current computer. On Windows XP and later, the [GetIpStatisticsEx](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getipstatisticsex) can be used to obtain the IP statistics for either IPv4 or IPv6.

#### Examples

The following example retrieves the IPv4 statistics for the local computer and prints values from the returned data.

```cpp
#ifndef UNICODE
#define UNICODE
#endif

#include <winsock2.h>
#include <ws2tcpip.h>
#include <iphlpapi.h>
#include <stdio.h>

#pragma comment(lib, "iphlpapi.lib")

#define MALLOC(x) HeapAlloc(GetProcessHeap(), 0, (x))
#define FREE(x) HeapFree(GetProcessHeap(), 0, (x))

/* Note: could also use malloc() and free() */

int main()
{

    DWORD dwRetval;
    MIB_IPSTATS *pStats;

    pStats = (MIB_IPSTATS *) MALLOC(sizeof (MIB_IPSTATS));

    if (pStats == NULL) {
        wprintf(L"Unable to allocate memory for MIB_IPSTATS\n");
        exit(1);
    }
    dwRetval = GetIpStatistics(pStats);
    if (dwRetval != NO_ERROR) {
        wprintf(L"GetIpStatistics call failed with %d\n", dwRetval);
        exit(1);
    } else {

        wprintf(L"IP forwarding: \t\t" );
        switch (pStats->dwForwarding) {
        case MIB_IP_FORWARDING:
            wprintf(L"Enabled\n");
            break;
        case MIB_IP_NOT_FORWARDING:
            wprintf(L"Disabled\n");
            break;
        default:
            wprintf(L"unknown value = %d\n", pStats->dwForwarding);
            break;
        }

        wprintf(L"Default initial TTL: \t\t\t\t\t%u\n", pStats->dwDefaultTTL);

        wprintf(L"Number of received datagrams: \t\t\t\t%u\n", pStats->dwInReceives);
        wprintf(L"Number of received datagrams with header errors: \t%u\n", pStats->dwInHdrErrors);
        wprintf(L"Number of received datagrams with address errors: \t%u\n", pStats->dwInAddrErrors);

        wprintf(L"Number of datagrams forwarded: \t\t\t\t%ld\n", pStats->dwForwDatagrams);

        wprintf(L"Number of received datagrams with an unknown protocol: \t%u\n", pStats->dwInUnknownProtos);
        wprintf(L"Number of received datagrams discarded: \t\t%u\n", pStats->dwInDiscards);
        wprintf(L"Number of received datagrams delivered: \t\t%u\n", pStats->dwInDelivers);

        wprintf(L"Number of outgoing datagrams requested to transmit: \t%u\n", pStats->dwOutRequests);
        wprintf(L"Number of outgoing datagrams discarded for routing: \t%u\n", pStats->dwRoutingDiscards);
        wprintf(L"Number of outgoing datagrams discarded: \t\t%u\n", pStats->dwOutDiscards);
        wprintf(L"Number of outgoing datagrams with no route to destination discarded: %u\n", pStats->dwOutNoRoutes);

        wprintf(L"Fragment reassembly timeout: \t\t\t\t%u\n", pStats->dwReasmTimeout);
        wprintf(L"Number of datagrams that required reassembly: \t\t%u\n", pStats->dwReasmReqds);
        wprintf(L"Number of datagrams successfully reassembled: \t\t%u\n", pStats->dwReasmOks);
        wprintf(L"Number of datagrams that could not be reassembled: \t%u\n", pStats->dwReasmFails);

        wprintf(L"Number of datagrams fragmented successfully: \t\t%u\n", pStats->dwFragOks);
        wprintf(L"Number of datagrams not fragmented and discarded: \t%u\n", pStats->dwFragFails);
        wprintf(L"Number of fragments created: \t\t\t\t%u\n", pStats->dwFragCreates);

        wprintf(L"Number of interfaces: \t\t\t\t\t%u\n", pStats->dwNumIf);
        wprintf(L"Number of IP addresses: \t\t\t\t%u\n", pStats->dwNumAddr);
        wprintf(L"Number of routes: \t\t\t\t\t%u\n", pStats->dwNumRoutes);
    }

// Free memory allocated for the MIB_IPSTATS structure
    if (pStats)
        FREE(pStats);

    return 0;
}

```

## See also

[GetIcmpStatistics](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-geticmpstatistics)

[GetIpStatisticsEx](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getipstatisticsex)

[GetTcpStatistics](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-gettcpstatistics)

[GetUdpStatistics](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getudpstatistics)

[IP Helper Function Reference](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-function-reference)

[IP Helper Start Page](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-start-page)

[MIB_IPSTATS](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipstats_lh)