# IDirectMusicSynth::Activate

## Description

The `Activate` method enables or disables the audio device under program control.

## Parameters

### `fEnable`

Specifies whether to enable or disable the audio device. If **TRUE**, the method enables the device. If **FALSE**, the method disables it.

## Return value

`Activate` returns S_OK if the call was successful. Otherwise, the method returns an appropriate error code. The following table shows some of the possible return status codes.

| Return code | Description |
| --- | --- |
| **S_FALSE** | Indicates audio device is already inactive. |
| **E_FAIL** | Indicates that the request failed. |
| **E_OUTOFMEMORY** | Indicates that not enough memory is available to load the device. |
| **DMUS_E_SYNTHNOTCONFIGURED** | Indicates that the synth is not opened or not properly configured. |
| **DMUS_E_NOSYNTHSINK** | Indicates that the **IDirectMusicSynthSink** object was not connected. |
| **DMUS_E_SYNTHACTIVE** | Indicates that the synth is already active. |

## Remarks

By enabling or disabling the audio device under program control, `Activate` gives the application the ability to manage its use of resources. When not playing music, the application can deactivate the wave-output resource, which frees it for other applications to use.

The wave-output resource is actually managed by a separate COM object, which has a [IDirectMusicSynthSink](https://learn.microsoft.com/windows/desktop/api/dmusics/nn-dmusics-idirectmusicsynthsink) interface. This object must first be connected with a call to **SetSynthSink**. Otherwise, the synthesizer will fail the `Activate` call with DMUS_E_NOSYNTHSINK.

Activation is mostly managed by the wave sink object. When `IDirectMusicSynth::Activate` is called, the synth sets its internal activation state and calls [IDirectMusicSynthSink::Activate](https://learn.microsoft.com/windows/desktop/api/dmusics/nf-dmusics-idirectmusicsynthsink-activate) to enable or disable the wave output.

## See also

[IDirectMusicSynth::Open](https://learn.microsoft.com/windows/desktop/api/dmusics/nf-dmusics-idirectmusicsynth-open)

[IDirectMusicSynthSink::Activate](https://learn.microsoft.com/windows/desktop/api/dmusics/nf-dmusics-idirectmusicsynthsink-activate)