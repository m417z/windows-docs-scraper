# ITextFont2::GetAutospaceNumeric

## Description

Gets the East Asian "autospace numeric" state.

## Parameters

### `pValue` [out, retval]

Type: **long***

A [tomBool](https://learn.microsoft.com/windows/desktop/Controls/about-text-object-model) value that can be one of the following.

| Value | Meaning |
| --- | --- |
| **tomTrue** | Use East Asian autospace numerics. |
| **tomFalse** | Do not use East Asian autospace numerics. |
| **tomUndefined** | The AutospaceNumeric property is undefined. |

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITextFont2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextfont2)

[ITextFont2::SetAutospaceNumeric](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextfont2-setautospacenumeric)