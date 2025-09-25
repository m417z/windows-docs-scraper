# MessageBox function

## Description

Displays a modal dialog box that contains a system icon, a set of buttons, and a brief application-specific message, such as status or error information. The message box returns an integer value that indicates which button the user clicked.

## Parameters

### `hWnd` [in, optional]

Type: **HWND**

A handle to the owner window of the message box to be created. If this parameter is **NULL**, the message box has no owner window.

### `lpText` [in, optional]

Type: **LPCTSTR**

The message to be displayed. If the string consists of more than one line, you can separate the lines using a carriage return and/or linefeed character between each line.

### `lpCaption` [in, optional]

Type: **LPCTSTR**

The dialog box title. If this parameter is **NULL**, the default title is **Error**.

### `uType` [in]

Type: **UINT**

The contents and behavior of the dialog box. This parameter can be a combination of flags from the following groups of flags.

To indicate the buttons displayed in the message box, specify one of the following values.

| Value | Meaning |
| --- | --- |
| **MB_ABORTRETRYIGNORE**<br><br>0x00000002L | The message box contains three push buttons: **Abort**, **Retry**, and **Ignore**. |
| **MB_CANCELTRYCONTINUE**<br><br>0x00000006L | The message box contains three push buttons: **Cancel**, **Try Again**, **Continue**. Use this message box type instead of MB_ABORTRETRYIGNORE. |
| **MB_HELP**<br><br>0x00004000L | Adds a **Help** button to the message box. When the user clicks the **Help** button or presses F1, the system sends a [WM_HELP](https://learn.microsoft.com/windows/desktop/shell/wm-help) message to the owner. |
| **MB_OK**<br><br>0x00000000L | The message box contains one push button: **OK**. This is the default. |
| **MB_OKCANCEL**<br><br>0x00000001L | The message box contains two push buttons: **OK** and **Cancel**. |
| **MB_RETRYCANCEL**<br><br>0x00000005L | The message box contains two push buttons: **Retry** and **Cancel**. |
| **MB_YESNO**<br><br>0x00000004L | The message box contains two push buttons: **Yes** and **No**. |
| **MB_YESNOCANCEL**<br><br>0x00000003L | The message box contains three push buttons: **Yes**, **No**, and **Cancel**. |

To display an icon in the message box, specify one of the following values.

| Value | Meaning |
| --- | --- |
| **MB_ICONEXCLAMATION**<br><br>0x00000030L | An exclamation-point icon appears in the message box. |
| **MB_ICONWARNING**<br><br>0x00000030L | An exclamation-point icon appears in the message box. |
| **MB_ICONINFORMATION**<br><br>0x00000040L | An icon consisting of a lowercase letter *i* in a circle appears in the message box. |
| **MB_ICONASTERISK**<br><br>0x00000040L | An icon consisting of a lowercase letter *i* in a circle appears in the message box. |
| **MB_ICONQUESTION**<br><br>0x00000020L | A question-mark icon appears in the message box. The question-mark message icon is no longer recommended because it does not clearly represent a specific type of message and because the phrasing of a message as a question could apply to any message type. In addition, users can confuse the message symbol question mark with Help information. Therefore, do not use this question mark message symbol in your message boxes. The system continues to support its inclusion only for backward compatibility. |
| **MB_ICONSTOP**<br><br>0x00000010L | A stop-sign icon appears in the message box. |
| **MB_ICONERROR**<br><br>0x00000010L | A stop-sign icon appears in the message box. |
| **MB_ICONHAND**<br><br>0x00000010L | A stop-sign icon appears in the message box. |

To indicate the default button, specify one of the following values.

| Value | Meaning |
| --- | --- |
| **MB_DEFBUTTON1**<br><br>0x00000000L | The first button is the default button.<br><br>**MB_DEFBUTTON1** is the default unless **MB_DEFBUTTON2**, **MB_DEFBUTTON3**, or **MB_DEFBUTTON4** is specified. |
| **MB_DEFBUTTON2**<br><br>0x00000100L | The second button is the default button. |
| **MB_DEFBUTTON3**<br><br>0x00000200L | The third button is the default button. |
| **MB_DEFBUTTON4**<br><br>0x00000300L | The fourth button is the default button. |

To indicate the modality of the dialog box, specify one of the following values.

| Value | Meaning |
| --- | --- |
| **MB_APPLMODAL**<br><br>0x00000000L | The user must respond to the message box before continuing work in the window identified by the *hWnd* parameter. However, the user can move to the windows of other threads and work in those windows.<br><br>Depending on the hierarchy of windows in the application, the user may be able to move to other windows within the thread. All child windows of the parent of the message box are automatically disabled, but pop-up windows are not.<br><br>**MB_APPLMODAL** is the default if neither **MB_SYSTEMMODAL** nor **MB_TASKMODAL** is specified. |
| **MB_SYSTEMMODAL**<br><br>0x00001000L | Same as MB_APPLMODAL except that the message box has the **WS_EX_TOPMOST** style. Use system-modal message boxes to notify the user of serious, potentially damaging errors that require immediate attention (for example, running out of memory). This flag has no effect on the user's ability to interact with windows other than those associated with *hWnd*. |
| **MB_TASKMODAL**<br><br>0x00002000L | Same as **MB_APPLMODAL** except that all the top-level windows belonging to the current thread are disabled if the *hWnd* parameter is **NULL**. Use this flag when the calling application or library does not have a window handle available but still needs to prevent input to other windows in the calling thread without suspending other threads. |

To specify other options, use one or more of the following values.

| Value | Meaning |
| --- | --- |
| **MB_DEFAULT_DESKTOP_ONLY**<br><br>0x00020000L | Same as desktop of the interactive window station. For more information, see [Window Stations](https://learn.microsoft.com/windows/desktop/winstation/window-stations).<br><br> If the current input desktop is not the default desktop, **MessageBox** does not return until the user switches to the default desktop. |
| **MB_RIGHT**<br><br>0x00080000L | The text is right-justified. |
| **MB_RTLREADING**<br><br>0x00100000L | Displays message and caption text using right-to-left reading order on Hebrew and Arabic systems. |
| **MB_SETFOREGROUND**<br><br>0x00010000L | The message box becomes the foreground window. Internally, the system calls the [SetForegroundWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setforegroundwindow) function for the message box. |
| **MB_TOPMOST**<br><br>0x00040000L | The message box is created with the **WS_EX_TOPMOST** window style. |
| **MB_SERVICE_NOTIFICATION**<br><br>0x00200000L | The caller is a service notifying the user of an event. The function displays a message box on the current active desktop, even if there is no user logged on to the computer.<br><br>**Terminal Services:** If the calling thread has an impersonation token, the function directs the message box to the session specified in the impersonation token.<br><br>If this flag is set, the *hWnd* parameter must be **NULL**. This is so that the message box can appear on a desktop other than the desktop corresponding to the *hWnd*.<br><br>For information on security considerations in regard to using this flag, see [Interactive Services](https://learn.microsoft.com/windows/desktop/Services/interactive-services). In particular, be aware that this flag can produce interactive content on a locked desktop and should therefore be used for only a very limited set of scenarios, such as resource exhaustion. |

## Return value

Type: **int**

If a message box has a **Cancel** button, the function returns the **IDCANCEL** value if either the ESC key is pressed or the **Cancel** button is selected. If the message box has no **Cancel** button, pressing ESC will no effect - unless an MB_OK button is present. If an MB_OK button is displayed and the user presses ESC, the return value will be **IDOK**.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

If the function succeeds, the return value is one of the following menu-item values.

| Return code/value | Description |
| --- | --- |
| **IDABORT**<br><br>3 | The **Abort** button was selected. |
| **IDCANCEL**<br><br>2 | The **Cancel** button was selected. |
| **IDCONTINUE**<br><br>11 | The **Continue** button was selected. |
| **IDIGNORE**<br><br>5 | The **Ignore** button was selected. |
| **IDNO**<br><br>7 | The **No** button was selected. |
| **IDOK**<br><br>1 | The **OK** button was selected. |
| **IDRETRY**<br><br>4 | The **Retry** button was selected. |
| **IDTRYAGAIN**<br><br>10 | The **Try Again** button was selected. |
| **IDYES**<br><br>6 | The **Yes** button was selected. |

## Remarks

The following system icons can be used in a message box by setting the *uType* parameter to the corresponding flag value.

| Icon | Flag values |
| --- | --- |
| ![Icon for MB_ICONHAND, MB_ICONSTOP, and MB_ICONERROR](https://learn.microsoft.com/windows/win32/api/winuser/images/MB_ICONHAND.png) | **MB_ICONHAND**, **MB_ICONSTOP**, or **MB_ICONERROR** |
| ![Icon for MB_ICONQUESTION](https://learn.microsoft.com/windows/win32/api/winuser/images/MB_ICONQUESTION.png) | **MB_ICONQUESTION** |
| ![Icon for MB_ICONEXCLAMATION and MB_ICONWARNING](https://learn.microsoft.com/windows/win32/api/winuser/images/MB_ICONEXCLAMATION.png) | **MB_ICONEXCLAMATION** or **MB_ICONWARNING** |
| ![Icon for MB_ICONASTERISK and MB_ICONINFORMATION](https://learn.microsoft.com/windows/win32/api/winuser/images/MB_ICONASTERISK.png) | **MB_ICONASTERISK** or **MB_ICONINFORMATION** |

Adding two right-to-left marks (RLMs), represented by Unicode formatting character U+200F, in the beginning of a MessageBox display string is interpreted by the MessageBox rendering engine so as to cause the reading order of the MessageBox to be rendered as right-to-left (RTL).

When you use a system-modal message box to indicate that the system is low on memory, the strings pointed to by the *lpText* and *lpCaption* parameters should not be taken from a resource file because an attempt to load the resource may fail.

If you create a message box while a dialog box is present, use a handle to the dialog box as the *hWnd* parameter. The *hWnd* parameter should not identify a child window, such as a control in a dialog box.

#### Examples

In the following example, the application displays a message box that prompts the user for an action after an error condition has occurred. The message box displays the message that describes the error condition and how to resolve it. The **MB_CANCELTRYCONTINUE** style directs **MessageBox** to provide three buttons with which the user can choose how to proceed. The **MB_DEFBUTTON2** style sets the default focus on the second button of the message box, in this case, the **Try Again** button.

```cpp
int DisplayResourceNAMessageBox()
{
    int msgboxID = MessageBox(
        NULL,
        (LPCWSTR)L"Resource not available\nDo you want to try again?",
        (LPCWSTR)L"Account Details",
        MB_ICONWARNING | MB_CANCELTRYCONTINUE | MB_DEFBUTTON2
    );

    switch (msgboxID)
    {
    case IDCANCEL:
        // TODO: add code
        break;
    case IDTRYAGAIN:
        // TODO: add code
        break;
    case IDCONTINUE:
        // TODO: add code
        break;
    }

    return msgboxID;
}
```

The following image shows the output from the preceding code example:

![Message box](https://learn.microsoft.com/windows/win32/api/winuser/images/messagebox_02.png)

For another message box example, see [Displaying a Message Box](https://learn.microsoft.com/windows/desktop/dlgbox/using-dialog-boxes).

## See also

**Conceptual**

[Dialog Boxes](https://learn.microsoft.com/windows/desktop/dlgbox/dialog-boxes)

[FlashWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-flashwindow)

[MessageBeep](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-messagebeep)

[MessageBoxEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-messageboxexa)

[MessageBoxIndirect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-messageboxindirecta)

**Other Resources**

**Reference**

[SetForegroundWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setforegroundwindow)