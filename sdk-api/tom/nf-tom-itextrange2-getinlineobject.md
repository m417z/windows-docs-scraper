# ITextRange2::GetInlineObject

## Description

Gets the properties of the inline object at the range active end.

## Parameters

### `pType` [out]

Type: **long***

The inline object type can be one of the following:

#### tomSimpleText

#### tomRuby

#### tomHorzVert

#### tomWarichu

#### tomAccent

#### tomBox

#### tomBoxedFormula

#### tomBrackets

#### tomBracketsWithSeps

#### tomEquationArray

#### tomFraction

#### tomFunctionApply

#### tomLeftSubSup

#### tomLowerLimit

#### tomMatrix

#### tomNary

#### tomOpChar

#### tomOverbar

#### tomPhantom

#### tomRadical

#### tomSlashedFraction

#### tomStack

#### tomStretchStack

#### tomSubscript

#### tomSubSup

#### tomSuperscript

#### tomUnderbar

#### tomUpperLimit

### `pAlign` [out]

Type: **long***

The inline object alignment, which can be one of these meanings depending on the inline object type:

| Inline object type | Meaning of Align Parameter |
| --- | --- |
| [tomRuby](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-objecttype) | [tomRubyBelow](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)<br><br>[tomRubyAlignCenter](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants) (default)<br><br>[tomRubyAlign010](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)<br><br>[tomRubyAlign121](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)<br><br>[tomRubyAlignLeft](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)<br><br>[tomRubyAlignRight](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants) |
| [tomBox](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-objecttype) | [tomBoxAlignCenter](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)<br><br>[tomSpaceMask](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)<br><br>[tomSpaceDefault](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)<br><br>[tomSpaceUnary](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)<br><br>[tomSpaceBinary](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)<br><br>[tomSpaceRelational](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)<br><br>[tomSpaceSkip](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)<br><br>[tomSpaceOrd](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)<br><br>[tomSpaceDifferential](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)<br><br>[tomSizeText](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)<br><br>[tomSizeScript](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)<br><br>[tomSizeScriptScript](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)<br><br>[tomNoBreak](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)<br><br>[tomTransparentForPositioning](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)<br><br>[tomTransparentForSpacing](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants) |
| [tomBoxedFormula](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-objecttype) | [tomBoxHideTop](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)<br><br>[tomBoxHideBottom](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)<br><br>[tomBoxHideLeft](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)<br><br>[tomBoxHideRight](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)<br><br>[tomBoxStrikeH](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)<br><br>[tomBoxStrikeV](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)<br><br>[tomBoxStrikeTLBR](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)<br><br>[tomBoxStrikeBLTR](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants) |
| [tomBrackets](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-objecttype) | [tomAlignDefault](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)<br><br>[tomAlignCenter](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)<br><br>[tomAlignMatchAscentDescent](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)<br><br>[tomMathVariant](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants) |
| [tomEquationArray](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-objecttype) | [tomEqArrayLayoutWidth](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)<br><br>[tomEqArrayAlignMask](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)<br><br>[tomEqArrayAlignCenter](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)<br><br>[tomEqArrayAlignTopRow](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)<br><br>[tomEqArrayAlignBottomRow](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants) |
| [tomMatrix](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-objecttype) | [tomMatrixAlignMask](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)<br><br>[tomMatrixAlignCenter](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)<br><br>[tomMatrixAlignTopRow](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)<br><br>[tomMatrixAlignBottomRow](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)<br><br>[tomShowMatPlaceHldr](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants) |
| [tomNary](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-objecttype) | [tomLimitsDefault](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)<br><br>[tomLimitsUnderOver](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)<br><br>[tomLimitsSubSup](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)<br><br>[tomUpperLimitAsSuperScript](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)<br><br>[tomLimitsOpposite](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)<br><br>[tomShowLLimPlaceHldr](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)<br><br>[tomShowULimPlaceHldr](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)<br><br>[tomDontGrowWithContent](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)<br><br>[tomGrowWithContent](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants) |
| [tomPhantom](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-objecttype) | [tomPhantomShow](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)<br><br>[tomPhantomZeroWidth](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)<br><br>[tomPhantomZeroAscent](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)<br><br>[tomPhantomZeroDescent](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)<br><br>[tomPhantomTransparent](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants) |
| [tomRadical](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-objecttype) | [tomShowDegPlaceHldr](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants) |
| [tomSubSup](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-objecttype) | [tomSubSupAlign](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants) |
| [tomStretchStack](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-objecttype) | [tomStretchCharBelow](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)<br><br>[tomStretchCharAbove](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)<br><br>[tomStretchBaseBelow](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)<br><br>[tomStretchBaseAbove](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants) |

