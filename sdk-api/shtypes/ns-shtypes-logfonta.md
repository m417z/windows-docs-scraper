# LOGFONTA structure

## Description

Defines the attributes of a font.

## Members

### `lfHeight`

Type: **LONG**

Specifies the height, in logical units, of the font's character cell or character. The character height value (also known as the em height) is the character cell height value minus the internal-leading value. The font mapper interprets the value specified in **lfHeight** in the following manner.

| Value | Description |
| --- | --- |
| > 0 | The font mapper transforms this value into device units and matches it against the cell height of the available fonts. |
| 0 | The font mapper uses a default height value when it searches for a match. |
| < 0 | The font mapper transforms this value into device units and matches its absolute value against the character height of the available fonts. |

For all height comparisons, the font mapper looks for the largest font that does not exceed the requested size.

This mapping occurs when the font is used for the first time.

For the MM_TEXT mapping mode, you may use the following formula to specify a height for a font with a given point size.

```cpp
lfHeight = -MulDiv(PointSize, GetDeviceCaps(hDC, LOGPIXELSY), 72);

```

where **MulDiv** is defined as follows:

```cpp
#define MulDiv(a,b,c)    (((a)*(b))/(c))

```

### `lfWidth`

Type: **LONG**

Specifies the average width, in logical units, of characters in the font. If **lfWidth** is not zero, the aspect ratio of the device is matched against the digitization aspect ratio of the available fonts to find the closest match, determined by the absolute value of the difference.

### `lfEscapement`

Type: **LONG**

Specifies the angle, in tenths of degrees, between the escapement vector and the x-axis of the device. The escapement vector is parallel to the base line of a row of text.

The **lfEscapement** member specifies both the escapement and orientation. You should set **lfEscapement** and **lfOrientation** to the same value.

### `lfOrientation`

Type: **LONG**

Specifies the angle, in tenths of degrees, between each character's base line and the x-axis of the device.

### `lfWeight`

Type: **LONG**

Specifies the weight of the font in the range 0 through 1000. For example, 400 is normal and 700 is bold. If this value is zero, a default weight is used.

The following values are defined in Wingdi.h for convenience.

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

Type: **BYTE**

**TRUE** to specify an italic font.

### `lfUnderline`

Type: **BYTE**

**TRUE** to specify an underlined font.

### `lfStrikeOut`

Type: **BYTE**

**TRUE** to specify a strikeout font.

### `lfCharSet`

Type: **BYTE**

Specifies the character set. The following values are predefined:

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

This member is important in the font mapping process. To ensure consistent results, specify a specific character set. If you specify a typeface name in the **lfFaceName** member, make sure that the **lfCharSet** value matches the character set of the typeface specified in **lfFaceName**.

### `lfOutPrecision`

Type: **BYTE**

Specifies the output precision. The output precision defines how closely the output must match the requested font's height, width, character orientation, escapement, pitch, and font type. It can be one of the following values defined in Wingdi.h:

| Value | Description |
| --- | --- |
| OUT_DEFAULT_PRECIS | Specifies the default font mapper behavior. |
| OUT_RASTER_PRECIS | Instructs the font mapper to choose a raster font when the system contains multiple fonts with the same name. |
| OUT_STRING_PRECIS | This value is not used by the font mapper, but it is returned when raster fonts are enumerated. |

### `lfClipPrecision`

Type: **BYTE**

Specifies the clipping precision. The clipping precision defines how to clip characters that are partially outside the clipping region. It can be one or more of the following values defined in Wingdi.h:

| Value | Description |
| --- | --- |
| CLIP_DEFAULT_PRECIS | Specifies default clipping behavior. |
| CLIP_CHARACTER_PRECIS | Not used. |
| CLIP_STROKE_PRECIS | Not used by the font mapper, but is returned when raster, vector, or TrueType fonts are enumerated. |

### `lfQuality`

Type: **BYTE**

Specifies the output quality. The output quality defines how carefully the GDI must attempt to match the logical-font attributes to those of an actual physical font. It can be one of the following values defined in Wingdi.h:

