# RxCreateVNetRoot function

## Description

**RxCreateVNetRoot** allocates and initializes a NET_ROOT structure and inserts the name into the net name table on the associated device object.

## Parameters

### `RxContext` [in]

A pointer to the RDBSS RX_CONTEXT containing the IRP describing a create operation.

### `NetRoot` [in]

A pointer to the associated NET_ROOT structure.

### `CanonicalName` [in]

A pointer to the canonical name to be inserted in the name table.

### `LocalNetRootName` [in]

A pointer to the local NET_ROOT name without the prefix name.

### `FilePath` [in]

A pointer to a file pathname. This parameter is not currently used and can be **NULL**.

### `RxConnectionId` [in]

A pointer to the connection ID to be associated with the name to be inserted in the prefix name table. This parameter can be **NULL** in which case no connection ID will be associated with the name inserted in the name table.

## Return value

**RxCreateVNetRoot** returns a pointer to a newly created V_NET_ROOT data structure on success or a **NULL** pointer on failure.

## Remarks

The **RxCreateVNetRoot** routine is not normally called by network mini-redirector drivers directly. RDBSS calls this routine internally when an I/O request packet is received for IRP_MJ_CREATE and a V_NET_ROOT needs to be created. This IRP is normally received by RDBSS in response to a user-mode application requesting a file create operation on a network share. It is also possible for another kernel driver to issue such an IRP.

Before calling **RxCreateVNetRoot**, a lock on the name table associated with the device object member of the *RxContext* parameter must be acquired in exclusive mode.

**RxCreateVNetRoot** sets a variety of security context parameters on the V_NET_ROOT structure based on parameters from the RX_CONTEXT. These parameters include the following: *LogonId*, *SessionId*, *pUserName*, *pUserDomainName*, *pPassword*, and *Flags*.

## See also

[RX_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxcontx/ns-rxcontx-_rx_context)

[RxCreateNetFcb](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxcreatenetfcb)

[RxCreateNetFobx](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxcreatenetfobx)

[RxCreateNetRoot](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxcreatenetroot)

[RxCreateSrvCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxcreatesrvcall)

[RxCreateSrvOpen](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxcreatesrvopen)

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

[RxInferFileType](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxinferfiletype)

[RxReference](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxreference)

[RxSetSrvCallDomainName](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxsetsrvcalldomainname)

[RxpDereferenceNetFcb](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxpdereferencenetfcb)

[RxpReferenceNetFcb](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxpreferencenetfcb)

[The NET_ROOT Structure](https://learn.microsoft.com/windows-hardware/drivers/ifs/the-net-root-structure)

[The V_NET_ROOT Structure](https://learn.microsoft.com/windows-hardware/drivers/ifs/the-v-net-root-structure)