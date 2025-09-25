# _MPIO_EventEntry structure

## Description

The MPIO_EventEntry structure is used to return events that MPIO has logged.

## Members

### `TimeStamp`

A 64-bitfield that specifies the timestamp for the event entry.

### `Severity`

A 32-bitfield that indicates the severity of the reported event.

### `Component`

A string that indicates the component to which this event belongs.

### `EventDescription`

A string that indicates the event description.