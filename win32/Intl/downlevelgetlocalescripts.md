# DownlevelGetLocaleScripts function

Provides a list of scripts for the specified locale.

> [!Note]
> This function is used only by applications that run on pre-Windows Vista operating systems. Its use requires the download package. Applications that only run on Windows Vista and later should call [**GetLocaleInfo**](https://learn.microsoft.com/windows/desktop/api/Winnls/nf-winnls-getlocaleinfoa) with *LCType* set to [LOCALE\_SSCRIPTS](https://learn.microsoft.com/windows/win32/intl/locale-sscripts).

## Parameters

*lpLocaleName* \[in\]

Pointer to a null-terminated [locale name](https://learn.microsoft.com/windows/win32/intl/locale-names).

*lpScripts* \[out\]

Pointer to a buffer in which this function retrieves a null-terminated string representing a list of scripts, using the 4-character notation used in [ISO 15924](https://www.unicode.org/iso15924/iso15924-codes.html). Each script name consists of four Latin characters, and the names are retrieved in alphabetical order. Each of them, including the last, is followed by a semicolon.

Alternatively, this parameter can contain **NULL** if *cchScripts* is set to 0. In this case, the function returns the required size for the script buffer.

*cchScripts* \[in\]

Size, in characters, for the script buffer indicated by *lpScripts*.

Alternatively, the application can set this parameter to 0. In this case, the function retrieves **NULL** in *lpScripts* and returns the required size for the script buffer.

## Return value

Returns the number of characters retrieved in the script buffer, including the terminating null character. If the function succeeds and the value of *cchScripts* is 0, the return value is the required size, in characters including a terminating null character, for the script buffer.

This function returns 0 if it does not succeed. To get extended error information, the application can call [**GetLastError**](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror), which can return one of the following error codes:

- ERROR\_BADDB. The function could not access the data. This situation should not normally occur, and typically indicates a bad installation, a disk problem, or the like.
- ERROR\_INSUFFICIENT\_BUFFER. A supplied buffer size was not large enough, or it was incorrectly set to **NULL**.
- ERROR\_INVALID\_PARAMETER. Any of the parameter values was invalid.

## Remarks

This function is useful as part of a strategy to mitigate security issues related to [internationalized domain names (IDNs)](https://learn.microsoft.com/windows/win32/intl/handling-internationalized-domain-names--idns).

Here are some examples of inputs and outputs for this function, assuming a sufficient buffer size:

| Locale | *lpLocaleName* | *lpScripts* |
|-------------------------|----------------|-----------------|
| English (United States) | en-US | Latn; |
| Hindi (India) | hi-IN | Deva; |
| Japanese (Japan) | ja-JP | Hani;Hira;Kana; |

The list does not contain the Latin script unless it is an essential part of the writing system used for a locale. However, Latin characters are often used in the context of locales for which they are not native, as for a foreign business name. In the example above for Hindi in India, the only script retrieved is "Deva" (for Devanagari), although Latin characters can also appear in Hindi text. The [**DownlevelVerifyScripts**](https://learn.microsoft.com/windows/win32/intl/downlevelverifyscripts) function has a special flag to address that case.

The required header file and DLL are part of the ["Microsoft Internationalized Domain Name (IDN) Mitigation APIs"](https://archive.org/details/idndl.x86) download available from [archive.org](https://archive.org/).

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| Redistributable<br> | Microsoft Internationalized Domain Name (IDN) Mitigation APIs on Windows XP (SP2 or later), Windows Server 2003 (SP1 or later), or Windows Vista<br> |
| Header<br> | Idndl.h |
| DLL<br> | Idndl.dll |

## See also

[National Language Support](https://learn.microsoft.com/windows/win32/intl/national-language-support)

[National Language Support Functions](https://learn.microsoft.com/windows/win32/intl/national-language-support-functions)

[Handling Internationalized Domain Names (IDNs)](https://learn.microsoft.com/windows/win32/intl/handling-internationalized-domain-names--idns)

[**DownlevelGetStringScripts**](https://learn.microsoft.com/windows/win32/intl/downlevelgetstringscripts)

[**DownlevelVerifyScripts**](https://learn.microsoft.com/windows/win32/intl/downlevelverifyscripts)

[**GetLocaleInfo**](https://learn.microsoft.com/windows/desktop/api/Winnls/nf-winnls-getlocaleinfoa)

