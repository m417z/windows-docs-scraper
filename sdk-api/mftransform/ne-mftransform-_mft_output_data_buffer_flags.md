# _MFT_OUTPUT_DATA_BUFFER_FLAGS enumeration

## Description

Defines flags for the [IMFTransform::ProcessOutput](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-processoutput) method.

## Constants

### `MFT_OUTPUT_DATA_BUFFER_INCOMPLETE:0x1000000`

The MFT can still generate output from this stream without receiving any more input. Call [ProcessOutput](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-processoutput) again to process the next batch of input data.

### `MFT_OUTPUT_DATA_BUFFER_FORMAT_CHANGE:0x100`

The format has changed on this output stream, or there is a new preferred format for this stream. When this flag is set, the MFT clears the media type for the stream. The [ProcessOutput](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-processoutput) method returns MF_E_TRANSFORM_STREAM_CHANGE and generates no output for any stream. Further calls to [IMFTransform::ProcessInput](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-processinput) or **ProcessOutput** will fail until the client sets a new media type.

### `MFT_OUTPUT_DATA_BUFFER_STREAM_END:0x200`

The MFT has removed this output stream. The output stream must have the MFT_OUTPUT_STREAM_REMOVABLE flag. (See [IMFTransform::GetOutputStreamInfo](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-getoutputstreaminfo).)

When the MFT removes an output stream, the MFT returns this status code on the next call to [ProcessOutput](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-processoutput) after the last output sample has been produced. When the MFT returns this status code, it does not modify any sample contained in the **pSample** member of the [MFT_OUTPUT_DATA_BUFFER](https://learn.microsoft.com/windows/desktop/api/mftransform/ns-mftransform-mft_output_data_buffer) structure, nor does it allocate a new sample if **pSample** is **NULL**.

After this status code is returned, the stream identifier for this output stream is no longer valid. The client should no longer provide an [MFT_OUTPUT_DATA_BUFFER](https://learn.microsoft.com/windows/desktop/api/mftransform/ns-mftransform-mft_output_data_buffer) structure for that stream when it calls [ProcessOutput](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-processoutput).

The [ProcessOutput](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-processoutput) method does not return **MF_E_TRANSFORM_STREAM_CHANGE** when a stream ends, unless there is a change in another stream that requires this return code.

### `MFT_OUTPUT_DATA_BUFFER_NO_SAMPLE:0x300`

There is no sample ready for this stream. This flag might be set if the MFT has multiple output streams that produce data at different times. It sets this flag for each stream that is not ready to produce data. It does not modify the output sample contained in the **pSample** member of the [MFT_OUTPUT_DATA_BUFFER](https://learn.microsoft.com/windows/desktop/api/mftransform/ns-mftransform-mft_output_data_buffer) structure, nor does it allocate a new sample is **pSample** is **NULL**.

If no streams are ready to produce output, the MFT does not set this flag. Instead, the [ProcessOutput](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-processoutput) method returns MF_E_TRANSFORM_NEED_MORE_INPUT.

## Remarks

The values in this enumeration are not bit flags, so they should not be combined with a bitwise **OR**. Also, the caller should test for these flags with the equality operator, not a bitwise **AND**:

``` syntax
// Correct.
if (Buffer.dwStatus == MFT_OUTPUT_DATA_BUFFER_STREAM_END)
{
    ...
}

// Incorrect.
if ((Buffer.dwStatus & MFT_OUTPUT_DATA_BUFFER_STREAM_END) != 0)
{
    ...
}

```

## See also

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)

[Media Foundation Transforms](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-transforms)