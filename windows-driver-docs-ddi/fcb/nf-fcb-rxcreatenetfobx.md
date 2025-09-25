# RxCreateNetFobx function

## Description

**RxCreateNetFobx** allocates, initializes, and inserts a new file object extension (FOBX) structure into the in-memory data structures for a FCB that this FOBX is being opened on.

## Parameters

### `RxContext` [out]

A pointer to the RX_CONTEXT structure describing a create operation.

### `MrxSrvOpen` [in]

A pointer to the associated SRV_OPEN structure.

## Return value

**RxCreateNetFobx** returns a pointer to a newly allocated FOBX data structure on success or a **NULL** pointer on failure.

## Remarks

Network mini-redirectors should call **RxCreateNetFobx** to create an FOBX at the end of a successful create operation.

Before calling **RxCreateNetFobx**, the FCB associated with the FOBX structure must be acquired in exclusive mode.

**RxCreateNetFobx** will try and use the FOBX allocated as part of the associated FCB structure if it is available. If the FOBX allocated with the FCB is not available, then **RxCreateNetFobx** will try and use the FOBX allocated as part of the associated SRV_OPEN structure if it is available. In either of these cases, **RxCreateNetFobx** only needs to initialize the existing FOBX structure, no memory allocation is required. If both of the FOBX structures on the associated FCB and SRV_OPEN structure are not available, then **RxCreateNetFobx** will allocate a new FOBX structure.

If the associated FCB is a paging file, **RxCreateNetFobx** allocates non-paged pool memory when creating the new FOBX data structure. If the associated FCB is a not a paging file, **RxCreateNetFobx** allocates paged pool memory when creating the new FOBX data structure.

Windows does not currently allow having a paging file on a remote machine.

On success, the following FOBX members in the FOBX structure are set:

* The **NodeReference** member is set to 1.
* The **FobxSerialNumber** member is set to 0.
* The **SrvOpen** member is set to the associated SRV_OPEN structure.
* The **fOpenCountDecremented** member is set to **FALSE**.
* The **Flags** member is set to a value based on parameters from the RX_CONTEXT and whether a new FOBX needed to be allocated.

On success, the reference count for the SRV_OPEN structure is incremented and the **NumberOfFobxs** member on the associated V_NET_ROOT structure is incremented.

## See also

[RX_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxcontx/ns-rxcontx-_rx_context)

[RxCreateNetFcb](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxcreatenetfcb)

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

[RxFinalizeSrvOpen](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxfinalizesrvopen)

[RxFinalizeVNetRoot](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxfinalizevnetroot)

[RxFinishFcbInitialization](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxfinishfcbinitialization)

[RxForceFinalizeAllVNetRoots](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxforcefinalizeallvnetroots)

[RxReference](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxreference)

[RxSetSrvCallDomainName](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxsetsrvcalldomainname)

[RxpDereferenceNetFcb](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxpdereferencenetfcb)

[RxpReferenceNetFcb](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxpreferencenetfcb)