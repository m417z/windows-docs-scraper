# GetBestInterfaceEx function

## Description

The
**GetBestInterfaceEx** function retrieves the index of the interface that has the best route to the specified IPv4 or IPv6 address.

## Parameters

### `pDestAddr` [in]

The destination IPv6 or IPv4 address for which to retrieve the interface with the best route, in the form of a [sockaddr](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2) structure.

### `pdwBestIfIndex` [out]

A pointer to the index of the interface with the best route to the IPv6 or IPv4 address specified by *pDestAddr*.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_CAN_NOT_COMPLETE** | The operation could not be completed. |
| **ERROR_INVALID_PARAMETER** | An invalid parameter was passed to the function. This error is returned if a **NULL** pointer is passed in the *pdwBestIfIndex* parameter or if the *pDestAddr*  or *pdwBestIfIndex* parameters point to memory that cannot be accessed. This error can also be returned if the *pdwBestIfIndex* parameter points to memory that can't be written to. |
| **ERROR_NOT_SUPPORTED** | The request is not supported. This error is returned if no IPv4 stack is on the local computer and an IPv4 address was specified in the *pDestAddr* parameter or no IPv6 stack is on the local computer and an IPv6 address was specified in the *pDestAddr* parameter. |
| **Other** | Use the [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) function to obtain the message string for the returned error. |

## Remarks

The **GetBestInterfaceEx** function differs from the [GetBestInterface](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getbestinterface) function in that it can be used with either IPv4 or IPv6 addresses.

The **Family** member of the sockaddr structure pointed to by the *pDestAddr* parameter must be set to one of the following values: **AF_INET** or **AF_INET6**.

On Windows Vista and later, the *pdwBestIfIndex* parameter is treated internally by IP Helper as a pointer to a **NET_IFINDEX** datatype.

## See also

[GetBestInterface](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getbestinterface)

[IP Helper Function Reference](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-function-reference)

[IP Helper Start Page](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-start-page)

[MIB_BEST_IF](https://learn.microsoft.com/windows/desktop/api/iprtrmib/ns-iprtrmib-mib_best_if)

[sockaddr](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2)