# IMFStreamSink::GetMediaTypeHandler

## Description

Retrieves the media type handler for the stream sink. You can use the media type handler to find which formats the stream supports, and to set the media type on the stream.

## Parameters

### `ppHandler` [out]

Receives a pointer to the [IMFMediaTypeHandler](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmediatypehandler) interface. The caller must release the interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_SHUTDOWN** | The media sink's [Shutdown](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediasink-shutdown) method has been called. |
| **MF_E_STREAMSINK_REMOVED** | This stream was removed from the media sink and is no longer valid. |

## Remarks

If the stream sink currently does not support any media types, this method returns a media type handler that fails any calls to [IMFMediaTypeHandler::GetCurrentMediaType](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediatypehandler-getcurrentmediatype) and [IMFMediaTypeHandler::IsMediaTypeSupported](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediatypehandler-ismediatypesupported).

## See also

[IMFStreamSink](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfstreamsink)

[Media Sinks](https://learn.microsoft.com/windows/desktop/medfound/media-sinks)