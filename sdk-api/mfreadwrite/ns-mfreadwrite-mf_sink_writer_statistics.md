# MF_SINK_WRITER_STATISTICS structure

## Description

Contains statistics about the performance of the sink writer.

## Members

### `cb`

The size of the structure, in bytes.

### `llLastTimestampReceived`

The time stamp of the most recent sample given to the sink writer. The sink writer updates this value each time the application calls [IMFSinkWriter::WriteSample](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nf-mfreadwrite-imfsinkwriter-writesample).

### `llLastTimestampEncoded`

The time stamp of the most recent sample to be encoded. The sink writer updates this value whenever it calls [IMFTransform::ProcessOutput](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-processoutput) on the encoder.

### `llLastTimestampProcessed`

The time stamp of the most recent sample given to the media sink. The sink writer updates this value whenever it calls [IMFStreamSink::ProcessSample](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfstreamsink-processsample) on the media sink.

### `llLastStreamTickReceived`

The time stamp of the most recent stream tick. The sink writer updates this value whenever the application calls [IMFSinkWriter::SendStreamTick](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nf-mfreadwrite-imfsinkwriter-sendstreamtick).

### `llLastSinkSampleRequest`

The system time of the most recent sample request from the media sink. The sink writer updates this value whenever it receives an [MEStreamSinkRequestSample](https://learn.microsoft.com/windows/desktop/medfound/mestreamsinkrequestsample) event from the media sink. The value is the current system time.

### `qwNumSamplesReceived`

The number of samples received.

### `qwNumSamplesEncoded`

The number of samples encoded.

### `qwNumSamplesProcessed`

The number of samples given to the media sink.

### `qwNumStreamTicksReceived`

The number of stream ticks received.

### `dwByteCountQueued`

The amount of data, in bytes, currently waiting to be processed.

### `qwByteCountProcessed`

The total amount of data, in bytes, that has been sent to the media sink.

### `dwNumOutstandingSinkSampleRequests`

The number of pending sample requests.

### `dwAverageSampleRateReceived`

The average rate, in media samples per 100-nanoseconds, at which the application sent samples to the sink writer.

### `dwAverageSampleRateEncoded`

The average rate, in media samples per 100-nanoseconds, at which the sink writer sent samples to the encoder.

### `dwAverageSampleRateProcessed`

The average rate, in media samples per 100-nanoseconds, at which the sink writer sent samples to the media sink.

## See also

[IMFSinkWriter::GetStatistics](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nf-mfreadwrite-imfsinkwriter-getstatistics)

[Media Foundation Structures](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-structures)