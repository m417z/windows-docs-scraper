# IVideoFrameNativeFactory::core

## Description

Creates an [IVideoFrameNative](https://learn.microsoft.com/windows/desktop/api/windows.media.core.interop/nn-windows-media-core-interop-ivideoframenative) from the provided [IMFSample](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfsample).

## Parameters

### `data` [in]

Type: **IMFSample***

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

### `minDisplayAperture` [in, optional]

Type: **const MFVideoArea***

The rectangular area within the surface that contains valid image data. Use NULL if the full frame is valid.

### `device` [in, optional]

Type: **IMFDXGIDeviceManager***

Pointer to the device associated with the image data.

### `riid` [in]

Type: **REFIID**

The IID of the [IVideoFrameNative](https://learn.microsoft.com/windows/desktop/api/windows.media.core.interop/nn-windows-media-core-interop-ivideoframenative) interface.

### `ppv` [out]

Type: **LPVOID***

When this method returns successfully, contains the requested interface.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns S_OK on successful completion.

## See also

[IVideoFrameNativeFactory](https://learn.microsoft.com/windows/desktop/api/windows.media.core.interop/nn-windows-media-core-interop-ivideoframenativefactory)