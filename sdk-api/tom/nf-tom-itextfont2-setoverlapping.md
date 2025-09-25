# ITextFont2::SetOverlapping

## Description

Sets whether overlapping text is active.

## Parameters

### `Value` [in]

Type: **long**

A [tomBool](https://learn.microsoft.com/windows/desktop/Controls/about-text-object-model) value that can be one of the following.

| Value | Meaning |
| --- | --- |
| **tomTrue** | Overlapping text is active. |
| **tomFalse** | Overlapping text is not active. |
| **tomToggle** | Toggle the Overlapping property. |
| **tomUndefined** | The Overlapping property is undefined. |

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITextFont2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextfont2)

[ITextFont2::GetOverlapping](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextfont2-getoverlapping)