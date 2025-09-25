# GetIpStatisticsEx function

## Description

The
**GetIpStatisticsEx** function retrieves the Internet Protocol (IP) statistics for the current computer. The
**GetIpStatisticsEx** function differs from the
[GetIpStatistics](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getipstatistics) function in that
**GetIpStatisticsEx** also supports the Internet Protocol version 6 (IPv6) protocol family.

## Parameters

### `Statistics` [out]

A pointer to a
[MIB_IPSTATS](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipstats_lh) structure that receives the IP statistics for the local computer.

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

## Remarks

The **GetIpStatisticsEx** can be used to obtain the IP statistics for either IPv4 or IPv6 on the local computer.

The
[GetIpStatistics](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getipstatistics) function returns the statistics for only IPv4 on the local computer.

## See also

[GetIpStatistics](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getipstatistics)

[GetTcpStatisticsEx](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-gettcpstatisticsex)

[GetUdpStatisticsEx](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getudpstatisticsex)

[IP Helper Function Reference](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-function-reference)

[IP Helper Start Page](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-start-page)

[MIB_IPSTATS](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipstats_lh)