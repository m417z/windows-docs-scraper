# IDirectMusicSynthSink::Init

## Description

The `Init` method initializes the synth-sink object.

## Parameters

### `pSynth`

Pointer to the synth object that the synth-sink object is to connect to. This parameter is a valid, non-NULL pointer to a [IDirectMusicSynth](https://learn.microsoft.com/windows/desktop/api/dmusics/nn-dmusics-idirectmusicsynth) object.

## Return value

`Init` returns S_OK if the call is successful. Otherwise, the method returns an appropriate error code.

## Remarks

When a synthesizer is connected to a synth sink by a call to [IDirectMusicSynth::SetSynthSink](https://learn.microsoft.com/windows/desktop/api/dmusics/nf-dmusics-idirectmusicsynth-setsynthsink), the synthesizer calls the synth sink's `Init` method.

In order to avoid cyclical references, the **IDirectMusicSynthSink** does not increment the reference count of the [IDirectMusicSynth](https://learn.microsoft.com/windows/desktop/api/dmusics/nn-dmusics-idirectmusicsynth) synth object. Instead, it abides by the rule that **IDirectMusicSynth** object is always the parent and always releases the **IDirectMusicSynthSink** object when it is done with it.

Once connected, the synth sink needs to be activated with a call to [IDirectMusicSynthSink::Activate](https://learn.microsoft.com/windows/desktop/api/dmusics/nf-dmusics-idirectmusicsynthsink-activate). At this point it starts generating wave buffers, which it passes to the synthesizer by calling [IDirectMusicSynth::Render](https://learn.microsoft.com/windows/desktop/api/dmusics/nf-dmusics-idirectmusicsynth-render).

The *pSynth* parameter follows the [reference-counting conventions for COM objects](https://learn.microsoft.com/windows-hardware/drivers/audio/reference-counting-conventions-for-com-objects).

For more information, see [Synthesizers and Wave Sinks](https://learn.microsoft.com/windows-hardware/drivers/audio/synthesizers-and-wave-sinks). Also see the description of the **IDirectMusic** interface in the Microsoft Windows SDK documentation.

## See also

[IDirectMusicSynth](https://learn.microsoft.com/windows/desktop/api/dmusics/nn-dmusics-idirectmusicsynth)

[IDirectMusicSynth::Activate](https://learn.microsoft.com/windows/desktop/api/dmusics/nf-dmusics-idirectmusicsynth-activate)

[IDirectMusicSynth::Render](https://learn.microsoft.com/windows/desktop/api/dmusics/nf-dmusics-idirectmusicsynth-render)

[IDirectMusicSynth::SetSynthSink](https://learn.microsoft.com/windows/desktop/api/dmusics/nf-dmusics-idirectmusicsynth-setsynthsink)

[IDirectMusicSynthSink::Activate](https://learn.microsoft.com/windows/desktop/api/dmusics/nf-dmusics-idirectmusicsynthsink-activate)