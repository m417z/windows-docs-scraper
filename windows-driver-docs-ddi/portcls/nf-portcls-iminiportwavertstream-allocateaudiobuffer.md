# IMiniportWaveRTStream::AllocateAudioBuffer

## Description

The AllocateAudioBuffer method allocates a cyclic buffer for audio data.

## Parameters

### `RequestedSize`

Specifies the requested size, in bytes, of the audio buffer.

### `AudioBufferMdl`

Output pointer for a memory descriptor list (MDL) that describes the audio buffer. This parameter points to a caller-allocated pointer variable into which the method writes a pointer to the MDL. For general information about Windows kernel MDLs, see [Using MDLs](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-mdls).

### `ActualSize`

Output pointer for the actual size, in bytes, of the allocated buffer. This parameter points to a ULONG variable into which the method writes the size value.

### `OffsetFromFirstPage`

Output pointer for the buffer's offset, in bytes, from the start of the first page in the MDL. This parameter points to a caller-allocated ULONG variable into which the method writes the offset value.

### `CacheType`

Specifies the type of caching that the client requests for the audio buffer. This parameter is a MEMORY_CACHING_TYPE enumeration value. For more information, see the Remarks section below.

## Return value

This method returns NTSTATUS. AllocateAudioBuffer returns STATUS_SUCCESS if the call was successful. Otherwise, the method returns an appropriate error status code. The following table shows some of the possible error status codes.

| Return code | Description |
| ----------------------------- | --------------------------------------------------------------------------- |
| STATUS_UNSUCCESSFUL | The driver does not support the specified combination of buffer attributes. |
| STATUS_INSUFFICIENT_RESOURCES | Insufficient memory is available to allocate the buffer. |
| STATUS_DEVICE_NOT_READY | The device is not ready. |

## Remarks

Note: Miniports for Intel High Definition Audio Codecs must specify a CacheType of MmWriteCombined to ensure cache coherency. This is because the Intel High Definition Audio Controller may be configured for non-snoop operation.

After receiving a [KSPROPERTY_RTAUDIO_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-rtaudio-buffer) request from the client, the port driver calls the AllocateAudioBuffer method to allocate a cyclic buffer that the port driver can later map to the client's virtual address space.

During the call to AllocateAudioBuffer, the miniport driver allocates the cyclic buffer by calling either IPortWaveRTStream::AllocatePagesForMdl or IPortWaveRTStream::AllocateContiguousPagesForMdl. The miniport driver also programs the audio hardware to play from or record into this buffer, but it does not start the DMA transfers until the port driver calls IMiniportWaveRTStream::SetState with State=KSSTATE_RUN. The output parameters from the AllocateAudioBuffer method include the MDL for the audio buffer, the actual size of the driver-allocated buffer, and the offset of the start of the buffer from the start of the first page in the MDL.

*RequestedSize* is an input parameter that indicates the size that the client is requesting for the audio buffer. ActualSize is an output parameter that indicates the actual size of the audio buffer.

The audio device might require the audio buffer to begin and end on sample boundaries or to meet other types of hardware-dependent alignment constraints. If sufficient memory is available, the actual size of the buffer is the requested size rounded (up or down) to the nearest sample or other hardware-constrained boundary. The actual size must be at least the requested size; otherwise, the Audio Session API (WASAPI) audio engine won't use the buffer, and stream creation will fail.

## See also

[IMiniPortWaveRTStream](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iminiportwavertstream)