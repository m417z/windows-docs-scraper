# IPX\_SPECIFIC\_DATA structure

\[This API has been superseded by the [Routing Table Manager Version 2](https://learn.microsoft.com/windows/win32/rras/about-routing-table-manager-version-2) API and will not be available beyond Windows Server 2003. Applications should use the Routing Table Manager Version 2 API.\]

The **IPX\_SPECIFIC\_DATA** structure contains IPX-specific data.

## Members

**FSD\_Flags**

Specifies flags that describe the route. Currently, this member is either zero or the following flag value.

| Value | Meaning |
|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------------------------|
|

**IPX\_GLOBAL\_CLIENT\_WAN\_ROUTE**

| Specifies that this route is for the global network allocated for all WAN clients.<br> |

**FSD\_TickCount**

Specifies the number of ticks it takes to reach the destination network. Routing protocols other than RIP should convert their metrics into ticks.

**FSD\_HopCount**

Specifies the hop count associated with the route.

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

[**RTM\_IPX\_ROUTE**](https://learn.microsoft.com/windows/win32/rras/rtm-ipx-route)

