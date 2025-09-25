# ITextFont2::GetUnderlinePositionMode

## Description

Gets the underline position mode.

## Parameters

### `pValue` [out, retval]

Type: **long***

The underline position mode. It can be one of the following values.

[tomUnderlinePositionAuto](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)
[tomUnderlinePositionBelow](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)
[tomUnderlinePositionAbove](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITextFont2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextfont2)

[ITextFont2::SetUnderlinePositionMode](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextfont2-setunderlinepositionmode)