# ITextFont2::GetEffects

## Description

Gets the character format effects.

## Parameters

### `pValue` [out]

Type: **long***

A combination of the following character format values.

#### tomAllCaps

#### tomBold

#### tomDisabled

#### tomEmboss

#### tomHidden

#### tomImprint

#### tomInlineObjectStart

#### tomItalic

#### tomLink

#### tomLinkProtected

#### tomMathZone

#### tomMathZoneDisplay

#### tomMathZoneNoBuildUp

#### tomMathZoneOrdinary

#### tomOutline

#### tomProtected

#### tomRevised

#### tomShadow

#### tomSmallCaps

#### tomStrikeout

#### tomUnderline

If the [tomInlineObjectStart](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants) flag is set, you might want to call [GetInlineObject](https://learn.microsoft.com/windows/desktop/api/dwrite/nf-dwrite-idwritetextlayout-getinlineobject) for more inline object properties.

### `pMask` [out]

Type: **long***

The differences in these flags over the range. A value of zero indicates that the properties are the same over the range. For an insertion point, this value is always zero.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITextFont2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextfont2)

[ITextFont2::SetEffects](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextfont2-seteffects)