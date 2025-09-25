# NdisCmMakeCallComplete function

## Description

**NdisCmMakeCallComplete** returns the final status of a client's request, for which the call manager
previously returned NDIS_STATUS_PENDING, to make an outgoing call.

## Parameters

### `Status` [in]

Specifies the final status of the attempt to make the connection, either NDIS_STATUS_SUCCESS or
any CM-determined NDIS_STATUS_
*XXX* except NDIS_STATUS_PENDING.

### `NdisVcHandle` [in]

Specifies the handle to the client-created VC, which the call manager originally obtained as an
input parameter to its
[ProtocolCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_create_vc) function. More
recently, the CM obtained this handle from its per-VC state designated by the
*CallMgrVcContext* passed in to its
[ProtocolCmMakeCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_make_call) function.

### `NdisPartyHandle` [in, optional]

Specifies the handle to the initial party on the client-created multipoint VC, which the call
manager obtained as an input parameter to its
*ProtocolCmMakeCall* function. If the given
*NdisVcHandle* represented a point-to-point VC, this parameter was **NULL**.

### `CallMgrPartyContext` [in, optional]

Specifies the CM-supplied handle to a caller-allocated resident context area, in which the CM will
maintain per-party state information, or **NULL** if
*NdisPartyHandle* is **NULL**. For a multipoint VC, NDIS passes this CM-supplied
*CallManagerPartyContext* handle in all subsequent calls to the ProtocolCm*Xxx* functions that concern this party. Otherwise, NDIS ignores this parameter.

### `CallParameters` [in]

Pointer to a structure of type
[CO_CALL_PARAMETERS](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff545384(v=vs.85)) that specifies the call
parameters set up for this connection if
*Status* is NDIS_STATUS_SUCCESS.

## Remarks

A stand-alone call manager should call
**NdisMCmMakeCallComplete** with NDIS_STATUS_SUCCESS only if the underlying miniport driver is ready to
make data transfers on the VC. That is, the call manager has negotiated with the network to establish
call parameters for the VC and called
[NdisCmActivateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmactivatevc) successfully.

A stand-alone call manager must call
**NdisCmMakeCallComplete** if its
[ProtocolCmMakeCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_make_call) function
previously returned NDIS_STATUS_PENDING for the given
*NdisVcHandle* . The client that initiated the pending outgoing call cannot use the VC to make
transfers until the CM calls
**NdisCmMakeCallComplete** with NDIS_STATUS_SUCCESS.

Even if the attempted connection failed, neither NDIS nor the client can release the resources they
allocated to maintain state until the CM's call to
**NdisCmMakeCallComplete** causes a call to that client's
[ProtocolClMakeCallComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_make_call_complete) function. In fact, neglecting to call
**NdisCmMakeCallComplete** for a failed attempt to set up such a connection causes a memory leak in the
call manager as well; it prevents the client from tearing down the VC it created for its failed outgoing
call, so the CM is not called to release the resources it allocated for that VC.

If the CM passes an error, such as NDIS_STATUS_FAILURE, for the
*Status*, it should consider the
*NdisPartyHandle*, if any, invalid as soon as it calls
**NdisCmMakeCallComplete**. The CM can release (or reinitialize for reuse) any resources that it
allocated to maintain state for the given party when
**NdisCmMakeCallComplete** returns control. The CM's
[ProtocolCoDeleteVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_delete_vc) function will
subsequently be called to release any resources that the CM allocated for tracking the state of the
client-created VC whenever the CM passes an error status to
**NdisCmMakeCallComplete**.

In the course of setting up a client-initiated outgoing call, the CM can modify the client-supplied
call parameters originally passed in to its
[ProtocolCmMakeCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_make_call) function. If it
does, the CM must pass its modifications in the buffer at
*CallParameters* when it calls
**NdisCmMakeCallComplete**. If the client finds these modified call parameters unacceptable, it will
then tear down the call, which also causes a call to the CM's
*ProtocolCoDeleteVc* function.

Only stand-alone call managers, which register themselves with NDIS as protocol drivers, can call
**NdisCmMakeCallComplete**. Miniport drivers that provide integrated call-management support call
[NdisMCmMakeCallComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmmakecallcomplete) instead.

## See also

[CO_CALL_PARAMETERS](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff545384(v=vs.85))

[NdisAllocateFromNPagedLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatefromnpagedlookasidelist)

[NdisClMakeCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclmakecall)

[NdisMCmMakeCallComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmmakecallcomplete)

[ProtocolClMakeCallComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_make_call_complete)

[ProtocolCmMakeCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_make_call)

[ProtocolCoDeleteVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_delete_vc)