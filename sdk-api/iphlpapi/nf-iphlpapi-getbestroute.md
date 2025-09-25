# GetBestRoute function

## Description

The
**GetBestRoute** function retrieves the best route to the specified destination IP address.

## Parameters

### `dwDestAddr` [in]

Destination IP address for which to obtain the best route.

### `dwSourceAddr` [in]

Source IP address. This IP address corresponds to an interface on the local computer. If multiple best routes to the destination address exist, the function selects the route that uses this interface.

This parameter is optional. The caller may specify zero for this parameter.

### `pBestRoute` [out]

Pointer to a
[MIB_IPFORWARDROW](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipforwardrow) structure containing the best route for the IP address specified by *dwDestAddr*.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, use
[FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error.

## See also

[GetBestInterface](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getbestinterface)

[IP Helper Function Reference](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-function-reference)

[IP Helper Start Page](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-start-page)

[MIB_IPFORWARDROW](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipforwardrow)