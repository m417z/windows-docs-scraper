# RtmEnumerateGetNextRoute function

\[This API has been superseded by the [Routing Table Manager Version 2](https://learn.microsoft.com/windows/win32/rras/about-routing-table-manager-version-2) API and will not be available beyond Windows Server 2003. Applications should use the Routing Table Manager Version 2 API.\]

The **RtmEnumerateGetNextRoute** function returns the next-route entry in the enumeration started by a call to [**RtmCreateEnumerationHandle**](https://learn.microsoft.com/windows/win32/rras/rtmcreateenumerationhandle).

## Parameters

*EnumerationHandle* \[in\]

Handle that identifies the enumeration and specifies its scope. Obtain this handle by calling [**RtmCreateEnumerationHandle**](https://learn.microsoft.com/windows/win32/rras/rtmcreateenumerationhandle).

*Route* \[out\]

Pointer to a protocol-family-specific route structure ( [**RTM\_IP\_ROUTE**](https://learn.microsoft.com/windows/win32/rras/rtm-ip-route) or [**RTM\_IPX\_ROUTE**](https://learn.microsoft.com/windows/win32/rras/rtm-ipx-route)). This structure will receive the next route in the enumeration.

## Return value

If the function succeeds, the return value is NO\_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Description |
|-------------------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------|
| **ERROR\_INVALID\_HANDLE** | The *EnumerationHandle* parameter is not valid.<br> |
| **ERROR\_NO\_MORE\_ROUTES** | There are no more routes in the enumeration.<br> |
| **ERROR\_NO\_SYSTEM\_RESOURCES** | There are insufficient resources to carry out the operation.<br> |

## Remarks

Although routes are not returned in any particular order, each route in the enumeration is returned only once.

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

[**RTM\_IP\_ROUTE**](https://learn.microsoft.com/windows/win32/rras/rtm-ip-route)

[**RTM\_IPX\_ROUTE**](https://learn.microsoft.com/windows/win32/rras/rtm-ipx-route)

[**RtmCloseEnumerationHandle**](https://learn.microsoft.com/windows/win32/rras/rtmcloseenumerationhandle)

[**RtmCreateEnumerationHandle**](https://learn.microsoft.com/windows/win32/rras/rtmcreateenumerationhandle)

