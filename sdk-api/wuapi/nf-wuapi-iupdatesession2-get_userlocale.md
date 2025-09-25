# IUpdateSession2::get_UserLocale

## Description

Gets and sets the preferred locale for which update information is retrieved..

If you do not specify the locale, the default is the user locale that [GetUserDefaultUILanguage](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getuserdefaultuilanguage) returns. If the information is not available in a specified locale or in the user locale, Windows Update Agent (WUA) tries to retrieve the information from the default update locale.

This property is read/write.

## Parameters

## Remarks

A search from an **UpdateSearch** object that was created from the **UpdateSession** object fails if the following conditions are true:

* A user or a power user set the **UserLocale** property for the [IUpdateSession2](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdatesession2) interface to a locale.
* The locale corresponds to a language that is not installed on the computer.

## See also

[IUpdateSession2](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdatesession2)