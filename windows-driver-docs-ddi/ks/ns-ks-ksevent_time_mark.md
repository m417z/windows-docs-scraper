# KSEVENT_TIME_MARK structure

## Description

The KSEVENT_TIME_MARK structure is used in various events within the [KSEVENTSETID_Clock](https://learn.microsoft.com/windows-hardware/drivers/stream/kseventsetid-clock) event set.

## Members

### `EventData`

A structure of type [KSEVENTDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-kseventdata) that specifies the standard event structure.

### `MarkTime`

Specifies the clock time when the event should be signaled.

## Remarks

The flags indicate the type of units for the interval. The interval can be specified in KSEVENT_DATA_MARKF_FILETIME units for these events, which are 100-nanosecond units.

## See also

[KSEVENTSETID_Clock](https://learn.microsoft.com/windows-hardware/drivers/stream/kseventsetid-clock)

[KSEVENT_TIME_INTERVAL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksevent_time_interval)