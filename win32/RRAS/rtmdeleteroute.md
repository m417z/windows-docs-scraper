# RtmDeleteRoute function

\[This API has been superseded by the [Routing Table Manager Version 2](https://learn.microsoft.com/windows/win32/rras/about-routing-table-manager-version-2) API and will not be available beyond Windows Server 2003. Applications should use the Routing Table Manager Version 2 API.\]

The **RtmDeleteRoute** function deletes a route entry.

## Parameters

*ClientHandle* \[in\]

Handle that identifies the client and therefore the routing protocol of the added or updated route. Obtain this handle by calling [**RtmRegisterClient**](https://learn.microsoft.com/windows/win32/rras/rtmregisterclient).

*Route* \[in\]

Pointer to a protocol-family-specific structure that specifies the new or updated route. The following fields are used by the routing table manager to update the routing table:

| Value | Meaning |
|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------|
|

**RR\_Network**

| Specifies the destination network number. <br> |
|

**RR\_InterfaceID**

| Specifies the index of the interface through which the route was received.<br> |
|

**RR\_NextHopAddress**

| Specifies the network address of the next-hop router.<br> |

*Flags* \[out\]

Pointer to a set of flags that indicate the type of the change message, and what information was placed in the provided buffers. This parameter is one of the following values.

| Flags | Meaning |
|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|

**RTM\_NO\_CHANGE**

| Deleting the route did not affect the best route to any destination network. In other words, another entry represents a route to the same destination network and has a lower metric.<br> |
|

**RTM\_ROUTE\_DELETED**

| The route deleted was the only route available for a particular destination network.<br> |
|

**RTM\_ROUTE\_CHANGED**

| After this route was deleted, another route became the best route to a particular destination network. *CurBestRoute* points to the information for the new best route.<br> |

*CurBestRoute* \[out\]

Pointer to a structure that receives the current best-route information, if any. The type of the structure is specific to the protocol family, for example, IP or IPX.

This parameter is optional. If the caller specifies **NULL** for this parameter, the current best-route information is not returned.

## Return value

If the function succeeds, the return value is **NO\_ERROR**.

If the function fails, the return value is one of the following error codes.

| Value | Description |
|-------------------------------------------------------------------------------------------------------------|--------------------------------------------------------------------------------------------------------|
| **ERROR\_INVALID\_HANDLE** | The client handle parameter is not a valid handle.<br> |
| **ERROR\_INVALID\_PARAMETER** | The route structure pointed to by the *Route* parameter contains a member value.<br> |
| **ERROR\_NO\_SUCH\_ROUTE** | There are no entries in the routing table that match the parameters of the specified route.<br> |
| **ERROR\_NO\_SYSTEM\_RESOURCES** | There are insufficient resources to perform the operation. <br> |

## Remarks

The function generates a route-change message if the best route to a destination network has changed as the result of the deletion. However, the route-change message is not sent to the client that makes this call. Instead, relevant information is returned by this function directly to that client.

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

[**RtmAddRoute**](https://learn.microsoft.com/windows/win32/rras/rtmaddroute)

[**RtmDequeueRouteChangeMessage**](https://learn.microsoft.com/windows/win32/rras/rtmdequeueroutechangemessage)

