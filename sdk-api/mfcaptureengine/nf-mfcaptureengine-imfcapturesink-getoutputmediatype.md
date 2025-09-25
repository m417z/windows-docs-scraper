# IMFCaptureSink::GetOutputMediaType

## Description

Gets the output format for a stream on this capture sink.

## Parameters

### `dwSinkStreamIndex` [in]

The zero-based index of the stream to query. The index is returned in the *pdwSinkStreamIndex* parameter of the [IMFCaptureSink::AddStream](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nf-mfcaptureengine-imfcapturesink-addstream) method.

### `ppMediaType` [out]

Receives a pointer to the [IMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediatype) interface. The caller must release the pointer.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **MF_E_INVALIDSTREAMNUMBER** | The *dwSinkStreamIndex* parameter is invalid. |

## See also

[IMFCaptureSink](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nn-mfcaptureengine-imfcapturesink)