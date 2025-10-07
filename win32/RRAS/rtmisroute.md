# RtmIsRoute function

\[This API has been superseded by the [Routing Table Manager Version 2](https://learn.microsoft.com/windows/win32/rras/about-routing-table-manager-version-2) API and will not be available beyond Windows Server 2003. Applications should use the Routing Table Manager Version 2 API.\]

The **RtmIsRoute** function determines if one or more routes to a specified destination network exist. If so, the function returns information for the best route to that network.

## Parameters

*ProtocolFamily* \[in\]

Specifies the type of data structure pointed to by the *Network* parameter, for example, [**IP\_NETWORK**](https://learn.microsoft.com/windows/win32/rras/ip-network), [**IPX\_NETWORK**](https://learn.microsoft.com/windows/win32/rras/ipx-network).

*Network* \[in\]

Pointer to a structure that specifies protocol-family-specific network number data. This data identifies the network for which the caller seeks route information.

*BestRoute* \[out\]

Pointer to a protocol-family-specific structure that receives the current best route information, if any.

## Return value

The return value is one of the following codes.

| Value | Description |
|-------------------------------------------------------------------------------------------------------------|----------------------------------------------------------------------------------------------------------------------------------------------------------|
| **TRUE** | At least one route to the specified network exists. The best route is returned in the structure pointed to by the *BestRoute* parameter.<br> |
| **FALSE** | There is no route to the specified network, or the operation failed. Call [**GetLastError**](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) to obtain more information:<br> |
| **NO\_ERROR** | The operation succeeded, but there is no route to the specified network.<br> |
| **ERROR\_INVALID\_PARAMETER** | The value of the *ProtocolFamily* parameter does not correspond to any installed protocol family.<br> |
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

[**GetLastError**](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror)

[**IP\_NETWORK**](https://learn.microsoft.com/windows/win32/rras/ip-network)

[**IPX\_NETWORK**](https://learn.microsoft.com/windows/win32/rras/ipx-network)

[RTMv1 Protocol Family Identifiers](https://learn.microsoft.com/windows/win32/rras/routing-table-manager-version-1-protocol-family-identifiers)

