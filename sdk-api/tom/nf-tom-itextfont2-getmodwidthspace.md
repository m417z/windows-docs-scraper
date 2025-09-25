# ITextFont2::GetModWidthSpace

## Description

Gets whether "increase width of whitespace" is active.

## Parameters

### `pValue` [out, retval]

Type: **long***

A [tomBool](https://learn.microsoft.com/windows/desktop/Controls/about-text-object-model) value that can be one of the following.

| Value | Meaning |
| --- | --- |
| **tomTrue** | Increase width of whitespace is active. |
| **tomFalse** | Increase width of whitespace is not active. |
| **tomUndefined** | The ModWidthSpace property is undefined. |

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITextFont2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextfont2)

[ITextFont2::SetModWidthSpace](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextfont2-setmodwidthspace)