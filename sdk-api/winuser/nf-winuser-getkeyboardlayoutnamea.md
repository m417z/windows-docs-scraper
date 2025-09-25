# GetKeyboardLayoutNameA function

## Description

Retrieves the name of the active input locale identifier (formerly called the keyboard layout) for the calling thread.

## Parameters

### `pwszKLID` [out]

Type: **LPTSTR**

The buffer (of at least **KL_NAMELENGTH** characters in length) that receives the name of the input locale identifier, including the terminating null character. This will be a copy of the string provided to the [LoadKeyboardLayout](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadkeyboardlayouta) function, unless layout substitution took place.

For a list of the input layouts that are supplied with Windows, see [Keyboard Identifiers and Input Method Editors for Windows](https://learn.microsoft.com/windows-hardware/manufacture/desktop/windows-language-pack-default-values).

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The input locale identifier is a broader concept than a keyboard layout, since it can also encompass a speech-to-text converter, an Input Method Editor (IME), or any other form of input.

**Beginning in Windows 8:** The preferred method to retrieve the language associated with the current keyboard layout or input method is a call to [Windows.Globalization.Language.CurrentInputMethodLanguageTag](https://learn.microsoft.com/uwp/api/windows.globalization.language.currentinputmethodlanguagetag). If your app passes language tags from **CurrentInputMethodLanguageTag** to any [National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-functions) functions, it must first convert the tags by calling [ResolveLocaleName](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-resolvelocalename).

> [!NOTE]
> The winuser.h header defines GetKeyboardLayoutName as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[ActivateKeyboardLayout](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-activatekeyboardlayout)

**Conceptual**

[Keyboard Input](https://learn.microsoft.com/windows/desktop/inputdev/keyboard-input)

[LoadKeyboardLayout](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadkeyboardlayouta)

**Reference**

[UnloadKeyboardLayout](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-unloadkeyboardlayout)