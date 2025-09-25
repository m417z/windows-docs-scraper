# GetKeyboardLayoutList function

## Description

Retrieves the input locale identifiers (formerly called keyboard layout handles) corresponding to the current set of input locales in the system. The function copies the identifiers to the specified buffer.

## Parameters

### `nBuff` [in]

Type: **int**

The maximum number of handles that the buffer can hold.

### `lpList` [out]

Type: **HKL***

A pointer to the buffer that receives the array of input locale identifiers.

## Return value

Type: **int**

If the function succeeds, the return value is the number of input locale identifiers copied to the buffer or, if
*nBuff* is zero, the return value is the size, in array elements, of the buffer needed to receive all current input locale identifiers.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The input locale identifier is a broader concept than a keyboard layout, since it can also encompass a speech-to-text converter, an Input Method Editor (IME), or any other form of input.

**Beginning in Windows 8:** The preferred method to retrieve the language associated with the current keyboard layout or input method is a call to [Windows.Globalization.Language.CurrentInputMethodLanguageTag](https://learn.microsoft.com/uwp/api/windows.globalization.language.currentinputmethodlanguagetag). If your app passes language tags from **CurrentInputMethodLanguageTag** to any [National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-functions) functions, it must first convert the tags by calling [ResolveLocaleName](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-resolvelocalename).

## See also

**Conceptual**

[GetKeyboardLayout](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getkeyboardlayout)

[Keyboard Input](https://learn.microsoft.com/windows/desktop/inputdev/keyboard-input)

**Reference**