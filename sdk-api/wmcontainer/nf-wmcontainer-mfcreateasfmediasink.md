# MFCreateASFMediaSink function

## Description

Creates the ASF media sink.

## Parameters

### `pIByteStream`

Pointer to a byte stream that will be used to write the ASF stream.

### `ppIMediaSink`

Receives a pointer to the [IMFMediaSink](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmediasink) interface. The caller must release the interface.

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The function succeeded. |

## See also

[IMFByteStream](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfbytestream)

[IMFMediaSink](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmediasink)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)