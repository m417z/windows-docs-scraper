# RtmAddRoute function

\[This API has been superseded by the [Routing Table Manager Version 2](https://learn.microsoft.com/windows/win32/rras/about-routing-table-manager-version-2) API and will not be available beyond Windows Server 2003. Applications should use the Routing Table Manager Version 2 API.\]

The **RtmAddRoute** function adds a route entry or updates an existing route entry.

## Parameters

*ClientHandle* \[in\]

Handle that identifies the client, and therefore the routing protocol, that added or updated the route. Obtain this handle by calling [**RtmRegisterClient**](https://learn.microsoft.com/windows/win32/rras/rtmregisterclient).

*Route* \[in\]

Pointer to a protocol-family-specific structure that specifies the new or updated route. The following fields are used by the routing table manager to update the routing table:

| Value | Meaning |
|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|

**RR\_Network**

| Specifies the destination network number.<br> |
|

**RR\_InterfaceID**

| Specifies the index of the interface through which the route was received.<br> |
|

**RR\_NextHopAddress**

| Specifies the address of the next-hop router.<br> |
|

**RR\_FamilySpecificData**

| Specifies data that is specific to the protocol family. Although the data is transparent to the routing table manager, it is considered when comparing routes to determine if route information has changed. The data is also used to set metric values that are independent of the routing protocol. Consequently, this data is used to determine the best route for the destination network.<br> |
|

**RR\_ProtocolSpecificData**

| Specifies data which is specific to the routing protocol that supplied the route.<br> |
|

**RR\_TimeStamp**

| Specifies the current system time. This field is set by the routing table manager.<br> |

*TimeToLive* \[in\]

Specifies the number of seconds the specified route should be kept in the routing table. If this parameter is set to INFINITE, the route is kept until it is explicitly deleted. The current limit for *TimeToLive* is 2147483 sec (24+ days).

*Flags* \[out\]

Pointer to a **DWORD** variable. The value of this variable is set by the routing table manager. The value indicates the type of the change, and what information was returned in the provided buffers. This parameter is one of the following.

| Flags | Meaning |
|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|

**RTM\_NO\_CHANGE**

| The addition or update either did not change any of the significant route parameters, or the route entry affected is not the best route among the entries for the destination network.<br> |
|

**RTM\_ROUTE\_ADDED**

| The route was added for the destination network. The *CurBestRoute* parameter points to the information for the added route.<br> |
|

**RTM\_ROUTE\_CHANGED**

| At least one of the significant parameters was changed for the best route to the destination network. The significant parameters are: <br> Protocol identifier<br> Interface index<br> Next-hop address<br> Protocol-family-specific data (including route metrics)<br> |

The *PrevBestRoute* parameter points to the route information as it was before the change. The *CurBestRoute* parameter points to the current (that is, after-change) route information.

*CurBestRoute* \[out\]

Pointer to a structure that receives the current best-route information, if any. The type of the structure is specific to the protocol family, for example, IP or IPX.

This parameter is optional. If the caller specifies **NULL** for this parameter, the current best-route information is not returned.

*PrevBestRoute* \[out\]

Pointer to a structure that receives the previous best-route information, if any. The type of the structure is specific to the protocol family, for example, IP or IPX.

This parameter is optional. If the caller specifies **NULL** for this parameter the previous best-route information is not returned.

## Return value

The return value is one of the following codes.

| Value | Description |
|-------------------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------|
| **NO\_ERROR** | The route was added or updated successfully.<br> |
| **ERROR\_INVALID\_HANDLE** | The client handle parameter is not a valid handle.<br> |
| **ERROR\_INVALID\_PARAMETER** | The route structure contains an invalid parameter.<br> |
| **ERROR\_NO\_SYSTEM\_RESOURCES** | There are insufficient resources to carry out the operation.<br> |
| **ERROR\_NOT\_ENOUGH\_MEMORY** | There is insufficient memory to allocate the route entry.<br> |

## Remarks

The function generates a route-change message if the best route to a destination network has changed as the result of this operation. However, the route-change message is not sent to the client that makes this call. Instead, relevant information is returned by this function directly to that client through the *Flags*, *CurBestRoute*, and *PrevBestRoute* parameters.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------------------------------|
| Minimum supported client<br> | None supported<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| End of server support<br> | Windows Server 2003<br> |
| Header<br> | Rtm.h |
| Library<br> | Rtm.lib |
| DLL<br> | Rtm.dll |

## See also

[Routing Table Manager Version 1 Reference](https://learn.microsoft.com/windows/win32/rras/routing-table-manager-version-1-reference)

[Routing Table Manager Version 1 Functions](https://learn.microsoft.com/windows/win32/rras/routing-table-manager-version-1-functions)

[**RtmDeleteRoute**](https://learn.microsoft.com/windows/win32/rras/rtmdeleteroute)

[**RtmDequeueRouteChangeMessage**](https://learn.microsoft.com/windows/win32/rras/rtmdequeueroutechangemessage)

