# IMFMediaEngineEx::SetStreamSelection

## Description

Selects or deselects a stream for playback.

## Parameters

### `dwStreamIndex` [in]

The zero-based index of the stream. To get the number of streams, call [IMFMediaEngineEx::GetNumberOfStreams](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imfmediaengineex-getnumberofstreams).

### `Enabled` [in]

Specifies whether to select or deselect the stream.

| Value | Meaning |
| --- | --- |
| ****TRUE**** | The stream is selected. During playback, this stream will play. |
| ****FALSE**** | The stream is not selected. During playback, this stream will not play. |

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFMediaEngineEx](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfmediaengineex)