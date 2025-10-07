# RtmCloseEnumerationHandle function

\[This API has been superseded by the [Routing Table Manager Version 2](https://learn.microsoft.com/windows/win32/rras/about-routing-table-manager-version-2) API and will not be available beyond Windows Server 2003. Applications should use the Routing Table Manager Version 2 API.\]

The **RtmCloseEnumerationHandle** terminates a specified enumeration and frees the associated resources.

## Parameters

*EnumerationHandle* \[in\]

Handle to the enumeration to terminate. Obtain this handle by calling [**RtmCreateEnumerationHandle**](https://learn.microsoft.com/windows/win32/rras/rtmcreateenumerationhandle).

## Return value

If the function succeeds, the return value is NO\_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Description |
|-------------------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------|
| **ERROR\_INVALID\_HANDLE** | The parameter is not valid.<br> |
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

[**RtmCreateEnumerationHandle**](https://learn.microsoft.com/windows/win32/rras/rtmcreateenumerationhandle)

[**RtmEnumerateGetNextRoute**](https://learn.microsoft.com/windows/win32/rras/rtmenumerategetnextroute)

