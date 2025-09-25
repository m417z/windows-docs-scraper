# IDirectMusicSynth::PlayBuffer

## Description

The `PlayBuffer` method downloads a stream of MIDI messages to the synthesizer.

## Parameters

### `rt`

Specifies the start time of the buffer. This value is specified in REFERENCE_TIME units, relative to the master clock, which was previously set with a call to [IDirectMusicSynth::SetMasterClock](https://learn.microsoft.com/windows/desktop/api/dmusics/nf-dmusics-idirectmusicsynth-setmasterclock). Also, this value should be after the time returned by the clock in [IDirectMusicSynth::GetLatencyClock](https://learn.microsoft.com/windows/desktop/api/dmusics/nf-dmusics-idirectmusicsynth-getlatencyclock).

### `pbBuffer`

Pointer to a memory buffer containing the time-stamped MIDI messages that the **IDirectMusicBuffer** object generates

### `cbBuffer`

Specifies the size of the buffer in bytes.

## Return value

`PlayBuffer` returns S_OK if the call was successful. Otherwise, the method returns an appropriate error code. The following table shows some of the possible return status codes.

| Return code | Description |
| --- | --- |
| **E_POINTER** | Indicates a bad buffer pointer. |
| **DMUS_E_SYNTHNOTCONFIGURED** | Indicates that the synth is not open or not properly configured. |
| **DMUS_E_NOSYNTHSINK** | Indicates that the **IDirectMusicSynthSink** object was not connected. |
| **DMUS_E_SYNTHINACTIVE** | Indicates that the method was called when the synth is inactive, which is not valid. |
| **E_FAIL** | Indicates that the method is unable to queue the messages. |

## Remarks

This is the software synthesizer's implementation of the **IDirectMusicPort::PlayBuffer** method. For details on the buffer format, see the description of **IDirectMusicPort::PlayBuffer** in the Microsoft Windows SDK documentation.

In order to properly associate the time stamp of each MIDI message in the buffer, the synth needs to convert from the REFERENCE_TIME format to its internal sample-based time. Because the wave-output stream is actually managed by [IDirectMusicSynthSink](https://learn.microsoft.com/windows/desktop/api/dmusics/nn-dmusics-idirectmusicsynthsink), the synth calls [IDirectMusicSynthSink::RefTimeToSample](https://learn.microsoft.com/windows/desktop/api/dmusics/nf-dmusics-idirectmusicsynthsink-reftimetosample) for each MIDI message to convert its time stamp into sample time.

Typically, the synthesizer pulls each MIDI message from the buffer, stamps it in sample time, and places it in its own internal queue. The queue is emptied later by the rendering process, which is managed by **IDirectMusicPort::Render** and called by the **IDirectMusicSynthSink** object.

For more information, see the descriptions of the **IDirectMusic**, **IDirectMusicPort**, and **IDirectMusicBuffer** interfaces in the Windows SDK documentation.

## See also

[IDirectMusicSynth::GetLatencyClock](https://learn.microsoft.com/windows/desktop/api/dmusics/nf-dmusics-idirectmusicsynth-getlatencyclock)

[IDirectMusicSynth::Render](https://learn.microsoft.com/windows/desktop/api/dmusics/nf-dmusics-idirectmusicsynth-render)

[IDirectMusicSynth::SetMasterClock](https://learn.microsoft.com/windows/desktop/api/dmusics/nf-dmusics-idirectmusicsynth-setmasterclock)

[IDirectMusicSynthSink](https://learn.microsoft.com/windows/desktop/api/dmusics/nn-dmusics-idirectmusicsynthsink)

[IDirectMusicSynthSink::RefTimeToSample](https://learn.microsoft.com/windows/desktop/api/dmusics/nf-dmusics-idirectmusicsynthsink-reftimetosample)