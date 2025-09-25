# IMFMediaEngineEx::GetAudioStreamCategory

## Description

Gets the audio stream category used for the next call to [SetSource](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imfmediaengine-setsource) or [Load](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imfmediaengine-load).

## Parameters

### `pCategory` [out]

Receives the audio stream category.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

For information on audio stream categories, see [AUDIO_STREAM_CATEGORY enumeration](https://learn.microsoft.com/windows/desktop/api/audiosessiontypes/ne-audiosessiontypes-audio_stream_category).

## See also

[IMFMediaEngineEx](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfmediaengineex)