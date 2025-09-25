# ITextFont2::GetScaling

## Description

Gets the font horizontal scaling percentage.

## Parameters

### `pValue` [out, retval]

Type: **long***

The scaling percentage.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The font horizontal scaling percentage can range from 200, which doubles the widths of characters, to 0, where no scaling is performed. When the percentage is increased the height does not change.

## See also

[ITextFont2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextfont2)

[ITextFont2::SetScaling](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextfont2-setscaling)