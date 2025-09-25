# _MFT_INPUT_STREAM_INFO_FLAGS enumeration

## Description

Describes an input stream on a Media Foundation transform (MFT).

## Constants

### `MFT_INPUT_STREAM_WHOLE_SAMPLES:0x1`

Each media sample ([IMFSample](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfsample) interface) of input data must contain complete, unbroken units of data. The definition of a *unit of data* depends on the media type: For uncompressed video, a video frame; for compressed data, a compressed packet; for uncompressed audio, a single audio frame.

For uncompressed audio formats, this flag is always implied. (It is valid to set the flag, but not required.) An uncompressed audio frame should never span more than one media sample.

### `MFT_INPUT_STREAM_SINGLE_SAMPLE_PER_BUFFER:0x2`

Each media sample that the client provides as input must contain exactly one unit of data, as defined for the MFT_INPUT_STREAM_WHOLE_SAMPLES flag.

If this flag is present, the MFT_INPUT_STREAM_WHOLE_SAMPLES flag must also be present.

An MFT that processes uncompressed audio should not set this flag. The MFT should accept buffers that contain more than a single audio frame, for efficiency.

### `MFT_INPUT_STREAM_FIXED_SAMPLE_SIZE:0x4`

All input samples must be the same size.
The size is given in the **cbSize** member of the [MFT_INPUT_STREAM_INFO](https://learn.microsoft.com/windows/desktop/api/mftransform/ns-mftransform-mft_input_stream_info) structure. The MFT must provide this value. During processing, the MFT should verify the size of input samples, and may drop samples with incorrect size.

### `MFT_INPUT_STREAM_HOLDS_BUFFERS:0x8`

The MFT might hold one or more input samples after [IMFTransform::ProcessOutput](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-processoutput) is called. If this flag is present, the **hnsMaxLatency** member of the [MFT_INPUT_STREAM_INFO](https://learn.microsoft.com/windows/desktop/api/mftransform/ns-mftransform-mft_input_stream_info) structure gives the maximum latency, and the **cbMaxLookahead** member gives the maximum number of bytes of lookahead.

### `MFT_INPUT_STREAM_DOES_NOT_ADDREF:0x100`

The MFT does not hold input samples after the [IMFTransform::ProcessInput](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-processinput) method returns. It releases the sample before the **ProcessInput** method returns.

If this flag is absent, the MFT might hold a reference count on the samples that are passed to the [ProcessInput](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-processinput) method. The client must not re-use or delete the buffer memory until the MFT releases the sample's [IMFSample](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfsample) pointer.

If this flag is absent, it does not guarantee that the MFT holds a reference count on the input samples. It is valid for an MFT to release input samples in [ProcessInput](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-processinput) even if the MFT does not set this flag. However, setting this flag might enable to client to optimize how it re-uses buffers.

An MFT should not set this flag if it ever holds onto an input sample after returning from [ProcessInput](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-processinput).

### `MFT_INPUT_STREAM_REMOVABLE:0x200`

This input stream can be removed by calling [IMFTransform::DeleteInputStream](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-deleteinputstream).

### `MFT_INPUT_STREAM_OPTIONAL:0x400`

This input stream is optional. The transform can produce output without receiving input from this stream. The caller can deselect the stream by not setting a media type or by setting a **NULL** media type. It is possible for every input stream on a transform to be optional, but at least one input must be selected in order to produce output.

### `MFT_INPUT_STREAM_PROCESSES_IN_PLACE:0x800`

The MFT can perform in-place processing. In this mode, the MFT directly modifies the input buffer. When the client calls [ProcessOutput](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-processoutput), the same sample that was delivered to this stream is returned in the output stream that has a matching stream identifier. This flag implies that the MFT holds onto the input buffer, so this flag cannot combined with the MFT_INPUT_STREAM_DOES_NOT_ADDREF flag.

If this flag is present, the MFT must set the MFT_OUTPUT_STREAM_PROVIDES_SAMPLES or MFT_OUTPUT_STREAM_CAN_PROVIDE_SAMPLES flag for the output stream that corresponds to this input stream. (See [IMFTransform::GetOutputStreamInfo](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-getoutputstreaminfo)).

## Remarks

Before the client sets the media types on the transform, the only flags guaranteed to be accurate are the MFT_INPUT_STREAM_REMOVABLE and MFT_INPUT_STREAM_OPTIONAL flags. For all other flags, the client should first set the media type on every non-optional stream.

In the default processing model, an MFT holds a reference count on the sample that it receives in [ProcessInput](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-processinput). It does not process the sample immediately inside **ProcessInput**. When [ProcessOutput](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-processoutput) is called, the MFT produces output data and then discards the input sample. The following variations on this model are defined:

* If an MFT never holds onto input samples between [ProcessInput](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-processinput) and [ProcessOutput](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-processoutput), it can set the MFT_INPUT_STREAM_DOES_NOT_ADDREF.
* If an MFT holds some input samples beyond the next call to [ProcessOutput](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-processoutput), it can set the MFT_INPUT_STREAM_HOLDS_BUFFERS.

## See also

[MFT_INPUT_STREAM_INFO](https://learn.microsoft.com/windows/desktop/api/mftransform/ns-mftransform-mft_input_stream_info)

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)

[Media Foundation Transforms](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-transforms)