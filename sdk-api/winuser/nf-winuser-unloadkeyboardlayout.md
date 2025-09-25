# UnloadKeyboardLayout function

## Description

Unloads an input locale identifier (formerly called a keyboard layout).

## Parameters

### `hkl` [in]

Type: **HKL**

The input locale identifier to be unloaded.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. The function can fail for the following reasons:

* An invalid input locale identifier was passed.
* The input locale identifier was preloaded.
* The input locale identifier is in use.

To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The input locale identifier is a broader concept than a keyboard layout, since it can also encompass a speech-to-text converter, an Input Method Editor (IME), or any other form of input.

**UnloadKeyboardLayout** cannot unload the system default input locale identifier if it is the only keyboard layout loaded. You must first load another input locale identifier before unloading the default input locale identifier.

## See also

[ActivateKeyboardLayout](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-activatekeyboardlayout)

**Conceptual**

[GetKeyboardLayoutName](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getkeyboardlayoutnamea)

[Keyboard Input](https://learn.microsoft.com/windows/desktop/inputdev/keyboard-input)

[LoadKeyboardLayout](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadkeyboardlayouta)

**Reference**