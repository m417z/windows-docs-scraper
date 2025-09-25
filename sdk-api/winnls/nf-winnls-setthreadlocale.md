# SetThreadLocale function

## Description

Sets the current locale of the calling thread.

## Parameters

### `Locale` [in]

[Locale identifier](https://learn.microsoft.com/windows/desktop/Intl/locale-identifiers) that specifies the locale. You can use the [MAKELCID](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-makelcid) macro to create a locale identifier or use one of the following predefined values.

* [LOCALE_CUSTOM_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants)
* [LOCALE_CUSTOM_UI_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants)
* [LOCALE_CUSTOM_UNSPECIFIED](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants)
* [LOCALE_INVARIANT](https://learn.microsoft.com/windows/desktop/Intl/locale-invariant)
* [LOCALE_SYSTEM_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-system-default)
* [LOCALE_USER_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-user-default)

## Return value

The function should return an LCID on success. This is the LCID of the previous thread locale.

## Remarks

When a thread is created, it uses the user locale. This value is returned by [GetUserDefaultLCID](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getuserdefaultlcid). The user locale can be modified for future processes and thread creation using the regional and language options portion of the Control Panel. The thread locale can also be changed using **SetThreadLocale**.

**SetThreadLocale** affects the selection of resources with a [LANGUAGE](https://learn.microsoft.com/windows/desktop/menurc/language-statement) statement. The statement affects such functions as [CreateDialog](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createdialoga), [DialogBox](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-dialogboxa), [LoadMenu](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadmenua), [LoadString](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadstringa), and [FindResource](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-findresourcea). It sets the code page implied by CP_THREAD_ACP, but does not affect [FindResourceEx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-findresourceexa). For more information, see [Code Page Identifiers](https://learn.microsoft.com/windows/desktop/Intl/code-page-identifiers).

**Windows Vista and later:**  Do not use **SetThreadLocale** to select a user interface language. The resource loader selects the resource that is defined in the .rc file with a [LANGUAGE](https://learn.microsoft.com/windows/desktop/menurc/language-statement) statement, or the application can use [FindResourceEx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-findresourceexa). Additionally, the application can use [SetThreadUILanguage](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-setthreaduilanguage).

**Windows 2000, Windows XP:** Do not use **SetThreadLocale** to select a user interface language. To select the resource that is defined in the .rc file with a [LANGUAGE](https://learn.microsoft.com/windows/desktop/menurc/language-statement) statement, the application must use the [FindResourceEx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-findresourceexa) function.

## See also

[GetSystemDefaultLCID](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getsystemdefaultlcid)

[GetThreadLocale](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getthreadlocale)

[GetUserDefaultLCID](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getuserdefaultlcid)

[National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support)

[National Language Support Functions](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-functions)