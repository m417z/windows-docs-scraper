# IWICBitmapLock::GetStride

## Description

Provides access to the stride value for the memory.

## Parameters

### `pcbStride` [in, out]

Type: **UINT***

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Note the stride value is specific to the [IWICBitmapLock](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmaplock), not the bitmap.
For example, two consecutive locks on the same rectangle of a bitmap may return different pointers and stride values, depending on internal implementation.