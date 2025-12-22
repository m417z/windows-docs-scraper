# UrlEscapeW function

## Description

Converts characters or surrogate pairs in a URL that might be altered during transport across the Internet ("unsafe" characters) into their corresponding escape sequences. Surrogate pairs are characters between U+10000 to U+10FFFF (in UTF-32) or between DC00 to DFFF (in UTF-16).

## Parameters

### `pszUrl` [in]

Type: **PCTSTR**

A null-terminated string of maximum length **INTERNET_MAX_URL_LENGTH** that contains a full or partial URL, as appropriate for the value in *dwFlags*.

### `pszEscaped` [out]

Type: **PTSTR**

The buffer that receives the converted string, with the unsafe characters converted to their escape sequences.

### `pcchEscaped` [in, out]

Type: **DWORD***

A pointer to a **DWORD** value that, on entry, contains the number of characters in the *pszEscaped* buffer. Before calling **UrlEscape**, the calling application must set the value referenced by *pcchEscaped* to the size of the buffer. When this function returns successfully, the value receives the number of characters written to the buffer, not including the terminating **NULL** character.

If an E_POINTER error code is returned, the buffer was too small to hold the result, and the value referenced by *pcchEscaped* is set to the required number of characters in the buffer. If any other errors are returned, the value referenced by *pcchEscaped* is undefined.

### `dwFlags`

Type: **DWORD**

The flags that indicate which portion of the URL is being provided in *pszURL* and which characters in that string should be converted to their escape sequences. The following flags are defined.

#### URL_DONT_ESCAPE_EXTRA_INFO (0x02000000)

