# LOGFONTW structure

## Description

The **LOGFONT** structure defines the attributes of a font.

## Members

### `lfHeight`

The height, in logical units, of the font's character cell or character. The character height value (also known as the em height) is the character cell height value minus the internal-leading value. The font mapper interprets the value specified in **lfHeight** in the following manner.

| Value | Meaning |
| --- | --- |
| > 0 | The font mapper transforms this value into device units and matches it against the cell height of the available fonts. |
| 0 | The font mapper uses a default height value when it searches for a match. |
| < 0 | The font mapper transforms this value into device units and matches its absolute value against the character height of the available fonts. |

For all height comparisons, the font mapper looks for the largest font that does not exceed the requested size.

This mapping occurs when the font is used for the first time.

For the MM_TEXT mapping mode, you can use the following formula to specify a height for a font with a specified point size:

```cpp

lfHeight = -MulDiv(PointSize, GetDeviceCaps(hDC, LOGPIXELSY), 72);

```

### `lfWidth`

The average width, in logical units, of characters in the font. If **lfWidth** is zero, the aspect ratio of the device is matched against the digitization aspect ratio of the available fonts to find the closest match, determined by the absolute value of the difference.

### `lfEscapement`

The angle, in tenths of degrees, between the escapement vector and the x-axis of the device. The escapement vector is parallel to the base line of a row of text.

 When the graphics mode is set to GM_ADVANCED, you can specify the escapement angle of the string independently of the orientation angle of the string's characters.

When the graphics mode is set to GM_COMPATIBLE, **lfEscapement** specifies both the escapement and orientation. You should set **lfEscapement** and **lfOrientation** to the same value.

### `lfOrientation`

The angle, in tenths of degrees, between each character's base line and the x-axis of the device.

### `lfWeight`

The weight of the font in the range 0 through 1000. For example, 400 is normal and 700 is bold. If this value is zero, a default weight is used.

The following values are defined for convenience.

| Value | Weight |
| --- | --- |
| FW_DONTCARE | 0 |
| FW_THIN | 100 |
| FW_EXTRALIGHT | 200 |
| FW_ULTRALIGHT | 200 |
| FW_LIGHT | 300 |
| FW_NORMAL | 400 |
| FW_REGULAR | 400 |
| FW_MEDIUM | 500 |
| FW_SEMIBOLD | 600 |
| FW_DEMIBOLD | 600 |
| FW_BOLD | 700 |
| FW_EXTRABOLD | 800 |
| FW_ULTRABOLD | 800 |
| FW_HEAVY | 900 |
| FW_BLACK | 900 |

### `lfItalic`

An italic font if set to **TRUE**.

### `lfUnderline`

An underlined font if set to **TRUE**.

### `lfStrikeOut`

A strikeout font if set to **TRUE**.

### `lfCharSet`

The character set. The following values are predefined:

| Value | Description |
|--|--|
| **ANSI_CHARSET** | This font supports the Windows ANSI character set. |
| **ARABIC_CHARSET** | This font supports the Arabic character set. |
| **BALTIC_CHARSET** | This font supports the Baltic character set. |
| **CHINESEBIG5_CHARSET** | This font supports the traditional Chinese (Big 5) character set. |
| **DEFAULT_CHARSET** | This font supports character set value based on the system default Windows ANSI code page. For example, when the system locale is English (United States), it is set as ANSI_CHARSET. |
| **EASTEUROPE_CHARSET** | This font supports the Eastern European character set. |
| **GB2312_CHARSET** | This font supports the simplified (PRC) Chinese character set. |
| **GREEK_CHARSET** | This font supports the Greek character set. |
| **HANGEUL_CHARSET** | This font supports the Korean (Hangul) character set. |
| **HEBREW_CHARSET** | This font supports the Hebrew character set. |
| **JOHAB_CHARSET** | This font supports the Korean (Johab) character set. |
| **MAC_CHARSET** | This font supports character set value based on the current system Macintosh code page. This value is used primarily in legacy code and should not generally be needed since modern Macintosh computers use Unicode for encoding. |
| **OEM_CHARSET** | This font supports an OEM-specific character set. The OEM character set is system dependent. |
| **RUSSIAN_CHARSET** | This font supports the Cyrillic character set. |
| **SHIFTJIS_CHARSET** | This font supports the Shift-JIS (Japanese Industry Standard) character set. |
| **SYMBOL_CHARSET** | This font supports the Windows symbol character set. |
| **THAI_CHARSET** | This font supports the Thai character set. |
| **TURKISH_CHARSET** | This font supports the Turkish character set. |
| **VIETNAMESE_CHARSET** | This font supports the Vietnamese character set. |

