# IMFSinkWriter::NotifyEndOfSegment

## Description

Notifies the media sink that a stream has reached the end of a segment.

## Parameters

### `dwStreamIndex` [in]

The zero-based index of a stream, or **MF_SINK_WRITER_ALL_STREAMS** to signal that all streams have reached the end of a segment.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| ****S_OK**** | The method succeeded. |
| ****MF_E_INVALIDREQUEST**** | The request is invalid. |

## Remarks

You must call [IMFSinkWriter::BeginWriting](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nf-mfreadwrite-imfsinkwriter-beginwriting) before calling this method. Otherwise, the method returns **MF_E_INVALIDREQUEST**.

This method sends an **MFSTREAMSINK_MARKER_ENDOFSEGMENT** marker to the media sink for the specified streams. For more information, see [IMFStreamSink::PlaceMarker](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfstreamsink-placemarker).

This interface is available on Windows Vista if Platform Update Supplement for Windows Vista is installed.

## See also

[IMFSinkWriter](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nn-mfreadwrite-imfsinkwriter)

[Sink Writer](https://learn.microsoft.com/windows/desktop/medfound/sink-writer)