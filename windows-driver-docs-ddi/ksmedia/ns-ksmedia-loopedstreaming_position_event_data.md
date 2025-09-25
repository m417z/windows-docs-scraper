# LOOPEDSTREAMING_POSITION_EVENT_DATA structure

## Description

The LOOPEDSTREAMING_POSITION_EVENT_DATA structure describes a position event in a looped buffer.

## Members

### `KsEventData`

Specifies the type of notification that the system will send to the client when the event occurs. For more information, see [KSEVENTDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-kseventdata).

### `Position`

Specifies the buffer position as a byte offset from the beginning of the looped buffer. If the size of the buffer is *n* bytes, the **Position** member must contain a value in the range 0 to *n*-1.

## Remarks

The [KSEVENT_LOOPEDSTREAMING_POSITION](https://learn.microsoft.com/windows-hardware/drivers/audio/ksevent-loopedstreaming-position) event uses the LOOPEDSTREAMING_POSITION_EVENT_DATA structure. This type of event occurs only in looped buffers. A looped buffer is a data buffer for an audio stream of type [KSINTERFACE_STANDARD_LOOPED_STREAMING](https://learn.microsoft.com/windows-hardware/drivers/stream/ksinterface-standard-looped-streaming).

The driver (typically a system component) that generates the event compares the byte offset in the **Position** member to the play cursor (in a rendering stream) or the record cursor (in a capture stream). The position event occurs when the play or record cursor passes through the specified position.

When the play or record cursor reaches the end of a looped buffer, the cursor wraps around to the beginning of the buffer, which corresponds to a byte offset of 0.

For more information about looped buffers, buffer positions, and play and record cursors, see [Audio Position Property](https://learn.microsoft.com/windows-hardware/drivers/audio/audio-position-property).

## See also

[KSEVENTDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-kseventdata)

[KSEVENTSET_LoopedStreaming](https://learn.microsoft.com/windows-hardware/drivers/audio/kseventsetid-loopedstreaming)

[KSEVENT_LOOPEDSTREAMING_POSITION](https://learn.microsoft.com/windows-hardware/drivers/audio/ksevent-loopedstreaming-position)

[KSINTERFACE_STANDARD_LOOPED_STREAMING](https://learn.microsoft.com/windows-hardware/drivers/stream/ksinterface-standard-looped-streaming)