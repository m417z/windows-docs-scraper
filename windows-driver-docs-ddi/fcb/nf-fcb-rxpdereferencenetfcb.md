# RxpDereferenceNetFcb function

## Description

**RxpDereferenceNetFcb** decrements the reference count on an FCB structure.

## Parameters

### `Fcb`

A pointer to the FCB structure to be dereferenced.

## Return value

**RxpDereferenceNetFcb** returns the final reference count after the dereference.

## Remarks

The referencing and dereferencing of FCBs is different from those of the other data structures because of the embedded resource in the FCB. This implies that the caller requires information regarding the status of the FCB (whether it was finalized or not ). To finalize the FCB, two locks need to be held, the NET_ROOT name table lock as well as the FCB resource. These considerations lead to a different approach in dereferencing FCBs. Consequently, **RxpDereferenceNetFcb** does not attempt to finalize the FCB.

A number of macros are defined in *fcb.h* for debugging that are the preferred way to call this routine. These macros provide a wrapper around the **RxpReferenceNetFcb** or **RxpDereferenceNetFcb** routines used for file structure management operations on FCB structures. The **RxDereferenceNetFcb** macro is the preferred way to call this routine. This macro first calls the **RxpTrackDereference** routine to log diagnostic information about the request before calling the **RxpDereferenceNetFcb** routine.

On checked builds, **RxpDereferenceNetFcb** causes the system to ASSERT if the node type for the structure is not an FCB or if the final reference count is less than 0.

## See also

[RxpReferenceNetFcb](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxpreferencenetfcb)

[RxpTrackDereference](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxptrackdereference)

[RxpTrackReference](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxptrackreference)

[The FCB Structure](https://learn.microsoft.com/windows-hardware/drivers/ifs/the-fcb-structure)