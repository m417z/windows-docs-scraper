# IMFMediaEngineEx::GetStreamSelection

## Description

Queries whether a stream is selected to play.

## Parameters

### `dwStreamIndex` [in]

The zero-based index of the stream. To get the number of streams, call [IMFMediaEngineEx::GetNumberOfStreams](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imfmediaengineex-getnumberofstreams).

### `pEnabled` [out]

Receives a Boolean value.

| Value | Meaning |
| --- | --- |
| **TRUE** | The stream is selected. During playback, this stream will play. |
| **FALSE** | The stream is not selected. During playback, this stream will not play. |

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFMediaEngineEx](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfmediaengineex)