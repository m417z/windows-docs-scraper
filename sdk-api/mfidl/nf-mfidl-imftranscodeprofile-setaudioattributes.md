# IMFTranscodeProfile::SetAudioAttributes

## Description

Sets audio stream configuration settings in the transcode profile.

To get a list of compatible audio media types supported by the Media Foundation transform (MFT) encoder , call [MFTranscodeGetAudioOutputAvailableTypes](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-mftranscodegetaudiooutputavailabletypes). You can get the attributes that are set on the required media type and set them on the transcode profile. To set the audio attributes properly, create a new attribute store and copy the attribute store from the required media media type by calling [IMFAttributes::CopyAllItems](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfattributes-copyallitems). This makes sure that the caller does not hold the references to the media type retrieved from the encoder. For example code, see [MFCreateTranscodeProfile](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-mfcreatetranscodeprofile).

## Parameters

### `pAttrs` [in]

Pointer to the [IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes) interface of an attribute store that contains the configuration settings for the audio stream. The specified attribute values overwrite any existing values stored in the transcode profile.

The following audio attributes can be set:

* [Audio Media Types](https://learn.microsoft.com/windows/desktop/medfound/audio-media-types)
* [MF_TRANSCODE_DONOT_INSERT_ENCODER](https://learn.microsoft.com/windows/desktop/medfound/mf-transcode-donot-insert-encoder)
* [MF_TRANSCODE_ENCODINGPROFILE](https://learn.microsoft.com/windows/desktop/medfound/mf-transcode-encodingprofile)
* [MF_TRANSCODE_QUALITYVSSPEED](https://learn.microsoft.com/windows/desktop/medfound/mf-transcode-qualityvsspeed)

To create the attribute store, call [MFCreateAttributes](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfcreateattributes). To set a specific attribute value in the attribute store, the caller must call the appropriate [IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes) methods depending on the data type of the attribute.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[Attributes in Media Foundation](https://learn.microsoft.com/windows/desktop/medfound/attributes-and-properties)

[IMFTranscodeProfile](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftranscodeprofile)

[Transcode API](https://learn.microsoft.com/windows/desktop/medfound/transcode-api)