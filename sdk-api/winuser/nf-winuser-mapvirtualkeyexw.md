# MapVirtualKeyExW function

## Description

Translates (maps) a virtual-key code into a scan code or character value, or translates a scan code into a virtual-key code. The function translates the codes using the input language and an input locale identifier.

## Parameters

### `uCode` [in]

Type: **UINT**

The [virtual key code](https://learn.microsoft.com/windows/desktop/inputdev/virtual-key-codes) or scan code for a key. How this value is interpreted depends on the value of the *uMapType* parameter.

### `uMapType` [in]

Type: **UINT**

The translation to perform. The value of this parameter depends on the value of the *uCode* parameter.

| Value | Meaning |
|-------|---------|
| **MAPVK\_VK\_TO\_VSC**<br>0 | The *uCode* parameter is a virtual-key code and is translated into a scan code. If it is a virtual-key code that does not distinguish between left- and right-hand keys, the left-hand scan code is returned. If there is no translation, the function returns 0. |
| **MAPVK\_VSC\_TO\_VK**<br>1 | The *uCode* parameter is a scan code and is translated into a virtual-key code that does not distinguish between left- and right-hand keys. If there is no translation, the function returns 0.<br>**Windows Vista and later:** the high byte of the *uCode* value can contain either 0xe0 or 0xe1 to specify the extended scan code. |
| **MAPVK\_VK\_TO\_CHAR**<br>2 | The *uCode* parameter is a virtual-key code and is translated into an unshifted character value in the low order word of the return value. Dead keys (diacritics) are indicated by setting the top bit of the return value. If there is no translation, the function returns 0. See Remarks. |
| **MAPVK\_VSC\_TO\_VK\_EX**<br>3 | The *uCode* parameter is a scan code and is translated into a virtual-key code that distinguishes between left- and right-hand keys. If there is no translation, the function returns 0.<br>**Windows Vista and later:** the high byte of the *uCode* value can contain either 0xe0 or 0xe1 to specify the extended scan code. |
| **MAPVK\_VK\_TO\_VSC\_EX**<br>4 | **Windows Vista and later:** The *uCode* parameter is a virtual-key code and is translated into a scan code. If it is a virtual-key code that does not distinguish between left- and right-hand keys, the left-hand scan code is returned. If the scan code is an extended scan code, the high byte of the returned value will contain either 0xe0 or 0xe1 to specify the extended scan code. If there is no translation, the function returns 0. |

### `dwhkl` [in, out, optional]

Type: **HKL**

Input locale identifier to use for translating the specified code. This parameter can be any input locale identifier previously returned by the [LoadKeyboardLayout](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-loadkeyboardlayoutw) function.

## Return value

Type: **UINT**

The return value is either a scan code, a virtual-key code, or a character value, depending on the value of *uCode* and *uMapType*. If there is no translation, the return value is zero.

## Remarks

The input locale identifier is a broader concept than a keyboard layout, since it can also encompass a speech-to-text converter, an Input Method Editor (IME), or any other form of input.

An application can use **MapVirtualKeyEx** to translate scan codes to the virtual-key code constants **VK_SHIFT**, **VK_CONTROL**, and **VK_MENU**, and vice versa. These translations do not distinguish between the left and right instances of the SHIFT, CTRL, or ALT keys.

An application can get the scan code corresponding to the left or right instance of one of these keys by calling **MapVirtualKeyEx** with *uCode* set to one of the following virtual-key code constants:

- **VK\_LSHIFT**
- **VK\_RSHIFT**
- **VK\_LCONTROL**
- **VK\_RCONTROL**
- **VK\_LMENU**
- **VK\_RMENU**

These left- and right-distinguishing constants are available to an application only through the [GetKeyboardState](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-getkeyboardstate), [SetKeyboardState](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-setkeyboardstate), [GetAsyncKeyState](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-getasynckeystate), [GetKeyState](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-getkeystate), [MapVirtualKey](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-mapvirtualkeyw), and **MapVirtualKeyEx** functions. For list complete table of virtual key codes, see [Virtual Key Codes](https://learn.microsoft.com/windows/win32/inputdev/virtual-key-codes).

In **MAPVK\_VK\_TO\_CHAR** mode [virtual-key codes](https://learn.microsoft.com/windows/win32/inputdev/virtual-key-codes), the 'A'..'Z' keys are translated to upper-case 'A'..'Z' characters regardless of current keyboard layout. If you want to translate a virtual-key code to the corresponding character, use the [ToUnicode](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-tounicode) function.

> [!NOTE]
> The winuser.h header defines MapVirtualKeyEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

- [GetAsyncKeyState](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getasynckeystate)
- [GetKeyState](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getkeystate)
- [GetKeyboardState](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getkeyboardstate)
- [GetSystemMetrics](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsystemmetrics)
- [MapVirtualKey](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-mapvirtualkeya)
- [SetKeyboardState](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setkeyboardstate)
- [LoadKeyboardLayout](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-loadkeyboardlayouta)
- [Keyboard Input](https://learn.microsoft.com/windows/desktop/inputdev/keyboard-input)
- [Keyboard Input Overview](https://learn.microsoft.com/windows/win32/inputdev/about-keyboard-input)