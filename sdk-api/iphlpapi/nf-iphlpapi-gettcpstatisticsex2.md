# GetTcpStatisticsEx2 function

## Description

The
**GetTcpStatisticsEx2** function retrieves the Transmission Control Protocol (TCP) statistics for the current computer. The
**GetTcpStatisticsEx2** function differs from the
[GetTcpStatisticsEx](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-gettcpstatisticsex) function in that
it uses a new output structure that contains 64-bit counters, rather than 32-bit counters.

## Parameters

### `Statistics` [out]

A pointer to a
[MIB_TCPSTATS2](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcpstats_lh) structure that receives the TCP statistics for the local computer.

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

[IP Helper Function Reference](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-function-reference)

[IP Helper Start Page](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-start-page)