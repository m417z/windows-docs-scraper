# GetAsyncKeyState function

## Description

Determines whether a key is up or down at the time the function is called, and whether the key has been pressed since a previous call to **GetAsyncKeyState**.

## Parameters

### `vKey` [in]

Type: **int**

The virtual-key code. For more information, see [Virtual Key Codes](https://learn.microsoft.com/windows/desktop/inputdev/virtual-key-codes).

You can use left- and right-distinguishing constants to specify certain keys. See the Remarks section for further information.

## Return value

Type: **SHORT**

The most significant bit of the return value is set if the specified key is currently down.
Since the most significant bit is the sign bit, a negative value indicates that the key is currently down.

For backward compatibility,
the least significant bit is set if the specified key has been pressed since the most
recent previous call in the session to **GetAsyncKeyState** for that key,
but the value is unreliable. (See Remarks.)

All other bits of the result are reserved and should be ignored.

The return value is zero if the call fails.
Reasons for failure include

* The current desktop is not the active desktop.
* UI Privilege Isolation (UIPI) prevents the calling thread from accessing the foreground thread.
* The foreground thread belongs to another process and the calling thread does not have **DESKTOP_HOOKCONTROL** or **DESKTOP_JOURNALRECORD** access to its desktop.

## Remarks

The **GetAsyncKeyState** function works with mouse buttons. However, it checks on the state of the physical mouse buttons, not on the logical mouse buttons that the physical buttons are mapped to. For example, the call **GetAsyncKeyState**(VK_LBUTTON) always returns the state of the left physical mouse button, regardless of whether it is mapped to the left or right logical mouse button. You can determine the system's current mapping of physical mouse buttons to logical mouse buttons by calling `GetSystemMetrics(SM_SWAPBUTTON)`,
which returns TRUE if the mouse buttons have been swapped.

Although the least significant bit of the return value indicates whether the key has been pressed since the last query, due to the preemptive multitasking nature of Windows, another application can call **GetAsyncKeyState** and receive the "recently pressed" bit instead of your application. The behavior of the least significant bit of the return value is retained for compatibility with 16-bit Windows applications (which are non-preemptive) and should not be relied upon because it can report false negatives.

You can use the virtual-key code constants **VK_SHIFT**, **VK_CONTROL**, and **VK_MENU** as values for the
*vKey* parameter. This gives the state of the SHIFT, CTRL, or ALT keys without distinguishing between left and right.

You can use the following virtual-key code constants as values for
*vKey* to distinguish between the left and right instances of those keys.

| Code | Meaning |
| --- | --- |
| **VK_LSHIFT** | Left-shift key. |
| **VK_RSHIFT** | Right-shift key. |
| **VK_LCONTROL** | Left-control key. |
| **VK_RCONTROL** | Right-control key. |
| **VK_LMENU** | Left-menu key. |
| **VK_RMENU** | Right-menu key. |

These left- and right-distinguishing constants are only available when you call the [GetKeyboardState](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getkeyboardstate), [SetKeyboardState](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setkeyboardstate), **GetAsyncKeyState**, [GetKeyState](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getkeystate), and [MapVirtualKey](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-mapvirtualkeya) functions.

## Example

```cpp
int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hInstPrev, PSTR cmdline, int cmdshow)
{
    BOOL considerSafeMode = FALSE;

    // If the user holds the CTRL key while the app is launching,
    // then offer to enter Safe Mode.
    if (GetAsyncKeyState(VK_CONTROL) < 0)
    {
        considerSafeMode = TRUE;
    }

    ...
}
```

## See also

- [GetAsyncKeyState](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getasynckeystate)
- [GetKeyState](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getkeystate)
- [GetKeyboardState](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getkeyboardstate)
- [GetSystemMetrics](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsystemmetrics)
- [MapVirtualKey](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-mapvirtualkeya)
- [SetKeyboardState](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setkeyboardstate)
- [Keyboard Input](https://learn.microsoft.com/windows/desktop/inputdev/keyboard-input)