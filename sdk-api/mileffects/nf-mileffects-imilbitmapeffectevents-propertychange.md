# IMILBitmapEffectEvents::PropertyChange

## Description

Notifies an [IMILBitmapEffectPrimitive](https://learn.microsoft.com/previous-versions/windows/desktop/api/mileffects/nn-mileffects-imilbitmapeffectprimitive) of a property change.

## Parameters

### `pEffect` [in]

Type: **[IMILBitmapEffect](https://learn.microsoft.com/previous-versions/windows/desktop/api/mileffects/nn-mileffects-imilbitmapeffect)***

The effect primitive to notify.

### `bstrPropertyName` [in]

Type: **BSTR**

The property that has changed.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.