# IMFASFStreamConfig::GetStreamType

## Description

Gets the major media type of the stream.

## Parameters

### `pguidStreamType` [out]

Receives the major media type for the stream. For a list of possible values, see [Major Media Types](https://learn.microsoft.com/windows/desktop/medfound/media-type-guids).

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFASFStreamConfig](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfstreamconfig)

[IMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediatype)