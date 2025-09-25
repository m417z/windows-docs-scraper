# IsTouchWindow function

## Description

Checks whether a specified window is touch-capable and, optionally, retrieves the modifier flags set for the window's touch capability.

## Parameters

### `hwnd` [in]

The handle of the window. The function fails with **ERROR_ACCESS_DENIED** if the calling thread is not on the same desktop as the specified window.

### `pulFlags` [out, optional]

The address of the **ULONG** variable to receive the modifier flags for the specified window's touch capability.

## Return value

Returns **TRUE** if the window supports Windows Touch; returns **FALSE** if the window does not support Windows Touch.

## Remarks

The following table lists the values for the *pulFlags* output parameter.

| Flag | Description |
| --- | --- |
| **TWF_FINETOUCH** | Specifies that *hWnd* prefers noncoalesced touch input. |
| **TWF_WANTPALM** | Clearing this flag disables palm rejection which reduces delays for getting [WM_TOUCH](https://learn.microsoft.com/windows/desktop/wintouch/wm-touchdown) messages. This is useful if you want as quick of a response as possible when a user touches your application.<br><br>Setting this flag enables palm detection and will prevent some [WM_TOUCH](https://learn.microsoft.com/windows/desktop/wintouch/wm-touchdown) messages from being sent to your application. This is useful if you do not want to receive **WM_TOUCH** messages that are from palm contact. |

## See also

[Functions](https://learn.microsoft.com/windows/desktop/wintouch/mtfunctions)