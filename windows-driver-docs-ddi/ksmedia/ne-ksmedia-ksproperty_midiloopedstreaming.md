# KSPROPERTY_MIDILOOPEDSTREAMING enumeration

## Description

The **KSPROPERTY_MIDILOOPEDSTREAMING** enumeration defines the properties available for MIDI looped streaming operations, which provide low-latency, high-performance MIDI data streaming capabilities.

## Constants

### `KSPROPERTY_MIDILOOPEDSTREAMING_BUFFER`

Specifies the property used to retrieve information about the looped streaming buffer. This property returns a **[KSMIDILOOPED_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksmidilooped_buffer)** structure containing the buffer address and size. The property request uses a **[KSMIDILOOPED_BUFFER_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksmidilooped_buffer_property)** structure to specify the requested buffer size.

### `KSPROPERTY_MIDILOOPEDSTREAMING_REGISTERS`

Specifies the property used to retrieve pointers to the read and write position registers for the looped streaming buffer. This property returns a **[KSMIDILOOPED_REGISTERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksmidilooped_registers)** structure containing pointers to the position registers that track the current read and write positions within the circular buffer.

### `KSPROPERTY_MIDILOOPEDSTREAMING_NOTIFICATION_EVENT`

Specifies the property used to set event handles for notifications during looped streaming operations. This property accepts a **[KSMIDILOOPED_EVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksmidilooped_event)** structure containing handles to events that will be signaled when read or write operations are completed.

## Remarks

The **KSPROPSETID_MidiLoopedStreaming** property set uses these enumeration values to identify specific properties related to MIDI looped streaming operations. Looped streaming provides a mechanism for low-latency MIDI data processing by establishing a circular buffer that is shared between the driver and client application.

The typical sequence for setting up looped streaming is:

1. Use **KSPROPERTY_MIDILOOPEDSTREAMING_BUFFER** to allocate and retrieve buffer information
1. Use **KSPROPERTY_MIDILOOPEDSTREAMING_REGISTERS** to obtain access to position tracking registers
1. Use **KSPROPERTY_MIDILOOPEDSTREAMING_NOTIFICATION_EVENT** to configure event-based notifications

This mechanism enables high-performance MIDI applications to achieve very low latency by providing direct access to the streaming buffer and position registers.

## See also

- **[KSMIDILOOPED_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksmidilooped_buffer)**
- **[KSMIDILOOPED_BUFFER_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksmidilooped_buffer_property)**
- **[KSMIDILOOPED_REGISTERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksmidilooped_registers)**
- **[KSMIDILOOPED_EVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksmidilooped_event)**