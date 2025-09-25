# VkKeyScanA function

## Description

[This function has been superseded by the [VkKeyScanEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-vkkeyscanexa) function. You can still use **VkKeyScan**, however, if you do not need to specify a keyboard layout.]

Translates a character to the corresponding virtual-key code and shift state for the current keyboard.

## Parameters

### `ch` [in]

Type: **TCHAR**

The character to be translated into a virtual-key code.

## Return value

Type: **SHORT**

If the function succeeds, the low-order byte of the return value contains the virtual-key code and the high-order byte contains the shift state, which can be a combination of the following flag bits.

| Return value | Description |
| --- | --- |
| 1 | Either SHIFT key is pressed. |
| 2 | Either CTRL key is pressed. |
| 4 | Either ALT key is pressed. |
| 8 | The Hankaku key is pressed |
| 16 | Reserved (defined by the keyboard layout driver). |
| 32 | Reserved (defined by the keyboard layout driver). |

If the function finds no key that translates to the passed character code, both the low-order and high-order bytes contain
–1.

## Remarks

For keyboard layouts that use the right-hand ALT key as a shift key (for example, the French keyboard layout), the shift state is represented by the value 6, because the right-hand ALT key is converted internally into CTRL+ALT.

Translations for the numeric keypad (**VK_NUMPAD0** through **VK_DIVIDE**) are ignored. This function is intended to translate characters into keystrokes from the main keyboard section only. For example, the character "7" is translated into VK_7, not VK_NUMPAD7.

**VkKeyScan** is used by applications that send characters by using the [WM_KEYUP](https://learn.microsoft.com/windows/desktop/inputdev/wm-keyup) and [WM_KEYDOWN](https://learn.microsoft.com/windows/desktop/inputdev/wm-keydown) messages.

> [!NOTE]
> The winuser.h header defines VkKeyScan as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

- [GetAsyncKeyState](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getasynckeystate)
- [GetKeyNameText](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getkeynametexta)
- [GetKeyState](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getkeystate)
- [GetKeyboardState](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getkeyboardstate)
- [Keyboard Input](https://learn.microsoft.com/windows/desktop/inputdev/keyboard-input)
- [SetKeyboardState](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setkeyboardstate)
- [VkKeyScanEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-vkkeyscanexa)
- [WM_KEYDOWN](https://learn.microsoft.com/windows/desktop/inputdev/wm-keydown)
- [WM_KEYUP](https://learn.microsoft.com/windows/desktop/inputdev/wm-keyup)
- [Keyboard Input](https://learn.microsoft.com/windows/desktop/inputdev/keyboard-input)