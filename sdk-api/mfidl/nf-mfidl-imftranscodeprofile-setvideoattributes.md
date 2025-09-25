# IMFTranscodeProfile::SetVideoAttributes

## Description

Sets video stream configuration settings in the transcode profile.

 For example code, see [MFCreateTranscodeProfile](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-mfcreatetranscodeprofile).

## Parameters

### `pAttrs` [in]

Pointer to the [IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes) interface of an attribute store that contains the configuration settings for the video stream. The specified attribute values overwrites any existing values stored in the transcode profile.

The following video attributes can be set:

* [Video Media Types](https://learn.microsoft.com/windows/desktop/medfound/video-media-types)
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