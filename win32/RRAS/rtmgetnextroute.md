# RtmGetNextRoute function

\[This API has been superseded by the [Routing Table Manager Version 2](https://learn.microsoft.com/windows/win32/rras/about-routing-table-manager-version-2) API and will not be available beyond Windows Server 2003. Applications should use the Routing Table Manager Version 2 API.\]

The **RtmGetNextRoute** function returns the next route from the specified subset of routes in the table.

## Parameters

*ProtocolFamily* \[in\]

Specifies the protocol family of routes to retrieve, for example, IP or IPX.

*EnumerationFlags* \[in\]

Specifies which routes should be enumerated. This parameter limits the set of deleted routes to a subset defined by the following flags and the values in the corresponding members of the structure pointed to by the *CriteriaRoute* parameter. The flags are the same as those used in [**RtmCreateEnumerationHandle**](https://learn.microsoft.com/windows/win32/rras/rtmcreateenumerationhandle).

*Route* \[in, out\]

On input, *Route* points to a protocol-family-specific structure ( [**RTM\_IP\_ROUTE**](https://learn.microsoft.com/windows/win32/rras/rtm-ip-route) or [**RTM\_IPX\_ROUTE**](https://learn.microsoft.com/windows/win32/rras/rtm-ipx-route)).

The calling function provides member values for this structure. These values, in conjunction with the *EnumerationFlags* parameter, specify the set from which to return routes.

On output, *Route* points to a structure that receives the first route that matched the specified criteria.

## Return value

If the function succeeds, the return value is **NO\_ERROR**.

If the function fails, the return value is one of the following error codes.

| Value | Description |
|-------------------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------|
| **ERROR\_INVALID\_PARAMETER** | One of the parameters is invalid.<br> |
| **ERROR\_NO\_ROUTES** | There are no routes that match the specified criteria.<br> |
| **ERROR\_NO\_SYSTEM\_RESOURCES** | There are insufficient resources to carry out the operation.<br> |

## Remarks

The routes are returned in the following order:

1. Network number
2. Routing protocol
3. Interface identifier
4. Next-hop address

This function is less efficient than the corresponding enumeration handle functions.

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

[**RtmCloseEnumerationHandle**](https://learn.microsoft.com/windows/win32/rras/rtmcloseenumerationhandle)

[**RtmCreateEnumerationHandle**](https://learn.microsoft.com/windows/win32/rras/rtmcreateenumerationhandle)

[**RtmEnumerateGetNextRoute**](https://learn.microsoft.com/windows/win32/rras/rtmenumerategetnextroute)

[**RtmGetFirstRoute**](https://learn.microsoft.com/windows/win32/rras/rtmgetfirstroute)

