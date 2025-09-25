# IMFMediaSink::GetStreamSinkById

## Description

Gets a stream sink, specified by stream identifier.

## Parameters

### `dwStreamSinkIdentifier` [in]

Stream identifier of the stream sink.

### `ppStreamSink` [out]

Receives a pointer to the stream's [IMFStreamSink](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfstreamsink) interface. The caller must release the interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_INVALIDSTREAMNUMBER** | The stream identifier is not valid. |
| **MF_E_SHUTDOWN** | The media sink's [Shutdown](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediasink-shutdown) method has been called. |

## Remarks

If you add a stream sink by calling the [IMFMediaSink::AddStreamSink](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediasink-addstreamsink) method, the stream identifier is specified in the *dwStreamSinkIdentifier* parameter of that method. If the media sink has a fixed set of streams, the media sink assigns the stream identifiers.

To enumerate the streams by index number instead of stream identifier, call [IMFMediaSink::GetStreamSinkByIndex](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediasink-getstreamsinkbyindex).

## See also

[IMFMediaSink](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmediasink)

[Media Sinks](https://learn.microsoft.com/windows/desktop/medfound/media-sinks)