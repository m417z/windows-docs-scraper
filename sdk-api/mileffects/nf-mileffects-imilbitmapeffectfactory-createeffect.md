# IMILBitmapEffectFactory::CreateEffect

## Description

Creates an [IMILBitmapEffect](https://learn.microsoft.com/previous-versions/windows/desktop/api/mileffects/nn-mileffects-imilbitmapeffect) object.

## Parameters

### `pguidEffect` [in]

Type: **const GUID***

A pointer to the GUID of the effect to create.

### `ppEffect` [out]

Type: **[IMILBitmapEffect](https://learn.microsoft.com/previous-versions/windows/desktop/api/mileffects/nn-mileffects-imilbitmapeffect)****

A pointer that receives a pointer to a new [IMILBitmapEffectPrimitive](https://learn.microsoft.com/previous-versions/windows/desktop/api/mileffects/nn-mileffects-imilbitmapeffectprimitive) object.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.