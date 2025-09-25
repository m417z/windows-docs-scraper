# IDirectMusicSynth::GetRunningStats

## Description

The `GetRunningStats` method retrieves current information about the state of the synthesizer so that an application can tell how the synth is performing.

## Parameters

### `pStats`

Pointer to a DMUS_SYNTHSTATS structure (described in Microsoft Windows SDK documentation). The method writes the synth's statistics into this structure.

## Return value

`GetRunningStats` returns S_OK if the call was successful. Otherwise, the method returns an appropriate error code. The following table shows some of the possible return status codes.

| Return code | Description |
| --- | --- |
| **E_FAIL** | Indicates that the method is unable to get the stats. |
| **E_POINTER** | Indicates a bad *pStats* pointer. |
| **E_NOTIMPL** | Indicates that the synthesizer has not implemented this method (so expect the worst!). |
| **DMUS_E_SYNTHNOTCONFIGURED** | Indicates that the synth is not open or not properly configured. |

## Remarks

The `GetRunningStats` method returns current information about the state of the synthesizer, including CPU loading, peak volume, and how many notes were stolen (from changing priority levels; see [IDirectMusicSynth::SetChannelPriority](https://learn.microsoft.com/windows/desktop/api/dmusics/nf-dmusics-idirectmusicsynth-setchannelpriority)). The method outputs these statistics into a DMUS_SYNTHSTATS structure.

An application can call `GetRunningStats` periodically to get the status of the synthesizer as it runs. All of the running status parameters, with the exception of *dwFreeMemory*, are refreshed every second.

An application typically accesses `GetRunningStats` indirectly by calling **IDirectMusicPort::GetRunningStats**, which is described in the Windows SDK documentation.

## See also

[IDirectMusicSynth::SetChannelPriority](https://learn.microsoft.com/windows/desktop/api/dmusics/nf-dmusics-idirectmusicsynth-setchannelpriority)