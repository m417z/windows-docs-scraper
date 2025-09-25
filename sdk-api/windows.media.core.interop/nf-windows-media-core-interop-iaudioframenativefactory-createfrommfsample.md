# IAudioFrameNativeFactory::core

## Description

Creates an [IAudioFrameNative](https://learn.microsoft.com/windows/desktop/api/windows.media.core.interop/nn-windows-media-core-interop-iaudioframenative) from the provided [IMFSample](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfsample).

## Parameters

### `data` [in]

Type: **IMFSample***

The source buffer containing an audio frame.

### `forceReadOnly` [in]

Type: **BOOL**

A value indicating whether the created software audio frame is read-only.

### `riid` [in]

Type: **REFIID**

The IID of the [IAudioFrameNative](https://learn.microsoft.com/windows/desktop/api/windows.media.core.interop/nn-windows-media-core-interop-iaudioframenative) interface.

### `ppv` [out]

Type: **LPVOID***

When this method returns successfully, contains the requested interface.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns S_OK on successful completion.

## See also

[IAudioFrameNativeFactory](https://learn.microsoft.com/windows/desktop/api/windows.media.core.interop/nn-windows-media-core-interop-iaudioframenativefactory)