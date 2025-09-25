# PWLX_SET_TIMEOUT callback function

## Description

[The WlxSetTimeout function is no longer available for use as of Windows Server 2008 and Windows Vista.]

Called by [GINA](https://learn.microsoft.com/windows/desktop/SecGloss/g-gly) to change the time-out associated with a dialog box. The default time-out is two minutes.

**Note** GINA DLLs are ignored in Windows Vista.

## Parameters

### `hWlx` [in]

Specifies the Winlogon handle passed to GINA in the
[WlxInitialize](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxinitialize) call.

### `Timeout` [in]

Requested time-out, in seconds.

## Return value

The **WlxSetTimeout** function returns one of the following values.

| Return code | Description |
| --- | --- |
| **TRUE** | The new time-out was accepted. |
| **FALSE** | The new time-out was not accepted. |

## See also

[WlxInitialize](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxinitialize)