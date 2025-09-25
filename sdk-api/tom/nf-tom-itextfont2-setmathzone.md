# ITextFont2::SetMathZone

## Description

Sets whether a math zone is active.

## Parameters

### `Value` [in]

Type: **long**

A [tomBool](https://learn.microsoft.com/windows/desktop/Controls/about-text-object-model) value that can be one of the following.

| Value | Meaning |
| --- | --- |
| **tomTrue** | A math zone is active. |
| **tomFalse** | A math zone is not active. |
| **tomToggle** | Toggle the MathZone property. |
| **tomUndefined** | The MathZone property is undefined. |

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITextFont2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextfont2)

[ITextFont2::GetMathZone](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextfont2-getmathzone)