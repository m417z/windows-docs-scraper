# MFT_INPUT_STREAM_INFO structure

## Description

Contains information about an input stream on a Media Foundation transform (MFT). To get these values, call [IMFTransform::GetInputStreamInfo](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-getinputstreaminfo).

## Members

### `hnsMaxLatency`

Maximum amount of time between an input sample and the corresponding output sample, in 100-nanosecond units. For example, an MFT that buffers two samples, each with a duration of 1 second, has a maximum latency of two seconds. If the MFT always turns input samples directly into output samples, with no buffering, the latency is zero.

### `dwFlags`

Bitwise **OR** of zero or more flags from the [_MFT_INPUT_STREAM_INFO_FLAGS](https://learn.microsoft.com/windows/win32/api/mftransform/ne-mftransform-_mft_input_stream_info_flags) enumeration.

### `cbSize`

The minimum size of each input buffer, in bytes. If the size is variable or the MFT does not require a specific size, the value is zero. For uncompressed audio, the value should be the audio frame size, which you can get from the [MF_MT_AUDIO_BLOCK_ALIGNMENT](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-audio-block-alignment-attribute) attribute in the media type.

### `cbMaxLookahead`

Maximum amount of input data, in bytes, that the MFT holds to perform lookahead. *Lookahead* is the action of looking forward in the data before processing it. This value should be the worst-case value. If the MFT does not keep a lookahead buffer, the value is zero.

### `cbAlignment`

The memory alignment required for input buffers. If the MFT does not require a specific alignment, the value is zero.

## Remarks

Before the media types are set, the only values that should be considered valid are the MFT_INPUT_STREAM_REMOVABLE and MFT_INPUT_STREAM_OPTIONAL flags in the **dwFlags** member.

* The MFT_INPUT_STREAM_REMOVABLE flag indicates that the stream can be deleted.
* The MFT_INPUT_STREAM_OPTIONAL flag indicates that the stream is optional and does not require a media type.

After you set a media type on all of the input and output streams (not including optional streams), all of the values returned by the [GetInputStreamInfo](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-getinputstreaminfo) method are valid. They might change if you set different media types.

## See also

[Media Foundation Structures](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-structures)

[Media Foundation Transforms](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-transforms)