# UILANGUAGE_ENUMPROCA callback function

## Description

An application-defined callback function that processes enumerated user interface language information provided by the [EnumUILanguages](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumuilanguagesa) function. The UILANGUAGE_ENUMPROC type defines a pointer to this callback function. **EnumUILanguagesProc** is a placeholder for the application-defined function name.

## Parameters

### `unnamedParam1`

### `unnamedParam2`

#### - lParam [in]

Application-defined value.

#### - lpUILanguageString [in]

Pointer to a buffer containing a null-terminated string representing a user interface language identifier or language name, depending on the value for the *dwFlags* parameter passed in the call to [EnumUILanguages](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumuilanguagesa).

## Return value

Returns **TRUE** to continue enumeration or **FALSE** otherwise.

## Remarks

An **EnumUILanguagesProc** function can carry out any task. The application registers this function by passing its address to the [EnumUILanguages](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumuilanguagesa) function.

If MUI_LANGUAGE_ID was specified in the call to **EnumUILanguages**, the language strings passed to this function will be hexadecimal language

identifiers that do not include the leading 0x, and will be 4 characters in length. For example, en-US will

be passed as "0409" and en as "0009".

### C# Signature

```cpp
delegate System.Boolean EnumUILanguagesProc(
            System.IntPtr lpUILanguageString,
            System.IntPtr lParam
            );

```

> [!NOTE]
> The winnls.h header defines UILANGUAGE_ENUMPROC as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[EnumUILanguages](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumuilanguagesa)

[Multilingual User Interface](https://learn.microsoft.com/windows/desktop/Intl/multilingual-user-interface)

[Multilingual User Interface Functions](https://learn.microsoft.com/windows/desktop/Intl/multilingual-user-interface-functions)