Used only in conjunction with **URL_ESCAPE_SPACES_ONLY** to prevent the conversion of characters in the query (the portion of the URL following the first # or ? character encountered in the string). This flag should not be used alone, nor combined with **URL_ESCAPE_SEGMENT_ONLY**.

#### URL_BROWSER_MODE

Defined to be the same as **URL_DONT_ESCAPE_EXTRA_INFO**.

#### URL_ESCAPE_SPACES_ONLY (0x04000000)

Convert only space characters to their escape sequences, including those space characters in the query portion of the URL. Other unsafe characters are not converted to their escape sequences. This flag assumes that *pszURL* does not contain a full URL. It expects only the portions following the server specification.

Combine this flag with **URL_DONT_ESCAPE_EXTRA_INFO** to prevent the conversion of space characters in the query portion of the URL.

This flag cannot be combined with **URL_ESCAPE_PERCENT** or **URL_ESCAPE_SEGMENT_ONLY**.

#### URL_ESCAPE_PERCENT (0x00001000)

Convert any % character found in the segment section of the URL (that section falling between the server specification and the first # or ? character). By default, the % character is not converted to its escape sequence. Other unsafe characters in the segment are also converted normally.

Combining this flag with **URL_ESCAPE_SEGMENT_ONLY** includes those % characters in the query portion of the URL. However, as the **URL_ESCAPE_SEGMENT_ONLY** flag causes the entire string to be considered the segment, any # or ? characters are also converted.

This flag cannot be combined with **URL_ESCAPE_SPACES_ONLY**.

#### URL_ESCAPE_SEGMENT_ONLY (0x00002000)

Indicates that *pszURL* contains only that section of the URL following the server component but preceding the query. All unsafe characters in the string are converted. If a full URL is provided when this flag is set, all unsafe characters in the entire string are converted, including # and ? characters.

Combine this flag with **URL_ESCAPE_PERCENT** to include that character in the conversion.

This flag cannot be combined with **URL_ESCAPE_SPACES_ONLY** or **URL_DONT_ESCAPE_EXTRA_INFO**.

#### URL_ESCAPE_AS_UTF8 (0x00040000)

**Windows 7 and later**. Percent-encode all non-ASCII characters as their UTF-8 equivalents.

#### URL_ESCAPE_ASCII_URI_COMPONENT (0x00080000)

**Windows 8 and later**. Percent-encode all ASCII characters outside of the unreserved set from URI RFC 3986 (a-zA-Z0-9-.~_).

##### - dwFlags.URL_BROWSER_MODE

Defined to be the same as **URL_DONT_ESCAPE_EXTRA_INFO**.

##### - dwFlags.URL_DONT_ESCAPE_EXTRA_INFO (0x02000000)

Used only in conjunction with **URL_ESCAPE_SPACES_ONLY** to prevent the conversion of characters in the query (the portion of the URL following the first # or ? character encountered in the string). This flag should not be used alone, nor combined with **URL_ESCAPE_SEGMENT_ONLY**.

##### - dwFlags.URL_ESCAPE_ASCII_URI_COMPONENT (0x00080000)

**Windows 8 and later**. Percent-encode all ASCII characters outside of the unreserved set from URI RFC 3986 (a-zA-Z0-9-.~_).

##### - dwFlags.URL_ESCAPE_AS_UTF8 (0x00040000)

**Windows 7 and later**. Percent-encode all non-ASCII characters as their UTF-8 equivalents.

##### - dwFlags.URL_ESCAPE_PERCENT (0x00001000)

Convert any % character found in the segment section of the URL (that section falling between the server specification and the first # or ? character). By default, the % character is not converted to its escape sequence. Other unsafe characters in the segment are also converted normally.

Combining this flag with **URL_ESCAPE_SEGMENT_ONLY** includes those % characters in the query portion of the URL. However, as the **URL_ESCAPE_SEGMENT_ONLY** flag causes the entire string to be considered the segment, any # or ? characters are also converted.

This flag cannot be combined with **URL_ESCAPE_SPACES_ONLY**.

##### - dwFlags.URL_ESCAPE_SEGMENT_ONLY (0x00002000)

Indicates that *pszURL* contains only that section of the URL following the server component but preceding the query. All unsafe characters in the string are converted. If a full URL is provided when this flag is set, all unsafe characters in the entire string are converted, including # and ? characters.

Combine this flag with **URL_ESCAPE_PERCENT** to include that character in the conversion.

This flag cannot be combined with **URL_ESCAPE_SPACES_ONLY** or **URL_DONT_ESCAPE_EXTRA_INFO**.

##### - dwFlags.URL_ESCAPE_SPACES_ONLY (0x04000000)

Convert only space characters to their escape sequences, including those space characters in the query portion of the URL. Other unsafe characters are not converted to their escape sequences. This flag assumes that *pszURL* does not contain a full URL. It expects only the portions following the server specification.

Combine this flag with **URL_DONT_ESCAPE_EXTRA_INFO** to prevent the conversion of space characters in the query portion of the URL.

This flag cannot be combined with **URL_ESCAPE_PERCENT** or **URL_ESCAPE_SEGMENT_ONLY**.

## Return value

Type: **HRESULT**

Returns S_OK if successful. If the *pcchEscaped* buffer was too small to contain the result, E_POINTER is returned, and the value pointed to by *pcchEscaped* is set to the required buffer size. Otherwise, a standard error value is returned.

## Remarks

For the purposes of this document, a typical URL is divided into three sections: the server, the segment, and the query. For example:

``` syntax
http://microsoft.com/test.asp?url=/example/abc.asp?frame=true#fragment
```

The server portion is "http://microsoft.com/". The trailing forward slash is considered part of the server portion.

The segment portion is any part of the path found following the server portion, but before the first # or ? character, in this case simply "test.asp".

The query portion is the remainder of the path from the first # or ? character (inclusive) to the end. In the example, it is "?url=/example/abc.asp?frame=true#fragment".

Unsafe characters are those characters that might be altered during transport across the Internet. This function converts unsafe characters into their equivalent "%xy" escape sequences. The following table shows unsafe characters and their escape sequences.

| Character | Escape Sequence |
| --- | --- |
| ^ | %5E |
| & | %26 |
| ` | %60 |
| { | %7B |
| } | %7D |
| \| | %7C |
| ] | %5D |
| [ | %5B |
| " | %22 |
| < | %3C |
| > | %3E |
| \ | %5C |

Use of the **URL_ESCAPE_SEGMENT_ONLY** flag also causes the conversion of the # (%23), ? (%3F), and / (%2F) characters.

By default, **UrlEscape** ignores any text following a # or ? character. The **URL_ESCAPE_SEGMENT_ONLY** flag overrides this behavior by regarding the entire string as the segment. The **URL_ESCAPE_SPACES_ONLY** flag overrides this behavior, but only for space characters.

#### Examples

The following examples show the effect of the various flags on a URL. The example URL is not valid but is exaggerated for demonstration purposes.

```cpp

// The full original URL
http://microsoft.com/test/t%e<s t.asp?url=/{ex% ample</abc.asp?frame=true#fr%agment

// URL_ESCAPE_SPACES_ONLY
// Only space characters are escaped. Other unsafe characters are ignored.
// Note: This flag expects the server portion of the URL to be omitted.
Original = test/t%e<s t.asp?url=/{ex% ample</abc.asp?frame=true#fr%agment
Result   = test/t%e<s%20t.asp?url=/{ex%%20ample</abc.asp?frame=true#fr%agment

// URL_ESCAPE_SPACES_ONLY | URL_DONT_ESCAPE_EXTRA_INFO
// Spaces in the segment are converted into their escape sequences, but
// spaces in the query are not.
Original = test/t%e<s t.asp?url=/{ex% ample</abc.asp?frame=true#fr%agment
Result   = test/t%e<s%20t.asp?url=/{ex% ample</abc.asp?frame=true#fr%agment

// URL_ESCAPE_PERCENT
// Here only the segment and query are supplied and the server component is
// omitted, although that is not required. Only the segment is considered.
// All unsafe characters plus the % character are converted in the segment.
Original = test/t%e<s t.asp?url=/{ex% ample</abc.asp?frame=true#fr%agment
Result   = test/t%25e%3Cs%20t.asp?url=/{ex% ample</abc.asp?frame=true#fr%agment

// URL_ESCAPE_SEGMENT_ONLY
// Note: This flag expects only the segment, omitting the server and query
//       components.
// The / character is escaped as well as the usual unsafe characters.
Original = test/t%e<s t.asp
Result   = test%2Ft%e%3Cs%20t.asp
```

> [!NOTE]
> The shlwapi.h header defines UrlEscape as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Handling Uniform Resource Locators](https://learn.microsoft.com/windows/desktop/WinInet/handling-uniform-resource-locators)