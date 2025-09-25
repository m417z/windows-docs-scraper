# EnumFontFamiliesA function

## Description

The **EnumFontFamilies** function enumerates the fonts in a specified font family that are available on a specified device.

**Note** This function is provided only for compatibility with 16-bit versions of Windows. Applications should use the [EnumFontFamiliesEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-enumfontfamiliesexa) function.

## Parameters

### `hdc` [in]

A handle to the device context from which to enumerate the fonts.

### `lpLogfont` [in]

A pointer to a null-terminated string that specifies the family name of the desired fonts. If *lpszFamily* is **NULL**, **EnumFontFamilies** selects and enumerates one font of each available type family.

### `lpProc` [in]

A pointer to the application defined callback function. For information, see [EnumFontFamProc](https://learn.microsoft.com/previous-versions/dd162621(v=vs.85)).

### `lParam` [in]

A pointer to application-supplied data. The data is passed to the callback function along with the font information.

## Return value

The return value is the last value returned by the callback function. Its meaning is implementation specific.

## Remarks

For each font having the typeface name specified by the *lpszFamily* parameter, the **EnumFontFamilies** function retrieves information about that font and passes it to the function pointed to by the *lpEnumFontFamProc* parameter. The application defined callback function can process the font information as desired. Enumeration continues until there are no more fonts or the callback function returns zero.

When the graphics mode on the device context is set to GM_ADVANCED using the SetGraphicsMode function and the DEVICE_FONTTYPE flag is passed to the FontType parameter, this function returns a list of type 1 and OpenType fonts on the system. When the graphics mode is not set to GM_ADVANCED, this function returns a list of type 1, OpenType, and TrueType fonts on the system.

The fonts for many East Asian languages have two typeface names: an English name and a localized name. [EnumFonts](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-enumfontsa), **EnumFontFamilies**, and [EnumFontFamiliesEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-enumfontfamiliesexa) return the English typeface name if the system locale does not match the language of the font.

#### Examples

For examples, see [Enumerating the Installed Fonts](https://learn.microsoft.com/windows/desktop/gdi/enumerating-the-installed-fonts).

> [!NOTE]
> The wingdi.h header defines EnumFontFamilies as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[EnumFontFamProc](https://learn.microsoft.com/previous-versions/dd162621(v=vs.85))

[EnumFontFamiliesEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-enumfontfamiliesexa)

[EnumFonts](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-enumfontsa)

[Font and Text Functions](https://learn.microsoft.com/windows/desktop/gdi/font-and-text-functions)

[Fonts and Text Overview](https://learn.microsoft.com/windows/desktop/gdi/fonts-and-text)