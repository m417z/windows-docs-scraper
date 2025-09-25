# GetMUILanguage function

## Description

Gets the language currently in use by the common controls for a particular process.

## Return value

Type: **[LANGID](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns the [language identifier](https://learn.microsoft.com/windows/desktop/Intl/language-identifiers) of the language an application has specified for the common controls by calling [InitMUILanguage](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-initmuilanguage). **GetMUILanguage** returns the value for the process from which it is called. If
**InitMUILanguage** has not been called or was not called from the same process, **GetMUILanguage** returns the language-neutral LANGID, [MAKELANGID](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-makelangid)(LANG_NEUTRAL, SUBLANG_NEUTRAL).

## Remarks

See [Internationalization for Windows Applications](https://learn.microsoft.com/windows/desktop/Intl/international-support) for further discussion of localization.