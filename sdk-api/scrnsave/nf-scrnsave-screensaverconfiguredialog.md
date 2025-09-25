# ScreenSaverConfigureDialog function

## Description

Receives messages sent to a screen saver's configuration dialog box. A screen saver that allows user configuration must define this function.

## Parameters

### `hDlg`

Type: **HWND**

The identifier of the configuration dialog box.

### `message`

Type: **UINT**

A message that was sent to the screen saver's configuration dialog box.

### `wParam`

Type: **WPARAM**

Additional message-specific information.

### `lParam`

Type: **LPARAM**

Additional message-specific information.

## Return value

Type: **BOOL**

If the function successfully processes the message, it should return **TRUE**. If not, it should return **FALSE**, except in response to a [WM_INITDIALOG](https://learn.microsoft.com/windows/desktop/dlgbox/wm-initdialog) message. In response to a **WM_INITDIALOG** message, **ScreenSaverConfigureDialog** should return **FALSE** if it calls the [SetFocus](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setfocus) function to set the keyboard focus to one of the controls in the dialog box. Otherwise, the function should return **TRUE**, in which case the system sets the keyboard focus to the first control in the dialog box that can be given the focus.

## Remarks

The dialog box template for the configuration dialog box must have the **DLG_SCRNSAVECONFIGURE** identifier.

The dialog box procedure is used only if the application specifies the default window class (**WC_DIALOG**) for the dialog box. The application uses the default class if no explicit class is given in the dialog box template. Although the dialog box procedure is similar to a window procedure, it must not call the [DefWindowProc](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-defwindowproca) function to process unwanted messages. Unwanted messages are processed internally by the default dialog box procedure.

The **ScreenSaverConfigureDialog** function must be exported by including it in the EXPORTS statement in the application's module-definition (.def) file.

## See also

[RegisterDialogClasses](https://learn.microsoft.com/windows/desktop/api/scrnsave/nf-scrnsave-registerdialogclasses)