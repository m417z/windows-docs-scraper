# ITextFont2::GetDoubleStrike

## Description

Gets whether characters are displayed with double horizontal lines through the center.

## Parameters

### `pValue` [out, retval]

Type: **long***

A [tomBool](https://learn.microsoft.com/windows/desktop/Controls/about-text-object-model) value that can be one of the following.

| Value | Meaning |
| --- | --- |
| **tomTrue** | Characters are displayed with double horizontal lines. |
| **tomFalse** | Characters are not displayed with double horizontal lines. |
| **tomUndefined** | The DoubleStrike property is undefined. |

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITextFont2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextfont2)

[ITextFont2::SetDoubleStrike](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextfont2-setdoublestrike)