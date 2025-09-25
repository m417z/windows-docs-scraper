# IMFMediaEngine::SetPreload

## Description

Sets the preload flag.

## Parameters

### `Preload` [in]

An [MF_MEDIA_ENGINE_PRELOAD](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/ne-mfmediaengine-mf_media_engine_preload) value equal to the preload flag.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method corresponds to setting the **preload** attribute of the **HTMLMediaElement** interface in HTML5. The value is a hint to the user-agent whether to preload the media resource.

## See also

[IMFMediaEngine](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfmediaengine)