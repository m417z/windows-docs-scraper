# ToUnicodeEx function

## Description

Translates the specified virtual-key code and keyboard state to the corresponding Unicode character or characters.

## Parameters

### `wVirtKey` [in]

Type: **UINT**

The virtual-key code to be translated. See [Virtual-Key Codes](https://learn.microsoft.com/windows/desktop/inputdev/virtual-key-codes).

### `wScanCode` [in]

Type: **UINT**

The hardware [scan code](https://learn.microsoft.com/windows/win32/inputdev/about-keyboard-input#scan-codes) of the key to be translated. The high-order bit of this value is set if the key is up.

### `lpKeyState` [in]

Type: **const BYTE***

A pointer to a 256-byte array that contains the current keyboard state. Each element (byte) in the array contains the state of one key.

If the high-order bit of a byte is set, the key is down. The low bit, if set, indicates that the key is toggled on. In this function, only the toggle bit of the CAPS LOCK key is relevant. The toggle state of the NUM LOCK and SCROLL LOCK keys is ignored. See [GetKeyboardState](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-getkeyboardstate) for more info.

### `pwszBuff` [out]

Type: **LPWSTR**

The buffer that receives the translated character or characters as array of UTF-16 code units. This buffer may be returned without being null-terminated even though the variable name suggests that it is null-terminated. You can use the return value of this method to determine how many characters were written.

### `cchBuff` [in]

Type: **int**

The size, in characters, of the buffer pointed to by the *pwszBuff* parameter.

### `wFlags` [in]

Type: **UINT**

The behavior of the function.

If bit 0 is set, a menu is active. In this mode **Alt+Numeric keypad** key combinations are not handled.

If bit 1 is set, **ToUnicodeEx** will translate scancodes marked as key break events in addition to its usual treatment of key make events.

If bit 2 is set, keyboard state is not changed (Windows 10, version 1607 and newer)

All other bits (through 31) are reserved.

### `dwhkl` [in, optional]

Type: **HKL**

The input locale identifier used to translate the specified code. This parameter can be any input locale identifier previously returned by the [LoadKeyboardLayout](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadkeyboardlayouta) function.

## Return value

Type: **int**

The function returns one of the following values.

| Return value | Description |
| --- | --- |
| *value* < 0 | The specified virtual key is a [dead key](https://learn.microsoft.com/windows/win32/inputdev/about-keyboard-input#dead-character-messages) character (accent or diacritic). This value is returned regardless of the keyboard layout, even if several characters have been typed and are stored in the keyboard state. If possible, even with Unicode keyboard layouts, the function has written a spacing version of the dead-key character to the buffer specified by *pwszBuff*. For example, the function writes the character ACUTE ACCENT (U+00B4), rather than the character COMBINING ACUTE ACCENT (U+0301). |
| 0 | The specified virtual key has no translation for the current state of the keyboard. Nothing was written to the buffer specified by *pwszBuff*. |
| *value* > 0 | One or more UTF-16 code units were written to the buffer specified by *pwszBuff*. Returned *pwszBuff* may contain more characters than the return value specifies. When this happens, any extra characters are invalid and should be ignored. |

## Remarks

The input locale identifier is a broader concept than a keyboard layout, since it can also encompass a speech-to-text converter, an Input Method Editor (IME), or any other form of input.

Some keyboard layouts may return several characters and/or supplementary characters as [surrogate pairs](https://learn.microsoft.com/windows/win32/intl/surrogates-and-supplementary-characters) in *pwszBuff*. If dead key character (accent or diacritic) stored in the keyboard layout could not be combined with the specified virtual key to form a single character then the previous entered dead character can be combined with the current character.

The parameters supplied to the **ToUnicodeEx** function might not be sufficient to translate the virtual-key code because a previous [dead key](https://learn.microsoft.com/windows/win32/inputdev/about-keyboard-input#dead-character-messages) is stored in the keyboard layout.

Typically, **ToUnicodeEx** performs the translation based on the virtual-key code. In some cases, however, bit 15 of the *wScanCode* parameter can be used to distinguish between a key press and a key release (for example for ALT+numpad key entry).

As **ToUnicodeEx** translates the virtual-key code, it also changes the state of the kernel-mode keyboard buffer. This state-change affects dead keys, ligatures, **Alt+Numeric keypad** key entry, and so on. It might also cause undesired side-effects if used in conjunction with [TranslateMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-translatemessage) (which also changes the state of the kernel-mode keyboard buffer).

## See also

**Conceptual**

[Keyboard Input](https://learn.microsoft.com/windows/desktop/inputdev/keyboard-input)

[LoadKeyboardLayout](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadkeyboardlayouta)

**Reference**

[ToAsciiEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-toasciiex)

[VkKeyScan](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-vkkeyscana)