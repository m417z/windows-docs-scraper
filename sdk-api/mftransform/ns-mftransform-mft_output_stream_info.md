# MFT_OUTPUT_STREAM_INFO structure

## Description

Contains information about an output stream on a Media Foundation transform (MFT). To get these values, call [IMFTransform::GetOutputStreamInfo](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-getoutputstreaminfo).

## Members

### `dwFlags`

Bitwise **OR** of zero or more flags from the [_MFT_OUTPUT_STREAM_INFO_FLAGS](https://learn.microsoft.com/windows/win32/api/mftransform/ne-mftransform-_mft_output_stream_info_flags) enumeration.

### `cbSize`

Minimum size of each output buffer, in bytes. If the MFT does not require a specific size, the value is zero. For uncompressed audio, the value should be the audio frame size, which you can get from the [MF_MT_AUDIO_BLOCK_ALIGNMENT](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-audio-block-alignment-attribute) attribute in the media type.

If the **dwFlags** member contains the MFT_OUTPUT_STREAM_PROVIDES_SAMPLES flag, the value is zero, because the MFT allocates the output buffers.

### `cbAlignment`

The memory alignment required for output buffers. If the MFT does not require a specific alignment, the value is zero. If the **dwFlags** member contains the MFT_OUTPUT_STREAM_PROVIDES_SAMPLES flag, this value is the alignment that the MFT uses internally when it allocates samples. It is recommended, but not required, that MFTs allocate buffers with at least a 16-byte memory alignment.

## Remarks

Before the media types are set, the only values that should be considered valid is the MFT_OUTPUT_STREAM_OPTIONAL flag in the **dwFlags** member. This flag indicates that the stream is optional and does not require a media type.

After you set a media type on all of the input and output streams (not including optional streams), all of the values returned by the [GetOutputStreamInfo](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-getoutputstreaminfo) method are valid. They might change if you set different media types.

## See also

[Media Foundation Structures](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-structures)

[Media Foundation Transforms](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-transforms)