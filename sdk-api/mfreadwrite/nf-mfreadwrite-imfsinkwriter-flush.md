# IMFSinkWriter::Flush

## Description

Flushes one or more streams.

## Parameters

### `dwStreamIndex` [in]

The zero-based index of the stream to flush, or **MF_SINK_WRITER_ALL_STREAMS** to flush all of the streams.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_INVALIDREQUEST** | The request is invalid. |

## Remarks

You must call [IMFSinkWriter::BeginWriting](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nf-mfreadwrite-imfsinkwriter-beginwriting) before calling this method. Otherwise, the method returns **MF_E_INVALIDREQUEST**.

For each stream that is flushed, the sink writer drops all pending samples, flushes the encoder, and sends an **MFSTREAMSINK_MARKER_ENDOFSEGMENT** marker to the media sink.

This interface is available on Windows Vista if Platform Update Supplement for Windows Vista is installed.

## See also

[IMFSinkWriter](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nn-mfreadwrite-imfsinkwriter)

[Sink Writer](https://learn.microsoft.com/windows/desktop/medfound/sink-writer)