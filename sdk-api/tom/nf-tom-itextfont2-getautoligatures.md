# ITextFont2::GetAutoLigatures

## Description

Gets whether support for automatic ligatures is active.

## Parameters

### `pValue` [out, retval]

Type: **long***

A [tomBool](https://learn.microsoft.com/windows/desktop/Controls/about-text-object-model) value that can be one of the following.

| Value | Meaning |
| --- | --- |
| **tomTrue** | Automatic ligature support is active. |
| **tomFalse** | Automatic ligature support is not active. |
| **tomUndefined** | The AutoLigatures property is undefined. |

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITextFont2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextfont2)

[ITextFont2::SetAutoLigatures](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextfont2-setautoligatures)