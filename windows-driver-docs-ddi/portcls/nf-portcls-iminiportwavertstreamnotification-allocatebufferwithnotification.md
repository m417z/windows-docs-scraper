# IMiniportWaveRTStreamNotification::AllocateBufferWithNotification

## Description

The `AllocateAudioBufferWithNotification` method allocates a cyclic buffer for audio data when you want to implement DMA-driven event notification. If you do not want event notification, you must use **IMiniportWaveRTStream::AllocateAudioBuffer**.

## Parameters

### `NotificationCount` [in]

Specifies the number of notifications wanted per buffer cycle. Valid values are 1 or 2, where 1 indicates a single notification at the end of the cyclic buffer and 2 indicates two notifications per buffer cycle, one at the mid-point of the buffer and one at the end.

### `RequestedSize` [in]

Specifies the requested size, in bytes, of the audio buffer.

### `AudioBufferMdl` [out]

Output pointer for a memory descriptor list ([MDL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_mdl)) that describes the audio buffer. This parameter points to a caller-allocated pointer variable into which the method writes a pointer to the MDL.

### `ActualSize` [out]

Output pointer for the actual size, in bytes, of the allocated buffer. This parameter points to a ULONG variable into which the method writes the size value.

### `OffsetFromFirstPage` [out]

Output pointer for the offset (in bytes) of the buffer, from the start of the first page in the MDL. This parameter points to a caller-allocated ULONG variable into which the method writes the offset value.

### `CacheType` [out]

Specifies the type of caching that the client requests for the audio buffer. This parameter is a [MEMORY_CACHING_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_memory_caching_type) enumeration value

## Return value

`AllocateBufferWithNotification` returns STATUS_SUCCESS if the call was successful. Otherwise, the method returns an appropriate error status code. The following table shows some of the possible error status codes.

| Return code | Description |
| --- | --- |
| **STATUS_UNSUCCESSFUL** | The driver does not support the specified combination of buffer attributes. |
| **STATUS_INSUFFICIENT_RESOURCES** | There is insufficient memory available to allocate the buffer. |
| **STATUS_DEVICE_NOT_READY** | The device is not ready. |

## Remarks

**Note** Miniports for Intel High Definition Audio Codecs must specify a CacheType of MmWriteCombined to ensure cache coherency. This is because the Intel High Definition Audio Controller may be configured for non-snoop operation.

After receiving a [KSPROPERTY_RTAUDIO_BUFFER_WITH_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-rtaudio-buffer-with-notification) request from the client, the port driver calls the `AllocateBufferWithNotification` method to allocate a cyclic buffer that the port driver can later map to the virtual address space of the client. `AllocateBufferWithNotification` operates in a manner similar to [IMiniportWaveRTStream::AllocateAudioBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iminiportwavertstream-allocateaudiobuffer). Additionally, `AllocateBufferWithNotification` identifies to the WaveRT port driver that DMA-driven event notification is wanted, and it specifies how many notifications per cycle of the cyclic buffer are needed.

## See also

[IMiniportWaveRTStream::AllocateAudioBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iminiportwavertstream-allocateaudiobuffer)

[IMiniportWaveRTStreamNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iminiportwavertstreamnotification)

[KSPROPERTY_RTAUDIO_BUFFER_WITH_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-rtaudio-buffer-with-notification)

[MDL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_mdl)

[MEMORY_CACHING_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_memory_caching_type)