# VerLanguageNameA function

## Description

Retrieves a description string for the language associated with a specified binary Microsoft language identifier.

## Parameters

### `wLang` [in]

Type: **DWORD**

The binary language identifier. For a complete list of the language identifiers, see [Language Identifiers](https://learn.microsoft.com/windows/desktop/Intl/language-identifiers).

For example, the description string associated with the language identifier 0x040A is "Spanish (Traditional Sort)". If the identifier is unknown, the *szLang* parameter points to a default string ("Language Neutral").

### `szLang` [out]

Type: **LPTSTR**

The language specified by the *wLang* parameter.

### `cchLang` [in]

Type: **DWORD**

The size, in characters, of the buffer pointed to by *szLang*.

## Return value

Type: **DWORD**

The return value is the size, in characters, of the string returned in the buffer. This value does not include the terminating null character. If the description string is smaller than or equal to the buffer, the entire description string is in the buffer. If the description string is larger than the buffer, the description string is truncated to the length of the buffer.

If an error occurs, the return value is zero. Unknown language identifiers do not produce errors.

## Remarks

 This function works on 16-, 32-, and 64-bit file images.

Typically, an installation program uses this function to translate a language identifier returned by the [VerQueryValue](https://learn.microsoft.com/windows/desktop/api/winver/nf-winver-verqueryvaluea) function. The text string may be used in a dialog box that asks the user how to proceed in the event of a language conflict.

> [!NOTE]
> The winver.h header defines VerLanguageName as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Version Information Overview](https://learn.microsoft.com/windows/desktop/menurc/version-information)