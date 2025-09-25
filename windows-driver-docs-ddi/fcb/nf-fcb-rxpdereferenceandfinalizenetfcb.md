# RxpDereferenceAndFinalizeNetFcb function

## Description

**RxpDereferenceAndFinalizeNetFcb** decrements the reference count and finalizes an FCB structure.

## Parameters

### `ThisFcb`

A pointer to the FCB structure to be dereferenced and finalized.

### `RxContext` [in]

A pointer to the RX_CONTEXT structure associated with the *Fcb* parameter.

### `RecursiveFinalize` [in]

A parameter that indicates if this should be a recursive finalize operation.

### `ForceFinalize` [in]

A parameter that indicates if this routine should force the *Fcb* parameter to be finalized.

## Return value

**RxpDereferenceAndFinalizeNetFcb** returns **TRUE** if the FCB was finalized.

## Remarks

The referencing and dereferencing of FCBs is different from those of the other data structures because of the embedded resource in the FCB. This implies that the caller requires information regarding the status of the FCB (whether it was finalized or not ).To finalize the FCB, two locks need to be held, the NET_ROOT name table lock as well as the FCB resource. **RxpDereferenceAndFinalizeNetFcb** acquires the additional lock if required to finalize the FCB.

On checked builds, **RxpDereferenceAndFinalizeNetFcb** causes the system to ASSERT if *ForceFinalize* is **FALSE**, if the node type for the structure is not an FCB, or if the FCB was acquired exclusive.

## See also

[RxpReferenceNetFcb](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxpreferencenetfcb)

[RxpTrackDereference](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxptrackdereference)

[RxpTrackReference](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxptrackreference)