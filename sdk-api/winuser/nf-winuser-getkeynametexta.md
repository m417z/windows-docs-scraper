# GetKeyNameTextA function

## Description

Retrieves a string that represents the name of a key.

## Parameters

### `lParam` [in]

Type: **LONG**

The second parameter of the keyboard message (such as [WM_KEYDOWN](https://learn.microsoft.com/windows/desktop/inputdev/wm-keydown)) to be processed. The function interprets the following bit positions in the *lParam*.

| Bits | Meaning |
|-------|---------|
| 16-23 | The scan code. The value depends on the OEM. |
| 24 | Indicates whether the key is an extended key, such as the right-hand ALT and CTRL keys that appear on an enhanced 101- or 102-key keyboard. The value is 1 if it is an extended key; otherwise, it is 0. |
| 25 | "Do not care" bit. The application calling this function sets this bit to indicate that the function should not distinguish between left and right CTRL and SHIFT keys, for example. |

For more detail, see [Keystroke Message Flags](https://learn.microsoft.com/windows/win32/inputdev/about-keyboard-input#keystroke-message-flags).

### `lpString` [out]

Type: **LPTSTR**

The buffer that will receive the key name.

### `cchSize` [in]

Type: **int**

The maximum length, in characters, of the key name, including the terminating null character. (This parameter should be equal to the size of the buffer pointed to by the *lpString* parameter.)

## Return value

Type: **int**

If the function succeeds, a null-terminated string is copied into the specified buffer, and the return value is the length of the string, in characters, not counting the terminating null character.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The format of the key-name string depends on the current keyboard layout.

The keyboard layout maintains a list of names in the form of character strings for keys with names longer than a single character.
The key name is translated according to the [currently active keyboard layout](https://learn.microsoft.com/windows/win32/inputdev/about-keyboard-input#languages-locales-and-keyboard-layouts), therefore the function might return different results for different [keyboard layouts](https://learn.microsoft.com/globalization/windows-keyboard-layouts).

The name of a character key is the character itself. The names of dead keys are spelled out in full.

Character keys that are mapped to the 'A'..'Z' [virtual-key codes](https://learn.microsoft.com/windows/win32/inputdev/virtual-key-codes) are translated to the .. characters regardless of current keyboard layout. In this case, use the [ToUnicode](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-tounicode) or [ToUnicodeEx](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-tounicodeex) methods to get the character for the corresponding key press.

This method might not work properly with some [keyboard layouts](https://learn.microsoft.com/globalization/windows-keyboard-layouts) that produce multiple characters (such as ligatures) or supplementary Unicode characters on a single key press.

The winuser.h header defines GetKeyNameText as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Keyboard Input](https://learn.microsoft.com/windows/desktop/inputdev/keyboard-input)

[Keyboard Layouts](https://learn.microsoft.com/globalization/windows-keyboard-layouts)

[Keyboard Layout Samples](https://learn.microsoft.com/samples/microsoft/windows-driver-samples/keyboard-layout-samples)

[ToUnicode](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-tounicode)

[ToUnicodeEx](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-tounicodeex)