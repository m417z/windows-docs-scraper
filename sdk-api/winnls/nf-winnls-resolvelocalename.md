# ResolveLocaleName function

## Description

Finds a possible [locale name](https://learn.microsoft.com/windows/desktop/Intl/locale-names) match for the supplied name.

## Parameters

### `lpNameToResolve` [in, optional]

Pointer to a name to resolve, for example, "en-XA" for English (Private Use).

### `lpLocaleName` [out, optional]

Pointer to a buffer in which this function retrieves the locale name that is the match for the input name. For example, the match for the name "en-XA" is "en-US" for English (United States).

**Note** If the function fails, the state of the output buffer is not guaranteed to be accurate. In this case, the application should check the return value and error status set by the function to determine the correct course of action.

### `cchLocaleName` [in]

Size, in characters, of the buffer indicated by *lpLocaleName*. The maximum possible length of a locale name, including a terminating null character, is the value of [LOCALE_NAME_MAX_LENGTH](https://learn.microsoft.com/windows/desktop/Intl/locale-name-constants). This is the recommended size to supply in this parameter.

## Return value

Returns the size of the buffer containing the locale name, including the terminating null character, if successful.

The function returns 0 if it does not succeed. To get extended error information, the application can call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror), which can return one of the following error codes:

* ERROR_INSUFFICIENT_BUFFER. A supplied buffer size was not large enough, or it was incorrectly set to **NULL**.

## Remarks

The retrieved locale name indicates a specific locale, including language and country/region, even if the input language is neutral. For example, an input of "en" for English (United States) causes the function to retrieve "en-US".

This function can retrieve data from [custom locales](https://learn.microsoft.com/windows/desktop/Intl/custom-locales). Data is not guaranteed to be the same from computer to computer or between runs of an application, nor does the return of a valid locale guarantee that it will be valid on another computer. If your application must persist or transmit data, see [Using Persistent Locale Data](https://learn.microsoft.com/windows/desktop/Intl/using-persistent-locale-data).

**Beginning in Windows 8:** Language tags obtained from the [Windows.Globalization](https://learn.microsoft.com/uwp/api/Windows.Globalization) namespace must be converted by **ResolveLocaleName** before they can be used with any National Language Support functions.

## See also

[National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support)

[National Language Support Functions](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-functions)

[Windows.Globalization](https://learn.microsoft.com/uwp/api/Windows.Globalization)