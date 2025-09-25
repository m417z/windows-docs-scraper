# IMFSinkWriter::SendStreamTick

## Description

Indicates a gap in an input stream.

## Parameters

### `dwStreamIndex` [in]

The zero-based index of the stream.

### `llTimestamp` [in]

The position in the stream where the gap in the data occurs. The value is given in 100-nanosecond units, relative to the start of the stream.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

For video, call this method once for each missing frame. For audio, call this method at least once per second during a gap in the audio. Set the [MFSampleExtension_Discontinuity](https://learn.microsoft.com/windows/desktop/medfound/mfsampleextension-discontinuity-attribute) attribute on the first media sample after the gap.

Internally, this method calls [IMFStreamSink::PlaceMarker](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfstreamsink-placemarker) on the media sink.

This interface is available on Windows Vista if Platform Update Supplement for Windows Vista is installed.

## See also

[IMFSinkWriter](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nn-mfreadwrite-imfsinkwriter)

[Sink Writer](https://learn.microsoft.com/windows/desktop/medfound/sink-writer)