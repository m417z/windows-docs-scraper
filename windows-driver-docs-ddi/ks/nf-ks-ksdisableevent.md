# KsDisableEvent function

## Description

The **KsDisableEvent** function disables events requested through IOCTL_KS_DISABLE_EVENT. It responds to all events previously enabled through **KsEnableEvent**. If the input buffer length is zero, it is assumed that all events on the list are to be disabled. This function can only be called at PASSIVE_LEVEL.

## Parameters

### `Irp` [in]

Specifies the IRP passed to the removal function, which uses the IRP to obtain context information. The file object associated with the IRP is used to compare against the file object originally specified when enabling the event. This allows a single event list to be used for multiple clients differentiated by file objects.

### `EventsList` [in, out]

Points to the head of the list of [KSEVENT_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksevent_entry) items on which the event may be found. If a client uses multiple event lists and does not know what list this event is on, the client can call this function multiple times. An event not found will return STATUS_UNSUCCESSFUL.

### `EventsFlags` [in]

Specifies a [KSEVENTS_LOCKTYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ne-ks-ksevents_locktype) flag specifying the type of exclusion lock to be used in accessing the event list. If no flag is set, then no lock is taken.

### `EventsLock` [in]

Used to synchronize access to an element on the list. After the element has been accessed, it is marked as being deleted so that subsequent removal requests fail. The lock is then released after calling the removal function, if any. The removal function must synchronize with event generation before actually removing the element from the list.

## Return value

The **KsDisableEvent** function returns STATUS_SUCCESS if successful, or an error specific to the event being enabled. The function always sets the IO_STATUS_BLOCK.Information field of the PIRP.IoStatus element within the IRP to zero. It does not set the IO_STATUS_BLOCK.Status field, nor does it complete the IRP.

## Remarks

It is important that the remove handler synchronize with event generation to ensure that when the event is removed from the list, it is not currently being serviced. Access to this list is assumed to be controlled with the lock passed.

## See also

[KsEnableEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksenableevent)