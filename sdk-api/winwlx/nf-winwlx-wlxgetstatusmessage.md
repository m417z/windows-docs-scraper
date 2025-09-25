# WlxGetStatusMessage function

## Description

[The WlxGetStatusMessage function is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **WlxGetStatusMessage** function must be implemented by a replacement [GINA](https://learn.microsoft.com/windows/desktop/SecGloss/g-gly) DLL. [Winlogon](https://learn.microsoft.com/windows/desktop/SecGloss/w-gly) calls this function to get the status message being displayed by the GINA DLL.

**Note** GINA DLLs are ignored in Windows Vista.

## Parameters

### `pWlxContext` [in]

Pointer to the GINA context associated with this window station. The GINA returns this context value when Winlogon calls
[WlxInitialize](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxinitialize) for this station.

### `pdwOptions` [out]

Pointer to a **DWORD** that will hold the display options for the current status message.

### `pMessage` [out]

Returns the current status message text.

### `dwBufferSize` [in]

Size of the *pMessage* buffer.

## Return value

| Return code | Description |
| --- | --- |
| **TRUE** | Returns **TRUE** if the message was retrieved. |
| **FALSE** | Returns **FALSE** if the message was not retrieved. |

## See also

[WlxDisplayStatusMessage](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxdisplaystatusmessage)

[WlxInitialize](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxinitialize)

[WlxRemoveStatusMessage](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxremovestatusmessage)