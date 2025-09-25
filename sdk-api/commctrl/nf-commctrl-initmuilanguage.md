# InitMUILanguage function

## Description

Enables an application to specify a language to be used with the common controls that is different from the system language.

## Parameters

### `uiLang`

Type: **[LANGID](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The [language identifier](https://learn.microsoft.com/windows/desktop/Intl/language-identifiers) of the language to be used by the common controls.

## Remarks

This function enables an application to override the system language setting, and specify a different language for the common controls. The selected language only applies to the process that **InitMUILanguage** is called from. See [Internationalization for Windows Applications](https://learn.microsoft.com/windows/desktop/Intl/international-support) for further discussion of localization.

## See also

[GetMUILanguage](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-getmuilanguage)