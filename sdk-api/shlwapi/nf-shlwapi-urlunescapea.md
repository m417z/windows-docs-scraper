# UrlUnescapeA function

## Description

Converts escape sequences back into ordinary characters.

## Parameters

### `pszUrl` [in, out]

Type: **PTSTR**

A pointer to a null-terminated string with the URL. If *dwFlags* is set to **URL_UNESCAPE_INPLACE**, the converted string is returned through this parameter.

### `pszUnescaped` [out, optional]

Type: **PTSTR**

A pointer to a buffer that will receive a null-terminated string that contains the unescaped version of *pszURL*. If **URL_UNESCAPE_INPLACE** is set in *dwFlags*, this parameter is ignored.

### `pcchUnescaped` [in, out, optional]

Type: **DWORD***

The number of characters in the buffer pointed to by *pszUnescaped*. On entry, the value *pcchUnescaped* points to is set to the size of the buffer. If the function returns a success code and the **URL_UNESCAPE_INPLACE** flag is not set, the value that *pcchUnescaped* points to is set to the number of characters written to that buffer, not counting the terminating **NULL** character. If an E_POINTER error code is returned, the buffer was too small, and the value to which *pcchUnescaped* points is set to the required number of characters that the buffer must be able to contain. If any other errors are returned, the value to which *pcchUnescaped* points is undefined.

### `dwFlags`

Type: **DWORD**

Flags that control which characters are unescaped. It can be a combination of the following flags.

#### URL_DONT_UNESCAPE_EXTRA_INFO

Do not convert the # or ? character, or any characters following them in the string.

#### URL_UNESCAPE_AS_UTF8

**Introduced in Windows 8**. Decode URLs that were encoded by using the **URL_ESCAPE_AS_UTF8** flag.

#### URL_UNESCAPE_INPLACE

Use *pszURL* to return the converted string instead of *pszUnescaped*.

## Return value

Type: **HRESULT**

Returns S_OK if successful. If the **URL_UNESCAPE_INPLACE** flag is not set, the value pointed to by *pcchUnescaped* will be set to the number of characters in the output buffer pointed to by *pszUnescaped*. Returns E_POINTER if the **URL_UNESCAPE_INPLACE** flag is not set and the output buffer is too small. The *pcchUnescaped* parameter will be set to the required buffer size. Otherwise, returns a standard error value.

## Remarks

An escape sequence has the form "%xy".

Input strings cannot be longer than INTERNET_MAX_URL_LENGTH.

> [!NOTE]
> The shlwapi.h header defines UrlUnescape as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).