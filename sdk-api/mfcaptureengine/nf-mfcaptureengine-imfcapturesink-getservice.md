# IMFCaptureSink::GetService

## Description

Queries the underlying [Sink Writer](https://learn.microsoft.com/windows/desktop/medfound/sink-writer) object for an interface.

## Parameters

### `dwSinkStreamIndex` [in]

The zero-based index of the stream to query. The index is returned in the *pdwSinkStreamIndex* parameter of the [IMFCaptureSink::AddStream](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nf-mfcaptureengine-imfcapturesink-addstream) method.

### `rguidService` [in]

A service identifier GUID. Currently, the value must be **GUID_NULL**.

### `riid` [in]

A service identifier GUID. Currently, the value must be **IID_IMFSinkWriter**.

### `ppUnknown` [out]

Receives a pointer to the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface. The caller must release the interface.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | Invalid argument. |
| **MF_E_INVALIDREQUEST** | Invalid request. |
| **MF_E_INVALIDSTREAMNUMBER** | Invalid stream number. |

## See also

[IMFCaptureSink](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nn-mfcaptureengine-imfcapturesink)