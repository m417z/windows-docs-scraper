# GetTcpStatistics function

## Description

The
**GetTcpStatistics** function retrieves the TCP statistics for the local computer.

## Parameters

### `Statistics` [out]

A pointer to a
[MIB_TCPSTATS](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcpstats_lh) structure that receives the TCP statistics for the local computer.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | The *pStats* parameter is **NULL**, or [GetTcpStatistics](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-gettcpstatistics) is unable to write to the memory pointed to by the *pStats* parameter. |
| **Other** | Use the [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) function to obtain the message string for the returned error. |

## Remarks

The
**GetTcpStatistics** function returns the TCP statistics for IPv4 on the current computer. On Windows XP and later, the [GetTcpStatisticsEx](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-gettcpstatisticsex) can be used to obtain the TCP statistics for either IPv4 or IPv6.

#### Examples

The following example retrieves the TCP statistics for the local computer and prints some values from the returned data.

```cpp
//#include <windows.h>
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
    PMIB_TCPSTATS pTCPStats;
    DWORD dwRetVal = 0;

    pTCPStats = (MIB_TCPSTATS*) MALLOC (sizeof(MIB_TCPSTATS));
    if (pTCPStats == NULL) {
        printf("Error allocating memory\n");
        return 1;
    }

    if ((dwRetVal = GetTcpStatistics(pTCPStats)) == NO_ERROR) {
      printf("\tActive Opens: %ld\n", pTCPStats->dwActiveOpens);
      printf("\tPassive Opens: %ld\n", pTCPStats->dwPassiveOpens);
      printf("\tSegments Recv: %ld\n", pTCPStats->dwInSegs);
      printf("\tSegments Xmit: %ld\n", pTCPStats->dwOutSegs);
      printf("\tTotal # Conxs: %ld\n", pTCPStats->dwNumConns);
    }
    else {
      printf("GetTcpStatistics failed with error: %ld\n", dwRetVal);

      LPVOID lpMsgBuf;
      if (FormatMessage( FORMAT_MESSAGE_ALLOCATE_BUFFER |
        FORMAT_MESSAGE_FROM_SYSTEM |
        FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL,
        dwRetVal,
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
        (LPTSTR) &lpMsgBuf,
        0,
        NULL )) {
        printf("\tError: %s", lpMsgBuf);
      }
      LocalFree( lpMsgBuf );
    }

    if (pTCPStats)
        FREE (pTCPStats);
}

```

## See also

[GetIcmpStatistics](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-geticmpstatistics)

[GetIpStatistics](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getipstatistics)

[GetTcpStatisticsEx](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-gettcpstatisticsex)

[GetUdpStatistics](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getudpstatistics)

[IP Helper Function Reference](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-function-reference)

[IP Helper Start Page](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-start-page)

[MIB_TCPSTATS](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcpstats_lh)