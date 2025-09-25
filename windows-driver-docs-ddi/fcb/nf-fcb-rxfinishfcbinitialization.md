# RxFinishFcbInitialization function

## Description

**RxFinishFcbInitialization** is used to finish initializing an FCB after the successful completion of a create operation by the network mini-redirector.

## Parameters

### `Fcb`

A pointer to the MRX_FCB structure being initialized.

### `FileType`

The value indicating the storage type of entity that the FCB refers to. Possible options for this parameter include the following:

| Value | Meaning |
| ----- | ------- |
| RDBSS_NTC_MAILSLOT | A mail slot. |
| RDBSS_NTC_SPOOLFILE | A printer spool file. |
| RDBSS_NTC_STORAGE_TYPE_DIRECTORY | A directory. |
| RDBSS_NTC_STORAGE_TYPE_UNKNOWN | The storage type is unknown. |
| RDBSS_NTC_STORAGE_TYPE_FILE | A file. |

### `InitPacket`

Pointer to extra data that is required for initialization depending on the storage type of the FCB being initialized. This parameter may be a **NULL** pointer if no extra data is provided.

## Remarks

When called as a result of an IRP_MJ_CREATE, [RxCreateNetFCB](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxcreatenetfcb) is called first to create the FCB. If the **Type** member of the NET_ROOT to be created is not a NET_ROOT_MAILSLOT, then **RxFinishFcbInitialization** is called to finish the initialization of the FCB structure.

If the **FcbState** member of the MRX_FCB structure pointed to by **MrxFcb** does not have the FCB_STATE_TIME_AND_SIZE_ALREADY_SET on, then the following members of the FCB will be updated from the **InitPacket** parameter if **InitPacket** is non **NULL**: **Attributes**, **NumberOfLinks**, **CreationTime**, **LastAccessTime**, **LastWriteTime**, **LastChangeTime**, **ActualAllocationLength**, **Header.AllocationSize**, **Header.FileSize**, and **Header.ValidDataLength**. The FCB_STATE_TIME_AND_SIZE_ALREADY_SET option is then set on in the **FcbState** member of the FCB structure.

If the storage type is an RDBSS_NTC_MAILSLOT and the FcbState member of the FCB does have the FCB_STATE_TIME_AND_SIZE_ALREADY_SET option set on, then the following members of the FCB structure for the mail slot will be initialized to 0: **Attributes**, **NumberOfLinks**, **CreationTime.QuadPart**, **LastAccessTime.QuadPart**, **LastWriteTime.QuadPart**, **LastChangeTime**.**QuadPart**, **ActualAllocationLength**, **Header.AllocationSize.QuadPart**, **Header.FileSize.QuadPart**, and **Header.ValidDataLength.QuadPart**

## See also

[RxCreateNetFCB](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxcreatenetfcb)

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

[RxForceFinalizeAllVNetRoots](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxforcefinalizeallvnetroots)

[RxReference](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxreference)

[RxSetSrvCallDomainName](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxsetsrvcalldomainname)

[RxpDereferenceNetFcb](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxpdereferencenetfcb)

[RxpReferenceNetFcb](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxpreferencenetfcb)