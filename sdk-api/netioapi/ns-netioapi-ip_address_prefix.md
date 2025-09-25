# IP_ADDRESS_PREFIX structure

## Description

The **IP_ADDRESS_PREFIX** structure stores an IP address prefix.

## Members

### `Prefix`

The prefix or network part of IP the address represented as an IP address.

The [SOCKADDR_INET](https://learn.microsoft.com/windows/desktop/api/ws2ipdef/ns-ws2ipdef-sockaddr_inet) union is defined in the *Ws2ipdef.h* header.

### `PrefixLength`

The length, in bits, of the prefix or network part of the IP address. For a unicast IPv4 address, any value greater than 32 is an illegal value. For a unicast IPv6 address, any value greater than 128 is an illegal value.
A value of 255 is commonly used to represent an illegal value.

## Remarks

The **IP_ADDRESS_PREFIX** structure is defined on Windows Vista and later.

The **IP_ADDRESS_PREFIX** structure is the data type of the **DestinationPrefix** member in the [MIB_IPFORWARD_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipforward_row2) structure. A number of functions use the **MIB_IPFORWARD_ROW2** structure including [CreateIpForwardEntry2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-createipforwardentry2), [DeleteIpForwardEntry2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-deleteipforwardentry2), [GetBestRoute2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getbestroute2), [GetIpForwardEntry2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getipforwardentry2), [GetIpForwardTable2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getipforwardtable2), [InitializeIpForwardEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-initializeipforwardentry), [NotifyRouteChange2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-notifyroutechange2), and [SetIpForwardEntry2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-setipforwardentry2).

## See also

[CreateIpForwardEntry2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-createipforwardentry2)

[DeleteIpForwardEntry2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-deleteipforwardentry2)

[GetBestRoute2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getbestroute2)

[GetIpForwardEntry2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getipforwardentry2)

[GetIpForwardTable2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getipforwardtable2)

[InitializeIpForwardEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-initializeipforwardentry)

[MIB_IPFORWARD_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipforward_row2)

[NotifyRouteChange2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-notifyroutechange2)

[SOCKADDR_INET](https://learn.microsoft.com/windows/desktop/api/ws2ipdef/ns-ws2ipdef-sockaddr_inet)

[SetIpForwardEntry2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-setipforwardentry2)