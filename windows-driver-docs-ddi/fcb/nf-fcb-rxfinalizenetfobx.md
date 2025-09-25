# RxFinalizeNetFobx function

## Description

**RxFinalizeNetFOBX** finalizes the given FOBX structure. The caller must have an exclusive lock on the FCB associated with FOBX structure.

## Parameters

### `ThisFobx` [out]

A pointer to the FOBX structure to finalize.

### `RecursiveFinalize` [in]

The value indicating whether the finalization should be done recursively. This parameter is not currently used.

### `ForceFinalize` [in]

The value indicating whether the finalization should be forced, regardless of the reference count.

If *ForceFinalize* is **FALSE**, then the **NodeReferenceCount** member of the FOBX structure pointed to by *ThisFobx* must be 0 for the FOBX to be finalized.

## Return value

**RxFinalizeNetFOBX** returns **TRUE** on success or **FALSE** if the finalization did not occur:

## Remarks

The **RxFinalizeNetFOBX** routine is not normally called by network mini-redirector drivers directly. RDBSS calls this routine internally when an I/O request packet is received for IRP_MJ_CLOSE. This IRP is normally received by RDBSS in response to a user-mode application requesting a file close operation. It is also possible for another kernel driver to issue such an IRP.

Before calling **RxFinalizeNetFOBX**, a lock on the FCB structure must be acquired in exclusive mode.

The **RxFinalizeNetFOBX** routine will call the **MRxDeallocateForFobx** routine provided by the network mini-redirector to free the memory for the FOBX if the network mini-redirector supports this routine.

## See also

[RxCreateNetFcb](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxcreatenetfcb)

[RxCreateNetFobx](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxcreatenetfobx)

[RxCreateNetRoot](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxcreatenetroot)

[RxCreateSrvCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxcreatesrvcall)

[RxCreateSrvOpen](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxcreatesrvopen)

[RxCreateVNetRoot](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxcreatevnetroot)

[RxDereference](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxdereference)

[RxFinalizeConnection](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxfinalizeconnection)

[RxFinalizeNetFcb](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxfinalizenetfcb)

[RxFinalizeNetRoot](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxfinalizenetroot)

[RxFinalizeSrvCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxfinalizesrvcall)

[RxFinalizeSrvOpen](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxfinalizesrvopen)

[RxFinalizeVNetRoot](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxfinalizevnetroot)

[RxFinishFcbInitialization](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxfinishfcbinitialization)

[RxForceFinalizeAllVNetRoots](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxforcefinalizeallvnetroots)

[RxReference](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxreference)

[RxSetSrvCallDomainName](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxsetsrvcalldomainname)

[RxpDereferenceNetFcb](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxpdereferencenetfcb)

[RxpReferenceNetFcb](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxpreferencenetfcb)

[The FCB Structure](https://learn.microsoft.com/windows-hardware/drivers/ifs/the-fcb-structure)

[The FOBX Structure](https://learn.microsoft.com/windows-hardware/drivers/ifs/the-fobx-structure)