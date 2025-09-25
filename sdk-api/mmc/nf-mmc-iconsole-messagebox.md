# IConsole::MessageBox

## Description

Displays a message box.

## Parameters

### `lpszText` [in]

A pointer to a null-terminated string that contains the message to be displayed.

### `lpszTitle` [in]

A pointer to a null-terminated string used for the message box title. If this parameter is **NULL**, the default title "Error" is used.

### `fuStyle` [in]

A value that specifies a set of bit flags that determine the contents and behavior of the message box. This parameter can be a combination of flags from the following groups of flags taken from the documentation for the Windows API
[MessageBox](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-messagebox).

Specify one of the following flags to indicate which buttons appear in the message box.

#### MB_ABORTRETRYIGNORE

The message box contains three buttons: Abort, Retry, and Ignore.

#### MB_OK

The message box contains one button: OK. This is the default.

#### MB_OKCANCEL

The message box contains two buttons: OK and
Cancel.

#### MB_RETRYCANCEL

The message box contains two buttons: Retry and
Cancel.

#### MB_YESNO

The message box contains two buttons: Yes and No.

#### MB_YESNOCANCEL

The message box contains three buttons: Yes, No, and
Cancel.

Specify one of the following flags to indicate which icon appears in the message box:

#### MB_ICONEXCLAMATION, MB_ICONWARNING

An exclamation point icon appears in the message box.

#### MB_ICONINFORMATION, MB_ICONASTERISK

An icon consisting of an "I" in a circle appears in the message box.

#### MB_ICONQUESTION

A question-mark icon appears in the message box.

#### MB_ICONSTOP,
MB_ICONERROR,
MB_ICONHAND

A stop sign icon appears in the message box.

Specify one of the following flags to indicate the default button:

#### MB_DEFBUTTON1

The first button is the default button unless one of the other flags in this group is specified as the default.

#### MB_DEFBUTTON2

The second button is the default button.

#### MB_DEFBUTTON3

The third button is the default button.

#### MB_DEFBUTTON4

The fourth button is the default button.

Specify one of the following flags to indicate the modality of the dialog box:

#### MB_APPLMODAL

The user must respond to the message box before continuing work in the current window. However, the user can move to the windows of other applications and work in those windows. The default is **MB_APPLMODAL** if neither **MB_SYSTEMMODAL** nor **MB_TASKMODAL** is specified.

#### MB_SYSTEMMODAL

All applications are suspended until the user responds to the message box. System-modal message boxes are used to notify the user of serious, potentially damaging errors that require immediate attention and should be used sparingly.

#### MB_TASKMODAL

Similar to **MB_APPLMODAL**, but not useful within a Microsoft Foundation Classes (MFC) application. This flag is reserved for a calling application or library that does not have a window handle available.

In addition, you can specify the following flags:

#### MB_DEFAULT_DESKTOP_ONLY

The desktop currently receiving input must be a default desktop; otherwise, the function fails. A default desktop is one an application runs on after the user has logged on.

#### MB_HELP

Adds a
**Help** button to the message box. Choosing the
**Help** button or pressing **F1** generates a Help event.

#### MB_RIGHT

The text is right-justified.

#### MB_RTLREADING

Displays message and caption text using right-to-left reading order for Hebrew and Arabic systems.

#### MB_SETFOREGROUND

The message box becomes the foreground window. Internally, the operating system calls the [SetForegroundWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setforegroundwindow) function for the message box.

#### MB_TOPMOST

The message box is created with the **WS_EX_TOPMOST** window style.

#### MB_SERVICE_NOTIFICATION

The caller is a service notifying the user of an event. The function displays a message box on the current active desktop, even if there is no user logged on to the computer.

For more information about using this flag, see the [MessageBox](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-messagebox) function.

#### MB_SERVICE_NOTIFICATION_NT3x

This value corresponds to the value defined for **MB_SERVICE_NOTIFICATION** for earlier versions of Windows.

### `piRetval` [out]

A pointer to the return value.

## Return value

This method can return one of these values.

## Remarks

**MessageBox** should not be used for that displays errors that occur when the snap-in does not have the focus. Generally,

**MessageBox** should be used only when the error demands user attention and when the result pane contains useful information despite the error.

In most cases, the MMC message OCX control is a more appropriate way of that displays error messages. For more information, see
[Using the MMC Message OCX Control](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/using-the-mmc-message-ocx-control).

## See also

[IConsole](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iconsole)