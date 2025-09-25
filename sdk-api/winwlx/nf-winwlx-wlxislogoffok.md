# WlxIsLogoffOk function

## Description

[The WlxIsLogoffOk function is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **WlxIsLogoffOk** function must be implemented by a replacement [GINA](https://learn.microsoft.com/windows/desktop/SecGloss/g-gly) DLL. [Winlogon](https://learn.microsoft.com/windows/desktop/SecGloss/w-gly) calls this function when the user initiates a logoff operation.

**Note** GINA DLLs are ignored in Windows Vista.

## Parameters

### `pWlxContext` [in]

Pointer to the GINA context associated with this window station. The GINA returns this context value when Winlogon calls
[WlxInitialize](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxinitialize) for this station.

## Return value

| Return code | Description |
| --- | --- |
| **TRUE** | Returns **TRUE** if it is acceptable to perform the logoff operation. |
| **FALSE** | Returns **FALSE** if it is not acceptable to perform the logoff operation. |

## Remarks

**WlxIsLogoffOk** can return **FALSE** to prevent the user from logging off the workstation.

## See also

[WlxInitialize](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxinitialize)