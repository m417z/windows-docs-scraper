# XAUDIO2_VOICE_SENDS structure

## Description

Defines a set of voices to receive data from a single output voice.

## Members

### `SendCount`

Number of voices to receive the output of the voice. An **OutputCount** value of 0 indicates the voice should not send output to any voices.

### `pSends`

Array of [XAUDIO2_SEND_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/xaudio2/ns-xaudio2-xaudio2_send_descriptor) structures describing destination voices and the filters that should be used when sending to the voices. This array should contain **SendCount** elements. If **SendCount** is 0 **pSends** should be NULL. Note that **pSends** cannot contain the same voice more than once.

## Remarks

If **pSends** is not NULL all of its elements must be non-NULL. To send output to the default mastering voice call [IXAudio2Voice::SetOutputVoices](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2voice-setoutputvoices) with the pSendList argument set to NULL.

Setting **SendCount** to 0 is useful for certain effects such as volume meters or file writers that don't generate any audio output to pass on to another voice.

If needed, a voice will perform a single sample rate conversion, from the voice's input sample rate to the input sample rate of the voice's output voices. Because only one sample rate conversion will be performed, all the voice's output voices must have the same input sample rate. If the input sample rates of the voice and its output voices are the same, no sample rate conversion is performed.

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