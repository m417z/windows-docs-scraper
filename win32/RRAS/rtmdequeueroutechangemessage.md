# RtmDequeueRouteChangeMessage function

\[This API has been superseded by the [Routing Table Manager Version 2](https://learn.microsoft.com/windows/win32/rras/about-routing-table-manager-version-2) API and will not be available beyond Windows Server 2003. Applications should use the Routing Table Manager Version 2 API.\]

The **RtmDequeueRouteChangeMessage** function returns the next route-change message in the queue associated with the specified client.

## Parameters

*ClientHandle* \[in\]

Handle that identifies the client for which the operation is performed. Obtain this handle by calling [**RtmRegisterClient**](https://learn.microsoft.com/windows/win32/rras/rtmregisterclient).

*Flags* \[out\]

Pointer to a **DWORD** variable. The value of this variable is set by the routing table manager. The value specifies the type of the change message, and what information was returned in the provided buffers. This parameter is one of the following.

| Flags | Meaning |
|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **RTM\_ROUTE\_ADDED** | The first route was added for a particular destination network. The *CurBestRoute* parameter points to the information for the added route.<br> |
| **RTM\_ROUTE\_DELETED** | The only route available for a particular destination network was deleted. The *PrevBestRoute* parameter points to the information for the deleted route.<br> |
| **RTM\_ROUTE\_CHANGED** | At least one of the significant parameters was changed for a best route to a particular destination network. The significant parameters are: <br> Protocol identifier<br> Interface index<br> Next-hop address<br> Protocol-family-specific data (including route metrics)<br> |

The *PrevBestRoute* parameter points to the route information as it was before the change. The *CurBestRoute* parameter points to current (that is, after-change) route information.

*CurBestRoute* \[out\]

Pointer to a structure that receives the current best-route information (if any). The type of the structure is specific to the protocol family, for example, IP or IPX.

This parameter is optional. If the caller specifies **NULL** for this parameter, the current best-route information is not returned.

*PrevBestRoute* \[out\]

Pointer to a structure that receives the previous best-route information, if any. The type of the structure is specific to the protocol family, for example, IP or IPX.

This parameter is optional. If the caller specifies **NULL** for this parameter, the previous best-route information is not returned.

## Return value

The return value is one of the following codes.

| Value | Description |
|-------------------------------------------------------------------------------------------------------------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **NO\_ERROR** | This message was the last message in the client's queue. The event object is reset.<br> |
| **ERROR\_INVALID\_HANDLE** | The *ClientHandle* parameter is not a valid handle, or at registration the client did not provide an event object for change message notification (see [**RtmRegisterClient**](https://learn.microsoft.com/windows/win32/rras/rtmregisterclient)).<br> |
| **ERROR\_MORE\_MESSAGES** | The client's queue contains additional messages. The client should call **RtmDequeueRouteChangeMessage** again as soon as possible to allow the routing table manager to free the resources associated with the pending messages.<br> |
| **ERROR\_NO\_MESSAGES** | The client's queue contains no messages; the call was unsolicited. The event is reset.<br> |
| **ERROR\_NO\_SYSTEM\_RESOURCES** | There are insufficient resources to carry out the operation.<br> |

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

[**RtmRegisterClient**](https://learn.microsoft.com/windows/win32/rras/rtmregisterclient)

