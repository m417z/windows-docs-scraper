# KSMIDILOOPED_REGISTERS structure

## Description

The **KSMIDILOOPED_REGISTERS** structure contains pointers to the read and write position registers for MIDI looped streaming operations.

## Members

### `WritePosition`

Pointer to a ULONG value that indicates the current write position within the looped streaming buffer, in bytes. The driver updates this register as it places new MIDI data into the buffer.

### `ReadPosition`

Pointer to a ULONG value that indicates the current read position within the looped streaming buffer, in bytes. The client updates this register as it consumes data from the buffer.

## Remarks

This structure is returned by the **[KSPROPERTY_MIDILOOPEDSTREAMING_REGISTERS](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-midiloopedstreaming-registers)** property and provides direct access to the position registers used in MIDI looped streaming. These registers enable efficient, lock-free communication between the driver and client application by providing a way to track the current read and write positions in the circular buffer.

The position registers are typically mapped into both the driver's and client's address spaces, allowing for high-performance, low-latency MIDI data streaming. The client reads from **ReadPosition** to **WritePosition**, while the driver writes from **WritePosition** onwards, wrapping around to the beginning of the buffer as needed.

Both positions are byte offsets from the beginning of the looped streaming buffer and should be accessed atomically to ensure consistency.

### Code sample

```cpp
HRESULT
    LoopedBufferCall(
        _In_ ULONG& bufferSize
    )
    {
        KSMIDILOOPED_BUFFER_PROPERTY property {0};
        KSMIDILOOPED_BUFFER buffer{0};
        ULONG propertySize {sizeof(property)};

        property.Property.Set           = KSPROPSETID_MidiLoopedStreaming;
        property.Property.Id            = KSPROPERTY_MIDILOOPEDSTREAMING_BUFFER;
        property.Property.Flags         = KSPROPERTY_TYPE_GET;
        property.RequestedBufferSize    = bufferSize;

        RETURN_IF_FAILED(SyncIoctl(
            m_Pin.get(),
            IOCTL_KS_PROPERTY,
            &property,
            propertySize,
            &buffer,
            sizeof(buffer),
            nullptr));

        bufferSize = buffer.ActualBufferSize;

        return S_OK;
    }
```

## See also

- **[KSPROPERTY_MIDILOOPEDSTREAMING_REGISTERS](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-midiloopedstreaming-registers)**
- **[KSMIDILOOPED_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksmidilooped_buffer)**
- **[KSMIDILOOPED_EVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksmidilooped_event)**
- **[KSPROPERTY_MIDILOOPEDSTREAMING](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ne-ksmedia-ksproperty_midiloopedstreaming)**