# ToAsciiEx function

## Description

Translates the specified virtual-key code and keyboard state to the corresponding character or characters. The function translates the code using the input language and physical keyboard layout identified by the input locale identifier.

> [!NOTE]
> This method may not work properly with some [keyboard layouts](https://learn.microsoft.com/globalization/windows-keyboard-layouts) that may produce multiple characters (i.e. ligatures) and/or supplementary Unicode characters on a single key press. It is highly recommended to use the [ToUnicode](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-tounicode) or [ToUnicodeEx](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-tounicodeex) methods that handles such cases properly.

## Parameters

### `uVirtKey` [in]

Type: **UINT**

The virtual-key code to be translated. See [Virtual-Key Codes](https://learn.microsoft.com/windows/desktop/inputdev/virtual-key-codes).

### `uScanCode` [in]

Type: **UINT**

The hardware scan code of the key to be translated. The high-order bit of this value is set if the key is up (not pressed).

### `lpKeyState` [in, optional]

Type: **const BYTE***

A pointer to a 256-byte array that contains the current keyboard state. Each element (byte) in the array contains the state of one key. If the high-order bit of a byte is set, the key is down (pressed).

The low bit, if set, indicates that the key is toggled on. In this function, only the toggle bit of the CAPS LOCK key is relevant. The toggle state of the NUM LOCK and SCOLL LOCK keys is ignored.

### `lpChar` [out]

Type: **LPWORD**

A pointer to the buffer that receives the translated character (or two characters packed into a single **WORD** value, where the low-order byte contains the first character and the high-order byte contains the second character).

### `uFlags` [in]

Type: **UINT**

This parameter must be 1 if a menu is active, zero otherwise.

### `dwhkl` [in, optional]

Type: **HKL**

Input locale identifier to use to translate the code. This parameter can be any input locale identifier previously returned by the [LoadKeyboardLayout](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadkeyboardlayouta) function.

## Return value

Type: **int**

The return value is one of the following values.

| Return value | Description |
| --- | --- |
| 0 | The specified virtual key has no translation for the current state of the keyboard. |
| 1 | One character was copied to the buffer. |
| 2 | Two characters were copied to the buffer. This usually happens when a dead-key character (accent or diacritic) stored in the keyboard layout cannot be composed with the specified virtual key to form a single character. |

## Remarks

The input locale identifier is a broader concept than a keyboard layout, since it can also encompass a speech-to-text converter, an Input Method Editor (IME), or any other form of input.

The parameters supplied to the **ToAsciiEx** function might not be sufficient to translate the virtual-key code, because a previous dead key is stored in the keyboard layout.

Typically, **ToAsciiEx** performs the translation based on the virtual-key code. In some cases, however, bit 15 of the
*uScanCode* parameter may be used to distinguish between a key press and a key release. The scan code is used for translating ALT+number key combinations.

Although NUM LOCK is a toggle key that affects keyboard behavior, **ToAsciiEx** ignores the toggle setting (the low bit) of
*lpKeyState* (**VK_NUMLOCK**) because the
*uVirtKey* parameter alone is sufficient to distinguish the cursor movement keys (**VK_HOME**, **VK_INSERT**, and so on) from the numeric keys (**VK_DECIMAL**, **VK_NUMPAD0** - **VK_NUMPAD9**).

## See also

**Conceptual**

[Keyboard Input](https://learn.microsoft.com/windows/desktop/inputdev/keyboard-input)

[LoadKeyboardLayout](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadkeyboardlayouta)

[MapVirtualKeyEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-mapvirtualkeyexa)

**Reference**

[ToUnicodeEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-tounicodeex)

[VkKeyScan](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-vkkeyscana)