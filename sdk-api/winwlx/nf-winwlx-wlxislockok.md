# WlxIsLockOk function

## Description

[The WlxIsLockOk function is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **WlxIsLockOk** function must be implemented by a replacement [GINA](https://learn.microsoft.com/windows/desktop/SecGloss/g-gly) DLL. [Winlogon](https://learn.microsoft.com/windows/desktop/SecGloss/w-gly) calls this function before attempting to lock the workstation.

**Note** GINA DLLs are ignored in Windows Vista.

## Parameters

### `pWlxContext` [in]

Pointer to the GINA context associated with this window station. The GINA supplies this context when Winlogon calls
[WlxInitialize](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxinitialize).

## Return value

| Return code | Description |
| --- | --- |
| **TRUE** | Returns **TRUE** if it is acceptable to lock the workstation. |
| **FALSE** | Returns **FALSE** if it is not acceptable to lock the workstation. |

## See also

[WlxInitialize](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxinitialize)