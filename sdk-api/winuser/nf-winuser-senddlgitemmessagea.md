# SendDlgItemMessageA function

## Description

Sends a message to the specified control in a dialog box.

## Parameters

### `hDlg` [in]

Type: **HWND**

A handle to the dialog box that contains the control.

### `nIDDlgItem` [in]

Type: **int**

The identifier of the control that receives the message.

### `Msg` [in]

Type: **UINT**

The message to be sent.

For lists of the system-provided messages, see [System-Defined Messages](https://learn.microsoft.com/windows/desktop/winmsg/about-messages-and-message-queues).

### `wParam` [in]

Type: **WPARAM**

Additional message-specific information.

### `lParam` [in]

Type: **LPARAM**

Additional message-specific information.

## Return value

Type: **LRESULT**

The return value specifies the result of the message processing and depends on the message sent.

## Remarks

The **SendDlgItemMessage** function does not return until the message has been processed.

Using **SendDlgItemMessage** is identical to retrieving a handle to the specified control and calling the [SendMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendmessage) function.

#### Examples

For an example, see [Creating a Modeless Dialog Box](https://learn.microsoft.com/windows/desktop/dlgbox/using-dialog-boxes).

> [!NOTE]
> The winuser.h header defines SendDlgItemMessage as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

**Conceptual**

[Dialog Boxes](https://learn.microsoft.com/windows/desktop/dlgbox/dialog-boxes)

**Reference**

[SendMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendmessage)