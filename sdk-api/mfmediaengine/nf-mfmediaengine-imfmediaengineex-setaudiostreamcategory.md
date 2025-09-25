# IMFMediaEngineEx::SetAudioStreamCategory

## Description

Sets the audio stream category for the next call to [SetSource](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imfmediaengine-setsource) or [Load](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imfmediaengine-load).

## Parameters

### `category` [in]

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

For information on audio stream categories, see [AUDIO_STREAM_CATEGORY enumeration](https://learn.microsoft.com/windows/desktop/api/audiosessiontypes/ne-audiosessiontypes-audio_stream_category).

## See also

[IMFMediaEngineEx](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfmediaengineex)