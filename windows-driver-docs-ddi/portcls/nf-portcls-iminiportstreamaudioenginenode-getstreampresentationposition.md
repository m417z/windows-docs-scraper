# IMiniportStreamAudioEngineNode::GetStreamPresentationPosition

## Description

Gets the current cursor position in the audio data stream that is being rendered to the endpoint.

## Parameters

### `pPresentationPosition` [out]

A [KSAUDIO_PRESENTATION_POSITION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksaudio_presentation_position) structure that represents the current cursor position in the audio data stream.

## Return value

**GetStreamPresentationPosition** returns S_OK, if the call was successful. Otherwise, the method returns an appropriate error

code.

## See also

[IMiniportStreamAudioEngineNode](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iminiportstreamaudioenginenode)

[KSAUDIO_PRESENTATION_POSITION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksaudio_presentation_position)