Fonts with other character sets may exist in the operating system. If an application uses a font with an unknown character set, it should not attempt to translate or interpret strings that are rendered with that font.

This parameter is important in the font mapping process. To ensure consistent results when creating a font, do not specify **OEM_CHARSET** or **DEFAULT_CHARSET**. If you specify a typeface name in the **lfFaceName** member, make sure that the **lfCharSet** value matches the character set of the typeface specified in **lfFaceName**.

### `lfOutPrecision`

The output precision. The output precision defines how closely the output must match the requested font's height, width, character orientation, escapement, pitch, and font type. It can be one of the following values.

| Value | Meaning |
| --- | --- |
| OUT_CHARACTER_PRECIS | Not used. |
| OUT_DEFAULT_PRECIS | Specifies the default font mapper behavior. |
| OUT_DEVICE_PRECIS | Instructs the font mapper to choose a Device font when the system contains multiple fonts with the same name. |
| OUT_OUTLINE_PRECIS | This value instructs the font mapper to choose from TrueType and other outline-based fonts. |
| OUT_PS_ONLY_PRECIS | Instructs the font mapper to choose from only PostScript fonts. If there are no PostScript fonts installed in the system, the font mapper returns to default behavior. |
| OUT_RASTER_PRECIS | Instructs the font mapper to choose a raster font when the system contains multiple fonts with the same name. |
| OUT_STRING_PRECIS | This value is not used by the font mapper, but it is returned when raster fonts are enumerated. |
| OUT_STROKE_PRECIS | This value is not used by the font mapper, but it is returned when TrueType, other outline-based fonts, and vector fonts are enumerated. |
| OUT_TT_ONLY_PRECIS | Instructs the font mapper to choose from only TrueType fonts. If there are no TrueType fonts installed in the system, the font mapper returns to default behavior. |
| OUT_TT_PRECIS | Instructs the font mapper to choose a TrueType font when the system contains multiple fonts with the same name. |

Applications can use the OUT_DEVICE_PRECIS, OUT_RASTER_PRECIS, OUT_TT_PRECIS, and OUT_PS_ONLY_PRECIS values to control how the font mapper chooses a font when the operating system contains more than one font with a specified name. For example, if an operating system contains a font named Symbol in raster and TrueType form, specifying OUT_TT_PRECIS forces the font mapper to choose the TrueType version. Specifying OUT_TT_ONLY_PRECIS forces the font mapper to choose a TrueType font, even if it must substitute a TrueType font of another name.

### `lfClipPrecision`

The clipping precision. The clipping precision defines how to clip characters that are partially outside the clipping region. It can be one or more of the following values.

For more information about the orientation of coordinate systems, see the description of the *nOrientation* parameter.

| Value | Meaning |
| --- | --- |
| CLIP_CHARACTER_PRECIS | Not used. |
| CLIP_DEFAULT_PRECIS | Specifies default clipping behavior. |
| CLIP_DFA_DISABLE | **Windows XP SP1:** Turns off font association for the font. Note that this flag is not guaranteed to have any effect on any platform after Windows Server 2003. |
| CLIP_EMBEDDED | You must specify this flag to use an embedded read-only font. |
| CLIP_LH_ANGLES | When this value is used, the rotation for all fonts depends on whether the orientation of the coordinate system is left-handed or right-handed.If not used, device fonts always rotate counterclockwise, but the rotation of other fonts is dependent on the orientation of the coordinate system. |
| CLIP_MASK | Not used. |
| CLIP_DFA_OVERRIDE | Turns off font association for the font. This is identical to CLIP_DFA_DISABLE, but it can have problems in some situations; the recommended flag to use is CLIP_DFA_DISABLE. |
| CLIP_STROKE_PRECIS | Not used by the font mapper, but is returned when raster, vector, or TrueType fonts are enumerated. For compatibility, this value is always returned when enumerating fonts. |
| CLIP_TT_ALWAYS | Not used. |

