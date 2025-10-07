# RtmGetRouteAge function

\[This API has been superseded by the [Routing Table Manager Version 2](https://learn.microsoft.com/windows/win32/rras/about-routing-table-manager-version-2) API and will not be available beyond Windows Server 2003. Applications should use the Routing Table Manager Version 2 API.\]

The **RtmGetRouteAge** function returns the age of a route. The age is the time, in seconds, since it was created or last updated.

## Parameters

*Route* \[in\]

Pointer to a protocol-family-specific structure that specifies route data recently obtained from the routing table manager.

## Return value

The return value is one of the following values.

| Value | Description |
|-----------------------------------------------------------------------------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **RouteAge** | The time in seconds since a route was created or last updated.<br> |
| **INFINITE** | The content of the route structure is invalid. In this case, a call to [**GetLastError**](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns ERROR\_INVALID\_PARAMETER.<br> |

## Remarks

The route age is computed from the RR\_TimeStamp member of the structure that is pointed to by the *Route* parameter. The routing table manager sets the value of this member when a route is added or updated.

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

[Routing Table Manager Version\_1 Reference](https://learn.microsoft.com/windows/win32/rras/routing-table-manager-version-1-reference)

[Routing Table Manager Version 1 Functions](https://learn.microsoft.com/windows/win32/rras/routing-table-manager-version-1-functions)

[**GetLastError**](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror)

[**RTM\_IP\_ROUTE**](https://learn.microsoft.com/windows/win32/rras/rtm-ip-route)

[**RTM\_IPX\_ROUTE**](https://learn.microsoft.com/windows/win32/rras/rtm-ipx-route)

