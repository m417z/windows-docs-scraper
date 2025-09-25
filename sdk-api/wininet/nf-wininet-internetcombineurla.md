# InternetCombineUrlA function

## Description

Combines a base and relative URL into a single URL. The resultant URL is canonicalized (see
[InternetCanonicalizeUrl](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetcanonicalizeurla)).

## Parameters

### `lpszBaseUrl` [in]

Pointer to a null-terminated string that contains the base URL.

### `lpszRelativeUrl` [in]

Pointer to a null-terminated string that contains the relative URL.

### `lpszBuffer` [out]

Pointer to a buffer that receives the combined URL.

### `lpdwBufferLength` [in, out]

Pointer to a variable that contains the size of the
*lpszBuffer* buffer, in characters. If the function succeeds, this parameter receives the size of the combined URL, in characters, not including the null-terminating character. If the function fails, this parameter receives the size of the required buffer, in characters (including the null-terminating character).

### `dwFlags` [in]

Controls the operation of the function. This parameter can be one of the following values.

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
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). Possible errors include the following.

| Return code | Description |
| --- | --- |
| **ERROR_BAD_PATHNAME** | The URLs could not be combined. |
| **ERROR_INSUFFICIENT_BUFFER** | The buffer supplied to the function was insufficient or **NULL**. The value indicated by the *lpdwBufferLength* parameter will contain the number of bytes required to hold the combined URL. |
| **ERROR_INTERNET_INVALID_URL** | The format of the URL is invalid. |
| **ERROR_INVALID_PARAMETER** | There is an invalid string, buffer, buffer size, or flags parameter. |

## Remarks

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

> [!NOTE]
> The wininet.h header defines InternetCombineUrl as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Handling Uniform Resource Locators](https://learn.microsoft.com/windows/desktop/WinInet/handling-uniform-resource-locators)

[WinINet Functions](https://learn.microsoft.com/windows/desktop/WinInet/wininet-functions)