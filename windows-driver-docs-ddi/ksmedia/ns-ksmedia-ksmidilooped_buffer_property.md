# KSMIDILOOPED_BUFFER_PROPERTY structure

## Description

The **KSMIDILOOPED_BUFFER_PROPERTY** structure specifies a property request for the looped streaming buffer and includes the requested buffer size.

## Members

### `Property`

Specifies a **[KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure)** structure that identifies the property set, property ID, and request type for the looped streaming buffer property.

### `RequestedBufferSize`

Specifies the requested size for the looped streaming buffer, in bytes. The driver may adjust this value based on system constraints or alignment requirements.

## Remarks

This structure is used when making a **[KSPROPERTY_MIDILOOPEDSTREAMING_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-midiloopedstreaming-buffer)** property request. It allows the client to specify the desired buffer size for the cyclic MIDI streaming buffer. The driver uses this information to allocate an appropriate buffer and returns the actual buffer details in a **[KSMIDILOOPED_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksmidilooped_buffer)** structure.

The **KSPROPERTY_MIDILOOPEDSTREAMING_BUFFER** call builds on the standard **KSPROPERTY**, adding the requested buffer size for the cross process looped memory buffer. The *RequestedBufferSize* is only a request. The driver can increase, decrease, or adjust the buffer size to meet hardware or alignment requirements. The actual buffer size, and the buffer address, are returned in the **KSMIDILOOPED_BUFFER**.

The looped streaming mechanism is designed for low-latency MIDI applications that require direct access to a cyclic buffer for efficient data processing.

### Code sample

```cpp
HRESULT LoopedBufferCall(_In_ ULONG& bufferSize)
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

- **[KSMIDILOOPED_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksmidilooped_buffer)**
- **[KSPROPERTY_MIDILOOPEDSTREAMING](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ne-ksmedia-ksproperty_midiloopedstreaming)**
- **[KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure)**