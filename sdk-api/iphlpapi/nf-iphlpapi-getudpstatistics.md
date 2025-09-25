# GetUdpStatistics function

## Description

The
**GetUdpStatistics** function retrieves the User Datagram Protocol (UDP) statistics for the local computer.

## Parameters

### `Stats` [out]

Pointer to a
[MIB_UDPSTATS](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udpstats) structure that receives the UDP statistics for the local computer.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, use
[FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error.

## Remarks

**Windows Server 2003 and Windows XP:** Use the
[GetUdpStatisticsEx](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getudpstatisticsex) function to obtain the UDP statistics for the IPv6 protocol.

## See also

[GetIcmpStatistics](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-geticmpstatistics)

[GetIpStatistics](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getipstatistics)

[GetTcpStatistics](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-gettcpstatistics)

[GetUdpStatisticsEx](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getudpstatisticsex)

[IP Helper Function Reference](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-function-reference)

[IP Helper Start Page](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-start-page)

[MIB_UDPSTATS](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udpstats)