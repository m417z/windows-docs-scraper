# RxpReferenceNetFcb function

## Description

**RxpReferenceNetFcb** increments the reference count on an FCB.

## Parameters

### `Fcb`

A pointer to the FCB structure to be referenced.

## Return value

**RxpReferenceNetFcb** returns the final reference count after the reference.

## Remarks

A number of debugging macros are defined in *fcb.h* that are the preferred way to call this routine. These macros provide a wrapper around the **RxpReferenceNetFcb** or **RxpDereferenceNetFcb** routines used for file structure management operations on FCB structures. The **RxReferenceNetFcb** macro is the preferred way to call this routine. This macro first calls the **RxpTrackReference** routine to log diagnostic information about the request before calling the **RxpReferenceNetFcb** routine.

On checked builds, **RxpReferenceNetFcb** causes the system to ASSERT if the node type for the structure is not an FCB.

## See also

[RxpDereferenceNetFcb](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxpdereferencenetfcb)

[RxpTrackDereference](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxptrackdereference)

[RxpTrackReference](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxptrackreference)