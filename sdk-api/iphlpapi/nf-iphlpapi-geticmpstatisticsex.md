# GetIcmpStatisticsEx function

## Description

The **GetIcmpStatisticsEx** function retrieves Internet Control Message Protocol (ICMP) statistics for the local computer. The **GetIcmpStatisticsEx** function is capable of retrieving IPv6 ICMP statistics.

## Parameters

### `Statistics` [out]

A pointer to a
[MIB_ICMP_EX](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_icmp_ex_xpsp1) structure that contains ICMP statistics for the local computer.

### `Family` [in]

The protocol family for which to retrieve ICMP statistics. Must be one of the following:

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

The [GetIpStatisticsEx](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getipstatisticsex) can be used to obtain the ICMP statistics for either IPv4 or IPv6 on the local computer.

The
[GetIcmpStatistics](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-geticmpstatistics) function returns the ICMP statistics for only IPv4 on the local computer.

## See also

[GetIcmpStatistics](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-geticmpstatistics)

[GetTcpStatisticsEx](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-gettcpstatisticsex)

[GetUdpStatisticsEx](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getudpstatisticsex)

[IP Helper Function Reference](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-function-reference)

[IP Helper Start Page](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-start-page)

[MIB_ICMP_EX](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_icmp_ex_xpsp1)