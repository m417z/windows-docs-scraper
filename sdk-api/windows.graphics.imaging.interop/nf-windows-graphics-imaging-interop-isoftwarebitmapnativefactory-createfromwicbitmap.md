# ISoftwareBitmapNativeFactory::CreateFromWICBitmap (windows.graphics.imaging.interop.h)

## Description

Creates a Windows Runtime [SoftwareBitmap](https://learn.microsoft.com/uwp/api/windows.graphics.imaging.softwarebitmap) object from the provided [IWICBitmap](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmap).

## Parameters

### `data` [in]

Type: **IWICBitmap***

The source WIC bitmap.

### `forceReadOnly` [in]

Type: **BOOL**

A value indicating whether the created software bitmap is read-only.

**Note** The read-only access applies only to the Windows Runtime [SoftwareBitmap](https://learn.microsoft.com/uwp/api/windows.graphics.imaging.softwarebitmap) object. Access to the underlying WIC bitmap is not restricted.

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