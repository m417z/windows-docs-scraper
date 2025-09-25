# SetThreadUILanguage function

## Description

Sets the user interface language for the current thread.

**Windows Vista and later:** This function cannot clear the thread preferred UI languages list. Your MUI application should call [SetThreadPreferredUILanguages](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-setthreadpreferreduilanguages) to clear the language list.

**Windows XP:** This function is limited to allowing the operating system to identify and set a value that is safe to use on the Windows console.

## Parameters

### `LangId` [in]

[Language identifier](https://learn.microsoft.com/windows/desktop/Intl/language-identifiers) for the user interface language for the thread.

**Windows Vista and later:** The application can specify a language identifier of 0 or a nonzero identifier. For more information, see the Remarks section.

**Windows XP:** The application can only set this parameter to 0. This setting causes the function to select the language that best supports the console display. For more information, see the Remarks section.

## Return value

Returns the input language identifier if successful. If the input identifier is nonzero, the function returns that value. If the language identifier is 0, the function always succeeds and returns the identifier of the language that best supports the Windows console. See the Remarks section.

If the input language identifier is nonzero and the function fails, the return value differs from the input language identifier. To get extended error information, the application can call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

When a thread is created, the thread user interface language setting is empty and the user interface for the thread is displayed in the user-selected language. This function enables the application to change the user interface language for the current running thread.

**Windows Vista and later:** Calling this function and specifying 0 for the language identifier is identical to calling [SetThreadPreferredUILanguages](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-setthreadpreferreduilanguages) with the MUI_CONSOLE_FILTER flag set. If the application specifies a valid nonzero language identifier, the function sets a particular user interface language for the thread. After specifying 0 for the language identifier, the application cannot use any of the following constants to correspond to a language identifier:

* [LOCALE_SYSTEM_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-system-default)
* [LOCALE_USER_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-user-default)
* [LOCALE_CUSTOM_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants)
* [LOCALE_CUSTOM_UI_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants)
* [LOCALE_CUSTOM_UNSPECIFIED](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants)

**Windows XP:** When the application calls this function with a language identifier of 0, the function first verifies that the current user interface does not require Uniscribe, and that it is supported by the console [code page](https://learn.microsoft.com/windows/desktop/Intl/code-pages). If the user interface passes these tests, the function uses the supplied value. If not, the function changes the thread user interface language to a language that the Windows console can display. Windows XP does not support a concept of thread user interface language separate from thread locale. Therefore, this function changes the thread locale on Windows XP. It is easy for your application to set a thread to use the most appropriate language for console display, based on user and system preferred UI languages, the language for non-Unicode applications, and the capabilities of the console.

### C# Signature

```cpp
[DllImport("Kernel32.dll", CharSet = CharSet.Auto)]
        static extern System.UInt16 SetThreadUILanguage(
            System.UInt16 LangId
            );

```

## See also

[GetThreadUILanguage](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getthreaduilanguage)

[Multilingual User Interface](https://learn.microsoft.com/windows/desktop/Intl/multilingual-user-interface)

[Multilingual User Interface Functions](https://learn.microsoft.com/windows/desktop/Intl/multilingual-user-interface-functions)

[SetThreadPreferredUILanguages](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-setthreadpreferreduilanguages)