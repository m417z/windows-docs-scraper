# RxFinalizeSrvOpen function

## Description

**RxFinalizeSrvOpen** finalizes the given SRV_OPEN structure. The caller must have an exclusive lock on the FCB associated with the SRV_OPEN and either a shared or exclusive lock on the table lock of the NET_ROOT associated with the FCB.

## Parameters

### `ThisSrvOpen` [out]

A pointer to the SRV_OPEN structure to finalize.

### `RecursiveFinalize` [in]

The value indicating whether the finalization should be done recursively.

### `ForceFinalize` [in]

The value indicating whether the finalization should be forced, regardless of the reference count.

If *ForceFinalize* is **FALSE**, then the **NodeReferenceCount** member of the SRV_OPEN structure pointed to by *ThisSrvOpen* must be 0 for the SRV_OPEN to be finalized.

## Return value

**RxFinalizeSrvOpen** returns **TRUE** on success or **FALSE** if the finalization did not occur:

## Remarks

The **RxFinalizeSrvOpen** routine is not normally called by network mini-redirector drivers directly. RDBSS calls this routine internally when the reference count on the SRV_OPEN is decremented to 1. RDBSS also calls **RxFinalizeSrvOpen** when the **RxFinalizeNetFcb** routine is called with the *RecursiveFinalize* set to **TRUE**. RDBSS calls **RxFinalizeNetFcb** when an I/O request packet is received for IRP_MJ_CLOSE. This IRP is normally received by RDBSS in response to a user-mode application requesting a file close operation. It is also possible for another kernel driver to issue such an IRP.

Before calling **RxFinalizeSrvOpen**, the caller must have acquired an exclusive lock on the FCB associated with the SRV_OPEN and acquired either a shared or exclusive lock on the table lock of the NET_ROOT associated with the FCB.

If the *RecursiveFinalize* parameter is **TRUE**, then **RxFinalizeSrvOpen** will finalize any FOBX structures associated with this SRV_OPEN by calling **RxFinalizeNetFobx** with the *RecursiveFinalize* parameter set to **TRUE** and the *ForceFinalize* parameter.

If the **FcbState** member of the associated FCB does not have the FCB_STATE_ORPHANED flag set, then **RxFinalizeSrvCall** will call the **MRxForceClosed** routine provided by the network mini-redirector to finalize the SRV_CALL. If the SRV_CALL structure was not originally allocated as part of creating the FCB, then the memory for the SRV_CALL structure will also be released.

## See also

[MRxForceClosed](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_forceclosed_calldown)

[RxCreateNetFcb](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxcreatenetfcb)

[RxCreateNetFobx](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxcreatenetfobx)

[RxCreateNetRoot](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxcreatenetroot)

[RxCreateSrvCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxcreatesrvcall)

[RxCreateSrvOpen](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxcreatesrvopen)

[RxCreateVNetRoot](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxcreatevnetroot)

[RxDereference](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxdereference)

[RxFinalizeConnection](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxfinalizeconnection)

[RxFinalizeNetFcb](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxfinalizenetfcb)

[RxFinalizeNetFobx](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxfinalizenetfobx)

[RxFinalizeNetRoot](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxfinalizenetroot)

[RxFinalizeSrvCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxfinalizesrvcall)

[RxFinalizeVNetRoot](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxfinalizevnetroot)

[RxFinishFcbInitialization](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxfinishfcbinitialization)

[RxForceFinalizeAllVNetRoots](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxforcefinalizeallvnetroots)

[RxReference](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxreference)

[RxSetSrvCallDomainName](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxsetsrvcalldomainname)

[RxpDereferenceNetFcb](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxpdereferencenetfcb)

[RxpReferenceNetFcb](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxpreferencenetfcb)

[The SRV_OPEN Structure](https://learn.microsoft.com/windows-hardware/drivers/ifs/the-srv-open-structure)