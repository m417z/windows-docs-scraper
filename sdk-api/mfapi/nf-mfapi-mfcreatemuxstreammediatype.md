# MFCreateMuxStreamMediaType function

## Description

Creates an [IMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediatype) describing the media types of multiplexed substreams.

## Parameters

### `pMediaTypesToMux` [in]

The collection containing the [IMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediatype) for each multiplexed substream.

### `ppMuxMediaType` [out]

The [IMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediatype) containing the media types for the multiplexed substreams.

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | The *pMediaTypesToMux* parameter in null. |