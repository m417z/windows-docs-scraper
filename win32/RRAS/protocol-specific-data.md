# PROTOCOL\_SPECIFIC\_DATA structure

\[This API has been superseded by the [Routing Table Manager Version 2](https://learn.microsoft.com/windows/win32/rras/about-routing-table-manager-version-2) API and will not be available beyond Windows Server 2003. Applications should use the Routing Table Manager Version 2 API.\]

The **PROTOCOL\_SPECIFIC\_DATA** structure contains memory reserved for data specific to a particular routing protocol.

## Members

**PSD\_Data**

Specifies an array of **DWORD** variables. This memory is reserved for data that is specific to routing protocols.

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------|
| Minimum supported client<br> | None supported<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| End of server support<br> | Windows Server 2003<br> |
| Header<br> | Rtm.h |

## See also

[Routing Table Manager Version 1 Reference](https://learn.microsoft.com/windows/win32/rras/routing-table-manager-version-1-reference)

[Routing Table Manager Version 1 Structures](https://learn.microsoft.com/windows/win32/rras/routing-table-manager-version-1-structures)

[**RTM\_IP\_ROUTE**](https://learn.microsoft.com/windows/win32/rras/rtm-ip-route)

[**RTM\_IPX\_ROUTE**](https://learn.microsoft.com/windows/win32/rras/rtm-ipx-route)

