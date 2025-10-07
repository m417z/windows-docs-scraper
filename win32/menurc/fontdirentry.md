# FONTDIRENTRY structure

Contains information about an individual font in a font resource group. The structure definition provided here is for explanation only; it is not present in any standard header file.

## Members

**dfVersion**

Type: **WORD**

A user-defined version number for the resource data that tools can use to read and write resource files.

**dfSize**

Type: **DWORD**

The size of the file, in bytes.

**dfCopyright\[60\]**

Type: **CHAR**

The font supplier's copyright information.

**dfType**

Type: **WORD**

The type of font file.

**dfPoints**

Type: **WORD**

The point size at which this character set looks best.

**dfVertRes**

Type: **WORD**

The vertical resolution, in dots per inch, at which this character set was digitized.

**dfHorizRes**

Type: **WORD**

The horizontal resolution, in dots per inch, at which this character set was digitized.

**dfAscent**

Type: **WORD**

The distance from the top of a character definition cell to the baseline of the typographical font.

**dfInternalLeading**

Type: **WORD**

The amount of leading inside the bounds set by the **dfPixHeight** member. Accent marks and other diacritical characters can occur in this area.

**dfExternalLeading**

Type: **WORD**

The amount of extra leading that the application adds between rows.

**dfItalic**

Type: **BYTE**

An italic font if not equal to zero.

**dfUnderline**

Type: **BYTE**

An underlined font if not equal to zero.

**dfStrikeOut**

Type: **BYTE**

A strikeout font if not equal to zero.

**dfWeight**

Type: **WORD**

The weight of the font in the range 0 through 1000. For example, 400 is roman and 700 is bold. If this value is zero, a default weight is used. For additional defined values, see the description of the [**LOGFONT**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-logfonta) structure.

**dfCharSet**

Type: **BYTE**

The character set of the font. For predefined values, see the description of the [**LOGFONT**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-logfonta) structure.

**dfPixWidth**

Type: **WORD**

The width of the grid on which a vector font was digitized. For raster fonts, if the member is not equal to zero, it represents the width for all the characters in the bitmap. If the member is equal to zero, the font has variable-width characters.

**dfPixHeight**

Type: **WORD**

The height of the character bitmap for raster fonts or the height of the grid on which a vector font was digitized.

**dfPitchAndFamily**

Type: **BYTE**

The pitch and the family of the font. For additional information, see the description of the [**LOGFONT**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-logfonta) structure.

**dfAvgWidth**

Type: **WORD**

The average width of characters in the font (generally defined as the width of the letter x). This value does not include the overhang required for bold or italic characters.

**dfMaxWidth**

Type: **WORD**

The width of the widest character in the font.

**dfFirstChar**

Type: **BYTE**

The first character code defined in the font.

**dfLastChar**

Type: **BYTE**

The last character code defined in the font.

**dfDefaultChar**

Type: **BYTE**

The character to substitute for characters not in the font.

**dfBreakChar**

Type: **BYTE**

The character that will be used to define word breaks for text justification.

**dfWidthBytes**

Type: **WORD**

The number of bytes in each row of the bitmap. This value is always even so that the rows start on word boundaries. For vector fonts, this member has no meaning.

**dfDevice**

Type: **DWORD**

The offset in the file to a null-terminated string that specifies a device name. For a generic font, this value is zero.

**dfFace**

Type: **DWORD**

The offset in the file to a null-terminated string that names the typeface.

**dfReserved**

Type: **DWORD**

This member is reserved.

**szDeviceName**

Type: **CHAR**

The name of the device if this font file is designated for a specific device.

**szFaceName**

Type: **CHAR**

The typeface name of the font.

## Remarks

There is one **FONTDIRENTRY** structure for every font in the .res file. Applications that generate .res files with font resources must also add to the file a **FONTDIRENTRY** structure for each font.

Font declarations can be mixed with other resource declarations in the .RC file because fonts do not need to be contiguous in the .res file.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |

## See also

**Reference**

[**DIRENTRY**](https://learn.microsoft.com/windows/win32/menurc/direntry)

[**FONTGROUPHDR**](https://learn.microsoft.com/windows/win32/menurc/fontgrouphdr)

**Conceptual**

[Resources](https://learn.microsoft.com/windows/win32/menurc/resources)

**Other Resources**

[**LOGFONT**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-logfonta)

