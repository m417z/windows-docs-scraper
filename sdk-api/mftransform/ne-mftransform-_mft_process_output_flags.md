# _MFT_PROCESS_OUTPUT_FLAGS enumeration

## Description

Defines flags for processing output samples in a Media Foundation transform (MFT).

## Constants

### `MFT_PROCESS_OUTPUT_DISCARD_WHEN_NO_BUFFER:0x1`

Do not produce output for streams in which the **pSample** member of the [MFT_OUTPUT_DATA_BUFFER](https://learn.microsoft.com/windows/desktop/api/mftransform/ns-mftransform-mft_output_data_buffer) structure is **NULL**. This flag is not valid unless the MFT has marked the output stream with the MFT_OUTPUT_STREAM_DISCARDABLE or MFT_OUTPUT_STREAM_LAZY_READ flag. For more information, see [IMFTransform::GetOutputStreamInfo](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-getoutputstreaminfo).

### `MFT_PROCESS_OUTPUT_REGENERATE_LAST_OUTPUT:0x2`

Regenerates the last output sample. This flag is only used by video processing MFTs.

**Note** Requires Windows 8.

## See also

[IMFTransform::ProcessOutput](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-processoutput)

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)

[Media Foundation Transforms](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-transforms)