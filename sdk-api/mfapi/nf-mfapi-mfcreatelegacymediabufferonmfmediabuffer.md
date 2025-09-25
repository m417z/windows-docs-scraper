# MFCreateLegacyMediaBufferOnMFMediaBuffer function

## Description

Converts a Media Foundation media buffer into a buffer that is compatible with DirectX Media Objects (DMOs).

## Parameters

### `pSample`

Pointer to the [IMFSample](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfsample) interface of the sample that contains the Media Foundation buffer. This parameter can be **NULL**.

### `pMFMediaBuffer`

Pointer to the [IMFMediaBuffer](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediabuffer) interface of the Media Foundation buffer.

### `cbOffset`

Offset in bytes from the start of the Media Foundation buffer. This offset defines where the DMO buffer starts. If this parameter is zero, the DMO buffer starts at the beginning of the Media Foundation buffer.

### `ppMediaBuffer`

Receives a pointer to the **IMediaBuffer** interface. This interface is documented in the DirectShow SDK documentation. The caller must release the interface.

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The function succeeded. |
| **E_INVALIDARG** | Invalid argument. The *pIMFMediaBuffer* parameter must not be **NULL**. |

## Remarks

The DMO buffer created by this function also exposes the [IMFSample](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfsample) interface. If *pIMFSample* is **NULL**, all of the **IMFSample** methods return MF_E_NOT_INITIALIZED. Otherwise, they call through to the *pIMFSample* pointer.

If the Media Foundation buffer specified by *pIMFMediaBuffer* exposes the [IMF2DBuffer](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imf2dbuffer) interface, the DMO buffer also exposes **IMF2DBuffer**.

## See also

[IMF2DBuffer](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imf2dbuffer)

[IMFMediaBuffer](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediabuffer)

[IMFSample](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfsample)

[Media Buffers](https://learn.microsoft.com/windows/desktop/medfound/media-buffers)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)