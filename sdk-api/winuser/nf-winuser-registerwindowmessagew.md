# RegisterWindowMessageW function

## Description

Defines a new window message that is guaranteed to be unique throughout the system. The message value can be used when sending or posting messages.

## Parameters

### `lpString` [in]

Type: **LPCTSTR**

The message to be registered.

## Return value

Type: **UINT**

If the message is successfully registered, the return value is a message identifier in the range 0xC000 through 0xFFFF.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **RegisterWindowMessage** function is typically used to register messages for communicating between two cooperating applications.

If two different applications register the same message string, the applications return the same message value. The message remains registered until the session ends.

Only use **RegisterWindowMessage** when more than one application must process the same message. For sending private messages within a window class, an application can use any integer in the range [WM_USER](https://learn.microsoft.com/windows/desktop/winmsg/wm-user) through 0x7FFF. (Messages in this range are private to a window class, not to an application. For example, predefined control classes such as **BUTTON**, **EDIT**, **LISTBOX**, and **COMBOBOX** may use values in this range.)

#### Examples

For an example, see [Finding Text](https://learn.microsoft.com/windows/desktop/dlgbox/using-common-dialog-boxes).

> [!NOTE]
> The winuser.h header defines RegisterWindowMessage as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

**Conceptual**

[Messages and Message Queues](https://learn.microsoft.com/windows/desktop/winmsg/messages-and-message-queues)

[PostMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-postmessagea)

**Reference**

[SendMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendmessage)