# ResolveIpNetEntry2 function

## Description

The
**ResolveIpNetEntry2** function resolves the physical address for a neighbor IP address entry on the local computer.

## Parameters

### `Row` [in, out]

A pointer to a
[MIB_IPNET_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipnet_row2) structure entry for a neighbor IP address entry. On successful return, this structure will be updated with the properties for neighbor IP address.

### `SourceAddress` [in, optional]

A pointer to a
an optional source IP address used to select the interface to send the requests on for the neighbor IP address entry.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_BAD_NET_NAME** | The network name cannot be found. This error is returned if the network with the neighbor IP address is unreachable. |
| **ERROR_INVALID_PARAMETER** | An invalid parameter was passed to the function. This error is returned if a **NULL** pointer is passed in the *Row* parameter, the **Address** member of the [MIB_IPNET_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipnet_row2) pointed to by the *Row* parameter was not set to a valid IPv4 or IPv6 address, or both the **InterfaceLuid** or **InterfaceIndex** members of the **MIB_IPNET_ROW2** pointed to by the *Row* parameter were unspecified. This error is also returned if a loopback address was passed in the **Address** member. |
| **ERROR_NOT_FOUND** | The specified interface could not be found. This error is returned if the network interface specified by the **InterfaceLuid** or **InterfaceIndex** member of the [MIB_IPNET_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipnet_row2) pointed to by the *Row* parameter could not be found. |
| **ERROR_NOT_SUPPORTED** | The request is not supported. This error is returned if no IPv4 stack is on the local computer and an IPv4 address was specified in the **Address** member of the [MIB_IPNET_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipnet_row2) pointed to by the *Row* parameter or no IPv6 stack is on the local computer and an IPv6 address was specified in the **Address** member. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error. |

## Remarks

The **ResolveIpNetEntry2** function is defined on Windows Vista and later.

The **ResolveIpNetEntry2** function is used to resolve the physical address for a neighbor IP address entry on a local computer. This function flushes any existing neighbor entry that matches the IP address on the interface and then resolves the physical address (MAC) address
by sending ARP requests for an IPv4 address or neighbor solicitation requests for an IPv6 address.
If the *SourceAddress* parameter is specified, the **ResolveIpNetEntry2** function will select the
interface with this source IP address to send the requests on.
If the *SourceAddress* parameter is not specified (NULL was passed in this parameter), the **ResolveIpNetEntry2** function will automatically select the
best interface to send the requests on.

The **Address** member in the [MIB_IPNET_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipnet_row2) structure pointed to by the *Row* parameter must be initialized to a valid IPv4 or IPv6 address and family. In addition, at least one of the following members in the **MIB_IPNET_ROW2** structure pointed to the *Row* parameter must be initialized to the interface: the **InterfaceLuid** or **InterfaceIndex**.

The fields are used in the order listed above. So if the **InterfaceLuid** is specified, then this member is used to determine the interface on which to add the unicast IP address. If no value was set for the **InterfaceLuid** member (the values of this member was set to zero), then the **InterfaceIndex** member is next used to determine the interface.

If the IP address passed in the **Address** member of the [MIB_IPNET_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipnet_row2) pointed to by the *Row* parameter is a duplicate of an existing neighbor IP address on the interface, the **ResolveIpNetEntry2** function will flush the existing entry before resolving the IP address.

On output when the call is successful, **ResolveIpNetEntry2** retrieves the other properties for the neighbor IP address and fills out the [MIB_IPNET_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipnet_row2) structure pointed to by the *Row* parameter. The **PhysicalAddress** and **PhysicalAddressLength** members in the **MIB_IPNET_ROW2** structure pointed to by the *Row* parameter will be initialized to a valid physical address.

## See also

[CreateIpNetEntry2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-createipnetentry2)

[DeleteIpNetEntry2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-deleteipnetentry2)

[FlushIpNetTable2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-flushipnettable2)

[GetIpNetEntry2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getipnetentry2)

[GetIpNetTable2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getipnettable2)

[MIB_IPNET_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipnet_row2)

[MIB_IPNET_TABLE2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipnet_table2)

[SOCKADDR_INET](https://learn.microsoft.com/windows/desktop/api/ws2ipdef/ns-ws2ipdef-sockaddr_inet)

[SetIpNetEntry2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-setipnetentry2)