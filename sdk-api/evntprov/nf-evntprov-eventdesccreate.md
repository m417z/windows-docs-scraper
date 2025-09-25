# EventDescCreate function

## Description

Sets the values of an event descriptor.

## Parameters

### `EventDescriptor` [out]

Event descriptor whose member values are set to those of the remaining
parameters. For details, see
[EVENT_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_descriptor).

### `Id` [in]

Event identifier. The value is used to set the **Id** member of
[EVENT_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_descriptor).

### `Version` [in]

Version of the event. The value is used to set the **Version** member of
[EVENT_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_descriptor).

### `Channel` [in]

The category of events to which this event belongs. The value is used to set the
**Channel** member of
[EVENT_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_descriptor).

### `Level` [in]

Specifies the severity of the event. The value is used to set the **Level**
member of
[EVENT_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_descriptor).

### `Task` [in]

Identifies a logical component of the application whose events you want to
enable. The value is used to set the **Task** member of
[EVENT_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_descriptor).

### `Opcode` [in]

Operation being performed at the time the event was written. The value is used
to set the **Opcode** member of
[EVENT_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_descriptor).

### `Keyword` [in]

Bitmask that further defines the category of events to which the event belongs.
The value is used to set the **Keyword** member of
[EVENT_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_descriptor).

## Return value

This function does not return a value.

## Remarks

This is a convenience macro for setting the members of the
[EVENT_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_descriptor)
structure.

## See also

[EventDescZero](https://learn.microsoft.com/windows/desktop/api/evntprov/nf-evntprov-eventdesczero)