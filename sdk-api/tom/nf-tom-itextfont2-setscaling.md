# ITextFont2::SetScaling

## Description

Sets the font horizontal scaling percentage.

## Parameters

### `Value` [in]

Type: **long**

The scaling percentage. Values from 0 through 255 are valid. For example, a value of 200 doubles the widths of characters while retaining the same height. A value of 0 has the same effect as a value of 100; that is, it turns scaling off.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITextFont2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextfont2)

[ITextFont2::GetScaling](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextfont2-getscaling)