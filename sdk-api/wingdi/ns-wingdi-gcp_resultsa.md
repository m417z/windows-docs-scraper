# GCP_RESULTSA structure

## Description

The **GCP_RESULTS** structure contains information about characters in a string. This structure receives the results of the [GetCharacterPlacement](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getcharacterplacementa) function. For some languages, the first element in the arrays may contain more, language-dependent information.

## Members

### `lStructSize`

The size, in bytes, of the structure.

### `lpOutString`

A pointer to the buffer that receives the output string or is **NULL** if the output string is not needed. The output string is a version of the original string that is in the order that will be displayed on a specified device. Typically the output string is identical to the original string, but may be different if the string needs reordering and the GCP_REORDER flag is set or if the original string exceeds the maximum extent and the GCP_MAXEXTENT flag is set.

### `lpOrder`

A pointer to the array that receives ordering indexes or is **NULL** if the ordering indexes are not needed. However, its meaning depends on the other elements of **GCP_RESULTS**. If glyph indexes are to be returned, the indexes are for the **lpGlyphs** array; if glyphs indexes are not returned and **lpOrder** is requested, the indexes are for **lpOutString**. For example, in the latter case the value of **lpOrder**[i] is the position of **lpString**[i] in the output string lpOutString.

This is typically used when [GetFontLanguageInfo](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getfontlanguageinfo) returns the GCP_REORDER flag, which indicates that the original string needs reordering. For example, in Hebrew, in which the text runs from right to left, the **lpOrder** array gives the exact locations of each element in the original string.

### `lpDx`

A pointer to the array that receives the distances between adjacent character cells or is **NULL** if these distances are not needed. If glyph rendering is done, the distances are for the glyphs not the characters, so the resulting array can be used with the [ExtTextOut](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-exttextouta) function.

The distances in this array are in display order. To find the distance for the *i*th character in the original string, use the **lpOrder** array as follows:

``` syntax

width = lpDx[lpOrder[i]];

```

### `lpCaretPos`

A pointer to the array that receives the caret position values or is **NULL** if caret positions are not needed. Each value specifies the caret position immediately before the corresponding character. In some languages the position of the caret for each character may not be immediately to the left of the character. For example, in Hebrew, in which the text runs from right to left, the caret position is to the right of the character. If glyph ordering is done, **lpCaretPos** matches the original string, not the output string. This means that some adjacent values may be the same.

The values in this array are in input order. To find the caret position value for the *i*th character in the original string, use the array as follows:

``` syntax

position = lpCaretPos[i];

```

### `lpClass`