### `pChar` [out]

Type: **long***

The inline object character.

The value for each object type is shown in the following table..

| Inline object type | Meaning of align parameter |
| --- | --- |
| [tomAccent](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-objecttype) | Accent (U+0300—U+36F, U+20D0—U+20EF) |
| [tomBoxedFormula](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-objecttype) | U+25AD for rectangle enclosure |
| [tomBrackets](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-objecttype) | Opening bracket. Default: U+0028. |
| [tomBracketsWithSeps](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-objecttype) | Opening bracket with separators. Default: U+0028 |
| [tomEquationArray](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-objecttype) | U+2588 |
| [tomFraction](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-objecttype) | Normal built-up fraction: U+002F; small numeric fraction: U+2298 |
| [tomFunctionApply](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-objecttype) | U+2061 |
| [tomLeftSubSup](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-objecttype) | U+005E |
| [tomLowerLimit](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-objecttype) | U+252C |
| [tomMatrix](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-objecttype) | U+25A0: no enclosing brackets<br><br>U+24A8: enclosing parentheses (\pmatrix)<br><br>U+24B1: enclosing vertical bars (\vmatrix)<br><br>U+24A9: enclosing double vertical bars (\Vmatrix) |
| [tomNary](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-objecttype) | n-ary symbol |
| [tomOpChar](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-objecttype) | Internal use for no-build operators |
| [tomOverbar](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-objecttype) | U+00AF |
| [tomPhantom](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-objecttype) | U+27E1: full or custom phantom<br><br>U+2B04: horizontal phantom<br><br>U+21F3: vertical phantom<br><br>U+2B06: ascent smash<br><br>U+2B07: descent smash<br><br>U+2B0C: horizontal smash<br><br>U+2B0D: full smash |
| [tomRadical](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-objecttype) | U+221A: square or nth root<br><br>U+221B: cube root<br><br>U+221C: fourth root |
| [tomSlashedFraction](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-objecttype) | U+2044: skewed fraction<br><br>U+2215: built-up linear fraction |
| [tomStack](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-objecttype) | U+00A6 |
| [tomStretchStack](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-objecttype) | Horizontal stretch character (see [Unicode Technical Note 28](https://www.unicode.org/notes/tn28/) Appendix B for a list) |
| [tomSubscript](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-objecttype) | U+005E |
| [tomSubSup](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-objecttype) | U+005E |
| [tomSuperscript](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-objecttype) | U+005F |
| [tomUnderbar](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-objecttype) | U+2581 |
| [tomUpperLimit](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-objecttype) | U+2534 |

### `pChar1` [out]

Type: **long***

The closing **tomBrackets** character. See [Unicode Technical Note 28](https://www.unicode.org/notes/tn28/) Appendix B. Character Keywords and Properties for a list.

### `pChar2` [out]

Type: **long***

The separator character for **tomBracketsWithSep**:

#### U+007C: vertical bar with no extra spacing

#### U+2223: vertical bar with extra spacing

### `pCount` [out]

Type: **long***

The inline object count of arguments.

### `pTeXStyle` [out]

Type: **long***

The inline object TeX style, which can be one of the following values.

**Note** The **tomStyleDefault** behavior depends on the context.

#### tomStyleDefault

#### tomStyleScriptScriptCramped

#### tomStyleScriptScript

#### tomStyleScriptCramped

#### tomStyleScript

#### tomStyleTextCramped

#### tomStyleText

#### tomStyleDisplayCramped

#### tomStyleDisplay

### `pcCol` [out]

Type: **long***

The inline object count of columns (**tomMatrix** only).

### `pLevel` [out]

Type: **long***

The inline object 0-based nesting level.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## Remarks

[Unicode Technical Note 28](https://www.unicode.org/notes/tn28/) describes the alignment and character values in detail when the active end character is an inline object start delimiter.

When that character is not a start delimiter, the character and column parameters are set to 0, the count is set to the 0-based argument index, and the other parameters are set according to the active-end character properties of the innermost inline object argument.

## See also

[ITextRange2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange2)

[ITextRange2::SetInlineObject](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange2-setinlineobject)