# RxCreateSrvCall function

## Description

**RxCreateSrvCall** builds a SRV_CALL structure and inserts the name into the net name table maintained by RDBSS.

## Parameters

### `RxContext`

[in] A pointer to the RX_CONTEXT structure containing the IRP describing a create operation.

### `Name`

[in] A pointer to the name to be inserted in the name table.

### `InnerNamePrefix`

A pointer to an optional inner prefix name to be inserted into the name table with the **Name**.

### `RxConnectionId`

[in] A pointer to the connection ID to be associated with the name to be inserted in the prefix name table. This parameter can be **NULL** in which case no connection ID will be associated with the name inserted in the prefix name table.

## Return value

**RxCreateSrvCall** returns a pointer to a newly created SRV_CALL data structure on success or a **NULL** pointer on failure.

## Remarks

The **RxCreateSrvCall** routine is not normally called by network mini-redirector drivers directly. RDBSS calls this routine internally when an I/O request packet is received for IRP_MJ_CREATE and a SRV_CALL needs to be created. This IRP is normally received by RDBSS in response to a user-mode application requesting a file create operation on a network share. It is also possible for another kernel driver to issue such an IRP.

Before calling **RxCreateSrvCall**, a lock on the name table associated with the device object member of the **RxContext** parameter must be acquired in exclusive mode.

**RxCreateSrvCall** initializes the server call parameters passed in through extended attributes as part of the associated RX_CONTEXT structure. Currently this includes initializing the **pPrincipalName** member of the SRV_CALL which is passed in by the DFS driver.

## See also

[RX_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxcontx/ns-rxcontx-_rx_context)

[RxCreateNetFcb](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxcreatenetfcb)

[RxCreateNetFobx](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxcreatenetfobx)

[RxCreateNetRoot](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxcreatenetroot)

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

[The SRV_CALL Structure](https://learn.microsoft.com/windows-hardware/drivers/ifs/the-srv-call-structure)