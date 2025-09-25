# IMFMediaEngineEx::GetTimelineMarkerTimer

## Description

Gets the time of the next timeline marker, if any.

## Parameters

### `pTimeToFire` [out]

Receives the marker time, in seconds. If no marker is set, this parameter receives the value **NaN**.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFMediaEngineEx](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfmediaengineex)