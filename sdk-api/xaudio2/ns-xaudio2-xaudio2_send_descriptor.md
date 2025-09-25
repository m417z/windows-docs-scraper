# XAUDIO2_SEND_DESCRIPTOR structure

## Description

Defines a destination voice that is the target of a send from another voice and specifies whether a filter should be used.

## Members

### `Flags`

Indicates whether a filter should be used on data sent to the voice pointed to by **pOutputVoice**. Flags can be 0 or XAUDIO2_SEND_USEFILTER.

### `pOutputVoice`

A pointer to an [IXAudio2Voice](https://learn.microsoft.com/windows/desktop/api/xaudio2/nn-xaudio2-ixaudio2voice) that will be the target of the send. The **pOutputVoice** member cannot be NULL.

## Remarks

### Platform Requirements

Windows 10 (XAudio2.9); Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[How to: Change Voice Volume](https://learn.microsoft.com/windows/desktop/xaudio2/how-to--change-voice-volume)

[How to: Use Submix Voices](https://learn.microsoft.com/windows/desktop/xaudio2/how-to--use-submix-voices)

[IXAudio2::CreateSourceVoice](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2-createsourcevoice)

[IXAudio2::CreateSubmixVoice](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2-createsubmixvoice)

[IXAudio2Voice::SetOutputVoices](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2voice-setoutputvoices)

[XAudio Structures](https://learn.microsoft.com/windows/desktop/xaudio2/structures)

[XAudio2 Sample Rate Conversions](https://learn.microsoft.com/windows/desktop/xaudio2/xaudio2-sample-rate-conversions)