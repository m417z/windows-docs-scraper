# KSEVENT_TIME_INTERVAL structure

## Description

The KSEVENT_TIME_INTERVAL structure is used in various events within the [KSEVENTSETID_Clock](https://learn.microsoft.com/windows-hardware/drivers/stream/kseventsetid-clock) event set.

## Members

### `EventData`

A structure of type [KSEVENTDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-kseventdata) that specifies the standard event structure.

### `TimeBase`

Specifies the initial clock time when the event should be signaled.

### `Interval`

Specifies the subsequent interval when the event should continue to be signaled.

## See also

[KSEVENTSETID_Clock](https://learn.microsoft.com/windows-hardware/drivers/stream/kseventsetid-clock)

[KSEVENT_TIME_MARK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksevent_time_mark)