# RxCreateNetFcb function

## Description

**RxCreateNetFCB** allocates, initializes, and inserts a new FCB structure into the in-memory data structures for a V_NET_ROOT that this FCB is being opened on. The structure allocated has space for a SRV_OPEN and an FOBX structure.

## Parameters

### `RxContext` [in]

A pointer to the RX_CONTEXT structure describing a create operation.

### `Irp` [in]

A pointer to the IRP encapsulated by this RX_CONTEXT structure.

### `VNetRoot` [in]

A pointer to the V_NET_ROOT structure that this FCB is being opened on.

### `Name` [in]

The name of the FCB. The V_NET_ROOT may contain a name prefix that is to be prepended here.

## Return value

**RxCreateNetFCB** returns a pointer to a newly allocated FCB data structure on success or a **NULL** pointer on failure.

## Remarks

The **RxCreateNetFCB** routine is not normally called by network mini-redirector drivers directly. RDBSS calls this routine internally when an I/O request packet is received for IRP_MJ_CREATE and an FCB structure needs to be created. This IRP is normally received by RDBSS in response to a user-mode application requesting a file create operation on a network share. It is also possible for another kernel driver to issue such an IRP.

If the FCB to be created is a paging file, **RxCreateNetFCB** allocates non-paged pool memory when creating the new FCB data structure and sets the following flag on in the FcbState member of the FCB:

If the FCB to be created is a not a paging file, **RxCreateNetFCB** allocates paged pool memory when creating the new FCB data structure.

Windows does not currently allow having a paging file on a remote machine.

If the **Create.Flags** member in the RX_CONTEXT has the RX_CONTEXT_CREATE_FLAG_ADDEDBACKSLASH flag on, the **FcbState** member of the FCB has the FCB_STATE_ADDEDBACKSLASH flag set on.

## See also

[RX_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxcontx/ns-rxcontx-_rx_context)

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

[RxFinalizeSrvOpen](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxfinalizesrvopen)

[RxFinalizeVNetRoot](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxfinalizevnetroot)

[RxFinishFcbInitialization](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxfinishfcbinitialization)

[RxForceFinalizeAllVNetRoots](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxforcefinalizeallvnetroots)

[RxReference](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxreference)

[RxSetSrvCallDomainName](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxsetsrvcalldomainname)

[RxpDereferenceNetFcb](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxpdereferencenetfcb)

[RxpReferenceNetFcb](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxpreferencenetfcb)

[The FCB Structure](https://learn.microsoft.com/windows-hardware/drivers/ifs/the-fcb-structure)

[The V_NET_ROOT Structure](https://learn.microsoft.com/windows-hardware/drivers/ifs/the-v-net-root-structure)