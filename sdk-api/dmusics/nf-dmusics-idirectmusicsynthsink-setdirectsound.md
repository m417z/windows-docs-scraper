# IDirectMusicSynthSink::SetDirectSound

## Description

The `SetDirectSound` method connects the synthesizer sink with an existing DirectSound object and a DirectSound buffer.

## Parameters

### `pDirectSound`

Pointer to an **IDirectSound** object that the sink is to be associated with. This parameter is set to a valid, non-**NULL** pointer value.

### `pDirectSoundBuffer`

Pointer to the **IDirectSoundBuffer** object that the sink is to be associated with. This parameter can be **NULL**. For more information, see the following Remarks section.

## Return value

`SetDirectSound` returns S_OK if the call was successful. Otherwise, the method returns an appropriate error code. The following table shows some of the possible return status codes.

| Return code | Description |
| --- | --- |
| **DMUS_E_SYNTHNOTCONFIGURED** | Indicates that the synth not set. |
| **DMUS_E_SYNTHACTIVE** | Indicates that the sink is active. |

## Remarks

The *pDirectSound* parameter points to an **IDirectSound** instance that is received from `IDirectMusicPort::SetDirectSound` and is non-**NULL**.

If *pDirectSoundBuffer* is **NULL**, the primary buffer for **IDirectSound** will be upgraded, if necessary, to support the sample rate and channel information for the sink (obtained from [IDirectMusicSynth::GetFormat](https://learn.microsoft.com/windows/desktop/api/dmusics/nf-dmusics-idirectmusicsynth-getformat)).

The **IDirectSoundBuffer** should be a secondary streaming buffer with a format that matches the format obtained from the synthesizer. If *pDirectSoundBuffer* is **NULL**, then an appropriate **IDirectSoundBuffer** instance will be created internally.

Neither the **IDirectSound** nor the **IDirectSoundBuffer** instance can be changed once the sink has been activated.

The *pDirectSound* and *pDirectSoundBuffer* parameters follow the [reference-counting conventions for COM objects](https://learn.microsoft.com/windows-hardware/drivers/audio/reference-counting-conventions-for-com-objects).

For more information, see the description of the **IDirectSound**, **IDirectSoundBuffer**, and **IDirectMusicPort** interfaces in the Microsoft Windows SDK documentation.

## See also

[IDirectMusicSynth::GetFormat](https://learn.microsoft.com/windows/desktop/api/dmusics/nf-dmusics-idirectmusicsynth-getformat)