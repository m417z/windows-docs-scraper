# IP\_SPECIFIC\_DATA structure

\[This API has been superseded by the [Routing Table Manager Version 2](https://learn.microsoft.com/windows/win32/rras/about-routing-table-manager-version-2) API and will not be available beyond Windows Server 2003. Applications should use the Routing Table Manager Version 2 API.\]

The **IP\_SPECIFIC DATA** structure contains IP-specific data.

## Members

**FSD\_Type**

Specifies the route type as defined in [RFC 1354](https://learn.microsoft.com/windows/win32/rras/routing-protocols-request-for-comments). The following table shows the possible values for this member.

| Member | Meaning |
|------------------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|

**1**

| The route type is not specified. The type is different from those listed here.<br> |
|

**2**

| The route is invalid. Normally, this value is used to invalidate a route. However, since invalidation is not supported by the routing table manager, the route is still considered in best-route computations. Therefore, routing protocols should not use this value.<br> |
|

**3**

| The route is a local route, that is, the next hop is the final destination.<br> |
|

**4**

| The route is a remote route, that is, the next hop is not the final destination.<br> |

**FSD\_Policy**

Specifies the set of conditions that would cause the selection of a multi-path route. This member is typically in IP TOS format. For more information, see [RFC 1354](https://learn.microsoft.com/windows/win32/rras/routing-protocols-request-for-comments).

**FSD\_NextHopAS**

Specifies the autonomous system number of the next hop.

**FSD\_Priority**

Specifies a metric value. The routing table manager uses this value to compare this route entry to route entries obtained from other routing protocols. The value of this member is set by the routing table manager.

**FSD\_Metric**

Specifies a metric value. The routing table manager uses this value to compare this route entry to other route entries obtained from the same routing protocol. The value of this member is set by the routing protocol.

**FSD\_Metric1**

Specifies a routing-protocol-specific metric value. This metric value is documented in [RFC 1354](https://learn.microsoft.com/windows/win32/rras/routing-protocols-request-for-comments).

**FSD\_Metric2**

Specifies a routing-protocol-specific metric value. This metric value is documented in [RFC 1354](https://learn.microsoft.com/windows/win32/rras/routing-protocols-request-for-comments).

**FSD\_Metric3**

Specifies a routing-protocol-specific metric value. This metric value is documented in [RFC 1354](https://learn.microsoft.com/windows/win32/rras/routing-protocols-request-for-comments).

**FSD\_Metric4**

Specifies a routing-protocol-specific metric value. This metric value is documented in [RFC 1354](https://learn.microsoft.com/windows/win32/rras/routing-protocols-request-for-comments).

**FSD\_Metric5**

Specifies a routing-protocol-specific metric value. This metric value is documented in [RFC 1354](https://learn.microsoft.com/windows/win32/rras/routing-protocols-request-for-comments).

**FSD\_Flags**

Specifies whether the route is valid. The routing protocol should first clear these flags, then set the route as either valid or invalid. The routing protocol should use the macros **ClearRouteFlags()**, **SetRouteValid()**, and **ClearRouteValid()** to perform these operations. These macros are defined in Rtm.h.

## Remarks

The routing table manager uses the **FSD\_Priority** and **FSD\_Metric** members to compute the best route to a particular destination network.

The **FSD\_Metric\[1-5\]** members are for MIB II conformance. MIB II agents display only these metric values. They do not display the **FSD\_Metric** metric value. To have the **FSD\_Metric** displayed, the routing protocol should also store the value in one of the **FSD\_Metric\[1-5\]** members.

The routing table manager does not use the metric values in the **FSD\_Metric\[1-5\]** members when computing the best route to a destination network. Therefore, the routing protocol should ensure that the **FSD\_Metric** member has an appropriate metric value.

A routing protocol could use the **FSD\_Flags** to mark a route as invalid, if the route should not be used by other routing protocols.

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

[**RTM\_IP\_ROUTE**](https://learn.microsoft.com/windows/win32/rras/rtm-ip-route)

