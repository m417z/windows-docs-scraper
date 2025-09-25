# KsEnableEvent function

## Description

The **KsEnableEvent** function enables events requested through IOCTL_KS_ENABLE_EVENT. It responds to all event identifiers defined by the sets. This function can only be called at PASSIVE_LEVEL.

## Parameters

### `Irp` [in]

Specifies the IRP with the enable request being handled. The file object associated with the IRP is stored with the event for later comparison when disabling the event.

### `EventSetsCount` [in]

Indicates the number of event set structures being passed.

### `EventSet` [in]

Specifies a pointer to the list of event set information.

### `EventsList` [in, out]

If the enabling event's KSEVENT_SET.AddHandler for the event set is **NULL**, it must point to the head of the list of KSEVENT_ENTRY items on which the event is to be added. This function assumes a single list for at least a subset of events.

### `EventsFlags` [in, optional]

Specifies [KSEVENTS_LOCKTYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ne-ks-ksevents_locktype) flags specifying the type of exclusion lock to be used in accessing the event list, if any. If no flag is set, then no lock is taken. If a handler is specified already, this parameter is ignored.

### `EventsLock` [in, optional]

If the KSEVENT_SET.AddHandler for the event set containing the event being enabled is **NULL**, then this is used to synchronize access to the list. This value can be **NULL** if no flag is set in *EventsFlags*.

## Return value

The **KsEnableEvent** function returns STATUS_SUCCESS if successful, or an error specific to the event being enabled if unsuccessful. The function always sets the IO_STATUS_BLOCK.Information field of the PIRP.IoStatus element within the IRP to zero. It does not set the IO_STATUS_BLOCK.Status field, nor does it complete the IRP.

## Remarks

Minidrivers do not call **KsEnableEvent**. Only a pure KS driver or a class driver should call this routine.

## See also

[KsDisableEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksdisableevent)