# IMFSinkWriter::PlaceMarker

## Description

Places a marker in the specified stream.

## Parameters

### `dwStreamIndex` [in]

The zero-based index of the stream.

### `pvContext` [in]

Pointer to an application-defined value. The value of this parameter is returned to the caller in the *pvContext* parameter of the caller's [IMFSinkWriterCallback::OnMarker](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nf-mfreadwrite-imfsinkwritercallback-onmarker) callback method. The application is responsible for any memory allocation associated with this data. This parameter can be **NULL**.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| ****S_OK**** | The method succeeded. |
| ****MF_E_INVALIDREQUEST**** | The request is invalid. |

## Remarks

To use this method, you must provide an asynchronous callback when you create the sink writer. Otherwise, the method returns **MF_E_INVALIDREQUEST**. For more information, see [MF_SINK_WRITER_ASYNC_CALLBACK](https://learn.microsoft.com/windows/desktop/medfound/mf-sink-writer-async-callback).

Markers provide a way to be notified when the media sink consumes all of the samples in a stream up to a certain point. The media sink does not process the marker until it has processed all of the samples that came before the marker. When the media sink processes the marker, the sink writer calls the application's [OnMarker](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nf-mfreadwrite-imfsinkwritercallback-onmarker) method. When the callback is invoked, you know that the sink has consumed all of the previous samples for that stream.

For example, to change the format midstream, call **PlaceMarker** at the point where the format changes. When [OnMarker](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nf-mfreadwrite-imfsinkwritercallback-onmarker) is called, it is safe to call [IMFSinkWriter::SetInputMediaType](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nf-mfreadwrite-imfsinkwriter-setinputmediatype) to change the input type (assuming that the media sink supports dynamic format changes).

Internally, this method calls [IMFStreamSink::PlaceMarker](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfstreamsink-placemarker) on the media sink.

**Note** The *pvContext* parameter of the **IMFSinkWriter::PlaceMarker** method is not passed to the *pvarContextValue* parameter of the [IMFStreamSink::PlaceMarker](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfstreamsink-placemarker) method. These two parameters are not directly related.

This interface is available on Windows Vista if Platform Update Supplement for Windows Vista is installed.

## See also

[IMFSinkWriter](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nn-mfreadwrite-imfsinkwriter)

[Sink Writer](https://learn.microsoft.com/windows/desktop/medfound/sink-writer)