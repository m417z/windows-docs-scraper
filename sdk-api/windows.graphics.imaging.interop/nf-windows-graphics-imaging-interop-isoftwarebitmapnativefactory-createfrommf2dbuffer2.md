# ISoftwareBitmapNativeFactory::CreateFromMF2DBuffer2 (windows.graphics.imaging.interop.h)

## Description

Creates a Windows Runtime [SoftwareBitmap](https://learn.microsoft.com/uwp/api/windows.graphics.imaging.softwarebitmap) object from the provided [IMF2DBuffer2](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imf2dbuffer2).

## Parameters

### `data` [in]

Type: **IMF2DBuffer2***

The source buffer containing a two-dimensional surface, such as a video frame.

### `subtype` [in]

Type: **REFGUID**

A GUID specifying the video subtype of the source buffer.

### `width` [in]

Type: **UINT32**

The width of the source surface.

### `height` [in]

Type: **UINT32**

The height of the source surface.

### `forceReadOnly` [in]

Type: **BOOL**

A value indicating whether the created software bitmap is read-only.

**Note** The read-only access applies only to the Windows Runtime [SoftwareBitmap](https://learn.microsoft.com/uwp/api/windows.graphics.imaging.softwarebitmap) object. Access to the underlying Media Foundation buffer is not restricted.

### `minDisplayAperture` [in, optional]

Type: **const MFVideoArea***

The rectangular area within the surface that contains valid image data. Use NULL if the full frame is valid.

### `riid` [in]

Type: **REFIID**

The interface to obtain from the created [SoftwareBitmap](https://learn.microsoft.com/uwp/api/windows.graphics.imaging.softwarebitmap) object.
This is usually Windows.Graphics.Imaging.ISoftwareBitmap.

### `ppv` [out]

Type: **LPVOID***

When this method returns successfully, contains the requested interface.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns S_OK on successful completion.

## See also

[ISoftwareBitmapNativeFactory](https://learn.microsoft.com/windows/desktop/api/windows.graphics.imaging.interop/nn-windows-graphics-imaging-interop-isoftwarebitmapnativefactory)