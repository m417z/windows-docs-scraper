# IDWriteBitmapRenderTarget::GetMemoryDC

## Description

 Gets a handle to the memory device context.

## Return value

Type: **HDC**

Returns a device context handle to the memory device context.

## Remarks

 An application can use the device context to draw using GDI functions. An application can obtain the bitmap handle
(HBITMAP) by calling [GetCurrentObject](https://learn.microsoft.com/windows/win32/api/wingdi/nf-wingdi-getcurrentobject). An application that wants information about the underlying bitmap, including
a pointer to the pixel data, can call [GetObject](https://learn.microsoft.com/windows/win32/api/wingdi/nf-wingdi-getobject) to fill in a [DIBSECTION](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-dibsection) structure. The bitmap is always a 32-bit
top-down DIB.

Note that this method takes no parameters and returns an HDC variable, not an HRESULT.

```cpp
memoryHdc = g_pBitmapRenderTarget->GetMemoryDC();

```

The HDC returned here is still owned by the bitmap render target object and should not be released or deleted by the client.

## See also

[IDWriteBitmapRenderTarget](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritebitmaprendertarget)