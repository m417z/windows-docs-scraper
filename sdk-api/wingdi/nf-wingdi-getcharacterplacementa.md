# GetCharacterPlacementA function

## Description

The **GetCharacterPlacement** function retrieves information about a character string, such as character widths, caret positioning, ordering within the string, and glyph rendering. The type of information returned depends on the *dwFlags* parameter and is based on the currently selected font in the specified display context. The function copies the information to the specified [GCP_RESULTS](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-gcp_resultsa) structure or to one or more arrays specified by the structure.

Although this function was once adequate for working with character strings, a need to work with an increasing number of languages and scripts has rendered it obsolete. It has been superseded by the functionality of the Uniscribe module. For more information, see [Uniscribe](https://learn.microsoft.com/windows/desktop/Intl/uniscribe).

It is recommended that an application use the [GetFontLanguageInfo](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getfontlanguageinfo) function to determine whether the GCP_DIACRITIC, GCP_DBCS, GCP_USEKERNING, GCP_LIGATE, GCP_REORDER, GCP_GLYPHSHAPE, and GCP_KASHIDA values are valid for the currently selected font. If not valid, **GetCharacterPlacement** ignores the value.

The GCP_NODIACRITICS value is no longer defined and should not be used.

## Parameters

### `hdc` [in]

A handle to the device context.

### `lpString` [in]

A pointer to the character string to process. The string does not need to be zero-terminated, since *nCount* specifies the length of the string.

### `nCount` [in]

The [length of the string](https://learn.microsoft.com/windows/desktop/gdi/specifying-length-of-text-output-string) pointed to by *lpString*.

### `nMexExtent` [in]

The maximum extent (in logical units) to which the string is processed. Characters that, if processed, would exceed this extent are ignored. Computations for any required ordering or glyph arrays apply only to the included characters. This parameter is used only if the GCP_MAXEXTENT value is specified in the *dwFlags* parameter. As the function processes the input string, each character and its extent is added to the output, extent, and other arrays only if the total extent has not yet exceeded the maximum. Once the limit is reached, processing will stop.

### `lpResults` [in, out]

A pointer to a [GCP_RESULTS](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-gcp_resultsa) structure that receives the results of the function.

### `dwFlags` [in]

Specifies how to process the string into the required arrays. This parameter can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **GCP_CLASSIN** | Specifies that the *lpClass* array contains preset classifications for characters. The classifications may be the same as on output. If the particular classification for a character is not known, the corresponding location in the array must be set to zero. for more information about the classifications, see GCP_RESULTS. This is useful only if [GetFontLanguageInfo](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getfontlanguageinfo) returned the GCP_REORDER flag. |
| **GCP_DIACRITIC** | Determines how diacritics in the string are handled. If this value is not set, diacritics are treated as zero-width characters. For example, a Hebrew string may contain diacritics, but you may not want to display them.<br><br>Use [GetFontLanguageInfo](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getfontlanguageinfo) to determine whether a font supports diacritics. If it does, you can use or not use the GCP_DIACRITIC flag in the call to **GetCharacterPlacement**, depending on the needs of your application. |
| **GCP_DISPLAYZWG** | For languages that need reordering or different glyph shapes depending on the positions of the characters within a word, nondisplayable characters often appear in the code page. For example, in the Hebrew code page, there are Left-To-Right and Right-To-Left markers, to help determine the final positioning of characters within the output strings. Normally these are not displayed and are removed from the *lpGlyphs* and *lpDx* arrays. You can use the GCP_DISPLAYZWG flag to display these characters. |
| **GCP_GLYPHSHAPE** | Specifies that some or all characters in the string are to be displayed using shapes other than the standard shapes defined in the currently selected font for the current code page. Some languages, such as Arabic, cannot support glyph creation unless this value is specified. As a general rule, if [GetFontLanguageInfo](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getfontlanguageinfo) returns this value for a string, this value must be used with **GetCharacterPlacement**. |
| **GCP_JUSTIFY** | Adjusts the extents in the *lpDx* array so that the string length is the same as *nMaxExtent*. GCP_JUSTIFY may only be used in conjunction with GCP_MAXEXTENT. |
| **GCP_KASHIDA** | Use Kashidas as well as, or instead of, adjusted extents to modify the length of the string so that it is equal to the value specified by *nMaxExtent*. In the *lpDx* array, a Kashida is indicated by a negative justification index. GCP_KASHIDA may be used only in conjunction with GCP_JUSTIFY and only if the font (and language) support Kashidas. Use [GetFontLanguageInfo](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getfontlanguageinfo) to determine whether the current font supports Kashidas.<br><br>Using Kashidas to justify the string can result in the number of glyphs required being greater than the number of characters in the input string. Because of this, when Kashidas are used, the application cannot assume that setting the arrays to be the size of the input string will be sufficient. (The maximum possible will be approximately dxPageWidth/dxAveCharWidth, where dxPageWidth is the width of the document and dxAveCharWidth is the average character width as returned from a [GetTextMetrics](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-gettextmetrics) call).<br><br>Note that just because [GetFontLanguageInfo](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getfontlanguageinfo) returns the GCP_KASHIDA flag does not mean that it has to be used in the call to **GetCharacterPlacement**, just that the option is available. |
| **GCP_LIGATE** | Use ligations wherever characters ligate. A ligation occurs where one glyph is used for two or more characters. For example, the letters a and e can ligate to ?. For this to be used, however, both the language support and the font must support the required glyphs (the example will not be processed by default in English).<br><br>Use [GetFontLanguageInfo](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getfontlanguageinfo) to determine whether the current font supports ligation. If it does and a specific maximum is required for the number of characters that will ligate, set the number in the first element of the **lpGlyphs** array. If normal ligation is required, set this value to zero. If GCP_LIGATE is not specified, no ligation will take place. See GCP_RESULTS for more information.<br><br>If the GCP_REORDER value is usually required for the character set but is not specified, the output will be meaningless unless the string being passed in is already in visual ordering (that is, the result that gets put into lpGcpResults->lpOutString in one call to **GetCharacterPlacement** is the input string of a second call).<br><br>Note that just because [GetFontLanguageInfo](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getfontlanguageinfo) returns the GCP_LIGATE flag does not mean that it has to be used in the call to **GetCharacterPlacement**, just that the option is available. |
| **GCP_MAXEXTENT** | Compute extents of the string only as long as the resulting extent, in logical units, does not exceed the values specified by the *nMaxExtent* parameter. |
| **GCP_NEUTRALOVERRIDE** | Certain languages only. Override the normal handling of neutrals and treat them as strong characters that match the strings reading order. Useful only with the GCP_REORDER flag. |
| **GCP_NUMERICOVERRIDE** | Certain languages only. Override the normal handling of numerics and treat them as strong characters that match the strings reading order. Useful only with the GCP_REORDER flag. |
| **GCP_NUMERICSLATIN** | Arabic/Thai only. Use standard Latin glyphs for numbers and override the system default. To determine if this option is available in the language of the font, use [GetStringTypeEx](https://learn.microsoft.com/previous-versions/ms960831(v%3dmsdn.10)) to see if the language supports more than one number format. |
| **GCP_NUMERICSLOCAL** | Arabic/Thai only. Use local glyphs for numeric characters and override the system default. To determine if this option is available in the language of the font, use [GetStringTypeEx](https://learn.microsoft.com/previous-versions/ms960831(v%3dmsdn.10)) to see if the language supports more than one number format. |
| **GCP_REORDER** | Reorder the string. Use for languages that are not SBCS and left-to-right reading order. If this value is not specified, the string is assumed to be in display order already.<br><br>If this flag is set for Semitic languages and the **lpClass** array is used, the first two elements of the array are used to specify the reading order beyond the bounds of the string. GCP_CLASS_PREBOUNDRTL and GCP_CLASS_PREBOUNDLTR can be used to set the order. If no preset order is required, set the values to zero. These values can be combined with other values if the GCPCLASSIN flag is set.<br><br>If the GCP_REORDER value is not specified, the *lpString* parameter is taken to be visual ordered for languages where this is used, and the *lpOutString* and *lpOrder* fields are ignored.<br><br>Use [GetFontLanguageInfo](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getfontlanguageinfo) to determine whether the current font supports reordering. |
| **GCP_SYMSWAPOFF** | Semitic languages only. Specifies that swappable characters are not reset. For example, in a right-to-left string, the '(' and ')' are not reversed. |
| **GCP_USEKERNING** | Use kerning pairs in the font (if any) when creating the widths arrays. Use [GetFontLanguageInfo](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getfontlanguageinfo) to determine whether the current font supports kerning pairs.<br><br>Note that just because [GetFontLanguageInfo](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getfontlanguageinfo) returns the GCP_USEKERNING flag does not mean that it has to be used in the call to **GetCharacterPlacement**, just that the option is available. Most TrueType fonts have a kerning table, but you do not have to use it. |

It is recommended that an application use the [GetFontLanguageInfo](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getfontlanguageinfo) function to determine whether the GCP_DIACRITIC, GCP_DBCS, GCP_USEKERNING, GCP_LIGATE, GCP_REORDER, GCP_GLYPHSHAPE, and GCP_KASHIDA values are valid for the currently selected font. If not valid, **GetCharacterPlacement** ignores the value.

The GCP_NODIACRITICS value is no longer defined and should not be used.

## Return value

If the function succeeds, the return value is the width and height of the string in logical units. The width is the low-order word and the height is the high-order word.

If the function fails, the return value is zero.

## Remarks

**GetCharacterPlacement** ensures that an application can correctly process text regardless of the international setting and type of fonts available. Applications use this function before using the [ExtTextOut](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-exttextouta) function and in place of the [GetTextExtentPoint32](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-gettextextentpoint32a) function (and occasionally in place of the [GetCharWidth32](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getcharwidth32a) and [GetCharABCWidths](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getcharabcwidthsa) functions).

Using **GetCharacterPlacement** to retrieve intercharacter spacing and index arrays is not always necessary unless justification or kerning is required. For non-Latin fonts, applications can improve the speed at which the [ExtTextOut](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-exttextouta) function renders text by using **GetCharacterPlacement** to retrieve the intercharacter spacing and index arrays before calling **ExtTextOut**. This is especially useful when rendering the same text repeatedly or when using intercharacter spacing to position the caret. If the **lpGlyphs** output array is used in the call to **ExtTextOut**, the ETO_GLYPH_INDEX flag must be set.

**GetCharacterPlacement** checks the **lpOrder**, **lpDX**, **lpCaretPos**, **lpOutString**, and **lpGlyphs** members of the [GCP_RESULTS](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-gcp_resultsa) structure and fills the corresponding arrays if these members are not set to **NULL**. If **GetCharacterPlacement** cannot fill an array, it sets the corresponding member to **NULL**. To ensure retrieval of valid information, the application is responsible for setting the member to a valid address before calling the function and for checking the value of the member after the call. If the GCP_JUSTIFY or GCP_USEKERNING values are specified, the **lpDX** and/or **lpCaretPos** members must have valid addresses.

Note that the glyph indexes returned in GCP_RESULTS.lpGlyphs are specific to the current font in the device context and should only be used to draw text in the device context while that font remains selected.

When computing justification, if the trailing characters in the string are spaces, the function reduces the length of the string and removes the spaces prior to computing the justification. If the array consists of only spaces, the function returns an error.

[ExtTextOut](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-exttextouta) expects an **lpDX** entry for each byte of a DBCS string, whereas **GetCharacterPlacement** assigns an **lpDX** entry for each glyph. To correct this mismatch when using this combination of functions, either use [GetGlyphIndices](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getglyphindicesa) or expand the **lpDX** array with zero-width entries for the corresponding second byte of a DBCS byte pair.

If the logical width is less than the width of the leading character in the input string, GCP_RESULTS.nMaxFit returns a bad value. For this case, call **GetCharacterPlacement** for glyph indexes and the **lpDX** array. Then use the **lpDX** array to do the extent calculation using the advance width of each character, where **nMaxFit** is the number of characters whose glyph indexes advance width is less than the width of the leading character.

> [!NOTE]
> The wingdi.h header defines GetCharacterPlacement as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[ExtTextOut](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-exttextouta)

[Font and Text Functions](https://learn.microsoft.com/windows/desktop/gdi/font-and-text-functions)

[Fonts and Text Overview](https://learn.microsoft.com/windows/desktop/gdi/fonts-and-text)

[GCP_RESULTS](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-gcp_resultsa)

[GetCharABCWidths](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getcharabcwidthsa)

[GetCharWidth32](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getcharwidth32a)

[GetFontLanguageInfo](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getfontlanguageinfo)

[GetStringTypeEx](https://learn.microsoft.com/previous-versions/ms960831(v%3dmsdn.10))

[GetTextExtentPoint32](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-gettextextentpoint32a)

[GetTextMetrics](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-gettextmetrics)