# IMFMediaSink::AddStreamSink

## Description

Adds a new stream sink to the media sink.

## Parameters

### `dwStreamSinkIdentifier` [in]

Identifier for the new stream. The value is arbitrary but must be unique.

### `pMediaType` [in]

Pointer to the [IMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediatype) interface, specifying the media type for the stream. This parameter can be **NULL**.

### `ppStreamSink` [out]

Receives a pointer to the new stream sink's [IMFStreamSink](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfstreamsink) interface. The caller must release the interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_INVALIDSTREAMNUMBER** | The specified stream identifier is not valid. |
| **MF_E_SHUTDOWN** | The media sink's [Shutdown](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediasink-shutdown) method has been called. |
| **MF_E_STREAMSINK_EXISTS** | There is already a stream sink with the same stream identifier. |
| **MF_E_STREAMSINKS_FIXED** | This media sink has a fixed set of stream sinks. New stream sinks cannot be added. |

## Remarks

Not all media sinks support this method. If the media sink does not support this method, the [IMFMediaSink::GetCharacteristics](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediasink-getcharacteristics) method returns the MEDIASINK_FIXED_STREAMS flag.

If *pMediaType* is **NULL**, use the [IMFMediaTypeHandler](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmediatypehandler) interface to set the media type. Call [IMFStreamSink::GetMediaTypeHandler](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfstreamsink-getmediatypehandler) to get a pointer to the interface.

## See also

[IMFMediaSink](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmediasink)

[Media Sinks](https://learn.microsoft.com/windows/desktop/medfound/media-sinks)