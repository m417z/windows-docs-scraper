# RtmCreateEnumerationHandle function

\[This API has been superseded by the [Routing Table Manager Version 2](https://learn.microsoft.com/windows/win32/rras/about-routing-table-manager-version-2) API and will not be available beyond Windows Server 2003. Applications should use the Routing Table Manager Version 2 API.\]

The **RtmCreateEnumerationHandle** function returns a handle to use with [**RtmEnumerateGetNextRoute**](https://learn.microsoft.com/windows/win32/rras/rtmenumerategetnextroute) to scan through all routes, or a subset of routes, known to the routing table manager.

## Parameters

*ProtocolFamily* \[in\]

Specifies the protocol family of the routes to enumerate.

*EnumerationFlags* \[in\]

Specifies which routes should be enumerated. This parameter limits the set of routes returned by the enumeration API to a subset defined by the following flags and the values in the corresponding members of the structure pointed to by the *CriteriaRoute* parameter. This parameter can be one of the following values.

| EnumerationFlags | Meaning |
|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **RTM\_ONLY\_THIS\_NETWORK** | Enumerate only those routes that have the same network number as the RR\_Network member of the structure pointed to by CriteriaRoute.<br> |
| **RTM\_ONLY\_THIS\_INTERFACE** | Enumerate only those routes that were obtained through the interface specified by the RR\_InterfaceID field of the structure pointed to by CriteriaRoute.<br> |
| **RTM\_ONLY\_THIS\_PROTOCOL** | Enumerate only those routes that were added by the routing protocol specified by the RR\_RoutingProtocol field of the structure pointed to by CriteriaRoute.<br> |
| **RTM\_ONLY\_BEST\_ROUTES** | Enumerate only the best routes to each of the networks in the set.<br> |

*CriteriaRoute* \[in\]

Pointer to a protocol-family-specific route structure ([**RTM\_IP\_ROUTE**](https://learn.microsoft.com/windows/win32/rras/rtm-ip-route) or [**RTM\_IPX\_ROUTE**](https://learn.microsoft.com/windows/win32/rras/rtm-ipx-route)). The member values in this structure correspond to the flags specified by the *EnumerationFlags* parameter.

## Return value

If the function succeeds, the return value is a **HANDLE** to use with subsequent enumeration calls.

If the function fails, or no routes exist with the specified criteria, the return value is **NULL**. Call [**GetLastError**](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) to obtain more information.

| Value | Description |
|-------------------------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------------------------------------|
| **ERROR\_NO\_ROUTES** | There are no routes that have the specified criteria.<br> |
| **ERROR\_INVALID\_PARAMETER** | One or more of the input parameters is invalid (for example, unknown protocol family, invalid enumeration flags).<br> |
| **ERROR\_NO\_SYSTEM\_RESOURCES** | There are insufficient resources to carry out the operation.<br> |
| **ERROR\_NOT\_ENOUGH\_MEMORY** | There is insufficient memory to allocate the handle.<br> |

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

[**RTM\_IP\_ROUTE**](https://learn.microsoft.com/windows/win32/rras/rtm-ip-route)

[**RTM\_IPX\_ROUTE**](https://learn.microsoft.com/windows/win32/rras/rtm-ipx-route)

[**RtmCloseEnumerationHandle**](https://learn.microsoft.com/windows/win32/rras/rtmcloseenumerationhandle)

[**RtmEnumerateGetNextRoute**](https://learn.microsoft.com/windows/win32/rras/rtmenumerategetnextroute)