| Value | Description |
| --- | --- |
| ANTIALIASED_QUALITY | Enables antialiasing for the font. The display driver must support antialiased text for this setting to work. |
| NONANTIALIASED_QUALITY | Forces use of draft quality when the **HKEY_LOCAL_MACHINE**\**System**\**GDI**\**Fontsmoothing** registry subkey is present. |
| CLEARTYPE_COMPAT_QUALITY | Enables ClearType text for the font using compatible widths. A compatible width produces text that has the same spacing as non-ClearType text. |
| CLEARTYPE_QUALITY | Enables ClearType text for the font. The display driver must support ClearType text for this setting to work. |
| DEFAULT_QUALITY | Appearance of the font does not matter. |
| DRAFT_QUALITY | For GDI raster fonts, scaling is enabled, which means that more font sizes are available, but the quality may be lower. Bold, italic, underline, and strikeout fonts are synthesized if necessary. |

### `lfPitchAndFamily`

Type: **BYTE**

Specifies the pitch and group of the font. The two low-order bits specify the pitch of the font and can be one of the following values defined in Wingdi.h:

* DEFAULT_PITCH
* FIXED_PITCH
* MONO_FONT
* VARIABLE_PITCH

Bits 4 through 7 of the member specify the font group and can be one of the following values defined in Wingdi.h:

* FF_DECORATIVE
* FF_DONTCARE
* FF_MODERN
* FF_ROMAN
* FF_SCRIPT
* FF_SWISS

The proper value can be obtained by using the Boolean OR operator to join one pitch constant with one family constant.

Font families describe the look of a font in a general way. They are intended for specifying fonts when the exact typeface desired is not available. The values for font families are as follows:

| Value | Description |
| --- | --- |
| FF_DECORATIVE | Novelty fonts, for example, Old English. |
| FF_DONTCARE | Do not care or do not know. |
| FF_MODERN | Fonts with constant stroke width (monospace), with or without serifs. Monospace fonts are usually modern, for example, Pica, Elite, and Courier New. |
| FF_ROMAN | Fonts with variable stroke width (proportional) and with serifs, for example, Serif. |
| FF_SCRIPT | Fonts designed to look like handwriting, for example, Script and Cursive. |
| FF_SWISS | Fonts with variable stroke width (proportional) and without serifs, for example, Sans Serif. |

### `lfFaceName`

Type: **TCHAR[LF_FACESIZE]**

Specifies a null-terminated string that specifies the typeface name of the font. The length of this string must not exceed 32 characters, including the terminating null character. The [EnumFontFamilies](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-enumfontfamiliesa) function can be used to enumerate the typeface names of all currently available fonts. If **lfFaceName** is an empty string, GDI uses the first font that matches the other specified attributes.

## Remarks

The following situations do not support ClearType antialiasing:

* Text is rendered on a printer.
* Display set for 256 colors or less.
* Text is rendered to a terminal server client.
* The font is not a TrueType font or an Microsoft OpenType font with TrueType outlines. For example, the following do not support ClearType antialiasing: Type 1 fonts, Postscript OpenType fonts without TrueType outlines, bitmap fonts, vector fonts, and device fonts.
* The font has tuned embedded bitmaps, for any font sizes that contain the embedded bitmaps. For example, this occurs commonly in East Asian fonts.

This structure first appeared in Shtypes.idl and Shtypes.h in Windows Vista, for ease of use with members of the [IVisualProperties](https://learn.microsoft.com/windows/desktop/api/shobjidl/nn-shobjidl-ivisualproperties) interface. However, the identical structure is defined in Wingdi.h and Windows.h in earlier versions of Windows.

## See also

[IVisualProperties::GetFont](https://learn.microsoft.com/windows/desktop/api/shobjidl/nf-shobjidl-ivisualproperties-getfont)

[IVisualProperties::SetFont](https://learn.microsoft.com/windows/desktop/api/shobjidl/nf-shobjidl-ivisualproperties-setfont)