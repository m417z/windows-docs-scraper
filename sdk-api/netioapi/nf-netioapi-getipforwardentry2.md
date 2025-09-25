# GetIpForwardEntry2 function

## Description

The
**GetIpForwardEntry2** function retrieves information for an IP route entry on the local computer.

## Parameters

### `Row` [in, out]

A pointer to a
[MIB_IPFORWARD_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipforward_row2) structure entry for an IP route entry. On successful return, this structure will be updated with the properties for the IP route entry.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | An invalid parameter was passed to the function. This error is returned if a **NULL** pointer is passed in the *Row* parameter, the **DestinationPrefix** member of the [MIB_IPFORWARD_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipforward_row2) pointed to by the *Row* parameter was not specified, the **NextHop** member of the **MIB_IPFORWARD_ROW2** pointed to by the *Row* parameter was not specified, or both the **InterfaceLuid** or **InterfaceIndex** members of the **MIB_IPFORWARD_ROW2** pointed to by the *Row* parameter were unspecified. |
| **ERROR_NOT_FOUND** | Element not found. This error is returned if the network interface specified by the **InterfaceLuid** or **InterfaceIndex** member of the [MIB_IPFORWARD_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipforward_row2) structure pointed to by the *Row* parameter does not match the IP address prefix and address family specified in the **DestinationPrefix** member in the **MIB_IPFORWARD_ROW2** structure. |
| **ERROR_NOT_SUPPORTED** | The request is not supported. This error is returned if no IPv4 stack is on the local computer and **AF_INET** was specified in the address family in the **DestinationPrefix** member of the [MIB_IPFORWARD_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipforward_row2) pointed to by the *Row* parameter. This error is also returned if no IPv6 stack is on the local computer and **AF_INET6** was specified for the address family in the **DestinationPrefix** member. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error. |

## Remarks

The **GetIpForwardEntry2** function is defined on Windows Vista and later.

The **GetIpForwardEntry2** function is used to retrieve a [MIB_IPFORWARD_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipforward_row2) structure entry.

On input, the **DestinationPrefix** member in the [MIB_IPFORWARD_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipforward_row2) structure pointed to by the *Row* parameter must be initialized to a valid IPv4 or IPv6 address prefix and family. On input, the **NextHop** member in the **MIB_IPFORWARD_ROW2** structure pointed to by the *Row* parameter must be initialized to a valid IPv4 or IPv6 address and family. In addition, at least one of the following members in the **MIB_IPFORWARD_ROW2** structure pointed to the *Row* parameter must be initialized: the **InterfaceLuid** or **InterfaceIndex**.

The fields are used in the order listed above. So if the **InterfaceLuid** is specified, then this member is used to determine the interface. If no value was set for the **InterfaceLuid** member (the values of this member was set to zero), then the **InterfaceIndex** member is next used to determine the interface.

On output when the call is successful, **GetIpForwardEntry2** retrieves the other properties for the IP route entry and fills out the [MIB_IPFORWARD_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipforward_row2) structure pointed to by the *Row* parameter.

The route metric offset specified in the **Metric** member of the [MIB_IPFORWARD_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipforward_row2) structure pointed to by *Row* parameter represents only part of the complete route metric. The complete metric is a combination of this route metric added to the interface metric specified in the **Metric** member of the [MIB_IPINTERFACE_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipinterface_row) structure of the associated interface. An application can retrieve the interface metric by calling the [GetIpInterfaceEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getipinterfaceentry) function.

The [GetIpForwardTable2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getipforwardtable2) function can be called to enumerate the IP route entries on a local computer.

## See also

[CreateIpForwardEntry2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-createipforwardentry2)

[DeleteIpForwardEntry2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-deleteipforwardentry2)

[GetBestRoute2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getbestroute2)

[GetIpForwardTable2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getipforwardtable2)

[GetIpInterfaceEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getipinterfaceentry)

[InitializeIpForwardEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-initializeipforwardentry)

[MIB_IPFORWARD_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipforward_row2)

[MIB_IPFORWARD_TABLE2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipforward_table2)

[MIB_IPINTERFACE_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipinterface_row)

[NotifyRouteChange2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-notifyroutechange2)

[SetIpForwardEntry2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-setipforwardentry2)