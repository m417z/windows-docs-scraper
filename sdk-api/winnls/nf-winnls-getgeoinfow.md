# GetGeoInfoW function

## Description

[**GetGeoInfo** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [GetGeoInfoEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getgeoinfoex).

]

Retrieves information about a specified geographical location.

## Parameters

### `Location` [in]

Identifier for the geographical location for which to get information. For more information, see [Table of Geographical Locations](https://learn.microsoft.com/windows/desktop/Intl/table-of-geographical-locations). You can obtain the available values by calling [EnumSystemGeoID](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumsystemgeoid).

### `GeoType` [in]

Type of information to retrieve. Possible values are defined by the [SYSGEOTYPE](https://learn.microsoft.com/windows/desktop/api/winnls/ne-winnls-sysgeotype) enumeration. If the value of *GeoType* is GEO_LCID, the function retrieves a locale identifier. If the value of *GeoType* is GEO_RFC1766, the function retrieves a string name that is compliant with RFC 4646 (Windows Vista). For more information, see the Remarks section.

**Windows XP:** When *GeoType* is set to GEO_LCID, the retrieved string is an 8-digit hexadecimal value.

**Windows Me:** When *GeoType* is set to GEO_LCID, the retrieved string is a decimal value.

### `lpGeoData` [out, optional]

Pointer to the buffer in which this function retrieves the information.

### `cchData` [in]

Size of the buffer indicated by *lpGeoData*. The size is the number of bytes for the ANSI version of the function, or the number of words for the Unicode version. The application can set this parameter to 0 if the function is to return the required size of the buffer.

### `LangId` [in]

Identifier for the language, used with the value of *Location*. The application can set this parameter to 0, with GEO_RFC1766 or GEO_LCID specified for *GeoType*. This setting causes the function to retrieve the language identifier by calling [GetUserDefaultLangID](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getuserdefaultlangid).

**Note** The application must set this parameter to 0 if *GeoType* has any value other than GEO_RFC1766 or GEO_LCID.

## Return value

Returns the number of bytes (ANSI) or words (Unicode) of geographical location information retrieved in the output buffer. If *cchData* is set to 0, the function returns the required size for the buffer.

The function returns 0 if it does not succeed. To get extended error information, the application can call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror), which can return one of the following error codes:

* ERROR_INSUFFICIENT_BUFFER. A supplied buffer size was not large enough, or it was incorrectly set to **NULL**.
* ERROR_INVALID_PARAMETER. Any of the parameter values was invalid.

## Remarks

If the application specifies GEO_RFC1766 for *GeoType*, it should specify a language identifier for *LangId* that is appropriate to the specified geographical location identifier. The appropriate language is either a locale-neutral language or one with a locale corresponding to the specified identifier. The resulting string, compliant with RFC 4646 (Windows Vista), constitutes a [locale name](https://learn.microsoft.com/windows/desktop/Intl/locale-names).

For example, if *Location* is specified as 0xF4 for United States, *GeoType* is specified as GEO_RFC1766, and *LangId* is specified as either 0x09 for locale-neutral English or 0x409 for English (United States), the function retrieves "en-US" on successful return. In fact, the function ignores the locale-specific portion of the language. Thus, if the application specifies *LangId* as 0x809 for English (United Kingdom), the function also writes "en-US" to *lpGeoData*.

Consider another example. If *Location* is specified as 0xF4 for United States, *GeoType* is specified as GEO_RFC1766, and *LangId* is specified as 0x04 for Chinese, the function retrieves "zh-US" on successful return. This is not the name of a supported locale.

If the application specifies GEO_LCID for *GeoType*, the function treats the language identifier as a locale identifier (LCID). It attempts to return the locale identifier if it is associated with the provided geographical identifier in some way.

> [!NOTE]
> The winnls.h header defines GetGeoInfo as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[EnumSystemGeoID](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumsystemgeoid)

[GetGeoInfoEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getgeoinfoex)

[National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support)

[National Language Support Functions](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-functions)

[SYSGEOTYPE](https://learn.microsoft.com/windows/desktop/api/winnls/ne-winnls-sysgeotype)