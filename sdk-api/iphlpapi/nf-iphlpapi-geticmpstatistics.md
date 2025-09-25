# GetIcmpStatistics function

## Description

The
**GetIcmpStatistics** function retrieves the Internet Control Message Protocol (ICMP) for IPv4 statistics for the local computer.

## Parameters

### `Statistics` [out]

A pointer to a
[MIB_ICMP](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_icmp) structure that receives the ICMP statistics for the local computer.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | The *pStats* parameter is **NULL**, or [GetIcmpStatistics](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-geticmpstatistics) is unable to write to the memory pointed to by the *pStats* parameter. |
| **Other** | Use the [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) function to obtain the message string for the returned error. |

## Remarks

The
**GetIcmpStatistics** function returns the ICMP statistics for IPv4 on the local computer. On Windows XP and later, the [GetIpStatisticsEx](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getipstatisticsex) can be used to obtain the ICMP statistics for either IPv4 or IPv6 on the local computer.

#### Examples

The following example retrieves the ICMP for IPv4 statistics for the local computer and prints some information from the returned data.

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

    DWORD dwRetVal = 0;
    PMIB_ICMP pIcmpStats;

    pIcmpStats = (MIB_ICMP *) MALLOC(sizeof (MIB_ICMP));
    if (pIcmpStats == NULL) {
        wprintf(L"Error allocating memory\n");
        return 1;
    }

    dwRetVal = GetIcmpStatistics(pIcmpStats);
    if (dwRetVal == NO_ERROR) {
        wprintf(L"Number of incoming ICMP messages: %ld\n",
                pIcmpStats->stats.icmpInStats.dwMsgs);
        wprintf(L"Number of incoming ICMP errors received: %ld\n",
                pIcmpStats->stats.icmpInStats.dwErrors);
        wprintf(L"Number of outgoing ICMP messages: %ld\n",
                pIcmpStats->stats.icmpOutStats.dwMsgs);
        wprintf(L"Number of outgoing ICMP errors sent: %ld\n",
                pIcmpStats->stats.icmpOutStats.dwErrors);
    } else {
        wprintf(L"GetIcmpStatistics failed with error: %ld\n", dwRetVal);
    }

    if (pIcmpStats)
        FREE(pIcmpStats);

    return 0;
}

```

## See also

[GetIpStatistics](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getipstatistics)

[GetIpStatisticsEx](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getipstatisticsex)

[GetTcpStatistics](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-gettcpstatistics)

[GetUdpStatistics](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getudpstatistics)

[IP Helper Function Reference](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-function-reference)

[IP Helper Start Page](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-start-page)

[MIB_ICMP](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_icmp)