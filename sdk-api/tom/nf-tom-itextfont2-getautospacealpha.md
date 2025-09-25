# ITextFont2::GetAutospaceAlpha

## Description

Gets the East Asian "autospace alphabetics" state.

## Parameters

### `pValue` [out, retval]

Type: **long***

A [tomBool](https://learn.microsoft.com/windows/desktop/Controls/about-text-object-model) value that can be one of the following.

| Value | Meaning |
| --- | --- |
| **tomTrue** | Use East Asian autospace alphabetics. |
| **tomFalse** | Do not use East Asian autospace alphabetics. |
| **tomUndefined** | The AutospaceAlpha property is undefined. |

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITextFont2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextfont2)

[ITextFont2::SetAutospaceAlpha](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextfont2-setautospacealpha)