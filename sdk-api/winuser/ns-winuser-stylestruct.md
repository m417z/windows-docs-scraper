# STYLESTRUCT structure

## Description

Contains the styles for a window.

## Members

### `styleOld`

Type: **DWORD**

The previous styles for a window. For more information, see the Remarks.

### `styleNew`

Type: **DWORD**

The new styles for a window. For more information, see the Remarks.

## Remarks

The styles in
**styleOld** and
**styleNew** can be either the window styles (**WS_***) or the extended window styles (**WS_EX_***), depending on the
*wParam* of the message that includes **STYLESTRUCT**.

The
**styleOld** and
**styleNew** members indicate the styles through their bit pattern. Note that several styles are equal to zero; to detect these styles, test for the negation of their inverse style. For example, to see if **WS_EX_LEFT** is set, you test for ~**WS_EX_RIGHT**.

## See also

**Conceptual**

**Reference**

[WM_STYLECHANGED](https://learn.microsoft.com/windows/desktop/winmsg/wm-stylechanged)

[WM_STYLECHANGING](https://learn.microsoft.com/windows/desktop/winmsg/wm-stylechanging)

[Windows](https://learn.microsoft.com/windows/desktop/winmsg/windows)