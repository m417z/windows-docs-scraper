# IMiniportWaveRTStream::FreeAudioBuffer

## Description

The FreeAudioBuffer method is used to free an audio buffer previously allocated with a call to IMiniportWaveRTStream::AllocateAudioBuffer.

## Parameters

### `AudioBufferMdl`

Specifies a memory descriptor list (MDL) previously allocated with a call to IMiniportWaveRTStream::AllocateAudioBuffer.

### `BufferSize`

Output pointer for the number of bytes that the method has written to the Attributes buffer. This parameter points to a ULONG variable into which the method writes the byte count.

## Remarks

## See also

[IMiniPortWaveRTStream](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iminiportwavertstream)