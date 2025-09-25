# MFCreateTranscodeTopology function

## Description

Creates a partial transcode topology.

The underlying topology builder creates a partial topology by connecting the required pipeline objects:
source, encoder, and sink. The encoder and the sink are configured according to the settings specified by the caller in the transcode profile.

To create the transcode profile object, call the [MFCreateTranscodeProfile](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-mfcreatetranscodeprofile) function and set the required attributes by calling the appropriate the [IMFTranscodeProfile](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftranscodeprofile) methods.

The configured transcode profile is passed to the **MFCreateTranscodeTopology** function, which creates the transcode topology with the appropriate settings. The caller can then set this topology on the Media Session and start the session to begin the encoding process. When the Media Session ends, the transcoded file is generated.

## Parameters

### `pSrc` [in]

A pointer to a media source that encapsulates the source file to be transcoded. The media source object exposes the [IMFMediaSource](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmediasource) interface and can be created by using the source resolver. For more information, see [Using the Source Resolver](https://learn.microsoft.com/windows/desktop/medfound/using-the-source-resolver).

### `pwszOutputFilePath` [in]

A pointer to a null-terminated string that contains the name and path of the output file to be generated.

### `pProfile` [in]

A pointer to the transcode profile that contains the configuration settings for the audio stream, the video stream, and the container to which the file is written. The transcode profile object exposes the [IMFTranscodeProfile](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftranscodeprofile) interface and must be created by calling the [MFCreateTranscodeProfile](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-mfcreatetranscodeprofile) function. After the object has been created the caller must provide the configuration settings by calling appropriate the **IMFTranscodeProfile** methods.

### `ppTranscodeTopo` [out]

Receives a pointer to the [IMFTopology](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftopology) interface of the transcode topology object. The caller must release the interface.

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The function call succeeded, and *ppTranscodeTopo* receives a pointer to the transcode topology. |
| **E_INVALIDARG** | *pwszOutputFilePath* contains invalid characters. |
| **MF_E_MEDIA_SOURCE_NO_STREAMS_SELECTED** | No streams are selected in the media source. |
| **MF_E_TRANSCODE_NO_CONTAINERTYPE** | The profile does not contain the [MF_TRANSCODE_CONTAINERTYPE](https://learn.microsoft.com/windows/desktop/medfound/mf-transcode-containertype) attribute. |
| **MF_E_TRANSCODE_NO_MATCHING_ENCODER** | For one or more streams, cannot find an encoder that accepts the media type given in the profile. |
| **MF_E_TRANSCODE_PROFILE_NO_MATCHING_STREAMS** | The profile does not specify a media type for any of the selected streams on the media source. |

## Remarks

For example code that uses this function, see the following topics:

* [Tutorial: Encoding an MP4 File](https://learn.microsoft.com/windows/desktop/medfound/tutorial--encoding-an-mp4-file-)
* [Tutorial: Encoding a WMA File](https://learn.microsoft.com/windows/desktop/medfound/tutorial--converting-an-mp3-file-to-a-wma-file)

## See also

[IMFTopology](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftopology)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)

[Topologies](https://learn.microsoft.com/windows/desktop/medfound/topologies)

[Transcode API](https://learn.microsoft.com/windows/desktop/medfound/transcode-api)