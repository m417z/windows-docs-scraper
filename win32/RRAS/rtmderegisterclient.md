# RtmDeregisterClient function

\[This API has been superseded by the [Routing Table Manager Version 2](https://learn.microsoft.com/windows/win32/rras/about-routing-table-manager-version-2) API and will not be available beyond Windows Server 2003. Applications should use the Routing Table Manager Version 2 API.\]

The **RtmDeregisterClient** function deregisters the client, and frees resources associated with the client.

## Parameters

*ClientHandle* \[in\]

Handle that identifies the client to deregister. Obtain this handle by calling [**RtmRegisterClient**](https://learn.microsoft.com/windows/win32/rras/rtmregisterclient).

## Return value

If the function succeeds, the return value is NO\_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Description |
|-------------------------------------------------------------------------------------------------------------|----------------------------------------------------------------|
| **ERROR\_INVALID\_HANDLE** | The *ClientHandle* parameter is not a valid handle.<br> |
| **ERROR\_NO\_SYSTEM\_RESOURCES** | Insufficient resources to carry out the operation.<br> |

## Remarks

This function removes all routes that were added by the client.

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

