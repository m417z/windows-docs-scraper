# ActivateKeyboardLayout function

## Description

Sets the input locale identifier (formerly called the keyboard layout handle) for the calling thread or the current process. The input locale identifier specifies a locale as well as the physical layout of the keyboard.

## Parameters

### `hkl` [in]

Type: **HKL**

Input locale identifier to be activated.

The input locale identifier must have been loaded by a previous call to the [LoadKeyboardLayout](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadkeyboardlayouta) function. This parameter must be either the handle to a keyboard layout or one of the following values.

| Value | Meaning |
| --- | --- |
| **HKL_NEXT**<br><br>1 | Selects the next locale identifier in the circular list of loaded locale identifiers maintained by the system. |
| **HKL_PREV**<br><br>0 | Selects the previous locale identifier in the circular list of loaded locale identifiers maintained by the system. |

### `Flags` [in]

Type: **UINT**

Specifies how the input locale identifier is to be activated. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **KLF_REORDER**<br><br>0x00000008 | If this bit is set, the system's circular list of loaded locale identifiers is reordered by moving the locale identifier to the head of the list. If this bit is not set, the list is rotated without a change of order.<br><br>For example, if a user had an English locale identifier active, as well as having French, German, and Spanish locale identifiers loaded (in that order), then activating the German locale identifier with the **KLF_REORDER** bit set would produce the following order: German, English, French, Spanish. Activating the German locale identifier without the **KLF_REORDER** bit set would produce the following order: German, Spanish, English, French.<br><br>If less than three locale identifiers are loaded, the value of this flag is irrelevant. |
| **KLF_RESET**<br><br>0x40000000 | If set but **KLF_SHIFTLOCK** is not set, the Caps Lock state is turned off by pressing the Caps Lock key again. If set and **KLF_SHIFTLOCK** is also set, the Caps Lock state is turned off by pressing either SHIFT key.<br><br>These two methods are mutually exclusive, and the setting persists as part of the User's profile in the registry. |
| **KLF_SETFORPROCESS**<br><br>0x00000100 | Activates the specified locale identifier for the entire process and sends the [WM_INPUTLANGCHANGE](https://learn.microsoft.com/windows/desktop/winmsg/wm-inputlangchange) message to the current thread's focus or active window. |
| **KLF_SHIFTLOCK**<br><br>0x00010000 | This is used with **KLF_RESET**. See **KLF_RESET** for an explanation. |
| **KLF_UNLOADPREVIOUS** | This flag is unsupported. Use the [UnloadKeyboardLayout](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-unloadkeyboardlayout) function instead. |

## Return value

Type: **HKL**

The return value is of type
**HKL**. If the function succeeds, the return value is the previous input locale identifier. Otherwise, it is zero.

To get extended error information, use the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

## Remarks

This function only affects the layout for the current process or thread.

This function is not restricted to keyboard layouts. The
*hkl* parameter is actually an input locale identifier. This is a broader concept than a keyboard layout, since it can also encompass a speech-to-text converter, an Input Method Editor (IME), or any other form of input. Several input locale identifiers can be loaded at any one time, but only one is active at a time. Loading multiple input locale identifiers makes it possible to rapidly switch between them.

When multiple IMEs are allowed for each locale, passing an input locale identifier in which the high word (the device handle) is zero activates the first IME in the list belonging to the locale.

The **KLF_RESET** and **KLF_SHIFTLOCK** flags alter the method by which the Caps Lock state is turned off. By default, the Caps Lock state is turned off by hitting the Caps Lock key again. If only **KLF_RESET** is set, the default state is reestablished. If **KLF_RESET** and **KLF_SHIFTLOCK** are set, the Caps Lock state is turned off by pressing either Caps Lock key. This feature is used to conform to local keyboard behavior standards as well as for personal preferences.

## See also

**Conceptual**

[GetKeyboardLayoutName](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getkeyboardlayoutnamea)

[Keyboard Input](https://learn.microsoft.com/windows/desktop/inputdev/keyboard-input)

[LoadKeyboardLayout](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadkeyboardlayouta)

**Reference**

[UnloadKeyboardLayout](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-unloadkeyboardlayout)