# IMILBitmapEffectPrimitive::TransformPoint

## Description

Transforms the given point.

## Parameters

### `uiIndex` [in]

Type: **ULONG**

A zero based index value indicating the output pin through which to transform the point.

### `p` [in, out]

Type: **[MIL_2DPOINTD](https://learn.microsoft.com/previous-versions/windows/desktop/api/mileffects/ns-mileffects-milpoint2d)***

A pointer to the point to transform.

### `fForwardTransform` [in]

Type: **VARIANT_BOOL**

A value indicating whether the point is being transformed from front to back in the effects graph.

### `pContext` [in]

Type: **[IMILBitmapEffectRenderContext](https://learn.microsoft.com/previous-versions/windows/desktop/api/mileffects/nn-mileffects-imilbitmapeffectrendercontext)***

The render context to use for the transformation.

### `pfPointTransformed` [out]

Type: **VARIANT_BOOL***

When this method returns, contains a value indicating whether the point transformed to a known location.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.