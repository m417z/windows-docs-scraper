# RTM\_IP\_ROUTE structure

\[This API has been superseded by the [Routing Table Manager Version 2](https://learn.microsoft.com/windows/win32/rras/about-routing-table-manager-version-2) API and will not be available beyond Windows Server 2003. Applications should use the Routing Table Manager Version 2 API.\]

The **RTM\_IP\_ROUTE** structure contains information that describes a route owned by the IP protocol family.

## Members

**RR\_TimeStamp**

Specifies the time that the route entry was created or last updated. This member is set by the routing table manager. The time is expressed as a FILETIME structure.

**RR\_RoutingProtocol**

Specifies the routing protocol that added the route.

**RR\_InterfaceID**

Specifies the interface through which the route was obtained.

**RR\_ProtocolSpecificData**

Specifies a [**PROTOCOL\_SPECIFIC\_DATA**](https://learn.microsoft.com/windows/win32/rras/protocol-specific-data) structure that contains memory reserved for routing-protocol-specific data.

**RR\_Network**

Specifies an [**IP\_NETWORK**](https://learn.microsoft.com/windows/win32/rras/ip-network) structure that contains an IP network address.

**RR\_NextHopAddress**

Specifies an [**IP\_NEXT\_HOP\_ADDRESS**](https://learn.microsoft.com/windows/win32/rras/ip-next-hop-address) structure that contains the address of the next-hop router.

**RR\_FamilySpecificData**

Specifies an [**IP\_SPECIFIC\_DATA**](https://learn.microsoft.com/windows/win32/rras/ip-specific-data) structure that contains IP protocol-family-specific data.

## Remarks

The members of the **RTM\_IP\_ROUTE** structure are all **DWORD** aligned.

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

[**IP\_NEXT\_HOP\_ADDRESS**](https://learn.microsoft.com/windows/win32/rras/ip-next-hop-address)

[**IP\_SPECIFIC\_DATA**](https://learn.microsoft.com/windows/win32/rras/ip-specific-data)

