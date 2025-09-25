# IMILBitmapEffectPrimitive::GetOutput

## Description

Performs pixel processing for the bitmap effect.

## Parameters

### `uiIndex` [in]

Type: **ULONG**

A zero based index value indicating which output pin to use for output.

### `pContext` [in]

Type: **[IMILBitmapEffectRenderContext](https://learn.microsoft.com/previous-versions/windows/desktop/api/mileffects/nn-mileffects-imilbitmapeffectrendercontext)***

The render context to use to determine how the effect should be rendered.

### `pfModifyInPlace` [in, out]

Type: **VARIANT_BOOL***

A value that indicates whether the effect should attempt to modify the input image in place.

### `ppBitmapSource` [out, retval]

Type: **IWICBitmapSource****

When this method returns, contains a pointer to the effect output.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If *pfModifyInPlace* is VARIANT_TRUE, the input image may be modified and returned.
If the custom effect does not support in place modifications, set *pfModifyInPlace* to VARIANT_FALSE to indicate a new image was created.