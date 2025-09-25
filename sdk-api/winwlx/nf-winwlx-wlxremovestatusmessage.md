# WlxRemoveStatusMessage function

## Description

[The WlxRemoveStatusMessage function is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **WlxRemoveStatusMessage** function must be implemented by a replacement [GINA](https://learn.microsoft.com/windows/desktop/SecGloss/g-gly) DLL. [Winlogon](https://learn.microsoft.com/windows/desktop/SecGloss/w-gly) calls this function to tell the GINA DLL to stop displaying the status message.

**Note** GINA DLLs are ignored in Windows Vista.

## Parameters

### `pWlxContext` [in]

Pointer to the GINA context associated with this window station. The GINA returns this context value when Winlogon calls
[WlxInitialize](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxinitialize) for this station.

## Return value

| Return code | Description |
| --- | --- |
| **TRUE** | Return **TRUE** if the message was removed. |
| **FALSE** | Return **FALSE** if the message was not removed. |

## See also

[WlxDisplayStatusMessage](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxdisplaystatusmessage)

[WlxGetStatusMessage](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxgetstatusmessage)

[WlxInitialize](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxinitialize)