# RTM\_IPX\_ROUTE structure

\[This API has been superseded by the [Routing Table Manager Version 2](https://learn.microsoft.com/windows/win32/rras/about-routing-table-manager-version-2) API and will not be available beyond Windows Server 2003. Applications should use the Routing Table Manager Version 2 API.\]

The **RTM\_IPX\_ROUTE** structure contains information that describes a route for the IPX protocol family.

## Members

**RR\_TimeStamp**

Specifies the time that the route entry was created or last updated. This member is set by the routing table manager. The time is expressed as a FILETIME structure.

**RR\_RoutingProtocol**

Specifies the routing protocol that added the route.

**RR\_InterfaceID**

Specifies the interface through which the route was obtained.

**RR\_ProtocolSpecificData**

Specifies a [**PROTOCOL\_SPECIFIC\_DATA**](https://learn.microsoft.com/windows/win32/rras/protocol-specific-data) structure containing memory reserved for data specific to routing protocols.

**RR\_Network**

Specifies an [**IPX\_NETWORK**](https://learn.microsoft.com/windows/win32/rras/ipx-network) structure that contains an IP network address.

**RR\_NextHopAddress**

Specifies an [**IPX\_NEXT\_HOP\_ADDRESS**](https://learn.microsoft.com/windows/win32/rras/ipx-next-hop-address) structure that contains the address of the next-hop router.

**RR\_FamilySpecificData**

Specifies an [**IPX\_SPECIFIC\_DATA**](https://learn.microsoft.com/windows/win32/rras/ipx-specific-data) structure that contains data specific to the IPX protocol family.

## Remarks

The members of the **RTM\_IPX\_ROUTE** structure are all **DWORD** aligned.

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------|
| Minimum supported client<br> | None supported<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| End of server support<br> | Windows Server 2003<br> |
| Header<br> | Rtm.h |

## See also

[Routing Table Manager Version 1 Reference](https://learn.microsoft.com/windows/win32/rras/routing-table-manager-version-1-reference)

[Routing Table Manager Version\_1\_Structures](https://learn.microsoft.com/windows/win32/rras/routing-table-manager-version-1-structures)

[**IPX\_NETWORK**](https://learn.microsoft.com/windows/win32/rras/ipx-network)

[**IPX\_NEXT\_HOP\_ADDRESS**](https://learn.microsoft.com/windows/win32/rras/ipx-next-hop-address)

[**IPX\_SPECIFIC\_DATA**](https://learn.microsoft.com/windows/win32/rras/ipx-specific-data)

