# BlockInput function

## Description

Blocks keyboard and mouse input events from reaching applications.

## Parameters

### `fBlockIt` [in]

Type: **BOOL**

The function's purpose. If this parameter is **TRUE**, keyboard and mouse input events are blocked. If this parameter is **FALSE**, keyboard and mouse events are unblocked. Note that only the thread that blocked input can successfully unblock input.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If input is already blocked, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

When input is blocked, real physical input from the mouse or keyboard will not affect the input queue's synchronous key state (reported by [GetKeyState](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getkeystate) and [GetKeyboardState](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getkeyboardstate)), nor will it affect the asynchronous key state (reported by [GetAsyncKeyState](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getasynckeystate)). However, the thread that is blocking input can affect both of these key states by calling [SendInput](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendinput). No other thread can do this.

The system will unblock input in the following cases:

* The thread that blocked input unexpectedly exits without calling **BlockInput** with
  *fBlock* set to **FALSE**. In this case, the system cleans up properly and re-enables input.
* The user presses CTRL+ALT+DEL or the system invokes the
  **Hard System Error** modal message box (for example, when a program faults or a device fails).

## See also

**Conceptual**

[GetAsyncKeyState](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getasynckeystate)

[GetKeyState](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getkeystate)

[GetKeyboardState](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getkeyboardstate)

[Keyboard Input](https://learn.microsoft.com/windows/desktop/inputdev/keyboard-input)

**Reference**

[SendInput](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendinput)