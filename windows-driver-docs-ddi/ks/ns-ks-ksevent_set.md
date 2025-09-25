# KSEVENT_SET structure

## Description

The KSEVENT_SET structure describes the events that comprise a kernel streaming event set.

## Members

### `Set`

Specifies a GUID that identifies the event set. For more information about defined event sets, see **Remarks**.

### `EventsCount`

Specifies the number of events in the event set.

### `EventItem`

Points to the beginning of the array of [KSEVENT_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksevent_item) structures that describe each event in the event set. The size of the array is in the **EventsCount** member.

## Remarks

Microsoft provides several system-defined kernel streaming event set GUIDs. Minidrivers specify one of these GUIDs in the **Set** member. Kernel streaming event sets typically begin with a *KSEVENTSETID* prefix. Event set GUIDs are defined in *ks.h*, *ksmedia.h*, *bdamedia.h*, and possibly other header files.

## See also

[KSEVENT_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksevent_item)