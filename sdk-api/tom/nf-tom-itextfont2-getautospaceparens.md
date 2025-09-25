# ITextFont2::GetAutospaceParens

## Description

Gets the East Asian "autospace parentheses" state.

## Parameters

### `pValue` [out, retval]

Type: **long***

A [tomBool](https://learn.microsoft.com/windows/desktop/Controls/about-text-object-model) value that can be one of the following.

| Value | Meaning |
| --- | --- |
| **tomTrue** | Use East Asian autospace parentheses. |
| **tomFalse** | Do not use East Asian autospace parentheses. |
| **tomUndefined** | The AutospaceParens property is undefined. |

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITextFont2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextfont2)

[ITextFont2::SetAutospaceParens](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextfont2-setautospaceparens)