# PARSEDURLW structure

## Description

Used by the [ParseURL](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-parseurla) function to return the parsed URL.

## Members

### `cbSize`

Type: **DWORD**

[in] The size of the structure, in bytes. The calling application must set this member before calling the [ParseURL](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-parseurla) function.

### `pszProtocol`

Type: **LPCTSTR**

[out] A pointer to the beginning of the protocol part of the URL.

### `cchProtocol`

Type: **UINT**

[out] The number of characters in the URL's protocol section.

### `pszSuffix`

Type: **LPCTSTR**

[out] A pointer to the section of the URL that follows the protocol and colon (':'). For file URLs, the function also skips the leading "//" characters.

### `cchSuffix`

Type: **UINT**

[out] The number of characters in the URL's suffix.

### `nScheme`

Type: **UINT**

[out] A value from the [URL_SCHEME](https://learn.microsoft.com/windows/desktop/api/shlwapi/ne-shlwapi-url_scheme) enumeration that specifies the URL's scheme.

## Remarks

> [!NOTE]
> The shlwapi.h header defines PARSEDURL as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).