# IDirectMusicSynthSink::SetMasterClock

## Description

The `SetMasterClock` method provides the synth sink with a master time source, which is required for synchronization with the rest of DirectMusic.

## Parameters

### `pClock`

Specifies the master clock to synchronize to. This parameter is a pointer to the master-clock object's **IReferenceClock** interface (described in the Microsoft Windows SDK documentation).

## Return value

`SetMasterClock` returns S_OK if the call was successful. Otherwise, the method returns an appropriate error code. The following table shows some of the possible return status codes.

| Return code | Description |
| --- | --- |
| **E_FAIL** | Indicates that the method is unable to accept clock. |

## Remarks

The synth sink cannot function until it has received a master clock to synchronize the streaming wave with the rest of DirectMusic.

Because the master time and sample time might be driven by different crystals, they can drift apart. The synth sink can lock its understanding of the current sample time to the master time with a phase-locked loop.

The master clock is different from the latency clock, which is retrieved from the synth sink with a call to [IDirectMusicSynth::GetLatencyClock](https://learn.microsoft.com/windows/desktop/api/dmusics/nf-dmusics-idirectmusicsynth-getlatencyclock). While the master clock provides the time base, the latency clock simply tracks the progress of the rendering of notes into the wave stream. This enables the application to know the earliest time it can submit a message for playback by using the [IDirectMusicSynth::PlayBuffer](https://learn.microsoft.com/windows/desktop/api/dmusics/nf-dmusics-idirectmusicsynth-playbuffer) method. The latency clock should be tightly synchronized to the master clock, so its units are relative.

You can measure the latency of the synthesizer by comparing the time of the latency clock with that of the master clock. Note that the latency clock will have jitter, reflecting the bursty nature of synthesizer mixing (each call to [IDirectMusicSynth::Render](https://learn.microsoft.com/windows/desktop/api/dmusics/nf-dmusics-idirectmusicsynth-render) jumps forward by the buffer length). In contrast, the master clock increments smoothly.

The *pClock* parameter follows the [reference-counting conventions for COM objects](https://learn.microsoft.com/windows-hardware/drivers/audio/reference-counting-conventions-for-com-objects).

## See also

[IDirectMusicSynth::GetLatencyClock](https://learn.microsoft.com/windows/desktop/api/dmusics/nf-dmusics-idirectmusicsynth-getlatencyclock)

[IDirectMusicSynth::PlayBuffer](https://learn.microsoft.com/windows/desktop/api/dmusics/nf-dmusics-idirectmusicsynth-playbuffer)

[IDirectMusicSynth::Render](https://learn.microsoft.com/windows/desktop/api/dmusics/nf-dmusics-idirectmusicsynth-render)