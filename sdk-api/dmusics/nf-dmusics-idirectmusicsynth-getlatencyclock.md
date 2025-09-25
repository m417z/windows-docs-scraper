# IDirectMusicSynth::GetLatencyClock

## Description

The `GetLatencyClock` method retrieves a reference to the **IReferenceClock** interface (described in the Microsoft Windows SDK documentation) of the reference-clock object that tracks the current mix time.

## Parameters

### `ppClock`

Output pointer for the latency clock. This parameter points to a caller-allocated pointer variable into which the method writes a pointer to the latency-clock object's **IReferenceClock** interface. Through this interface, the synthesizer is able to get the current mix time. Specify a valid, non-NULL pointer value for this parameter.

## Return value

`GetLatencyClock` returns S_OK if the call was successful. Otherwise, the method returns an appropriate error code. The following table shows some of the possible return status codes.

| Return code | Description |
| --- | --- |
| **E_FAIL** | Indicates that the method was unable to access the latency clock. |
| **E_POINTER** | Indicates that the *ppClock* pointer is not valid. |
| **DMUS_E_NOSYNTHSINK** | Indicates that the **IDirectMusicSynthSink** object was not connected. |
| **DMUS_E_SYNTHNOTCONFIGURED** | Indicates that the synth is not open or is not properly configured. |

## Remarks

This method returns the latency clock created by the wave sink ([IDirectMusicSynthSink](https://learn.microsoft.com/windows/desktop/api/dmusics/nn-dmusics-idirectmusicsynthsink)) object, which handles the output audio stream. The latency clock returns the current render time whenever its **IReferenceClock::GetTime** method is called. This time is always relative to the time established by the master clock (installed in the synthesizer and wave sink through a call to [IDirectMusicSynth::SetMasterClock](https://learn.microsoft.com/windows/desktop/api/dmusics/nf-dmusics-idirectmusicsynth-setmasterclock) and [IDirectMusicSynthSink::SetMasterClock](https://learn.microsoft.com/windows/desktop/api/dmusics/nf-dmusics-idirectmusicsynthsink-setmasterclock)). The latency time is used by the performance to identify the next available time to start playing a note. The latency should not exceed 450 milliseconds.

For more information about latency clocks, see [Synthesizer Latency](https://learn.microsoft.com/windows-hardware/drivers/audio/synthesizer-latency). Also see the description of the **IDirectMusic** and **IReferenceClock** interfaces in the Windows SDK documentation.

The *ppClock* parameter follows the [reference-counting conventions for COM objects](https://learn.microsoft.com/windows-hardware/drivers/audio/reference-counting-conventions-for-com-objects).

## See also

[IDirectMusicSynth::SetMasterClock](https://learn.microsoft.com/windows/desktop/api/dmusics/nf-dmusics-idirectmusicsynth-setmasterclock)

[IDirectMusicSynthSink](https://learn.microsoft.com/windows/desktop/api/dmusics/nn-dmusics-idirectmusicsynthsink)

[IDirectMusicSynthSink::SetMasterClock](https://learn.microsoft.com/windows/desktop/api/dmusics/nf-dmusics-idirectmusicsynthsink-setmasterclock)