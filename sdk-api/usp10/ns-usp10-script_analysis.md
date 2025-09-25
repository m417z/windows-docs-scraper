# SCRIPT_ANALYSIS structure

## Description

Contains a portion of a Unicode string, that is, an "item".

## Members

### `eScript`

Opaque value identifying the engine that Uniscribe uses when calling the [ScriptShape](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptshape), [ScriptPlace](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptplace), and [ScriptTextOut](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scripttextout) functions for the item. The value for this member is undefined and applications should not rely on its value being the same from one release to the next. An application can obtain the attributes of **eScript** by calling [ScriptGetProperties](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptgetproperties).

To disable shaping, the application should set this member to SCRIPT_UNDEFINED.

### `fRTL`

Value indicating rendering direction. Possible values are defined in the following table. This member is set to **TRUE** for a number in a left-to-right run, because digits are always displayed left to right, or **FALSE** for a number in a right-to-left run. The value of this member is normally identical to the parity of the Unicode embedding level, but it might differ if overridden by [GetCharacterPlacement](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getcharacterplacementa) legacy support.

| Value | Meaning |
| --- | --- |
| ****TRUE**** | Use a right-to-left rendering direction. |
| ****FALSE**** | Use a left-to-right rendering direction. |

### `fLayoutRTL`

Value indicating layout direction for a number. Possible values are defined in the following table. This member is usually the same as the value assigned to **fRTL** for a number in a right-to-left run.

| Value | Meaning |
| --- | --- |
| ****TRUE**** | Lay out the number in a right-to-left run, because it is read as part of the right-to-left sequence. |
| ****FALSE**** | Lay out the number in a left-to-right run, because it is read as part of the left-to-right sequence. |

### `fLinkBefore`

Value indicating if the shaping engine shapes the first character of the item as if it joins with a previous character. Possible values are defined in the following table. This member is set by [ScriptItemize](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptitemize). The application can override the value before calling [ScriptShape](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptshape).

| Value | Meaning |
| --- | --- |
| ****TRUE**** | Shape the first character by linking with a previous character. |
| ****FALSE**** | Do not shape the first character by linking with a previous character. |

### `fLinkAfter`

Value indicating if the shaping engine shapes the last character of the item as if it joins with a subsequent character. Possible values are defined in the following table. This member is set by [ScriptItemize](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptitemize). The application can override the value before calling **ScriptItemize**.

| Value | Meaning |
| --- | --- |
| ****TRUE**** | Shape the last character by linking with a subsequent character. |
| ****FALSE**** | Do not shape the last character by linking with a subsequent character. |

### `fLogicalOrder`

Value indicating if the shaping engine generates all glyph-related arrays in logical order. Possible values are defined in the following table. This member is set to **FALSE** by [ScriptItemize](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptitemize). The application can override the value before calling [ScriptShape](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptshape).

| Value | Meaning |
| --- | --- |
| ****TRUE**** | Generate all glyph-related arrays in logical order. |
| ****FALSE**** | Generate all glyph-related arrays in visual order, with the first array entry corresponding to the leftmost glyph. This value is the default. |

### `fNoGlyphIndex`

Value indicating the use of glyphs for the item. Possible values are defined in the following table. The application can set this member to **TRUE** on input to [ScriptShape](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptshape) to disable the use of glyphs for the item. Additionally, **ScriptShape** sets it to **TRUE** for a hardware context containing symbolic, unrecognized, and device fonts.

Disabling the use of glyphs also disables complex script shaping. Setting this member to **TRUE** implements shaping and placing directly by calls to [GetTextExtentExPoint](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-gettextextentexpointa) and [ExtTextOut](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-exttextouta).

| Value | Meaning |
| --- | --- |
| ****TRUE**** | Disable the use of glyphs for the item. This value is used for bitmap, vector, and device fonts. |
| ****FALSE**** | Enable the use of glyphs for the item. This value is the default. |

### `s`

A [SCRIPT_STATE](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_state) structure containing a copy of the Unicode algorithm state.

## Remarks

This structure is filled by [ScriptItemize](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptitemize) or [ScriptItemizeOpenType](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptitemizeopentype), each of which breaks a Unicode string into individually shapeable items. Neither function accesses the **SCRIPT_ANALYSIS** structure directly. Each function handles an array of [SCRIPT_ITEM](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_item) structures, each of which has a member defining a **SCRIPT_ANALYSIS** structure.

Applications that use [ScriptItemizeOpenType](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptitemizeopentype) instead of [ScriptItemize](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptitemize) should also use [ScriptShapeOpenType](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptshapeopentype) and [ScriptPlaceOpenType](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptplaceopentype) instead of [ScriptShape](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptshape) and [ScriptPlace](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptplace). For more information, see [Displaying Text with Uniscribe](https://learn.microsoft.com/windows/desktop/Intl/displaying-text-with-uniscribe).

## See also

[SCRIPT_ITEM](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_item)

[SCRIPT_STATE](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_state)

[ScriptGetProperties](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptgetproperties)

[ScriptItemize](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptitemize)

[ScriptItemizeOpenType](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptitemizeopentype)

[ScriptPlace](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptplace)

[ScriptPlaceOpenType](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptplaceopentype)

[ScriptShape](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptshape)

[ScriptShapeOpenType](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptshapeopentype)

[ScriptTextOut](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scripttextout)

[Uniscribe](https://learn.microsoft.com/windows/desktop/Intl/uniscribe)

[Uniscribe Structures](https://learn.microsoft.com/windows/desktop/Intl/uniscribe-structures)