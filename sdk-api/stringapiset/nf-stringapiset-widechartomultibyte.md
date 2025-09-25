# WideCharToMultiByte function

## Description

Maps a UTF-16 (wide character) string to a new character string. The new character string is not necessarily from a multibyte character set.

**Caution** Using the **WideCharToMultiByte** function incorrectly can compromise the security of your application. Calling this function can easily cause a buffer overrun because the size of the input buffer indicated by *lpWideCharStr* equals the number of characters in the Unicode string, while the size of the output buffer indicated by *lpMultiByteStr* equals the number of bytes. To avoid a buffer overrun, your application must specify a buffer size appropriate for the data type the buffer receives.

Data converted from UTF-16 to non-Unicode encodings is subject to data loss, because a code page might not be able to represent every character used in the specific Unicode data. For more information, see [Security Considerations: International Features](https://learn.microsoft.com/windows/desktop/Intl/security-considerations--international-features).

**Note** The ANSI code pages can be different on different computers, or can be changed for a single computer, leading to data corruption. For the most consistent results, applications should use Unicode, such as UTF-8 or UTF-16, instead of a specific code page, unless legacy standards or data formats prevent the use of Unicode. If using Unicode is not possible, applications should tag the data stream with the appropriate encoding name when protocols allow it. HTML and XML files allow tagging, but text files do not.

## Parameters

### `CodePage` [in]

Code page to use in performing the conversion. This parameter can be set to the value of any code page that is installed or available in the operating system. For a list of code pages, see [Code Page Identifiers](https://learn.microsoft.com/windows/desktop/Intl/code-page-identifiers). Your application can also specify one of the values shown in the following table.

| Value | Meaning |
| --- | --- |
| **CP_ACP** | The system default Windows ANSI code page.<br><br>**Note** This value can be different on different computers, even on the same network. It can be changed on the same computer, leading to stored data becoming irrecoverably corrupted. This value is only intended for temporary use and permanent storage should use UTF-16 or UTF-8 if possible. |
| **CP_MACCP** | The current system Macintosh code page. <br><br>**Note** This value can be different on different computers, even on the same network. It can be changed on the same computer, leading to stored data becoming irrecoverably corrupted. This value is only intended for temporary use and permanent storage should use UTF-16 or UTF-8 if possible.<br><br>**Note** This value is used primarily in legacy code and should not generally be needed since modern Macintosh computers use Unicode for encoding. |
| **CP_OEMCP** | The current system OEM code page. <br><br>**Note** This value can be different on different computers, even on the same network. It can be changed on the same computer, leading to stored data becoming irrecoverably corrupted. This value is only intended for temporary use and permanent storage should use UTF-16 or UTF-8 if possible. |
| **CP_SYMBOL** | **Windows 2000:** Symbol code page (42). |
| **CP_THREAD_ACP** | **Windows 2000:** The Windows ANSI code page for the current thread. <br><br>**Note** This value can be different on different computers, even on the same network. It can be changed on the same computer, leading to stored data becoming irrecoverably corrupted. This value is only intended for temporary use and permanent storage should use UTF-16 or UTF-8 if possible. |
| **CP_UTF7** | UTF-7. Use this value only when forced by a 7-bit transport mechanism. Use of UTF-8 is preferred. With this value set, *lpDefaultChar* and *lpUsedDefaultChar* must be set to **NULL**. |
| **CP_UTF8** | UTF-8. With this value set, *lpDefaultChar* and *lpUsedDefaultChar* must be set to **NULL**. |

### `dwFlags` [in]

Flags indicating the conversion type. The application can specify a combination of the following values. The function performs more quickly when none of these flags is set. The application should specify WC_NO_BEST_FIT_CHARS and WC_COMPOSITECHECK with the specific value WC_DEFAULTCHAR to retrieve all possible conversion results. If all three values are not provided, some results will be missing.

| Value | Meaning |
| --- | --- |
| **WC_COMPOSITECHECK** | Convert composite characters, consisting of a base character and a nonspacing character, each with different character values. Translate these characters to precomposed characters, which have a single character value for a base-nonspacing character combination. For example, in the character è, the e is the base character and the accent grave mark is the nonspacing character.<br><br>**Note** Windows normally represents Unicode strings with precomposed data, making the use of the WC_COMPOSITECHECK flag unnecessary.<br><br>Your application can combine WC_COMPOSITECHECK with any one of the following flags, with the default being WC_SEPCHARS. These flags determine the behavior of the function when no precomposed mapping for a base-nonspacing character combination in a Unicode string is available. If none of these flags is supplied, the function behaves as if the WC_SEPCHARS flag is set. For more information, see WC_COMPOSITECHECK and related flags in the [Remarks](https://learn.microsoft.com/windows/win32/api/stringapiset/nf-stringapiset-widechartomultibyte#remarks) section.<br><br>|  |  | | --- | --- | | WC_DEFAULTCHAR | Replace exceptions with the default character during conversion. | | WC_DISCARDNS | Discard nonspacing characters during conversion. | | WC_SEPCHARS | Default. Generate separate characters during conversion. | |
| **WC_ERR_INVALID_CHARS** | **Windows Vista and later:** Fail (by returning 0 and setting the last-error code to ERROR_NO_UNICODE_TRANSLATION) if an invalid input character is encountered. You can retrieve the last-error code with a call to [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). If this flag is not set, the function replaces illegal sequences with U+FFFD (encoded as appropriate for the specified codepage) and succeeds by returning the length of the converted string. Note that this flag only applies when *CodePage* is specified as CP_UTF8 or 54936. It cannot be used with other code page values. |
| **WC_NO_BEST_FIT_CHARS** | Translate any Unicode characters that do not translate directly to multibyte equivalents to the default character specified by *lpDefaultChar*. In other words, if translating from Unicode to multibyte and back to Unicode again does not yield the same Unicode character, the function uses the default character. This flag can be used by itself or in combination with the other defined flags.<br><br>For strings that require validation, such as file, resource, and user names, the application should always use the WC_NO_BEST_FIT_CHARS flag. This flag prevents the function from mapping characters to characters that appear similar but have very different semantics. In some cases, the semantic change can be extreme. For example, the symbol for "∞" (infinity) maps to 8 (eight) in some code pages. |

For the code pages listed below, *dwFlags* must be 0. Otherwise, the function fails with ERROR_INVALID_FLAGS.

* 50220
* 50221
* 50222
* 50225
* 50227
* 50229
* 57002 through 57011
* 65000 (UTF-7)
* 42 (Symbol)

**Note** For the code page 65001 (UTF-8) or the code page 54936 (GB18030, Windows Vista and later), *dwFlags* must be set to either 0 or WC_ERR_INVALID_CHARS. Otherwise, the function fails with ERROR_INVALID_FLAGS.

### `lpWideCharStr` [in]

Pointer to the Unicode string to convert.

### `cchWideChar` [in]

Size, in characters, of the string indicated by *lpWideCharStr*. Alternatively, this parameter can be set to -1 if the string is null-terminated. If *cchWideChar* is set to 0, the function fails.

If this parameter is -1, the function processes the entire input string, including the terminating null character. Therefore, the resulting character string has a terminating null character, and the length returned by the function includes this character.

If this parameter is set to a positive integer, the function processes exactly the specified number of characters. If the provided size does not include a terminating null character, the resulting character string is not null-terminated, and the returned length does not include this character.

### `lpMultiByteStr` [out, optional]

Pointer to a buffer that receives the converted string.

### `cbMultiByte` [in]

Size, in bytes, of the buffer indicated by *lpMultiByteStr*. If this value is 0, the function returns the required buffer size, in bytes, including any terminating null character, and makes no use of the *lpMultiByteStr* buffer.

### `lpDefaultChar` [in, optional]

Pointer to the character to use if a character cannot be represented in the specified code page. The application sets this parameter to **NULL** if the function is to use a system default value. To obtain the system default character, the application can call the [GetCPInfo](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getcpinfo) or [GetCPInfoEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getcpinfoexa) function.

For the CP_UTF7 and CP_UTF8 settings for *CodePage*, this parameter must be set to **NULL**. Otherwise, the function fails with ERROR_INVALID_PARAMETER.

### `lpUsedDefaultChar` [out, optional]

Pointer to a flag that indicates if the function has used a default character in the conversion. The flag is set to **TRUE** if one or more characters in the source string cannot be represented in the specified code page. Otherwise, the flag is set to **FALSE**. This parameter can be set to **NULL**.

For the CP_UTF7 and CP_UTF8 settings for *CodePage*, this parameter must be set to **NULL**. Otherwise, the function fails with ERROR_INVALID_PARAMETER.

## Return value

If successful, returns the number of bytes written to the buffer pointed to by *lpMultiByteStr*. If the function succeeds and *cbMultiByte* is 0, the return value is the required size, in bytes, for the buffer indicated by *lpMultiByteStr*. Also see *dwFlags* for info about how the WC_ERR_INVALID_CHARS flag affects the return value when invalid sequences are input.

The function returns 0 if it does not succeed. To get extended error information, the application can call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror), which can return one of the following error codes:

* ERROR_INSUFFICIENT_BUFFER. A supplied buffer size was not large enough, or it was incorrectly set to **NULL**.
* ERROR_INVALID_FLAGS. The values supplied for flags were not valid.
* ERROR_INVALID_PARAMETER. Any of the parameter values was invalid.
* ERROR_NO_UNICODE_TRANSLATION. Invalid Unicode was found in a string.

## Remarks

The *lpMultiByteStr* and *lpWideCharStr* pointers must not be the same. If they are the same, the function fails, and [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns ERROR_INVALID_PARAMETER.

**WideCharToMultiByte** does not null-terminate an output string if the input string length is explicitly specified without a terminating null character. To null-terminate an output string for this function, the application should pass in -1 or explicitly count the terminating null character for the input string.

If *cbMultiByte* is less than *cchWideChar*, this function writes the number of characters specified by *cbMultiByte* to the buffer indicated by *lpMultiByteStr*. However, if *CodePage* is set to CP_SYMBOL and *cbMultiByte* is less than *cchWideChar,* the function writes no characters to *lpMultiByteStr*.

The **WideCharToMultiByte** function operates most efficiently when both *lpDefaultChar* and *lpUsedDefaultChar* are set to **NULL**. The following table shows the behavior of the function for the four possible combinations of these parameters.

| *lpDefaultChar* | *lpUsedDefaultChar* | Result |
| --- | --- | --- |
| **NULL** | **NULL** | No default checking. These parameter settings are the most efficient ones for use with this function. |
| Non-null character | **NULL** | Uses the specified default character, but does not set *lpUsedDefaultChar*. |
| **NULL** | Non-null character | Uses the system default character and sets *lpUsedDefaultChar* if necessary. |
| Non-null character | Non-null character | Uses the specified default character and sets *lpUsedDefaultChar* if necessary. |

Starting with Windows Vista, this function fully conforms with the Unicode 4.1 specification for UTF-8 and UTF-16. The function used on earlier operating systems encodes or decodes lone [surrogate](https://learn.microsoft.com/windows/desktop/Intl/surrogates-and-supplementary-characters) halves or mismatched surrogate pairs. Code written in earlier versions of Windows that rely on this behavior to encode random non-text binary data might run into problems. However, code that uses this function to produce valid UTF-8 strings will behave the same way as on earlier Windows operating systems.

**Starting with Windows 8:** **WideCharToMultiByte** is declared in Stringapiset.h. Before Windows 8, it was declared in Winnls.h.

### WC_COMPOSITECHECK and related flags

As discussed in [Using Unicode Normalization to Represent Strings](https://learn.microsoft.com/windows/desktop/Intl/using-unicode-normalization-to-represent-strings), Unicode allows multiple representations of the same string (interpreted linguistically). For example, Capital A with dieresis (umlaut) can be represented either precomposed as a single Unicode code point "Ä" (U+00C4) or decomposed as the combination of Capital A and the combining dieresis character ("A" + "¨", that is U+0041 U+0308). However, most code pages provide only composed characters.

The WC_COMPOSITECHECK flag causes the **WideCharToMultiByte** function to test for decomposed Unicode characters and attempts to compose them before converting them to the requested code page. This flag is only available for conversion to [single byte (SBCS)](https://learn.microsoft.com/windows/desktop/Intl/single-byte-character-sets) or [double byte (DBCS)](https://learn.microsoft.com/windows/desktop/Intl/double-byte-character-sets) code pages (code pages < 50000, excluding code page 42). If your application needs to convert decomposed Unicode data to single byte or double byte code pages, this flag might be useful. However, not all characters can be converted this way and it is more reliable to save and store such data as Unicode.

When an application is using WC_COMPOSITECHECK, some character combinations might remain incomplete or might have additional nonspacing characters left over. For example, A + ¨ + ¨ combines to Ä + ¨. Using the WC_DISCARDNS flag causes the function to discard additional nonspacing characters. Using the WC_DEFAULTCHAR flag causes the function to use the default replacement character (typically "?") instead. Using the WC_SEPCHARS flag causes the function to attempt to convert each additional nonspacing character to the target code page. Usually this flag also causes the use of the replacement character ("?"). However, for code page 1258 (Vietnamese) and 20269, nonspacing characters exist and can be used. The conversions for these code pages are not perfect. Some combinations do not convert correctly to code page 1258, and WC_COMPOSITECHECK corrupts data in code page 20269. As mentioned earlier, it is more reliable to design your application to save and store such data as Unicode.

## Examples

```cpp
ISDSC_STATUS DiscpUnicodeToAnsiSize(
    IN __in PWCHAR UnicodeString,
    OUT ULONG *AnsiSizeInBytes
    )
/*++
Routine Description:
    This routine will return the length needed to represent the unicode
    string as ANSI
Arguments:
    UnicodeString is the unicode string whose ansi length is returned
    *AnsiSizeInBytes is number of bytes needed to represent unicode
        string as ANSI
Return Value:
    ERROR_SUCCESS or error code
--*/
{
    _try
    {
        *AnsiSizeInBytes = WideCharToMultiByte(CP_ACP,
                                               0,
                                               UnicodeString,
                                               -1,
                                               NULL,
                                               0, NULL, NULL);
    } _except(EXCEPTION_EXECUTE_HANDLER) {
        return(ERROR_NOACCESS);
    }
    return((*AnsiSizeInBytes == 0) ? GetLastError() : ERROR_SUCCESS);
}
```

## See also

[MultiByteToWideChar](https://learn.microsoft.com/windows/win32/api/stringapiset/nf-stringapiset-multibytetowidechar)

[Unicode and Character Set Functions](https://learn.microsoft.com/windows/win32/Intl/unicode-and-character-set-functions)

[Unicode and Character Sets](https://learn.microsoft.com/windows/win32/Intl/unicode-and-character-sets)

[Vertdll APIs available in VBS enclaves](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-available-in-vertdll)