# EnumFontsA function

## Description

The **EnumFonts** function enumerates the fonts available on a specified device. For each font with the specified typeface name, the **EnumFonts** function retrieves information about that font and passes it to the application defined callback function. This callback function can process the font information as desired. Enumeration continues until there are no more fonts or the callback function returns zero.

**Note** This function is provided only for compatibility with 16-bit versions of Windows. Applications should use the [EnumFontFamiliesEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-enumfontfamiliesexa) function.

## Parameters

### `hdc` [in]

A handle to the device context from which to enumerate the fonts.

### `lpLogfont` [in]

A pointer to a null-terminated string that specifies the typeface name of the desired fonts. If *lpFaceName* is **NULL**, **EnumFonts** randomly selects and enumerates one font of each available typeface.

### `lpProc` [in]

A pointer to the application definedcallback function. For more information, see [EnumFontsProc](https://learn.microsoft.com/previous-versions/dd162623(v=vs.85)).

### `lParam` [in]

A pointer to any application-defined data. The data is passed to the callback function along with the font information.

## Return value

The return value is the last value returned by the callback function. Its meaning is defined by the application.

## Remarks

Use [EnumFontFamiliesEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-enumfontfamiliesexa) instead of **EnumFonts**. The **EnumFontFamiliesEx** function differs from the **EnumFonts** function in that it retrieves the style names associated with a TrueType font. With **EnumFontFamiliesEx**, you can retrieve information about font styles that cannot be enumerated using the **EnumFonts** function.

The fonts for many East Asian languages have two typeface names: an English name and a localized name. **EnumFonts**, [EnumFontFamilies](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-enumfontfamiliesa), and [EnumFontFamiliesEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-enumfontfamiliesexa) return the English typeface name if the system locale does not match the language of the font.

> [!NOTE]
> The wingdi.h header defines EnumFonts as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[EnumFontFamilies](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-enumfontfamiliesa)

[EnumFontFamiliesEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-enumfontfamiliesexa)

[EnumFontsProc](https://learn.microsoft.com/previous-versions/dd162623(v=vs.85))

[Font and Text Functions](https://learn.microsoft.com/windows/desktop/gdi/font-and-text-functions)

[Fonts and Text Overview](https://learn.microsoft.com/windows/desktop/gdi/fonts-and-text)

[GetDeviceCaps](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getdevicecaps)