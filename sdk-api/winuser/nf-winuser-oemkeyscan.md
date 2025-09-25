# OemKeyScan function

## Description

Maps OEMASCII codes 0 through 0x0FF into the OEM scan codes and shift states. The function provides information that allows a program to send OEM text to another program by simulating keyboard input.

## Parameters

### `wOemChar` [in]

Type: **WORD**

The ASCII value of the OEM character.

## Return value

Type: **DWORD**

The low-order word of the return value contains the scan code of the OEM character, and the high-order word contains the shift state, which can be a combination of the following bits.

| Bit | Description |
| --- | --- |
| 1 | Either SHIFT key is pressed. |
| 2 | Either CTRL key is pressed. |
| 4 | Either ALT key is pressed. |
| 8 | The Hankaku key is pressed. |
| 16 | Reserved (defined by the keyboard layout driver). |
| 32 | Reserved (defined by the keyboard layout driver). |

If the character cannot be produced by a single keystroke using the current keyboard layout, the return value is
–1.

## Remarks

This function does not provide translations for characters that require CTRL+ALT or dead keys. Characters not translated by this function must be copied by simulating input using the ALT+ keypad mechanism. The NUMLOCK key must be off.

This function does not provide translations for characters that cannot be typed with one keystroke using the current keyboard layout, such as characters with diacritics requiring dead keys. Characters not translated by this function may be simulated using the ALT+ keypad mechanism. The NUMLOCK key must be on.

This function is implemented using the [VkKeyScan](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-vkkeyscana) function.

## See also

**Conceptual**

[Keyboard Input](https://learn.microsoft.com/windows/desktop/inputdev/keyboard-input)

**Reference**

[VkKeyScan](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-vkkeyscana)