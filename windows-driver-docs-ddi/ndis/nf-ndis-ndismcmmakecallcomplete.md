# NdisMCmMakeCallComplete macro

## Description

**NdisMCmMakeCallComplete** returns the final status of a client's request, for which the MCM driver
previously returned NDIS_STATUS_PENDING, to make an outgoing call.

## Parameters

### `_S_`

Specifies the final status of the attempt to make the connection, either NDIS_STATUS_SUCCESS or
any caller-determined NDIS_STATUS_
*XXX* except NDIS_STATUS_PENDING.

### `_VH_`

Specifies the handle to the client-created VC, which the MCM driver obtained as an input parameter
to its
[ProtocolCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_create_vc) function and,
more recently, from the
*CallMgrVcContext* passed to its
[ProtocolCmMakeCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_make_call) function.

### `_PH_`

Specifies the handle to the initial party on the client-created multipoint VC, which the MCM
driver obtained as an input parameter to its
*ProtocolCmMakeCall* function. If the given
*NdisVcHandle* represented a point-to-point VC, this parameter was **NULL**.

### `_CC_`

Specifies the handle to a caller-allocated resident context area, in which the MCM driver will
maintain per-party state information, or this parameter is **NULL** if
*NdisPartyHandle* is **NULL**. For a multipoint VC, NDIS passes this MCM-driver-supplied
*CallManagerPartyContext* handle in all subsequent calls to the ProtocolCm*Xxx* functions that concern this party. If
*Status* is anything other than NDIS_STATUS_SUCCESS, NDIS ignores this parameter.

### `_CP_`

Pointer to a structure of type
[CO_CALL_PARAMETERS](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff545384(v=vs.85)) that specifies the call
parameters set up for this connection if
*Status* is NDIS_STATUS_SUCCESS.

## Remarks

An MCM driver should call
**NdisMCmMakeCallComplete** with NDIS_STATUS_SUCCESS only if it is ready to make data transfers on the
VC. That is, the MCM driver has negotiated with the network to establish the call parameters for the VC,
set up a NIC for those call parameters, and called
[NdisMCmActivateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmactivatevc) to notify NDIS of the
VC activation.

An MCM driver must call
**NdisMCmMakeCallComplete** if its
[ProtocolCmMakeCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_make_call) function
previously returned NDIS_STATUS_PENDING for the given
*NdisVcHandle* .The client, which initiated the pending outgoing call, cannot use the VC to make
transfers until the miniport driver calls
**NdisMCmMakeCallComplete** with NDIS_STATUS_SUCCESS.

Even if the attempted connection failed, neither NDIS nor the client can release the resources they
allocated to maintain state until the MCM driver's call to
**NdisMCmMakeCallComplete** causes a call to that client's
[ProtocolClMakeCallComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_make_call_complete) function. In fact, neglecting to call
**NdisMCmMakeCallComplete** for a failed attempt to set up such a connection causes a memory leak in
the MCM driver as well; it prevents the client from tearing down the VC it created for its failed
outgoing call, so the MCM driver's
[ProtocolCoDeleteVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_delete_vc) function is not
called to release the resources the miniport driver allocated for that VC.

If the MCM driver passes an error, such as NDIS_STATUS_FAILURE, for the
*Status*, it must consider the
*NdisPartyHandle*, if any, invalid when
**NdisMCmMakeCallComplete** returns control. The CM can release (or reinitialize for reuse) any
resources that it allocated to maintain state for the given party after
**NdisMCmMakeCallComplete** returns control. The MCM driver's
*ProtocolCoDeleteVc* function will subsequently be called to release any resources that the miniport
driver allocated for tracking the state of the client-created VC whenever the MCM driver passes an error
status to
**NdisMCmMakeCallComplete**.

In the course of setting up a client-initiated outgoing call, the MCM driver can modify the
client-supplied call parameters originally passed in to its
*ProtocolCmMakeCall* function. If it does, the MCM driver must pass its modifications in the buffer
at
*CallParameters* when it calls
**NdisMCmMakeCallComplete**. If the client finds these modified call parameters unacceptable, it will
then tear down the call, which also causes a call to the MCM driver's
*ProtocolCoDeleteVc* function.

Only connection-oriented miniport drivers that provide integrated call-management support can call
**NdisMCmMakeCallComplete**. Stand-alone call managers, which register themselves with NDIS as
protocol drivers, call
**NdisCmMakeCallComplete** instead.

## See also

[CO_CALL_PARAMETERS](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff545384(v=vs.85))

[NdisAllocateFromNPagedLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatefromnpagedlookasidelist)

[NdisClMakeCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclmakecall)

[NdisCmMakeCallComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmmakecallcomplete)

[ProtocolClMakeCallComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_make_call_complete)

[ProtocolCmMakeCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_make_call)

[ProtocolCoDeleteVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_delete_vc)