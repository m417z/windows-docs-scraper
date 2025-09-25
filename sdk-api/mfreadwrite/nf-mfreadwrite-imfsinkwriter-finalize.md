# IMFSinkWriter::Finalize

## Description

Completes all writing operations on the sink writer.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Call this method after you send all of the input samples to the sink writer. The method performs any operations needed to create the final output from the media sink.

If you provide a callback interface when you create the sink writer, this method completes asynchronously. When the operation completes, the [IMFSinkWriterCallback::OnFinalize](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nf-mfreadwrite-imfsinkwritercallback-onfinalize) method of your callback is called. For more information, see [MF_SINK_WRITER_ASYNC_CALLBACK](https://learn.microsoft.com/windows/desktop/medfound/mf-sink-writer-async-callback). Otherwise, if you do not provide a callback, the **Finalize** method blocks until the operation completes.

Internally, this method calls [IMFStreamSink::PlaceMarker](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfstreamsink-placemarker) to place end-of-segment markers for each stream on the media sink. It also calls [IMFFinalizableMediaSink::BeginFinalize](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imffinalizablemediasink-beginfinalize) and [EndFinalize](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imffinalizablemediasink-endfinalize) if the media sink supports the [IMFFinalizableMediaSink](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imffinalizablemediasink) interface.

After this method is called, the following methods will fail:

* [IMFSinkWriter::PlaceMarker](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nf-mfreadwrite-imfsinkwriter-placemarker)
* [IMFSinkWriter::SendStreamTick](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nf-mfreadwrite-imfsinkwriter-sendstreamtick)
* [IMFSinkWriter::WriteSample](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nf-mfreadwrite-imfsinkwriter-writesample)

If you do not call **Finalize**, the output from the media sink might be incomplete or invalid. For example, required file headers might be missing from the output file.

This interface is available on Windows Vista if Platform Update Supplement for Windows Vista is installed.

## See also

[IMFSinkWriter](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nn-mfreadwrite-imfsinkwriter)

[Sink Writer](https://learn.microsoft.com/windows/desktop/medfound/sink-writer)