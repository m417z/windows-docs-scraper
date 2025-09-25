# NdisCmDispatchIncomingCallQoSChange function

## Description

**NdisCmDispatchIncomingCallQoSChange** notifies a client that a request to change the quality of service
on that client's active connection has been received over the network.

## Parameters

### `NdisVcHandle` [in]

Specifies the handle to the VC for which the change in QoS is being requested. The call manager
originally obtained this handle either when it called
[NdisCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscocreatevc) to set up this connection
for an incoming call or as an input parameter to its
[ProtocolCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_create_vc) function.

### `CallParameters` [in]

Pointer to a structure of type
[CO_CALL_PARAMETERS](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff545384(v=vs.85)) that specifies the new
QoS, requested by the client on the remote node, for this connection.

## Remarks

A stand-alone call manager calls
**NdisCmDispatchIncomingCallQoSChange** to notify the client that it has received a request to modify
the QoS on an active connection. Such a CM supports dynamic QoS changes on active calls, which is a
feature like QoS itself that depends on the signaling protocol.

When the CM itself receives a request for a QoS change, the call manager passes appropriately modified
call parameters to
[NdisCmActivateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmactivatevc), so the underlying
miniport driver also is notified of the proposed QoS change. Assuming the underlying miniport driver
accepts the changed call parameters, the CM then calls
**NdisCmDispatchIncomingCallQoSChange**.

A call to
**NdisCmDispatchIncomingCallQoSChange** causes NDIS to call the client's
*ProtocolClIncomingQoSChange* function. The client accepts the proposed modifications to the call
parameters for the VC by doing nothing, except possibly updating any state it maintains about the QoS for
the VC, and returning control. Otherwise, the client rejects the proposed QoS change by tearing down the
call.

Only stand-alone call managers, which register themselves with NDIS as protocol drivers, can call
**NdisCmDispatchIncomingCallQoSChange**. Connection-oriented miniport drivers that provide integrated
call-management support call
**NdisMCmDispatchIncomingCallQoSChange** instead.

## See also

[CO_CALL_PARAMETERS](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff545384(v=vs.85))

[MiniportCoActivateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_co_activate_vc)

[NdisClCloseCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclclosecall)

[NdisClModifyCallQoS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclmodifycallqos)

[NdisCmActivateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmactivatevc)

[NdisMCmDispatchIncomingCallQoSChange](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmdispatchincomingcallqoschange)

[ProtocolClIncomingCallQosChange](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_incoming_call_qos_change)

[ProtocolCoReceiveNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_receive_net_buffer_lists)