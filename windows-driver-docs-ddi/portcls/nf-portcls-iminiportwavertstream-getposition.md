# IMiniportWaveRTStream::GetPosition

## Description

The GetPosition method retrieves the current play or record position as a byte offset from the beginning of the buffer.

## Parameters

### `Position`

Pointer to a KSAUDIO_POSITION structure. For a wave rendering stream, the method writes the write position and the play position into this structure. For a wave-capture stream, the method writes the read position and the record position into the structure. Positions are specified as byte offsets from the beginning of the cyclic buffer.

## Return value

This method returns NTSTATUS which contains STATUS_SUCCESS if the call was successful. Otherwise, the function returns an appropriate error status code.

## Remarks

The WaveRT port driver calls this method in response to a KSPROPERTY_AUDIO_POSITION property request from a client.

## See also

[IMiniPortWaveRTStream](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iminiportwavertstream)