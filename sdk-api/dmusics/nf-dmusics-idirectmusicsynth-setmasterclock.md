# IDirectMusicSynth::SetMasterClock

## Description

The `SetMasterClock` method provides the synthesizer with a master time source, which the synthesizer requires to synchronize itself with the rest of DirectMusic.

## Parameters

### `pClock`

Pointer to the master **IReferenceClock** (defined in Microsoft Windows SDK documentation) object, which is used by all devices in the current instance of DirectMusic.

## Return value

`SetMasterClock` returns S_OK if the call was successful. Otherwise, the method returns an appropriate error code. The following table shows some of the possible return status codes.

| Return code | Description |
| --- | --- |
| **E_POINTER** | Indicates a bad interface pointer. |
| **DMUS_E_SYNTHNOTCONFIGURED** | Indicates that the synth is not open or not properly configured. |

## Remarks

The synthesizer wave-output device, which is managed by [IDirectMusicSynthSink](https://learn.microsoft.com/windows/desktop/api/dmusics/nn-dmusics-idirectmusicsynthsink), cannot function until it has received a master clock to synchronize to. It phase locks its own internal clock to the master clock, and is thus able to provide timing information to the synthesizer so it can make sense of the time stamps it receives in the calls to [IDirectMusicSynth::PlayBuffer](https://learn.microsoft.com/windows/desktop/api/dmusics/nf-dmusics-idirectmusicsynth-playbuffer).

In most implementations, `SetMasterClock` does little more than pass the master clock to the **IDirectMusicSynthSink** with a call to [IDirectMusicSynthSink::SetMasterClock](https://learn.microsoft.com/windows/desktop/api/dmusics/nf-dmusics-idirectmusicsynthsink-setmasterclock).

The master clock is very different from the latency clock, which is retrieved from the synth with a call to [IDirectMusicSynth::GetLatencyClock](https://learn.microsoft.com/windows/desktop/api/dmusics/nf-dmusics-idirectmusicsynth-getlatencyclock). While the master clock provides the time base, the latency clock simply tracks the progress of the synthesizer's render engine. This enables the application to know the earliest time that it can submit an event for playback by calling the **PlayBuffer** method. The latency clock is tightly synchronized to the master clock, so its units are relative.

You can measure the latency of the synthesizer by comparing the time of the latency clock with the master clock. Note that the latency clock will have jitter, reflecting the bursts of synthesizer mixing, while the master clock should increment smoothly. Latency should not exceed 450 milliseconds.

For more information, see the description of the **IDirectMusic** interface in the Windows SDK documentation.

The *pClock* parameter follows the [reference-counting conventions for COM objects](https://learn.microsoft.com/windows-hardware/drivers/audio/reference-counting-conventions-for-com-objects).

## See also

[IDirectMusicSynth::GetLatencyClock](https://learn.microsoft.com/windows/desktop/api/dmusics/nf-dmusics-idirectmusicsynth-getlatencyclock)

[IDirectMusicSynth::PlayBuffer](https://learn.microsoft.com/windows/desktop/api/dmusics/nf-dmusics-idirectmusicsynth-playbuffer)

[IDirectMusicSynthSink](https://learn.microsoft.com/windows/desktop/api/dmusics/nn-dmusics-idirectmusicsynthsink)

[IDirectMusicSynthSink::SetMasterClock](https://learn.microsoft.com/windows/desktop/api/dmusics/nf-dmusics-idirectmusicsynthsink-setmasterclock)