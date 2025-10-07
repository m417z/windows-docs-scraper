# KSRTAUDIO\_BUFFER\_PROPERTY structure

The KSRTAUDIO\_BUFFER\_PROPERTY structure appends a buffer base address and requested buffer size to a [**KSPROPERTY**](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure) structure. This structure is used by the client to request allocation of the audio buffer via [**KSPROPERTY\_RTAUDIO\_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-rtaudio-buffer).

## Members

**Property**
A KSPROPERTY structure that the client initializes appropriately prior to calling KSPROPERTY\_RTAUDIO\_BUFFER.

**BaseAddress**
Specifies the desired buffer base address. Unless the client specifies a base address, this parameter is set to **NULL**.

**RequestedBufferSize**
Specifies the desired buffer size in bytes. The driver returns the actual size of the allocated buffer in the [**KSRTAUDIO\_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksrtaudio_buffer) structure that it returns.

## Remarks

The KSPROPERTY\_RTAUDIO\_BUFFER request uses the KSRTAUDIO\_BUFFER\_PROPERTY structure to describe the cyclic buffer that the client requests. The driver returns a KSRTAUDIO\_BUFFER structure to describe the buffer that was actually allocated.

The value that the client writes into the **RequestedBufferSize** member is not binding on the driver. However, the driver must specify a buffer size that is as close as possible to the requested size, taking into account the buffer size constraints on the driver itself. The driver allocates a buffer of a different size if the hardware cannot handle the requested size or the system is low on memory. For example, a driver allocates a buffer no smaller than a memory page, or it rounds the buffer size down to the next whole sample block. Also, if the system is running low on memory, the driver allocates a buffer that is smaller than the requested size.

## Requirements

|  |  |
| --- | --- |
| Version | Available in Windows Vista and later Windows operating systems. |
| Header | Ksmedia.h |