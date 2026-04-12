# KSMIDILOOPED_BUFFER structure

## Description

The **KSMIDILOOPED_BUFFER** structure describes the buffer information returned by the [KSPROPERTY_MIDILOOPEDSTREAMING_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-midiloopedstreaming-buffer) property. It contains a pointer to the cross process memory buffer mapped into the callers process space, along with the size of the buffer allocated.

## Members

### `BufferAddress`

Specifies the virtual address of the looped streaming buffer. This is the memory location where MIDI data is stored for cyclic processing.

### `ActualBufferSize`

Specifies the actual size of the allocated looped streaming buffer, in bytes. This may differ from the requested buffer size due to system constraints or alignment requirements.

## Remarks

This structure is used with the **KSPROPERTY_MIDILOOPEDSTREAMING_BUFFER** property to retrieve information about the cyclic buffer used for MIDI looped streaming. The looped streaming mechanism allows for efficient, low-latency MIDI data processing by providing a circular buffer that can be accessed by both the driver and client applications.

The buffer address returned in *BufferAddress* is typically mapped into the client process's address space to allow direct access to the MIDI data stream.

The *ActualBufferSize* value may differ from the requested size due to hardware or alignment requirements.

## See also

- **[KSMIDILOOPED_BUFFER_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksmidilooped_buffer_property)**
- **[KSMIDILOOPED_REGISTERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksmidilooped_registers)**
- **[KSMIDILOOPED_EVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksmidilooped_event)**
- **[KSPROPERTY_MIDILOOPEDSTREAMING](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ne-ksmedia-ksproperty_midiloopedstreaming)**