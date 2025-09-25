# GetBestRoute2 function

## Description

The
**GetBestRoute2** function retrieves the IP route entry on the local computer for the best route to the specified destination IP address.

## Parameters

### `InterfaceLuid` [in, optional]

The locally unique identifier (LUID) to specify the network interface associated with an IP route entry.

### `InterfaceIndex` [in]

The local index value to specify the network interface associated with an IP route entry. This index value may change when a network adapter is disabled and then enabled, or under other circumstances, and should not be considered persistent.

### `SourceAddress` [in]

The source IP address. This parameter may be omitted and passed as a **NULL** pointer.

### `DestinationAddress` [in]

The destination IP address.

### `AddressSortOptions` [in]

A set of options that affect how IP addresses are sorted. This parameter is not currently used.

### `BestRoute` [out]

A pointer to the [MIB_IPFORWARD_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipforward_row2) for the best route from the source IP address to the destination IP address.

### `BestSourceAddress` [out]

A pointer to the best source IP address.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | An invalid parameter was passed to the function. This error is returned if a **NULL** pointer is passed in the *DestinationAddress*, *BestSourceAddress*, or the *BestRoute* parameter. This error is also returned if the *DestinationAddress* parameter does not specify an IPv4 or IPv6 address and family. |
| **ERROR_FILE_NOT_FOUND** | The specified interface could not be found. This error is returned if the network interface specified by the *InterfaceLuid* or *InterfaceIndex* parameter could not be found. |
| **ERROR_NOT_SUPPORTED** | The request is not supported. This error is returned if no IPv4 stack is on the local computer and an IPv4 address and family was specified in the *DestinationAddress* parameter. This error is also returned if no IPv6 stack is on the local computer and an IPv6 address and family was specified in the *DestinationAddress* parameter. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error. |

## Remarks

The **GetBestRoute2** function is defined on Windows Vista and later.

The **GetBestRoute2** function is used to retrieve a [MIB_IPFORWARD_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipforward_row2) structure entry for the best route from a source IP address to a destination IP address.

On input, the *DestinationAddress* parameter must be initialized to a valid IPv4 or IPv6 address and family. On input, the *SourceAddress* parameter may be initialized to the preferred IPv4 or IPv6 address and family. In addition, at least one of the following parameters must be initialized: the *InterfaceLuid* or *InterfaceIndex*.

The parameters are used in the order listed above. So if the *InterfaceLuid* is specified, then this member is used to determine the interface. If no value was set for the *InterfaceLuid* member (the values of this member was set to zero), then the *InterfaceIndex* member is next used to determine the interface.

On output when the call is successful, **GetBestRoute2** retrieves and [MIB_IPFORWARD_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipforward_row2) structure for the best route from the source IP address the destination IP address.

## See also

[CreateIpForwardEntry2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-createipforwardentry2)

[DeleteIpForwardEntry2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-deleteipforwardentry2)

[GetIpForwardEntry2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getipforwardentry2)

[GetIpForwardTable2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getipforwardtable2)

[InitializeIpForwardEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-initializeipforwardentry)

[MIB_IPFORWARD_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipforward_row2)

[MIB_IPFORWARD_TABLE2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipforward_table2)

[NotifyRouteChange2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-notifyroutechange2)

[SetIpForwardEntry2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-setipforwardentry2)