# _MFT_OUTPUT_STREAM_INFO_FLAGS enumeration

## Description

Describes an output stream on a Media Foundation transform (MFT).

## Constants

### `MFT_OUTPUT_STREAM_WHOLE_SAMPLES:0x1`

Each media sample ([IMFSample](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfsample) interface) of output data from the MFT contains complete, unbroken units of data. The definition of a *unit of data* depends on the media type: For uncompressed video, a video frame; for compressed data, a compressed packet; for uncompressed audio, a single audio frame.

For uncompressed audio formats, this flag is always implied. (It is valid to set the flag, but not required.) An uncompressed audio frame should never span more than one media sample.

### `MFT_OUTPUT_STREAM_SINGLE_SAMPLE_PER_BUFFER:0x2`

Each output sample contains exactly one unit of data, as defined for the MFT_OUTPUT_STREAM_WHOLE_SAMPLES flag.

If this flag is present, the MFT_OUTPUT_STREAM_WHOLE_SAMPLES flag must also be present.

An MFT that outputs uncompressed audio should not set this flag. For efficiency, it should output more than one audio frame at a time.

### `MFT_OUTPUT_STREAM_FIXED_SAMPLE_SIZE:0x4`

All output samples are the same size.

### `MFT_OUTPUT_STREAM_DISCARDABLE:0x8`

The MFT can discard the output data from this output stream, if requested by the client. To discard the output, set the MFT_PROCESS_OUTPUT_DISCARD_WHEN_NO_BUFFER flag in the [IMFTransform::ProcessOutput](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-processoutput) method.

### `MFT_OUTPUT_STREAM_OPTIONAL:0x10`

This output stream is optional. The client can deselect the stream by not setting a media type or by setting a **NULL** media type. When an optional stream is deselected, it does not produce any output data.

### `MFT_OUTPUT_STREAM_PROVIDES_SAMPLES:0x100`

The MFT provides the output samples for this stream, either by allocating them internally or by operating directly on the input samples. The MFT cannot use output samples provided by the client for this stream.

If this flag is not set, the MFT must set **cbSize** to a nonzero value in the [MFT_OUTPUT_STREAM_INFO](https://learn.microsoft.com/windows/desktop/api/mftransform/ns-mftransform-mft_output_stream_info) structure, so that the client can allocate the correct buffer size. For more information, see [IMFTransform::GetOutputStreamInfo](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-getoutputstreaminfo). This flag cannot be combined with the MFT_OUTPUT_STREAM_CAN_PROVIDE_SAMPLES flag.

### `MFT_OUTPUT_STREAM_CAN_PROVIDE_SAMPLES:0x200`

The MFT can either provide output samples for this stream or it can use samples that the client allocates. This flag cannot be combined with the MFT_OUTPUT_STREAM_PROVIDES_SAMPLES flag.

If the MFT does not set this flag or the MFT_OUTPUT_STREAM_PROVIDES_SAMPLES flag, the client must allocate the samples for this output stream. The MFT will not provide its own samples.

### `MFT_OUTPUT_STREAM_LAZY_READ:0x400`

The MFT does not require the client to process the output for this stream. If the client continues to send input data without getting the output from this stream, the MFT simply discards the previous input.

### `MFT_OUTPUT_STREAM_REMOVABLE:0x800`

The MFT might remove this output stream during streaming. This flag typically applies to demultiplexers, where the input data contains multiple streams that can start and stop during streaming. For more information, see [IMFTransform::ProcessOutput](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-processoutput).

## Remarks

Before the client sets the media types on the MFT, the only flag guaranteed to be accurate is the MFT_OUTPUT_STREAM_OPTIONAL flag. For all other flags, the client should first set the media type on every non-optional stream.

The MFT_OUTPUT_STREAM_DISCARDABLE and MFT_OUTPUT_STREAM_LAZY_READ flags define different behaviors for how the MFT can discard output data.

* MFT_OUTPUT_STREAM_DISCARDABLE: The MFT discards output data only if the client calls [ProcessOutput](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-processoutput) with the MFT_PROCESS_OUTPUT_DISCARD_WHEN_NO_BUFFER flag. The MFT never discards data when the client calls [ProcessInput](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-processinput).
* MFT_OUTPUT_STREAM_LAZY_READ: If the client continues to call [ProcessInput](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-processinput) without collecting the output from this stream, the MFT eventually discards the output. If all output streams have the MFT_OUTPUT_STREAM_LAZY_READ flag, the MFT never refuses more input data.

If neither of these flags is set, the MFT never discards output data.

## See also

[MFT_OUTPUT_STREAM_INFO](https://learn.microsoft.com/windows/desktop/api/mftransform/ns-mftransform-mft_output_stream_info)

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)

[Media Foundation Transforms](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-transforms)