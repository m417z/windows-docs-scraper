# SendInput function

## Description

Synthesizes keystrokes, mouse motions, and button clicks.

## Parameters

### `cInputs` [in]

Type: **UINT**

The number of structures in the *pInputs* array.

### `pInputs` [in]

Type: **LPINPUT**

An array of [INPUT](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-input) structures. Each structure represents an event to be inserted into the keyboard or mouse input stream.

### `cbSize` [in]

Type: **int**

The size, in bytes, of an [INPUT](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-input) structure. If *cbSize* is not the size of an **INPUT** structure, the function fails.

## Return value

Type: **UINT**

The function returns the number of events that it successfully inserted into the keyboard or mouse input stream. If the function returns zero, the input was already blocked by another thread. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

This function fails when it is blocked by UIPI. Note that neither [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) nor the return value will indicate the failure was caused by UIPI blocking.

## Remarks

This function is subject to UIPI. Applications are permitted to inject input only into applications that are at an equal or lesser integrity level.

The **SendInput** function inserts the events in the [INPUT](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-input) structures serially into the keyboard or mouse input stream. These events are not interspersed with other keyboard or mouse input events inserted either by the user (with the keyboard or mouse) or by calls to [keybd_event](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-keybd_event), [mouse_event](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-mouse_event), or other calls to **SendInput**.

This function does not reset the keyboard's current state. Any keys that are already pressed when the function is called might interfere with the events that this function generates. To avoid this problem, check the keyboard's state with the [GetAsyncKeyState](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getasynckeystate) function and correct as necessary.

Because the touch keyboard uses the surrogate macros defined in winnls.h to send input to the system, a listener on the keyboard event hook must decode input originating from the touch keyboard. For more information, see [Surrogates and Supplementary Characters](https://learn.microsoft.com/windows/desktop/Intl/surrogates-and-supplementary-characters).

An accessibility application can use **SendInput** to inject keystrokes corresponding to application launch shortcut keys that are handled by the shell. This functionality is not guaranteed to work for other types of applications.

## Example

```cpp
//**********************************************************************
//
// Sends Win + D to toggle to the desktop
//
//**********************************************************************
void ShowDesktop()
{
    OutputString(L"Sending 'Win-D'\r\n");
    INPUT inputs[4] = {};
    ZeroMemory(inputs, sizeof(inputs));

    inputs[0].type = INPUT_KEYBOARD;
    inputs[0].ki.wVk = VK_LWIN;

    inputs[1].type = INPUT_KEYBOARD;
    inputs[1].ki.wVk = 'D';

    inputs[2].type = INPUT_KEYBOARD;
    inputs[2].ki.wVk = 'D';
    inputs[2].ki.dwFlags = KEYEVENTF_KEYUP;

    inputs[3].type = INPUT_KEYBOARD;
    inputs[3].ki.wVk = VK_LWIN;
    inputs[3].ki.dwFlags = KEYEVENTF_KEYUP;

    UINT uSent = SendInput(ARRAYSIZE(inputs), inputs, sizeof(INPUT));
    if (uSent != ARRAYSIZE(inputs))
    {
        OutputString(L"SendInput failed: 0x%x\n", HRESULT_FROM_WIN32(GetLastError()));
    }
}
```

## See also

**Conceptual**

[GetAsyncKeyState](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getasynckeystate)

[INPUT](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-input)

[Keyboard Input](https://learn.microsoft.com/windows/desktop/inputdev/keyboard-input)

**Reference**

[Surrogates and Supplementary Characters](https://learn.microsoft.com/windows/desktop/Intl/surrogates-and-supplementary-characters)

[keybd_event](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-keybd_event)

[mouse_event](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-mouse_event)