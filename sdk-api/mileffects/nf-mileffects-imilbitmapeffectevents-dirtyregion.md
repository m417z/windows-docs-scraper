# IMILBitmapEffectEvents::DirtyRegion

## Description

Invalidates the specified region of the given [IMILBitmapEffectPrimitive](https://learn.microsoft.com/previous-versions/windows/desktop/api/mileffects/nn-mileffects-imilbitmapeffectprimitive).

## Parameters

### `pEffect` [in]

Type: **[IMILBitmapEffect](https://learn.microsoft.com/previous-versions/windows/desktop/api/mileffects/nn-mileffects-imilbitmapeffect)***

A pointer to the primitive to dirty.

### `pRect` [in]

Type: **[MIL_RECTD](https://learn.microsoft.com/previous-versions/windows/desktop/api/mileffects/ns-mileffects-milrectd)***

A pointer to the rectangle to dirty.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.