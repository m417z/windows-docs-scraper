# RxFinalizeConnection function

## Description

**RxFinalizeConnection** deletes a connection to a share. Any files open on the connection are closed depending on the level of force specified. The network mini-redirector might choose to keep the transport connection open for performance reasons, unless some option is specified to force a close of connection.

## Parameters

### `NetRoot`

[in, out] A pointer to the NET_ROOT structure being finalized.

### `VNetRoot`

A pointer to the V_NET_ROOT structure being finalized.

### `ForceFilesClosed`

The flag that controls the behavior of the **RxFinalizeConnection** routine. The flag can be one of the following values:

**TRUE**

**RxFinalizeConnection** succeeds no matter what even if orphan files and IRP_MN_NOTIFY_CHANGE_DIRECTORY requests are open. The option forces these orphan files closed.

**FALSE**

**RxFinalizeConnection** fails if files or change notifications are open.

0xff

**RxFinalizeConnection** removes the extra reference on the V_NET_ROOT structure due to the add connection request, but otherwise act like **FALSE**. **RxFinalizeConnection** fails if files or change notifications are open.

## Return value

**RxFinalizeConnection** returns STATUS_SUCCESS on success or one of the following error codes on failure:

| Return code | Description |
| --- | --- |
| **STATUS_CANCELLED** | The **Flags** member of the RX_CONTEXT structure indicates the IRP was canceled. |
| **STATUS_CONNECTION_IN_USE** | The connection is still in use. |
| **STATUS_FILES_OPEN** | The file was open, so the remote connection should not be deleted. |
| **STATUS_LOCK_NOT_GRANTED** | An exclusive lock on the associated |

## Remarks

**RxFinalizeConnection** is normally called by a network mini-redirector driver in response to receiving a custom IOCTL request from user mode. For example, a user might execute from the command line a "NET USE x: /d" to delete a share. This request would be mapped through the network provider DLL provided by the network mini-redirector to a custom IOCTL request sent to the network mini-redirector kernel driver which would call the **RxFinalizeConnection** routine to delete the connection.

**RxFinalizeConnection** cancels all the outstanding requests for a given V_NET_ROOT structure. These V_NET_ROOT structures are created and deleted independent of the files that are opened and manipulated on them. Therefore it is imperative that when a delete operation is attempted, all the outstanding requests are canceled.

## See also

[RxCreateNetFcb](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxcreatenetfcb)

[RxCreateNetFobx](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxcreatenetfobx)

[RxCreateNetRoot](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxcreatenetroot)

[RxCreateSrvCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxcreatesrvcall)

[RxCreateSrvOpen](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxcreatesrvopen)

[RxCreateVNetRoot](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxcreatevnetroot)

[RxDereference](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxdereference)

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

[The V_NET_ROOT Structure](https://learn.microsoft.com/windows-hardware/drivers/ifs/the-v-net-root-structure)