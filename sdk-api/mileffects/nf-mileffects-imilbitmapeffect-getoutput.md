# IMILBitmapEffect::GetOutput

## Description

Gets the output of the effect.

## Parameters

### `uiIndex` [in]

Type: **ULONG**

The output index.

### `pContext` [in]

Type: **[IMILBitmapEffectRenderContext](https://learn.microsoft.com/previous-versions/windows/desktop/api/mileffects/nn-mileffects-imilbitmapeffectrendercontext)***

A pointer to the render context of the effect.

### `ppBitmapSource` [out, retval]

Type: **IWICBitmapSource****

A pointer that receives a pointer to the effect's output.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.