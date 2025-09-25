# GetKeyState function

## Description

Retrieves the status of the specified virtual key. The status specifies whether the key is up, down, or toggled (on, off—alternating each time the key is pressed).

## Parameters

### `nVirtKey` [in]

Type: **int**

A virtual key. If the desired virtual key is a letter or digit (A through Z, a through z, or 0 through 9),
*nVirtKey* must be set to the ASCII value of that character. For other keys, it must be a virtual-key code.

If a non-English keyboard layout is used, virtual keys with values in the range ASCII A through Z and 0 through 9 are used to specify most of the character keys. For example, for the German keyboard layout, the virtual key of value ASCII O (0x4F) refers to the "o" key, whereas VK_OEM_1 refers to the "o with umlaut" key.

## Return value

Type: **SHORT**

The return value specifies the status of the specified virtual key, as follows:

* If the high-order bit is 1, the key is down; otherwise, it is up.
* If the low-order bit is 1, the key is toggled. A key, such as the CAPS LOCK key, is toggled if it is turned on. The key is off and untoggled if the low-order bit is 0. A toggle key's indicator light (if any) on the keyboard will be on when the key is toggled, and off when the key is untoggled.

## Remarks

The key status returned from this function changes as a thread reads key messages from its message queue. The status does not reflect the interrupt-level state associated with the hardware. Use the [GetAsyncKeyState](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getasynckeystate) function to retrieve that information.

An application calls **GetKeyState** in response to a keyboard-input message. This function retrieves the state of the key when the input message was generated.

To retrieve state information for all the virtual keys, use the [GetKeyboardState](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getkeyboardstate) function.

An application can use the [virtual key code](https://learn.microsoft.com/windows/desktop/inputdev/virtual-key-codes) constants **VK_SHIFT**, **VK_CONTROL**, and **VK_MENU** as values for the
*nVirtKey* parameter. This gives the status of the SHIFT, CTRL, or ALT keys without distinguishing between left and right. An application can also use the following virtual-key code constants as values for
*nVirtKey* to distinguish between the left and right instances of those keys:

**VK_LSHIFT**
**VK_RSHIFT**
**VK_LCONTROL**
**VK_RCONTROL**
**VK_LMENU**
**VK_RMENU**
These left- and right-distinguishing constants are available to an application only through the [GetKeyboardState](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getkeyboardstate), [SetKeyboardState](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setkeyboardstate), [GetAsyncKeyState](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getasynckeystate), **GetKeyState**, and [MapVirtualKey](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-mapvirtualkeya) functions.

#### Examples

For an example, see [Displaying Keyboard Input](https://learn.microsoft.com/windows/desktop/inputdev/using-keyboard-input).

## See also

- [GetAsyncKeyState](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getasynckeystate)
- [GetKeyState](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getkeystate)
- [GetKeyboardState](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getkeyboardstate)
- [MapVirtualKey](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-mapvirtualkeya)
- [SetKeyboardState](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setkeyboardstate)
- [Keyboard Input](https://learn.microsoft.com/windows/desktop/inputdev/keyboard-input)