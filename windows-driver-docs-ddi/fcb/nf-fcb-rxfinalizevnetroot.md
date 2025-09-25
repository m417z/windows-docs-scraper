# RxFinalizeVNetRoot function

## Description

**RxFinalizeVNetRoot** finalizes the given V_NET_ROOT structure. The caller must have an exclusive lock on the netname table associated with the device object.

## Parameters

### `ThisVNetRoot` [out]

A pointer to the V_NET_ROOT structure to finalize.

### `RecursiveFinalize` [in]

The value indicating whether the finalization should be done recursively. This parameter in not currently used.

### `ForceFinalize` [in]

The value indicating whether the finalization should be forced, regardless of the reference count.

If *ForceFinalize* is **FALSE**, then the **NodeReferenceCount** member of the V_NET_ROOT structure pointed to by *ThisVNetRoot* must be 1 for the V_NET_ROOT to be finalized.

## Return value

**RxFinalizeVNetRoot** returns **TRUE** on success or **FALSE** if the finalization did not occur:

## Remarks

The **RxFinalizeVNetRoot** routine is not normally called by network mini-redirector drivers directly. RDBSS calls this routine internally when the reference count on the V_NET_ROOT is decremented to 1.

**RxFinalizeVNetRoot** is also called by the **RxFinalizeConnection** routine if the *Level* parameter to **RxFinalizeConnection** is set to **TRUE**. **RxFinalizeConnection** is normally called by a network mini-redirector driver in response to receiving a custom IOCTL request from user mode. For example, a user might execute from the command line a "NET USE x: /d" to delete a share. This request would be mapped through the network provider DLL provided by the network mini-redirector to a custom IOCTL request sent to the network mini-redirector kernel driver which would call the **RxFinalizeConnection** routine to delete the connection and any associated V_NET_ROOT structures.

**RxFinalizeVNetRoot** is also called by the **RxForceFinalizeAllVNetRoots** routine to finalize each V_NET_ROOT associated with a NET_ROOT structure.

Before calling **RxFinalizeVNetRoot**, a lock on the netname table associated with the device object must be acquired in exclusive mode.

If the **UpperFinalization** member of the V_NET_ROOT is 0, then **RxFinalizeVNetRoot** will iterate through all the FCBs that belong to the NET_ROOT associated with this V_NET_ROOT and orphan all of the SRV_OPEN structures that are associated with the V_NET_ROOT.

**RxFinalizeVNetRoot** will call the **MRxFinalizeVNetRoot** routine provided by the network mini-redirector to finalize the V_NET_ROOT before the memory for the V_NET_ROOT structure will be released.

## See also

[MRxFinalizeVNetRoot](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_finalize_v_net_root_calldown)

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

[RxFinalizeNetRoot](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxfinalizenetroot)

[RxFinalizeSrvCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxfinalizesrvcall)

[RxFinalizeSrvOpen](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxfinalizesrvopen)

[RxFinishFcbInitialization](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxfinishfcbinitialization)

[RxForceFinalizeAllVNetRoots](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxforcefinalizeallvnetroots)

[RxReference](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxreference)

[RxSetSrvCallDomainName](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxsetsrvcalldomainname)

[RxpDereferenceNetFcb](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxpdereferencenetfcb)

[RxpReferenceNetFcb](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxpreferencenetfcb)

[The V_NET_ROOT Structure](https://learn.microsoft.com/windows-hardware/drivers/ifs/the-v-net-root-structure)