# IDirectMusicSynthSink::Activate

## Description

The `Activate` method activates or deactivates the synthesizer sink.

## Parameters

### `fEnable`

Specifies whether to activate the synth sink. If **TRUE**, the method activates the synth sink. If **FALSE**, it deactivates it.

## Return value

`Activate` returns S_OK if the call was successful. Otherwise, the method returns an appropriate error code. The following table shows some of the possible return status codes.

| Return code | Description |
| --- | --- |
| **E_FAIL** | Indicates that the method is unable to activate or deactivate the synth sink. |
| **DMUS_E_SYNTHNOTCONFIGURED** | Indicates that the synth is not set or not properly configured. |
| **DMUS_E_SYNTHACTIVE** | Indicates that the sink is already active. |
| **DMUS_E_DSOUND_NOT_SET** | Indicates that **SetDirectSound** hasn't been called successfully. |
| **DMUS_E_NO_MASTER_CLOCK** | Indicates that **SetMasterClock** hasn't been called successfully. |

## Remarks

The synthesizer itself can be told to enable or disable the audio device. In turn, it calls the synth sink, which manages the audio device. This gives the application the ability to manage its use of resources. When it is not playing music, it can deactivate the sink to free the wave-output device for other applications.

For more information, see the description of the **IDirectMusic** interface in the Microsoft Windows SDK documentation.

## See also

[IDirectMusicSynth](https://learn.microsoft.com/windows/desktop/api/dmusics/nn-dmusics-idirectmusicsynth)

[IDirectMusicSynth::Activate](https://learn.microsoft.com/windows/desktop/api/dmusics/nf-dmusics-idirectmusicsynth-activate)