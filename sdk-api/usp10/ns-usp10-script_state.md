# SCRIPT_STATE structure

## Description

Contains script state information.

## Members

### `uBidiLevel`

Embedding level associated with all characters in the associated run according to the Unicode bidirectional algorithm. When the application passes this structure to [ScriptItemize](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptitemize), this member should be initialized to 0 for a left-to-right base embedding level, or to 1 for a right-to-left base embedding level.

### `fOverrideDirection`

Initial override direction value indicating if the script uses an override level (LRO or RLO code in the string). Possible values are defined in the following table. For an override level, characters are laid out in one direction only, either left to right or right to left. No reordering of digits or strong characters of opposing direction takes place. Note that this value is reset by LRE, RLE, LRO or RLO codes in the string.

| Value | Meaning |
| --- | --- |
| ****TRUE**** | Use an override level that reflects the embedding level. |
| ****FALSE**** | Do not use an override level that reflects the embedding level. |

### `fInhibitSymSwap`

Value indicating if the shaping engine bypasses mirroring of Unicode mirrored glyphs, for example, brackets. Possible values are defined in the following table. This member is set by Unicode character ISS, and cleared by ASS.

| Value | Meaning |
| --- | --- |
| ****TRUE**** | Bypass mirroring of Unicode mirrored glyphs. |
| ****FALSE**** | Do not bypass mirroring of Unicode mirrored glyphs. |

### `fCharShape`

Not implemented. Value indicating if character codes in the Arabic Presentation Forms areas of Unicode should be shaped. Possible values are defined in the following table.

| Value | Meaning |
| --- | --- |
| ****TRUE**** | Shape character codes in the Arabic Presentation Forms areas of Unicode. |
| ****FALSE**** | Do not shape character codes in the Arabic Presentation Forms areas of Unicode. |

### `fDigitSubstitute`

This member provides the same control over digit substitution behavior that might have been obtained in legacy implementations using the now-deprecated Unicode characters U+206E NATIONAL DIGIT SHAPES ("NADS") and U+206F NOMINAL DIGIT SHAPES ("NODS"). Possible values are defined in the following table.

| Value | Meaning |
| --- | --- |
| ****TRUE**** | Character codes U+0030 through U+0039 are substituted by national digits. |
| ****FALSE**** | Character codes U+0030 through U+0039 are not substituted by national digits. |

### `fInhibitLigate`

Value indicating if ligatures are used in the shaping of Arabic or Hebrew characters. Possible values are defined in the following table.

| Value | Meaning |
| --- | --- |
| ****TRUE**** | Do not use ligatures in the shaping of Arabic or Hebrew characters. |
| ****FALSE**** | Use ligatures in the shaping of Arabic or Hebrew characters. |

### `fDisplayZWG`

Value indicating if nondisplayable control characters are shaped as representational glyphs for languages that need reordering or different glyph shapes, depending on the positions of the characters within a word. Possible values are defined in the following table. Typically, the characters are not displayed. They are shaped to the blank glyph and given a width of 0.

| Value | Meaning |
| --- | --- |
| ****TRUE**** | Shape control characters as representational glyphs. |
| ****FALSE**** | Do not shape control characters as representational glyphs. |

### `fArabicNumContext`

Value indicating if prior strong characters are Arabic for the purposes of rule P0, as discussed in the Unicode Standard, version 2.0. Possible values are defined in the following table. This member should normally be set to **TRUE** before itemization of a right-to-left paragraph in an Arabic language, and to **FALSE** otherwise.

| Value | Meaning |
| --- | --- |
| ****TRUE**** | Consider prior strong characters to be Arabic for the purposes of rule P0. |
| ****FALSE**** | Do not consider prior strong characters to be Arabic for the purposes of rule P0. |

### `fGcpClusters`

For [GetCharacterPlacement](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getcharacterplacementa) legacy support only. Value indicating how [ScriptShape](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptshape) should generate the array indicated by *pwLogClust*. Possible values are defined in the following table. This member affects only Arabic and Hebrew items.

| Value | Meaning |
| --- | --- |
| ****TRUE**** | Generate the array the same way as [GetCharacterPlacement](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getcharacterplacementa) does. |
| ****FALSE**** | Do not generate the array the same way as [GetCharacterPlacement](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getcharacterplacementa) does. |

### `fReserved`

Reserved; always initialize to 0.

### `fEngineReserved`

Reserved; always initialize to 0.

## Remarks

This structure is used to initialize the Unicode algorithm state as an input to [ScriptItemize](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptitemize). It is also used as a component of the analysis retrieved by **ScriptItemize**.

## See also

[ScriptItemize](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptitemize)

[ScriptShape](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptshape)

[Uniscribe](https://learn.microsoft.com/windows/desktop/Intl/uniscribe)

[Uniscribe Structures](https://learn.microsoft.com/windows/desktop/Intl/uniscribe-structures)