# PWLX_GET_SOURCE_DESKTOP callback function

## Description

[The WlxGetSourceDesktop function is no longer available for use as of Windows Server 2008 and Windows Vista.]

Called by [GINA](https://learn.microsoft.com/windows/desktop/SecGloss/g-gly) to determine the name and handle of the desktop that was current before [Winlogon](https://learn.microsoft.com/windows/desktop/SecGloss/w-gly) switched to the Winlogon desktop.

**Note** GINA DLLs are ignored in Windows Vista.

GINA can use this function to modify its behavior, depending on the originating desktop.

## Parameters

### `hWlx` [in]

Specifies the Winlogon handle passed to GINA in the
[WlxInitialize](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxinitialize) call.

### `ppDesktop` [out]

Receives a pointer to a
[WLX_DESKTOP](https://learn.microsoft.com/windows/desktop/api/winwlx/ns-winwlx-wlx_desktop) structure containing necessary information describing the desktop. This pointer can be freed with
[LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree).

## Return value

The **WlxGetSourceDesktop** function returns one of the following values.

| Return code | Description |
| --- | --- |
| **TRUE** | The call succeeded. |
| **FALSE** | The call failed. |

## See also

[LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree)

[WLX_DESKTOP](https://learn.microsoft.com/windows/desktop/api/winwlx/ns-winwlx-wlx_desktop)

[WlxInitialize](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxinitialize)