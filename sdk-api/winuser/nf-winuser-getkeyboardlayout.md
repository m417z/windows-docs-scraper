# GetKeyboardLayout function

## Description

Retrieves the active input locale identifier (formerly called the keyboard layout).

## Parameters

### `idThread` [in]

Type: **DWORD**

The identifier of the thread to query, or 0 for the current thread.

## Return value

Type: **HKL**

The return value is the input locale identifier for the thread. The low word contains a [Language Identifier](https://learn.microsoft.com/windows/desktop/Intl/language-identifiers) for the input language and the high word contains a device handle to the physical layout of the keyboard.

## Remarks

The input locale identifier is a broader concept than a keyboard layout, since it can also encompass a speech-to-text converter, an Input Method Editor (IME), or any other form of input.

Since the keyboard layout can be dynamically changed, applications that cache information about the current keyboard layout should process the [WM_INPUTLANGCHANGE](https://learn.microsoft.com/windows/desktop/winmsg/wm-inputlangchange) message to be informed of changes in the input language.

To get the KLID (keyboard layout ID) of the currently active HKL, call the [GetKeyboardLayoutName](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getkeyboardlayoutnamea).

**Beginning in Windows 8:** The preferred method to retrieve the language associated with the current keyboard layout or input method is a call to [Windows.Globalization.Language.CurrentInputMethodLanguageTag](https://learn.microsoft.com/uwp/api/windows.globalization.language.currentinputmethodlanguagetag). If your app passes language tags from **CurrentInputMethodLanguageTag** to any [National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-functions) functions, it must first convert the tags by calling [ResolveLocaleName](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-resolvelocalename).

## See also

[ActivateKeyboardLayout](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-activatekeyboardlayout)

**Conceptual**

[CreateThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createthread)

[Keyboard Input](https://learn.microsoft.com/windows/desktop/inputdev/keyboard-input)

[LoadKeyboardLayout](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadkeyboardlayouta)

**Other Resources**

**Reference**

[WM_INPUTLANGCHANGE](https://learn.microsoft.com/windows/desktop/winmsg/wm-inputlangchange)