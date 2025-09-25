# IDCompositionTableTransferEffect::SetRedTableValue(UINT,IDCompositionAnimation)

## Description

Sets a value in the red table.

## Parameters

### `index` [in]

Type: **UINT**

The index of the value to set.

### `animation` [in]

Type: **[IDCompositionAnimation](https://learn.microsoft.com/windows/desktop/api/dcompanimation/nn-dcompanimation-idcompositionanimation)***

An animation that represents how the value changes over time. This parameter must not be NULL.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDCompositionTableTransferEffect](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositiontabletransfereffect)