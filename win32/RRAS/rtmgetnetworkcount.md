# RtmGetNetworkCount function

\[This API has been superseded by the [Routing Table Manager Version 2](https://learn.microsoft.com/windows/win32/rras/about-routing-table-manager-version-2) API and will not be available beyond Windows Server 2003. Applications should use the Routing Table Manager Version 2 API.\]

The **RtmGetNetworkCount** function retrieves the number of networks to which the routing table manager has routes.

## Parameters

*ProtocolFamily* \[in\]

Specifies for which type of network to obtain route information, for example, IP or IPX.

## Return value

If the function succeeds, the return value is the network count, the number of networks known to the routing protocols of the specified protocol family.

If the return value is zero, either no routes are available, or the operation failed. Call [**GetLastError**](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) to obtain more information.

| Value | Description |
|----------------------------------------------------------------------------------------------------------|--------------------------------------------------------------------------------------------------------------|
| **NO\_ERROR** | The operation succeeded, but no routes are available.<br> |
| **ERROR\_INVALID\_PARAMETER** | The value of the *ProtocolFamily* parameter does not correspond to any installed protocol family.<br> |

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

[RTMv1 Protocol Family Identifiers](https://learn.microsoft.com/windows/win32/rras/routing-table-manager-version-1-protocol-family-identifiers)

