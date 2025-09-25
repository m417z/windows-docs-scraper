# ITextPara2::SetEffects

## Description

Sets the paragraph format effects.

## Parameters

### `Value` [in]

Type: **long**

The paragraph effects value.

This value can be a combination of the flags defined in the table for [ITextPara2::GetEffects](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara2-geteffects).

### `Mask` [in]

Type: **long**

The desired mask.

This value can be a combination of the flags defined in the table for [ITextPara2::GetEffects](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara2-geteffects).

Only effects with the corresponding mask flag set are modified.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITextPara2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextpara2)

[ITextPara2::GetEffects](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara2-geteffects)