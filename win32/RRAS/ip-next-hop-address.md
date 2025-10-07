# IP\_NEXT\_HOP\_ADDRESS structure

\[This API has been superseded by the [Routing Table Manager Version 2](https://learn.microsoft.com/windows/win32/rras/about-routing-table-manager-version-2) API and will not be available beyond Windows Server 2003. Applications should use the Routing Table Manager Version 2 API.\]

The **IP\_NEXT\_HOP\_ADDRESS** structure contains the address for the next-hop router for an IP route.

## Members

**N\_NetNumber**

Specifies the IP network address expressed as an IP address in machine-byte order.

**N\_NetMask**

Specifies the network mask. Apply this mask to the IP address in order to extract the network address. The network mask is in machine-byte order.

## Remarks

The **IP\_NEXT\_HOP\_ADDRESS** structure is a typedef of the [**IP\_NETWORK**](https://learn.microsoft.com/windows/win32/rras/ip-network) structure. The typedef is in Rtm.h.

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------|
| Minimum supported client<br> | None supported<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| End of server support<br> | Windows Server 2003<br> |
| Header<br> | Rtm.h |

## See also

[Routing Table Manager Version 1 Reference](https://learn.microsoft.com/windows/win32/rras/routing-table-manager-version-1-reference)

[Routing Table Manager Version 1 Structures](https://learn.microsoft.com/windows/win32/rras/routing-table-manager-version-1-structures)

[**IP\_NETWORK**](https://learn.microsoft.com/windows/win32/rras/ip-network)

[**RTM\_IP\_ROUTE**](https://learn.microsoft.com/windows/win32/rras/rtm-ip-route)

