# IDirectMusicSynthSink::GetLatencyClock

## Description

The `GetLatencyClock` method retrieves the latency clock, which measures the progress of the output audio stream.

## Parameters

### `ppClock`

Output pointer for the latency clock. This parameter points to a caller-allocated pointer variable into which the method writes a pointer to the latency-clock object's **IReferenceClock** interface (described in the Microsoft Windows SDK documentation).

## Return value

`GetLatencyClock` returns S_OK if the call was successful. Otherwise, the method returns an appropriate error code. The following table shows some of the possible return status codes.

| Return code | Description |
| --- | --- |
| **E_FAIL** | Indicates that the method is unable to access latency clock. |

## Remarks

The latency **IReferenceClock** returns the current render time whenever its **IReferenceClock::GetTime** method is called. This time is always relative to the time established by the master clock, installed in the synth sink by using [IDirectMusicSynthSink::SetMasterClock](https://learn.microsoft.com/windows/desktop/api/dmusics/nf-dmusics-idirectmusicsynthsink-setmasterclock). The latency time is used by the performance layer of DirectMusic to identify the next available time to start playing a note.

The *ppClock* parameter follows the [reference-counting conventions for COM objects](https://learn.microsoft.com/windows-hardware/drivers/audio/reference-counting-conventions-for-com-objects).

For more information about latency clocks, see [Synthesizer Latency](https://learn.microsoft.com/windows-hardware/drivers/audio/synthesizer-latency). Also see the descriptions of the **IReferenceClock** and **IDirectMusic** interfaces in the Microsoft Windows SDK documentation.

## See also

[IDirectMusicSynth](https://learn.microsoft.com/windows/desktop/api/dmusics/nn-dmusics-idirectmusicsynth)

[IDirectMusicSynth::SetMasterClock](https://learn.microsoft.com/windows/desktop/api/dmusics/nf-dmusics-idirectmusicsynth-setmasterclock)