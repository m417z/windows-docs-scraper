# ITextFont2::GetPositionSubSuper

## Description

Gets the subscript or superscript position relative to the baseline.

## Parameters

### `pValue` [out, retval]

Type: **long***

The subscript or superscript position relative to the baseline.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The subscript or superscript position is relative to the baseline as a percent of the font height.

Subscripts and superscripts in math zones are handled using the [tomSubscript](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-objecttype), [tomSuperscript](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-objecttype), [tomSubSup](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-objecttype), and [tomLeftSubSup](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-objecttype) mathematical objects. See [ITextRange2::GetInlineObject](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange2-getinlineobject).

## See also

[ITextFont2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextfont2)

[ITextFont2::SetPositionSubSuper](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextfont2-setpositionsubsuper)