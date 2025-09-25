# RxCreateNetRoot function

## Description

**RxCreateNetRoot** allocates and initializes a NET_ROOT structure and inserts the name into the net name table on the associated device object.

## Parameters

### `SrvCall` [in]

A pointer to the associated SRV_CALL structure.

### `Name` [in]

A pointer to the name to be inserted in the name table.

### `NetRootFlags` [in]

The value to set the **Flags** member of the NET_ROOT which is used to denote the state of the NET_ROOT structure.

### `RxConnectionId` [in, optional]

A pointer to the connection ID to be associated with the name to be inserted in the prefix name table. This parameter can be **NULL** in which case no connection ID will be associated with the name inserted in the prefix name table.

## Return value

**RxCreateNetRoot** returns a pointer to a newly created NET_ROOT data structure on success or a **NULL** pointer on failure.

## Remarks

The **RxCreateNetRoot** routine is not normally called by network mini-redirector drivers directly. RDBSS calls this routine internally when an I/O request packet is received for IRP_MJ_CREATE and a NET_ROOT needs to be created. This IRP is normally received by RDBSS in response to a user-mode application requesting a file create operation on a network share. It is also possible for another kernel driver to issue such an IRP.

Before calling **RxCreateNetRoot**, a lock on the name table associated with the device object member of the *SrvCall* parameter must be acquired in exclusive mode.

The NET_ROOT flags are split into two groups, those visible to network mini redirectors and those invisible to network mini redirectors. The visible ones are the lower 16-bits of the **Flags** member of the NET_ROOT. This routine does not check or test which flags are being set.

On success, the reference count for the SRV_CALL structure is incremented.

## See also

[RxCreateNetFcb](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxcreatenetfcb)

[RxCreateNetFobx](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxcreatenetfobx)

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

[The NET_ROOT Structure](https://learn.microsoft.com/windows-hardware/drivers/ifs/the-net-root-structure)

[The SRV_CALL Structure](https://learn.microsoft.com/windows-hardware/drivers/ifs/the-srv-call-structure)