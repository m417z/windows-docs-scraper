# WlxDisplayStatusMessage function

## Description

[The WlxDisplayStatusMessage function is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **WlxDisplayStatusMessage** function must be implemented by a replacement [GINA](https://learn.microsoft.com/windows/desktop/SecGloss/g-gly) DLL. [Winlogon](https://learn.microsoft.com/windows/desktop/SecGloss/w-gly) calls this function when the GINA DLL should display a message.

**Note** GINA DLLs are ignored in Windows Vista.

## Parameters

### `pWlxContext` [in]

Pointer to the GINA context associated with this window station. The GINA returns this context value when Winlogon calls
[WlxInitialize](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxinitialize) for this station.

### `hDesktop` [in]

A handle to the desktop where the status message should be displayed.

### `dwOptions` [in]

Specifies display options for the status dialog box. The following options are valid:

STATUSMSG_OPTION_NOANIMATION

STATUSMSG_OPTION_SETFOREGROUND

### `pTitle` [in]

Pointer to a null-terminated wide character string that specifies the title of the message to be displayed.

### `pMessage` [in]

Pointer to a null-terminated wide character string that specifies the message to be displayed.

## Return value

| Return code | Description |
| --- | --- |
| **TRUE** | Returns **TRUE** if the message was displayed. |
| **FALSE** | Returns **FALSE** if the message was not displayed. |

## See also

[WlxInitialize](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxinitialize)