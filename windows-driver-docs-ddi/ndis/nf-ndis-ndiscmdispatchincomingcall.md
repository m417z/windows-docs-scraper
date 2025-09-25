# NdisCmDispatchIncomingCall function

## Description

**NdisCmDispatchIncomingCall** informs the client of an incoming call on a SAP previously registered by
that client.

## Parameters

### `NdisSapHandle` [in]

Specifies the handle identifying the SAP. NDIS set up this handle when the client originally
called
[NdisClRegisterSap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclregistersap), and the call
manager originally obtained this handle as an input parameter to its
[ProtocolCmRegisterSap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_reg_sap) function.

### `NdisVcHandle` [in]

Specifies the handle identifying the VC, created with
[NdisCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscocreatevc) when the call manager
processes the incoming call offer directed to this registered SAP.

### `CallParameters` [in]

Pointer to a structure of type
[CO_CALL_PARAMETERS](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff545384(v=vs.85)) that specifies the
traffic and media parameters for the VC.

## Return value

When
**NdisCmDispatchIncomingCall** returns anything other than NDIS_STATUS_PENDING, the call manager
should make an internal call to its
[ProtocolCmIncomingCallComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_incoming_call_complete) function. Otherwise, NDIS calls the CM's
*ProtocolCmIncomingCallComplete* function when this operation is completed.

## Remarks

Before calling
**NdisCmDispatchIncomingCall**, a stand-alone call manager has already done the following:

* Identified the target SAP, previously registered by a particular client, for the call (actually, a
  request to make a connection) that it received over the network
* Created a VC for the incoming call with
  [NdisCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscocreatevc)
* Possibly negotiated about acceptable call parameters over the network, or accepted the call
  parameters sent from the remote node
* Activated the VC with
  [NdisCmActivateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmactivatevc), causing the
  underlying miniport driver to make itself ready for transfers on the VC in accord with the negotiated
  or accepted call parameters

The CM's call to
**NdisCmDispatchIncomingCall** causes NDIS to call the client's
[ProtocolClIncomingCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_incoming_call) function,
within which the client either accepts or rejects the requested connection. After deciding whether to
accept the connection, the client calls
[NdisClIncomingCallComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclincomingcallcomplete),
which, in turn, calls the CM's
[ProtocolCmIncomingCallComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_incoming_call_complete) function. If the client accepted the call, the CM next calls
[NdisCmDispatchCallConnected](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmdispatchcallconnected).
Otherwise, it deactivates (and possibly deletes) the VC it created, after notifying the remote node that
the offered call was rejected.

Only stand-alone call managers, which register themselves with NDIS as protocol drivers, can call
**NdisCmDispatchIncomingCall**. Connection-oriented miniport drivers that provide integrated
call-management support call
**NdisMCmDispatchIncomingCall** instead.

## See also

[CO_CALL_PARAMETERS](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff545384(v=vs.85))

[NdisClIncomingCallComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclincomingcallcomplete)

[NdisClRegisterSap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclregistersap)

[NdisCmActivateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmactivatevc)

[NdisCmDeactivateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmdeactivatevc)

[NdisCmDispatchCallConnected](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmdispatchcallconnected)

[NdisCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscocreatevc)

[NdisCoDeleteVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscodeletevc)

[NdisCoSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscosendnetbufferlists)

[NdisMCmDispatchIncomingCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmdispatchincomingcall)

[ProtocolClIncomingCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_incoming_call)

[ProtocolCmIncomingCallComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_incoming_call_complete)

[ProtocolCmRegisterSap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_reg_sap)

[ProtocolCoReceiveNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_receive_net_buffer_lists)