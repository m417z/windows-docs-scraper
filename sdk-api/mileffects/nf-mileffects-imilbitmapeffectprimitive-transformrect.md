# IMILBitmapEffectPrimitive::TransformRect

## Description

Transforms the output of the given rectangle.

## Parameters

### `uiIndex` [in]

Type: **ULONG**

A zero based index value indicating the output pin through which to transform the rectangle.

### `p` [in, out]

Type: **[MIL_RECTD](https://learn.microsoft.com/previous-versions/windows/desktop/api/mileffects/ns-mileffects-milrectd)***

A pointer to the rectangle to transform.

### `fForwardTransform` [in]

Type: **VARIANT_BOOL**

A value indicating whether the rectangle is being transformed from front to back in the effects graph.

### `pContext` [in]

Type: **[IMILBitmapEffectRenderContext](https://learn.microsoft.com/previous-versions/windows/desktop/api/mileffects/nn-mileffects-imilbitmapeffectrendercontext)***

The render context to use for the transformation.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.