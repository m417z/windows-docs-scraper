# MCIWndCreateW function

## Description

The **MCIWndCreate** function registers the MCIWnd window class and creates an MCIWnd window for using MCI services. **MCIWndCreate** can also open an MCI device or file (such as an AVI file) and associate it with the MCIWnd window.

## Parameters

### `hwndParent`

Handle to the parent window.

### `hInstance`

Handle to the module instance to associate with the MCIWnd window.

### `dwStyle`

Flags defining the window style. In addition to specifying the window styles used with the [CreateWindowEx](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-createwindowexa) function, you can specify the following styles to use with MCIWnd windows.

| Value | Meaning |
| --- | --- |
| MCIWNDF_NOAUTOSIZEWINDOW | Will not change the dimensions of an MCIWnd window when the image size changes. |
| MCIWNDF_NOAUTOSIZEMOVIE | Will not change the dimensions of the destination rectangle when an MCIWnd window size changes. |
| MCIWNDF_NOERRORDLG | Inhibits display of MCI errors to users. |
| MCIWNDF_NOMENU | Hides the Menu button from view on the toolbar and prohibits users from accessing its pop-up menu. |
| MCIWNDF_NOOPEN | Hides the open and close commands from the MCIWnd menu and prohibits users from accessing these choices in the pop-up menu. |
| MCIWNDF_NOPLAYBAR | Hides the toolbar from view and prohibits users from accessing it. |
| MCIWNDF_NOTIFYANSI | Causes MCIWnd to use an ANSI string instead of a Unicode string when notifying the parent window of device mode changes. This flag is used in combination with MCIWNDF_NOTIFYMODE. |
| MCIWNDF_NOTIFYMODE | Causes MCIWnd to notify the parent window with an [MCIWNDM_NOTIFYMODE](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-notifymode) message whenever the device changes operating modes. The *lParam* parameter of this message identifies the new mode, such as MCI_MODE_STOP. |
| MCIWNDF_NOTIFYPOS | Causes MCIWnd to notify the parent window with an [MCIWNDM_NOTIFYPOS](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-notifypos) message whenever a change in the playback or record position within the content occurs. The *lParam* parameter of this message contains the new position in the content. |
| MCIWNDF_NOTIFYMEDIA | Causes MCIWnd to notify the parent window with an [MCIWNDM_NOTIFYMEDIA](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-notifymedia) message whenever a new device is used or a data file is opened or closed. The *lParam* parameter of this message contains a pointer to the new file name. |
| MCIWNDF_NOTIFYSIZE | Causes MCIWnd to notify the parent window when the MCIWnd window size changes. |
| MCIWNDF_NOTIFYERROR | Causes MCIWnd to notify the parent window when an MCI error occurs. |
| MCIWNDF_NOTIFYALL | Causes all MCIWNDF window notification styles to be used. |
| MCIWNDF_RECORD | Adds a Record button to the toolbar and adds a new file command to the menu if the MCI device has recording capability. |
| MCIWNDF_SHOWALL | Causes all MCIWNDF_SHOW styles to be used. |
| MCIWNDF_SHOWMODE | Displays the current mode of the MCI device in the window title bar. For a list of device modes, see the [MCIWndGetMode](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-mciwndgetmode) macro. |
| MCIWNDF_SHOWNAME | Displays the name of the open MCI device or data file in the MCIWnd window title bar. |
| MCIWNDF_SHOWPOS | Displays the current position within the content of the MCI device in the window title bar. |

### `szFile`

Null-terminated string indicating the name of an MCI device or data file to open.

## Return value

Returns the handle to an MCI window if successful or zero otherwise.

## Remarks

Default window styles for a child window are WS_CHILD, WS_BORDER, and WS_VISIBLE. **MCIWndCreate** assumes a child window when a non-**NULL** handle of a parent window is specified.

Default window styles for a parent window are WS_OVERLAPPEDWINDOW and WS_VISIBLE. **MCIWndCreate** assumes a parent window when a **NULL** handle of a parent window is specified.

Use the window handle returned by this function for the window handle in the MCIWnd macros. If your application uses this function, it does not need to use the [MCIWndRegisterClass](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-mciwndregisterclass) function.

> [!NOTE]
> The vfw.h header defines MCIWndCreate as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[MCIWNDM_NOTIFYMEDIA](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-notifymedia)

[MCIWNDM_NOTIFYMODE](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-notifymode)

[MCIWNDM_NOTIFYPOS](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-notifypos)

[MCIWndGetMode](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-mciwndgetmode)

[MCIWndRegisterClass](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-mciwndregisterclass)