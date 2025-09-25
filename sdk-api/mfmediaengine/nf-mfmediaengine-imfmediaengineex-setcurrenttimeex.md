# IMFMediaEngineEx::SetCurrentTimeEx

## Description

Seeks to a new playback position using the specified [MF_MEDIA_ENGINE_SEEK_MODE](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/ne-mfmediaengine-mf_media_engine_seek_mode).

## Parameters

### `seekTime` [in]

The new playback position, in seconds.

### `seekMode` [in]

Specifies if the seek is a normal seek or an approximate seek.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFMediaEngineEx](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfmediaengineex)