# RxFinalizeSrvCall function

## Description

**RxFinalizeSrvCall** finalizes the given SRV_CALL structure. The caller must have an exclusive lock on the netname table associated with the device object.

## Parameters

### `ThisSrvCall` [out]

A pointer to the SRV_CALL structure to finalize.

### `ForceFinalize` [in]

The value indicating whether the finalization should be forced, regardless of the reference count.

If *ForceFinalize* is **FALSE**, then the **NodeReferenceCount** member of the SRV_CALL structure pointed to by *ThisSrvCall* must be 1 for the SRV_CALL to be finalized.

## Return value

**RxFinalizeSrvCall** returns **TRUE** on success or **FALSE** if the finalization did not occur:

## Remarks

The **RxFinalizeSrvCall** routine is not normally called by network mini-redirector drivers directly. RDBSS calls this routine internally when the reference count on the SRV_CALL is decremented to 1. RDBSS also calls **RxFinalizeSrvCall** when the network mini-redirector driver is stopped or unloaded.

Before calling **RxFinalizeSrvCall**, a lock on the netname table associated with the device object must be acquired in exclusive mode.

If the current executing process ID is the same as the RDBSS process ID, then a delayed worker thread will be dispatched to destroy the SRV_CALL structure. This worker thread will later call the **MRxFinalizeSrvCall** routine provided by the network mini-redirector to finalize the SRV_CALL. Otherwise, the **MRxFinalizeSrvCall** routine will be called directly to finalize the SRV_CALL.

## See also

[MRxFinalizeSrvCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_finalize_srvcall_calldown)

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

[RxFinalizeSrvOpen](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxfinalizesrvopen)

[RxFinalizeVNetRoot](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxfinalizevnetroot)

[RxFinishFcbInitialization](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxfinishfcbinitialization)

[RxForceFinalizeAllVNetRoots](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxforcefinalizeallvnetroots)

[RxReference](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxreference)

[RxSetSrvCallDomainName](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxsetsrvcalldomainname)

[RxpDereferenceNetFcb](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxpdereferencenetfcb)

[RxpReferenceNetFcb](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxpreferencenetfcb)

[The SRV_CALL Structure](https://learn.microsoft.com/windows-hardware/drivers/ifs/the-srv-call-structure)