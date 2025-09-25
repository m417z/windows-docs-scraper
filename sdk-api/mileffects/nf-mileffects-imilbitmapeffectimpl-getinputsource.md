# IMILBitmapEffectImpl::GetInputSource

## Description

Retrieves the input [IWICBitmapSource Interface](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapsource).

## Parameters

### `uiIndex` [in]

Type: **ULONG**

The index of the input source.

### `ppBitmapSource` [out, retval]

Type: **IWICBitmapSource****

A pointer that receives a pointer to the input bitmap source.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.