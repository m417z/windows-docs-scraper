# IMILBitmapEffectImpl::IsInPlaceModificationAllowed

## Description

Determines whether the effect allows in-place modifications.

## Parameters

### `pOutputConnector` [in]

Type: **[IMILBitmapEffectOutputConnector](https://learn.microsoft.com/previous-versions/windows/desktop/api/mileffects/nn-mileffects-imilbitmapeffectoutputconnector)***

The output connect to check if in-place modifications are allowed.

### `pfModifyInPlace` [out]

Type: **VARIANT_BOOL***

A pointer that receives `TRUE` if in-place modifications are allowed; otherwise, `FALSE`.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.