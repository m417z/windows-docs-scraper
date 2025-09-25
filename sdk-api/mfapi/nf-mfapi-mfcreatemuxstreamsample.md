# MFCreateMuxStreamSample function

## Description

Creates an [IMFSample](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfsample) containing the samples of multiplexed substreams.

## Parameters

### `pSamplesToMux` [in]

The collection containing the [IMFSample](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfsample) for each multiplexed substream.

### `ppMuxSample` [out]

The [IMFSample](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfsample) containing the samples for the multiplexed substreams.

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | The *pSamplesToMux* parameter in null. |