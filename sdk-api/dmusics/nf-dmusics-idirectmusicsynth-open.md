# IDirectMusicSynth::Open

## Description

The `Open` method opens a DirectMusic synthesizer "port".

## Parameters

### `pPortParams`

Pointer to a DMUS_PORTPARAMS structure (described in the Microsoft Windows SDK documentation) specifying a set of options for opening the DirectMusic "port". The structure contains setup parameters for the port, including sample rate, stereo mode, and number of voices. If this parameter is set to **NULL**, default settings are used.

## Return value

`Open` returns S_OK if the call was successful. Otherwise, the method returns an appropriate error code. The following table shows some of the possible return status codes.

| Return code | Description |
| --- | --- |
| **E_POINTER** | Indicates a bad pointer was passed in *pPortParams*. |
| **DMUS_E_ALREADYOPEN** | Indicates that the port was already opened. |
| **DMUS_E_NOSYNTHSINK** | Indicates that no sink is available for output. |

## Remarks

The DirectMusic synthesizer "port" can be opened only once. A second attempt to open the port will fail.

However, DirectMusic does support multiple instances of a synthesizer port. It does this by calling **CoCreateInstance** (described in the Windows SDK documentation) to create multiple **IDirectMusicSynth** objects.

The port is valid until it is closed by the [IDirectMusicSynth::Close](https://learn.microsoft.com/windows/desktop/api/dmusics/nf-dmusics-idirectmusicsynth-close) method.

When opening the port, some of the parameters asked for in DMUS_PORTPARAMS might not be supported or the port might "upgrade" a parameter request (that is, return the maximum number of voices supported instead of just what was asked for). In either of these cases, the Microsoft Software Synthesizer will return S_FALSE and modify DMUS_PORTPARAMS accordingly, to show what is actually supported. Custom synths should emulate this behavior to ensure compatibility with existing code.

Opening a port is not enough to enable the synthesizer. The synthesizer is enabled by opening the port and enabling audio output through [IDirectMusicSynth::Activate](https://learn.microsoft.com/windows/desktop/api/dmusics/nf-dmusics-idirectmusicsynth-activate).

Avoid confusing the term DirectMusic "port" with a DMus port driver. A DirectMusic port corresponds to a render or capture pin on a DirectMusic filter. For more information about DirectMusic ports, see the description of the **IDirectMusicPort** interface in the Windows SDK documentation.

## See also

[IDirectMusicSynth::Activate](https://learn.microsoft.com/windows/desktop/api/dmusics/nf-dmusics-idirectmusicsynth-activate)

[IDirectMusicSynth::Close](https://learn.microsoft.com/windows/desktop/api/dmusics/nf-dmusics-idirectmusicsynth-close)

[IDirectMusicSynth::Download](https://learn.microsoft.com/windows/desktop/api/dmusics/nf-dmusics-idirectmusicsynth-download)

[IDirectMusicSynth::PlayBuffer](https://learn.microsoft.com/windows/desktop/api/dmusics/nf-dmusics-idirectmusicsynth-playbuffer)

[IDirectMusicSynth::Unload](https://learn.microsoft.com/windows/desktop/api/dmusics/nf-dmusics-idirectmusicsynth-unload)

[IDirectMusicSynthSink](https://learn.microsoft.com/windows/desktop/api/dmusics/nn-dmusics-idirectmusicsynthsink)