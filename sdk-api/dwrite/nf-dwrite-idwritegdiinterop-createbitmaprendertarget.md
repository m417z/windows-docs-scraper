# IDWriteGdiInterop::CreateBitmapRenderTarget

## Description

 Creates an object that encapsulates a bitmap and memory DC (device context) which can be used for rendering glyphs.

## Parameters

### `hdc` [in, optional]

Type: **HDC**

A handle to the optional device context used to create a compatible memory DC (device context).

### `width`

Type: **UINT32**

The width of the bitmap render target.

### `height`

Type: **UINT32**

The height of the bitmap render target.

### `renderTarget` [out]

Type: **[IDWriteBitmapRenderTarget](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritebitmaprendertarget)****

When this method returns, contains an address of a pointer to the newly created [IDWriteBitmapRenderTarget](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritebitmaprendertarget) object.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteGdiInterop](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritegdiinterop)