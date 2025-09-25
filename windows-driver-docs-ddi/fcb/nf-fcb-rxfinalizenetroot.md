# RxFinalizeNetRoot function

## Description

**RxFinalizeNetRoot** finalizes the given NET_ROOT structure. The caller must have an exclusive lock on the netname table associated with the device object.

## Parameters

### `ThisNetRoot` [out]

A pointer to the NET_ROOT structure to finalize.

### `RecursiveFinalize` [in]

The value indicating whether the finalization should be done recursively.

### `ForceFinalize` [in]

The value indicating whether the finalization should be forced, regardless of the reference count.

If *ForceFinalize* is **FALSE**, then the **NodeReferenceCount** member of the NET_ROOT structure pointed to by *ThisNetRoot* must be 1 for the NET_ROOT to be finalized.

## Return value

**RxFinalizeNetRoot** returns **TRUE** on success or **FALSE** if the finalization did not occur: If a finalization of the NET_ROOT is already in process, **RxFinalizeNetRoot** will return **FALSE**.

## Remarks

The **RxFinalizeNetRoot** routine is not normally called by network mini-redirector drivers directly. RDBSS calls this routine internally when the reference count on the NET_ROOT is decremented to 1.

Before calling **RxFinalizeNetRoot**, a lock on the netname table associated with the device object must be acquired in exclusive mode.

If the *RecursiveFinalize* parameter is **TRUE**, then **RxFinalizeNetRoot** will purge any orphaned FCB structures associated with this NET_ROOT. These orphaned FCBs are structures where the **FcbState** member has the FCB_STATE_ORPHANED flag set on.

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

[RxFinalizeNetFobx](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxfinalizenetfobx)

[RxFinalizeSrvCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxfinalizesrvcall)

[RxFinalizeSrvOpen](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxfinalizesrvopen)

[RxFinalizeVNetRoot](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxfinalizevnetroot)

[RxFinishFcbInitialization](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxfinishfcbinitialization)

[RxForceFinalizeAllVNetRoots](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxforcefinalizeallvnetroots)

[RxReference](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxreference)

[RxSetSrvCallDomainName](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxsetsrvcalldomainname)

[RxpDereferenceNetFcb](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxpdereferencenetfcb)

[RxpReferenceNetFcb](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxpreferencenetfcb)

[The NET_ROOT Structure](https://learn.microsoft.com/windows-hardware/drivers/ifs/the-net-root-structure)