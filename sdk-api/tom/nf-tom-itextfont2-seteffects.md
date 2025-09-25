# ITextFont2::SetEffects

## Description

Sets the character format effects.

## Parameters

### `Value` [in]

Type: **long**

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

### `Mask` [in]

Type: **long**

The desired mask, which can be a combination of the *Value* flags. Only effects with the corresponding mask flag set are modified.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Only effects with the corresponding mask flag set are modified.

## See also

[ITextFont2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextfont2)

[ITextFont2::GetEffects](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextfont2-geteffects)