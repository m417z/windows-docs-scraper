# ITextPara2::SetFontAlignment

## Description

Sets the paragraph font alignment for Chinese, Japanese, Korean text.

## Parameters

### `Value` [in]

Type: **long**

The paragraph font alignment. It can be one of the following values.

| Font Alignment States |
| --- |
| [tomFontAlignmentAuto](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants) (default) |
| [tomFontAlignmentTop](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants) |
| [tomFontAlignmentBaseline](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants) |
| [tomFontAlignmentBottom](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants) |
| [tomFontAlignmentCenter](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants) |

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITextPara2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextpara2)

[ITextPara2::GetFontAlignment](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara2-getfontalignment)