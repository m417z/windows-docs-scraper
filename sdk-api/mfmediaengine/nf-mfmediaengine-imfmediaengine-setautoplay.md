# IMFMediaEngine::SetAutoPlay

## Description

Specifies whether the Media Engine automatically begins playback.

## Parameters

### `AutoPlay` [in]

If **TRUE**, the Media Engine automatically begins playback after it loads a media source. Otherwise, playback does not begin until the application calls [IMFMediaEngine::Play](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imfmediaengine-play).

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method corresponds to setting the **autoplay** attribute of the **HTMLMediaElement** interface in HTML5.

## See also

[IMFMediaEngine](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfmediaengine)