# MFCreateMuxStreamAttributes function

## Description

Creates an [IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes) describing the content of multiplexed substreams.

## Parameters

### `pAttributesToMux` [in]

The collection containing the [IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes) for each multiplexed substream.

### `ppMuxAttribs` [out]

The [IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes) containing the attributes for the multiplexed substreams.

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | The *pAttributesToMux* parameter in null. |