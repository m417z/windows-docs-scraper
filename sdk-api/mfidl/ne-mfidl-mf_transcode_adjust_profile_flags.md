# MF_TRANSCODE_ADJUST_PROFILE_FLAGS enumeration

## Description

Defines the profile flags that are set in the [MF_TRANSCODE_ADJUST_PROFILE](https://learn.microsoft.com/windows/desktop/medfound/mf-transcode-adjust-profile) attribute.

These flags are checked by [MFCreateTranscodeTopology](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-mfcreatetranscodetopology) during topology building. Based on these flags, **MFCreateTranscodeTopology** adjusts the transcode profile by modifying the configuration settings for the streams according to the input requirements of the encoder used in the topology.

For more information about the stream settings that an application can specify, see [Using the Transcode API](https://learn.microsoft.com/windows/desktop/medfound/fast-transcode-objects).

## Constants

### `MF_TRANSCODE_ADJUST_PROFILE_DEFAULT:0`

Media Foundation uses the application-specified settings for audio and video streams. If the required settings are not provided by the application, the topology is created but the encoding session fails. For the video stream, the frame rate and the interlace mode settings are modified. For more information, see Remarks.

### `MF_TRANSCODE_ADJUST_PROFILE_USE_SOURCE_ATTRIBUTES:1`

For both audio and video streams, the missing stream settings are filled by copying the input source attributes. This flag ensures the transcoded output file is the closest match to the input file.

## Remarks

If the **MF_TRANSCODE_ADJUST_PROFILE_DEFAULT** flag is specified, the following changes are made for the video stream:

* If the frame rate of the media source specified in the *pSrc* parameter of [MFCreateTranscodeTopology](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-mfcreatetranscodetopology) and the frame rate specified by the application in the [MF_MT_FRAME_RATE](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-frame-rate-attribute) attribute differ by less than 1/1000, the profile uses the media source frame rate. This is because the pipeline considers the difference to be negligible.
* If the application does not specify an interlaced mode by setting the [MF_MT_INTERLACE_MODE](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-interlace-mode-attribute) attribute, the profile is changed to use progressive frames.

The **MF_TRANSCODE_ADJUST_PROFILE_DEFAULT** flag must be accompanied with the required audio and video stream attributes provided by the application. For the audio stream, the required attributes are as follows:

* [MF_MT_AUDIO_NUM_CHANNELS](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-audio-num-channels-attribute)
* [MF_MT_AUDIO_SAMPLES_PER_SECOND](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-audio-samples-per-second-attribute)
* [MF_MT_AUDIO_BLOCK_ALIGNMENT](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-audio-block-alignment-attribute)
* [MF_MT_AUDIO_AVG_BYTES_PER_SECOND](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-audio-avg-bytes-per-second-attribute)
* [MF_MT_AUDIO_BITS_PER_SAMPLE](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-audio-bits-per-sample-attribute)

For the video stream, the required attributes are as follows:

* [MF_MT_FRAME_RATE](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-frame-rate-attribute)
* [MF_MT_FRAME_SIZE](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-frame-size-attribute)
* [MF_MT_AVG_BITRATE](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-avg-bitrate-attribute)
* [MF_MT_PIXEL_ASPECT_RATIO](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-pixel-aspect-ratio-attribute)

If these attributes are not set, [MFCreateTranscodeTopology](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-mfcreatetranscodetopology) creates the topology but Media Session fails to generate the encoded file. The failure code depends on the MFT node in the topology. For example, if the application does not set the frame size, the WMV encoder fails to encode the content and application gets the MF_E_INVALIDMEDIATYPE error code through the Media Session.

Use the **MF_TRANSCODE_ADJUST_PROFILE_USE_SOURCE_ATTRIBUTES** flag when you want to transcode the file by using the input stream attributes. The input source stream attributes are copied to the output media type before the MFT node is inserted in the topology. If you set additional stream attributes, this flag does not overwrite the set values. Only the missing attributes are filled with the input source's attribute values. This flag is useful in remux scenario where you want to generate the output file in the same format as the input source. If you want to perform format conversion, make sure you set the [MF_MT_SUBTYPE](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-subtype-attribute) attribute for the stream to specify the encoder that topology builder must use. The transform node is added in the topology unless [MF_TRANSCODE_DONOT_INSERT_ENCODER](https://learn.microsoft.com/windows/desktop/medfound/mf-transcode-donot-insert-encoder) is set. In this case, and the content is not encoded. Instead, if permitted by the container, the content is embedded in the specified container.

For example, assume that your input source is an MP3 file. You set the container to be **MFTranscodeContainerType_ASF**, you do not set any stream attributes, and you set the **MF_TRANSCODE_ADJUST_PROFILE_USE_SOURCE_ATTRIBUTES** flag. In this case, the generated output file is an ASF file (.wma) containing MP3 media data. Note that if you use this flag, certain input stream attributes and the container type might not be compatible.

## See also

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)

[Transcode API](https://learn.microsoft.com/windows/desktop/medfound/transcode-api)