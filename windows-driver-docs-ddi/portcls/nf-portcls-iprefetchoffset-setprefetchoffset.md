# IPreFetchOffset::SetPreFetchOffset

## Description

The `SetPreFetchOffset` method sets the prefetch offset, which is the number of bytes of data separating the write cursor from the play cursor in a DirectSound output stream.

## Parameters

### `PreFetchOffset` [in]

Specifies the prefetch offset size in bytes.

## Remarks

A WavePci miniport driver calls the `SetPreFetchOffset` method to specify the prefetch offset of a hardware-accelerated DirectSound output stream.

The prefetch offset is the number of bytes of data separating the write cursor from the play cursor in the audio device's hardware buffer:

* The write cursor specifies the buffer position into which a DirectSound application can safely write the next sound sample.
* The play cursor specifies the buffer position of the sound sample that is currently being played by the audio device.

For more information about write cursors and play cursors, see [KSAUDIO_POSITION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksaudio_position).

For information about using `SetPreFetchOffset` to control a DirectSound stream's prefetch offset, see [Prefetch Offsets](https://learn.microsoft.com/windows-hardware/drivers/audio/prefetch-offsets).

## See also

[IMiniportWavePciStream::GetPosition](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iminiportwavepcistream-getposition)

[IPortWavePciStream::GetMapping](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iportwavepcistream-getmapping)

[IPreFetchOffset](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iprefetchoffset)

[KSAUDIO_POSITION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksaudio_position)

[KSPROPERTY_AUDIO_POSITION](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-audio-position)