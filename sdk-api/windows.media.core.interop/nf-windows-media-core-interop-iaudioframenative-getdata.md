# IAudioFrameNative::core

## Description

This method returns an interface that provides access to the audio data.

## Parameters

### `riid` [in]

Type: **REFIID**

The IID of the interface to retrieve.

### `ppv` [out]

Type: **LPVOID***

When this method returns successfully, contains the interface pointer requested in *riid* parameter.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns S_OK on successful completion. Returns E_NOINTERFACE if the requested interface can't be found.

## See also

[IAudioFrameNative](https://learn.microsoft.com/windows/desktop/api/windows.media.core.interop/nn-windows-media-core-interop-iaudioframenative)