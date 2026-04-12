# KSMIDILOOPED_EVENT structure

## Description

The **KSMIDILOOPED_EVENT** structure specifies the event handles used for notification in MIDI looped streaming operations.

## Members

### `WriteEvent`

Handle to the event that is signaled when the driver has completed a write operation to the looped streaming buffer. This event is used to synchronize data writing operations between the client and the driver.

## Remarks

This structure is used with the **KSPROPERTY_MIDILOOPEDSTREAMING_NOTIFICATION_EVENT** property to configure event-based notification for MIDI looped streaming operations. The structure provides a mechanism for efficient, low-latency communication between the MIDI driver and client applications.

The write event is typically signaled when the driver has processed data from the buffer, indicating that buffer space is available for new data. The client should create this event before setting the property, and it should be a reset event (manual or automatic reset, depending on the application's needs).

### Code sample

```cpp
_Use_decl_annotations_
NTSTATUS StreamEngine::SetLoopedStreamingNotificationEvent(PKSMIDILOOPED_EVENT Buffer)
{
 // Code to handle event...
}
```

## See also

- **[KSMIDILOOPED_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksmidilooped_buffer)**
- **[KSMIDILOOPED_REGISTERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksmidilooped_registers)**
- **[KSPROPERTY_MIDILOOPEDSTREAMING](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ne-ksmedia-ksproperty_midiloopedstreaming)**