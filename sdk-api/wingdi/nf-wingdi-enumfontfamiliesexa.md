# EnumFontFamiliesExA function

## Description

The **EnumFontFamiliesEx** function enumerates all uniquely-named fonts in the system that match the font characteristics specified by the [LOGFONT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logfonta) structure. **EnumFontFamiliesEx** enumerates fonts based on typeface name, character set, or both.

## Parameters

### `hdc` [in]

A handle to the device context from which to enumerate the fonts.

### `lpLogfont` [in]

A pointer to a [LOGFONT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logfonta) structure that contains information about the fonts to enumerate. The function examines the following members.

| Member | Description |
| --- | --- |
| **lfCharSet** | If set to DEFAULT_CHARSET, the function enumerates all uniquely-named fonts in all character sets. (If there are two fonts with the same name, only one is enumerated.) If set to a valid character set value, the function enumerates only fonts in the specified character set. |
| **lfFaceName** | If set to an empty string, the function enumerates one font in each available typeface name. If set to a valid typeface name, the function enumerates all fonts with the specified name. |
| **lfPitchAndFamily** | Must be set to zero for all language versions of the operating system. |

### `lpProc` [in]

A pointer to the application defined callback function. For more information, see the [EnumFontFamExProc](https://learn.microsoft.com/previous-versions/dd162618(v=vs.85)) function.

### `lParam` [in]

An application defined value. The function passes this value to the callback function along with font information.

### `dwFlags`

This parameter is not used and must be zero.

## Return value

The return value is the last value returned by the callback function. This value depends on which font families are available for the specified device.

## Remarks

The **EnumFontFamiliesEx** function does not use tagged typeface names to identify character sets. Instead, it always passes the correct typeface name and a separate character set value to the callback function. The function enumerates fonts based on the values of the **lfCharSet** and **lfFaceName** members in the [LOGFONT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logfonta) structure.

As with [EnumFontFamilies](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-enumfontfamiliesa), **EnumFontFamiliesEx** enumerates all font styles. Not all styles of a font cover the same character sets. For example, Fontorama Bold might contain ANSI, Greek, and Cyrillic characters, but Fontorama Italic might contain only ANSI characters. For this reason, it's best not to assume that a specified font covers a specific character set, even if it is the ANSI character set. The following table shows the results of various combinations of values for **lfCharSet** and **lfFaceName**.

| Values | Meaning |
| --- | --- |
| **lfCharSet** = DEFAULT_CHARSET<br><br>**lfFaceName** = '\0' | Enumerates all uniquely-named fonts within all character sets. If there are two fonts with the same name, only one is enumerated. |
| **lfCharSet** = DEFAULT_CHARSET<br><br>**lfFaceName** = a specific font | Enumerates all character sets and styles in a specific font. |
| **lfCharSet** =a specific character set<br><br>**lfFaceName** = '\0' | Enumerates all styles of all fonts in the specific character set. |
| **lfCharSet** =a specific character set<br><br>**lfFaceName** = a specific font | Enumerates all styles of a font in a specific character set. |

The following code sample shows how these values are used.

```cpp

// To enumerate all styles and charsets of all fonts:
lf.lfFaceName[0] = '\0';
lf.lfCharSet = DEFAULT_CHARSET;
HRESULT hr;

// To enumerate all styles and character sets of the Arial font:
hr = StringCchCopy( (LPSTR)lf.lfFaceName, LF_FACESIZE, "Arial" );
if (FAILED(hr))
{
// TODO: write error handler
}

lf.lfCharSet = DEFAULT_CHARSET;

```

```cpp

// To enumerate all styles of all fonts for the ANSI character set
lf.lfFaceName[0] = '\0';
lf.lfCharSet = ANSI_CHARSET;

// To enumerate all styles of Arial font that cover the ANSI charset
hr = StringCchCopy( (LPSTR)lf.lfFaceName, LF_FACESIZE, "Arial" );
if (FAILED(hr))
{
// TODO: write error handler
}

lf.lfCharSet = ANSI_CHARSET;

```

The callback functions for [EnumFontFamilies](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-enumfontfamiliesa) and **EnumFontFamiliesEx** are very similar. The main difference is that the [ENUMLOGFONTEX](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-enumlogfontexa) structure includes a script field.

Note, based on the values of **lfCharSet** and **lfFaceName**, **EnumFontFamiliesEx** will enumerate the same font as many times as there are distinct character sets in the font. This can create an extensive list of fonts which can be burdensome to a user. For example, the Century Schoolbook font can appear for the Baltic, Western, Greek, Turkish, and Cyrillic character sets. To avoid this, an application should filter the list of fonts.

The fonts for many East Asian languages have two typeface names: an English name and a localized name. [EnumFonts](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-enumfontsa), [EnumFontFamilies](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-enumfontfamiliesa), and **EnumFontFamiliesEx** return the English typeface name if the system locale does not match the language of the font.

When the graphics mode on the device context is set to GM_ADVANCED using the SetGraphicsMode function and the DEVICE_FONTTYPE flag is passed to the FontType parameter, this function returns a list of type 1 and OpenType fonts on the system. When the graphics mode is not set to GM_ADVANCED, this function returns a list of type 1, OpenType, and TrueType fonts on the system.

> [!NOTE]
> The wingdi.h header defines EnumFontFamiliesEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[EnumFontFamExProc](https://learn.microsoft.com/previous-versions/dd162618(v=vs.85))

[EnumFontFamilies](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-enumfontfamiliesa)

[EnumFonts](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-enumfontsa)

[Font and Text Functions](https://learn.microsoft.com/windows/desktop/gdi/font-and-text-functions)

[Fonts and Text Overview](https://learn.microsoft.com/windows/desktop/gdi/fonts-and-text)

[LOGFONT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logfonta)