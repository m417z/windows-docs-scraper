# IMFTranscodeProfile::GetAudioAttributes

## Description

Gets the audio stream settings that are currently set in the transcode profile.

## Parameters

### `ppAttrs` [out]

Receives a pointer to the [IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes) interface of the attribute store containing the current audio stream settings. Caller must release the interface pointer.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If there are no audio attributes set in the transcode profile, the call to **GetAudioAttributes** succeeds and *ppAttrs* receives **NULL**.

To get a specific attribute value, the caller must call the appropriate [IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes) method depending on the data type of the attribute, and specify the attribute name. The following topics describe the audio attributes:

* [Audio Media Types](https://learn.microsoft.com/windows/desktop/medfound/audio-media-types)
* [MF_TRANSCODE_ENCODINGPROFILE](https://learn.microsoft.com/windows/desktop/medfound/mf-transcode-encodingprofile)
* [MF_TRANSCODE_QUALITYVSSPEED](https://learn.microsoft.com/windows/desktop/medfound/mf-transcode-qualityvsspeed)

## See also

[Attributes in Media Foundation](https://learn.microsoft.com/windows/desktop/medfound/attributes-and-properties)

[IMFTranscodeProfile](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftranscodeprofile)

[Transcode API](https://learn.microsoft.com/windows/desktop/medfound/transcode-api)