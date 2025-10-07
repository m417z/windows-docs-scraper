# RtmRegisterClient function

\[This API has been superseded by the [Routing Table Manager Version 2](https://learn.microsoft.com/windows/win32/rras/about-routing-table-manager-version-2) API and will not be available beyond Windows Server 2003. Applications should use the Routing Table Manager Version 2 API.\]

The **RtmRegisterClient** function registers a client as a handler of the specified protocol. It establishes a route change notification mechanism for the client, and sets protocol options.

## Parameters

*ProtocolFamily* \[in\]

Specifies the protocol family of the routing protocol to register.

*RoutingProtocol* \[in\]

Specifies the routing protocol identifier, the same as that used when registering with the router manager. See [**RegisterProtocol**](https://learn.microsoft.com/windows/desktop/api/Routprot/nc-routprot-pregister_protocol).

*ChangeEvent* \[in\]

Specifies that a best route to a network in the table has changed. The routing table manager signals this event after a change to the best route to any network in the table. See [**RtmDequeueRouteChangeMessage**](https://learn.microsoft.com/windows/win32/rras/rtmdequeueroutechangemessage) for more information about route-change notification.

This parameter is optional. If the caller specifies **NULL** for this parameter, the routing table manager does not notify the client of changes in best route status.

*Flags* \[in\]

Specifies miscellaneous options for special handling of the routing protocol. The following value is currently supported.

| Flags | Meaning |
|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|

**RTM\_PROTOCOL\_SINGLE\_ROUTE**

| The routing table manager keeps only one route per destination network for the routing protocol. In other words, the routing table manager replaces route entries that have the same destination network numbers instead of adding new ones.<br> |

## Return value

On successful return, a **HANDLE** value that identifies the client in subsequent calls to the routing table manager.

A **NULL** handle indicates that the routing table manager was unable to register the client. Call [**GetLastError**](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) to obtain the reason for the failure.

| Value | Description |
|---------------------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------|
| **ERROR\_CLIENT\_ALREADY\_EXISTS** | Another client has already registered to handle the specified protocol.<br> |
| **ERROR\_INVALID\_PARAMETER** | The specified protocol family is not supported, or the *Flags* parameter is invalid.<br> |
| **ERROR\_NO\_SYSTEM\_RESOURCES** | Insufficient resources to carry out the operation.<br> |
| **ERROR\_NOT\_ENOUGH\_MEMORY** | Insufficient memory to allocate data structures for the client.<br> |

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

[**GetLastError**](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror)

[**RegisterProtocol**](https://learn.microsoft.com/windows/desktop/api/Routprot/nc-routprot-pregister_protocol)

[RTMv1 Protocol Family Identifiers](https://learn.microsoft.com/windows/win32/rras/routing-table-manager-version-1-protocol-family-identifiers)

[**RtmDequeueRouteChangeMessage**](https://learn.microsoft.com/windows/win32/rras/rtmdequeueroutechangemessage)

[**RtmDeregisterClient**](https://learn.microsoft.com/windows/win32/rras/rtmderegisterclient)

