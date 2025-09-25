# IMFMediaSink::GetStreamSinkByIndex

## Description

Gets a stream sink, specified by index.

## Parameters

### `dwIndex` [in]

Zero-based index of the stream. To get the number of streams, call [IMFMediaSink::GetStreamSinkCount](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediasink-getstreamsinkcount).

### `ppStreamSink` [out]

Receives a pointer to the stream's [IMFStreamSink](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfstreamsink) interface. The caller must release the interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_INVALIDINDEX** | Invalid index. |
| **MF_E_SHUTDOWN** | The media sink's [Shutdown](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediasink-shutdown) method has been called. |

## Remarks

Enumerating stream sinks is not a thread-safe operation, because stream sinks can be added or removed between calls to this method.

## See also

[IMFMediaSink](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmediasink)

[Media Sinks](https://learn.microsoft.com/windows/desktop/medfound/media-sinks)