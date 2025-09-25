# RxFinalizeNetFcb function

## Description

**RxFinalizeNetFCB** finalizes the given FCB structure. The caller must have an exclusive lock on the NET_ROOT associated with FCB.

## Parameters

### `ThisFcb` [out]

A pointer to the FCB structure to finalize.

### `RecursiveFinalize` [in]

The value indicating whether the finalization should be done recursively.

### `ForceFinalize` [in]

The value indicating whether the finalization should be forced, regardless of the reference count.

If this parameter is **FALSE**, then the **NodeReferenceCount** member of the FCB must be 1 for the FCB to be finalized.

### `ReferenceCount` [in]

The reference count on the FCB that will still allow forced finalization.

## Return value

**RxFinalizeNetFCB** returns **TRUE** on success or **FALSE** if the finalization did not occur:

## Remarks

The **RxFinalizeNetFCB** routine is not normally called by network mini-redirector drivers directly. RDBSS calls this routine internally when an I/O request packet is received for IRP_MJ_CLOSE. This IRP is normally received by RDBSS in response to a user-mode application requesting a file close operation. It is also possible for another kernel driver to issue such an IRP.

The close handling strategy in RDBSS is predicated upon the axiom that the workload on the server should be minimized as and when possible. There are a number of applications which repeatedly close and open the same file (batch file processing, for example). In these cases the same file is opened, a line from a buffer is read, the file is closed and the same set of operations are repeated over and over again.

This is handled in RDBSS by a delayed processing of the close request. There is a delay of about 10 seconds between completing the request and initiating processing on the close request. This opens up a window during which a subsequent open operation can be collapsed onto an existing SRV_OPEN. The time interval can be tuned to meet these requirements.

Before calling **RxFinalizeNetFCB**, a lock on the FCB structure must be acquired in exclusive mode.

If the *RecursiveFinalize* parameter is **FALSE**, then **RxFinalizeNetFCB** will fail if there are outstanding references to the FCB (the **OpenCount** or **CleanCount** members of the FCB structure are non zero).

If the *ForceFinalize* parameter is **TRUE**, **RxFinalizeNetFCB** causes the system to ASSERT on checked builds.

After recursive finalization, the reference count associated with the FCB could be at most 1 for further finalization to occur. This final reference count belongs to the prefix name table of the NET_ROOT. The actual finalization is divided into two parts:

* if the reference count equals 1 or the *ForceFinalize* parameter was **TRUE**, **RxFinalizeNetFCB** finalizes the FCB.
* if the reference count goes to zero, the FCB is finalized and the memory used for the FCB is also released.

## See also

[RxCreateNetFcb](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxcreatenetfcb)

[RxCreateNetFobx](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxcreatenetfobx)

[RxCreateNetRoot](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxcreatenetroot)

[RxCreateSrvCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxcreatesrvcall)

[RxCreateSrvOpen](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxcreatesrvopen)

[RxCreateVNetRoot](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxcreatevnetroot)

[RxDereference](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxdereference)

[RxFinalizeConnection](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxfinalizeconnection)

[RxFinalizeNetFobx](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxfinalizenetfobx)

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