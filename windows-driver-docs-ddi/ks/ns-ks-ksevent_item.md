# KSEVENT_ITEM structure

## Description

The KSEVENT_ITEM structure describe a minidriver's support for a specific event within an event set.

## Members

### `EventId`

Specifies the unique ID of the event within the event set.

### `DataInput`

Specifies the size in bytes of event data. The event data begins with a [KSEVENTDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-kseventdata) structure that describes how the client should be notified when the event occurs, optionally followed by any additional parameters that specify when the event occurs. Must be at least **sizeof**(KSEVENTDATA).

### `ExtraEntryData`

Specifies the size in bytes of any additional memory that the system should allocate for each enable request for this event. The driver uses this memory to store any data it needs to keep track of the event request. The memory is allocated directly after the event enable request's [KSEVENT_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksevent_entry) structure.

### `AddHandler`

Pointer to a minidriver-supplied [AVStrMiniAddEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnksaddevent) callback routine. Not used by the stream class driver. For AVStream minidrivers only.

### `RemoveHandler`

Pointer to a minidriver-supplied [AVStrMiniRemoveEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnksremoveevent) callback routine. Not used by the stream class driver. For AVStream minidrivers only.

### `SupportHandler`

Not used by the stream class driver.

## Remarks

*A minidriver that specifies the* **AddHandler** *and* **RemoveHandler** *members and does not properly clean the events up can cause a resource (memory/handle) leak.*

## See also

[IOCTL_KS_DISABLE_EVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ni-ks-ioctl_ks_disable_event)

[KSEVENTDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-kseventdata)

[KSEVENT_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksevent_entry)

[KsDefaultAddEventHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksdefaultaddeventhandler)