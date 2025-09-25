# ITextFont2::SetModWidthPairs

## Description

Sets whether "decrease widths on pairs" is active.

## Parameters

### `Value` [in]

Type: **long**

A [tomBool](https://learn.microsoft.com/windows/desktop/Controls/about-text-object-model) value that can be one of the following.

| Value | Meaning |
| --- | --- |
| **tomTrue** | Decrease widths on pairs is active. |
| **tomFalse** | Decrease widths on pairs is not active. |
| **tomToggle** | Toggle the ModWidthPairs property. |
| **tomUndefined** | The ModWidthPairs property is undefined. |

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITextFont2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextfont2)

[ITextFont2::GetModWidthPairs](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextfont2-getmodwidthpairs)