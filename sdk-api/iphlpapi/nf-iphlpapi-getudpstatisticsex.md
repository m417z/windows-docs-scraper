# GetUdpStatisticsEx function

## Description

The
**GetUdpStatisticsEx** function retrieves the User Datagram Protocol (UDP) statistics for the current computer. The
**GetUdpStatisticsEx** function differs from the
**GetUdpStatistics** function in that
**GetUdpStatisticsEx** also supports the Internet Protocol version 6 (IPv6) protocol family.

## Parameters

### `Statistics` [out]

A pointer to a
[MIB_UDPSTATS](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udpstats) structure that receives the UDP statistics for the local computer.

### `Family` [in]

The protocol family for which to retrieve statistics. This parameter must be one of the following values:

| Value | Meaning |
| --- | --- |
| **AF_INET** | Internet Protocol version 4 (IPv4). |
| **AF_INET6** | Internet Protocol version 6 (IPv6). |

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | The *pStats* parameter is **NULL** or does not point to valid memory, or the *dwFamily* parameter is not a valid value. |
| **ERROR_NOT_SUPPORTED** | This function is not supported on the operating system on which the function call was made. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error. |

## See also

[GetIpStatisticsEx](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getipstatisticsex)

[GetTcpStatisticsEx](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-gettcpstatisticsex)

[GetUdpStatistics](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getudpstatistics)

[IP Helper Function Reference](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-function-reference)

[IP Helper Start Page](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-start-page)

[MIB_UDPSTATS](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udpstats)