# IMFTranscodeSinkInfoProvider::SetProfile

## Description

Sets the transcoding profile on the transcode sink activation object.

## Parameters

### `pProfile` [in]

A pointer to the [IMFTranscodeProfile](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftranscodeprofile) interface. To get a pointer to this interface, call [MFCreateTranscodeProfile](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-mfcreatetranscodeprofile).

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Before calling this method, initialize the profile object as follows:

* Set the [MF_TRANSCODE_CONTAINERTYPE](https://learn.microsoft.com/windows/desktop/medfound/mf-transcode-containertype) attribute to specify the container type of the output file.
* If the output file will have a video stream, set video attributes by calling the [IMFTranscodeProfile::SetVideoAttributes](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imftranscodeprofile-setvideoattributes) method.
* If the output file will have an audio stream, set audio attributes by calling the [IMFTranscodeProfile::SetAudioAttributes](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imftranscodeprofile-setaudioattributes) method.

## See also

[IMFTranscodeSinkInfoProvider](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftranscodesinkinfoprovider)