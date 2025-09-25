# InternetCanonicalizeUrlW function

## Description

Canonicalizes a URL, which includes converting unsafe characters and spaces into escape sequences.

## Parameters

### `lpszUrl` [in]

 A pointer to the string that contains the URL to canonicalize.

### `lpszBuffer` [out]

A pointer to the buffer that receives the resulting canonicalized URL.

### `lpdwBufferLength` [in, out]

A pointer to a variable that contains the size, in characters, of the
*lpszBuffer* buffer. If the function succeeds, this parameter receives the number of characters actually copied to the
*lpszBuffer* buffer, which does not include the terminating null character. If the function fails, this parameter receives the required size of the
buffer, in characters, which includes the terminating null character.

### `dwFlags` [in]

Controls canonicalization. If no flags are specified, the function converts all unsafe characters and meta sequences (such as \.,\ .., and \...) to escape sequences.
This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| ICU_BROWSER_MODE | Does not encode or decode characters after "#" or "?", and does not remove trailing white space after "?". If this value is not specified, the entire URL is encoded and trailing white space is removed. |
| ICU_DECODE | Converts all %XX sequences to characters, including escape sequences, before the URL is parsed. |
| ICU_ENCODE_PERCENT | Encodes any percent signs encountered. By default, percent signs are not encoded. This value is available in Microsoft Internet Explorer 5 and later. |
| ICU_ENCODE_SPACES_ONLY | Encodes spaces only. |
| ICU_NO_ENCODE | Does not convert unsafe characters to escape sequences. |
| ICU_NO_META | Does not remove meta sequences (such as "." and "..") from the URL. |

## Return value

Returns **TRUE** if successful, or **FALSE** otherwise. To get extended error information, call
the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function. Possible errors include the following.

| Return code | Description |
| --- | --- |
| **ERROR_BAD_PATHNAME** | The URL could not be canonicalized. |
| **ERROR_INSUFFICIENT_BUFFER** | The canonicalized URL is too large to fit in the buffer provided. The *lpdwBufferLength* parameter is set to the size, in bytes, of the buffer required to hold the canonicalized URL. |
| **ERROR_INTERNET_INVALID_URL** | The format of the URL is invalid. |
| **ERROR_INVALID_PARAMETER** | There is an invalid string, buffer, buffer size, or flags parameter. |

## Remarks

In Internet Explorer 4.0 and later,
**InternetCanonicalizeUrl** always functions as if the **ICU_BROWSER_MODE** flag is set. Client applications that must canonicalize the entire URL should use either
[CoInternetParseUrl](https://msdn.microsoft.com/25f9b097-ee42-48df-8573-d6bf9a52f53b) (with the action **PARSE_CANONICALIZE** and the flag **URL_ESCAPE_UNSAFE**) or
[UrlCanonicalize](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-urlcanonicalizea).

**InternetCanonicalizeUrl** always encodes by default, even if the **ICU_DECODE** flag has been specified. To decode without reencoding, use **ICU_DECODE** | **ICU_NO_ENCODE**. If the **ICU_DECODE** flag is used without **ICU_NO_ENCODE**, the URL is decoded before being parsed; unsafe characters are then re-encoded after parsing. This function handles arbitrary protocol schemes, but to do so it must make inferences from the unsafe character set.

Applications that call
**InternetCanonicalizeUrl** when using Internet Explorer 3.0 (or when setting the **ICU_ENCODE_PERCENT** flag for Internet Explorer 5 and later) should track the usage of this function on a particular URL. If unsafe characters in a URL have been converted to escape sequences, using
**InternetCanonicalizeUrl** again on the URL (with no flags) causes the escape sequences to be converted to another escape sequence. For example, a blank space in a URL would be converted to the escape sequence %20. Calling
**InternetCanonicalizeUrl** again on the URL would cause the escape sequence %20 to be converted to the escape sequence %2520, because the % sign is an unsafe character that is reserved for escape sequences and is replaced by the function with the escape sequence %25.

Like all other aspects of the WinINet API, this function cannot be safely called from within DllMain or the constructors and destructors of global objects.

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

> [!NOTE]
> The wininet.h header defines InternetCanonicalizeUrl as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Handling Uniform Resource Locators](https://learn.microsoft.com/windows/desktop/WinInet/handling-uniform-resource-locators)

[WinINet Functions](https://learn.microsoft.com/windows/desktop/WinInet/wininet-functions)