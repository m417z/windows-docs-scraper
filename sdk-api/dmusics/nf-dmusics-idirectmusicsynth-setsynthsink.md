# IDirectMusicSynth::SetSynthSink

## Description

The `SetSynthSink` method establishes the connection of the synth to the wave sink.

## Parameters

### `pSynthSink`

Pointer to the synth sink. This parameter either points to the [IDirectMusicSynthSink](https://learn.microsoft.com/windows/desktop/api/dmusics/nn-dmusics-idirectmusicsynthsink) sink object to connect to the synth, or is **NULL** to disconnect the synth from its current synth sink.

## Return value

`SetSynthSink` returns S_OK if the call was successful. Otherwise, the method returns an appropriate error code. The following table shows some of the possible return status codes.

| Return code | Description |
| --- | --- |
| **E_POINTER** | Indicates that a bad pointer was passed in *pSynthSink*. |
| **E_FAIL** | Indicates that the method failed because it was unable to connect to the **IDirectMusicSynthSink** object. |
| **E_OUTOFMEMORY** | Indicates that not enough memory is available to establish the connection. |

## Remarks

Before the synthesizer can expose much of its functionality, it must be connected to a wave sink object, which is represented by the **IDirectMusicSynthSink** interface. The `IDirectMusicSynth::SetSynthSink` method establishes this connection.

The **IDirectMusicSynthSink** object does the work of actually connecting up to the ultimate audio destination, which might be DirectSound, Microsoft Win32 wave audio, or some other audio stream. The default implementation sends data to DirectSound.

This approach allows a synthesizer to connect to many different styles of audio out without special code within the synthesizer itself. This makes it very easy to connect one synthesizer implementation to any available wave-output device.

For more information, see the description of the **IDirectMusic** interface in the Microsoft Windows SDK documentation.

The *pSynthSink* parameter follows the [reference-counting conventions for COM objects](https://learn.microsoft.com/windows-hardware/drivers/audio/reference-counting-conventions-for-com-objects).

## See also

[IDirectMusicSynthSink](https://learn.microsoft.com/windows/desktop/api/dmusics/nn-dmusics-idirectmusicsynthsink)