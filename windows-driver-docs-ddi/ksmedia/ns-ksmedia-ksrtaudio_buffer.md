# KSRTAUDIO_BUFFER structure

## Description

The KSRTAUDIO_BUFFER structure specifies the buffer address, size, and a call memory barrier flag for a cyclic audio data buffer.

## Members

### `BufferAddress`

Specifies the base address of the cyclic buffer. This is a virtual memory address through which the user-mode client can directly access the buffer. The driver writes the actual base address of the allocated buffer into this member.

### `ActualBufferSize`

Specifies the buffer size, in bytes. The driver sets this member to the actual size of the allocated buffer.

### `CallMemoryBarrier`

Specifies a flag based on cache type of the allocated buffer. The driver sets this flag to **TRUE** if the cache type is **MmWriteCombined**; otherwise, the flag should be set to **FALSE**. For more information about **MmWriteCombined**, see [MEMORY_CACHING_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_memory_caching_type) ,

## Remarks

The [KSPROPERTY_RTAUDIO_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-rtaudio-buffer) request uses the KSRTAUDIO_BUFFER structure to describe the actual cyclic buffer that the driver allocates. This client fills in a [KSRTAUDIO_BUFFER_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/audio/ksrtaudio-buffer-property) structure to request the audio buffer, and the driver fills in a KSRTAUDIO_BUFFER structure with the results from the buffer allocation.

## See also

[KSPROPERTY_RTAUDIO_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-rtaudio-buffer)

[KSRTAUDIO_BUFFER_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/audio/ksrtaudio-buffer-property)

[MEMORY_CACHING_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_memory_caching_type)