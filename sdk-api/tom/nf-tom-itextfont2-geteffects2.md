# ITextFont2::GetEffects2

## Description

Gets the additional character format effects.

## Parameters

### `pValue` [out]

Type: **long***

A combination of the following character format flags.

#### tomAutoSpaceAlpha

#### tomAutoSpaceNumeric

#### tomAutoSpaceParens

#### tomDoublestrike

#### tomEmbeddedFont

#### tomModWidthPairs

#### tomModWidthSpace

#### tomOverlapping

### `pMask` [out]

Type: **long***

The differences in these flags over the range. Zero values indicate that the properties are the same over the range. For an insertion point, this value is always zero.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITextFont2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextfont2)

[ITextFont2::GetEffects](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextfont2-geteffects)

[ITextFont2::SetEffects2](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextfont2-seteffects2)