A pointer to the array that contains and/or receives character classifications. The values indicate how to lay out characters in the string and are similar (but not identical) to the CT_CTYPE2 values returned by the [GetStringTypeEx](https://learn.microsoft.com/previous-versions/ms960831(v%3dmsdn.10)) function. Each element of the array can be set to zero or one of the following values.

| Value | Meaning |
| --- | --- |
| **GCPCLASS_ARABIC** | Arabic character. |
| **GCPCLASS_HEBREW** | Hebrew character. |
| **GCPCLASS_LATIN** | Character from a Latin or other single-byte character set for a left-to-right language. |
| **GCPCLASS_LATINNUMBER** | Digit from a Latin or other single-byte character set for a left-to-right language. |
| **GCPCLASS_LOCALNUMBER** | Digit from the character set associated with the current font. |

In addition, the following can be used when supplying values in the **lpClass** array with the GCP_CLASSIN flag.

| Value | Meaning |
| --- | --- |
| **GCPCLASS_LATINNUMERICSEPARATOR** | Input only. Character used to separate Latin digits, such as a comma or decimal point. |
| **GCPCLASS_LATINNUMERICTERMINATOR** | Input only. Character used to terminate Latin digits, such as a plus or minus sign. |
| **GCPCLASS_NEUTRAL** | Input only. Character has no specific classification. |
| **GCPCLASS_NUMERICSEPARATOR** | Input only. Character used to separate digits, such as a comma or decimal point. |

For languages that use the GCP_REORDER flag, the following values can also be used with the GCP_CLASSIN flag. Unlike the preceding values, which can be used anywhere in the **lpClass** array, all of the following values are used only in the first location in the array. All combine with other classifications.

Note that GCPCLASS_PREBOUNDLTR and GCPCLASS_PREBOUNDRTL are mutually exclusive, as are GCPCLASSPOSTBOUNDLTR and GCPCLASSPOSTBOUNDRTL.

| Value | Meaning |
| --- | --- |
| **GCPCLASS_PREBOUNDLTR** | Set **lpClass**[0] to GCPCLASS_PREBOUNDLTR to bind the string to left-to-right reading order before the string. |
| **GCPCLASS_PREBOUNDRTL** | Set **lpClass**[0] to GCPCLASS_PREBOUNDRTL to bind the string to right-to-left reading order before the string. |
| **GCPCLASS_POSTBOUNDLTR** | Set **lpClass**[0] to GCPCLASS_POSTBOUNDLTR to bind the string to left-to-right reading order after the string. |
| **GCPCLASS_POSTBOUNDRTL** | Set **lpClass**[0] to GCPCLASS_POSTBOUNDRTL to bind the string to right-to-left reading order after the string. |

To force the layout of a character to be carried out in a specific way, preset the classification for the corresponding array element; the function leaves such preset classifications unchanged and computes classifications only for array elements that have been set to zero. Preset classifications are used only if the GCP_CLASSIN flag is set and the **lpClass** array is supplied.

If [GetFontLanguageInfo](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getfontlanguageinfo) does not return GCP_REORDER for the current font, only the GCPCLASS_LATIN value is meaningful.

### `lpGlyphs`

A pointer to the array that receives the values identifying the glyphs used for rendering the string or is **NULL** if glyph rendering is not needed. The number of glyphs in the array may be less than the number of characters in the original string if the string contains ligated glyphs. Also if reordering is required, the order of the glyphs may not be sequential.

This array is useful if more than one operation is being done on a string which has any form of ligation, kerning or order-switching. Using the values in this array for subsequent operations saves the time otherwise required to generate the glyph indices each time.

This array always contains glyph indices and the ETO_GLYPH_INDEX value must always be used when this array is used with the [ExtTextOut](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-exttextouta) function.

When GCP_LIGATE is used, you can limit the number of characters that will be ligated together. (In Arabic for example, three-character ligations are common). This is done by setting the maximum required in lpGcpResults->lpGlyphs[0]. If no maximum is required, you should set this field to zero.

For languages such as Arabic, where [GetFontLanguageInfo](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getfontlanguageinfo) returns the GCP_GLYPHSHAPE flag, the glyphs for a character will be different depending on whether the character is at the beginning, middle, or end of a word. Typically, the first character in the input string will also be the first character in a word, and the last character in the input string will be treated as the last character in a word. However, if the displayed string is a subset of the complete string, such as when displaying a section of scrolled text, this may not be true. In these cases, it is desirable to force the first or last characters to be shaped as not being initial or final forms. To do this, again, the first location in the **lpGlyphs** array is used by performing an OR operation of the ligation value above with the values GCPGLYPH_LINKBEFORE and/or GCPGLYPH_LINKAFTER. For example, a value of GCPGLYPH_LINKBEFORE | 2 means that two-character ligatures are the maximum required, and the first character in the string should be treated as if it is in the middle of a word.

### `nGlyphs`

On input, this member must be set to the size of the arrays pointed to by the array pointer members. On output, this is set to the number of glyphs filled in, in the output arrays. If glyph substitution is not required (that is, each input character maps to exactly one glyph), this member is the same as it is on input.

### `nMaxFit`

The number of characters that fit within the extents specified by the *nMaxExtent* parameter of the [GetCharacterPlacement](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getcharacterplacementa) function. If the GCP_MAXEXTENT or GCP_JUSTIFY value is set, this value may be less than the number of characters in the original string. This member is set regardless of whether the GCP_MAXEXTENT or GCP_JUSTIFY value is specified. Unlike **nGlyphs**, which specifies the number of output glyphs, **nMaxFit** refers to the number of characters from the input string. For Latin SBCS languages, this will be the same.

## Remarks

Whether the **lpGlyphs**, **lpOutString**, or neither is required depends on the results of the [GetFontLanguageInfo](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getfontlanguageinfo) call.

In the case of a font for a language such as English, in which none of the GCP_DBCS, GCP_REORDER, GCP_GLYPHSHAPE, GCP_LIGATE, GCP_DIACRITIC, or GCP_KASHIDA flags are returned, neither of the arrays is required for proper operation. (Though not required, they can still be used. If the **lpOutString** array is used, it will be exactly the same as the *lpInputString* passed to [GetCharacterPlacement](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getcharacterplacementa).) Note, however, that if GCP_MAXEXTENT is used, then **lpOutString** will contain the truncated string if it is used, NOT an exact copy of the original.

In the case of fonts for languages such as Hebrew, which DO have reordering but do not typically have extra glyph shapes, **lpOutString** should be used. This will give the string on the screen-readable order. However, the **lpGlyphs** array is not typically needed. (Hebrew can have extra glyphs, if the font is a TrueType/Open font.)

In the case of languages such as Thai or Arabic, in which [GetFontLanguageInfo](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getfontlanguageinfo) returns the GCP_GLYPHSHAPE flag, the **lpOutString** will give the display-readable order of the string passed to [GetCharacterPlacement](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getcharacterplacementa), but the values will still be the unshaped characters. For proper display, the **lpGlyphs** array must be used.

> [!NOTE]
> The wingdi.h header defines GCP_RESULTS as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[ExtTextOut](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-exttextouta)

[Font and Text Structures](https://learn.microsoft.com/windows/desktop/gdi/font-and-text-structures)

[Fonts and Text Overview](https://learn.microsoft.com/windows/desktop/gdi/fonts-and-text)

[GetCharacterPlacement](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getcharacterplacementa)

[GetFontLanguageInfo](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getfontlanguageinfo)