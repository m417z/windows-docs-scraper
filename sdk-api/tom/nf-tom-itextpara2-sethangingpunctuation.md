# ITextPara2::SetHangingPunctuation

## Description

Sets whether to hang
punctuation symbols on the right margin when the paragraph is justified.

## Parameters

### `Value` [in]

Type: **long**

A [tomBool](https://learn.microsoft.com/windows/desktop/Controls/about-text-object-model) value that can be one of the following.

| Value | Meaning |
| --- | --- |
| **tomTrue** | Hang punctuation symbols on the right margin. |
| **tomFalse** | Do not hang punctuation symbols on the right margin. |
| **tomToggle** | Toggle the HangingPunctuation property. |
| **tomUndefined** | The HangingPunctuation property is undefined. |

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITextPara2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextpara2)

[ITextPara2::GetHangingPunctuation](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara2-gethangingpunctuation)