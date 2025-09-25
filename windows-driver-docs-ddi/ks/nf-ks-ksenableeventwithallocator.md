## Description

The **KsEnableEventWithAllocator** function enables events requested through IOCTL_KS_ENABLE_EVENT but also allows an optional allocator callback to be used to provide a buffer for the parameters. It responds to all event identifiers defined by the sets. This function can only be called at PASSIVE_LEVEL.

If used, the filter may need to free the buffer in some nonconventional manner. Note that the IRP_BUFFERED_IO and IRP_DEALLOCATE_BUFFER flags are not set when using a custom allocator.

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

### `Allocator` [in, optional]

Optionally points to an allocation function that will be used to allocate memory to store the event parameters.

### `EventItemSize` [in, optional]

Optionally contains the size of each KSEVENT_ITEM structure in each list of events. The event item may be extended in order to store private information. If this parameter is zero, the structure size is assumed to be normal. If it is greater than or equal to an event item structure, the KSEVENT_ITEM_IRP_STORAGE macro can be used to return a pointer to the event item so the custom data can be retrieved. On 64-bit platforms, this parameter must be a multiple of 8.

## Return value

Same as **KsEnableEvent**, which returns STATUS_SUCCESS if successful, or an error specific to the event being enabled if unsuccessful. The function always sets the IO_STATUS_BLOCK.Information field of the PIRP.IoStatus element within the IRP to zero. It does not set the IO_STATUS_BLOCK.Status field, nor does it complete the IRP.

## Remarks

If the optional allocator callback is used, the filter may need to free the buffer in some nonconventional manner. Note that the IRP_BUFFERED_IO and IRP_DEALLOCATE_BUFFER flags are not set when using a custom allocator.