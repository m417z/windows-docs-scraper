# IMFSinkWriter::BeginWriting

## Description

Initializes the sink writer for writing.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| ****S_OK**** | The method succeeded. |
| ****MF_E_INVALIDREQUEST**** | The request is invalid. |

## Remarks

Call this method after you configure the input streams and before you send any data to the sink writer.

You must call **BeginWriting** before calling any of the following methods:

* [IMFSinkWriter::Finalize](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nf-mfreadwrite-imfsinkwriter-finalize)
* [IMFSinkWriter::Flush](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nf-mfreadwrite-imfsinkwriter-flush)
* [IMFSinkWriter::NotifyEndOfSegment](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nf-mfreadwrite-imfsinkwriter-notifyendofsegment)
* [IMFSinkWriter::PlaceMarker](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nf-mfreadwrite-imfsinkwriter-placemarker)
* [IMFSinkWriter::SendStreamTick](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nf-mfreadwrite-imfsinkwriter-sendstreamtick)
* [IMFSinkWriter::WriteSample](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nf-mfreadwrite-imfsinkwriter-writesample)

The underlying media sink must have at least one input stream. Otherwise, **BeginWriting** returns **MF_E_INVALIDREQUEST**. To add input streams, call the [IMFSinkWriter::AddStream](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nf-mfreadwrite-imfsinkwriter-addstream) method.

If **BeginWriting** succeeds, any further calls to **BeginWriting** return **MF_E_INVALIDREQUEST**.

This interface is available on Windows Vista if Platform Update Supplement for Windows Vista is installed.

## See also

[IMFSinkWriter](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nn-mfreadwrite-imfsinkwriter)

[Sink Writer](https://learn.microsoft.com/windows/desktop/medfound/sink-writer)