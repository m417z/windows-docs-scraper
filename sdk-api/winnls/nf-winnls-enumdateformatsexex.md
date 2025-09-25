# EnumDateFormatsExEx function

## Description

Enumerates the long date, short date, or year/month formats that are available for a locale specified by name.

**Note** The application should call this function in preference to [EnumDateFormats](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumdateformatsa) or [EnumDateFormatsEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumdateformatsexa) if designed to run only on Windows Vista and later.

**Note** This function can enumerate data that changes between releases, for example, due to a custom locale. If your application must persist or transmit data, see [Using Persistent Locale Data](https://learn.microsoft.com/windows/desktop/Intl/using-persistent-locale-data).

## Parameters

### `lpDateFmtEnumProcExEx` [in]

Pointer to an application-defined callback function. For more information, see [EnumDateFormatsProcExEx](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd317815(v=vs.85)).

### `lpLocaleName` [in, optional]

Pointer to a [locale name](https://learn.microsoft.com/windows/desktop/Intl/locale-names), or one of the following predefined values.

* [LOCALE_NAME_INVARIANT](https://learn.microsoft.com/windows/desktop/Intl/locale-name-constants)
* [LOCALE_NAME_SYSTEM_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-name-constants)
* [LOCALE_NAME_USER_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-name-constants)

### `dwFlags` [in]

Flag specifying date formats. The application can supply one of the following values or the [LOCALE_USE_CP_ACP](https://learn.microsoft.com/windows/desktop/Intl/locale-use-cp-acp) constant.

| Value | Meaning |
| --- | --- |
| **DATE_SHORTDATE** | Use short date formats. This value cannot be used with any of the other flag values. |
| **DATE_LONGDATE** | Use long date formats. This value cannot be used with any of the other flag values. |
| **DATE_YEARMONTH** | Use year/month formats. This value cannot be used with any of the other flag values. |
| **DATE_MONTHDAY** | Use month/day formats. This value cannot be used with any of the other flag values. |

### `lParam` [in]

An application-provided parameter to pass to the callback function. This value is especially useful for multi-threaded applications.

## Return value

Returns a nonzero value if successful, or 0 otherwise. To get extended error information, the application can call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror), which can return one of the following error codes:

* ERROR_BADDB. The function could not access the data. This situation should not normally occur, and typically indicates a bad installation, a disk problem, or the like.
* ERROR_INVALID_FLAGS. The values supplied for flags were not valid.
* ERROR_INVALID_PARAMETER. Any of the parameter values was invalid.

## Remarks

**Note** This API is being updated to support the May 2019 Japanese era change. If your application supports the Japanese calendar, you should validate that it properly handles the new era. See [Prepare your application for the Japanese era change](https://learn.microsoft.com/windows/uwp/design/globalizing/japanese-era-change) for more information.

The function enumerates the date formats by passing date format string pointers, one at a time, to the specified application-defined callback function, along with an application-defined constant that is useful for multi-threaded applications. This process continues until **EnumDateFormatsExEx** finds the last date format or the callback function returns **FALSE**.

**Beginning in Windows 8:** If your app passes language tags to this function from the [Windows.Globalization](https://learn.microsoft.com/uwp/api/Windows.Globalization) namespace, it must first convert the tags by calling [ResolveLocaleName](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-resolvelocalename).

## See also

[EnumDateFormats](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumdateformatsa)

[EnumDateFormatsEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumdateformatsexa)

[EnumDateFormatsProcExEx](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd317815(v=vs.85))

[National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support)

[National Language Support Functions](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-functions)