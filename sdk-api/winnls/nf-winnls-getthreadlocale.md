# GetThreadLocale function

## Description

Returns the [locale identifier](https://learn.microsoft.com/windows/desktop/Intl/locale-identifiers) of the current locale for the calling thread.

**Note** This function can retrieve data that changes between releases, for example, due to a custom locale. If your application must persist or transmit data, see [Using Persistent Locale Data](https://learn.microsoft.com/windows/desktop/Intl/using-persistent-locale-data).

## Return value

Returns the [locale identifier](https://learn.microsoft.com/windows/desktop/Intl/locale-identifiers) of the locale associated with the current thread.

**Windows Vista**: This function can return the identifier of a [custom locale](https://learn.microsoft.com/windows/desktop/Intl/custom-locales). If the current thread locale is a custom locale, the function returns [LOCALE_CUSTOM_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants). If the current thread locale is a supplemental custom locale, the function can return [LOCALE_CUSTOM_UNSPECIFIED](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants). All supplemental locales share this locale identifier.

## Remarks

When an application process launches, it uses the Standards and Formats variable for the locale. For more information, see [NLS Terminology](https://learn.microsoft.com/windows/desktop/Intl/nls-terminology).

When a new thread is created in a process, it inherits the locale of the creating thread. This locale can be either the default Standards and Formats locale or a different locale set for the creating thread in a call to [SetThreadLocale](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-setthreadlocale). **GetThreadLocale** and **SetThreadLocale** can be used to modify the locale of the new thread.

## See also

[GetSystemDefaultLCID](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getsystemdefaultlcid)

[GetUserDefaultLCID](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getuserdefaultlcid)

[National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support)

[National Language Support Functions](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-functions)

[SetThreadLocale](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-setthreadlocale)