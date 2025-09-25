# DrawThemeParentBackgroundEx function

## Description

Used by partially-transparent or alpha-blended child controls to draw the part of their parent in front of which they appear. Sends a [WM_ERASEBKGND](https://learn.microsoft.com/windows/desktop/winmsg/wm-erasebkgnd) message followed by a [WM_PRINTCLIENT](https://learn.microsoft.com/windows/desktop/gdi/wm-printclient).

## Parameters

### `hwnd` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle of the child control.

### `hdc` [in]

Type: **[HDC](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

HDC of the child control.

### `dwFlags` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Zero or more of the following values. If this value is zero, this function returns S_OK only if the parent handled [WM_PRINTCLIENT](https://learn.microsoft.com/windows/desktop/gdi/wm-printclient).

| Value | Meaning |
| --- | --- |
| **DTPB_WINDOWDC** | If set, *hdc* is assumed to be a window DC, not a client DC. |
| **DTPB_USECTLCOLORSTATIC** | If set, this function sends a [WM_CTLCOLORSTATIC](https://learn.microsoft.com/windows/desktop/Controls/wm-ctlcolorstatic) message to the parent and uses the brush if one is provided. Otherwise, it uses COLOR_BTNFACE. |
| **DTPB_USEERASEBKGND** | If set, this function returns S_OK without sending a [WM_CTLCOLORSTATIC](https://learn.microsoft.com/windows/desktop/Controls/wm-ctlcolorstatic) message if the parent actually painted on [WM_ERASEBKGND](https://learn.microsoft.com/windows/desktop/winmsg/wm-erasebkgnd). |

### `prc` [in]

Type: **const [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)***

Optional. The area to be drawn, in child coordinates. If this parameter is NULL, the area to be drawn includes the entire area occupied by the child control.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

S_OK if successful; otherwise, S_FALSE.