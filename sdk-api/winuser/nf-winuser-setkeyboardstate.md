# SetKeyboardState function

## Description

Copies an array of keyboard key states into the calling thread's keyboard input-state table. This is the same table accessed by the [GetKeyboardState](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getkeyboardstate) and [GetKeyState](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getkeystate) functions. Changes made to this table do not affect keyboard input to any other thread.

## Parameters

### `lpKeyState` [in]

Type: **LPBYTE**

A pointer to a 256-byte array that contains keyboard key states.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Because the **SetKeyboardState** function alters the input state of the calling thread and not the global input state of the system, an application cannot use **SetKeyboardState** to set the NUM LOCK, CAPS LOCK, or SCROLL LOCK (or the Japanese KANA) indicator lights on the keyboard. These can be set or cleared using [SendInput](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendinput) to simulate keystrokes.

## See also

- [GetAsyncKeyState](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getasynckeystate)
- [GetKeyState](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getkeystate)
- [GetKeyboardState](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getkeyboardstate)
- [GetSystemMetrics](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsystemmetrics)
- [MapVirtualKey](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-mapvirtualkeya)
- [SetKeyboardState](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setkeyboardstate)
- [SendInput](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendinput)
- [keybd_event](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-keybd_event)
- [Keyboard Input](https://learn.microsoft.com/windows/desktop/inputdev/keyboard-input)