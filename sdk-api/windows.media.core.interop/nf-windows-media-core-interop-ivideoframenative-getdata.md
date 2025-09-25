# IVideoFrameNative::core

## Description

This method returns an interface that provides access to the video data.

## Parameters

### `riid` [in]

The IID of the interface to retrieve.

### `ppv` [out]

When this method returns successfully, contains the interface pointer requested in *riid* parameter.

## Return value

Returns S_OK on successful completion. Returns E_NOINTERFACE if the requested interface can't be found.

## See also

[IVideoFrameNative](https://learn.microsoft.com/windows/desktop/api/windows.media.core.interop/nn-windows-media-core-interop-ivideoframenative)