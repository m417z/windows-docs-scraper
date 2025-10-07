# RtmBlockDeleteRoutes function

\[This API has been superseded by the [Routing Table Manager Version 2](https://learn.microsoft.com/windows/win32/rras/about-routing-table-manager-version-2) API and will not be available beyond Windows Server 2003. Applications should use the Routing Table Manager Version 2 API.\]

The **RtmBlockDeleteRoutes** function deletes all routes in the specified subset of routes in the table.

## Parameters

*ClientHandle* \[in\]

Handle that identifies the client, and therefore the routing protocol, of the routes to be deleted.

*EnumerationFlags* \[in\]

Specifies which routes should be enumerated. This parameter limits the set of deleted routes to a subset defined by the following flags and the values in the corresponding members of the structure pointed to by the *CriteriaRoute* parameter. The flags are the same as those used in [**RtmCreateEnumerationHandle**](https://learn.microsoft.com/windows/win32/rras/rtmcreateenumerationhandle) except that RTM\_ONLY\_BEST\_ROUTES is redundant for **RtmBlockDeleteRoutes**. The best-route designation is adjusted as routes are deleted, so the function eventually deletes all the routes in the subset.

*CriteriaRoute* \[in\]

Pointer to a protocol-family-specific route structure ( [**RTM\_IP\_ROUTE**](https://learn.microsoft.com/windows/win32/rras/rtm-ip-route) or [**RTM\_IPX\_ROUTE**](https://learn.microsoft.com/windows/win32/rras/rtm-ipx-route)). The member values in this structure correspond to the flags specified by the *EnumerationFlags* parameter.

## Return value

If the function succeeds, the return value is NO\_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Description |
|-------------------------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------------------|
| **ERROR\_NO\_ROUTES** | There are no routes that have the specified criteria.<br> |
| **ERROR\_INVALID\_HANDLE** | The *ClientHandle* parameter is not valid.<br> |
| **ERROR\_INVALID\_PARAMETER** | One or more of the input parameters is invalid, for example, the enumeration flags are invalid.<br> |
| **ERROR\_NO\_SYSTEM\_RESOURCES** | There are insufficient resources to carry out the operation.<br> |
| **ERROR\_NOT\_ENOUGH\_MEMORY** | There is insufficient memory to carry out the operation.<br> |

## Remarks

The function generates appropriate notification messages to all registered clients including the caller.

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

[**RtmCreateEnumerationHandle**](https://learn.microsoft.com/windows/win32/rras/rtmcreateenumerationhandle)

[**RtmRegisterClient**](https://learn.microsoft.com/windows/win32/rras/rtmregisterclient)

