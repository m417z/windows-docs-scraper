# IDsDisplaySpecifier::SetLanguageID

## Description

The **IDsDisplaySpecifier::SetLanguageID** method changes the locale used by the [IDsDisplaySpecifier](https://learn.microsoft.com/windows/desktop/api/dsclient/nn-dsclient-idsdisplayspecifier) object to a specified language.

## Parameters

### `langid` [in]

Contains the language identifier used by the [IDsDisplaySpecifier](https://learn.microsoft.com/windows/desktop/api/dsclient/nn-dsclient-idsdisplayspecifier) object. If this parameter is zero, this method calls the
[GetUserDefaultUILanguage](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getuserdefaultuilanguage) function to retrieve the current user language identifier and uses that locale.

## Return value

This method always returns **S_OK**.

## Remarks

During object creation, the [IDsDisplaySpecifier](https://learn.microsoft.com/windows/desktop/api/dsclient/nn-dsclient-idsdisplayspecifier) object obtains the locale by calling [GetUserDefaultUILanguage](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getuserdefaultuilanguage). This method enables the object user to change the locale used with the display specifiers.

## See also

[Display Interfaces in Active Directory Domain Services](https://learn.microsoft.com/windows/desktop/AD/display-interfaces-in-active-directory-domain-services)

[GetUserDefaultUILanguage](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getuserdefaultuilanguage)

[IDsDisplaySpecifier](https://learn.microsoft.com/windows/desktop/api/dsclient/nn-dsclient-idsdisplayspecifier)