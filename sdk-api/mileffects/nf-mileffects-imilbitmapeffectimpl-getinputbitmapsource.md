# IMILBitmapEffectImpl::GetInputBitmapSource

## Description

Gets the input bitmap source of the effect of the given render context.

## Parameters

### `uiIndex` [in]

Type: **ULONG**

The index of the of the input bitmap source.

### `pRenderContext` [in]

Type: **[IMILBitmapEffectRenderContext](https://learn.microsoft.com/previous-versions/windows/desktop/api/mileffects/nn-mileffects-imilbitmapeffectrendercontext)***

A pointer to the [IMILBitmapEffectRenderContext](https://learn.microsoft.com/previous-versions/windows/desktop/api/mileffects/nn-mileffects-imilbitmapeffectrendercontext).

### `pfModifyInPlace` [in, out]

Type: **VARIANT_BOOL***

A value that indicates whether to modify in-place.

### `ppBitmapSource` [out, retval]

Type: **IWICBitmapSource****

A pointer that receives a pointer to the input [IWICBitmapSource Interface](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapsource).

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.