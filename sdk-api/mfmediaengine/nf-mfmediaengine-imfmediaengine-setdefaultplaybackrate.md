# IMFMediaEngine::SetDefaultPlaybackRate

## Description

Sets the default playback rate.

## Parameters

### `Rate` [in]

The default playback rate, as a multiple of normal (1×) playback. A negative value indicates reverse playback.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method corresponds to setting the **defaultPlaybackRate** attribute of the **HTMLMediaElement** interface in HTML5.

## See also

[IMFMediaEngine](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfmediaengine)