# GetBestInterface function

## Description

The
**GetBestInterface** function retrieves the index of the interface that has the best route to the specified IPv4 address.

## Parameters

### `dwDestAddr` [in]

The destination IPv4 address for which to retrieve the interface that has the best route, in the form of an [IPAddr](https://learn.microsoft.com/windows/desktop/api/inaddr/ns-inaddr-in_addr) structure.

### `pdwBestIfIndex` [out]

A pointer to a **DWORD** variable that receives the index of the interface that has the best route to the IPv4 address specified by *dwDestAddr*.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_CAN_NOT_COMPLETE** | The operation could not be completed. |
| **ERROR_INVALID_PARAMETER** | An invalid parameter was passed to the function. This error is returned if a **NULL** pointer is passed in the *pdwBestIfIndex* parameter or if the *pdwBestIfIndex* points to memory that cannot be written. |
| **ERROR_NOT_SUPPORTED** | The request is not supported. This error is returned if no IPv4 stack is on the local computer. |
| **Other** | Use the [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) function to obtain the message string for the returned error. |

## Remarks

The **GetBestInterface** function only works with IPv4 addresses. For use with IPv6 addresses, the [GetBestInterfaceEx](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getbestinterfaceex) must be used.

For information about the **IPAddr** data type, see
[Windows Data Types](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types). To convert an IP address between dotted decimal notation and **IPAddr** format, use the
[inet_addr](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-inet_addr) and
[inet_ntoa](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-inet_ntoa) functions.

On Windows Vista and later, the *pdwBestIfIndex* parameter is treated internally by IP Helper as a pointer to a **NET_IFINDEX** datatype.

## See also

[GetBestInterfaceEx](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getbestinterfaceex)

[GetBestRoute](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getbestroute)

[IP Helper Function Reference](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-function-reference)

[IP Helper Start Page](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-start-page)

[IPAddr](https://learn.microsoft.com/windows/desktop/api/inaddr/ns-inaddr-in_addr)

[MIB_BEST_IF](https://learn.microsoft.com/windows/desktop/api/iprtrmib/ns-iprtrmib-mib_best_if)

[Windows Data Types](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)