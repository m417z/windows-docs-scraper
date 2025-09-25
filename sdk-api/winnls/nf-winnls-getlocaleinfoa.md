# GetLocaleInfoA function

## Description

Retrieves information about a locale specified by identifier.

**Note** For interoperability reasons, the application should prefer the [GetLocaleInfoEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getlocaleinfoex) function to **GetLocaleInfo** because Microsoft is migrating toward the use of locale names instead of locale identifiers for new locales. Any application that runs only on Windows Vista and later should use [GetLocaleInfoEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getlocaleinfoex).

**Note** For global compatibility, the application should prefer the Unicode "W" API forms to the "A" forms. GetLocaleInfoA will limit the character data and could result in results that appear corrupted to users, particularly in globally enabled applications. For this API, [GetLocaleInfoEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getlocaleinfoex) is preferred as it is Unicode and also supports modern locale name standards.

## Parameters

### `Locale` [in]

[Locale identifier](https://learn.microsoft.com/windows/desktop/Intl/locale-identifiers) for which to retrieve information. You can use the [MAKELCID](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-makelcid) macro to create a locale identifier or use one of the following predefined values.

* [LOCALE_CUSTOM_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants)
* [LOCALE_CUSTOM_UI_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants)
* [LOCALE_CUSTOM_UNSPECIFIED](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants)
* [LOCALE_INVARIANT](https://learn.microsoft.com/windows/desktop/Intl/locale-invariant)
* [LOCALE_SYSTEM_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-system-default)
* [LOCALE_USER_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-user-default)

### `LCType` [in]

The locale information to retrieve. For detailed definitions, see the *LCType* parameter of [GetLocaleInfoEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getlocaleinfoex).

**Note** For **GetLocaleInfo**, the value LOCALE_USE_CP_ACP is relevant only for the ANSI version.

### `lpLCData` [out, optional]

Pointer to a buffer in which this function retrieves the requested locale information. This pointer is not used if *cchData* is set to 0. For more information, see the Remarks section.

### `cchData` [in]

Size, in TCHAR values, of the data buffer indicated by *lpLCData*. Alternatively, the application can set this parameter to 0. In this case, the function does not use the *lpLCData* parameter and returns the required buffer size, including the terminating null character.

## Return value

Returns the number of characters retrieved in the locale data buffer if successful and *cchData* is a nonzero value. If the function succeeds, *cchData* is nonzero, and [LOCALE_RETURN_NUMBER](https://learn.microsoft.com/windows/desktop/Intl/locale-return-constants) is specified, the return value is the size of the integer retrieved in the data buffer; that is, 2 for the Unicode version of the function or 4 for the ANSI version. If the function succeeds and the value of *cchData* is 0, the return value is the required size, in characters including a null character, for the locale data buffer.

The function returns 0 if it does not succeed. To get extended error information, the application can call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror), which can return one of the following error codes:

* ERROR_INSUFFICIENT_BUFFER. A supplied buffer size was not large enough, or it was incorrectly set to **NULL**.
* ERROR_INVALID_FLAGS. The values supplied for flags were not valid.
* ERROR_INVALID_PARAMETER. Any of the parameter values was invalid.

## Remarks

For the operation of this function, see Remarks for [GetLocaleInfoEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getlocaleinfoex).

**Note** Even when the *LCType* parameter is specified as LOCALE_FONTSIGNATURE, *cchData* and the function return are still TCHAR counts. The count is different for the ANSI and Unicode versions of the function. When an application calls the generic version of **GetLocaleInfo** with LOCALE_FONTSIGNATURE, *cchData* can be safely specified as sizeof(LOCALESIGNATURE) / sizeof(TCHAR).

The following examples deal correctly with the buffer size for non-text values:

```cpp
int   ret;
CALID calid;
DWORD value;

ret = GetLocaleInfo(LOCALE_USER_DEFAULT,
                    LOCALE_ICALENDARTYPE | LOCALE_RETURN_NUMBER,
                    (LPTSTR)&value,
                    sizeof(value) / sizeof(TCHAR) );
calid = value;

LOCALESIGNATURE LocSig;

ret = GetLocaleInfo(LOCALE_USER_DEFAULT,
                    LOCALE_FONTSIGNATURE,
                    (LPWSTR)&LocSig,
                    sizeof(LocSig) / sizeof(TCHAR) );

```

The ANSI string retrieved by the ANSI version of this function is translated from Unicode to ANSI based on the default ANSI code page for the locale identifier. However, if [LOCALE_USE_CP_ACP](https://learn.microsoft.com/windows/desktop/Intl/locale-use-cp-acp) is specified, the translation is based on the system default ANSI code page.

When the ANSI version of this function is used with a Unicode-only locale identifier, the function can succeed because the operating system uses the system code page. However, characters that are undefined in the system code page appear in the string as a question mark (?).

> [!NOTE]
> The winnls.h header defines GetLocaleInfo as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[GetLocaleInfoEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getlocaleinfoex)

[GetSystemDefaultLCID](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getsystemdefaultlcid)

[GetUserDefaultLCID](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getuserdefaultlcid)

[National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support)

[National Language Support Functions](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-functions)

[Retrieving and Setting Locale Information](https://learn.microsoft.com/windows/desktop/Intl/retrieving-and-setting-locale-information)

[SetLocaleInfo](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-setlocaleinfoa)