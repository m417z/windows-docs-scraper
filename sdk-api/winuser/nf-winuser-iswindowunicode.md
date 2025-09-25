# IsWindowUnicode function

## Description

Determines whether the specified window is a native Unicode window.

## Parameters

### `hWnd` [in]

Type: **HWND**

A handle to the window to be tested.

## Return value

Type: **BOOL**

If the window is a native Unicode window, the return value is nonzero.

If the window is not a native Unicode window, the return value is zero. The window is a native ANSI window.

## Remarks

The character set of a window is determined by the use of the [RegisterClass](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerclassa) function. If the window class was registered with the ANSI version of **RegisterClass** (**RegisterClassA**), the character set of the window is ANSI. If the window class was registered with the Unicode version of **RegisterClass** (**RegisterClassW**), the character set of the window is Unicode.

The system does automatic two-way translation (Unicode to ANSI) for window messages. For example, if an ANSI window message is sent to a window that uses the Unicode character set, the system translates that message into a Unicode message before calling the window procedure. The system calls **IsWindowUnicode** to determine whether to translate the message.

## See also

[Windows Overview](https://learn.microsoft.com/windows/desktop/winmsg/windows)