### `lfQuality`

The output quality. The output quality defines how carefully the graphics device interface (GDI) must attempt to match the logical-font attributes to those of an actual physical font. It can be one of the following values.

| Value | Meaning |
| --- | --- |
| ANTIALIASED_QUALITY | Font is always antialiased if the font supports it and the size of the font is not too small or too large. |
| CLEARTYPE_QUALITY | If set, text is rendered (when possible) using ClearType antialiasing method. See Remarks for more information. |
| DEFAULT_QUALITY | Appearance of the font does not matter. |
| DRAFT_QUALITY | Appearance of the font is less important than when PROOF_QUALITY is used. For GDI raster fonts, scaling is enabled, which means that more font sizes are available, but the quality may be lower. Bold, italic, underline, and strikeout fonts are synthesized if necessary. |
| NONANTIALIASED_QUALITY | Font is never antialiased. |
| PROOF_QUALITY | Character quality of the font is more important than exact matching of the logical-font attributes. For GDI raster fonts, scaling is disabled and the font closest in size is chosen. Although the chosen font size may not be mapped exactly when PROOF_QUALITY is used, the quality of the font is high and there is no distortion of appearance. Bold, italic, underline, and strikeout fonts are synthesized if necessary. |

If neither ANTIALIASED_QUALITY nor NONANTIALIASED_QUALITY is selected, the font is antialiased only if the user chooses smooth screen fonts in Control Panel.

### `lfPitchAndFamily`

The pitch and family of the font. The two low-order bits specify the pitch of the font and can be one of the following values.

* DEFAULT_PITCH
* FIXED_PITCH
* VARIABLE_PITCH

Bits 4 through 7 of the member specify the font family and can be one of the following values.

* FF_DECORATIVE
* FF_DONTCARE
* FF_MODERN
* FF_ROMAN
* FF_SCRIPT
* FF_SWISS

The proper value can be obtained by using the bitwise OR (|) operator to join one pitch constant with one family constant.

Font families describe the look of a font in a general way. They are intended for specifying fonts when the exact typeface desired is not available. The values for font families are as follows.

| Value | Meaning |
| --- | --- |
| FF_DECORATIVE | Novelty fonts. Old English is an example. |
| FF_DONTCARE | Use default font. |
| FF_MODERN | Fonts with constant stroke width (monospace), with or without serifs. Monospace fonts are usually modern. Pica, Elite, and CourierNew are examples. |
| FF_ROMAN | Fonts with variable stroke width (proportional) and with serifs. MS Serif is an example. |
| FF_SCRIPT | Fonts designed to look like handwriting. Script and Cursive are examples. |
| FF_SWISS | Fonts with variable stroke width (proportional) and without serifs. MS Sans Serif is an example. |

### `lfFaceName`

A null-terminated string that specifies the typeface name of the font. The length of this string must not exceed 32 **TCHAR** values, including the terminating **NULL**. The [EnumFontFamiliesEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-enumfontfamiliesexa) function can be used to enumerate the typeface names of all currently available fonts. If **lfFaceName** is an empty string, GDI uses the first font that matches the other specified attributes.

## Remarks

The following situations do not support ClearType antialiasing:

* Text is rendered on a printer.
* Display set for 256 colors or less.
* Text is rendered to a terminal server client.
* The font is not a TrueType font or an OpenType font with TrueType outlines. For example, the following do not support ClearType antialiasing: Type 1 fonts, Postscript OpenType fonts without TrueType outlines, bitmap fonts, vector fonts, and device fonts.
* The font has tuned embedded bitmaps, for any font sizes that contain the embedded bitmaps. For example, this occurs commonly in East Asian fonts.

> [!NOTE]
> The wingdi.h header defines LOGFONT as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CreateFont](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createfonta)

[CreateFontIndirect](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createfontindirecta)

[EnumFontFamiliesEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-enumfontfamiliesexa)

[Font and Text Structures](https://learn.microsoft.com/windows/desktop/gdi/font-and-text-structures)

[Fonts and Text Overview](https://learn.microsoft.com/windows/desktop/gdi/fonts-and-text)