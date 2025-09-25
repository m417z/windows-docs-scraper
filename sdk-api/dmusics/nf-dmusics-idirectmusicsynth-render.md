# IDirectMusicSynth::Render

## Description

The `Render` method is called by the synth sink to render to a buffer in the audio stream.

## Parameters

### `pBuffer`

Pointer to the buffer to write to

### `dwLength`

Specifies the length of the buffer. The buffer length is expressed in samples, not bytes. The size in bytes of the buffer can vary, depending on the buffer's format, which the synth sets in response to an [IDirectMusicSynth::Activate](https://learn.microsoft.com/windows/desktop/api/dmusics/nf-dmusics-idirectmusicsynth-activate) command.

### `llPosition`

Specifies the position in the audio stream. The position is expressed in samples, not bytes. The caller should always increment this value by *dwLength* after each call.

## Return value

`Render` returns S_OK if the call was successful. Otherwise, the method returns an appropriate error code. The following table shows some of the possible return status codes.

| Return code | Description |
| --- | --- |
| **E_FAIL** | Indicates that the method failed. |
| **E_POINTER** | Indicates a bad buffer. |
| **DMUS_E_SYNTHNOTCONFIGURED** | Indicates that the synth is not open or not properly configured. |
| **DMUS_E_SYNTHINACTIVE** | Indicates that the method is not valid when synth is inactive. |

## Remarks

Typically, a synthesizer manages converting messages into rendered wave data in two processes. In the first, it time stamps the MIDI messages it receives from the application via calls to [IDirectMusicSynth::PlayBuffer](https://learn.microsoft.com/windows/desktop/api/dmusics/nf-dmusics-idirectmusicsynth-playbuffer) and places them in its own internal queue. Then, in response to `Render`, the second process generates audio by pulling MIDI messages from the queue and synthesizing the appropriate tones within the time span of the requested render buffer.

As the synthesizer renders the MIDI messages into the buffer, it calls [IDirectMusicSynthSink::RefTimeToSample](https://learn.microsoft.com/windows/desktop/api/dmusics/nf-dmusics-idirectmusicsynthsink-reftimetosample) to translate the MIDI time stamps into sample positions. This guarantees extremely accurate timing (as long as the **IDirectMusicSynthSink** implementation is well written).

For more information, see the description of the **IDirectMusic** interface in the Microsoft Windows SDK documentation.

## See also

[IDirectMusicSynth::Activate](https://learn.microsoft.com/windows/desktop/api/dmusics/nf-dmusics-idirectmusicsynth-activate)

[IDirectMusicSynth::PlayBuffer](https://learn.microsoft.com/windows/desktop/api/dmusics/nf-dmusics-idirectmusicsynth-playbuffer)

[IDirectMusicSynthSink::RefTimeToSample](https://learn.microsoft.com/windows/desktop/api/dmusics/nf-dmusics-idirectmusicsynthsink-reftimetosample)